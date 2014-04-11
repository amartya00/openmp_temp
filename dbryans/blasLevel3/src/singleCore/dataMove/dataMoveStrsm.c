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
 *  @file   dataMoveStrsm.h
 *  @brief  This file contains various data movement functions needed for STRSM
 *
 */

#include "string.h" // for memset
#include "dataMoveStrsm.h"
#include "defSC66.h"

// get inverse of 4x4 lower triangular matrix
void inverse4x4LowerS(real * restrict src, int ld, int flagDiagisU)
{
  real v00, v10, v20, v30;
  real v11, v21, v31;
  real v22, v32;
  real v33;
  real iv00, iv10, iv20, iv30;
  real iv11, iv21, iv31;
  real iv22, iv32;
  real iv33;
  real tempf;


  if(flagDiagisU)
  {
	v00 = 1.0f;
	v11 = 1.0f;
	v22 = 1.0f;
	v33 = 1.0f;
	iv00 = 1.0f;
	iv11 = 1.0f;
	iv22 = 1.0f;
	iv33 = 1.0f;
  }
  else
  {
	v00 = src[0];
	v11 = src[ld+1];
    v22 = src[2*ld+2];
    v33 = src[3*ld+3];
  }
  v10 = src[1];
  v20 = src[2];
  v30 = src[3];
  v21 = src[ld+2];
  v31 = src[ld+3];
  v32 = src[2*ld+3];

  tempf = v00*v11*v22*v33;
  // absorb alpha here
  tempf = 1.0f/tempf;
  iv00 = tempf*v11*v22*v33;
  iv10 = -tempf*v10*v22*v33;
  iv20 = tempf*(v10*v33*v21-v33*v20*v11);
  iv30 = tempf*(v32*v20*v11-v22*v30*v11+v10*v22*v31-v32*v21*v10);
  iv11 = tempf*v00*v22*v33;
  iv21 = -tempf*v33*v21*v00;
  iv31 = tempf*(v32*v21*v00-v22*v31*v00);
  iv22 = tempf*v00*v11*v33;
  iv32 = -tempf*v00*v11*v32;
  iv33 = tempf*v00*v11*v22;

  src[0]      = iv00;
  src[1]      = iv10;
  src[2]      = iv20;
  src[3]      = iv30;
  src[ld]     = 0.0f;
  src[ld+1]   = iv11;
  src[ld+2]   = iv21;
  src[ld+3]   = iv31;
  src[2*ld]   = 0.0f;
  src[2*ld+1] = 0.0f;
  src[2*ld+2] = iv22;
  src[2*ld+3] = iv32;
  src[3*ld]   = 0.0f;
  src[3*ld+1] = 0.0f;
  src[3*ld+2] = 0.0f;
  src[3*ld+3] = iv33;
}

// get inverse of 4x4 upper triangular matrix
inverse4x4UpperS(real * restrict src, int ld, int flagDiagisU)
{
  real v00, v01, v02, v03;
  real v11, v12, v13;
  real v22, v23;
  real v33;
  real iv00, iv01, iv02, iv03;
  real iv11, iv12, iv13;
  real iv22, iv23;
  real iv33;
  real tempf;


  if(flagDiagisU)
  {
	v00 = 1.0f;
	v11 = 1.0f;
	v22 = 1.0f;
	v33 = 1.0f;
	iv00 = 1.0f;
	iv11 = 1.0f;
	iv22 = 1.0f;
	iv33 = 1.0f;
  }
  else
  {
	v00 = src[0];
	v11 = src[ld+1];
    v22 = src[2*ld+2];
    v33 = src[3*ld+3];
  }
  v01 = src[ld];
  v02 = src[2*ld];
  v12 = src[2*ld+1];
  v03 = src[3*ld];
  v13 = src[3*ld+1];
  v23 = src[3*ld+2];

  tempf = v00*v11*v22*v33;
  tempf = 1.0f/tempf;
  iv00 = tempf*v11*v22*v33;
  iv01 = -tempf*v01*v22*v33;
  iv02 = tempf*(v01*v33*v12-v33*v02*v11);
  iv03 = tempf*(v23*v02*v11-v22*v03*v11+v01*v22*v13-v23*v12*v01);
  iv11 = tempf*v00*v22*v33;
  iv12 = -tempf*v33*v12*v00;
  iv13 = tempf*(v23*v12*v00-v22*v13*v00);
  iv22 = tempf*v00*v11*v33;
  iv23 = -tempf*v00*v11*v23;
  iv33 = tempf*v00*v11*v22;

  src[0]      = iv00;
  src[1]      = 0.0f;
  src[2]      = 0.0f;
  src[3]      = 0.0f;
  src[ld]     = iv01;
  src[ld+1]   = iv11;
  src[ld+2]   = 0.0f;
  src[ld+3]   = 0.0f;
  src[2*ld]   = iv02;
  src[2*ld+1] = iv12;
  src[2*ld+2] = iv22;
  src[2*ld+3] = 0.0f;
  src[3*ld]   = iv03;
  src[3*ld+1] = iv13;
  src[3*ld+2] = iv23;
  src[3*ld+3] = iv33;
}

void arrangeDataUAStrsm(real * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
{
  int cnt, diagCnt;
  int iValue, jValue;
  // zero out above diagonal
  if(kLoc < -mCnt)
  {
	  return;
  }
  else if(kLoc < 0)
  {
	iValue = 0;
	jValue = kCnt+kLoc;
	diagCnt = mCnt+kLoc;
  }
  else if(kLoc < kCnt-mCnt)
  {
	iValue = 0;
	jValue = kCnt-mCnt-kLoc;
	diagCnt = mCnt;
  }
  else if(kLoc < kCnt)
  {
	iValue = kCnt-kLoc-mCnt;
	jValue = 0;
	diagCnt = mCnt-iValue;
  }
  else
  {
	return;
  }

  if(jValue < 0) jValue = 0;
  if(iValue < 0) iValue = 0;
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_S)
  {
	inverse4x4UpperS(ptrA+(jValue+cnt)*MPARTITION_S+iValue+cnt, MPARTITION_S, flagDiagisU);
  }
  return;
}

void arrangeDataLTAStrsm(real * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
{
  int cnt, diagCnt;
  int iValue, jValue;
  // zero out above diagonal
  if(kLoc < -mCnt)
  {
	  return;
  }
  else if(kLoc < 0)
  {
	iValue = 0;
	jValue = kCnt+kLoc;
	diagCnt = mCnt+kLoc;
  }
  else if(kLoc < kCnt-mCnt)
  {
	iValue = 0;
	jValue = kCnt-mCnt-kLoc;
	diagCnt = mCnt;
  }
  else if(kLoc < kCnt)
  {
	iValue = kCnt-kLoc-mCnt;
	jValue = 0;
	diagCnt = mCnt-iValue;
  }
  else
  {
	return;
  }

  if(jValue < 0) jValue = 0;
  if(iValue < 0) iValue = 0;
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_S)
  {
	inverse4x4LowerS(ptrA+(iValue+cnt)*KPARTITION_S+jValue+cnt, KPARTITION_S, flagDiagisU);
  }
  return;
}

void arrangeDataLAStrsm(real * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
{
  int cnt, diagCnt;
  int iValue, jValue;
  // zero out below diagonal
  if(kLoc <= 0)
  {
	  return;
  }
  else if(kLoc <= mCnt)
  {
	iValue = 0;
	jValue = kCnt-kLoc;
	diagCnt = kLoc;
  }
  else if(kLoc <= kCnt)
  {
	iValue = 0;
	jValue = kCnt-kLoc;
	diagCnt = mCnt;
  }
  else if(kLoc <= kCnt+mCnt)
  {
	iValue = kLoc-kCnt;
	jValue = 0;
	diagCnt = kCnt+mCnt-kLoc;
  }
  else
  {
	return;
  }

  if(jValue < 0) jValue = 0;
  if(iValue < 0) iValue = 0;
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_S)
  {
	inverse4x4LowerS(ptrA+(jValue+cnt)*MPARTITION_S+iValue+cnt, MPARTITION_S, flagDiagisU);
  }
  return;
}

void arrangeDataUTAStrsm(real * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
{
  int cnt, diagCnt;
  int iValue, jValue;
  // zero out below diagonal
  if(kLoc <= 0)
  {
	  return;
  }
  else if(kLoc <= mCnt)
  {
	iValue = 0;
	jValue = kCnt-kLoc;
	diagCnt = kLoc;
  }
  else if(kLoc <= kCnt)
  {
	iValue = 0;
	jValue = kCnt-kLoc;
	diagCnt = mCnt;
  }
  else if(kLoc <= kCnt+mCnt)
  {
	iValue = kLoc-kCnt;
	jValue = 0;
	diagCnt = kCnt+mCnt-kLoc;
  }
  else
  {
	return;
  }

  if(jValue < 0) jValue = 0;
  if(iValue < 0) iValue = 0;
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_S)
  {
	inverse4x4UpperS(ptrA+(iValue+cnt)*KPARTITION_S+jValue+cnt, KPARTITION_S, flagDiagisU);
  }
  return;
}


