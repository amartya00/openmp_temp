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
 *  @file   sgemmKernel.c
 *  @brief  This file contains functions single precision
 *          matrix multiplication implementation of sizes
 *          4xk by kx8 producing 4x8 output. This is C66 intrinsic
 *          optimized code. There are several variations based on how the
 *          output is saved.
 *
 */

#include "c6x.h"
#include "sgemmKernel.h"

#include "stdio.h"

void sgemmKernel(const real *pA, const real *pB, real *pC, const real a, const int k, const int stepC)
{
  __float2_t sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7;
  __float2_t sum8, sum9, suma, sumb, sumc, sumd, sume, sumf;
  __float2_t * restrict ptrB     = (__float2_t *) pB;
  __float2_t * restrict ptrA     = (__float2_t *) pA;
  __float2_t * restrict ptrC;
  __float2_t regA2, regC, regS;
  int_least16_t index;

  // zero out accumulators
  sum0 = 0.0;
  sum1 = 0.0;
  sum2 = 0.0;
  sum3 = 0.0;
  sum4 = 0.0;
  sum5 = 0.0;
  sum6 = 0.0;
  sum7 = 0.0;
  sum8 = 0.0;
  sum9 = 0.0;
  suma = 0.0;
  sumb = 0.0;
  sumc = 0.0;
  sumd = 0.0;
  sume = 0.0;
  sumf = 0.0;

  for (index = 0; index < k; index++)
  { // loop over k;
    // each iteration performs rank one update of 4x1 by 1x8
    // matrices of A and B respectively; result is
    // accumulated over 4x8 matrix
	__float2_t b01, b23, b45, b67, a01, a23;
	__x128_t   reg128;

    a01 = *ptrA++;
	a23 = *ptrA++;

    b01 = *ptrB++;
    b23 = *ptrB++;
    b45 = *ptrB++;
    b67 = *ptrB++;

    reg128 = _cmpysp(a01, b01);
    // accumulate a[0]*b[1] and -a[0]*b[0]
    sum0 = _daddsp(sum0, _lof2_128(reg128));
    // accumulate a[1]*b[0] and a[1]*b[1]
    sum1 = _daddsp(sum1, _hif2_128(reg128));

    reg128 = _cmpysp(a01, b23);
    // accumulate a[0]*b[3] and -a[0]*b[2]
    sum2 = _daddsp(sum2, _lof2_128(reg128));
    // accumulate a[1]*b[2] and a[1]*b[3]
    sum3 = _daddsp(sum3, _hif2_128(reg128));

    reg128 = _cmpysp(a01, b45);
    // accumulate a[0]*b[5] and -a[0]*b[4]
    sum4 = _daddsp(sum4, _lof2_128(reg128));
    // accumulate a[1]*b[4] and a[1]*b[5]
    sum5 = _daddsp(sum5, _hif2_128(reg128));

    reg128 = _cmpysp(a01, b67);
    // accumulate a[0]*b[7] and -a[0]*b[6]
    sum6 = _daddsp(sum6, _lof2_128(reg128));
    // accumulate a[1]*b[6] and a[1]*b[7]
    sum7 = _daddsp(sum7, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b01);
    // accumulate a[2]*b[1] and -a[2]*b[0]
    sum8 = _daddsp(sum8, _lof2_128(reg128));
    // accumulate a[3]*b[0] and a[3]*b[1]
    sum9 = _daddsp(sum9, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b23);
    // accumulate a[2]*b[3] and -a[2]*b[2]
    suma = _daddsp(suma, _lof2_128(reg128));
    // accumulate a[3]*b[2] and a[3]*b[3]
    sumb = _daddsp(sumb, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b45);
    // accumulate a[2]*b[5] and -a[2]*b[4]
    sumc = _daddsp(sumc, _lof2_128(reg128));
    // accumulate a[3]*b[4] and a[3]*b[5]
    sumd = _daddsp(sumd, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b67);
    // accumulate a[2]*b[7] and -a[2]*b[6]
    sume = _daddsp(sume, _lof2_128(reg128));
    // accumulate a[3]*b[6] and a[3]*b[7]
    sumf = _daddsp(sumf, _hif2_128(reg128));

  }

  {
    regA2 = _ftof2(a, a);
    index = (stepC>>1)-2;

    ptrC = (__float2_t *) pC;
    // update c[0,0] and c[1,0]
    regC = *ptrC;
    regS = _ftof2(_lof2(sum1),-_hif2(sum0));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,0] and c[3,0]
    regC = *ptrC;
    regS = _ftof2(_lof2(sum9),-_hif2(sum8));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,1] and c[1,1]
    regC = *ptrC;
    regS = _ftof2(_hif2(sum1),_lof2(sum0));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,1] and c[3,1]
    regC = *ptrC;
    regS = _ftof2(_hif2(sum9),_lof2(sum8));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,2] and c[1,2]
    regC = *ptrC;
    regS = _ftof2(_lof2(sum3),-_hif2(sum2));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,2] and c[3,2]
    regC = *ptrC;
    regS = _ftof2(_lof2(sumb),-_hif2(suma));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,3] and c[1,3]
    regC = *ptrC;
    regS = _ftof2(_hif2(sum3),_lof2(sum2));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,3] and c[3,3]
    regC = *ptrC;
    regS = _ftof2(_hif2(sumb),_lof2(suma));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,4] and c[1,4]
    regC = *ptrC;
    regS = _ftof2(_lof2(sum5),-_hif2(sum4));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,4] and c[3,4]
    regC = *ptrC;
    regS = _ftof2(_lof2(sumd),-_hif2(sumc));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,5] and c[1,5]
    regC = *ptrC;
    regS = _ftof2(_hif2(sum5),_lof2(sum4));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,5] and c[3,5]
    regC = *ptrC;
    regS = _ftof2(_hif2(sumd),_lof2(sumc));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,6] and c[1,6]
    regC = *ptrC;
    regS = _ftof2(_lof2(sum7),-_hif2(sum6));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,6] and c[3,6]
    regC = *ptrC;
    regS = _ftof2(_lof2(sumf),-_hif2(sume));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,7] and c[1,7]
    regC = *ptrC;
    regS = _ftof2(_hif2(sum7),_lof2(sum6));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,7] and c[3,7]
    regC = *ptrC;
    regS = _ftof2(_hif2(sumf),_lof2(sume));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
  }
  return;
} // sgemmKernel()

void sgemmKernelFlexSave(const real *pA, const real *pB, real *pC, const real a, const int k, const int stepC, const int saveLoc, const int flagisN)
{
  __float2_t sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7;
  __float2_t sum8, sum9, suma, sumb, sumc, sumd, sume, sumf;
  __float2_t * restrict ptrB     = (__float2_t *) pB;
  __float2_t * restrict ptrA     = (__float2_t *) pA;
  __float2_t * restrict ptrC;
  __float2_t regA2, regC, regS;
  int_least16_t index;

  // zero out accumulators
  sum0 = 0.0;
  sum1 = 0.0;
  sum2 = 0.0;
  sum3 = 0.0;
  sum4 = 0.0;
  sum5 = 0.0;
  sum6 = 0.0;
  sum7 = 0.0;
  sum8 = 0.0;
  sum9 = 0.0;
  suma = 0.0;
  sumb = 0.0;
  sumc = 0.0;
  sumd = 0.0;
  sume = 0.0;
  sumf = 0.0;

  for (index = 0; index < k; index++)
  { // loop over k;
    // each iteration performs rank one update of 4x1 by 1x8
    // matrices of A and B respectively; result is
    // accumulated over 4x8 matrix
	__float2_t b01, b23, b45, b67, a01, a23;
	__x128_t   reg128;

	a01 = *ptrA++;
	a23 = *ptrA++;

    b01 = *ptrB++;
    b23 = *ptrB++;
    b45 = *ptrB++;
    b67 = *ptrB++;

    reg128 = _cmpysp(a01, b01);
    // accumulate a[0]*b[1] and -a[0]*b[0]
    sum0 = _daddsp(sum0, _lof2_128(reg128));
    // accumulate a[1]*b[0] and a[1]*b[1]
    sum1 = _daddsp(sum1, _hif2_128(reg128));

    reg128 = _cmpysp(a01, b23);
    // accumulate a[0]*b[3] and -a[0]*b[2]
    sum2 = _daddsp(sum2, _lof2_128(reg128));
    // accumulate a[1]*b[2] and a[1]*b[3]
    sum3 = _daddsp(sum3, _hif2_128(reg128));

    reg128 = _cmpysp(a01, b45);
    // accumulate a[0]*b[5] and -a[0]*b[4]
    sum4 = _daddsp(sum4, _lof2_128(reg128));
    // accumulate a[1]*b[4] and a[1]*b[5]
    sum5 = _daddsp(sum5, _hif2_128(reg128));

    reg128 = _cmpysp(a01, b67);
    // accumulate a[0]*b[7] and -a[0]*b[6]
    sum6 = _daddsp(sum6, _lof2_128(reg128));
    // accumulate a[1]*b[6] and a[1]*b[7]
    sum7 = _daddsp(sum7, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b01);
    // accumulate a[2]*b[1] and -a[2]*b[0]
    sum8 = _daddsp(sum8, _lof2_128(reg128));
    // accumulate a[3]*b[0] and a[3]*b[1]
    sum9 = _daddsp(sum9, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b23);
    // accumulate a[2]*b[3] and -a[2]*b[2]
    suma = _daddsp(suma, _lof2_128(reg128));
    // accumulate a[3]*b[2] and a[3]*b[3]
    sumb = _daddsp(sumb, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b45);
    // accumulate a[2]*b[5] and -a[2]*b[4]
    sumc = _daddsp(sumc, _lof2_128(reg128));
    // accumulate a[3]*b[4] and a[3]*b[5]
    sumd = _daddsp(sumd, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b67);
    // accumulate a[2]*b[7] and -a[2]*b[6]
    sume = _daddsp(sume, _lof2_128(reg128));
    // accumulate a[3]*b[6] and a[3]*b[7]
    sumf = _daddsp(sumf, _hif2_128(reg128));
  }

  regA2 = _ftof2(a, a);
  if(flagisN>0) // saving in normal form
  {
	index = (stepC>>1)-2;

    switch(saveLoc)
    {
    case -3:
    case -2:
    case -1:
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
  	  ptrC = (__float2_t *) pC;
	  // update c[0,0] and c[1,0]
	  regC = *ptrC;
	  regS = _ftof2(_lof2(sum1),-_hif2(sum0));
	  if(saveLoc>-1) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;
	  // update c[2,0] and c[3,0]
	  regC = *ptrC;
	  regS = _ftof2(_lof2(sum9),-_hif2(sum8));
	  if(saveLoc>-3) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;

	    // move to next column
	  ptrC += index;
	  // update c[0,1] and c[1,1]
	  regC = *ptrC;
	  regS = _ftof2(_hif2(sum1),_lof2(sum0));
	  if(saveLoc>0) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;
	  // update c[2,1] and c[3,1]
	  regC = *ptrC;
	  regS = _ftof2(_hif2(sum9),_lof2(sum8));
	  if(saveLoc>-2) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;

	  // move to next column
	  ptrC += index;
	  // update c[0,2] and c[1,2]
	  regC = *ptrC;
	  regS = _ftof2(_lof2(sum3),-_hif2(sum2));
	  if(saveLoc>1) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;
	  // update c[2,2] and c[3,2]
	  regC = *ptrC;
	  regS = _ftof2(_lof2(sumb),-_hif2(suma));
	  if(saveLoc>-1) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;

	  // move to next column
	  ptrC += index;
	  // update c[0,3] and c[1,3]
	  regC = *ptrC;
	  regS = _ftof2(_hif2(sum3),_lof2(sum2));
	  if(saveLoc>2) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;
	  // update c[2,3] and c[3,3]
	  regC = *ptrC;
	  regS = _ftof2(_hif2(sumb),_lof2(suma));
	  if(saveLoc>0) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;

	  // move to next column
	  ptrC += index;
	  // update c[0,4] and c[1,4]
	  regC = *ptrC;
	  regS = _ftof2(_lof2(sum5),-_hif2(sum4));
	  if(saveLoc>3) *ptrC =  _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;
	  // update c[2,4] and c[3,4]
	  regC = *ptrC;
	  regS = _ftof2(_lof2(sumd),-_hif2(sumc));
	  if(saveLoc>1) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;

	  // move to next column
	  ptrC += index;
	  // update c[0,5] and c[1,5]
	  regC = *ptrC;
	  regS = _ftof2(_hif2(sum5),_lof2(sum4));
	  if(saveLoc>4) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;
	  // update c[2,5] and c[3,5]
	  regC = *ptrC;
	  regS = _ftof2(_hif2(sumd),_lof2(sumc));
	  if(saveLoc>2) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;

	  // move to next column
	  ptrC += index;
	  // update c[0,6] and c[1,6]
	  regC = *ptrC;
	  regS = _ftof2(_lof2(sum7),-_hif2(sum6));
	  if(saveLoc>5) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;
	  // update c[2,6] and c[3,6]
	  regC = *ptrC;
	  regS = _ftof2(_lof2(sumf),-_hif2(sume));
	  if(saveLoc>3) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;

	  // move to next column
	  ptrC += index;
	  // update c[0,7] and c[1,7]
	  regC = *ptrC;
	  regS = _ftof2(_hif2(sum7),_lof2(sum6));
	  if(saveLoc>6) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;
	  // update c[2,7] and c[3,7]
	  regC = *ptrC;
	  regS = _ftof2(_hif2(sumf),_lof2(sume));
	  if(saveLoc>4) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
	  ptrC++;

	  // update c[1,0] if necessary
	  pC++;
	  if(saveLoc==-1) *pC = *pC + a * _lof2(sum1);
	  // update c[3,0] if necessary
	  pC += 2;
	  if(saveLoc==-3) *pC = *pC + a * _lof2(sum9);
	  // update c[1,1] if necessary
	  pC += (stepC-2);
	  if(saveLoc==0) *pC = *pC + a * _hif2(sum1);
	  // update c[3,1] if necessary
	  pC += 2;
	  if(saveLoc==-2) *pC = *pC + a * _hif2(sum9);
	  // update c[1,2] if necessary
	  pC += (stepC-2);
	  if(saveLoc==1) *pC = *pC + a * _lof2(sum3);
	  // update c[3,2] if necessary
	  pC += 2;
	  if(saveLoc==-1) *pC = *pC + a * _lof2(sumb);
	  // update c[1,3] if necessary
	  pC += (stepC-2);
	  if(saveLoc==2) *pC = *pC + a * _hif2(sum3);
	  // update c[3,3] if necessary
	  pC += 2;
	  if(saveLoc==0) *pC = *pC + a * _hif2(sumb);
	  // update c[1,4] if necessary
	  pC += (stepC-2);
	  if(saveLoc==3) *pC = *pC + a * _lof2(sum5);
	  // update c[3,4] if necessary
	  pC += 2;
	  if(saveLoc==1) *pC = *pC + a * _lof2(sumd);
	  // update c[1,5] if necessary
	  pC += (stepC-2);
	  if(saveLoc==4) *pC = *pC + a * _hif2(sum5);
	  // update c[3,5] if necessary
	  pC += 2;
	  if(saveLoc==2) *pC = *pC + a * _hif2(sumd);
	  // update c[1,6] if necessary
	  pC += (stepC-2);
	  if(saveLoc==5) *pC = *pC + a * _lof2(sum7);
	  // update c[3,6] if necessary
	  pC += 2;
	  if(saveLoc==3) *pC = *pC + a * _lof2(sumf);
	  // update c[1,7] if necessary
	  pC += (stepC-2);
	  if(saveLoc==6) *pC = *pC + a * _hif2(sum7);
	  // update c[3,7] if necessary
	  pC += 2;
	  if(saveLoc==4) *pC = *pC + a * _hif2(sumf);

	  break;
  default:
    ptrC = (__float2_t *) pC;
    // update c[0,0] and c[1,0]
    regC = *ptrC;
    regS = _ftof2(_lof2(sum1),-_hif2(sum0));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,0] and c[3,0]
    regC = *ptrC;
    regS = _ftof2(_lof2(sum9),-_hif2(sum8));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,1] and c[1,1]
    regC = *ptrC;
    regS = _ftof2(_hif2(sum1),_lof2(sum0));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,1] and c[3,1]
    regC = *ptrC;
    regS = _ftof2(_hif2(sum9),_lof2(sum8));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,2] and c[1,2]
    regC = *ptrC;
    regS = _ftof2(_lof2(sum3),-_hif2(sum2));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,2] and c[3,2]
    regC = *ptrC;
    regS = _ftof2(_lof2(sumb),-_hif2(suma));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,3] and c[1,3]
    regC = *ptrC;
    regS = _ftof2(_hif2(sum3),_lof2(sum2));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,3] and c[3,3]
    regC = *ptrC;
    regS = _ftof2(_hif2(sumb),_lof2(suma));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,4] and c[1,4]
    regC = *ptrC;
    regS = _ftof2(_lof2(sum5),-_hif2(sum4));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,4] and c[3,4]
    regC = *ptrC;
    regS = _ftof2(_lof2(sumd),-_hif2(sumc));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,5] and c[1,5]
    regC = *ptrC;
    regS = _ftof2(_hif2(sum5),_lof2(sum4));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,5] and c[3,5]
    regC = *ptrC;
    regS = _ftof2(_hif2(sumd),_lof2(sumc));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,6] and c[1,6]
    regC = *ptrC;
    regS = _ftof2(_lof2(sum7),-_hif2(sum6));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,6] and c[3,6]
    regC = *ptrC;
    regS = _ftof2(_lof2(sumf),-_hif2(sume));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

    // move to next column
    ptrC += index;
    // update c[0,7] and c[1,7]
    regC = *ptrC;
    regS = _ftof2(_hif2(sum7),_lof2(sum6));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
    // update c[2,7] and c[3,7]
    regC = *ptrC;
    regS = _ftof2(_hif2(sumf),_lof2(sume));
    *ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
  }
  }
  else // saving in transpose form
  {
    index = (stepC>>1)-4;

	switch(saveLoc)
	{
	  case -3:
	  case -2:
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
	  case 4:
	  case 5:
	  case 6:
	    ptrC = (__float2_t *) pC;
		// update c[0,0] and c[0,1]
		regC = *ptrC;
		regS = _ftof2(_lof2(sum0),-_hif2(sum0));
		if(saveLoc>0) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;
		// update c[0,2] and c[0,3]
		regC = *ptrC;
		regS = _ftof2(_lof2(sum2),-_hif2(sum2));
		if(saveLoc>2) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;

		// update c[0,4] and c[0,5]
		regC = *ptrC;
		regS = _ftof2(_lof2(sum4),-_hif2(sum4));
		if(saveLoc>4) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;
		// update c[0,6] and c[0,7]
		regC = *ptrC;
		regS = _ftof2(_lof2(sum6),-_hif2(sum6));
		if(saveLoc>6) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;

		// move to next column
		ptrC += index;
		// update c[1,0] and c[1,1]
		regC = *ptrC;
		regS = sum1;
		if(saveLoc>-1) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;
		// update c[1,2] and c[1,3]
		regC = *ptrC;
		regS = sum3;
		if(saveLoc>1) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;

		// update c[1,4] and c[1,5]
		regC = *ptrC;
		regS = sum5;
		if(saveLoc>3) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;
		// update c[1,6] and c[1,7]
		regC = *ptrC;
		regS = sum7;
		if(saveLoc>5) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;

		// move to next column
		ptrC += index;
		// update c[2,0] and c[2,1]
		regC = *ptrC;
		regS = _ftof2(_lof2(sum8),-_hif2(sum8));
		if(saveLoc>-2) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;
		// update c[2,2] and c[2,3]
		regC = *ptrC;
		regS = _ftof2(_lof2(suma),-_hif2(suma));
		if(saveLoc>0) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;

		// update c[2,4] and c[2,5]
		regC = *ptrC;
		regS = _ftof2(_lof2(sumc),-_hif2(sumc));
		if(saveLoc>2) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;
		// update c[2,6] and c[2,7]
		regC = *ptrC;
		regS = _ftof2(_lof2(sume),-_hif2(sume));
		if(saveLoc>4) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;

		// move to next column
		ptrC += index;
		// update c[3,0] and c[3,1]
		regC = *ptrC;
		regS = sum9;
		if(saveLoc>-3) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;
		// update c[3,2] and c[3,3]
		regC = *ptrC;
		regS = sumb;
		if(saveLoc>-1) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;

		// update c[3,4] and c[3,5]
		regC = *ptrC;
		regS = sumd;
		if(saveLoc>1) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;
		// update c[3,6] and c[3,7]
		regC = *ptrC;
		regS = sumf;
		if(saveLoc>3) *ptrC = _daddsp(_dmpysp(regA2, regS), regC);
		ptrC++;

		// update c[0,0] if necessary
		if(saveLoc==0) *pC = *pC - a * _hif2(sum0);
		// update c[0,2] if necessary
		pC += 2;
		if(saveLoc==2) *pC = *pC - a * _hif2(sum2);
		// update c[0,4] if necessary
		pC += 2;
		if(saveLoc==4) *pC = *pC - a * _hif2(sum4);
		// update c[0,6] if necessary
		pC += 2;
		if(saveLoc==6) *pC = *pC - a * _hif2(sum6);
		// update c[1,0] if necessary
		pC += (stepC-6);
		if(saveLoc==-1) *pC = *pC + a * _lof2(sum1);
		// update c[1,2] if necessary
		pC += 2;
		if(saveLoc==1) *pC = *pC + a * _lof2(sum3);
		// update c[1,4] if necessary
		pC += 2;
		if(saveLoc==3) *pC = *pC + a * _lof2(sum5);
		// update c[1,6] if necessary
		pC += 2;
		if(saveLoc==5) *pC = *pC + a * _lof2(sum7);
		// update c[2,0] if necessary
		pC += (stepC-6);
		if(saveLoc==-2) *pC = *pC - a * _hif2(sum8);
		// update c[2,2] if necessary
		pC += 2;
		if(saveLoc==0) *pC = *pC - a * _hif2(suma);
		// update c[2,4] if necessary
		pC += 2;
		if(saveLoc==2) *pC = *pC - a * _hif2(sumc);
		// update c[2,6] if necessary
		pC += 2;
		if(saveLoc==4) *pC = *pC - a * _hif2(sume);
		// update c[3,0] if necessary
		pC += (stepC-6);
		if(saveLoc==-3) *pC = *pC + a * _lof2(sum9);
		// update c[3,2] if necessary
		pC += 2;
		if(saveLoc==-1) *pC = *pC + a * _lof2(sumb);
		// update c[3,4] if necessary
		pC += 2;
		if(saveLoc==1) *pC = *pC + a * _lof2(sumd);
		// update c[3,6] if necessary
		pC += 2;
		if(saveLoc==3) *pC = *pC + a * _lof2(sumf);

		break;

	  default:
		ptrC = (__float2_t *) pC;
		// update c[0,0] and c[0,1]
		regC = *ptrC;
		regS = _ftof2(_lof2(sum0),-_hif2(sum0));
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
		// update c[0,2] and c[0,3]
		regC = *ptrC;
		regS = _ftof2(_lof2(sum2),-_hif2(sum2));
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

		// update c[0,4] and c[0,5]
	    regC = *ptrC;
		regS = _ftof2(_lof2(sum4),-_hif2(sum4));
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
		// update c[0,6] and c[0,7]
		regC = *ptrC;
		regS = _ftof2(_lof2(sum6),-_hif2(sum6));
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

		// move to next column
		ptrC += index;
		// update c[1,0] and c[1,1]
		regC = *ptrC;
		regS = sum1;
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
		// update c[1,2] and c[1,3]
		regC = *ptrC;
		regS = sum3;
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

		// update c[1,4] and c[1,5]
		regC = *ptrC;
		regS = sum5;
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
		// update c[1,6] and c[1,7]
		regC = *ptrC;
		regS = sum7;
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

		// move to next column
		ptrC += index;
		// update c[2,0] and c[2,1]
		regC = *ptrC;
		regS = _ftof2(_lof2(sum8),-_hif2(sum8));
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
		// update c[2,2] and c[2,3]
		regC = *ptrC;
		regS = _ftof2(_lof2(suma),-_hif2(suma));
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

		// update c[2,4] and c[2,5]
		regC = *ptrC;
		regS = _ftof2(_lof2(sumc),-_hif2(sumc));
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
		// update c[2,6] and c[2,7]
		regC = *ptrC;
		regS = _ftof2(_lof2(sume),-_hif2(sume));
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

		// move to next column
		ptrC += index;
		// update c[3,0] and c[3,1]
		regC = *ptrC;
		regS = sum9;
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
		// update c[3,2] and c[3,3]
		regC = *ptrC;
		regS = sumb;
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);

		// update c[3,4] and c[3,5]
		regC = *ptrC;
		regS = sumd;
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
		// update c[3,6] and c[3,7]
		regC = *ptrC;
		regS = sumf;
		*ptrC++ = _daddsp(_dmpysp(regA2, regS), regC);
	}
  }
  return;
} // sgemmKernelFlexSave()


void sgemmKernelNoReadFlexSave(const real *pA, const real *pB, real *pC, const real a, const int k, const int stepC, const int saveLoc, const int flagisN)
{
  __float2_t sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7;
  __float2_t sum8, sum9, suma, sumb, sumc, sumd, sume, sumf;
  __float2_t * restrict ptrB     = (__float2_t *) pB;
  __float2_t * restrict ptrA     = (__float2_t *) pA;
  __float2_t * restrict ptrC;
  __float2_t regA2, regS;
  int_least16_t index;

  // zero out accumulators
  sum0 = 0.0;
  sum1 = 0.0;
  sum2 = 0.0;
  sum3 = 0.0;
  sum4 = 0.0;
  sum5 = 0.0;
  sum6 = 0.0;
  sum7 = 0.0;
  sum8 = 0.0;
  sum9 = 0.0;
  suma = 0.0;
  sumb = 0.0;
  sumc = 0.0;
  sumd = 0.0;
  sume = 0.0;
  sumf = 0.0;

  for (index = 0; index < k; index++)
  { // loop over k;
    // each iteration performs rank one update of 4x1 by 1x8
    // matrices of A and B respectively; result is
    // accumulated over 4x8 matrix
	__float2_t b01, b23, b45, b67, a01, a23;
	__x128_t   reg128;

	a01 = *ptrA++;
	a23 = *ptrA++;

    b01 = *ptrB++;
    b23 = *ptrB++;
    b45 = *ptrB++;
    b67 = *ptrB++;

    reg128 = _cmpysp(a01, b01);
    // accumulate a[0]*b[1] and -a[0]*b[0]
    sum0 = _daddsp(sum0, _lof2_128(reg128));
    // accumulate a[1]*b[0] and a[1]*b[1]
    sum1 = _daddsp(sum1, _hif2_128(reg128));

    reg128 = _cmpysp(a01, b23);
    // accumulate a[0]*b[3] and -a[0]*b[2]
    sum2 = _daddsp(sum2, _lof2_128(reg128));
    // accumulate a[1]*b[2] and a[1]*b[3]
    sum3 = _daddsp(sum3, _hif2_128(reg128));

    reg128 = _cmpysp(a01, b45);
    // accumulate a[0]*b[5] and -a[0]*b[4]
    sum4 = _daddsp(sum4, _lof2_128(reg128));
    // accumulate a[1]*b[4] and a[1]*b[5]
    sum5 = _daddsp(sum5, _hif2_128(reg128));

    reg128 = _cmpysp(a01, b67);
    // accumulate a[0]*b[7] and -a[0]*b[6]
    sum6 = _daddsp(sum6, _lof2_128(reg128));
    // accumulate a[1]*b[6] and a[1]*b[7]
    sum7 = _daddsp(sum7, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b01);
    // accumulate a[2]*b[1] and -a[2]*b[0]
    sum8 = _daddsp(sum8, _lof2_128(reg128));
    // accumulate a[3]*b[0] and a[3]*b[1]
    sum9 = _daddsp(sum9, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b23);
    // accumulate a[2]*b[3] and -a[2]*b[2]
    suma = _daddsp(suma, _lof2_128(reg128));
    // accumulate a[3]*b[2] and a[3]*b[3]
    sumb = _daddsp(sumb, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b45);
    // accumulate a[2]*b[5] and -a[2]*b[4]
    sumc = _daddsp(sumc, _lof2_128(reg128));
    // accumulate a[3]*b[4] and a[3]*b[5]
    sumd = _daddsp(sumd, _hif2_128(reg128));

    reg128 = _cmpysp(a23, b67);
    // accumulate a[2]*b[7] and -a[2]*b[6]
    sume = _daddsp(sume, _lof2_128(reg128));
    // accumulate a[3]*b[6] and a[3]*b[7]
    sumf = _daddsp(sumf, _hif2_128(reg128));
  }

  regA2 = _ftof2(a, a);
  if(flagisN>0) // saving in normal form
  {
	index = (stepC>>1)-2;
      switch(saveLoc)
	  {
	    case -3:
	    case -2:
	    case -1:
	    case 0:
	    case 1:
	    case 2:
	    case 3:
	    case 4:
	    case 5:
	    case 6:
	  	  ptrC = (__float2_t *) pC;
		  // save c[0,0] and c[1,0]
		  regS = _ftof2(_lof2(sum1),-_hif2(sum0));
		  if(saveLoc>-1) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;
		  // save c[2,0] and c[3,0]
		  regS = _ftof2(_lof2(sum9),-_hif2(sum8));
		  if(saveLoc>-3) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;

		    // move to next column
		  ptrC += index;
		  // save c[0,1] and c[1,1]
		  regS = _ftof2(_hif2(sum1),_lof2(sum0));
		  if(saveLoc>0) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;
		  // save c[2,1] and c[3,1]
		  regS = _ftof2(_hif2(sum9),_lof2(sum8));
		  if(saveLoc>-2) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;

		  // move to next column
		  ptrC += index;
		  // save c[0,2] and c[1,2]
		  regS = _ftof2(_lof2(sum3),-_hif2(sum2));
		  if(saveLoc>1) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;
		  // save c[2,2] and c[3,2]
		  regS = _ftof2(_lof2(sumb),-_hif2(suma));
		  if(saveLoc>-1) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;

		  // move to next column
		  ptrC += index;
		  // save c[0,3] and c[1,3]
		  regS = _ftof2(_hif2(sum3),_lof2(sum2));
		  if(saveLoc>2) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;
		  // save c[2,3] and c[3,3]
		  regS = _ftof2(_hif2(sumb),_lof2(suma));
		  if(saveLoc>0) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;

		  // move to next column
		  ptrC += index;
		  // save c[0,4] and c[1,4]
		  regS = _ftof2(_lof2(sum5),-_hif2(sum4));
		  if(saveLoc>3) *ptrC =  _dmpysp(regA2, regS);
		  ptrC++;
		  // save c[2,4] and c[3,4]
		  regS = _ftof2(_lof2(sumd),-_hif2(sumc));
		  if(saveLoc>1) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;

		  // move to next column
		  ptrC += index;
		  // save c[0,5] and c[1,5]
		  regS = _ftof2(_hif2(sum5),_lof2(sum4));
		  if(saveLoc>4) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;
		  // save c[2,5] and c[3,5]
		  regS = _ftof2(_hif2(sumd),_lof2(sumc));
		  if(saveLoc>2) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;

		  // move to next column
		  ptrC += index;
		  // save c[0,6] and c[1,6]
		  regS = _ftof2(_lof2(sum7),-_hif2(sum6));
		  if(saveLoc>5) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;
		  // save c[2,6] and c[3,6]
		  regS = _ftof2(_lof2(sumf),-_hif2(sume));
		  if(saveLoc>3) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;

		  // move to next column
		  ptrC += index;
		  // save c[0,7] and c[1,7]
		  regS = _ftof2(_hif2(sum7),_lof2(sum6));
		  if(saveLoc>6) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;
		  // save c[2,7] and c[3,7]
		  regS = _ftof2(_hif2(sumf),_lof2(sume));
		  if(saveLoc>4) *ptrC = _dmpysp(regA2, regS);
		  ptrC++;

		  // save c[1,0] if necessary
		  pC++;
		  if(saveLoc==-1) *pC = a * _lof2(sum1);
		  // save c[3,0] if necessary
		  pC += 2;
		  if(saveLoc==-3) *pC = a * _lof2(sum9);
		  // save c[1,1] if necessary
		  pC += (stepC-2);
		  if(saveLoc==0) *pC = a * _hif2(sum1);
		  // save c[3,1] if necessary
		  pC += 2;
		  if(saveLoc==-2) *pC = a * _hif2(sum9);
		  // save c[1,2] if necessary
		  pC += (stepC-2);
		  if(saveLoc==1) *pC = a * _lof2(sum3);
		  // save c[3,2] if necessary
		  pC += 2;
		  if(saveLoc==-1) *pC = a * _lof2(sumb);
		  // save c[1,3] if necessary
		  pC += (stepC-2);
		  if(saveLoc==2) *pC = a * _hif2(sum3);
		  // save c[3,3] if necessary
		  pC += 2;
		  if(saveLoc==0) *pC = a * _hif2(sumb);
		  // save c[1,4] if necessary
		  pC += (stepC-2);
		  if(saveLoc==3) *pC = a * _lof2(sum5);
		  // save c[3,4] if necessary
		  pC += 2;
		  if(saveLoc==1) *pC = a * _lof2(sumd);
		  // save c[1,5] if necessary
		  pC += (stepC-2);
		  if(saveLoc==4) *pC = a * _hif2(sum5);
		  // save c[3,5] if necessary
		  pC += 2;
		  if(saveLoc==2) *pC = a * _hif2(sumd);
		  // save c[1,6] if necessary
		  pC += (stepC-2);
		  if(saveLoc==5) *pC = a * _lof2(sum7);
		  // save c[3,6] if necessary
		  pC += 2;
		  if(saveLoc==3) *pC = a * _lof2(sumf);
		  // save c[1,7] if necessary
		  pC += (stepC-2);
		  if(saveLoc==6) *pC = a * _hif2(sum7);
		  // save c[3,7] if necessary
		  pC += 2;
		  if(saveLoc==4) *pC = a * _hif2(sumf);

		  break;
	    default:
	      ptrC = (__float2_t *) pC;
	      // save c[0,0] and c[1,0]
	      regS = _ftof2(_lof2(sum1),-_hif2(sum0));
	      *ptrC++ = _dmpysp(regA2, regS);
	      // save c[2,0] and c[3,0]
	      regS = _ftof2(_lof2(sum9),-_hif2(sum8));
	      *ptrC++ = _dmpysp(regA2, regS);

	      // move to next column
	      ptrC += index;
	      // save c[0,1] and c[1,1]
	      regS = _ftof2(_hif2(sum1),_lof2(sum0));
	      *ptrC++ = _dmpysp(regA2, regS);
	      // save c[2,1] and c[3,1]
	      regS = _ftof2(_hif2(sum9),_lof2(sum8));
	      *ptrC++ = _dmpysp(regA2, regS);

	      // move to next column
	      ptrC += index;
	      // save c[0,2] and c[1,2]
	      regS = _ftof2(_lof2(sum3),-_hif2(sum2));
	      *ptrC++ = _dmpysp(regA2, regS);
	      // save c[2,2] and c[3,2]
	      regS = _ftof2(_lof2(sumb),-_hif2(suma));
	      *ptrC++ = _dmpysp(regA2, regS);

	      // move to next column
	      ptrC += index;
	      // save c[0,3] and c[1,3]
	      regS = _ftof2(_hif2(sum3),_lof2(sum2));
	      *ptrC++ = _dmpysp(regA2, regS);
	      // save c[2,3] and c[3,3]
	      regS = _ftof2(_hif2(sumb),_lof2(suma));
	      *ptrC++ = _dmpysp(regA2, regS);

	      // move to next column
	      ptrC += index;
	      // save c[0,4] and c[1,4]
	      regS = _ftof2(_lof2(sum5),-_hif2(sum4));
	      *ptrC++ = _dmpysp(regA2, regS);
	      // save c[2,4] and c[3,4]
	      regS = _ftof2(_lof2(sumd),-_hif2(sumc));
	      *ptrC++ = _dmpysp(regA2, regS);

	      // move to next column
	      ptrC += index;
	      // save c[0,5] and c[1,5]
	      regS = _ftof2(_hif2(sum5),_lof2(sum4));
	      *ptrC++ = _dmpysp(regA2, regS);
	      // save c[2,5] and c[3,5]
	      regS = _ftof2(_hif2(sumd),_lof2(sumc));
	      *ptrC++ = _dmpysp(regA2, regS);

	      // move to next column
	      ptrC += index;
	      // save c[0,6] and c[1,6]
	      regS = _ftof2(_lof2(sum7),-_hif2(sum6));
	      *ptrC++ = _dmpysp(regA2, regS);
	      // save c[2,6] and c[3,6]
	      regS = _ftof2(_lof2(sumf),-_hif2(sume));
	      *ptrC++ = _dmpysp(regA2, regS);

	      // move to next column
	      ptrC += index;
	      // save c[0,7] and c[1,7]
	      regS = _ftof2(_hif2(sum7),_lof2(sum6));
	      *ptrC++ = _dmpysp(regA2, regS);
	      // save c[2,7] and c[3,7]
	      regS = _ftof2(_hif2(sumf),_lof2(sume));
	      *ptrC++ = _dmpysp(regA2, regS);
	    }
	  }
	  else // saving in transpose form
	  {
	    index = (stepC>>1)-4;

		switch(saveLoc)
		{
		  case -3:
		  case -2:
		  case -1:
		  case 0:
		  case 1:
		  case 2:
		  case 3:
		  case 4:
		  case 5:
		  case 6:
		    ptrC = (__float2_t *) pC;
			// save c[0,0] and c[0,1]
			regS = _ftof2(_lof2(sum0),-_hif2(sum0));
			if(saveLoc>0) *ptrC = _dmpysp(regA2, regS);
			ptrC++;
			// save c[0,2] and c[0,3]
			regS = _ftof2(_lof2(sum2),-_hif2(sum2));
			if(saveLoc>2) *ptrC = _dmpysp(regA2, regS);
			ptrC++;

			// save c[0,4] and c[0,5]
			regS = _ftof2(_lof2(sum4),-_hif2(sum4));
			if(saveLoc>4) *ptrC = _dmpysp(regA2, regS);
			ptrC++;
			// save c[0,6] and c[0,7]
			regS = _ftof2(_lof2(sum6),-_hif2(sum6));
			if(saveLoc>6) *ptrC = _dmpysp(regA2, regS);
			ptrC++;

			// move to next column
			ptrC += index;
			// save c[1,0] and c[1,1]
			regS = sum1;
			if(saveLoc>-1) *ptrC = _dmpysp(regA2, regS);
			ptrC++;
			// save c[1,2] and c[1,3]
			regS = sum3;
			if(saveLoc>1) *ptrC = _dmpysp(regA2, regS);
			ptrC++;

			// save c[1,4] and c[1,5]
			regS = sum5;
			if(saveLoc>3) *ptrC = _dmpysp(regA2, regS);
			ptrC++;
			// save c[1,6] and c[1,7]
			regS = sum7;
			if(saveLoc>5) *ptrC = _dmpysp(regA2, regS);
			ptrC++;

			// move to next column
			ptrC += index;
			// save c[2,0] and c[2,1]
			regS = _ftof2(_lof2(sum8),-_hif2(sum8));
			if(saveLoc>-2) *ptrC = _dmpysp(regA2, regS);
			ptrC++;
			// save c[2,2] and c[2,3]
			regS = _ftof2(_lof2(suma),-_hif2(suma));
			if(saveLoc>0) *ptrC = _dmpysp(regA2, regS);
			ptrC++;

			// save c[2,4] and c[2,5]
			regS = _ftof2(_lof2(sumc),-_hif2(sumc));
			if(saveLoc>2) *ptrC = _dmpysp(regA2, regS);
			ptrC++;
			// save c[2,6] and c[2,7]
			regS = _ftof2(_lof2(sume),-_hif2(sume));
			if(saveLoc>4) *ptrC = _dmpysp(regA2, regS);
			ptrC++;

			// move to next column
			ptrC += index;
			// save c[3,0] and c[3,1]
			regS = sum9;
			if(saveLoc>-3) *ptrC = _dmpysp(regA2, regS);
			ptrC++;
			// save c[3,2] and c[3,3]
			regS = sumb;
			if(saveLoc>-1) *ptrC = _dmpysp(regA2, regS);
			ptrC++;

			// save c[3,4] and c[3,5]
			regS = sumd;
			if(saveLoc>1) *ptrC = _dmpysp(regA2, regS);
			ptrC++;
			// save c[3,6] and c[3,7]
			regS = sumf;
			if(saveLoc>3) *ptrC = _dmpysp(regA2, regS);
			ptrC++;

			// save c[0,0] if necessary
			if(saveLoc==0) *pC = - a * _hif2(sum0);
			// save c[0,2] if necessary
			pC += 2;
			if(saveLoc==2) *pC = - a * _hif2(sum2);
			// save c[0,4] if necessary
			pC += 2;
			if(saveLoc==4) *pC = - a * _hif2(sum4);
			// save c[0,6] if necessary
			pC += 2;
			if(saveLoc==6) *pC = - a * _hif2(sum6);
			// save c[1,0] if necessary
			pC += (stepC-6);
			if(saveLoc==-1) *pC = a * _lof2(sum1);
			// save c[1,2] if necessary
			pC += 2;
			if(saveLoc==1) *pC = a * _lof2(sum3);
			// save c[1,4] if necessary
			pC += 2;
			if(saveLoc==3) *pC = a * _lof2(sum5);
			// save c[1,6] if necessary
			pC += 2;
			if(saveLoc==5) *pC = a * _lof2(sum7);
			// save c[2,0] if necessary
			pC += (stepC-6);
			if(saveLoc==-2) *pC = - a * _hif2(sum8);
			// save c[2,2] if necessary
			pC += 2;
			if(saveLoc==0) *pC = - a * _hif2(suma);
			// save c[2,4] if necessary
			pC += 2;
			if(saveLoc==2) *pC = - a * _hif2(sumc);
			// save c[2,6] if necessary
			pC += 2;
			if(saveLoc==4) *pC = - a * _hif2(sume);
			// save c[3,0] if necessary
			pC += (stepC-6);
			if(saveLoc==-3) *pC = a * _lof2(sum9);
			// save c[3,2] if necessary
			pC += 2;
			if(saveLoc==-1) *pC = a * _lof2(sumb);
			// save c[3,4] if necessary
			pC += 2;
			if(saveLoc==1) *pC = a * _lof2(sumd);
			// save c[3,6] if necessary
			pC += 2;
			if(saveLoc==3) *pC = a * _lof2(sumf);

			break;

		  default:
			ptrC = (__float2_t *) pC;
			// save c[0,0] and c[0,1]
			regS = _ftof2(_lof2(sum0),-_hif2(sum0));
			*ptrC++ = _dmpysp(regA2, regS);
			// save c[0,2] and c[0,3]
			regS = _ftof2(_lof2(sum2),-_hif2(sum2));
			*ptrC++ = _dmpysp(regA2, regS);

			// save c[0,4] and c[0,5]
			regS = _ftof2(_lof2(sum4),-_hif2(sum4));
			*ptrC++ = _dmpysp(regA2, regS);
			// save c[0,6] and c[0,7]
			regS = _ftof2(_lof2(sum6),-_hif2(sum6));
			*ptrC++ = _dmpysp(regA2, regS);

			// move to next column
			ptrC += index;
			// save c[1,0] and c[1,1]
			regS = sum1;
			*ptrC++ = _dmpysp(regA2, regS);
			// save c[1,2] and c[1,3]
			regS = sum3;
			*ptrC++ = _dmpysp(regA2, regS);

			// save c[1,4] and c[1,5]
			regS = sum5;
			*ptrC++ = _dmpysp(regA2, regS);
			// save c[1,6] and c[1,7]
			regS = sum7;
			*ptrC++ = _dmpysp(regA2, regS);

			// move to next column
			ptrC += index;
			// save c[2,0] and c[2,1]
			regS = _ftof2(_lof2(sum8),-_hif2(sum8));
			*ptrC++ = _dmpysp(regA2, regS);
			// save c[2,2] and c[2,3]
			regS = _ftof2(_lof2(suma),-_hif2(suma));
			*ptrC++ = _dmpysp(regA2, regS);

			// save c[2,4] and c[2,5]
			regS = _ftof2(_lof2(sumc),-_hif2(sumc));
			*ptrC++ = _dmpysp(regA2, regS);
			// save c[2,6] and c[2,7]
			regS = _ftof2(_lof2(sume),-_hif2(sume));
			*ptrC++ = _dmpysp(regA2, regS);

			// move to next column
			ptrC += index;
			// save c[3,0] and c[3,1]
			regS = sum9;
			*ptrC++ = _dmpysp(regA2, regS);
			// save c[3,2] and c[3,3]
			regS = sumb;
			*ptrC++ = _dmpysp(regA2, regS);

			// save c[3,4] and c[3,5]
			regS = sumd;
			*ptrC++ = _dmpysp(regA2, regS);
			// save c[3,6] and c[3,7]
			regS = sumf;
			*ptrC++ = _dmpysp(regA2, regS);
		}
	  }
	  return;
} // sgemmKernelNoReadFlexSave()

