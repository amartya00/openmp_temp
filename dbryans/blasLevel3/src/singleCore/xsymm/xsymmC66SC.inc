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
 *  @file   xsymmC66SC.inc
 *  @brief  This file single core xsymm/xhemm implementation.
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

// xsymm interface (designed to work with xhemm as well)
void xsymm(char side, char uplo,
		   int m, int n,
		   dataType alpha, dataType * restrict a, int lda,
           dataType * restrict b, int ldb,
           dataType beta,  dataType * restrict c, int ldc)
{
  int aXferIndex, bXferIndex, aXferIndex0, aXferIndex1;
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
  int flagSideisL = 0, flagUploisL = 0;
  short flagUseDMACopyA = 1, flagUseDMACopyB = 1;
  int part0, part1, kLoc;

  if((m==0) || (n==0)) return;

  if((side=='l') || (side=='L')) flagSideisL=1;
#ifdef HERMITIAN
  else if((side=='r') || (side=='R')) flagSideisL=-1;
#else
  else if((side=='r') || (side=='R')) flagSideisL=0;
#endif
  else
  {
	System_printf("%s non valid value for side: %d\n", XSYMM, side);
	return;
  }

  if((uplo=='l') || (uplo=='L')) flagUploisL=1;
  else if((uplo=='u') || (uplo=='U')) flagUploisL=0;
  else
  {
	System_printf("%s non valid value for uplo: %d\n", XSYMM, uplo);
	return;
  }


  // matA moved from DDR to MSMC here
  ptrASeg1  = Memory_allocMSMC((MPARTITION*KPARTITION+2*NPARTITION*KPARTITION)*sizeof(dataType), CACHELINE);
  // matA moved here after data placement needed per kernel
  ptrASeg2 = (dataType *) Memory_alloc((IHeap_Handle) l2Heap, (MPARTITION*KPARTITION+BANKOFFSET)*sizeof(dataType), CACHELINE, NULL);
  ptrBSeg  = (dataType *) Memory_alloc((IHeap_Handle) l1Heap, N_KERNEL*KPARTITION*sizeof(dataType), CACHELINE, NULL);

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
  if(beta != 1.0f) // only if scaling of C is needed
  {
	if(beta==0.0f)
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
  // re-define m, k, n to xgemm like definitions
  if(flagSideisL > 0)
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
    edmaLinkXfer();
    Cache_inv(ptrASeg1, MPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
  }

  if(flagUploisL)
  {
  	part1 = kCnt-mCnt;
  	part0 = kCnt-part1;
    aXferIndex0 = aXferIndex+part0*lda;
    aXferIndex1 =aXferIndex0/lda;
    aXferIndex0=(aXferIndex0-lda*aXferIndex1)*lda+aXferIndex1;
    if(flagUseDMACopyA)
    {
	  edmaInitiateXfer(ptrASeg1+part0*mCnt, a+aXferIndex0, part1*sizeof(dataType), mCnt, 1,
		  lda*sizeof(dataType), part1*sizeof(dataType), 1,
	      1, 2, 0);
	  edmaInitiateXfer(ptrASeg1, a+aXferIndex, mCnt*sizeof(dataType), part0, 1,
		  lda*sizeof(dataType), mCnt*sizeof(dataType), 1,
	      1, 0, 1);
    }
    else
    {
      for(innerIndex_m=0;innerIndex_m< part0; innerIndex_m++)
    	memcpy(ptrASeg1+innerIndex_m*mCnt, a+aXferIndex+innerIndex_m*lda, mCnt*sizeof(dataType));
      for(innerIndex_m=0;innerIndex_m< mCnt; innerIndex_m++)
    	memcpy(ptrASeg1+part0*mCnt+innerIndex_m*part1, a+aXferIndex0+innerIndex_m*lda, part1*sizeof(dataType));
    }
  }
  else // A is Upper
  {
	part0=0;
  	part1 = kCnt;
	aXferIndex0 = aXferIndex+part0*lda;
	if(flagUseDMACopyA)
	{
      edmaInitiateXfer(ptrASeg1+part0*mCnt, a+aXferIndex0, mCnt*sizeof(dataType), part1, 1,
		  lda*sizeof(dataType), mCnt*sizeof(dataType), 1,
	      1, 2, 0);
	  edmaInitiateXfer(ptrASeg1, a+aXferIndex0, part0*sizeof(dataType), mCnt, 1,
		  lda*sizeof(dataType), part0*sizeof(dataType), 1,
	      1, 0, 1);
	}
	else
	{
      for(innerIndex_m=0;innerIndex_m< part1; innerIndex_m++)
    	memcpy(ptrASeg1+part0*mCnt+innerIndex_m*mCnt, a+aXferIndex0+innerIndex_m*lda, mCnt*sizeof(dataType));
	}
  }
  // initiate first transfer of B to to MSMC SRAM
  if(flagUseDMACopyB)
  {
    Cache_inv(ptrBSeg1, NPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
  }
  if(flagSideisL > 0)
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
	if(flagSideisL > 0) bXferIndex = kIndex;
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
      if(flagUploisL)
      {
        // Move A to L2 SRAM in desired contiguous arrangement
        kLoc = (kIndex+kCnt)-(mIndex);
          if(kLoc <= 0)
          {
        	part1 = 0;
        	part0 = kCnt;
          }
          else if(kLoc<=mCnt)
          {
        	part1 = 0;
        	part0 = kCnt;
        	// transpose data
            dataMoveLsymm(ptrASeg1+mCnt*(kCnt-kLoc), kLoc, mCnt);
          }
          else if(kLoc<=kCnt)
          {
        	part1 = kLoc-mCnt;
        	part0 = kCnt-part1;
        	// transpose data
            dataMoveLsymm(ptrASeg1+mCnt*(part0-mCnt), mCnt, mCnt);
          }
          else if(kLoc <= kCnt+mCnt)
          {
        	part0 = 0;
        	part1 = kCnt;
        	// transpose data
            dataMoveLsymm(ptrASeg1+kCnt*(kLoc-kCnt), kCnt+mCnt-kLoc, kCnt);
          }
          else
          {
        	part0 = 0;
        	part1 = kCnt;
          }
    	  dataMoveALsymm(ptrASeg2, ptrASeg1, mCnt, part0, mCnt);
    	  dataMoveAUsymm(ptrASeg2+M_KERNEL*part0, ptrASeg1+mCnt*part0, mCnt, part1, part1);

        aXferIndex += mCnt;
        aXferIndex = (!flagLastM) ? aXferIndex: aXferIndex-m+kCnt*lda;
        if(flagUseDMACopyA)
        {
          Cache_inv(ptrASeg1, MPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
        }
        if((!flagLastM) || (!flagLastK)) // don't carry out DMA for the last iteration
        {
          kLoc = (flagLastM ? (kIndex+kCnt+kCntNext) : (kIndex+kCnt)-(mIndex+mCnt));
          if(kLoc <= 0)
          {
          	part1 = 0;
          	part0 = (flagLastM ? kCntNext : kCnt);
          }
          else if(kLoc<=mCntNext)
          {
          	part1 = 0;
          	part0 = (flagLastM ? kCntNext : kCnt);
          }
          else if(kLoc<=kCnt)
          {
          	part1 = kLoc-mCntNext;
          	part0 = (flagLastM ? kCntNext : kCnt)-part1;
          }
          else if(kLoc <= (flagLastM ? kCntNext : kCnt)+mCntNext)
          {
          	part0 = 0;
          	part1 = (flagLastM ? kCntNext : kCnt);
          }
          else
          {
          	part0 = 0;
          	part1 = (flagLastM ? kCntNext : kCnt);
          }

          aXferIndex0 = aXferIndex+part0*lda;
          aXferIndex1 =aXferIndex0/lda;
          aXferIndex0=(aXferIndex0-lda*aXferIndex1)*lda+aXferIndex1;
          if(flagUseDMACopyA)
          {
        	if(part0 < part1)
        	{
    	      edmaInitiateXfer(ptrASeg1+part0*mCntNext, a+aXferIndex0, part1*sizeof(dataType), mCntNext, 1,
    		    lda*sizeof(dataType), part1*sizeof(dataType), 1,
    	        1, 2, 0);
    	      edmaInitiateXfer(ptrASeg1, a+aXferIndex, mCntNext*sizeof(dataType), part0, 1,
    		    lda*sizeof(dataType), mCntNext*sizeof(dataType), 1,
    	        1, 0, 1);
        	}
        	else
        	{
      	      edmaInitiateXfer(ptrASeg1, a+aXferIndex, mCntNext*sizeof(dataType), part0, 1,
      		    lda*sizeof(dataType), mCntNext*sizeof(dataType), 1,
      	        1, 2, 0);
    	      edmaInitiateXfer(ptrASeg1+part0*mCntNext, a+aXferIndex0, part1*sizeof(dataType), mCntNext, 1,
    		    lda*sizeof(dataType), part1*sizeof(dataType), 1,
    	        1, 0, 1);
        	}
          }
          else
          {
            for(innerIndex_m=0;innerIndex_m< part0; innerIndex_m++)
        	  memcpy(ptrASeg1+innerIndex_m*mCntNext, a+aXferIndex+innerIndex_m*lda, mCntNext*sizeof(dataType));
            for(innerIndex_m=0;innerIndex_m< mCntNext; innerIndex_m++)
        	  memcpy(ptrASeg1+part0*mCntNext+innerIndex_m*part1, a+aXferIndex0+innerIndex_m*lda, part1*sizeof(dataType));
          }
        }
    	// move data in desired contiguous location
      }
      else // A is in upper
      {
          kLoc = (kIndex+kCnt)-(mIndex);
          // Move A to L2 SRAM in desired contiguous arrangement
          if(kLoc > kCnt+mCnt)
          {
          	part0 = 0;
          	part1 = kCnt;
          }
          else if(kLoc > kCnt)
          {
          	part0 = 0;
          	part1 = kCnt;
          	// transpose data
            dataMoveUsymm(ptrASeg1+kLoc-kCnt, kCnt+mCnt-kLoc, mCnt);
          }
          else if(kLoc > mCnt)
          {
          	part1 = kLoc;
          	part0 = kCnt-part1;
          	// transpose data
            dataMoveUsymm(ptrASeg1+mCnt*part0, mCnt, mCnt);
          }
          else if(kLoc > 0)
          {
          	part1 = 0;
          	part0 = kCnt;
          	// transpose data
            dataMoveUsymm(ptrASeg1+kCnt-kLoc, kLoc, kCnt);
          }
          else
          {
          	part1 = 0;
          	part0 = kCnt;
          }

        dataMoveAUsymm(ptrASeg2, ptrASeg1, mCnt, part0, part0);
      	dataMoveALsymm(ptrASeg2+M_KERNEL*part0, ptrASeg1+mCnt*part0, mCnt, part1, mCnt);

        aXferIndex += mCnt;
        aXferIndex = (!flagLastM) ? aXferIndex: aXferIndex-m+kCnt*lda;
        if(flagUseDMACopyA)
        {
          Cache_inv(ptrASeg1, MPARTITION*KPARTITION*sizeof(dataType), Cache_Type_L1D, 1);
        }
        if((!flagLastM) || (!flagLastK)) // don't carry out DMA for the last iteration
        {
            kLoc = (flagLastM ? (kIndex+kCnt+kCntNext) : (kIndex+kCnt)-(mIndex+mCnt));
            if(kLoc > (flagLastM ? kCntNext : kCnt)+mCntNext)
            {
            	part0 = 0;
            	part1 = (flagLastM ? kCntNext : kCnt);
            }
            else if(kLoc > (flagLastM ? kCntNext : kCnt))
            {
            	part0 = 0;
            	part1 = (flagLastM ? kCntNext : kCnt);
            }
            else if(kLoc > mCntNext)
            {
            	part1 = kLoc;
            	part0 = (flagLastM ? kCntNext : kCnt)-part1;
            }
            else if(kLoc > 0)
            {
            	part1 = 0;
            	part0 = (flagLastM ? kCntNext : kCnt);
            }
            else
            {
            	part1 = 0;
            	part0 = (flagLastM ? kCntNext : kCnt);
            }
            aXferIndex0 = aXferIndex;
            aXferIndex1 =aXferIndex0/lda;
            aXferIndex0=(aXferIndex0-lda*aXferIndex1)*lda+aXferIndex1;
            if(flagUseDMACopyA)
            {
              if(part0 < part1)
              {
      	        edmaInitiateXfer(ptrASeg1, a+aXferIndex0, part0*sizeof(dataType), mCntNext, 1,
      		      lda*sizeof(dataType), part0*sizeof(dataType), 1,
      	          1, 2, 0);
      	        edmaInitiateXfer(ptrASeg1+part0*mCntNext, a+aXferIndex+part0*lda, mCntNext*sizeof(dataType), part1, 1,
      		      lda*sizeof(dataType), mCntNext*sizeof(dataType), 1,
      	          1, 0, 1);
              }
              else
              {
        	    edmaInitiateXfer(ptrASeg1+part0*mCntNext, a+aXferIndex+part0*lda, mCntNext*sizeof(dataType), part1, 1,
        		  lda*sizeof(dataType), mCntNext*sizeof(dataType), 1,
        	       1, 2, 0);
      	        edmaInitiateXfer(ptrASeg1, a+aXferIndex0, part0*sizeof(dataType), mCntNext, 1,
      		      lda*sizeof(dataType), part0*sizeof(dataType), 1,
      	          1, 0, 1);
              }
            }
            else
            {
              for(innerIndex_m=0;innerIndex_m< mCntNext; innerIndex_m++)
       	        memcpy(ptrASeg1+innerIndex_m*part0, a+aXferIndex0+innerIndex_m*lda, part0*sizeof(dataType));
              aXferIndex0 = aXferIndex+part0*lda;
              for(innerIndex_m=0;innerIndex_m< part1; innerIndex_m++)
       	        memcpy(ptrASeg1+part0*mCntNext+innerIndex_m*mCntNext, a+aXferIndex0+innerIndex_m*lda, mCntNext*sizeof(dataType));
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
          if(flagSideisL > 0)
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
          if(flagSideisL > 0)
          {
        	dataMoveBsymm(ptrBSeg, ptrB, kCnt);
            ptrB += (N_KERNEL*KPARTITION);
          }
          else
          {
          	dataMoveBTsymm(ptrBSeg, ptrB, kCnt);
            ptrB += N_KERNEL;
          }

          // L2 memory assignment for B
          ptrA = ptrASeg2;
          // output memory assignment
          if(flagSideisL > 0) ptrC= c + mIndex + (nIndex+innerIndex_n)*ldc;
          else ptrC= c + mIndex*ldc + (nIndex+innerIndex_n);

          for(innerIndex_m = 0; innerIndex_m<mCnt; innerIndex_m+=M_KERNEL)
          {

    	    // pre-fetch required A to L1 Cache
            // 4xk * kxN_KERNEL core matrix multiplications
            touch(ptrA, M_KERNEL * kCnt * sizeof(dataType));
    	    xsymmKernel(ptrA, ptrBSeg, ptrC, alpha, kCnt, ldc, N_KERNEL, flagSideisL);
    	    // address of C to write to
      	    if(flagSideisL > 0) ptrC += M_KERNEL;
      	    else ptrC += (M_KERNEL*ldc);
    	    ptrA += (M_KERNEL*KPARTITION);

          } // inner loop m
        } // inner loop n
      } // n loop
    } // m loop
  } // k loop

  if(flagUseDMACopyA)
  {
    edmaUnLinkXfer();
  }
    
  Memory_freeMSMC(ptrASeg1, (MPARTITION*KPARTITION+2*NPARTITION*KPARTITION)*sizeof(dataType));
  Memory_free((IHeap_Handle) l2Heap, ptrASeg2-BANKOFFSET, (MPARTITION*KPARTITION+BANKOFFSET)*sizeof(dataType));
  Memory_free((IHeap_Handle) l1Heap, ptrBSeg, N_KERNEL*KPARTITION*sizeof(dataType));

  // do a global cache write-back from all local data memory
  CACHE_wbInvAllL1d(CACHE_WAIT);
  CACHE_wbInvAllL2(CACHE_WAIT);

  return;
}
