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
 *  @file   dataMoveZgemm.h
 *  @brief  This file contains various data movement functions needed for zgemm
 *
 */

#include "dataMoveZgemm.h"
#include "defZC66.h"

// moving B-Hermitian from L2 to L1
void dataMoveBHZgemm(doublecomplex * restrict dst, doublecomplex * restrict src, int k)
{
  int kCnt;
  double * restrict ptrDst = (double *) dst;
  double * restrict ptrSrc = (double *) src;
  _nassert((unsigned int) ptrDst%8 == 0);
  _nassert((unsigned int) ptrSrc%8 == 0);

  for(kCnt=0; kCnt<k; kCnt++)
  {
	*ptrDst++ = (*ptrSrc++);
	*ptrDst++ = -(*ptrSrc++);

	ptrSrc += ((NPARTITION_Z-1)<<1);
  }
}

// moving B' from L2 to L1
void dataMoveBTZgemm(doublecomplex * restrict dst, doublecomplex * restrict src, int k)
{
  int kCnt;
  double * restrict ptrDst = (double *) dst;
  double * restrict ptrSrc = (double *) src;
  _nassert((unsigned int) ptrDst%8 == 0);
  _nassert((unsigned int) ptrSrc%8 == 0);

  for(kCnt=0; kCnt<k; kCnt++)
  {
	*ptrDst++ = (*ptrSrc++);
	*ptrDst++ = (*ptrSrc++);

	ptrSrc += ((NPARTITION_Z-1)<<1);
  }
}

// moving B from L2 to L1 (needs transpose)
void dataMoveBZgemm(doublecomplex * restrict dst, doublecomplex * restrict src, int k)
{
  int kCnt;
  double * restrict ptrDst = (double *) dst;
  double * restrict ptrSrc = (double *) src;
  _nassert((unsigned int) ptrDst%8 == 0);
  _nassert((unsigned int) ptrSrc%8 == 0);

  for(kCnt=0; kCnt<k; kCnt++)
  {
	*ptrDst++ = (*ptrSrc++);
	*ptrDst++ = (*ptrSrc++);
  }
}

// moving data from A to format needed for kernel
void dataMoveAZgemm(doublecomplex * restrict dst, doublecomplex * restrict src, int m, int k, int mPartition)
{
  int kCnt, mCnt;
  double * restrict ptrDst = (double *) dst;
  double * restrict ptrSrc = (double *) src;
  _nassert((unsigned int) ptrDst%8 == 0);
  _nassert((unsigned int) ptrSrc%8 == 0);

  for(mCnt=0;mCnt<m;mCnt++)
  {
	ptrDst  = ((double *) dst) + ((mCnt*KPARTITION_Z)<<1);
	ptrSrc  = ((double *) src) + (mCnt<<1);
    for(kCnt=0; kCnt<k; kCnt++)
    {
	  *ptrDst++ = (*ptrSrc++);
	  *ptrDst++ = (*ptrSrc++);

	  ptrSrc += ((mPartition-1)<<1);
    }
  }
}

// moving data from A' to format needed for kernel
void dataMoveATZgemm(doublecomplex * restrict dst, doublecomplex * restrict src, int m, int k, int kPartition)
{
  int kCnt, mCnt;
  double * restrict ptrDst = (double *) dst;
  double * restrict ptrSrc = (double *) src;
  _nassert((unsigned int) ptrDst%8 == 0);
  _nassert((unsigned int) ptrSrc%8 == 0);

  for(mCnt=0;mCnt<m;mCnt++)
  {
	ptrDst  = ((double *) dst) + ((mCnt*KPARTITION_Z)<<1);
	ptrSrc  = ((double *) src) + ((mCnt*kPartition)<<1);
    for(kCnt=0; kCnt<k; kCnt++)
    {
	  *ptrDst++ = (*ptrSrc++);
	  *ptrDst++ = (*ptrSrc++);
    }
  }
}

// moving data from A-Hermitian to format needed for kernel
void dataMoveAHZgemm(doublecomplex * restrict dst, doublecomplex * restrict src, int m, int k, int kPartition)
{
	  int kCnt, mCnt;
	  double * restrict ptrDst = (double *) dst;
	  double * restrict ptrSrc = (double *) src;
	  _nassert((unsigned int) ptrDst%8 == 0);
	  _nassert((unsigned int) ptrSrc%8 == 0);

	  for(mCnt=0;mCnt<m;mCnt++)
	  {
		ptrDst  = ((double *) dst) + ((mCnt*KPARTITION_Z)<<1);
		ptrSrc  = ((double *) src) + ((mCnt*kPartition)<<1);
	    for(kCnt=0; kCnt<k; kCnt++)
	    {
		  *ptrDst++ = (*ptrSrc++);
		  *ptrDst++ = -(*ptrSrc++);
	    }
	  }
}

