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
 *  @file   strsmKernel.c
 *  @brief  This file contains kernel functions for single precision
 *          triangular matrix inversion implementation of sizes
 *          4xk by kx8 producing 4x8 output. This is C66 intrinsic
 *          optimized code.
 *
 */

#include "c6x.h"
#include "strsmKernel.h"
#include "defSC66.h"

void strsmKernel(const real *pA, real *pB, real *pC, real *pBHat, const int k, const int stepC, const int flagisN, const int flagisL)
{
  __float2_t sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7;
  __float2_t sum8, sum9, suma, sumb, sumc, sumd, sume, sumf;
  __float2_t * restrict ptrB     = (__float2_t *) pB;
  __float2_t * restrict ptrA     = (__float2_t *) pA;
  __float2_t * restrict ptrC;
  __float2_t regC, regS, regS0, regS1, regS2, regS3;
  real reg0, reg1, * restrict pRegB;
  __float2_t * restrict ptrBH;
  const real * restrict pReg;
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

  if(flagisN>0) // saving in normal form
  {
	if(flagisL)
	{
	  index = (stepC>>1)-2;

      regS = _ftof2(_lof2(sum1),-_hif2(sum0));
	  // c[0,1] and c[1,1]
	  sum1 = _ftof2(_hif2(sum1),_lof2(sum0));
	  // c[0,0] and c[1,0]
	  sum0 = regS;

	  regS = _ftof2(_lof2(sum3),-_hif2(sum2));
	  // c[0,3] and c[1,3]
	  sum3 = _ftof2(_hif2(sum3),_lof2(sum2));
	  // c[0,2] and c[1,2]
	  sum2 = regS;

	  regS = _ftof2(_lof2(sum5),-_hif2(sum4));
	  // c[0,5] and c[1,5]
	  sum5 = _ftof2(_hif2(sum5),_lof2(sum4));
	  // c[0,4] and c[1,4]
	  sum4 = regS;

	  regS = _ftof2(_lof2(sum7),-_hif2(sum6));
	  // c[0,7] and c[1,7]
	  sum7 = _ftof2(_hif2(sum7),_lof2(sum6));
	  // c[0,6] and c[1,6]
	  sum6 = regS;

	  regS = _ftof2(_lof2(sum9),-_hif2(sum8));
	  // c[2,1] and c[3,1]
	  sum9 = _ftof2(_hif2(sum9),_lof2(sum8));
	  // c[2,0] and c[3,0]
	  sum8 = regS;

	  regS = _ftof2(_lof2(sumb),-_hif2(suma));
	  // c[2,3] and c[3,3]
	  sumb = _ftof2(_hif2(sumb),_lof2(suma));
	  // c[2,2] and c[3,2]
	  suma = regS;

	  regS = _ftof2(_lof2(sumd),-_hif2(sumc));
	  // c[2,5] and c[3,5]
	  sumd = _ftof2(_hif2(sumd),_lof2(sumc));
	  // c[2,4] and c[3,4]
	  sumc = regS;

	  regS = _ftof2(_lof2(sumf),-_hif2(sume));
	  // c[2,7] and c[3,7]
	  sumf = _ftof2(_hif2(sumf),_lof2(sume));
	  // c[2,6] and c[3,6]
	  sume = regS;

	  ptrC = (__float2_t *) pC;

	  regC = *ptrC++;
      sum0 = _dsubsp(regC,sum0);
	  regC = *ptrC++;
      sum8 = _dsubsp(regC,sum8);

	  // move to next column
      ptrC += index;
	  regC = *ptrC++;
      sum1 = _dsubsp(regC,sum1);
	  regC = *ptrC++;
      sum9 = _dsubsp(regC,sum9);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum2 = _dsubsp(regC,sum2);
	  regC = *ptrC++;
      suma = _dsubsp(regC,suma);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum3 = _dsubsp(regC,sum3);
	  regC = *ptrC++;
      sumb = _dsubsp(regC,sumb);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum4 = _dsubsp(regC,sum4);
	  regC = *ptrC++;
      sumc = _dsubsp(regC,sumc);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum5 = _dsubsp(regC,sum5);
	  regC = *ptrC++;
      sumd = _dsubsp(regC,sumd);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum6 = _dsubsp(regC,sum6);
	  regC = *ptrC++;
      sume = _dsubsp(regC,sume);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum7 = _dsubsp(regC,sum7);
	  regC = *ptrC++;
      sumf = _dsubsp(regC,sumf);

	  pReg = pA+k*M_KERNEL_S;
	  pRegB = pB+k*N_KERNEL_S;
	  ptrBH = (__float2_t *) (pBHat+k);
	  // load the 4x4 triangular inverse matrix
	  reg0 = *pReg;
	  reg1 = *(pReg+2*M_KERNEL_S+2);
	  regS0 = _ftof2(*(pReg+M_KERNEL_S+1), *(pReg+1));
	  regS1 = _ftof2(*(pReg+M_KERNEL_S+2), *(pReg+2));
	  regS2 = _ftof2(*(pReg+M_KERNEL_S+3), *(pReg+3));
	  regS3 = _ftof2(*(pReg+3*M_KERNEL_S+3), *(pReg+2*M_KERNEL_S+3));

	  ptrC = (__float2_t *) pC;
	  // update c[0,0] and c[1,0]
	  regS = _dmpysp(sum0,regS0);
	  regS = _ftof2(_lof2(regS)+_hif2(regS),reg0*_lof2(sum0));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  // update c[2,0] and c[3,0]
	  regS = _dmpysp(regS1,sum0);
	  regC = _daddsp(_dmpysp(regS2,sum0),_dmpysp(regS3,sum8));
	  regS = _ftof2(_lof2(regC)+_hif2(regC),_lof2(regS)+_hif2(regS)+reg1*_lof2(sum8));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,1] and c[1,1]
	  regS = _dmpysp(sum1,regS0);
	  regS = _ftof2(_lof2(regS)+_hif2(regS),reg0*_lof2(sum1));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  // update c[2,1] and c[3,1]
	  regS = _dmpysp(regS1,sum1);
	  regC = _daddsp(_dmpysp(regS2,sum1),_dmpysp(regS3,sum9));
	  regS = _ftof2(_lof2(regC)+_hif2(regC),_lof2(regS)+_hif2(regS)+reg1*_lof2(sum9));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,2] and c[1,2]
	  regS = _dmpysp(sum2,regS0);
	  regS = _ftof2(_lof2(regS)+_hif2(regS),reg0*_lof2(sum2));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  // update c[2,2] and c[3,2]
	  regS = _dmpysp(regS1,sum2);
	  regC = _daddsp(_dmpysp(regS2,sum2),_dmpysp(regS3,suma));
	  regS = _ftof2(_lof2(regC)+_hif2(regC),_lof2(regS)+_hif2(regS)+reg1*_lof2(suma));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,3] and c[1,3]
	  regS = _dmpysp(sum3,regS0);
	  regS = _ftof2(_lof2(regS)+_hif2(regS),reg0*_lof2(sum3));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  // update c[2,3] and c[3,3]
	  regS = _dmpysp(regS1,sum3);
	  regC = _daddsp(_dmpysp(regS2,sum3),_dmpysp(regS3,sumb));
	  regS = _ftof2(_lof2(regC)+_hif2(regC),_lof2(regS)+_hif2(regS)+reg1*_lof2(sumb));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,4] and c[1,4]
	  regS = _dmpysp(sum4,regS0);
	  regS = _ftof2(_lof2(regS)+_hif2(regS),reg0*_lof2(sum4));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  // update c[2,4] and c[3,4]
	  regS = _dmpysp(regS1,sum4);
	  regC = _daddsp(_dmpysp(regS2,sum4),_dmpysp(regS3,sumc));
	  regS = _ftof2(_lof2(regC)+_hif2(regC),_lof2(regS)+_hif2(regS)+reg1*_lof2(sumc));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,5] and c[1,5]
	  regS = _dmpysp(sum5,regS0);
	  regS = _ftof2(_lof2(regS)+_hif2(regS),reg0*_lof2(sum5));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  // update c[2,5] and c[3,5]
	  regS = _dmpysp(regS1,sum5);
	  regC = _daddsp(_dmpysp(regS2,sum5),_dmpysp(regS3,sumd));
	  regS = _ftof2(_lof2(regC)+_hif2(regC),_lof2(regS)+_hif2(regS)+reg1*_lof2(sumd));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,4] and c[1,4]
	  regS = _dmpysp(sum6,regS0);
	  regS = _ftof2(_lof2(regS)+_hif2(regS),reg0*_lof2(sum6));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  // update c[2,4] and c[3,4]
	  regS = _dmpysp(regS1,sum6);
	  regC = _daddsp(_dmpysp(regS2,sum6),_dmpysp(regS3,sume));
	  regS = _ftof2(_lof2(regC)+_hif2(regC),_lof2(regS)+_hif2(regS)+reg1*_lof2(sume));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,7] and c[1,7]
	  regS = _dmpysp(sum7,regS0);
	  regS = _ftof2(_lof2(regS)+_hif2(regS),reg0*_lof2(sum7));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  // update c[2,7] and c[3,7]
	  regS = _dmpysp(regS1,sum7);
	  regC = _daddsp(_dmpysp(regS2,sum7),_dmpysp(regS3,sumf));
	  regS = _ftof2(_lof2(regC)+_hif2(regC),_lof2(regS)+_hif2(regS)+reg1*_lof2(sumf));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	}
	else
	{
	  index = (stepC>>1)-2;

      regS = _ftof2(_lof2(sum1),-_hif2(sum0));
	  // c[0,1] and c[1,1]
	  sum1 = _ftof2(_hif2(sum1),_lof2(sum0));
	  // c[0,0] and c[1,0]
	  sum0 = regS;

	  regS = _ftof2(_lof2(sum3),-_hif2(sum2));
	  // c[0,3] and c[1,3]
	  sum3 = _ftof2(_hif2(sum3),_lof2(sum2));
	  // c[0,2] and c[1,2]
	  sum2 = regS;

	  regS = _ftof2(_lof2(sum5),-_hif2(sum4));
	  // c[0,5] and c[1,5]
	  sum5 = _ftof2(_hif2(sum5),_lof2(sum4));
	  // c[0,4] and c[1,4]
	  sum4 = regS;

	  regS = _ftof2(_lof2(sum7),-_hif2(sum6));
	  // c[0,7] and c[1,7]
	  sum7 = _ftof2(_hif2(sum7),_lof2(sum6));
	  // c[0,6] and c[1,6]
	  sum6 = regS;

	  regS = _ftof2(_lof2(sum9),-_hif2(sum8));
	  // c[2,1] and c[3,1]
	  sum9 = _ftof2(_hif2(sum9),_lof2(sum8));
	  // c[2,0] and c[3,0]
	  sum8 = regS;

	  regS = _ftof2(_lof2(sumb),-_hif2(suma));
	  // c[2,3] and c[3,3]
	  sumb = _ftof2(_hif2(sumb),_lof2(suma));
	  // c[2,2] and c[3,2]
	  suma = regS;

	  regS = _ftof2(_lof2(sumd),-_hif2(sumc));
	  // c[2,5] and c[3,5]
	  sumd = _ftof2(_hif2(sumd),_lof2(sumc));
	  // c[2,4] and c[3,4]
	  sumc = regS;

	  regS = _ftof2(_lof2(sumf),-_hif2(sume));
	  // c[2,7] and c[3,7]
	  sumf = _ftof2(_hif2(sumf),_lof2(sume));
	  // c[2,6] and c[3,6]
	  sume = regS;

	  ptrC = (__float2_t *) pC;

	  regC = *ptrC++;
      sum0 = _dsubsp(regC,sum0);
	  regC = *ptrC++;
      sum8 = _dsubsp(regC,sum8);

	  // move to next column
      ptrC += index;
	  regC = *ptrC++;
      sum1 = _dsubsp(regC,sum1);
	  regC = *ptrC++;
      sum9 = _dsubsp(regC,sum9);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum2 = _dsubsp(regC,sum2);
	  regC = *ptrC++;
      suma = _dsubsp(regC,suma);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum3 = _dsubsp(regC,sum3);
	  regC = *ptrC++;
      sumb = _dsubsp(regC,sumb);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum4 = _dsubsp(regC,sum4);
	  regC = *ptrC++;
      sumc = _dsubsp(regC,sumc);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum5 = _dsubsp(regC,sum5);
	  regC = *ptrC++;
      sumd = _dsubsp(regC,sumd);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum6 = _dsubsp(regC,sum6);
	  regC = *ptrC++;
      sume = _dsubsp(regC,sume);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum7 = _dsubsp(regC,sum7);
	  regC = *ptrC++;
      sumf = _dsubsp(regC,sumf);

	  pReg = pA-M_KERNEL_S*M_KERNEL_S;
	  pRegB = pB-M_KERNEL_S*N_KERNEL_S;
	  ptrBH = (__float2_t *) (pBHat-M_KERNEL_S);
	  // load the 4x4 triangular inverse matrix
	  reg0 = *(pReg+3*M_KERNEL_S+3);;
	  reg1 = *(pReg+  M_KERNEL_S+1);
	  regS0 = _ftof2(*(pReg+3*M_KERNEL_S+2), *(pReg+2*M_KERNEL_S+2));
	  regS1 = _ftof2(*(pReg+3*M_KERNEL_S+1), *(pReg+2*M_KERNEL_S+1));
	  regS2 = _ftof2(*(pReg+3*M_KERNEL_S  ), *(pReg+2*M_KERNEL_S  ));
	  regS3 = _ftof2(*(pReg+  M_KERNEL_S  ), *(pReg                      ));

	  ptrC = (__float2_t *) pC;
	  // update c[0,0] and c[1,0]
	  // update c[2,0] and c[3,0]
	  regS = _dmpysp(regS1,sum8);
	  regC = _daddsp(_dmpysp(regS3,sum0),_dmpysp(regS2,sum8));
	  regS = _ftof2(_lof2(regS)+_hif2(regS)+reg1*_hif2(sum0),_lof2(regC)+_hif2(regC));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  regS = _dmpysp(sum8,regS0);
	  regS = _ftof2(reg0*_hif2(sum8),_lof2(regS)+_hif2(regS));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,1] and c[1,1]
	  // update c[2,1] and c[3,1]
	  regS = _dmpysp(regS1,sum9);
	  regC = _daddsp(_dmpysp(regS3,sum1),_dmpysp(regS2,sum9));
	  regS = _ftof2(_lof2(regS)+_hif2(regS)+reg1*_hif2(sum1),_lof2(regC)+_hif2(regC));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  regS = _dmpysp(sum9,regS0);
	  regS = _ftof2(reg0*_hif2(sum9),_lof2(regS)+_hif2(regS));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,1] and c[1,1]
	  // update c[2,1] and c[3,1]
	  regS = _dmpysp(regS1,suma);
	  regC = _daddsp(_dmpysp(regS3,sum2),_dmpysp(regS2,suma));
	  regS = _ftof2(_lof2(regS)+_hif2(regS)+reg1*_hif2(sum2),_lof2(regC)+_hif2(regC));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  regS = _dmpysp(suma,regS0);
	  regS = _ftof2(reg0*_hif2(suma),_lof2(regS)+_hif2(regS));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,1] and c[1,1]
	  // update c[2,1] and c[3,1]
	  regS = _dmpysp(regS1,sumb);
	  regC = _daddsp(_dmpysp(regS3,sum3),_dmpysp(regS2,sumb));
	  regS = _ftof2(_lof2(regS)+_hif2(regS)+reg1*_hif2(sum3),_lof2(regC)+_hif2(regC));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  regS = _dmpysp(sumb,regS0);
	  regS = _ftof2(reg0*_hif2(sumb),_lof2(regS)+_hif2(regS));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,1] and c[1,1]
	  // update c[2,1] and c[3,1]
	  regS = _dmpysp(regS1,sumc);
	  regC = _daddsp(_dmpysp(regS3,sum4),_dmpysp(regS2,sumc));
	  regS = _ftof2(_lof2(regS)+_hif2(regS)+reg1*_hif2(sum4),_lof2(regC)+_hif2(regC));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  regS = _dmpysp(sumc,regS0);
	  regS = _ftof2(reg0*_hif2(sumc),_lof2(regS)+_hif2(regS));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,1] and c[1,1]
	  // update c[2,1] and c[3,1]
	  regS = _dmpysp(regS1,sumd);
	  regC = _daddsp(_dmpysp(regS3,sum5),_dmpysp(regS2,sumd));
	  regS = _ftof2(_lof2(regS)+_hif2(regS)+reg1*_hif2(sum5),_lof2(regC)+_hif2(regC));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  regS = _dmpysp(sumd,regS0);
	  regS = _ftof2(reg0*_hif2(sumd),_lof2(regS)+_hif2(regS));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,1] and c[1,1]
	  // update c[2,1] and c[3,1]
	  regS = _dmpysp(regS1,sume);
	  regC = _daddsp(_dmpysp(regS3,sum6),_dmpysp(regS2,sume));
	  regS = _ftof2(_lof2(regS)+_hif2(regS)+reg1*_hif2(sum6),_lof2(regC)+_hif2(regC));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  regS = _dmpysp(sume,regS0);
	  regS = _ftof2(reg0*_hif2(sume),_lof2(regS)+_hif2(regS));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	  // move to next column
	  ptrC += index;
	  ptrBH += ((KPARTITION_S>>1)-2);
	  // update c[0,1] and c[1,1]
	  // update c[2,1] and c[3,1]
	  regS = _dmpysp(regS1,sumf);
	  regC = _daddsp(_dmpysp(regS3,sum7),_dmpysp(regS2,sumf));
	  regS = _ftof2(_lof2(regS)+_hif2(regS)+reg1*_hif2(sum7),_lof2(regC)+_hif2(regC));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB) = _lof2(regS);
	  *(pRegB+N_KERNEL_S) = _hif2(regS);
	  regS = _dmpysp(sumf,regS0);
	  regS = _ftof2(reg0*_hif2(sumf),_lof2(regS)+_hif2(regS));
	  *ptrC++ = regS;
	  *ptrBH++ = regS;
	  *(pRegB+2*N_KERNEL_S) = _lof2(regS);
	  *(pRegB+3*N_KERNEL_S) = _hif2(regS);
	  pRegB++;

	}
  }
  else // saving in transpose form
  {
	if(flagisL)
	{
	  index = (stepC>>1)-4;

	  // c[0,0] and c[0,1]
	  sum0 = _ftof2(_lof2(sum0),-_hif2(sum0));
	  // c[1,0] and c[1,1] in sum1

	  // c[0,2] and c[0,3]
	  sum2 = _ftof2(_lof2(sum2),-_hif2(sum2));
	  // c[1,2] and c[1,3] in sum3

	  // c[0,4] and c[0,5]
	  sum4 = _ftof2(_lof2(sum4),-_hif2(sum4));
	  // c[1,4] and c[1,5] in sum5

	  // c[0,6] and c[0,7]
	  sum6 = _ftof2(_lof2(sum6),-_hif2(sum6));
	  // c[1,6] and c[1,7] in sum7

	  // c[2,0] and c[2,1]
	  sum8 = _ftof2(_lof2(sum8),-_hif2(sum8));
	  // c[3,0] and c[3,1] in sum9

	  // c[2,2] and c[2,3]
	  suma = _ftof2(_lof2(suma),-_hif2(suma));
	  // c[3,2] and c[3,3] in sumb

	  // c[2,4] and c[2,5]
	  sumc = _ftof2(_lof2(sumc),-_hif2(sumc));
	  // c[3,4] and c[3,5] in sumd

	  // c[2,6] and c[2,7]
	  sume = _ftof2(_lof2(sume),-_hif2(sume));
	  // c[3,6] and c[3,7] in sumf

      ptrC = (__float2_t *) pC;
	  regC = *ptrC++;
      sum0 = _dsubsp(regC,sum0);
	  regC = *ptrC++;
      sum2 = _dsubsp(regC,sum2);
	  regC = *ptrC++;
      sum4 = _dsubsp(regC,sum4);
	  regC = *ptrC++;
      sum6 = _dsubsp(regC,sum6);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum1 = _dsubsp(regC,sum1);
	  regC = *ptrC++;
      sum3 = _dsubsp(regC,sum3);
	  regC = *ptrC++;
      sum5 = _dsubsp(regC,sum5);
	  regC = *ptrC++;
      sum7 = _dsubsp(regC,sum7);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum8 = _dsubsp(regC,sum8);
	  regC = *ptrC++;
      suma = _dsubsp(regC,suma);
	  regC = *ptrC++;
      sumc = _dsubsp(regC,sumc);
	  regC = *ptrC++;
      sume = _dsubsp(regC,sume);

	  // move to next column
	  ptrC += index;
      regC = *ptrC++;
      sum9 = _dsubsp(regC,sum9);
	  regC = *ptrC++;
      sumb = _dsubsp(regC,sumb);
	  regC = *ptrC++;
      sumd = _dsubsp(regC,sumd);
	  regC = *ptrC++;
      sumf = _dsubsp(regC,sumf);

	  pReg = pA+k*M_KERNEL_S;
	  regS3 = _ftof2(*(pReg+3*M_KERNEL_S+3), *(pReg+3*M_KERNEL_S+3));
	  regS2 = _ftof2(*(pReg+2*M_KERNEL_S+3), *(pReg+2*M_KERNEL_S+3));
	  regS1 = _ftof2(*(pReg+  M_KERNEL_S+3), *(pReg+  M_KERNEL_S+3));
	  regS0 = _ftof2(*(pReg                    +3), *(pReg                    +3));
	  sum9 = _dmpysp(sum9, regS3);
      sumb = _dmpysp(sumb, regS3);
      sumd = _dmpysp(sumd, regS3);
      sumf = _dmpysp(sumf, regS3);
      sum9 = _daddsp(sum9, _dmpysp(sum8, regS2));
      sumb = _daddsp(sumb, _dmpysp(suma, regS2));
      sumd = _daddsp(sumd, _dmpysp(sumc, regS2));
      sumf = _daddsp(sumf, _dmpysp(sume, regS2));
      sum9 = _daddsp(sum9, _dmpysp(sum1, regS1));
      sumb = _daddsp(sumb, _dmpysp(sum3, regS1));
      sumd = _daddsp(sumd, _dmpysp(sum5, regS1));
      sumf = _daddsp(sumf, _dmpysp(sum7, regS1));
      sum9 = _daddsp(sum9, _dmpysp(sum0, regS0));
      sumb = _daddsp(sumb, _dmpysp(sum2, regS0));
      sumd = _daddsp(sumd, _dmpysp(sum4, regS0));
      sumf = _daddsp(sumf, _dmpysp(sum6, regS0));

	  regS2 = _ftof2(*(pReg+2*M_KERNEL_S+2), *(pReg+2*M_KERNEL_S+2));
	  regS1 = _ftof2(*(pReg+  M_KERNEL_S+2), *(pReg+  M_KERNEL_S+2));
	  regS0 = _ftof2(*(pReg+                   +2), *(pReg                    +2));
	  sum8 = _dmpysp(sum8, regS2);
      suma = _dmpysp(suma, regS2);
      sumc = _dmpysp(sumc, regS2);
      sume = _dmpysp(sume, regS2);
      sum8 = _daddsp(sum8, _dmpysp(sum1, regS1));
      suma = _daddsp(suma, _dmpysp(sum3, regS1));
      sumc = _daddsp(sumc, _dmpysp(sum5, regS1));
      sume = _daddsp(sume, _dmpysp(sum7, regS1));
      sum8 = _daddsp(sum8, _dmpysp(sum0, regS0));
      suma = _daddsp(suma, _dmpysp(sum2, regS0));
      sumc = _daddsp(sumc, _dmpysp(sum4, regS0));
      sume = _daddsp(sume, _dmpysp(sum6, regS0));

	  regS1 = _ftof2(*(pReg+M_KERNEL_S+1), *(pReg+M_KERNEL_S+1));
	  regS0 = _ftof2(*(pReg                  +1), *(pReg                  +1));
      sum1 = _dmpysp(sum1, regS1);
      sum3 = _dmpysp(sum3, regS1);
      sum5 = _dmpysp(sum5, regS1);
      sum7 = _dmpysp(sum7, regS1);
      sum1 = _daddsp(sum1, _dmpysp(sum0, regS0));
      sum3 = _daddsp(sum3, _dmpysp(sum2, regS0));
      sum5 = _daddsp(sum5, _dmpysp(sum4, regS0));
      sum7 = _daddsp(sum7, _dmpysp(sum6, regS0));

	  regS0 = _ftof2(*(pReg), *(pReg));
      sum0 = _dmpysp(sum0, regS0);
      sum2 = _dmpysp(sum2, regS0);
      sum4 = _dmpysp(sum4, regS0);
      sum6 = _dmpysp(sum6, regS0);

	  ptrB = (__float2_t *) (pB+k*N_KERNEL_S);
	  ptrBH = (__float2_t *) (pBHat+k*NPARTITION_S);
      ptrC = (__float2_t *) pC;
      *ptrC++ = sum0;
      *ptrC++ = sum2;
      *ptrC++ = sum4;
      *ptrC++ = sum6;
      *ptrB++ = sum0;
      *ptrB++ = sum2;
      *ptrB++ = sum4;
      *ptrB++ = sum6;
      *ptrBH++ = sum0;
      *ptrBH++ = sum2;
      *ptrBH++ = sum4;
      *ptrBH++ = sum6;
	  // move to next column
	  ptrC += index;
      ptrBH += ((NPARTITION_S>>1)-4);
      *ptrC++ = sum1;
      *ptrC++ = sum3;
      *ptrC++ = sum5;
      *ptrC++ = sum7;
      *ptrB++ = sum1;
      *ptrB++ = sum3;
      *ptrB++ = sum5;
      *ptrB++ = sum7;
      *ptrBH++ = sum1;
      *ptrBH++ = sum3;
      *ptrBH++ = sum5;
      *ptrBH++ = sum7;
	  // move to next column
	  ptrC += index;
      ptrBH += ((NPARTITION_S>>1)-4);
      *ptrC++ = sum8;
      *ptrC++ = suma;
      *ptrC++ = sumc;
      *ptrC++ = sume;
      *ptrB++ = sum8;
      *ptrB++ = suma;
      *ptrB++ = sumc;
      *ptrB++ = sume;
      *ptrBH++ = sum8;
      *ptrBH++ = suma;
      *ptrBH++ = sumc;
      *ptrBH++ = sume;
	  // move to next column
	  ptrC += index;
      ptrBH += ((NPARTITION_S>>1)-4);
      *ptrC++ = sum9;
      *ptrC++ = sumb;
      *ptrC++ = sumd;
      *ptrC++ = sumf;
      *ptrB++ = sum9;
      *ptrB++ = sumb;
      *ptrB++ = sumd;
      *ptrB++ = sumf;
      *ptrBH++ = sum9;
      *ptrBH++ = sumb;
      *ptrBH++ = sumd;
      *ptrBH++ = sumf;
	}
	else
	{
	  index = (stepC>>1)-4;

	  // c[0,0] and c[0,1]
	  sum0 = _ftof2(_lof2(sum0),-_hif2(sum0));
	  // c[1,0] and c[1,1] in sum1

	  // c[0,2] and c[0,3]
	  sum2 = _ftof2(_lof2(sum2),-_hif2(sum2));
	  // c[1,2] and c[1,3] in sum3

	  // c[0,4] and c[0,5]
	  sum4 = _ftof2(_lof2(sum4),-_hif2(sum4));
	  // c[1,4] and c[1,5] in sum5

	  // c[0,6] and c[0,7]
	  sum6 = _ftof2(_lof2(sum6),-_hif2(sum6));
	  // c[1,6] and c[1,7] in sum7

	  // c[2,0] and c[2,1]
	  sum8 = _ftof2(_lof2(sum8),-_hif2(sum8));
	  // c[3,0] and c[3,1] in sum9

	  // c[2,2] and c[2,3]
	  suma = _ftof2(_lof2(suma),-_hif2(suma));
	  // c[3,2] and c[3,3] in sumb

	  // c[2,4] and c[2,5]
	  sumc = _ftof2(_lof2(sumc),-_hif2(sumc));
	  // c[3,4] and c[3,5] in sumd

	  // c[2,6] and c[2,7]
	  sume = _ftof2(_lof2(sume),-_hif2(sume));
	  // c[3,6] and c[3,7] in sumf

      ptrC = (__float2_t *) pC;
	  regC = *ptrC++;
      sum0 = _dsubsp(regC,sum0);
	  regC = *ptrC++;
      sum2 = _dsubsp(regC,sum2);
	  regC = *ptrC++;
      sum4 = _dsubsp(regC,sum4);
	  regC = *ptrC++;
      sum6 = _dsubsp(regC,sum6);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum1 = _dsubsp(regC,sum1);
	  regC = *ptrC++;
      sum3 = _dsubsp(regC,sum3);
	  regC = *ptrC++;
      sum5 = _dsubsp(regC,sum5);
	  regC = *ptrC++;
      sum7 = _dsubsp(regC,sum7);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum8 = _dsubsp(regC,sum8);
	  regC = *ptrC++;
      suma = _dsubsp(regC,suma);
	  regC = *ptrC++;
      sumc = _dsubsp(regC,sumc);
	  regC = *ptrC++;
      sume = _dsubsp(regC,sume);

	  // move to next column
	  ptrC += index;
	  regC = *ptrC++;
      sum9 = _dsubsp(regC,sum9);
	  regC = *ptrC++;
      sumb = _dsubsp(regC,sumb);
	  regC = *ptrC++;
      sumd = _dsubsp(regC,sumd);
	  regC = *ptrC++;
      sumf = _dsubsp(regC,sumf);

	  pReg = pA-M_KERNEL_S*M_KERNEL_S;
	  regS3 = _ftof2(*(pReg+3*M_KERNEL_S), *(pReg+3*M_KERNEL_S));
	  regS2 = _ftof2(*(pReg+2*M_KERNEL_S), *(pReg+2*M_KERNEL_S));
	  regS1 = _ftof2(*(pReg+1*M_KERNEL_S), *(pReg+1*M_KERNEL_S));
	  regS0 = _ftof2(*(pReg                    ), *(pReg                    ));
	  sum0 = _dmpysp(sum0, regS0);
      sum2 = _dmpysp(sum2, regS0);
      sum4 = _dmpysp(sum4, regS0);
      sum6 = _dmpysp(sum6, regS0);
      sum0 = _daddsp(sum0, _dmpysp(sum1, regS1));
      sum2 = _daddsp(sum2, _dmpysp(sum3, regS1));
      sum4 = _daddsp(sum4, _dmpysp(sum5, regS1));
      sum6 = _daddsp(sum6, _dmpysp(sum7, regS1));
      sum0 = _daddsp(sum0, _dmpysp(sum8, regS2));
      sum2 = _daddsp(sum2, _dmpysp(suma, regS2));
      sum4 = _daddsp(sum4, _dmpysp(sumc, regS2));
      sum6 = _daddsp(sum6, _dmpysp(sume, regS2));
      sum0 = _daddsp(sum0, _dmpysp(sum9, regS3));
      sum2 = _daddsp(sum2, _dmpysp(sumb, regS3));
      sum4 = _daddsp(sum4, _dmpysp(sumd, regS3));
      sum6 = _daddsp(sum6, _dmpysp(sumf, regS3));

	  regS3 = _ftof2(*(pReg+3*M_KERNEL_S+1), *(pReg+3*M_KERNEL_S+1));
	  regS2 = _ftof2(*(pReg+2*M_KERNEL_S+1), *(pReg+2*M_KERNEL_S+1));
	  regS1 = _ftof2(*(pReg+1*M_KERNEL_S+1), *(pReg+1*M_KERNEL_S+1));
	  sum1 = _dmpysp(sum1, regS1);
      sum3 = _dmpysp(sum3, regS1);
      sum5 = _dmpysp(sum5, regS1);
      sum7 = _dmpysp(sum7, regS1);
      sum1 = _daddsp(sum1, _dmpysp(sum8, regS2));
      sum3 = _daddsp(sum3, _dmpysp(suma, regS2));
      sum5 = _daddsp(sum5, _dmpysp(sumc, regS2));
      sum7 = _daddsp(sum7, _dmpysp(sume, regS2));
      sum1 = _daddsp(sum1, _dmpysp(sum9, regS3));
      sum3 = _daddsp(sum3, _dmpysp(sumb, regS3));
      sum5 = _daddsp(sum5, _dmpysp(sumd, regS3));
      sum7 = _daddsp(sum7, _dmpysp(sumf, regS3));

	  regS3 = _ftof2(*(pReg+3*M_KERNEL_S+2), *(pReg+3*M_KERNEL_S+2));
	  regS2 = _ftof2(*(pReg+2*M_KERNEL_S+2), *(pReg+2*M_KERNEL_S+2));
      sum8 = _dmpysp(sum8, regS2);
      suma = _dmpysp(suma, regS2);
      sumc = _dmpysp(sumc, regS2);
      sume = _dmpysp(sume, regS2);
      sum8 = _daddsp(sum8, _dmpysp(sum9, regS3));
      suma = _daddsp(suma, _dmpysp(sumb, regS3));
      sumc = _daddsp(sumc, _dmpysp(sumd, regS3));
      sume = _daddsp(sume, _dmpysp(sumf, regS3));

	  regS3 = _ftof2(*(pReg+3*M_KERNEL_S+3), *(pReg+3*M_KERNEL_S+3));
      sum9 = _dmpysp(sum9, regS3);
      sumb = _dmpysp(sumb, regS3);
      sumd = _dmpysp(sumd, regS3);
      sumf = _dmpysp(sumf, regS3);

	  ptrB = (__float2_t *) (pB-M_KERNEL_S*N_KERNEL_S);
	  ptrBH = (__float2_t *) (pBHat-M_KERNEL_S*NPARTITION_S);
      ptrC = (__float2_t *) pC;
      *ptrC++ = sum0;
      *ptrC++ = sum2;
      *ptrC++ = sum4;
      *ptrC++ = sum6;
      *ptrB++ = sum0;
      *ptrB++ = sum2;
      *ptrB++ = sum4;
      *ptrB++ = sum6;
      *ptrBH++ = sum0;
      *ptrBH++ = sum2;
      *ptrBH++ = sum4;
      *ptrBH++ = sum6;
	  // move to next column
	  ptrC += index;
      ptrBH += ((NPARTITION_S>>1)-4);
      *ptrC++ = sum1;
      *ptrC++ = sum3;
      *ptrC++ = sum5;
      *ptrC++ = sum7;
      *ptrB++ = sum1;
      *ptrB++ = sum3;
      *ptrB++ = sum5;
      *ptrB++ = sum7;
      *ptrBH++ = sum1;
      *ptrBH++ = sum3;
      *ptrBH++ = sum5;
      *ptrBH++ = sum7;
	  // move to next column
	  ptrC += index;
      ptrBH += ((NPARTITION_S>>1)-4);
      *ptrC++ = sum8;
      *ptrC++ = suma;
      *ptrC++ = sumc;
      *ptrC++ = sume;
      *ptrB++ = sum8;
      *ptrB++ = suma;
      *ptrB++ = sumc;
      *ptrB++ = sume;
      *ptrBH++ = sum8;
      *ptrBH++ = suma;
      *ptrBH++ = sumc;
      *ptrBH++ = sume;
	  // move to next column
	  ptrC += index;
      ptrBH += ((NPARTITION_S>>1)-4);
      *ptrC++ = sum9;
      *ptrC++ = sumb;
      *ptrC++ = sumd;
      *ptrC++ = sumf;
      *ptrB++ = sum9;
      *ptrB++ = sumb;
      *ptrB++ = sumd;
      *ptrB++ = sumf;
      *ptrBH++ = sum9;
      *ptrBH++ = sumb;
      *ptrBH++ = sumd;
      *ptrBH++ = sumf;
	}
  }
  return;
} // strsmKernel()

