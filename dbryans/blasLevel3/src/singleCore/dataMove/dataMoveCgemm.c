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
 *  @file   dataMoveCgemm.h
 *  @brief  This file contains various data movement functions needed for cgemm
 *
 */

#include "c6x.h"
#include "dataMoveCgemm.h"
#include "defCC66.h"

// moving B-Hermitian from L2 to L1
void dataMoveBHCgemm(complex * restrict dst, complex * restrict src, int k)
{
  int kCnt;
  __float2_t * restrict ptrDst = (__float2_t *) dst;
  __float2_t * restrict ptrSrc = (__float2_t *) src;
  _nassert((unsigned int) ptrSrc%8 == 0);
  _nassert((unsigned int) ptrDst%8 == 0);

  for(kCnt=0; kCnt<k; kCnt++)
  {
	__float2_t data;
    data = *ptrSrc++;
    *ptrDst++ = _ftof2(-_hif(data),_lof(data));
    data = *ptrSrc++;
    *ptrDst++ = _ftof2(-_hif(data),_lof(data));
    data = *ptrSrc++;
    *ptrDst++ = _ftof2(-_hif(data),_lof(data));
    data = *ptrSrc++;
    *ptrDst++ = _ftof2(-_hif(data),_lof(data));

	ptrSrc += (NPARTITION_C-4);
  }
}

// moving B' from L2 to L1
void dataMoveBTCgemm(complex * restrict dst, complex * restrict src, int k)
{
  int kCnt;
  __float2_t * restrict ptrDst = (__float2_t *) dst;
  __float2_t * restrict ptrSrc = (__float2_t *) src;
  _nassert((unsigned int) ptrSrc%8 == 0);
  _nassert((unsigned int) ptrDst%8 == 0);

  for(kCnt=0; kCnt<k; kCnt++)
  {
	*ptrDst++ = *ptrSrc++;
	*ptrDst++ = *ptrSrc++;
	*ptrDst++ = *ptrSrc++;
	*ptrDst++ = *ptrSrc++;

	ptrSrc += (NPARTITION_C-4);
  }
}

// moving B from L2 to L1 (needs transpose)
void dataMoveBCgemm(complex * restrict dst, complex * restrict src, int k)
{
  int kCnt;
  __float2_t * restrict ptrDst = (__float2_t *) dst;
  __float2_t * restrict ptrSrc0 = (__float2_t *) src;
  __float2_t * restrict ptrSrc1 = ptrSrc0 + KPARTITION_C;
  __float2_t * restrict ptrSrc2 = ptrSrc1 + KPARTITION_C;
  __float2_t * restrict ptrSrc3 = ptrSrc2 + KPARTITION_C;
  _nassert((unsigned int) ptrSrc0%8 == 0);
  _nassert((unsigned int) ptrSrc1%8 == 0);
  _nassert((unsigned int) ptrSrc2%8 == 0);
  _nassert((unsigned int) ptrSrc3%8 == 0);
  _nassert((unsigned int) ptrDst%8 == 0);

  for(kCnt=0; kCnt<k; kCnt++)
  {
	*ptrDst++ = *ptrSrc0++;
	*ptrDst++ = *ptrSrc1++;
	*ptrDst++ = *ptrSrc2++;
	*ptrDst++ = *ptrSrc3++;

  }
}

// moving data from A to format needed for kernel
void dataMoveACgemm(complex * restrict dst, complex * restrict src, int m, int k, int mPartition)
{
  int kCnt, mCnt;
  __float2_t * restrict ptrDst;
  __float2_t * restrict ptrSrc;

  for(mCnt=0;mCnt<(m>>1);mCnt++)
  {
	ptrDst  = ((__float2_t *) dst) + ((mCnt<<1)*KPARTITION_C);
	ptrSrc  = ((__float2_t *) src) + (mCnt<<1);
	for(kCnt=0;kCnt<k;kCnt++)
	{
	  // load M_KERNEL floats sequentially
	  *ptrDst++ = *ptrSrc++;
	  *ptrDst++ = *ptrSrc++;

	  ptrSrc += (mPartition-2);
	}
  }

  if(m&1) // one more set to push
  {
	ptrDst  = ((__float2_t *) dst) + ((m-1)*KPARTITION_C);
	ptrSrc  = ((__float2_t *) src) + (m-1);
	for(kCnt=0;kCnt<k;kCnt++)
	{
	  *ptrDst = *ptrSrc;

	  ptrDst += 2;
	  ptrSrc += (mPartition);
	}
  }
}

// moving data from A' to format needed for kernel
void dataMoveATCgemm(complex * restrict dst, complex * restrict src, int m, int k, int kPartition)
{
  int kCnt, mCnt;
  __float2_t * restrict ptrDst;
  __float2_t * restrict ptrSrc0;
  __float2_t * restrict ptrSrc1;

  for(mCnt=0;mCnt<(m>>1);mCnt++)
  {
	ptrDst  = ((__float2_t *) dst) + ((mCnt<<1)*KPARTITION_C);
	ptrSrc0  = ((__float2_t *) src) + ((mCnt<<1)*kPartition);
	ptrSrc1  = ((__float2_t *) src) + (((mCnt<<1)+1)*kPartition);
	for(kCnt=0;kCnt<k;kCnt++)
	{
	  // load M_KERNEL floats sequentially
	  *ptrDst++ = *ptrSrc0++;
	  *ptrDst++ = *ptrSrc1++;
	}
  }

  if(m&1) // one more set to push
  {
	ptrDst  = ((__float2_t *) dst) + ((m-1)*KPARTITION_C);
	ptrSrc0  = ((__float2_t *) src) + (m-1)*kPartition;
	for(kCnt=0;kCnt<k;kCnt++)
	{
	  *ptrDst = *ptrSrc0++;

	  ptrDst += 2;
	}
  }
}

// moving data from A-Hermitian to format needed for kernel
void dataMoveAHCgemm(complex * restrict dst, complex * restrict src, int m, int k, int kPartition)
{
  int kCnt, mCnt;
  __float2_t * restrict ptrDst;
  __float2_t * restrict ptrSrc0;
  __float2_t * restrict ptrSrc1;

  for(mCnt=0;mCnt<(m>>1);mCnt++)
  {
	ptrDst  = ((__float2_t *) dst) + ((mCnt<<1)*KPARTITION_C);
	ptrSrc0  = ((__float2_t *) src) + ((mCnt<<1)*kPartition);
	ptrSrc1  = ((__float2_t *) src) + (((mCnt<<1)+1)*kPartition);
	for(kCnt=0;kCnt<k;kCnt++)
	{
	  __float2_t data;
	  data = *ptrSrc0++;
	  *ptrDst++ = _ftof2(-_hif(data),_lof(data));
	  data = *ptrSrc1++;
	  *ptrDst++ = _ftof2(-_hif(data),_lof(data));
	}
  }

  if(m&1) // one more set to push
  {
	ptrDst  = ((__float2_t *) dst) + ((m-1)*KPARTITION_C);
	ptrSrc0  = ((__float2_t *) src) + (m-1)*kPartition;
	for(kCnt=0;kCnt<k;kCnt++)
	{
	  __float2_t data;
	  data = *ptrSrc0++;
	  *ptrDst = _ftof2(-_hif(data),_lof(data));

	  ptrDst += 2;
	}
  }
}

