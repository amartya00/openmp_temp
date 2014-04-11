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
 *  @file   cgemmKernel.c
 *  @brief  This file contains functions single precision complex
 *          matrix multiplication implementation of sizes
 *          2xk by kx4 producing 2x4 output. This is C66 intrinsic
 *          optimized code. There are several variations based on how the
 *          output is saved.
 *
 */

#include "c6x.h"
#include "cgemmKernel.h"

#include "stdio.h"

void cgemmKernel(const complex *pA, const complex *pB, complex *pC, const complex a, const int k, const int stepC)
{
  __float2_t sum00a, sum10a, sum00b, sum10b;
  __float2_t sum01a, sum11a, sum01b, sum11b;
  __float2_t sum02a, sum12a, sum02b, sum12b;
  __float2_t sum03a, sum13a, sum03b, sum13b;
  __float2_t * restrict ptrB     = (__float2_t *) pB;
  __float2_t * restrict ptrA     = (__float2_t *) pA;
  __float2_t * restrict ptrC;
  __float2_t regA, regC;
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

  {
	__x128_t   reg128;
    ptrA  = (__float2_t *) &a;
    regA  = *ptrA;
    // the value of a and the final values need to be
    // rearranged due to the specific way cmpysp assumes
    // data arrangement
    regA  =_ftof2(-_lof(regA), _hif(regA));
    index = stepC-2;
    ptrC  = (__float2_t *) pC;

    // update and save c[0,0]
    sum00a = _daddsp(sum00a, sum00b);
    reg128 = _cmpysp(regA, sum00a);
    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
    regC = *ptrC;
    *ptrC++ = _daddsp(_ftof2(-_lof(sum00a),_hif(sum00a)),regC);

    // update and save c[1,0]
    sum10a = _daddsp(sum10a, sum10b);
    reg128 = _cmpysp(regA, sum10a);
    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
    regC = *ptrC;
    *ptrC++ = _daddsp(_ftof2(-_lof(sum10a),_hif(sum10a)),regC);

    // move to next column
    ptrC += index;
    // update and save c[0,1]
    sum01a = _daddsp(sum01a, sum01b);
    reg128 = _cmpysp(regA, sum01a);
    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
    regC = *ptrC;
    *ptrC++ = _daddsp(_ftof2(-_lof(sum01a),_hif(sum01a)),regC);

    // update and save c[1,1]
    sum11a = _daddsp(sum11a, sum11b);
    reg128 = _cmpysp(regA, sum11a);
    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
    regC = *ptrC;
    *ptrC++ = _daddsp(_ftof2(-_lof(sum11a),_hif(sum11a)),regC);

    // move to next column
    ptrC += index;
    // update and save c[0,2]
    sum02a = _daddsp(sum02a, sum02b);
    reg128 = _cmpysp(regA, sum02a);
    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
    regC = *ptrC;
    *ptrC++ = _daddsp(_ftof2(-_lof(sum02a),_hif(sum02a)),regC);

    // update and save c[1,2]
    sum12a = _daddsp(sum12a, sum12b);
    reg128 = _cmpysp(regA, sum12a);
    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
    regC = *ptrC;
    *ptrC++ = _daddsp(_ftof2(-_lof(sum12a),_hif(sum12a)),regC);

    // move to next column
    ptrC += index;
    // update and save c[0,3]
    sum03a = _daddsp(sum03a, sum03b);
    reg128 = _cmpysp(regA, sum03a);
    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
    regC = *ptrC;
    *ptrC++ = _daddsp(_ftof2(-_lof(sum03a),_hif(sum03a)),regC);

    // update and save c[1,3]
    sum13a = _daddsp(sum13a, sum13b);
    reg128 = _cmpysp(regA, sum13a);
    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
    regC = *ptrC;
    *ptrC++ = _daddsp(_ftof2(-_lof(sum13a),_hif(sum13a)),regC);

  }
	  return;
} // cgemmKernel()

void cgemmKernelFlexSave(const complex *pA, const complex *pB, complex *pC, const complex a, const int k, const int stepC, const int saveLoc, const int flagisN)
{
  __float2_t sum00a, sum10a, sum00b, sum10b;
  __float2_t sum01a, sum11a, sum01b, sum11b;
  __float2_t sum02a, sum12a, sum02b, sum12b;
  __float2_t sum03a, sum13a, sum03b, sum13b;
  __float2_t * restrict ptrB     = (__float2_t *) pB;
  __float2_t * restrict ptrA     = (__float2_t *) pA;
  __float2_t * restrict ptrC;
  __float2_t regA, regC;
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

  if(flagisN>0) // saving in normal form
  {
    __x128_t   reg128;
    ptrA  = (__float2_t *) &a;
    regA  = *ptrA;
    // the value of a and the final values need to be
    // rearranged due to the specific way cmpysp assumes
    // data arrangement
    regA  =_ftof2(-_lof(regA), _hif(regA));
    index = stepC-2;
    ptrC  = (__float2_t *) pC;

	switch(saveLoc)
	{
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc > -1) *ptrC = _daddsp(_ftof2(-_lof(sum00a),_hif(sum00a)),regC);
	    ptrC++;

	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc > -2) *ptrC = _daddsp(_ftof2(-_lof(sum10a),_hif(sum10a)),regC);
	    ptrC++;

	    // move to next column
	    ptrC += index;
	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  0) *ptrC = _daddsp(_ftof2(-_lof(sum01a),_hif(sum01a)),regC);
	    ptrC++;

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc > -1) *ptrC = _daddsp(_ftof2(-_lof(sum11a),_hif(sum11a)),regC);
	    ptrC++;

	    // move to next column
	    ptrC += index;
	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  1) *ptrC = _daddsp(_ftof2(-_lof(sum02a),_hif(sum02a)),regC);
	    ptrC++;

	    // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  0) *ptrC = _daddsp(_ftof2(-_lof(sum12a),_hif(sum12a)),regC);
	    ptrC++;

	    // move to next column
		ptrC += index;
	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  2) *ptrC = _daddsp(_ftof2(-_lof(sum03a),_hif(sum03a)),regC);
	    ptrC++;

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  1) *ptrC = _daddsp(_ftof2(-_lof(sum13a),_hif(sum13a)),regC);

	    break;

	  default:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum00a),_hif(sum00a)),regC);

	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum10a),_hif(sum10a)),regC);

	    // move to next column
	    ptrC += index;
	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum01a),_hif(sum01a)),regC);

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum11a),_hif(sum11a)),regC);

	    // move to next column
	    ptrC += index;
	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum02a),_hif(sum02a)),regC);

	    // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum12a),_hif(sum12a)),regC);

	    // move to next column
		ptrC += index;
	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum03a),_hif(sum03a)),regC);

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum13a),_hif(sum13a)),regC);
	}
  }
  else if(flagisN==0) // saving in transpose form
  {
    __x128_t   reg128;
    ptrA  = (__float2_t *) &a;
    regA  = *ptrA;
    // the value of a and the final values need to be
    // rearranged due to the specific way cmpysp assumes
    // data arrangement
    regA  =_ftof2(-_lof(regA), _hif(regA));
    index = stepC-4;
    ptrC  = (__float2_t *) pC;
	switch(saveLoc)
	{
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc > -1) *ptrC = _daddsp(_ftof2(-_lof(sum00a),_hif(sum00a)),regC);
	    ptrC++;

	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  0) *ptrC = _daddsp(_ftof2(-_lof(sum01a),_hif(sum01a)),regC);
	    ptrC++;

	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  1) *ptrC = _daddsp(_ftof2(-_lof(sum02a),_hif(sum02a)),regC);
	    ptrC++;

	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  2) *ptrC = _daddsp(_ftof2(-_lof(sum03a),_hif(sum03a)),regC);
	    ptrC++;

	    // move to next column
	    ptrC += index;
	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  -2) *ptrC = _daddsp(_ftof2(-_lof(sum10a),_hif(sum10a)),regC);
	    ptrC++;

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  -1) *ptrC = _daddsp(_ftof2(-_lof(sum11a),_hif(sum11a)),regC);
	    ptrC++;

	    // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  0) *ptrC = _daddsp(_ftof2(-_lof(sum12a),_hif(sum12a)),regC);
	    ptrC++;

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  1) *ptrC = _daddsp(_ftof2(-_lof(sum13a),_hif(sum13a)),regC);

	    break;

	  default:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum00a),_hif(sum00a)),regC);

	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum01a),_hif(sum01a)),regC);

	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum02a),_hif(sum02a)),regC);

	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum03a),_hif(sum03a)),regC);

	    // move to next column
	    ptrC += index;
	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum10a),_hif(sum10a)),regC);

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum11a),_hif(sum11a)),regC);

	   // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum12a),_hif(sum12a)),regC);

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(-_lof(sum13a),_hif(sum13a)),regC);
	}

  }
  else // saving in conjugate transpose form
  {
    __x128_t   reg128;
    ptrA  = (__float2_t *) &a;
    regA  = *ptrA;
    // the value of a and the final values need to be
    // rearranged due to the specific way cmpysp assumes
    // data arrangement
    regA  =_ftof2(-_lof(regA), -_hif(regA));
    index = stepC-4;
    ptrC  = (__float2_t *) pC;
	switch(saveLoc)
	{
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc > -1) *ptrC = _daddsp(_ftof2(_lof(sum00a),_hif(sum00a)),regC);
	    ptrC++;

	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  0) *ptrC = _daddsp(_ftof2(_lof(sum01a),_hif(sum01a)),regC);
	    ptrC++;

	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  1) *ptrC = _daddsp(_ftof2(_lof(sum02a),_hif(sum02a)),regC);
	    ptrC++;

	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  2) *ptrC = _daddsp(_ftof2(_lof(sum03a),_hif(sum03a)),regC);
	    ptrC++;

	    // move to next column
	    ptrC += index;
	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  -2) *ptrC = _daddsp(_ftof2(_lof(sum10a),_hif(sum10a)),regC);
	    ptrC++;

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  -1) *ptrC = _daddsp(_ftof2(_lof(sum11a),_hif(sum11a)),regC);
	    ptrC++;

	    // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  0) *ptrC = _daddsp(_ftof2(_lof(sum12a),_hif(sum12a)),regC);
	    ptrC++;

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    if(saveLoc >  1) *ptrC = _daddsp(_ftof2(_lof(sum13a),_hif(sum13a)),regC);

	    break;

	  default:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(_lof(sum00a),_hif(sum00a)),regC);

	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(_lof(sum01a),_hif(sum01a)),regC);

	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(_lof(sum02a),_hif(sum02a)),regC);

	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(_lof(sum03a),_hif(sum03a)),regC);

	    // move to next column
	    ptrC += index;
	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(_lof(sum10a),_hif(sum10a)),regC);

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(_lof(sum11a),_hif(sum11a)),regC);

	   // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(_lof(sum12a),_hif(sum12a)),regC);

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    regC = *ptrC;
	    *ptrC++ = _daddsp(_ftof2(_lof(sum13a),_hif(sum13a)),regC);
	}

  }

  return;
} // cgemmKernelFlexSave()


void cgemmKernelNoReadFlexSave(const complex *pA, const complex *pB, complex *pC, const complex a, const int k, const int stepC, const int saveLoc, const int flagisN)
{
  __float2_t sum00a, sum10a, sum00b, sum10b;
  __float2_t sum01a, sum11a, sum01b, sum11b;
  __float2_t sum02a, sum12a, sum02b, sum12b;
  __float2_t sum03a, sum13a, sum03b, sum13b;
  __float2_t * restrict ptrB     = (__float2_t *) pB;
  __float2_t * restrict ptrA     = (__float2_t *) pA;
  __float2_t * restrict ptrC;
  __float2_t regA;
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

  if(flagisN>0) // saving in normal form
  {
    __x128_t   reg128;
    ptrA  = (__float2_t *) &a;
    regA  = *ptrA;
    // the value of a and the final values need to be
    // rearranged due to the specific way cmpysp assumes
    // data arrangement
    regA  =_ftof2(-_lof(regA), _hif(regA));
    index = stepC-2;
    ptrC  = (__float2_t *) pC;

	switch(saveLoc)
	{
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc > -1) *ptrC = _ftof2(-_lof(sum00a),_hif(sum00a));
	    ptrC++;

	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc > -2) *ptrC = _ftof2(-_lof(sum10a),_hif(sum10a));
	    ptrC++;

	    // move to next column
	    ptrC += index;
	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  0) *ptrC = _ftof2(-_lof(sum01a),_hif(sum01a));
	    ptrC++;

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc > -1) *ptrC = _ftof2(-_lof(sum11a),_hif(sum11a));
	    ptrC++;

	    // move to next column
	    ptrC += index;
	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  1) *ptrC = _ftof2(-_lof(sum02a),_hif(sum02a));
	    ptrC++;

	    // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  0) *ptrC = _ftof2(-_lof(sum12a),_hif(sum12a));
	    ptrC++;

	    // move to next column
		ptrC += index;
	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  2) *ptrC = _ftof2(-_lof(sum03a),_hif(sum03a));
	    ptrC++;

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  1) *ptrC = _ftof2(-_lof(sum13a),_hif(sum13a));

	    break;

	  default:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum00a),_hif(sum00a));

	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum10a),_hif(sum10a));

	    // move to next column
	    ptrC += index;
	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum01a),_hif(sum01a));

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum11a),_hif(sum11a));

	    // move to next column
	    ptrC += index;
	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum02a),_hif(sum02a));

	    // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum12a),_hif(sum12a));

	    // move to next column
		ptrC += index;
	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum03a),_hif(sum03a));

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum13a),_hif(sum13a));
	}
  }
  else if(flagisN==0) // saving in transpose form
  {
    __x128_t   reg128;
    ptrA  = (__float2_t *) &a;
    regA  = *ptrA;
    // the value of a and the final values need to be
    // rearranged due to the specific way cmpysp assumes
    // data arrangement
    regA  =_ftof2(-_lof(regA), _hif(regA));
    index = stepC-4;
    ptrC  = (__float2_t *) pC;
	switch(saveLoc)
	{
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc > -1) *ptrC = _ftof2(-_lof(sum00a),_hif(sum00a));
	    ptrC++;

	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  0) *ptrC = _ftof2(-_lof(sum01a),_hif(sum01a));
	    ptrC++;

	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  1) *ptrC = _ftof2(-_lof(sum02a),_hif(sum02a));
	    ptrC++;

	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  2) *ptrC = _ftof2(-_lof(sum03a),_hif(sum03a));
	    ptrC++;

	    // move to next column
	    ptrC += index;
	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  -2) *ptrC = _ftof2(-_lof(sum10a),_hif(sum10a));
	    ptrC++;

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  -1) *ptrC = _ftof2(-_lof(sum11a),_hif(sum11a));
	    ptrC++;

	    // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  0) *ptrC = _ftof2(-_lof(sum12a),_hif(sum12a));
	    ptrC++;

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  1) *ptrC = _ftof2(-_lof(sum13a),_hif(sum13a));

	    break;

	  default:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum00a),_hif(sum00a));

	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum01a),_hif(sum01a));

	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum02a),_hif(sum02a));

	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum03a),_hif(sum03a));

	    // move to next column
	    ptrC += index;
	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum10a),_hif(sum10a));

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum11a),_hif(sum11a));

	   // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum12a),_hif(sum12a));

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(-_lof(sum13a),_hif(sum13a));
	}

  }
  else // saving in conjugate transpose form
  {
    __x128_t   reg128;
    ptrA  = (__float2_t *) &a;
    regA  = *ptrA;
    // the value of a and the final values need to be
    // rearranged due to the specific way cmpysp assumes
    // data arrangement
    regA  =_ftof2(-_lof(regA), -_hif(regA));
    index = stepC-4;
    ptrC  = (__float2_t *) pC;
	switch(saveLoc)
	{
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc > -1) *ptrC = _ftof2(_lof(sum00a),_hif(sum00a));
	    ptrC++;

	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  0) *ptrC = _ftof2(_lof(sum01a),_hif(sum01a));
	    ptrC++;

	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  1) *ptrC = _ftof2(_lof(sum02a),_hif(sum02a));
	    ptrC++;

	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  2) *ptrC = _ftof2(_lof(sum03a),_hif(sum03a));
	    ptrC++;

	    // move to next column
	    ptrC += index;
	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  -2) *ptrC = _ftof2(_lof(sum10a),_hif(sum10a));
	    ptrC++;

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  -1) *ptrC = _ftof2(_lof(sum11a),_hif(sum11a));
	    ptrC++;

	    // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  0) *ptrC = _ftof2(_lof(sum12a),_hif(sum12a));
	    ptrC++;

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    if(saveLoc >  1) *ptrC = _ftof2(_lof(sum13a),_hif(sum13a));

	    break;

	  default:
	    // update and save c[0,0]
	    sum00a = _daddsp(sum00a, sum00b);
	    reg128 = _cmpysp(regA, sum00a);
	    sum00a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(_lof(sum00a),_hif(sum00a));

	    // update and save c[0,1]
	    sum01a = _daddsp(sum01a, sum01b);
	    reg128 = _cmpysp(regA, sum01a);
	    sum01a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(_lof(sum01a),_hif(sum01a));

	    // update and save c[0,2]
	    sum02a = _daddsp(sum02a, sum02b);
	    reg128 = _cmpysp(regA, sum02a);
	    sum02a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(_lof(sum02a),_hif(sum02a));

	    // update and save c[0,3]
	    sum03a = _daddsp(sum03a, sum03b);
	    reg128 = _cmpysp(regA, sum03a);
	    sum03a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(_lof(sum03a),_hif(sum03a));

	    // move to next column
	    ptrC += index;
	    // update and save c[1,0]
	    sum10a = _daddsp(sum10a, sum10b);
	    reg128 = _cmpysp(regA, sum10a);
	    sum10a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(_lof(sum10a),_hif(sum10a));

	    // update and save c[1,1]
	    sum11a = _daddsp(sum11a, sum11b);
	    reg128 = _cmpysp(regA, sum11a);
	    sum11a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(_lof(sum11a),_hif(sum11a));

	   // update and save c[1,2]
	    sum12a = _daddsp(sum12a, sum12b);
	    reg128 = _cmpysp(regA, sum12a);
	    sum12a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(_lof(sum12a),_hif(sum12a));

	    // update and save c[1,3]
	    sum13a = _daddsp(sum13a, sum13b);
	    reg128 = _cmpysp(regA, sum13a);
	    sum13a = _daddsp(_hif2_128(reg128),_lof2_128(reg128));
	    *ptrC++ = _ftof2(_lof(sum13a),_hif(sum13a));
	}

  }

  return;
} // cgemmKernelNoReadFlexSave()

