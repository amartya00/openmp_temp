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
 *  @file   xsurkInternalSC.inc
 *  @brief  This file contains single core xsyrk/xherk/xsyr2k/xher3k implementation.
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

// xsyrk interface (designed to operate with xsyr2k, xherk, and xher2k)
void xsyrkInternal(char uplo, char trans,
		   int n, int k,
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
  int flagTransAisN = 0, flagTransBisN = 0, flagUploisL = 0;
  short flagUseDMACopyA = 1, flagUseDMACopyB = 1;
  int mStart, mLast;
  int nStart, nLast, nLoc, m;

  if((n==0) || (k==0)) return;

  m = n;

  if((uplo=='l') || (uplo=='L')) flagUploisL=1;
#ifdef HERMITIAN
  else if((uplo=='u') || (uplo=='U')) flagUploisL=-1;
#else
  else if((uplo=='u') || (uplo=='U')) flagUploisL=0;
#endif
  else
  {
	System_printf("%s non valid value for side: %c\n", XSYRK, uplo);
	return;
  }

  if((trans=='n') || (trans=='N'))
  {
		flagTransAisN=1;
		flagTransBisN=0;
  }
#ifdef HERMITIAN
  else if((trans=='c') || (trans=='C'))
#else
  else if((trans=='t') || (trans=='T'))
#endif
  {
		flagTransAisN=0;
		flagTransBisN=1;
  }
  else
  {
	System_printf("%s non valid value for trans: %c\n", XSYRK, trans);
	return;
  }

  // matA moved from DDR to MSMC here
  ptrASeg1  = (dataType *) Memory_allocMSMC((MPARTITION*KPARTITION+2*NPARTITION*KPARTITION)*sizeof(dataType), BUFALIGN);
  // matA moved here after data placement needed per kernel
  ptrASeg2 = (dataType *) Memory_alloc((IHeap_Handle) l2Heap, (MPARTITION*KPARTITION+BANKOFFSET)*sizeof(dataType), BUFALIGN, NULL);
  ptrASeg2 += BANKOFFSET;
  ptrBSeg  = (dataType *) Memory_alloc((IHeap_Handle) l1Heap, N_KERNEL*KPARTITION*sizeof(dataType), BUFALIGN, NULL);

  // matB ping pong buffer here
  ptrBSeg1 = ptrASeg1+(MPARTITION*KPARTITION);
  ptrBSeg2 = ptrBSeg1+(NPARTITION*KPARTITION);

  // Scale C = beta * C here.
#ifdef COMPLEX
  if(flagUploisL>0) // C is lower triangular
  {
	if(!((beta.r == (baseType) 1.0) && (beta.i == (baseType) 0.0))) // only if scaling of C is needed
    {
	  if((beta.r==(baseType) 0.0) && (beta.i==(baseType) 0.0))
	  {
		for(nCnt=0;nCnt<m;nCnt++)
		{
		  memset(c+nCnt*ldc+nCnt,0,(m-nCnt)*sizeof(dataType)); // zero out c column by column
		}
	  } // if(beta==0.0)
	  else
	  {
		for(nCnt=0;nCnt<n;nCnt++)
		{
		  for(mCnt=nCnt;mCnt<m;mCnt++)
		  {
			  baseType temp;
			  temp = c[nCnt*ldc+mCnt].r * beta.r - c[nCnt*ldc+mCnt].i * beta.i;
			  c[nCnt*ldc+mCnt].i = c[nCnt*ldc+mCnt].r * beta.i + c[nCnt*ldc+mCnt].i * beta.r;
			  c[nCnt*ldc+mCnt].r = temp;
		  }
		}
	  } // else
    } // if(beta != 1.0f)
  }
  else  // C is upper triangular
  {
	if(!((beta.r == (baseType) 1.0) && (beta.i == (baseType) 0.0))) // only if scaling of C is needed
	{
	  if((beta.r==(baseType) 0.0) && (beta.i==(baseType) 0.0))
	  {
		for(nCnt=0;nCnt<m;nCnt++)
		{
		  memset(c+nCnt*ldc,0,(nCnt+1)*sizeof(dataType)); // zero out c column by column
		}
	  } // if(beta==0.0)
	  else
	  {
		for(nCnt=0;nCnt<n;nCnt++)
		{
		  for(mCnt=0;mCnt<nCnt+1;mCnt++)
		  {
			  baseType temp;
			  temp = c[nCnt*ldc+mCnt].r * beta.r - c[nCnt*ldc+mCnt].i * beta.i;
			  c[nCnt*ldc+mCnt].i = c[nCnt*ldc+mCnt].r * beta.i + c[nCnt*ldc+mCnt].i * beta.r;
			  c[nCnt*ldc+mCnt].r = temp;
		  }
		}
	  } // else
	} // if(beta != 1.0f)
  }
#else
  if(flagUploisL>0) // C is lower triangular
  {
    if(beta != 1.0f) // only if scaling of C is needed
    {
	  if(beta==0.0f)
	  {
		for(nCnt=0;nCnt<m;nCnt++)
		{
		  memset(c+nCnt*ldc+nCnt,0,(m-nCnt)*sizeof(dataType)); // zero out c column by column
		}
	  } // if(beta==0.0f)
	  else
	  {
		for(nCnt=0;nCnt<m;nCnt++)
		{
		  for(mCnt=nCnt;mCnt<m;mCnt++)
		  {
			c[nCnt*ldc+mCnt] *= beta; // column by column multiplication
		  }
		}
	  } // else
    } // if(beta != 1.0f)
  }
  else  // C is upper triangular
  {
	if(beta != 1.0f) // only if scaling of C is needed
	{
	  if(beta==0.0f)
	  {
		for(nCnt=0;nCnt<m;nCnt++)
		{
		  memset(c+nCnt*ldc,0,(nCnt+1)*sizeof(dataType)); // zero out c column by column
		}
	  } // if(beta==0.0f)
	  else
	  {
 		for(nCnt=0;nCnt<m;nCnt++)
		{
		  for(mCnt=0;mCnt<nCnt+1;mCnt++)
		  {
			c[nCnt*ldc+mCnt] *= beta; // column by column multiplication
		  }
		}
	  } // else
	} // if(beta != 1.0f)
  }
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
  if(flagTransAisN)
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
  if(flagTransBisN)
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
    kCnt = ((k-kIndex) < KPARTITION) ? (k-kIndex) : KPARTITION;
    kCntNext = ((k-kIndex-KPARTITION) < KPARTITION) ? (k-kIndex-KPARTITION) : KPARTITION;
    flagLastK = ((kIndex+KPARTITION) < k) ? 0 : 1;

    //if(flagLastK) kCntNext = (k < KPARTITION) ? k : KPARTITION;

    for(mIndex = 0; mIndex<m; mIndex+=MPARTITION)  // partition in m dimension
    { // This is GEPB loop
      // This is GEPP loop
      if(flagTransBisN) bXferIndex = kIndex;
      else bXferIndex = kIndex*ldb;  // B is in transposed form

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
      if(flagTransAisN)
      {
        aXferIndex += mCnt;
        aXferIndex = (!flagLastM) ? aXferIndex: aXferIndex-m+kCnt*lda;
        // Move A to L2 SRAM in desired contiguous arrangement
        dataMoveAsyrk(ptrASeg2, ptrASeg1, mCnt, kCnt, MPARTITION);
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
    	// move data in desired contiguous location
      }
      else // A is in transposed form
      {
        aXferIndex += mCnt*lda;
        aXferIndex = (!flagLastM) ? aXferIndex: aXferIndex-m*lda+kCnt;
        // Move A to L2 SRAM in desired contiguous arrangement
        dataMoveATsyrk(ptrASeg2, ptrASeg1, mCnt, kCnt, KPARTITION);
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

	  nStart = 0;
	  nLast=mIndex+mCnt;
      if(flagTransBisN) bXferIndex += nStart*ldb;
      else bXferIndex += nStart;  // B is in transposed form

      for(nIndex = nStart; nIndex<nLast; nIndex+=NPARTITION)  // partition in n dimension
      {
        nCnt = ((nLast-nIndex) < NPARTITION) ? (nLast-nIndex) : NPARTITION;
        nCntNext = ((nLast-nIndex-NPARTITION) < NPARTITION) ? (nLast-nIndex-NPARTITION) : NPARTITION;
        flagLastN = ((nIndex+NPARTITION)<nLast) ? 0 : 1;

        if(flagLastN) nCntNext = (nLast < NPARTITION) ? nLast : NPARTITION;

        // bring in B into L1 SRAM (a new parallel transfer)
        indexBCurrent = (indexBCurrent+1) & 1;
        indexBNext = (indexBNext+1) & 1;

        if(flagUseDMACopyB)
        {
          edmaWait4Completion(1);
        }
        if((!flagLastM) || (!flagLastK) || (!flagLastN)) // don't carry out DMA for the last iteration
        {
          if(flagTransBisN)
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
          if(flagTransBisN)
          {
        	dataMoveBsyrk(ptrBSeg, ptrB, kCnt);
            ptrB += (N_KERNEL*KPARTITION);
          }
          else
          {
          	dataMoveBTsyrk(ptrBSeg, ptrB, kCnt);
            ptrB += N_KERNEL;
          }

          // L2 memory assignment for B
          ptrA = ptrASeg2;
          // output memory assignment
          if(flagUploisL>0) ptrC= c + mIndex + (nIndex+innerIndex_n)*ldc;
          else ptrC= c + mIndex*ldc + (nIndex+innerIndex_n);

		  nLoc = (mIndex)-(nIndex+innerIndex_n);
		  if(nLoc>-M_KERNEL) mStart = 0;
		  else
		  {
		    mStart = -nLoc;
		    nLoc = - (mStart & (M_KERNEL-1));
		  }

		  mLast = mCnt;
		  ptrA += (mStart*KPARTITION);
		  if(flagUploisL>0) ptrC += (mStart);
		  else ptrC += (mStart*ldc);

		  for(innerIndex_m = mStart; innerIndex_m<mLast; innerIndex_m+=M_KERNEL)
          {

    	    // pre-fetch required A to L1 Cache
            // M_KERNEL by k *  k by N_KERNEL core matrix multiplications
            touch(ptrA, M_KERNEL * kCnt * sizeof(dataType));
    	    xsyrkKernelFlexSave(ptrA, ptrBSeg, ptrC, alpha, kCnt, ldc, nLoc, flagUploisL);
    	    // address of C to write to
      	    nLoc += M_KERNEL;
      	    if(flagUploisL>0) ptrC += M_KERNEL;
      	    else ptrC += (M_KERNEL*ldc);
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
