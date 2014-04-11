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
 *  @file   ctrsmKernel.c
 *  @brief  This file contains functions single precision complex
 *          triangular matrix inversion implementation of sizes
 *          2xk by kx4 producing 2x4 output. This is C66 intrinsic
 *          optimized code. There are several variations based on how the
 *          output is saved.
 *
 */

#include "c6x.h"
#include "ctrsmKernel.h"
#include "defCC66.h"

void ctrsmKernel(const complex *pA, complex *pB, complex *pC, complex *pBHat, const int k, const int stepC,
		const int flagisN, const int flagisL)
{
  __float2_t sum00a, sum10a, sum00b, sum10b;
  __float2_t sum01a, sum11a, sum01b, sum11b;
  __float2_t sum02a, sum12a, sum02b, sum12b;
  __float2_t sum03a, sum13a, sum03b, sum13b;
  __float2_t * restrict ptrB     = (__float2_t *) pB;
  __float2_t * restrict ptrA     = (__float2_t *) pA;
  __float2_t * restrict pRegA, * restrict pRegB, * restrict pRegBH, * restrict pRegC;
  __float2_t regC, tempd;
  __float2_t a00, a01;
  __float2_t a10, a11;
  __x128_t temp128;
  int_least16_t index;

  // zero out accumulators
  sum00a = 0.0;
  sum10a = 0.0;
  sum01a = 0.0;
  sum11a = 0.0;
  sum02a = 0.0;
  sum12a = 0.0;
  sum03a = 0.0;
  sum13a = 0.0;
  sum00b = 0.0;
  sum10b = 0.0;
  sum01b = 0.0;
  sum11b = 0.0;
  sum02b = 0.0;
  sum12b = 0.0;
  sum03b = 0.0;
  sum13b = 0.0;

for (index = 0; index < k; index++)
  { // loop over k;
    // each iteration performs rank one update of 2x1 by 1x4
    // matrices of A and B respectively; result is
	// accumulated over 2x4 matrix
	__float2_t b0, b1, b2, b3, a0, a1;
	__x128_t   reg128;

	a0 = *ptrA++;
	a1 = *ptrA++;

    b0 = *ptrB++;
    b1 = *ptrB++;
    b2 = *ptrB++;
    b3 = *ptrB++;

    // the four partial sums are accumulated independently
    // a[0]*b[0]
    reg128 = _cmpysp(a0, b0);
    sum00a = _daddsp(sum00a, _lof2_128(reg128));
    sum00b = _daddsp(sum00b, _hif2_128(reg128));

    // a[1]*b[0]
    reg128 = _cmpysp(a1, b0);
    sum10a = _daddsp(sum10a, _lof2_128(reg128));
    sum10b = _daddsp(sum10b, _hif2_128(reg128));

    // a[0]*b[1]
    reg128 = _cmpysp(a0, b1);
    sum01a = _daddsp(sum01a, _lof2_128(reg128));
    sum01b = _daddsp(sum01b, _hif2_128(reg128));

    // a[1]*b[1]
    reg128 = _cmpysp(a1, b1);
    sum11a = _daddsp(sum11a, _lof2_128(reg128));
    sum11b = _daddsp(sum11b, _hif2_128(reg128));

    // a[0]*b[2]
    reg128 = _cmpysp(a0, b2);
    sum02a = _daddsp(sum02a, _lof2_128(reg128));
    sum02b = _daddsp(sum02b, _hif2_128(reg128));

    // a[1]*b[2]
    reg128 = _cmpysp(a1, b2);
    sum12a = _daddsp(sum12a, _lof2_128(reg128));
    sum12b = _daddsp(sum12b, _hif2_128(reg128));

    // a[0]*b[3]
    reg128 = _cmpysp(a0, b3);
    sum03a = _daddsp(sum03a, _lof2_128(reg128));
    sum03b = _daddsp(sum03b, _hif2_128(reg128));

    // a[1]*b[3]
    reg128 = _cmpysp(a1, b3);
    sum13a = _daddsp(sum13a, _lof2_128(reg128));
    sum13b = _daddsp(sum13b, _hif2_128(reg128));
  }

  if(flagisN > 0)  // final saving in Normal form
  {
	if(flagisL) // lower triangular
	{
	  // read and update 2x4 matrix
	  pRegC = (__float2_t *) pC;
	  // c[0,0]
	  sum00a = _daddsp(sum00a, sum00b);
	  sum00a = _dsubsp((*pRegC++),_ftof2(_lof(sum00a),-_hif(sum00a)));
	  // c[1,0]
	  sum10a = _daddsp(sum10a, sum10b);
	  sum10a = _dsubsp((*pRegC++),_ftof2(_lof(sum10a),-_hif(sum10a)));
	  // next column
	  pRegC += (stepC-2);
	  // c[0,1]
	  sum01a = _daddsp(sum01a, sum01b);
	  sum01a = _dsubsp((*pRegC++),_ftof2(_lof(sum01a),-_hif(sum01a)));
	  // c[1,1]
	  sum11a = _daddsp(sum11a, sum11b);
	  sum11a = _dsubsp((*pRegC++),_ftof2(_lof(sum11a),-_hif(sum11a)));
	  // next column
	  pRegC += (stepC-2);
	  // c[0,2]
	  sum02a = _daddsp(sum02a, sum02b);
	  sum02a = _dsubsp((*pRegC++),_ftof2(_lof(sum02a),-_hif(sum02a)));
	  // c[1,2]
	  sum12a = _daddsp(sum12a, sum12b);
	  sum12a = _dsubsp((*pRegC++),_ftof2(_lof(sum12a),-_hif(sum12a)));
	  // next column
	  pRegC += (stepC-2);
	  // c[0,3]
	  sum03a = _daddsp(sum03a, sum03b);
	  sum03a = _dsubsp((*pRegC++),_ftof2(_lof(sum03a),-_hif(sum03a)));
	  // c[1,3]
	  sum13a = _daddsp(sum13a, sum13b);
	  sum13a = _dsubsp((*pRegC++),_ftof2(_lof(sum13a),-_hif(sum13a)));

	  pRegA = (__float2_t *) (pA+k*M_KERNEL_C);
	  // load the 2x2 lower triangular inverse matrix
	  a00 = pRegA[0];
	  a10 = pRegA[1];

	  a11 = pRegA[M_KERNEL_C+1];

	  // 2x2 matrix multiply followed by saving
	  pRegB = (__float2_t *) (pB+k*N_KERNEL_C);
	  pRegBH = (__float2_t *) (pBHat+k);
	  pRegC = (__float2_t *) pC;

	  // update c[0,0]
	  temp128 = _cmpysp(a00,sum00a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,0]
	  temp128 = _cmpysp(a10,sum00a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum10a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_C) = tempd;

	  // next column
	  pRegC += (stepC-2);
      pRegBH += (KPARTITION_C-2);
      pRegB++;
	  // update c[0,1]
	  temp128 = _cmpysp(a00,sum01a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,1]
	  temp128 = _cmpysp(a10,sum01a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum11a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_C) = tempd;

	  // next column
	  pRegC += (stepC-2);
      pRegBH += (KPARTITION_C-2);
      pRegB++;
	  // update c[0,2]
	  temp128 = _cmpysp(a00,sum02a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,2]
	  temp128 = _cmpysp(a10,sum02a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum12a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_C) = tempd;

	  // next column
	  pRegC += (stepC-2);
      pRegBH += (KPARTITION_C-2);
      pRegB++;
	  // update c[0,3]
	  temp128 = _cmpysp(a00,sum03a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,3]
	  temp128 = _cmpysp(a10,sum03a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum13a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_C) = tempd;

	}
	else // upper triangular
	{
	  // read and update 2x4 matrix
	  pRegC = (__float2_t *) pC;
	  // c[0,0]
	  sum00a = _daddsp(sum00a, sum00b);
	  sum00a = _dsubsp((*pRegC++),_ftof2(_lof(sum00a),-_hif(sum00a)));
	  // c[1,0]
	  sum10a = _daddsp(sum10a, sum10b);
	  sum10a = _dsubsp((*pRegC++),_ftof2(_lof(sum10a),-_hif(sum10a)));
	  // next column
	  pRegC += (stepC-2);
	  // c[0,1]
	  sum01a = _daddsp(sum01a, sum01b);
	  sum01a = _dsubsp((*pRegC++),_ftof2(_lof(sum01a),-_hif(sum01a)));
	  // c[1,1]
	  sum11a = _daddsp(sum11a, sum11b);
	  sum11a = _dsubsp((*pRegC++),_ftof2(_lof(sum11a),-_hif(sum11a)));
	  // next column
	  pRegC += (stepC-2);
	  // c[0,2]
	  sum02a = _daddsp(sum02a, sum02b);
	  sum02a = _dsubsp((*pRegC++),_ftof2(_lof(sum02a),-_hif(sum02a)));
	  // c[1,2]
	  sum12a = _daddsp(sum12a, sum12b);
	  sum12a = _dsubsp((*pRegC++),_ftof2(_lof(sum12a),-_hif(sum12a)));
	  // next column
	  pRegC += (stepC-2);
	  // c[0,3]
	  sum03a = _daddsp(sum03a, sum03b);
	  sum03a = _dsubsp((*pRegC++),_ftof2(_lof(sum03a),-_hif(sum03a)));
	  // c[1,3]
	  sum13a = _daddsp(sum13a, sum13b);
	  sum13a = _dsubsp((*pRegC++),_ftof2(_lof(sum13a),-_hif(sum13a)));

	  pRegA = (__float2_t *) (pA-M_KERNEL_C*M_KERNEL_C);
	  // load the 2x2 lower triangular inverse matrix
	  a00 = pRegA[0];

	  a01 = pRegA[M_KERNEL_C];
	  a11 = pRegA[M_KERNEL_C+1];

	  // 2x2 matrix multiply followed by saving
	  pRegB = (__float2_t *) (pB-M_KERNEL_C*N_KERNEL_C);
	  pRegBH = (__float2_t *) (pBHat-M_KERNEL_C);
	  pRegC = (__float2_t *) pC;

	  // update c[0,0]
	  temp128 = _cmpysp(a00,sum00a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum10a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,0]
	  temp128 = _cmpysp(a11,sum10a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_C) = tempd;

	  // next column
	  pRegC += (stepC-2);
      pRegBH += (KPARTITION_C-2);
      pRegB++;
      // update c[0,1]
	  temp128 = _cmpysp(a00,sum01a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum11a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,1]
	  temp128 = _cmpysp(a11,sum11a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_C) = tempd;

	  // next column
	  pRegC += (stepC-2);
      pRegBH += (KPARTITION_C-2);
      pRegB++;
	  // update c[0,2]
	  temp128 = _cmpysp(a00,sum02a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum12a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,2]
	  temp128 = _cmpysp(a11,sum12a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_C) = tempd;

	  // next column
	  pRegC += (stepC-2);
      pRegBH += (KPARTITION_C-2);
      pRegB++;
	  // update c[0,3]
	  temp128 = _cmpysp(a00,sum03a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum13a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,3]
	  temp128 = _cmpysp(a11,sum13a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_C) = tempd;
	}
  }
  else if(flagisN == 0)  // final saving in transpose form
  {
	if(flagisL) // lower triangular
	{
	  // read and update 2x4 matrix
	  pRegC = (__float2_t *) pC;
	  // c[0,0]
	  sum00a = _daddsp(sum00a, sum00b);
	  sum00a = _dsubsp((*pRegC++),_ftof2(_lof(sum00a),-_hif(sum00a)));
	  // c[0,1]
	  sum01a = _daddsp(sum01a, sum01b);
	  sum01a = _dsubsp((*pRegC++),_ftof2(_lof(sum01a),-_hif(sum01a)));
	  // c[0,2]
	  sum02a = _daddsp(sum02a, sum02b);
	  sum02a = _dsubsp((*pRegC++),_ftof2(_lof(sum02a),-_hif(sum02a)));
	  // c[0,3]
	  sum03a = _daddsp(sum03a, sum03b);
	  sum03a = _dsubsp((*pRegC++),_ftof2(_lof(sum03a),-_hif(sum03a)));
	  // next column
	  pRegC += (stepC-4);
	  // c[1,0]
	  sum10a = _daddsp(sum10a, sum10b);
	  sum10a = _dsubsp((*pRegC++),_ftof2(_lof(sum10a),-_hif(sum10a)));
	  // c[1,1]
	  sum11a = _daddsp(sum11a, sum11b);
	  sum11a = _dsubsp((*pRegC++),_ftof2(_lof(sum11a),-_hif(sum11a)));
	  // c[1,2]
	  sum12a = _daddsp(sum12a, sum12b);
	  sum12a = _dsubsp((*pRegC++),_ftof2(_lof(sum12a),-_hif(sum12a)));
	  // c[1,3]
	  sum13a = _daddsp(sum13a, sum13b);
	  sum13a = _dsubsp((*pRegC++),_ftof2(_lof(sum13a),-_hif(sum13a)));

	  pRegA = (__float2_t *) (pA+k*M_KERNEL_C);
	  // load the 2x2 lower triangular inverse matrix
	  a00 = pRegA[0];
	  a10 = pRegA[1];

	  a11 = pRegA[M_KERNEL_C+1];

	  // 2x2 matrix multiply followed by saving
	  pRegB = (__float2_t *) (pB+k*N_KERNEL_C);
	  pRegBH = (__float2_t *) (pBHat+k*NPARTITION_C);
	  pRegC = (__float2_t *) pC;

	  // update c[0,0]
	  temp128 = _cmpysp(a00,sum00a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,1]
	  temp128 = _cmpysp(a00,sum01a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,2]
	  temp128 = _cmpysp(a00,sum02a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,3]
	  temp128 = _cmpysp(a00,sum03a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

	  // next column
	  pRegC += (stepC-4);
      pRegBH += (NPARTITION_C-4);
	  // update c[1,0]
	  temp128 = _cmpysp(a10,sum00a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum10a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,1]
	  temp128 = _cmpysp(a10,sum01a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum11a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

	  // update c[0,2]
	  temp128 = _cmpysp(a10,sum02a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum12a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,3]
	  temp128 = _cmpysp(a10,sum03a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum13a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

	}
	else // upper triangular
	{
	  // read and update 2x4 matrix
	  pRegC = (__float2_t *) pC;
	  // c[0,0]
	  sum00a = _daddsp(sum00a, sum00b);
	  sum00a = _dsubsp((*pRegC++),_ftof2(_lof(sum00a),-_hif(sum00a)));
	  // c[0,1]
	  sum01a = _daddsp(sum01a, sum01b);
	  sum01a = _dsubsp((*pRegC++),_ftof2(_lof(sum01a),-_hif(sum01a)));
	  // c[0,2]
	  sum02a = _daddsp(sum02a, sum02b);
	  sum02a = _dsubsp((*pRegC++),_ftof2(_lof(sum02a),-_hif(sum02a)));
	  // c[0,3]
	  sum03a = _daddsp(sum03a, sum03b);
	  sum03a = _dsubsp((*pRegC++),_ftof2(_lof(sum03a),-_hif(sum03a)));
	  // next column
	  pRegC += (stepC-4);
	  // c[1,0]
	  sum10a = _daddsp(sum10a, sum10b);
	  sum10a = _dsubsp((*pRegC++),_ftof2(_lof(sum10a),-_hif(sum10a)));
	  // c[1,1]
	  sum11a = _daddsp(sum11a, sum11b);
	  sum11a = _dsubsp((*pRegC++),_ftof2(_lof(sum11a),-_hif(sum11a)));
	  // c[1,2]
	  sum12a = _daddsp(sum12a, sum12b);
	  sum12a = _dsubsp((*pRegC++),_ftof2(_lof(sum12a),-_hif(sum12a)));
	  // c[1,3]
	  sum13a = _daddsp(sum13a, sum13b);
	  sum13a = _dsubsp((*pRegC++),_ftof2(_lof(sum13a),-_hif(sum13a)));

	  pRegA = (__float2_t *) (pA-M_KERNEL_C*M_KERNEL_C);
	  // load the 2x2 lower triangular inverse matrix
	  a00 = pRegA[0];

	  a01 = pRegA[M_KERNEL_C];
	  a11 = pRegA[M_KERNEL_C+1];

	  // 2x2 matrix multiply followed by saving
	  pRegB = (__float2_t *) (pB-M_KERNEL_C*N_KERNEL_C);
	  pRegBH = (__float2_t *) (pBHat-M_KERNEL_C*NPARTITION_C);
	  pRegC = (__float2_t *) pC;

	  // update c[0,0]
	  temp128 = _cmpysp(a00,sum00a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum10a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,1]
	  temp128 = _cmpysp(a00,sum01a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum11a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

      // update c[0,2]
	  temp128 = _cmpysp(a00,sum02a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum12a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,3]
	  temp128 = _cmpysp(a00,sum03a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum13a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

	  // next column
	  pRegC += (stepC-4);
      pRegBH += (NPARTITION_C-4);
 	  // update c[1,0]
	  temp128 = _cmpysp(a11,sum10a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,1]
	  temp128 = _cmpysp(a11,sum11a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,2]
	  temp128 = _cmpysp(a11,sum12a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,3]
	  temp128 = _cmpysp(a11,sum13a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	}
  }
  else  // final saving in conjugate transpose form
  {
	if(flagisL) // lower triangular
	{
	  // read and update 2x4 matrix
	  pRegC = (__float2_t *) pC;
	  // c[0,0]
	  regC = *pRegC++;
	  sum00a = _daddsp(sum00a, sum00b);
	  sum00a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum00a),-_hif(sum00a)));
	  // c[0,1]
	  regC = *pRegC++;
	  sum01a = _daddsp(sum01a, sum01b);
	  sum01a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum01a),-_hif(sum01a)));
	  // c[0,2]
	  regC = *pRegC++;
	  sum02a = _daddsp(sum02a, sum02b);
	  sum02a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum02a),-_hif(sum02a)));
	  // c[0,3]
	  regC = *pRegC++;
	  sum03a = _daddsp(sum03a, sum03b);
	  sum03a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum03a),-_hif(sum03a)));
	  // next column
	  pRegC += (stepC-4);
	  // c[1,0]
	  regC = *pRegC++;
	  sum10a = _daddsp(sum10a, sum10b);
	  sum10a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum10a),-_hif(sum10a)));
	  // c[1,1]
	  regC = *pRegC++;
	  sum11a = _daddsp(sum11a, sum11b);
	  sum11a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum11a),-_hif(sum11a)));
	  // c[1,2]
	  regC = *pRegC++;
	  sum12a = _daddsp(sum12a, sum12b);
	  sum12a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum12a),-_hif(sum12a)));
	  // c[1,3]
	  regC = *pRegC++;
	  sum13a = _daddsp(sum13a, sum13b);
	  sum13a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum13a),-_hif(sum13a)));

	  pRegA = (__float2_t *) (pA+k*M_KERNEL_C);
	  // load the 2x2 lower triangular inverse matrix
	  a00 = pRegA[0];
	  a10 = pRegA[1];

	  a11 = pRegA[M_KERNEL_C+1];

	  // 2x2 matrix multiply followed by saving
	  pRegB = (__float2_t *) (pB+k*N_KERNEL_C);
	  pRegBH = (__float2_t *) (pBHat+k*NPARTITION_C);
	  pRegC = (__float2_t *) pC;

	  // update c[0,0]
	  temp128 = _cmpysp(a00,sum00a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	  // update c[0,1]
	  temp128 = _cmpysp(a00,sum01a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	  // update c[0,2]
	  temp128 = _cmpysp(a00,sum02a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	  // update c[0,3]
	  temp128 = _cmpysp(a00,sum03a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));

	  // next column
	  pRegC += (stepC-4);
      pRegBH += (NPARTITION_C-4);
	  // update c[1,0]
	  temp128 = _cmpysp(a10,sum00a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum10a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	  // update c[1,1]
	  temp128 = _cmpysp(a10,sum01a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum11a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));

	  // update c[0,2]
	  temp128 = _cmpysp(a10,sum02a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum12a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	  // update c[1,3]
	  temp128 = _cmpysp(a10,sum03a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a11,sum13a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));

	}
	else // upper triangular
	{
	  // read and update 2x4 matrix
	  pRegC = (__float2_t *) pC;
	  // c[0,0]
	  regC = *pRegC++;
	  sum00a = _daddsp(sum00a, sum00b);
	  sum00a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum00a),-_hif(sum00a)));
	  // c[0,1]
	  regC = *pRegC++;
	  sum01a = _daddsp(sum01a, sum01b);
	  sum01a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum01a),-_hif(sum01a)));
	  // c[0,2]
	  regC = *pRegC++;
	  sum02a = _daddsp(sum02a, sum02b);
	  sum02a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum02a),-_hif(sum02a)));
	  // c[0,3]
	  regC = *pRegC++;
	  sum03a = _daddsp(sum03a, sum03b);
	  sum03a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum03a),-_hif(sum03a)));
	  // next column
	  pRegC += (stepC-4);
	  // c[1,0]
	  regC = *pRegC++;
	  sum10a = _daddsp(sum10a, sum10b);
	  sum10a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum10a),-_hif(sum10a)));
	  // c[1,1]
	  regC = *pRegC++;
	  sum11a = _daddsp(sum11a, sum11b);
	  sum11a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum11a),-_hif(sum11a)));
	  // c[1,2]
	  regC = *pRegC++;
	  sum12a = _daddsp(sum12a, sum12b);
	  sum12a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum12a),-_hif(sum12a)));
	  // c[1,3]
	  regC = *pRegC++;
	  sum13a = _daddsp(sum13a, sum13b);
	  sum13a = _dsubsp(_ftof2(-_hif(regC),_lof(regC)),_ftof2(_lof(sum13a),-_hif(sum13a)));

	  pRegA = (__float2_t *) (pA-M_KERNEL_C*M_KERNEL_C);
	  // load the 2x2 lower triangular inverse matrix
	  a00 = pRegA[0];

	  a01 = pRegA[M_KERNEL_C];
	  a11 = pRegA[M_KERNEL_C+1];

	  // 2x2 matrix multiply followed by saving
	  pRegB = (__float2_t *) (pB-M_KERNEL_C*N_KERNEL_C);
	  pRegBH = (__float2_t *) (pBHat-M_KERNEL_C*NPARTITION_C);
	  pRegC = (__float2_t *) pC;

	  // update c[0,0]
	  temp128 = _cmpysp(a00,sum00a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum10a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	  // update c[0,1]
	  temp128 = _cmpysp(a00,sum01a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum11a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));

      // update c[0,2]
	  temp128 = _cmpysp(a00,sum02a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum12a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	  // update c[0,3]
	  temp128 = _cmpysp(a00,sum03a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  temp128 = _cmpysp(a01,sum13a);
	  tempd   = _daddsp(tempd,_daddsp(_lof2_128(temp128),_hif2_128(temp128)));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));

	  // next column
	  pRegC += (stepC-4);
      pRegBH += (NPARTITION_C-4);
	  // update c[1,0]
	  temp128 = _cmpysp(a11,sum10a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	  // update c[1,1]
	  temp128 = _cmpysp(a11,sum11a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	  // update c[1,2]
	  temp128 = _cmpysp(a11,sum12a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	  // update c[1,3]
	  temp128 = _cmpysp(a11,sum13a);
	  tempd   = _daddsp(_lof2_128(temp128),_hif2_128(temp128));
	  tempd   = _ftof2(-_lof(tempd),-_hif(tempd));
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = _ftof2(-_hif(tempd),_lof(tempd));
	}
  }
	  return;
} // ctrsmKernel()

