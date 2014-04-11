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
 *  @file   dataMoveSgemm.h
 *  @brief  This file contains various data movement functions needed for SGEMM
 *
 */

#include "dataMoveSgemm.h"
#include "defSC66.h"

// moving B' from L2 to L1
void dataMoveBTSgemm(real * restrict dst, real * restrict src, int k)
{
  int kCnt;
  int srcAddr;
  int dstAddr;
  _nassert((unsigned int) src%8 == 0);
  _nassert((unsigned int) dst%8 == 0);

  srcAddr = 0;
  dstAddr = 0;
  for(kCnt=0; kCnt<k; kCnt++)
  {
	dst[dstAddr]   = src[srcAddr];
	dst[dstAddr+1] = src[srcAddr+1];
	dst[dstAddr+2] = src[srcAddr+2];
	dst[dstAddr+3] = src[srcAddr+3];
	dst[dstAddr+4] = src[srcAddr+4];
	dst[dstAddr+5] = src[srcAddr+5];
	dst[dstAddr+6] = src[srcAddr+6];
	dst[dstAddr+7] = src[srcAddr+7];

	dstAddr += N_KERNEL_S;
	srcAddr += NPARTITION_S;

  }
}

// moving B from L2 to L1 (needs transpose)
void dataMoveBSgemm(real * restrict dst, real * restrict src, int k)
{
  int kCnt;
  int srcAddr0, srcAddr1, srcAddr2, srcAddr3;
  int srcAddr4, srcAddr5, srcAddr6, srcAddr7;
  int dstAddr;

  srcAddr0 = 0;
  srcAddr1 = KPARTITION_S/*k*/;
  srcAddr2 = 2*KPARTITION_S/*k*/;
  srcAddr3 = 3*KPARTITION_S/*k*/;
  srcAddr4 = 4*KPARTITION_S/*k*/;
  srcAddr5 = 5*KPARTITION_S/*k*/;
  srcAddr6 = 6*KPARTITION_S/*k*/;
  srcAddr7 = 7*KPARTITION_S/*k*/;
  dstAddr  = 0;

  _nassert((unsigned int) src%8 == 0);
  _nassert((unsigned int) dst%8 == 0);
//#pragma UNROLL(2) // unrolling by 2; valid for even k
  for(kCnt=0; kCnt<((k>>1)<<1); kCnt++)
  {
	real f0, f1, f2, f3, f4, f5, f6, f7;
	f0=src[srcAddr0];
	f1=src[srcAddr1];
	f2=src[srcAddr2];
	f3=src[srcAddr3];
	f4=src[srcAddr4];
	f5=src[srcAddr5];
	f6=src[srcAddr6];
	f7=src[srcAddr7];

	srcAddr0++;
	srcAddr1++;
	srcAddr2++;
	srcAddr3++;
	srcAddr4++;
	srcAddr5++;
	srcAddr6++;
	srcAddr7++;

	dst[dstAddr] = f0;
	dst[dstAddr+1] = f1;
	dst[dstAddr+2] = f2;
	dst[dstAddr+3] = f3;
	dst[dstAddr+4] = f4;
	dst[dstAddr+5] = f5;
	dst[dstAddr+6] = f6;
	dst[dstAddr+7] = f7;

	dstAddr += N_KERNEL_S;
  }
  if((k&1)==1) // odd k; one more value to take care
  {
	real f0, f1, f2, f3, f4, f5, f6, f7;
	f0=src[srcAddr0];
	f1=src[srcAddr1];
	f2=src[srcAddr2];
	f3=src[srcAddr3];
	f4=src[srcAddr4];
	f5=src[srcAddr5];
	f6=src[srcAddr6];
	f7=src[srcAddr7];

	dst[dstAddr] = f0;
	dst[dstAddr+1] = f1;
	dst[dstAddr+2] = f2;
	dst[dstAddr+3] = f3;
	dst[dstAddr+4] = f4;
	dst[dstAddr+5] = f5;
	dst[dstAddr+6] = f6;
	dst[dstAddr+7] = f7;
  }
}

// moving data from A to format needed for kernel
void dataMoveASgemm(real * restrict dst, real * restrict src, int m, int k, int mPartition)
{
  int kCnt, mCnt, mLeft;
  int srcAddr, dstAddr;

  mLeft=m-((m>>2)<<2);

  _nassert((unsigned int) src%8 == 0);
  _nassert((unsigned int) dst%8 == 0);
  for(kCnt=0;kCnt<k;kCnt++){
	for(mCnt=0;mCnt<(m>>2);mCnt++)
	{
	  real f0, f1, f2, f3;
	  srcAddr = (kCnt*mPartition/*m*/)+(mCnt<<2);
	  dstAddr = (mCnt*(KPARTITION_S/*k*/<<2))+(kCnt<<2);
	  // load M_KERNEL floats sequentially
	  f0 = src[srcAddr];
	  f1 = src[srcAddr+1];
	  f2 = src[srcAddr+2];
	  f3 = src[srcAddr+3];

	  // push M_KERNEL floats to desired loc
      dst[dstAddr] = f0;
      dst[dstAddr+1] = f1;
      dst[dstAddr+2] = f2;
      dst[dstAddr+3] = f3;
	}
	// leftover in m dimension of A
 	srcAddr = kCnt*mPartition/*m*/+((m>>2)<<2);
   	dstAddr = ((m>>2)*(KPARTITION_S/*k*/<<2))+(kCnt<<2);
    for(mCnt=0;mCnt<mLeft;mCnt++)
    {
      dst[dstAddr+mCnt] = src[srcAddr+mCnt];
    }
  }
}

// moving data from A' to format needed for kernel
void dataMoveATSgemm(real * restrict dst, real * restrict src, int m, int k, int kPartition)
{
  int mCnt, kCnt, mLeft;
  int srcAddr, dstAddr;

  mLeft=m-((m>>2)<<2);
  _nassert((unsigned int) src%8 == 0);
  _nassert((unsigned int) dst%8 == 0);
  for(kCnt=0;kCnt<(k>>1);kCnt++){
	for(mCnt=0;mCnt<(m>>2);mCnt++)
	{
	  real f00, f01, f02, f03;
	  real f10, f11, f12, f13;
	  srcAddr = (mCnt<<2)*kPartition/*k*/+(kCnt<<1);
	  dstAddr = (mCnt*(KPARTITION_S/*k*/<<2))+(kCnt<<3);

	  // load 2 x M_KERNEL floats
	  f00 = src[srcAddr];
	  f10 = src[srcAddr+1];
	  f01 = src[srcAddr+kPartition/*k*/];
	  f11 = src[srcAddr+kPartition/*k*/+1];
	  f02 = src[srcAddr+2*kPartition/*k*/];
	  f12 = src[srcAddr+2*kPartition/*k*/+1];
	  f03 = src[srcAddr+3*kPartition/*k*/];
	  f13 = src[srcAddr+3*kPartition/*k*/+1];

	  // push 2 x M_KERNEL floats to desired loc
      dst[dstAddr]   = f00;
      dst[dstAddr+1] = f01;
      dst[dstAddr+2] = f02;
      dst[dstAddr+3] = f03;
      dst[dstAddr+4] = f10;
      dst[dstAddr+5] = f11;
      dst[dstAddr+6] = f12;
      dst[dstAddr+7] = f13;
	}
	// leftover in m dimension of A
  	srcAddr = ((m>>2)<<2)*kPartition/*k*/+(kCnt<<1);
   	dstAddr = ((m>>2)*(KPARTITION_S/*k*/<<2))+(kCnt<<3);
    for(mCnt=0;mCnt<mLeft;mCnt++)
    {
      dst[dstAddr+mCnt] = src[srcAddr+mCnt*kPartition/*k*/];
      dst[dstAddr+mCnt+4] = src[srcAddr+mCnt*kPartition/*k*/+1];
    }
  }

  if((k&1)==1) // one more left in k dimension
  {
	kCnt = k-1;
	for(mCnt=0;mCnt<(m>>2);mCnt++)
	{
	  real f00, f01, f02, f03;
	  int srcAddr = (mCnt<<2)*kPartition/*k*/+kCnt;
	  int dstAddr = (mCnt*(KPARTITION_S/*k*/<<2))+(kCnt<<2);

	  // load 1 x M_KERNEL floats
	  f00 = src[srcAddr];
	  f01 = src[srcAddr+kPartition/*k*/];
	  f02 = src[srcAddr+2*kPartition/*k*/];
	  f03 = src[srcAddr+3*kPartition/*k*/];

	  // push 2 x M_KERNEL floats to desired loc
	  dst[dstAddr]   = f00;
	  dst[dstAddr+1] = f01;
	  dst[dstAddr+2] = f02;
	  dst[dstAddr+3] = f03;
	}
	// leftover in m dimension of A
	// leftover in m dimension of A
  	srcAddr = ((m>>2)<<2)*kPartition/*k*/+(kCnt);
   	dstAddr = ((m>>2)*(KPARTITION_S/*k*/<<2))+(kCnt<<2);
    for(mCnt=0;mCnt<mLeft;mCnt++)
    {
      dst[dstAddr+mCnt] = src[srcAddr+mCnt*kPartition/*k*/];
      dst[dstAddr+mCnt+4] = src[srcAddr+mCnt*kPartition/*k*/+1];
    }
  }
}

