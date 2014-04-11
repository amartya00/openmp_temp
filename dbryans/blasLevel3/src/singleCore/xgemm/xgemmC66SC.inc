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
 *  @file   xgemmC66SC.inc
 *  @brief  This file single core xgemm implementation.
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

// xgemm interface
void xgemm(char transa, char transb,
		   int m, int n, int k,
		   dataType alpha, dataType * restrict a, int lda,
           dataType * restrict b, int ldb,
           dataType beta,  dataType * restrict c, int ldc)
{
  int aXferIndex, bXferIndex;
  int kIndex, kCnt, kCntNext;
  int mIndex, mCnt, mCntNext;
  int nIndex, nCnt, nCntNext/*, innerNCnt*/;
  int innerIndex_m, innerIndex_n;
  int flagLastK, flagLastM, flagLastN;
  dataType * restrict ptrA, * restrict ptrB, * restrict ptrC;
  dataType * restrict ptrASeg1, * restrict ptrASeg2;
  dataType * restrict ptrBSeg1, * restrict ptrBSeg2, * restrict ptrBSeg;
  short  indexACurrent, indexANext, indexBCurrent, indexBNext;
  int flagTransA = 0, flagTransB = 0;
  short flagUseDMACopyA = 1, flagUseDMACopyB = 1;

  if((m==0) || (n==0) || (k==0)) return;

  if((transa=='n') || (transa=='N')) flagTransA=0;
  else if((transa=='t') || (transa=='T')) flagTransA=1;
  else if((transa=='c') || (transa=='C')) flagTransA=2;
  else
  {
	System_printf("%s non valid value for transa: %d\n", XGEMM, transa);
	return;
  }
  if((transb=='n') || (transb=='N')) flagTransB=0;
  else if((transb=='t') || (transb=='T')) flagTransB=1;
  else if((transb=='c') || (transb=='C')) flagTransB=2;
  else
  {
	System_printf("%s non valid value for transb: %d\n", XGEMM, transb);
	return;
  }

  // matA moved from DDR to MSMC here
  ptrASeg1  = Memory_allocMSMC((MPARTITION*KPARTITION+2*NPARTITION*KPARTITION)*sizeof(dataType), BUFALIGN);
  // matA moved here after data placement needed per kernel
  ptrASeg2 = (dataType *) Memory_alloc((IHeap_Handle) l2Heap, (MPARTITION*KPARTITION+BANKOFFSET)*sizeof(dataType), BUFALIGN, NULL);
  ptrBSeg  = (dataType *) Memory_alloc((IHeap_Handle) l1Heap, N_KERNEL*KPARTITION*sizeof(dataType), BUFALIGN, NULL);

  // matB ping pong buffer here
  ptrASeg2 += BANKOFFSET;
  ptrBSeg1 = ptrASeg1+(MPARTITION*KPARTITION);
  ptrBSeg2 = ptrBSeg1+(NPARTITION*KPARTITION);

  // Scale C = beta * C here.
#ifdef COMPLEX
  if(!((beta.r == (baseType) 1.0) && (beta.i == (baseType) 0.0))) // only if scaling of C is needed
  {
	if((beta.r==(baseType) 0.0) && (beta.i==(baseType) 0.0))
	{
	  for(nCnt=0;nCnt<n;nCnt++)
	  {
	   	memset(c+nCnt*ldc,0,m*sizeof(dataType)); // zero out c column by column
	  }
	} // if(beta==0.0f)
	else
	{
	  for(nCnt=0;nCnt<n;nCnt++)
	  {
		for(mCnt=0;mCnt<m;mCnt++)
		{
		  baseType temp;
		  temp = c[nCnt*ldc+mCnt].r * beta.r - c[nCnt*ldc+mCnt].i * beta.i;
		  c[nCnt*ldc+mCnt].i = c[nCnt*ldc+mCnt].r * beta.i + c[nCnt*ldc+mCnt].i * beta.r;
		  c[nCnt*ldc+mCnt].r = temp;
		}
	  }
	} // else
  } // if(beta != 1.0f)
#else
  if(beta != (dataType) 1.0) // only if scaling of C is needed
  {
	if(beta==(dataType) 0.0)
	{
	  for(nCnt=0;nCnt<n;nCnt++)
	  {
	   	memset(c+nCnt*ldc,0,m*sizeof(dataType)); // zero out c column by column
	  }
	} // if(beta==0.0f)
	else
	{
	  for(nCnt=0;nCnt<n;nCnt++)
	  {
		for(mCnt=0;mCnt<m;mCnt++)
		{
		  c[nCnt*ldc+mCnt] *= beta; // column by column multiplication
		}
	  }
	} // else
  } // if(beta != 1.0f)
#endif

  aXferIndex = 0;
  bXferIndex = 0;

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
    	memcpy(ptrASeg1 + innerIndex_m * MPARTITION, a+innerIndex_m*lda, mCnt*sizeof(dataType));
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
      	memcpy(ptrASeg1+innerIndex_m*KPARTITION, a+innerIndex_m*lda, kCnt*sizeof(dataType));
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
	if(flagTransB == 0) bXferIndex = kIndex;
	else bXferIndex = kIndex*ldb;  // B is in transposed form
    kCnt = ((k-kIndex) < KPARTITION) ? (k-kIndex) : KPARTITION;
    kCntNext = ((k-kIndex-KPARTITION) < KPARTITION) ? (k-kIndex-KPARTITION) : KPARTITION;
    flagLastK = ((kIndex+KPARTITION) < k) ? 0 : 1;

    //if(flagLastK) kCntNext = (k < KPARTITION) ? k : KPARTITION;

    for(mIndex = 0; mIndex<m; mIndex+=MPARTITION)  // partition in m dimension
    { // This is GEPB loop
      mCnt = ((m-mIndex) < MPARTITION) ? (m-mIndex) : MPARTITION;
      mCntNext = ((m-mIndex-MPARTITION) < MPARTITION) ? (m-mIndex-MPARTITION) : MPARTITION;
      flagLastM = ((mIndex+MPARTITION)<m) ? 0 : 1;

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
        aXferIndex += mCnt;
        aXferIndex = (!flagLastM) ? aXferIndex: aXferIndex-m+kCnt*lda;
        // Move A to L2 SRAM in desired contiguous arrangement
    	dataMoveAgemm(ptrASeg2, ptrASeg1, mCnt, kCnt, MPARTITION);
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
        	  memcpy(ptrASeg1+innerIndex_m*MPARTITION, a+aXferIndex+innerIndex_m*lda, mCntNext*sizeof(dataType));
          }
        }
      }
      else // A is in transposed form
      {
        aXferIndex += mCnt*lda;
        aXferIndex = (!flagLastM) ? aXferIndex: aXferIndex-m*lda+kCnt;
        // Move A to L2 SRAM in desired contiguous arrangement
        if(flagTransA == 1)
          dataMoveATgemm(ptrASeg2, ptrASeg1, mCnt, kCnt, KPARTITION);
        else
          dataMoveAHgemm(ptrASeg2, ptrASeg1, mCnt, kCnt, KPARTITION);
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
            	memcpy(ptrASeg1+innerIndex_m*KPARTITION, a+aXferIndex+innerIndex_m*lda, (flagLastM ? kCntNext : kCnt)*sizeof(dataType));
          }
        }
      }

      for(nIndex = 0; nIndex<n; nIndex+=NPARTITION)  // partition in n dimension
      {
        nCnt = ((n-nIndex) < NPARTITION) ? (n-nIndex) : NPARTITION;
        nCntNext = ((n-nIndex-NPARTITION) < NPARTITION) ? (n-nIndex-NPARTITION) : NPARTITION;
        flagLastN = ((nIndex+NPARTITION)<n) ? 0 : 1;

        if(flagLastN) nCntNext = (n < NPARTITION) ? n : NPARTITION;

        // bring in B into MSMC SRAM (a new parallel transfer)
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
            bXferIndex += nCnt*ldb;
            bXferIndex = (!flagLastN) ? bXferIndex: kIndex;
            bXferIndex = ((!flagLastN) || (!flagLastM)) ? bXferIndex: (kIndex+kCnt);
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
            bXferIndex += nCnt;
            bXferIndex = (!flagLastN) ? bXferIndex: kIndex*ldb;
            bXferIndex = ((!flagLastN) || (!flagLastM)) ? bXferIndex: (kIndex+kCnt)*ldb;
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
        	dataMoveBgemm(ptrBSeg, ptrB, kCnt);
            ptrB += (N_KERNEL*KPARTITION);
          }
          else if(flagTransB == 1)
          {
          	dataMoveBTgemm(ptrBSeg, ptrB, kCnt);
            ptrB += N_KERNEL;
          }
          else
          {
          	dataMoveBHgemm(ptrBSeg, ptrB, kCnt);
            ptrB += N_KERNEL;
          }

          // L2 memory assignment for B
          ptrA = ptrASeg2;
          // output memory assignment
          ptrC= c + mIndex + (nIndex+innerIndex_n)*ldc;

          for(innerIndex_m = 0; innerIndex_m<mCnt; innerIndex_m+=M_KERNEL)
          {

    	    // pre-fetch required A to L1 Cache
            // M_KERNELxk * kxN_KERNEL core matrix multiplications
            touch(ptrA, M_KERNEL * kCnt * sizeof(dataType));
    	    xgemmKernel(ptrA, ptrBSeg, ptrC, alpha, kCnt, ldc);
    	    // address of C to write to
    	    ptrC += M_KERNEL;
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

  return;

}
