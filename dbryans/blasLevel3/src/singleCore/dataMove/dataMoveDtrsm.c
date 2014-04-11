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
 *  @file   dataMoveDtrsm.h
 *  @brief  This file contains various data movement functions needed for DTRSM
 *
 */

#include "string.h" // for memset
#include "dataMoveDtrsm.h"
#include "defDC66.h"

// get inverse of 4x4 lower triangular matrix
void inverse4x4LowerD(double * restrict src, int ld, int flagDiagisU)
{
  double v00, v10, v20, v30;
  double v11, v21, v31;
  double v22, v32;
  double v33;
  double iv00, iv10, iv20, iv30;
  double iv11, iv21, iv31;
  double iv22, iv32;
  double iv33;
  double tempd;


  if(flagDiagisU)
  {
	v00 = (double) 1.0;
	v11 = (double) 1.0;
	v22 = (double) 1.0;
	v33 = (double) 1.0;
	iv00 = (double) 1.0;
	iv11 = (double) 1.0;
	iv22 = (double) 1.0;
	iv33 = (double) 1.0;
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

  tempd = v00*v11*v22*v33;
  // absorb alpha here
  tempd = (double) 1.0/tempd;
  iv00 = tempd*v11*v22*v33;
  iv10 = -tempd*v10*v22*v33;
  iv20 = tempd*(v10*v33*v21-v33*v20*v11);
  iv30 = tempd*(v32*v20*v11-v22*v30*v11+v10*v22*v31-v32*v21*v10);
  iv11 = tempd*v00*v22*v33;
  iv21 = -tempd*v33*v21*v00;
  iv31 = tempd*(v32*v21*v00-v22*v31*v00);
  iv22 = tempd*v00*v11*v33;
  iv32 = -tempd*v00*v11*v32;
  iv33 = tempd*v00*v11*v22;

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
inverse4x4UpperD(double * restrict src, int ld, int flagDiagisU)
{
  double v00, v01, v02, v03;
  double v11, v12, v13;
  double v22, v23;
  double v33;
  double iv00, iv01, iv02, iv03;
  double iv11, iv12, iv13;
  double iv22, iv23;
  double iv33;
  double tempd;


  if(flagDiagisU)
  {
	v00 = (double) 1.0;
	v11 = (double) 1.0;
	v22 = (double) 1.0;
	v33 = (double) 1.0;
	iv00 = (double) 1.0;
	iv11 = (double) 1.0;
	iv22 = (double) 1.0;
	iv33 = (double) 1.0;
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

  tempd = v00*v11*v22*v33;
  tempd = (double) 1.0/tempd;
  iv00 = tempd*v11*v22*v33;
  iv01 = -tempd*v01*v22*v33;
  iv02 = tempd*(v01*v33*v12-v33*v02*v11);
  iv03 = tempd*(v23*v02*v11-v22*v03*v11+v01*v22*v13-v23*v12*v01);
  iv11 = tempd*v00*v22*v33;
  iv12 = -tempd*v33*v12*v00;
  iv13 = tempd*(v23*v12*v00-v22*v13*v00);
  iv22 = tempd*v00*v11*v33;
  iv23 = -tempd*v00*v11*v23;
  iv33 = tempd*v00*v11*v22;

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

void arrangeDataUADtrsm(double * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_D)
  {
	inverse4x4UpperD(ptrA+(jValue+cnt)*MPARTITION_D+iValue+cnt, MPARTITION_D, flagDiagisU);
  }
  return;
}

void arrangeDataLTADtrsm(double * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_D)
  {
	inverse4x4LowerD(ptrA+(iValue+cnt)*KPARTITION_D+jValue+cnt, KPARTITION_D, flagDiagisU);
  }
  return;
}

void arrangeDataLADtrsm(double * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_D)
  {
	inverse4x4LowerD(ptrA+(jValue+cnt)*MPARTITION_D+iValue+cnt, MPARTITION_D, flagDiagisU);
  }
  return;
}

void arrangeDataUTADtrsm(double * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_D)
  {
	inverse4x4UpperD(ptrA+(iValue+cnt)*KPARTITION_D+jValue+cnt, KPARTITION_D, flagDiagisU);
  }
  return;
}


