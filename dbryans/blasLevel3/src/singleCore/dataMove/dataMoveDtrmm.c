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
 *  @file   dataMoveDtrmm.h
 *  @brief  This file contains various data movement functions needed for DTRMM
 *
 */

#include "string.h" // for memset
#include "dataMoveDtrmm.h"
#include "defDC66.h"

void arrangeDataUADtrmm(double * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt++)
  {
	// zero out below diagonal
	memset(ptrA+(jValue+cnt)*MPARTITION_D+iValue+cnt+1, 0, (mCnt-iValue-cnt-1)*sizeof(double));
    if(flagDiagisU)
    {
      // set diagonals to unity
      ptrA[(jValue+cnt)*MPARTITION_D+iValue+cnt] = 1.0f;
    }
  }
  return;
}

void arrangeDataLTADtrmm(double * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt++)
  {
	// zero out below diagonal
	memset(ptrA+(iValue+cnt)*KPARTITION_D, 0, (jValue+cnt)*sizeof(double));
    if(flagDiagisU)
    {
      // set diagonals to unity
      ptrA[(iValue+cnt)*KPARTITION_D+jValue+cnt] = 1.0f;
    }
  }
  return;
}

void arrangeDataLADtrmm(double * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt++)
  {
	// zero out above diagonal
	memset(ptrA+(jValue+cnt)*MPARTITION_D, 0, (iValue+cnt)*sizeof(double));
    if(flagDiagisU)
    {
      // set diagonals to unity
      ptrA[(jValue+cnt)*MPARTITION_D+iValue+cnt] = 1.0f;
    }
  }
  return;
}

void arrangeDataUTADtrmm(double * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt++)
  {
	// zero out below diagonal
	memset(ptrA+(iValue+cnt)*KPARTITION_D+jValue+cnt+1, 0, (kCnt-jValue-cnt-1)*sizeof(double));
    if(flagDiagisU)
    {
      // set diagonals to unity
      ptrA[(iValue+cnt)*KPARTITION_D+jValue+cnt] = 1.0f;
    }
  }
  return;
}


