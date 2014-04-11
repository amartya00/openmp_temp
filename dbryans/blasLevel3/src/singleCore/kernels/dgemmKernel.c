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
 *  @file   dgemmKernel.c
 *  @brief  This file contains functions double precision
 *          matrix multiplication implementation of sizes
 *          4xk by kx4 producing 4x4 output. This is C66 intrinsic
 *          optimized code. There are several variations based on how the
 *          output is saved.
 *
 */

#include "c6x.h"
#include "dgemmKernel.h"

void dgemmKernel(const double *pA, const double *pB, double *pC, const double a, const int k, const int stepC)
{
  double sum00, sum01, sum02, sum03;
  double sum10, sum11, sum12, sum13;
  double sum20, sum21, sum22, sum23;
  double sum30, sum31, sum32, sum33;
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

  for(index = 0; index < k; index++)
  {  // loop over k;
	 // each iteration performs rank one update of 4x1 by 1x4
	 // matrices of A and B respectively; result is
     // accumulated over 4x4 matrix
     double a0, a1, a2, a3;
     double b0, b1, b2, b3;

     a0 = *pA++;
     a1 = *pA++;
     a2 = *pA++;
     a3 = *pA++;
     b0 = *pB++;
     b1 = *pB++;
     b2 = *pB++;
     b3 = *pB++;

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

  // update and save c[0,0]
  *pC++ = a * sum00 + (*pC);
  // update and save c[1,0]
  *pC++ = a * sum10 + (*pC);
  // update and save c[2,0]
  *pC++ = a * sum20 + (*pC);
  // update and save c[3,0]
  *pC++ = a * sum30 + (*pC);

  // move to next column
  pC += (stepC-4);

  // update and save c[0,1]
  *pC++ = a * sum01 + (*pC);
  // update and save c[1,1]
  *pC++ = a * sum11 + (*pC);
  // update and save c[2,1]
  *pC++ = a * sum21 + (*pC);
  // update and save c[3,1]
  *pC++ = a * sum31 + (*pC);

  // move to next column
  pC += (stepC-4);

  // update and save c[0,2]
  *pC++ = a * sum02 + (*pC);
  // update and save c[1,2]
  *pC++ = a * sum12 + (*pC);
  // update and save c[2,2]
  *pC++ = a * sum22 + (*pC);
  // update and save c[3,2]
  *pC++ = a * sum32 + (*pC);

  // move to next column
  pC += (stepC-4);

  // update and save c[0,3]
  *pC++ = a * sum03 + (*pC);
  // update and save c[1,3]
  *pC++ = a * sum13 + (*pC);
  // update and save c[2,3]
  *pC++ = a * sum23 + (*pC);
  // update and save c[3,3]
  *pC++ = a * sum33 + (*pC);

  return;
} // dgemmKernel()

void dgemmKernelFlexSave(const double *pA, const double *pB, double *pC, const double a, const int k, const int stepC, const int saveLoc, const int flagisN)
{
  double sum00, sum01, sum02, sum03;
  double sum10, sum11, sum12, sum13;
  double sum20, sum21, sum22, sum23;
  double sum30, sum31, sum32, sum33;
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

  for(index = 0; index < k; index++)
  {  // loop over k;
	 // each iteration performs rank one update of 4x1 by 1x4
	 // matrices of A and B respectively; result is
     // accumulated over 4x4 matrix
     double a0, a1, a2, a3;
     double b0, b1, b2, b3;
     a0 = *pA++;
     a1 = *pA++;
     a2 = *pA++;
     a3 = *pA++;
     b0 = *pB++;
     b1 = *pB++;
     b2 = *pB++;
     b3 = *pB++;

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

  if(flagisN>0) // saving in normal form
  {
	switch(saveLoc)
	{
	  case -3:
	  case -2:
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
		// update and save c[0,0]
	    if(saveLoc > -1 ) *pC = a * sum00 + (*pC);
	    pC++;
		// update and save c[1,0]
	    if(saveLoc > -2 ) *pC = a * sum10 + (*pC);
	    pC++;
		// update and save c[2,0]
	    if(saveLoc > -3 ) *pC = a * sum20 + (*pC);
	    pC++;
		// update and save c[3,0]
	    if(saveLoc > -4 ) *pC = a * sum30 + (*pC);
	    pC++;

	    // move to next column
	    pC += (stepC-4);

		// update and save c[0,1]
	    if(saveLoc >  0 ) *pC = a * sum01 + (*pC);
	    pC++;
		// update and save c[1,1]
	    if(saveLoc > -1 ) *pC = a * sum11 + (*pC);
	    pC++;
		// update and save c[2,1]
	    if(saveLoc > -2 ) *pC = a * sum21 + (*pC);
	    pC++;
		// update and save c[3,1]
	    if(saveLoc > -3 ) *pC = a * sum31 + (*pC);
	    pC++;

	    // move to next column
	    pC += (stepC-4);

		// update and save c[0,2]
	    if(saveLoc >  1 ) *pC = a * sum02 + (*pC);
	    pC++;
		// update and save c[1,2]
	    if(saveLoc >  0 ) *pC = a * sum12 + (*pC);
	    pC++;
		// update and save c[2,2]
	    if(saveLoc > -1 ) *pC = a * sum22 + (*pC);
	    pC++;
		// update and save c[3,2]
	    if(saveLoc > -2 ) *pC = a * sum32 + (*pC);
	    pC++;

	    // move to next column
	    pC += (stepC-4);

		// update and save c[0,3]
	    if(saveLoc >  2 ) *pC = a * sum03 + (*pC);
	    pC++;
		// update and save c[1,3]
	    if(saveLoc >  1 ) *pC = a * sum13 + (*pC);
	    pC++;
		// update and save c[2,3]
	    if(saveLoc >  0 ) *pC = a * sum23 + (*pC);
	    pC++;
		// update and save c[3,3]
	    if(saveLoc >  -1 ) *pC = a * sum33 + (*pC);
		break;

	  default:
	    // update and save c[0,0]
	    *pC++ = a * sum00 + (*pC);
  	    // update and save c[1,0]
	    *pC++ = a * sum10 + (*pC);
	    // update and save c[2,0]
	    *pC++ = a * sum20 + (*pC);
	    // update and save c[3,0]
	    *pC++ = a * sum30 + (*pC);

	    // move to next column
	    pC += (stepC-4);

	    // update and save c[0,1]
	    *pC++ = a * sum01 + (*pC);
	    // update and save c[1,1]
	    *pC++ = a * sum11 + (*pC);
	    // update and save c[2,1]
	    *pC++ = a * sum21 + (*pC);
	    // update and save c[3,1]
	    *pC++ = a * sum31 + (*pC);

	    // move to next column
	    pC += (stepC-4);

	    // update and save c[0,2]
	    *pC++ = a * sum02 + (*pC);
	    // update and save c[1,2]
	    *pC++ = a * sum12 + (*pC);
	    // update and save c[2,2]
	    *pC++ = a * sum22 + (*pC);
	    // update and save c[3,2]
	    *pC++ = a * sum32 + (*pC);

	    // move to next column
	    pC += (stepC-4);

	    // update and save c[0,3]
	    *pC++ = a * sum03 + (*pC);
	    // update and save c[1,3]
	    *pC++ = a * sum13 + (*pC);
	    // update and save c[2,3]
	    *pC++ = a * sum23 + (*pC);
	    // update and save c[3,3]
	    *pC++ = a * sum33 + (*pC);
	}
  }
  else // saving in transpose form
  {
	switch(saveLoc)
	{
	  case -3:
	  case -2:
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
		// update and save c[0,0]
	    if(saveLoc > -1 ) *pC = a * sum00 + (*pC);
	    pC++;
		// update and save c[0,1]
	    if(saveLoc > 0 ) *pC = a * sum01 + (*pC);
	    pC++;
		// update and save c[0,2]
	    if(saveLoc > 1 ) *pC = a * sum02 + (*pC);
	    pC++;
		// update and save c[0,3]
	    if(saveLoc > 2 ) *pC = a * sum03 + (*pC);
	    pC++;

	    // move to next column
	    pC += (stepC-4);

	    // update and save c[1,0]
 	    if(saveLoc > -2 ) *pC = a * sum10 + (*pC);
	    pC++;
		// update and save c[1,1]
	    if(saveLoc > -1 ) *pC = a * sum11 + (*pC);
	    pC++;
		// update and save c[1,2]
	    if(saveLoc > 0 ) *pC = a * sum12 + (*pC);
	    pC++;
		// update and save c[1,3]
	    if(saveLoc > 1 ) *pC = a * sum13 + (*pC);
	    pC++;

	    // move to next column
	    pC += (stepC-4);

		// update and save c[2,0]
	    if(saveLoc >  -3 ) *pC = a * sum20 + (*pC);
	    pC++;
		// update and save c[2,1]
	    if(saveLoc >  -2 ) *pC = a * sum21 + (*pC);
	    pC++;
		// update and save c[2,2]
	    if(saveLoc > -1 ) *pC = a * sum22 + (*pC);
	    pC++;
		// update and save c[2,3]
	    if(saveLoc > 0 ) *pC = a * sum23 + (*pC);
	    pC++;

	    // move to next column
	    pC += (stepC-4);

		// update and save c[3,0]
	    if(saveLoc >  -4 ) *pC = a * sum30 + (*pC);
	    pC++;
		// update and save c[3,1]
	    if(saveLoc >  -3 ) *pC = a * sum31 + (*pC);
	    pC++;
		// update and save c[3,2]
	    if(saveLoc >  -2 ) *pC = a * sum32 + (*pC);
	    pC++;
		// update and save c[3,3]
	    if(saveLoc >  -1 ) *pC = a * sum33 + (*pC);
		break;

	  default:
	    // update and save c[0,0]
	    *pC++ = a * sum00 + (*pC);
  	    // update and save c[0,1]
	    *pC++ = a * sum01 + (*pC);
	    // update and save c[0,2]
	    *pC++ = a * sum02 + (*pC);
	    // update and save c[0,3]
	    *pC++ = a * sum03 + (*pC);

	    // move to next column
	    pC += (stepC-4);
	    // update and save c[1,0]
	    *pC++ = a * sum10 + (*pC);
	    // update and save c[1,1]
	    *pC++ = a * sum11 + (*pC);
	    // update and save c[1,2]
	    *pC++ = a * sum12 + (*pC);
	    // update and save c[1,3]
	    *pC++ = a * sum13 + (*pC);

	    // move to next column
	    pC += (stepC-4);
	    // update and save c[2,0]
	    *pC++ = a * sum20 + (*pC);
	    // update and save c[2,1]
	    *pC++ = a * sum21 + (*pC);
	    // update and save c[2,2]
	    *pC++ = a * sum22 + (*pC);
	    // update and save c[2,3]
	    *pC++ = a * sum23 + (*pC);

	    // move to next column
	    pC += (stepC-4);
	    // update and save c[3,0]
	    *pC++ = a * sum30 + (*pC);
	    // update and save c[3,1]
	    *pC++ = a * sum31 + (*pC);
	    // update and save c[3,2]
	    *pC++ = a * sum32 + (*pC);
	    // update and save c[3,3]
	    *pC++ = a * sum33 + (*pC);
	}
  }

	  return;
} // dgemmKernelFlexSave()


void dgemmKernelNoReadFlexSave(const double *pA, const double *pB, double *pC, const double a, const int k, const int stepC, const int saveLoc, const int flagisN)
{
  double sum00, sum01, sum02, sum03;
  double sum10, sum11, sum12, sum13;
  double sum20, sum21, sum22, sum23;
  double sum30, sum31, sum32, sum33;
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

  for(index = 0; index < k; index++)
  {  // loop over k;
	 // each iteration performs rank one update of 4x1 by 1x4
	 // matrices of A and B respectively; result is
     // accumulated over 4x4 matrix
     double a0, a1, a2, a3;
     double b0, b1, b2, b3;
     a0 = *pA++;
     a1 = *pA++;
     a2 = *pA++;
     a3 = *pA++;
     b0 = *pB++;
     b1 = *pB++;
     b2 = *pB++;
     b3 = *pB++;

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
  if(flagisN>0) // saving in normal form
  {
	switch(saveLoc)
	{
	  case -3:
	  case -2:
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
		// save c[0,0]
	    if(saveLoc > -1 ) *pC = a * sum00;
	    pC++;
		// save c[1,0]
	    if(saveLoc > -2 ) *pC = a * sum10;
	    pC++;
		// save c[2,0]
	    if(saveLoc > -3 ) *pC = a * sum20;
	    pC++;
		// save c[3,0]
	    if(saveLoc > -4 ) *pC = a * sum30;
	    pC++;

	    // move to next column
	    pC += (stepC-4);
		// save c[0,1]
	    if(saveLoc >  0 ) *pC = a * sum01;
	    pC++;
		// save c[1,1]
	    if(saveLoc > -1 ) *pC = a * sum11;
	    pC++;
		// save c[2,1]
	    if(saveLoc > -2 ) *pC = a * sum21;
	    pC++;
		// save c[3,1]
	    if(saveLoc > -3 ) *pC = a * sum31;
	    pC++;

	    // move to next column
	    pC += (stepC-4);
		// save c[0,2]
	    if(saveLoc >  1 ) *pC = a * sum02;
	    pC++;
		// save c[1,2]
	    if(saveLoc >  0 ) *pC = a * sum12;
	    pC++;
		// save c[2,2]
	    if(saveLoc > -1 ) *pC = a * sum22;
	    pC++;
		// save c[3,2]
	    if(saveLoc > -2 ) *pC = a * sum32;
	    pC++;

	    // move to next column
	    pC += (stepC-4);
		// save c[0,3]
	    if(saveLoc >  2 ) *pC = a * sum03;
	    pC++;
		// save c[1,3]
	    if(saveLoc >  1 ) *pC = a * sum13;
	    pC++;
		// save c[2,3]
	    if(saveLoc >  0 ) *pC = a * sum23;
	    pC++;
		// save c[3,3]
	    if(saveLoc >  -1 ) *pC = a * sum33;
		break;

	  default:
	    // save c[0,0]
	    *pC++ = a * sum00;
  	    // save c[1,0]
	    *pC++ = a * sum10;
	    // save c[2,0]
	    *pC++ = a * sum20;
	    // save c[3,0]
	    *pC++ = a * sum30;

	    // move to next column
	    pC += (stepC-4);

	    // save c[0,1]
	    *pC++ = a * sum01;
	    // save c[1,1]
	    *pC++ = a * sum11;
	    // save c[2,1]
	    *pC++ = a * sum21;
	    // save c[3,1]
	    *pC++ = a * sum31;

	    // move to next column
	    pC += (stepC-4);

	    // save c[0,2]
	    *pC++ = a * sum02;
	    // save c[1,2]
	    *pC++ = a * sum12;
	    // save c[2,2]
	    *pC++ = a * sum22;
	    // save c[3,2]
	    *pC++ = a * sum32;

	    // move to next column
	    pC += (stepC-4);

	    // save c[0,3]
	    *pC++ = a * sum03;
	    // save c[1,3]
	    *pC++ = a * sum13;
	    // save c[2,3]
	    *pC++ = a * sum23;
	    // save c[3,3]
	    *pC++ = a * sum33;
	}
  }
  else // saving in transpose form
  {
	switch(saveLoc)
	{
	  case -3:
	  case -2:
	  case -1:
	  case 0:
	  case 1:
	  case 2:
	  case 3:
	    // save c[0,0]
	    if(saveLoc > -1 ) *pC = a * sum00;
	    pC++;
		// save c[0,1]
	    if(saveLoc > -2 ) *pC = a * sum01;
	    pC++;
	    // save c[0,2]
	    if(saveLoc > -3 ) *pC = a * sum02;
	    pC++;
		// save c[0,3]
	    if(saveLoc > -4 ) *pC = a * sum03;
	    pC++;

	    // move to next column
		pC += (stepC-4);

	    // save c[1,0]
 	    if(saveLoc >  0 ) *pC = a * sum10;
	    pC++;
		// save c[1,1]
	    if(saveLoc > -1 ) *pC = a * sum11;
	    pC++;
		// save c[1,2]
	    if(saveLoc > -2 ) *pC = a * sum12;
	    pC++;
		// save c[1,3]
	    if(saveLoc > -3 ) *pC = a * sum13;
	    pC++;

	    // move to next column
	    pC += (stepC-4);

		// save c[2,0]
	    if(saveLoc >  1 ) *pC = a * sum20;
	    pC++;
		// save c[2,1]
	    if(saveLoc >  0 ) *pC = a * sum21;
	    pC++;
		// save c[2,2]
	    if(saveLoc > -1 ) *pC = a * sum22;
	    pC++;
		// save c[2,3]
	    if(saveLoc > -2 ) *pC = a * sum23;
	    pC++;

	    // move to next column
	    pC += (stepC-4);

		// save c[3,0]
	    if(saveLoc >  2 ) *pC = a * sum30;
	    pC++;
		// save c[3,1]
	    if(saveLoc >  1 ) *pC = a * sum31;
	    pC++;
		// save c[3,2]
	    if(saveLoc >  0 ) *pC = a * sum32;
	    pC++;
		// save c[3,3]
	    if(saveLoc >  -1 ) *pC = a * sum33;
		break;
	  default:
	    // save c[0,0]
	    *pC++ = a * sum00;
  	    // save c[0,1]
	    *pC++ = a * sum01;
	    // save c[0,2]
	    *pC++ = a * sum02;
	    // save c[0,3]
	    *pC++ = a * sum03;

	    // move to next column
	    pC += (stepC-4);
	    // save c[1,0]
	    *pC++ = a * sum10;
	    // save c[1,1]
	    *pC++ = a * sum11;
	    // save c[1,2]
	    *pC++ = a * sum12;
	    // save c[1,3]
	    *pC++ = a * sum13;

	    // move to next column
	    pC += (stepC-4);
	    // save c[2,0]
	    *pC++ = a * sum20;
	    // save c[2,1]
	    *pC++ = a * sum21;
	    // save c[2,2]
	    *pC++ = a * sum22;
	    // save c[2,3]
	    *pC++ = a * sum23;

	    // move to next column
	    pC += (stepC-4);
	    // save c[3,0]
	    *pC++ = a * sum30;
	    // save c[3,1]
	    *pC++ = a * sum31;
	    // save c[3,2]
	    *pC++ = a * sum32;
	    // save c[3,3]
	    *pC++ = a * sum33;
	}
  }

  return;
} // dgemmKernelNoReadFlexSave()

