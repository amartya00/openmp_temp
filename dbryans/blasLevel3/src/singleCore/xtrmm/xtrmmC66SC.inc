/* Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the
* distribution.
*
* Neither the name of Texas Instruments Incorporated nor the names of
* its contributors may be used to endorse or promote products derived
* from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  @file   xtrmmC66SC.inc
 *  @brief  This file single core xtrmm implementation.
 *          The functions has been been independent of data type.
 *          Proper renaming with #define is necessary.
 *
 */

#include <xdc/std.h>
#include "stdio.h"

#include "string.h" // for memset
#include <ti/sysbios/family/c66/Cache.h>
#include <ti/csl/csl_cacheAux.h>
#include <xdc/runtime/System.h>

// includes needed for heap/memory allocation
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/cfg/global.h>
#include "../../util/memory.h"

#include "../../util/touch.h"
#include "../../util/edma.h"

// xtrmm interface for upper triangular form
void xtrmmUpper(char side, char uplo, char transA, char diag,
		   int m, int n,
		   dataType alpha, dataType *a, int lda,
           dataType *b, int ldb)
{
  int aXferIndex, bXferIndex;
  int k;
  int kIndex, kCnt, kCntNext;
  int mIndex, mCnt, mCntNext;
  int nIndex, nCnt, nCntNext/*, innerNCnt*/;
  int innerIndex_m, innerIndex_n;
  int flagLastK, flagLastM, flagLastN;
  dataType * restrict ptrA, * restrict ptrB, * restrict ptrC;
  dataType * restrict ptrASeg1, * restrict ptrASeg2;
  dataType * restrict ptrBSeg1, * restrict ptrBSeg2, * restrict ptrBSeg;
  short  indexACurrent, indexANext, indexBCurrent, indexBNext;
  int flagTransA = 0, flagTransB = 0, flagSaveC = 0, flagDiagisU = 0;
  short flagUseDMACopyA = 1, flagUseDMACopyB = 1;
  int kLoc;

  if((m==0) || (n==0)) return;

  if((diag == 'u') || (diag == 'U')) flagDiagisU = 1;
  else if((diag == 'n') || (diag == 'N')) flagDiagisU = 0;
  else
  {
	System_printf("%s non valid value for diag: %c\n", XTRMM, diag);
	return;
  }

  if(((side=='l') || (side=='L')) &&
		  ((uplo=='u') || (uplo=='U')) &&
		  ((transA=='n') || (transA=='N')))
  {
	// compute A*B and save A*B
	flagTransB = 0;
	flagTransA = 0;
	flagSaveC = 1;
  }
  else if(((side=='l') || (side=='L')) &&
		  ((uplo=='l') || (uplo=='L')) &&
		  ((transA=='t') || (transA=='T')))
  {
	// compute AT*B and save AT*B
	flagTransB = 0;
	flagTransA = 1;
	flagSaveC = 1;
  }
  else if(((side=='l') || (side=='L')) &&
		  ((uplo=='l') || (uplo=='L')) &&
		  ((transA=='c') || (transA=='C')))
  {
	// compute AH*B and save AH*B
	flagTransB = 0;
	flagTransA = 2;
	flagSaveC = 1;
  }
  else if(((side=='r') || (side=='R')) &&
		  ((uplo=='l') || (uplo=='L')) &&
		  ((transA=='n') || (transA=='N')))
  {
	// compute AT*BT and save (AT*BT)T
	flagTransB = 1;
	flagTransA = 1;
	flagSaveC = 0;
  }
  else if(((side=='r') || (side=='R')) &&
		  ((uplo=='u') || (uplo=='U')) &&
		  ((transA=='t') || (transA=='T')))
  {
	// compute A*BT and save (A*BT)T
	flagTransB = 1;
	flagTransA = 0;
	flagSaveC = 0;
  }
  else if(((side=='r') || (side=='R')) &&
		  ((uplo=='u') || (uplo=='U')) &&
		  ((transA=='c') || (transA=='C')))
  {
	// compute A*BH and save (A*BH)H
	flagTransB = 2;
	flagTransA = 0;
	flagSaveC = -1;
  }
  else
  {
	System_printf("%s (upper) non valid combination for side, uplo and transA: %c %c %c\n", XTRMM, side, uplo, transA);
	return;
  }

  // matA moved from DDR to MSMC here
  ptrASeg1  = Memory_allocMSMC((MPARTITION*KPARTITION+2*NPARTITION*KPARTITION)*sizeof(dataType), BUFALIGN);
  // matA moved here after data placement needed per kernel
  ptrASeg2 = (dataType *) Memory_alloc((IHeap_Handle) l2Heap, (MPARTITION*KPARTITION+BANKOFFSET)*sizeof(dataType), BUFALIGN, NULL);
  ptrASeg2 += BANKOFFSET;
  ptrBSeg  = (dataType *) Memory_alloc((IHeap_Handle) l1Heap, N_KERNEL*KPARTITION*sizeof(dataType), BUFALIGN, NULL);

  ptrBSeg1 = ptrASeg1+(MPARTITION*KPARTITION);
  ptrBSeg2 = ptrBSeg1+(NPARTITION*KPARTITION);

  aXferIndex = 0;
  bXferIndex = 0;
  if(flagSaveC > 0)
  {
	k = m;
  }
  else
  {
	k = n;
	n = m;
	m = k;
  }

  mCnt = (m < MPARTITION) ? m : MPARTITION;
  kCnt = (k < KPARTITION) ? k : KPARTITION;
  nCnt = (n < NPARTITION) ? n : NPARTITION;

#ifdef DMA_COPYA
  if(lda*sizeof(dataType) < MAXDMASTRIDE)
	 flagUseDMACopyA = 1; // use DMA
  else
	 flagUseDMACopyA = 0; // cannot use DMA since stride is only 16 bit signed
#else
  flagUseDMACopyA = 0;
#endif
#ifdef DMA_COPYB
  if(ldb*sizeof(dataType) < MAXDMASTRIDE)
	 flagUseDMACopyB = 1; // use DMA
  else
	 flagUseDMACopyB = 0; // cannot use DMA since stride is only 16 bit signed
#else
  flagUseDMACopyB = 0;
#endif

  // initiate first transfer of A to MSMC SRAM
  if(flagUseDMACopyA)
  {
    Cache_inv(ptrASeg1, MPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
  }

  if(flagTransA == 0)
  {
	if(flagUseDMACopyA)
	{
	  edmaInitiateXfer(ptrASeg1, a, mCnt*sizeof(dataType), kCnt, 1,
		  lda*sizeof(dataType), /*mCnt*/MPARTITION*sizeof(dataType), 1,
	      1, 0, 1);
	}
	else
	{
      for(innerIndex_m=0;innerIndex_m< kCnt; innerIndex_m++)
      {
    	memcpy(ptrASeg1 + innerIndex_m * MPARTITION, a+innerIndex_m*lda, mCnt*sizeof(dataType));
    	// now invalidate cache for a
  	    Cache_inv(a+innerIndex_m*lda, mCnt*sizeof(dataType), Cache_Type_ALLD, 1);
      }
	}
  }
  else // A is in transposed form
  {
	if(flagUseDMACopyA)
	{
	  edmaInitiateXfer(ptrASeg1, a, kCnt*sizeof(dataType), mCnt, 1,
			  lda*sizeof(dataType), /*kCnt*/KPARTITION*sizeof(dataType), 1,
		      1, 0, 1);
	}
	else
	{
      for(innerIndex_m=0;innerIndex_m< mCnt; innerIndex_m++)
      {
      	memcpy(ptrASeg1+innerIndex_m*KPARTITION, a+innerIndex_m*lda, kCnt*sizeof(dataType));
    	// now invalidate cache for a
    	Cache_inv(a+innerIndex_m*lda, kCnt*sizeof(dataType), Cache_Type_ALLD, 1);
      }
	}
  }
  // initiate first transfer of B to to MSMC SRAM
  if(flagUseDMACopyB)
  {
    Cache_inv(ptrBSeg1, NPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
  }
  if(flagTransB == 0)
  {
	if(flagUseDMACopyB)
	{
	  edmaInitiateXfer(ptrBSeg1, b, kCnt*sizeof(dataType), nCnt, 1,
  		ldb*sizeof(dataType), /*kCnt*/KPARTITION*sizeof(dataType), 1,
  		1, 1, 1);
	}
	else
	{
      for(innerIndex_m=0;innerIndex_m< nCnt; innerIndex_m++)
    	memcpy(ptrBSeg1 + innerIndex_m * KPARTITION, b+innerIndex_m*ldb, kCnt*sizeof(dataType));
	}
  }
  else // B is in transposed form
  {
	if(flagUseDMACopyB)
	{
	  edmaInitiateXfer(ptrBSeg1, b, nCnt*sizeof(dataType), kCnt, 1,
	    	ldb*sizeof(dataType), /*nCnt*/NPARTITION*sizeof(dataType), 1,
	  		1, 1, 1);
	}
	else
	{
      for(innerIndex_m=0;innerIndex_m< kCnt; innerIndex_m++)
    	memcpy(ptrBSeg1 + innerIndex_m * NPARTITION, b+innerIndex_m*ldb, nCnt*sizeof(dataType));
	}
  }

  indexACurrent=1;
  indexANext=0;
  indexBCurrent=1;
  indexBNext=0;

  for(kIndex=0; kIndex<k; kIndex+=KPARTITION)  // partition in k dimension
  {
    // This is GEPP loop
    kCnt = ((k-kIndex) < KPARTITION) ? (k-kIndex) : KPARTITION;
    kCntNext = ((k-kIndex-KPARTITION) < KPARTITION) ? (k-kIndex-KPARTITION) : KPARTITION;
    flagLastK = ((kIndex+KPARTITION) < k) ? 0 : 1;

    //if(flagLastK) kCntNext = (k < KPARTITION) ? k : KPARTITION;

    for(mIndex = 0; mIndex<kIndex+kCnt; mIndex+=MPARTITION)  // partition in m dimension
    { // This is GEPB loop
      mCnt = ((kIndex+kCnt-mIndex) < MPARTITION) ? (kIndex+kCnt-mIndex) : MPARTITION;
      mCntNext = ((kIndex+kCnt-mIndex-MPARTITION) < MPARTITION) ? (kIndex+kCnt-mIndex-MPARTITION) : MPARTITION;
      flagLastM = ((mIndex+MPARTITION)<kIndex+kCnt) ? 0 : 1;

      if(flagLastM) mCntNext = (kIndex+kCnt+kCntNext < MPARTITION) ? kIndex+kCnt+kCntNext : MPARTITION;

      // bring in A into MSMC SRAM (a new parallel transfer)
      indexACurrent = (indexACurrent+1) & 1;
      indexANext = (indexANext+1) & 1;
  	if(flagUseDMACopyA)
  	{
      edmaWait4Completion(0);
  	}
    if(flagTransA == 0)
    {
      kLoc = (kIndex+kCnt)-(mIndex);
      aXferIndex = (flagLastM) ? (kIndex+kCnt)*lda : kIndex*lda+(mIndex+mCnt);
      // Move A to L2 SRAM in desired contiguous arrangement
      arrangeDataUAtrmm(ptrASeg1, kLoc, mCnt, kCnt, flagDiagisU);
      dataMoveAtrmm(ptrASeg2, ptrASeg1, mCnt, kCnt, MPARTITION);
      if(flagUseDMACopyA)
      {
        Cache_inv(ptrASeg1, MPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
      }
      if((!flagLastM) || (!flagLastK)) // don't carry out DMA for the last iteration
      {
        if(flagUseDMACopyA)
        {
      	  edmaInitiateXfer(ptrASeg1, a+aXferIndex, mCntNext*sizeof(dataType),
      		(flagLastM ? kCntNext : kCnt), 1,
    	    lda*sizeof(dataType), /*mCntNext*/MPARTITION*sizeof(dataType), 1,
    		1, 0, 1);
        }
        else
        {
          for(innerIndex_m=0;innerIndex_m< (flagLastM ? kCntNext : kCnt); innerIndex_m++)
          {
        	memcpy(ptrASeg1+innerIndex_m*MPARTITION, a+aXferIndex+innerIndex_m*lda, mCntNext*sizeof(dataType));
        	// now invalidate cache for a
        	Cache_inv(a+aXferIndex+innerIndex_m*lda, mCntNext*sizeof(dataType), Cache_Type_ALLD, 1);
          }
        }
      }
    	// move data in desired contiguous location
    }
    else // A is in transposed form
    {
      kLoc = (kIndex+kCnt)-(mIndex);
      aXferIndex = (flagLastM) ? (kIndex+kCnt) : kIndex+(mIndex+mCnt)*lda;
      // Move A to L2 SRAM in desired contiguous arrangement
      arrangeDataLTAtrmm(ptrASeg1, kLoc, mCnt, kCnt, flagDiagisU);
      if(flagTransA==1)
      {
        dataMoveATtrmm(ptrASeg2, ptrASeg1, mCnt, kCnt, KPARTITION);
      }
      else
      {
        dataMoveAHtrmm(ptrASeg2, ptrASeg1, mCnt, kCnt, KPARTITION);
      }
  	  if(flagUseDMACopyA)
  	  {
        Cache_inv(ptrASeg1, MPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
  	  }
      if((!flagLastM) || (!flagLastK)) // don't carry out DMA for the last iteration
      {
        if(flagUseDMACopyA)
        {
          edmaInitiateXfer(ptrASeg1, a+aXferIndex, (flagLastM ? kCntNext : kCnt)*sizeof(dataType), mCntNext, 1,
     	   lda*sizeof(dataType), /*(flagLastM ? kCntNext : kCnt)*/KPARTITION*sizeof(dataType), 1,
		   1, 0, 1);
        }
        else
        {
          for(innerIndex_m=0;innerIndex_m< mCntNext; innerIndex_m++)
          {
          	memcpy(ptrASeg1+innerIndex_m*KPARTITION, a+aXferIndex+innerIndex_m*lda, (flagLastM ? kCntNext : kCnt)*sizeof(dataType));
        	// now invalidate cache for a
          	Cache_inv(a+aXferIndex+innerIndex_m*lda, (flagLastM ? kCntNext : kCnt)*sizeof(dataType), Cache_Type_ALLD, 1);
          }
        }
      }
    }
      for(nIndex = 0; nIndex<n; nIndex+=NPARTITION)  // partition in n dimension
      {
        nCnt = ((n-nIndex) < NPARTITION) ? (n-nIndex) : NPARTITION;
        nCntNext = ((n-nIndex-NPARTITION) < NPARTITION) ? (n-nIndex-NPARTITION) : NPARTITION;
        flagLastN = ((nIndex+NPARTITION)<n) ? 0 : 1;

        if(flagLastN) nCntNext = (n < NPARTITION) ? n : NPARTITION;

        // bring in B into L1 SRAM (a new parallel transfer)
        indexBCurrent = (indexBCurrent+1) & 1;
        indexBNext = (indexBNext+1) & 1;

        if(flagUseDMACopyB)
        {
          edmaWait4Completion(1);
        }
        if((!flagLastM) || (!flagLastK) || (!flagLastN)) // don't carry out DMA for the last iteration
        {
          if(flagTransB == 0)
          {
            bXferIndex = ((flagLastN) ? 0 : (nIndex+nCnt))*ldb + ((flagLastM && flagLastN) ? kIndex+kCnt : kIndex);
            ptrB = (indexBNext == 0) ? ptrBSeg1: ptrBSeg2;
            if(flagUseDMACopyB)
            {
              Cache_inv(ptrB, NPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
              edmaInitiateXfer(ptrB, b+bXferIndex, ((flagLastM && flagLastN) ? kCntNext : kCnt)*sizeof(dataType), nCntNext, 1,
              		ldb*sizeof(dataType), /*((flagLastM && flagLastN) ? kCntNext : kCnt)*/KPARTITION*sizeof(dataType), 1,
              		1, 1, 1);
            }
            else
            {
              for(innerIndex_m=0;innerIndex_m< nCntNext; innerIndex_m++)
          	    memcpy(ptrB + innerIndex_m * KPARTITION, b+bXferIndex+innerIndex_m*ldb, ((flagLastM && flagLastN) ? kCntNext : kCnt)*sizeof(dataType));
            }
          }
          else // B is in transposed form
          {
            bXferIndex = ((flagLastN) ? 0 : (nIndex+nCnt)) + ((flagLastM && flagLastN) ? kIndex+kCnt : kIndex)*ldb;
            ptrB = (indexBNext == 0) ? ptrBSeg1: ptrBSeg2;
            if(flagUseDMACopyB)
            {
              Cache_inv(ptrB, NPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
              edmaInitiateXfer(ptrB, b+bXferIndex, nCntNext*sizeof(dataType), ((flagLastM && flagLastN) ? kCntNext : kCnt), 1,
        	    	ldb*sizeof(dataType), /*nCntNext*/NPARTITION*sizeof(dataType), 1,
        	  		1, 1, 1);
            }
            else
            {
              for(innerIndex_m=0;innerIndex_m< ((flagLastM && flagLastN) ? kCntNext : kCnt); innerIndex_m++)
          	    memcpy(ptrB + innerIndex_m * NPARTITION, b+bXferIndex+innerIndex_m*ldb, nCntNext*sizeof(dataType));
            }
          }
        }
        // L2 memory assignment for B
        ptrB = (indexBCurrent == 0) ? ptrBSeg1: ptrBSeg2;

        for(innerIndex_n = 0; innerIndex_n<nCnt; innerIndex_n+=N_KERNEL)
        {

          // Move B to L1 SRAM in desired contiguous arrangement
          if(flagTransB == 0)
          {
        	dataMoveBtrmm(ptrBSeg, ptrB, kCnt);
            ptrB += (N_KERNEL*KPARTITION);
          }
          else if(flagTransB == 1)
          {
          	dataMoveBTtrmm(ptrBSeg, ptrB, kCnt);
            ptrB += N_KERNEL;
          }
          else
          {
          	dataMoveBHtrmm(ptrBSeg, ptrB, kCnt);
            ptrB += N_KERNEL;
          }

          // L2 memory assignment for B
          ptrA = ptrASeg2;
          // output memory assignment
          if(flagSaveC > 0) ptrC= b + mIndex + (nIndex+innerIndex_n)*ldb;
          else ptrC= b + mIndex*ldb + (nIndex+innerIndex_n);

          for(innerIndex_m = 0; innerIndex_m<mCnt; innerIndex_m+=M_KERNEL)
          {
        	if(((mIndex+innerIndex_m)>=kIndex) && (mIndex+innerIndex_m)<(kIndex+kCnt))
        	{ // we are in a diagonal entry
      	      // pre-fetch required A to L1 Cache
              // M_KERNELxk * kxN_KERNEL core matrix multiplications
        	  kLoc=(mIndex+innerIndex_m)-kIndex;
              touch(ptrA+M_KERNEL *kLoc, M_KERNEL * (kCnt-kLoc) * sizeof(dataType));
      	      xtrmmKernelNoReadFlexSave(ptrA+M_KERNEL * kLoc, ptrBSeg+N_KERNEL * kLoc,
      	      		  ptrC, alpha, kCnt-kLoc, ldb, N_KERNEL, flagSaveC);
        	}
        	else if((mIndex+innerIndex_m)<(kIndex+kCnt))
        	{
    	      // pre-fetch required A to L1 Cache
              // M_KERNELxk * kxN_KERNEL core matrix multiplications
              touch(ptrA, M_KERNEL * kCnt * sizeof(dataType));
    	      xtrmmKernelFlexSave(ptrA, ptrBSeg, ptrC, alpha, kCnt, ldb, N_KERNEL, flagSaveC);
        	}
  	        // address of C to write to
    	    if(flagSaveC > 0) ptrC += M_KERNEL;
    	    else ptrC += (M_KERNEL*ldb);
  	        ptrA += (M_KERNEL*KPARTITION);
          } // inner loop m
        } // inner loop n
      } // n loop
    } // m loop
  } // k loop

  Memory_freeMSMC(ptrASeg1, (MPARTITION*KPARTITION+2*NPARTITION*KPARTITION)*sizeof(dataType));
  Memory_free((IHeap_Handle) l2Heap, ptrASeg2-BANKOFFSET, (MPARTITION*KPARTITION+BANKOFFSET)*sizeof(dataType));
  Memory_free((IHeap_Handle) l1Heap, ptrBSeg, N_KERNEL*KPARTITION*sizeof(dataType));

  // do a global cache write-back from all local data memory
  CACHE_wbInvAllL1d(CACHE_WAIT);
  CACHE_wbInvAllL2(CACHE_WAIT);

}

void xtrmmLower(char side, char uplo, char transA, char diag,
		   int m, int n,
		   dataType alpha, dataType *a, int lda,
           dataType *b, int ldb)
{
  int aXferIndex, bXferIndex;
  int k;
  int kIndex, kCnt, kCntNext;
  int mIndex, mCnt, mCntNext;
  int nIndex, nCnt, nCntNext/*, innerNCnt*/;
  int innerIndex_m, innerIndex_n;
  int flagLastK, flagLastM, flagLastN;
  dataType * restrict ptrA, * restrict ptrB, * restrict ptrC;
  dataType * restrict ptrASeg1, * restrict ptrASeg2;
  dataType * restrict ptrBSeg1, * restrict ptrBSeg2, * restrict ptrBSeg;
  short  indexACurrent, indexANext, indexBCurrent, indexBNext;
  int flagTransA = 0, flagTransB = 0, flagSaveC = 0, flagDiagisU = 0;
  short flagUseDMACopyA = 1, flagUseDMACopyB = 1;
  int kLoc;

  if((m==0) || (n==0)) return;

  if((diag == 'u') || (diag == 'U')) flagDiagisU = 1;
  else if((diag == 'n') || (diag == 'N')) flagDiagisU = 0;
  else
  {
	System_printf("%s non valid value for diag: %c\n", XTRMM, diag);
	return;
  }

  if(((side=='l') || (side=='L')) &&
		  ((uplo=='l') || (uplo=='L')) &&
		  ((transA=='n') || (transA=='N')))
  {
	// compute A*B and save A*B
	flagTransB = 0;
	flagTransA = 0;
	flagSaveC = 1;
  }
  else if(((side=='l') || (side=='L')) &&
		  ((uplo=='u') || (uplo=='U')) &&
		  ((transA=='t') || (transA=='T')))
  {
	// compute AT*B and save AT*B
	flagTransB = 0;
	flagTransA = 1;
	flagSaveC = 1;
  }
  else if(((side=='l') || (side=='L')) &&
		  ((uplo=='u') || (uplo=='U')) &&
		  ((transA=='c') || (transA=='C')))
  {
	// compute AH*B and save AH*B
	flagTransB = 0;
	flagTransA = 2;
	flagSaveC = 1;
  }
  else if(((side=='r') || (side=='R')) &&
		  ((uplo=='u') || (uplo=='U')) &&
		  ((transA=='n') || (transA=='N')))
  {
	// compute AT*BT and save (AT*BT)T
	flagTransB = 1;
	flagTransA = 1;
	flagSaveC = 0;
  }
  else if(((side=='r') || (side=='R')) &&
		  ((uplo=='l') || (uplo=='L')) &&
		  ((transA=='t') || (transA=='T')))
  {
	// compute A*BT and save (A*BT)T
	flagTransB = 1;
	flagTransA = 0;
	flagSaveC = 0;
  }
  else if(((side=='r') || (side=='R')) &&
		  ((uplo=='l') || (uplo=='L')) &&
		  ((transA=='c') || (transA=='C')))
  {
	// compute A*BH and save (A*BH)H
	flagTransB = 2;
	flagTransA = 0;
	flagSaveC = -1;
  }
  else
  {
	System_printf("%s (upper) non valid combination for side, uplo and transA: %c %c %c\n", XTRMM, side, uplo, transA);
	return;
  }

  // matA moved from DDR to MSMC here
  ptrASeg1  = Memory_allocMSMC((MPARTITION*KPARTITION+2*NPARTITION*KPARTITION)*sizeof(dataType), BUFALIGN);
  // matA moved here after data placement needed per kernel
  ptrASeg2 = (dataType *) Memory_alloc((IHeap_Handle) l2Heap, (MPARTITION*KPARTITION+BANKOFFSET)*sizeof(dataType), BUFALIGN, NULL);
  ptrASeg2 += BANKOFFSET;
  ptrBSeg  = (dataType *) Memory_alloc((IHeap_Handle) l1Heap, N_KERNEL*KPARTITION*sizeof(dataType), BUFALIGN, NULL);

  ptrBSeg1 = ptrASeg1+(MPARTITION*KPARTITION);
  ptrBSeg2 = ptrBSeg1+(NPARTITION*KPARTITION);

  aXferIndex = 0;
  bXferIndex = 0;
  if(flagSaveC > 0)
  {
    // make m multiple of M_KERNEL
	m = M_KERNEL*((m+(M_KERNEL-1))/M_KERNEL);
	// make n multiple of N_KERNEL
	n = N_KERNEL*((n+(N_KERNEL-1))/N_KERNEL);
    k = m;
  }
  else
  {
    k = n;
	// make n multiple of M_KERNEL
	n = M_KERNEL*((m+(M_KERNEL-1))/M_KERNEL);
    // make m multiple of N_KERNEL
	m = N_KERNEL*((k+(N_KERNEL-1))/N_KERNEL);
	k = m;
  }

  mCnt = (m < MPARTITION) ? m : MPARTITION;
  kCnt = (k < KPARTITION) ? k : KPARTITION;
  nCnt = (n < NPARTITION) ? n : NPARTITION;

#ifdef DMA_COPYA
  if(lda*sizeof(dataType) < MAXDMASTRIDE)
	 flagUseDMACopyA = 1; // use DMA
  else
	 flagUseDMACopyA = 0; // cannot use DMA since stride is only 16 bit signed
#else
  flagUseDMACopyA = 0;
#endif
#ifdef DMA_COPYB
  if(ldb*sizeof(dataType) < MAXDMASTRIDE)
	 flagUseDMACopyB = 1; // use DMA
  else
	 flagUseDMACopyB = 0; // cannot use DMA since stride is only 16 bit signed
#else
  flagUseDMACopyB = 0;
#endif

  // initiate first transfer of A to MSMC SRAM
  if(flagUseDMACopyA)
  {
    Cache_inv(ptrASeg1, MPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
  }

  if(flagTransA == 0)
  {
	aXferIndex = (k-kCnt)*lda+(m-mCnt);
	if(flagUseDMACopyA)
	{
	  edmaInitiateXfer(ptrASeg1, a+aXferIndex, mCnt*sizeof(dataType), kCnt, 1,
		  lda*sizeof(dataType), /*mCnt*/MPARTITION*sizeof(dataType), 1,
	      1, 0, 1);
	}
	else
	{
      for(innerIndex_m=0;innerIndex_m< kCnt; innerIndex_m++)
      {
    	memcpy(ptrASeg1 + innerIndex_m * MPARTITION, a+aXferIndex+innerIndex_m*lda, mCnt*sizeof(dataType));
    	// now invalidate cache for a
  	    Cache_inv(a+aXferIndex+innerIndex_m*lda, mCnt*sizeof(dataType), Cache_Type_ALLD, 1);
      }
	}
  }
  else // A is in transposed form
  {
	aXferIndex = (k-kCnt)+(m-mCnt)*lda;
	if(flagUseDMACopyA)
	{
	  edmaInitiateXfer(ptrASeg1, a+aXferIndex, kCnt*sizeof(dataType), mCnt, 1,
			  lda*sizeof(dataType), /*kCnt*/KPARTITION*sizeof(dataType), 1,
		      1, 0, 1);
	}
	else
	{
      for(innerIndex_m=0;innerIndex_m< mCnt; innerIndex_m++)
      {
      	memcpy(ptrASeg1+innerIndex_m*KPARTITION, a+aXferIndex+innerIndex_m*lda, kCnt*sizeof(dataType));
    	// now invalidate cache for a
  	    Cache_inv(a+aXferIndex+innerIndex_m*lda, kCnt*sizeof(dataType), Cache_Type_ALLD, 1);
      }
	}
  }
  // initiate first transfer of B to to MSMC SRAM
  if(flagUseDMACopyB)
  {
    Cache_inv(ptrBSeg1, NPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
  }
  if(flagTransB == 0)
  {
	  bXferIndex = (n-nCnt)*ldb+(k-kCnt);
	  if(flagUseDMACopyB)
	  {
	    edmaInitiateXfer(ptrBSeg1, b+bXferIndex, kCnt*sizeof(dataType), nCnt, 1,
  		  ldb*sizeof(dataType), /*kCnt*/KPARTITION*sizeof(dataType), 1,
  		  1, 1, 1);
	  }
	  else
	  {
        for(innerIndex_m=0;innerIndex_m< nCnt; innerIndex_m++)
        {
    	  memcpy(ptrBSeg1 + innerIndex_m * KPARTITION, b+bXferIndex+innerIndex_m*ldb, kCnt*sizeof(dataType));
        }
	  }
  }
  else // B is in transposed form
  {
	  bXferIndex = (n-nCnt)+(k-kCnt)*ldb;
	  if(flagUseDMACopyB)
	  {
	    edmaInitiateXfer(ptrBSeg1, b+bXferIndex, nCnt*sizeof(dataType), kCnt, 1,
	    	ldb*sizeof(dataType), /*nCnt*/NPARTITION*sizeof(dataType), 1,
	  		1, 1, 1);
	  }
	  else
	  {
        for(innerIndex_m=0;innerIndex_m< kCnt; innerIndex_m++)
        {
    	  memcpy(ptrBSeg1 + innerIndex_m * NPARTITION, b+bXferIndex+innerIndex_m*ldb, nCnt*sizeof(dataType));
        }
	  }
  }

  indexACurrent=1;
  indexANext=0;
  indexBCurrent=1;
  indexBNext=0;

  //for(kIndex=0; kIndex<k; kIndex+=KPARTITION)  // partition in k dimension
  for(kIndex=k; kIndex>0; kIndex-=KPARTITION)  // partition in k dimension
  {
    // This is GEPP loop
    kCnt = ((kIndex) < KPARTITION) ? (kIndex) : KPARTITION;
    kCntNext = ((kIndex-KPARTITION) < KPARTITION) ? (kIndex-KPARTITION) : KPARTITION;
    flagLastK = ((kIndex-KPARTITION) > 0) ? 0 : 1;

    //if(flagLastK) kCntNext = (k < KPARTITION) ? k : KPARTITION;

    //for(mIndex = 0; mIndex<kIndex+kCnt; mIndex+=MPARTITION)  // partition in m dimension
    for(mIndex = m; mIndex>kIndex-kCnt; mIndex-=MPARTITION)  // partition in m dimension
    { // This is GEPB loop
      mCnt = ((mIndex) < MPARTITION) ? (mIndex) : MPARTITION;
      mCntNext = ((mIndex-MPARTITION) < MPARTITION) ? (mIndex-MPARTITION) : MPARTITION;
      flagLastM = ((mIndex-(kIndex-kCnt)-MPARTITION)> 0) ? 0 : 1;

      if(flagLastM) mCntNext = (m < MPARTITION) ? m : MPARTITION;

      // bring in A into MSMC SRAM (a new parallel transfer)
      indexACurrent = (indexACurrent+1) & 1;
      indexANext = (indexANext+1) & 1;
      if(flagUseDMACopyA)
      {
        edmaWait4Completion(0);
      }

      if(flagTransA == 0)
      {
        kLoc = (kIndex)-(mIndex);
        aXferIndex = ((flagLastM) ? ((kIndex-kCnt-kCntNext )*lda + (m-mCntNext)) : ((kIndex-kCnt)*lda+(mIndex-mCnt-mCntNext)));
        // Move A to L2 SRAM in desired contiguous arrangement
        arrangeDataLAtrmm(ptrASeg1, kLoc, mCnt, kCnt, flagDiagisU);
    	dataMoveAtrmm(ptrASeg2, ptrASeg1, mCnt, kCnt, MPARTITION);
    	if(flagUseDMACopyA)
    	{
          Cache_inv(ptrASeg1, MPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
    	}
        if((!flagLastM) || (!flagLastK)) // don't carry out DMA for the last iteration
        {
          if(flagUseDMACopyA)
          {
      	    edmaInitiateXfer(ptrASeg1, a+aXferIndex, mCntNext*sizeof(dataType),
      		  (flagLastM ? kCntNext : kCnt), 1,
    	      lda*sizeof(dataType), /*mCntNext*/MPARTITION*sizeof(dataType), 1,
    		  1, 0, 1);
          }
          else
          {
            for(innerIndex_m=0;innerIndex_m< (flagLastM ? kCntNext : kCnt); innerIndex_m++)
            {
        	  memcpy(ptrASeg1+innerIndex_m*MPARTITION, a+aXferIndex+innerIndex_m*lda, mCntNext*sizeof(dataType));
          	  // now invalidate cache for a
        	  Cache_inv(a+aXferIndex+innerIndex_m*lda, mCntNext*sizeof(dataType), Cache_Type_ALLD, 1);
            }
          }
        }
    	// move data in desired contiguous location
      }
      else // A is in transposed form
      {
        kLoc = (kIndex)-(mIndex);
        aXferIndex = ((flagLastM) ? ((kIndex-kCnt-kCntNext ) + (m-mCntNext)*lda) : ((kIndex-kCnt)+(mIndex-mCnt-mCntNext)*lda));
        // Move A to L2 SRAM in desired contiguous arrangement
        arrangeDataUTAtrmm(ptrASeg1, kLoc, mCnt, kCnt, flagDiagisU);
        if(flagTransA == 1)
    	  dataMoveATtrmm(ptrASeg2, ptrASeg1, mCnt, kCnt, KPARTITION);
        else
          dataMoveAHtrmm(ptrASeg2, ptrASeg1, mCnt, kCnt, KPARTITION);

        if(flagUseDMACopyA)
        {
          Cache_inv(ptrASeg1, MPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
        }
        if((!flagLastM) || (!flagLastK)) // don't carry out DMA for the last iteration
        {
          if(flagUseDMACopyA)
          {
            edmaInitiateXfer(ptrASeg1, a+aXferIndex, (flagLastM ? kCntNext : kCnt)*sizeof(dataType), mCntNext, 1,
     	      lda*sizeof(dataType), /*(flagLastM ? kCntNext : kCnt)*/KPARTITION*sizeof(dataType), 1,
		      1, 0, 1);
          }
          else
          {
            for(innerIndex_m=0;innerIndex_m< mCntNext; innerIndex_m++)
            {
            	memcpy(ptrASeg1+innerIndex_m*KPARTITION, a+aXferIndex+innerIndex_m*lda, (flagLastM ? kCntNext : kCnt)*sizeof(dataType));
            	// now invalidate cache for a
          	    Cache_inv(a+aXferIndex+innerIndex_m*lda, (flagLastM ? kCntNext : kCnt)*sizeof(dataType), Cache_Type_ALLD, 1);
            }
          }
        }
      }

      for(nIndex = n; nIndex>0; nIndex-=NPARTITION)  // partition in n dimension
      {
        nCnt = ((nIndex) < NPARTITION) ? (nIndex) : NPARTITION;
        nCntNext = ((nIndex-NPARTITION) < NPARTITION) ? (nIndex-NPARTITION) : NPARTITION;
        flagLastN = ((nIndex-NPARTITION)>0) ? 0 : 1;

        if(flagLastN) nCntNext = (n < NPARTITION) ? n : NPARTITION;
        // bring in B into L1 SRAM (a new parallel transfer)
        indexBCurrent = (indexBCurrent+1) & 1;
        indexBNext = (indexBNext+1) & 1;

        if(flagUseDMACopyB)
        {
          edmaWait4Completion(1);
        }
        if((!flagLastM) || (!flagLastK) || (!flagLastN)) // don't carry out DMA for the last iteration
        {
          if(flagTransB == 0)
          {
            bXferIndex = ((flagLastN) ? (n-nCntNext) : (nIndex-nCnt-nCntNext))*ldb + ((flagLastM && flagLastN) ? kIndex-kCnt-kCntNext : kIndex-kCnt);

            ptrB = (indexBNext == 0) ? ptrBSeg1: ptrBSeg2;
            if(flagUseDMACopyB)
            {
              Cache_inv(ptrB, NPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
              edmaInitiateXfer(ptrB, b+bXferIndex, ((flagLastM && flagLastN) ? kCntNext : kCnt)*sizeof(dataType), nCntNext, 1,
              		ldb*sizeof(dataType), /*((flagLastM && flagLastN) ? kCntNext : kCnt)*/KPARTITION*sizeof(dataType), 1,
              		1, 1, 1);
            }
            else
            {
              for(innerIndex_m=0;innerIndex_m< nCntNext; innerIndex_m++)
          	  memcpy(ptrB + innerIndex_m * KPARTITION, b+bXferIndex+innerIndex_m*ldb, ((flagLastM && flagLastN) ? kCntNext : kCnt)*sizeof(dataType));
            }
          }
          else // B is in transposed form
          {
            bXferIndex = ((flagLastN) ? (n-nCntNext) : (nIndex-nCnt-nCntNext)) + ((flagLastM && flagLastN) ? kIndex-kCnt-kCntNext : kIndex-kCnt)*ldb;
            ptrB = (indexBNext == 0) ? ptrBSeg1: ptrBSeg2;
            if(flagUseDMACopyB)
            {
              Cache_inv(ptrB, NPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
              edmaInitiateXfer(ptrB, b+bXferIndex, nCntNext*sizeof(dataType), ((flagLastM && flagLastN) ? kCntNext : kCnt), 1,
        	    	ldb*sizeof(dataType), /*nCntNext*/NPARTITION*sizeof(dataType), 1,
        	  		1, 1, 1);
            }
            else
            {
              for(innerIndex_m=0;innerIndex_m< ((flagLastM && flagLastN) ? kCntNext : kCnt); innerIndex_m++)
          	  memcpy(ptrB + innerIndex_m * NPARTITION, b+bXferIndex+innerIndex_m*ldb, nCntNext*sizeof(dataType));
            }
          }
        }
        // L2 memory assignment for B
        ptrB = (indexBCurrent == 0) ? ptrBSeg1: ptrBSeg2;
        if(flagSaveC > 0) ptrB += (nCnt*KPARTITION);
        else ptrB += (nCnt);
        for(innerIndex_n = 0; innerIndex_n<nCnt; innerIndex_n+=N_KERNEL)
        {

          // Move B to L1 SRAM in desired contiguous arrangement
          if(flagTransB == 0)
          {
            ptrB -= (N_KERNEL*KPARTITION);
        	dataMoveBtrmm(ptrBSeg, ptrB, kCnt);
          }
          else if(flagTransB == 1)
          {
            ptrB -= N_KERNEL;
          	dataMoveBTtrmm(ptrBSeg, ptrB, kCnt);
          }
          else
          {
            ptrB -= N_KERNEL;
          	dataMoveBHtrmm(ptrBSeg, ptrB, kCnt);
          }

          // L2 memory assignment for B
          ptrA = ptrASeg2+(mCnt*KPARTITION);
          // output memory assignment
          if(flagSaveC > 0) ptrC= b + (mIndex) + (nIndex-innerIndex_n-N_KERNEL)*ldb;
          else ptrC= b + (mIndex)*ldb + (nIndex-innerIndex_n-N_KERNEL);

          for(innerIndex_m = 0; innerIndex_m<mCnt; innerIndex_m+=M_KERNEL)
          {
    	    // address of C to write to
      	    if(flagSaveC > 0) ptrC -= M_KERNEL;
      	    else ptrC -= (M_KERNEL*ldb);
    	    ptrA -= (M_KERNEL*KPARTITION);

        	if(((mIndex-innerIndex_m)<=kIndex) && (mIndex-innerIndex_m)>(kIndex-kCnt))
        	{ // we are in a diagonal entry
      	      // pre-fetch required A to L1 Cache
              // M_KERNELxk * kxN_KERNEL core matrix multiplications
        	  kLoc=kCnt-(kIndex-(mIndex-innerIndex_m));
              touch(ptrA, M_KERNEL * kLoc * sizeof(dataType));
      	      xtrmmKernelNoReadFlexSave(ptrA, ptrBSeg, ptrC, alpha, kLoc, ldb, N_KERNEL, flagSaveC);
        	}
        	else if((mIndex-innerIndex_m)>(kIndex))
        	{
    	      // pre-fetch required A to L1 Cache
              // M_KERNELxk * kxN_KERNEL core matrix multiplications
              touch(ptrA, M_KERNEL * kCnt * sizeof(dataType));
    	      xtrmmKernelFlexSave(ptrA, ptrBSeg, ptrC, alpha, kCnt, ldb, N_KERNEL, flagSaveC);
        	}
          } // inner loop m
        } // inner loop n
      } // n loop
    } // m loop
  } // k loop

  // close down the DMA channels initialized; does not work for omp
  //edmaClose();
  // change back to original m and n;

  Memory_freeMSMC(ptrASeg1, (MPARTITION*KPARTITION+2*NPARTITION*KPARTITION)*sizeof(dataType));
  Memory_free((IHeap_Handle) l2Heap, ptrASeg2-BANKOFFSET, (MPARTITION*KPARTITION+BANKOFFSET)*sizeof(dataType));
  Memory_free((IHeap_Handle) l1Heap, ptrBSeg, N_KERNEL*KPARTITION*sizeof(dataType));

  // do a global cache write-back from all local data memory
  CACHE_wbInvAllL1d(CACHE_WAIT);
  CACHE_wbInvAllL2(CACHE_WAIT);

}

