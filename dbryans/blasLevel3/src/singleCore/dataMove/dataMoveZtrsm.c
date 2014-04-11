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
 *  @file   dataMoveZtrsm.h
 *  @brief  This file contains various data movement functions needed for ZTRSM
 *
 */

#include "string.h" // for memset
#include "dataMoveZtrsm.h"
#include "defZC66.h"

void arrangeDataUAZtrsm(doublecomplex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_Z)
  {
    if(flagDiagisU)
    {
	  ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].r = (double) 1.0;
	  ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].i = (double) 0.0;
	}
	else
	{
	  double ar, ai, av;
      ar = ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].r;
      ai = ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].i;
	  av = (ar*ar+ai*ai);
	  av = ((double) 1.0)/av;
	  ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].r = av * ar;
	  ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].i = -av * ai;
	}
  }
  return;
}

void arrangeDataLTAZtrsm(doublecomplex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_Z)
  {
    if(flagDiagisU)
    {
	  ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].r = (double) 1.0;
	  ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].i = (double) 0.0;
	}
	else
	{
	  double ar, ai, av;
      ar = ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].r;
      ai = ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].i;
	  av = (ar*ar+ai*ai);
	  av = ((double) 1.0)/av;
	  ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].r = av * ar;
	  ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].i = -av * ai;
	}
  }
  return;
}

void arrangeDataLAZtrsm(doublecomplex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_Z)
  {
    if(flagDiagisU)
    {
	  ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].r = (double) 1.0;
	  ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].i = (double) 0.0;
	}
	else
	{
	  double ar, ai, av;
      ar = ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].r;
      ai = ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].i;
	  av = (ar*ar+ai*ai);
	  av = ((double) 1.0)/av;
	  ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].r = av * ar;
	  ptrA[(jValue+cnt)*MPARTITION_Z+iValue+cnt].i = -av * ai;
	}
  }
  return;
}

void arrangeDataUTAZtrsm(doublecomplex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_Z)
  {
    if(flagDiagisU)
    {
	  ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].r = (double) 1.0;
	  ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].i = (double) 0.0;
	}
	else
	{
	  double ar, ai, av;
      ar = ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].r;
      ai = ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].i;
	  av = (ar*ar+ai*ai);
	  av = ((double) 1.0)/av;
	  ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].r = av * ar;
	  ptrA[(iValue+cnt)*KPARTITION_Z+jValue+cnt].i = -av * ai;
	}
  }
  return;
}

