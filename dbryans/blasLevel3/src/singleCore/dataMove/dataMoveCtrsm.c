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
 *  @file   dataMoveCtrsm.h
 *  @brief  This file contains various data movement functions needed for CTRSM
 *
 */

#include "c6x.h"
#include "string.h" // for memset
#include "dataMoveCtrsm.h"
#include "defCC66.h"

// get inverse of 2x2 lower triangular matrix
void inverse2x2LowerC(complex * restrict src, int ld, int flagDiagisU)
{
  __float2_t v00, v10;
  __float2_t v11;
  __float2_t *pSrc = (__float2_t *) src;

  if(flagDiagisU)
  {
	pSrc[0] = _ftof2(0.0f, 1.0f);
	v10 = pSrc[1];
	pSrc[1] = _ftof2(-_hif(v10),-_lof(v10));
	pSrc[ld] = _ftof2(0.0f, 0.0f);
	pSrc[ld+1] = _ftof2(0.0f, 1.0f);
  }
  else
  {
	__float2_t v00s, v11s, tempf2, tempf2a;
	__x128_t     temp128;
	float      tempf;

	v00 = pSrc[0];
	v10 = pSrc[1];
    v11 = pSrc[ld+1];
    v00s = _dmpysp(v00,v00);
    v11s = _dmpysp(v11,v11);
    tempf = 1.0f/((_lof(v00s)+_hif(v00s))*(_lof(v11s)+_hif(v11s)));
    temp128 = _cmpysp(v00,v11);
    tempf2 = _dmpysp(_ftof2(-tempf, -tempf),_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
    tempf2 = _ftof2(_lof(tempf2),_hif(tempf2));
    temp128 = _cmpysp(tempf2,v11);
    tempf2a = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
    pSrc[0] = _ftof2(_lof(tempf2a),-_hif(tempf2a));

    temp128 = _cmpysp(tempf2,v10);
    tempf2a = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
    pSrc[1] = _ftof2(-_lof(tempf2a),_hif(tempf2a));

    pSrc[ld] = _ftof2(0.0f, 0.0f);

    temp128 = _cmpysp(tempf2,v00);
    tempf2a = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
    pSrc[ld+1] = _ftof2(_lof(tempf2a),-_hif(tempf2a));

  }
}

// get inverse of 2x2 upper triangular matrix
inverse2x2Upper(complex * restrict src, int ld, int flagDiagisU)
{
	  __float2_t v00;
	  __float2_t v01, v11;
	  __float2_t *pSrc = (__float2_t *) src;

	  if(flagDiagisU)
	  {
		pSrc[0] = _ftof2(0.0f, 1.0f);
		pSrc[1] = _ftof2(0.0f, 0.0f);
		v01 = pSrc[ld];
		pSrc[ld] = _ftof2(-_hif(v01),-_lof(v01));
		pSrc[ld+1] = _ftof2(0.0f, 1.0f);
	  }
	  else
	  {
		__float2_t v00s, v11s, tempf2, tempf2a;
		__x128_t     temp128;
		float      tempf;

		v00 = pSrc[0];
	    v01 = pSrc[ld];
	    v11 = pSrc[ld+1];
	    v00s = _dmpysp(v00,v00);
	    v11s = _dmpysp(v11,v11);
	    tempf = 1.0f/((_lof(v00s)+_hif(v00s))*(_lof(v11s)+_hif(v11s)));
	    temp128 = _cmpysp(v00,v11);
	    tempf2 = _dmpysp(_ftof2(-tempf, -tempf),_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	    tempf2 = _ftof2(_lof(tempf2),_hif(tempf2));
	    temp128 = _cmpysp(tempf2,v11);
	    tempf2a = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	    pSrc[0] = _ftof2(_lof(tempf2a),-_hif(tempf2a));

	    pSrc[1] = _ftof2(0.0f, 0.0f);

	    temp128 = _cmpysp(tempf2,v01);
	    tempf2a = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	    pSrc[ld] = _ftof2(-_lof(tempf2a),_hif(tempf2a));


	    temp128 = _cmpysp(tempf2,v00);
	    tempf2a = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	    pSrc[ld+1] = _ftof2(_lof(tempf2a),-_hif(tempf2a));

	  }
}

void arrangeDataUACtrsm(complex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_C)
  {
	inverse2x2Upper(ptrA+(jValue+cnt)*MPARTITION_C+iValue+cnt, MPARTITION_C, flagDiagisU);
  }
  return;
}

void arrangeDataLTACtrsm(complex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_C)
  {
	inverse2x2LowerC(ptrA+(iValue+cnt)*KPARTITION_C+jValue+cnt, KPARTITION_C, flagDiagisU);
  }
  return;
}

void arrangeDataLACtrsm(complex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_C)
  {
	inverse2x2LowerC(ptrA+(jValue+cnt)*MPARTITION_C+iValue+cnt, MPARTITION_C, flagDiagisU);
  }
  return;
}

void arrangeDataUTACtrsm(complex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU)
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
  for(cnt=0;cnt<diagCnt;cnt+=M_KERNEL_C)
  {
	inverse2x2Upper(ptrA+(iValue+cnt)*KPARTITION_C+jValue+cnt, KPARTITION_C, flagDiagisU);
  }
  return;
}

