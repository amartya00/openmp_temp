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
 *  @file   dtrsmKernel.c
 *  @brief  This file contains functions double precision
 *          triangular matrix inversion implementation of sizes
 *          4xk by kx4 producing 4x4 output. This is C66 intrinsic
 *          optimized code. There are several variations based on how the
 *          output is saved.
 *
 */

#include "c6x.h"
#include "dtrsmKernel.h"
#include "defDC66.h"


void dtrsmKernel(const double *pA, double *pB, double *pC, double *pBHat, const int k, const int stepC,
		const int flagisN, const int flagisL)
{
  double sum00, sum01, sum02, sum03;
  double sum10, sum11, sum12, sum13;
  double sum20, sum21, sum22, sum23;
  double sum30, sum31, sum32, sum33;
  const double * restrict pRegA;
  double * restrict pRegB, * restrict pRegBH, * restrict pRegC;
  double a00, a01, a02, a03;
  double a10, a11, a12, a13;
  double a20, a21, a22, a23;
  double a30, a31, a32, a33;
  double tempd;
  int index;

  sum00 = 0.0;
  sum01 = 0.0;
  sum02 = 0.0;
  sum03 = 0.0;
  sum10 = 0.0;
  sum11 = 0.0;
  sum12 = 0.0;
  sum13 = 0.0;
  sum20 = 0.0;
  sum21 = 0.0;
  sum22 = 0.0;
  sum23 = 0.0;
  sum30 = 0.0;
  sum31 = 0.0;
  sum32 = 0.0;
  sum33 = 0.0;

  pRegA = pA;
  pRegB = pB;
  for(index = 0; index < k; index++)
  {  // loop over k;
	 // each iteration performs rank one update of 4x1 by 1x4
	 // matrices of A and B respectively; result is
     // accumulated over 4x4 matrix
     double a0, a1, a2, a3;
     double b0, b1, b2, b3;

     a0 = *pRegA++;
     a1 = *pRegA++;
     a2 = *pRegA++;
     a3 = *pRegA++;
     b0 = *pRegB++;
     b1 = *pRegB++;
     b2 = *pRegB++;
     b3 = *pRegB++;

     // a[0]*b[0]
     sum00 += a0*b0;
     // a[0]*b[1]
     sum01 += a0*b1;
     // a[0]*b[2]
     sum02 += a0*b2;
     // a[0]*b[3]
     sum03 += a0*b3;
     // a[1]*b[0]
     sum10 += a1*b0;
     // a[1]*b[1]
     sum11 += a1*b1;
     // a[1]*b[2]
     sum12 += a1*b2;
     // a[1]*b[3]
     sum13 += a1*b3;
     // a[2]*b[0]
     sum20 += a2*b0;
     // a[2]*b[1]
     sum21 += a2*b1;
     // a[2]*b[2]
     sum22 += a2*b2;
     // a[2]*b[3]
     sum23 += a2*b3;
     // a[3]*b[0]
     sum30 += a3*b0;
     // a[3]*b[1]
     sum31 += a3*b1;
     // a[3]*b[2]
     sum32 += a3*b2;
     // a[3]*b[3]
     sum33 += a3*b3;
  }

  if(flagisN > 0)  // final saving in Normal form
  {
	if(flagisL) // lower triangular
	{
		  // read and update 4x4 matrix
		  pRegC = pC;
		  // c[0,0]
		  sum00 = (*pRegC++) -sum00;
		  // c[1,0]
		  sum10 = (*pRegC++) -sum10;
		  // c[2,0]
		  sum20 = (*pRegC++) -sum20;
		  // c[3,0]
		  sum30 = (*pRegC++) -sum30;
		  // next column
		  pRegC += (stepC-4);
		  // c[0,1]
		  sum01 = (*pRegC++) -sum01;
		  // c[1,1]
		  sum11 = (*pRegC++) -sum11;
		  // c[2,1]
		  sum21 = (*pRegC++) -sum21;
		  // c[3,1]
		  sum31 = (*pRegC++) -sum31;
		  // next column
		  pRegC += (stepC-4);
		  // c[0,2]
		  sum02 = (*pRegC++) -sum02;
		  // c[1,2]
		  sum12 = (*pRegC++) -sum12;
		  // c[2,2]
		  sum22 = (*pRegC++) -sum22;
		  // c[3,2]
		  sum32 = (*pRegC++) -sum32;
		  // next column
		  pRegC += (stepC-4);
		  // c[0,3]2
		  sum03 = (*pRegC++) -sum03;
		  // c[1,3]
		  sum13 = (*pRegC++) -sum13;
		  // c[2,3]
		  sum23 = (*pRegC++) -sum23;
		  // c[3,3]
		  sum33 = (*pRegC++) -sum33;

		  pRegA = pA+k*M_KERNEL_D;
		  // load the 4x4 lower triangular inverse matrix
		  a00 = pRegA[0];
		  a10 = pRegA[1];
		  a20 = pRegA[2];
		  a30 = pRegA[3];

		  a11 = pRegA[M_KERNEL_D+1];
		  a21 = pRegA[M_KERNEL_D+2];
		  a31 = pRegA[M_KERNEL_D+3];

		  a22 = pRegA[2*M_KERNEL_D+2];
		  a32 = pRegA[2*M_KERNEL_D+3];

		  a33 = pRegA[3*M_KERNEL_D+3];

		  // 4x4 matrix multiply followed by saving
		  pRegB = pB+k*N_KERNEL_D;
		  pRegBH = (pBHat+k);
		  pRegC = pC;

		  // update c[0,0]
		  tempd = a00*sum00;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *pRegB = tempd;
		  // update c[1,0]
		  tempd = a10*sum00+a11*sum10;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *(pRegB+N_KERNEL_D) = tempd;
		  // update c[2,0]
		  tempd = a20*sum00+a21*sum10+a22*sum20;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *(pRegB+2*N_KERNEL_D) = tempd;
		  // update c[3,0]
		  tempd = a30*sum00+a31*sum10+a32*sum20+a33*sum30;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *(pRegB+3*N_KERNEL_D) = tempd;

		  // next column
	      pRegC += (stepC-4);
	      pRegBH += (KPARTITION_D-4);
	      pRegB++;
		  // update c[0,1]
		  tempd = a00*sum01;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *pRegB = tempd;
		  // update c[1,1]
		  tempd = a10*sum01+a11*sum11;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *(pRegB+N_KERNEL_D) = tempd;
		  // update c[2,1]
		  tempd = a20*sum01+a21*sum11+a22*sum21;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *(pRegB+2*N_KERNEL_D) = tempd;
		  // update c[3,1]
		  tempd = a30*sum01+a31*sum11+a32*sum21+a33*sum31;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *(pRegB+3*N_KERNEL_D) = tempd;

		  // next column
	      pRegC += (stepC-4);
	      pRegBH += (KPARTITION_D-4);
	      pRegB++;
		  // update c[0,2]
		  tempd = a00*sum02;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *pRegB = tempd;
		  // update c[1,2]
		  tempd = a10*sum02+a11*sum12;
		  *pRegC++ = tempd;
		  *(pRegB+N_KERNEL_D) = tempd;
		  *pRegBH++ = tempd;
		  // update c[2,2]
		  tempd = a20*sum02+a21*sum12+a22*sum22;
		  *pRegC++ = tempd;
		  *(pRegB+2*N_KERNEL_D) = tempd;
		  *pRegBH++ = tempd;
		  // update c[3,2]
		  tempd = a30*sum02+a31*sum12+a32*sum22+a33*sum32;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *(pRegB+3*N_KERNEL_D) = tempd;

		  // next column
	      pRegC += (stepC-4);
	      pRegBH += (KPARTITION_D-4);
	      pRegB++;
		  // update c[0,3]
		  tempd = a00*sum03;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *pRegB = tempd;
		  // update c[1,3]
		  tempd = a10*sum03+a11*sum13;
		  *pRegC++ = tempd;
		  *(pRegB+N_KERNEL_D) = tempd;
		  *pRegBH++ = tempd;
		  // update c[2,3]
		  tempd = a20*sum03+a21*sum13+a22*sum23;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *(pRegB+2*N_KERNEL_D) = tempd;
		  // update c[3,3]
		  tempd = a30*sum03+a31*sum13+a32*sum23+a33*sum33;
		  *pRegC++ = tempd;
		  *pRegBH++ = tempd;
		  *(pRegB+3*N_KERNEL_D) = tempd;

	}
	else // upper triangular
	{

	  // read and update 4x4 matrix
	  pRegC = pC;
	  // c[0,0]
	  sum00 = (*pRegC++) -sum00;
	  // c[1,0]
	  sum10 = (*pRegC++) -sum10;
	  // c[2,0]
	  sum20 = (*pRegC++) -sum20;
	  // c[3,0]
	  sum30 = (*pRegC++) -sum30;
	  // next column
	  pRegC += (stepC-4);
	  // c[0,1]
	  sum01 = (*pRegC++) -sum01;
	  // c[1,1]
	  sum11 = (*pRegC++) -sum11;
	  // c[2,1]
	  sum21 = (*pRegC++) -sum21;
	  // c[3,1]
	  sum31 = (*pRegC++) -sum31;
	  // next column
	  pRegC += (stepC-4);
	  // c[0,2]
	  sum02 = (*pRegC++) -sum02;
	  // c[1,2]
	  sum12 = (*pRegC++) -sum12;
	  // c[2,2]
	  sum22 = (*pRegC++) -sum22;
	  // c[3,2]
	  sum32 = (*pRegC++) -sum32;
	  // next column
	  pRegC += (stepC-4);
	  // c[0,3]2
	  sum03 = (*pRegC++) -sum03;
	  // c[1,3]
	  sum13 = (*pRegC++) -sum13;
	  // c[2,3]
	  sum23 = (*pRegC++) -sum23;
	  // c[3,3]
	  sum33 = (*pRegC++) -sum33;

	  pRegA = pA-M_KERNEL_D*M_KERNEL_D;
	  // load the 4x4 upper triangular inverse matrix
	  a00 = pRegA[0];

	  a01 = pRegA[M_KERNEL_D];
	  a11 = pRegA[M_KERNEL_D+1];

	  a02 = pRegA[2*M_KERNEL_D];
	  a12 = pRegA[2*M_KERNEL_D+1];
	  a22 = pRegA[2*M_KERNEL_D+2];

	  a03 = pRegA[3*M_KERNEL_D];
	  a13 = pRegA[3*M_KERNEL_D+1];
	  a23 = pRegA[3*M_KERNEL_D+2];
	  a33 = pRegA[3*M_KERNEL_D+3];

	  // 4x4 matrix multiply followed by saving
	  pRegB = pB-M_KERNEL_D*M_KERNEL_D;
	  pRegBH = (double *) (pBHat-M_KERNEL_D);
	  pRegC = pC;

	  tempd = a00*sum00+a01*sum10+a02*sum20+a03*sum30;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,0]
	  tempd = a11*sum10+a12*sum20+a13*sum30;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_D) = tempd;
	  // update c[2,0]
	  tempd = a22*sum20+a23*sum30;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+2*N_KERNEL_D) = tempd;
	  // update c[3,0]
	  tempd = a33*sum30;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+3*N_KERNEL_D) = tempd;

	  // next column
	  pRegC += (stepC-4);
      pRegBH += (KPARTITION_D-4);
	  pRegB++;
	  // update c[0,1]
	  tempd = a00*sum01+a01*sum11+a02*sum21+a03*sum31;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,1]
	  tempd = a11*sum11+a12*sum21+a13*sum31;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_D) = tempd;
	  // update c[2,1]
	  tempd = a22*sum21+a23*sum31;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+2*N_KERNEL_D) = tempd;
	  // update c[3,1]
	  tempd = a33*sum31;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+3*N_KERNEL_D) = tempd;

	  // next column
      pRegC += (stepC-4);
      pRegBH += (KPARTITION_D-4);
      pRegB++;
	  // update c[0,2]
	  tempd = a00*sum02+a01*sum12+a02*sum22+a03*sum32;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,2]
	  tempd = a11*sum12+a12*sum22+a13*sum32;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_D) = tempd;
	  // update c[2,2]
	  tempd = a22*sum22+a23*sum32;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+2*N_KERNEL_D) = tempd;
	  // update c[3,2]
	  tempd = a33*sum32;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+3*N_KERNEL_D) = tempd;

	  // next column
      pRegC += (stepC-4);
      pRegBH += (KPARTITION_D-4);
      pRegB++;
	  // update c[0,3]
	  tempd = a00*sum03+a01*sum13+a02*sum23+a03*sum33;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB = tempd;
	  // update c[1,3]
	  tempd = a11*sum13+a12*sum23+a13*sum33;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+N_KERNEL_D) = tempd;
	  // update c[2,3]
	  tempd = a22*sum23+a23*sum33;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+2*N_KERNEL_D) = tempd;
	  // update c[3,3]
	  tempd = a33*sum33;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *(pRegB+3*N_KERNEL_D) = tempd;
	}
  }
  else   // final saving in transpose form
  {
	if(flagisL) // lower triangular
	{
	  // read and update 4x4 matrix
	  pRegC = pC;
	  // c[0,0]
	  sum00 = (*pRegC++) -sum00;
	  // c[0,1]
	  sum01 = (*pRegC++) -sum01;
	  // c[0,2]
	  sum02 = (*pRegC++) -sum02;
	  // c[0,3]
	  sum03 = (*pRegC++) -sum03;
	  // next column
	  pRegC += (stepC-4);
	  // c[1,0]
	  sum10 = (*pRegC++) -sum10;
	  // c[1,1]
	  sum11 = (*pRegC++) -sum11;
	  // c[1,2]
	  sum12 = (*pRegC++) -sum12;
	  // c[1,3]
	  sum13 = (*pRegC++) -sum13;
	  // next column
	  pRegC += (stepC-4);
	  // c[2,0]
	  sum20 = (*pRegC++) -sum20;
	  // c[2,1]
	  sum21 = (*pRegC++) -sum21;
	  // c[2,2]
	  sum22 = (*pRegC++) -sum22;
	  // c[2,3]
	  sum23 = (*pRegC++) -sum23;
	  // next column
	  pRegC += (stepC-4);
	  // c[3,0]2
	  sum30 = (*pRegC++) -sum30;
	  // c[3,1]
	  sum31 = (*pRegC++) -sum31;
	  // c[3,2]
	  sum32 = (*pRegC++) -sum32;
	  // c[3,3]
	  sum33 = (*pRegC++) -sum33;

	  pRegA = pA+k*M_KERNEL_D;
	  // load the 4x4 lower triangular inverse matrix
	  a00 = pRegA[0];
	  a10 = pRegA[1];
	  a20 = pRegA[2];
	  a30 = pRegA[3];

	  a11 = pRegA[M_KERNEL_D+1];
	  a21 = pRegA[M_KERNEL_D+2];
	  a31 = pRegA[M_KERNEL_D+3];

	  a22 = pRegA[2*M_KERNEL_D+2];
	  a32 = pRegA[2*M_KERNEL_D+3];

	  a33 = pRegA[3*M_KERNEL_D+3];

	  // 4x4 matrix multiply followed by saving
	  pRegB = pB+k*N_KERNEL_D;
	  pRegBH = (pBHat+k*NPARTITION_D);
	  pRegC = pC;

	  // update c[0,0]
	  tempd = a00*sum00;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,1]
	  tempd = a00*sum01;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,2]
	  tempd = a00*sum02;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,3]
	  tempd = a00*sum03;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

	  // next column
      pRegC += (stepC-4);
      pRegBH += (NPARTITION_D-4);
	  // update c[1,0]
	  tempd = a10*sum00+a11*sum10;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,1]
	  tempd = a10*sum01+a11*sum11;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,2]
	  tempd = a10*sum02+a11*sum12;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,3]
	  tempd = a10*sum03+a11*sum13;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

	  // next column
      pRegC += (stepC-4);
      pRegBH += (NPARTITION_D-4);
	  // update c[2,0]
	  tempd = a20*sum00+a21*sum10+a22*sum20;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[2,1]
	  tempd = a20*sum01+a21*sum11+a22*sum21;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[2,2]
	  tempd = a20*sum02+a21*sum12+a22*sum22;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[2,3]
	  tempd = a20*sum03+a21*sum13+a22*sum23;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

	  // next column
      pRegC += (stepC-4);
      pRegBH += (NPARTITION_D-4);
	  // update c[3,0]
	  tempd = a30*sum00+a31*sum10+a32*sum20+a33*sum30;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[3,1]
	  tempd = a30*sum01+a31*sum11+a32*sum21+a33*sum31;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[3,2]
	  tempd = a30*sum02+a31*sum12+a32*sum22+a33*sum32;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[3,3]
	  tempd = a30*sum03+a31*sum13+a32*sum23+a33*sum33;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	}
	else // upper triangular
	{
	  // read and update 4x4 matrix
	  pRegC = pC;
	  // c[0,0]
	  sum00 = (*pRegC++) -sum00;
	  // c[0,1]
	  sum01 = (*pRegC++) -sum01;
	  // c[0,2]
	  sum02 = (*pRegC++) -sum02;
	  // c[0,3]
	  sum03 = (*pRegC++) -sum03;

	  // next column
	  pRegC += (stepC-4);
	  // c[1,0]
	  sum10 = (*pRegC++) -sum10;
	  // c[1,1]
	  sum11 = (*pRegC++) -sum11;
	  // c[1,2]
	  sum12 = (*pRegC++) -sum12;
	  // c[1,3]
	  sum13 = (*pRegC++) -sum13;

	  // next column
	  pRegC += (stepC-4);
	  // c[2,0]
	  sum20 = (*pRegC++) -sum20;
	  // c[2,1]
	  sum21 = (*pRegC++) -sum21;
	  // c[2,2]
	  sum22 = (*pRegC++) -sum22;
	  // c[2,3]
	  sum23 = (*pRegC++) -sum23;

	  // next column
	  pRegC += (stepC-4);
	  // c[3,0]
	  sum30 = (*pRegC++) -sum30;
	  // c[3,1]
	  sum31 = (*pRegC++) -sum31;
	  // c[3,2]
	  sum32 = (*pRegC++) -sum32;
	  // c[3,3]
	  sum33 = (*pRegC++) -sum33;

	  pRegA = pA-M_KERNEL_D*M_KERNEL_D;
	  // load the 4x4 upper triangular inverse matrix
	  a00 = pRegA[0];

	  a01 = pRegA[M_KERNEL_D];
	  a11 = pRegA[M_KERNEL_D+1];

	  a02 = pRegA[2*M_KERNEL_D];
	  a12 = pRegA[2*M_KERNEL_D+1];
	  a22 = pRegA[2*M_KERNEL_D+2];

	  a03 = pRegA[3*M_KERNEL_D];
	  a13 = pRegA[3*M_KERNEL_D+1];
	  a23 = pRegA[3*M_KERNEL_D+2];
	  a33 = pRegA[3*M_KERNEL_D+3];

	  // 4x4 matrix multiply followed by saving
	  pRegB = pB-M_KERNEL_D*M_KERNEL_D;
	  pRegBH = (pBHat-M_KERNEL_D*NPARTITION_D);
	  pRegC = pC;

	  // update c[0,0]
	  tempd = a00*sum00+a01*sum10+a02*sum20+a03*sum30;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,1]
	  tempd = a00*sum01+a01*sum11+a02*sum21+a03*sum31;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,2]
	  tempd = a00*sum02+a01*sum12+a02*sum22+a03*sum32;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[0,3]
	  tempd = a00*sum03+a01*sum13+a02*sum23+a03*sum33;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

	  // next column
	  pRegC += (stepC-4);
      pRegBH += (NPARTITION_D-4);
	  // update c[1,0]
	  tempd = a11*sum10+a12*sum20+a13*sum30;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,1]
	  tempd = a11*sum11+a12*sum21+a13*sum31;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,2]
	  tempd = a11*sum12+a12*sum22+a13*sum32;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[1,3]
	  tempd = a11*sum13+a12*sum23+a13*sum33;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

	  // next column
      pRegC += (stepC-4);
      pRegBH += (NPARTITION_D-4);
      // update c[2,0]
	  tempd = a22*sum20+a23*sum30;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[2,1]
	  tempd = a22*sum21+a23*sum31;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[2,2]
	  tempd = a22*sum22+a23*sum32;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[2,3]
	  tempd = a22*sum23+a23*sum33;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;

	  // next column
      pRegC += (stepC-4);
      pRegBH += (NPARTITION_D-4);
	  // update c[3,0]
	  tempd = a33*sum30;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[3,1]
	  tempd = a33*sum31;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[3,2]
	  tempd = a33*sum32;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	  // update c[3,3]
	  tempd = a33*sum33;
	  *pRegC++ = tempd;
	  *pRegBH++ = tempd;
	  *pRegB++ = tempd;
	}
  }

  return;
} // dtrsmKernel()

