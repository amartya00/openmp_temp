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
 *  @file   zgemmKernel.c
 *  @brief  This file contains functions double precision complex
 *          matrix multiplication implementation of sizes
 *          1xk by kx1 producing 1x1 output. This is C66 intrinsic
 *          optimized code. There are several variations based on how the
 *          output is saved.
 *
 */


#include "c6x.h"
#include "zgemmKernel.h"

#include "stdio.h"
void zgemmKernel(const doublecomplex *pA, const doublecomplex *pB, doublecomplex *pC, const doublecomplex a, const int k, const int stepC)
{
  double * restrict ptrA = (double *) pA;
  double * restrict ptrB = (double *) pB;
  double * restrict ptrC = (double *) pC;
  double sum00r, sum00i;
  int index;
  int kEven = k&0xFFFE;

  sum00r = 0.0;
  sum00i = 0.0;

  if(k>4) // The loop is safe for k > 4
  {
#pragma UNROLL(2)
    for(index = 0; index<kEven; index++)
    { // loop over k;
  	  // each iteration performs rank one update of 1x1 by 1x1
	  // matrices of A and B respectively; result is
	  // accumulated over 1x1 matrix
	  double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;

    }
    if(k&1) // odd k; one left to do
    {
	  double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;
    }
  }
  else
  {
    if(k>0)
    { double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;
    }
    if(k>1)
    { double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;
    }
    if(k>2)
    { double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;
    }
    if(k>3)
    { double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;
    }

  }

  {  // final saving
	double ar, ai;
	ar = a.r;
	ai = a.i;

	*ptrC++ = (ar * sum00r - ai * sum00i) + (*ptrC);
	*ptrC   = (ar * sum00i + ai * sum00r) + (*ptrC);
  }

  return;
} // zgemmKernel()

void zgemmKernelFlexSave(const doublecomplex *pA, const doublecomplex *pB, doublecomplex *pC, const doublecomplex a, const int k, const int stepC, const int saveLoc, const int flagisN)
{
	  double * restrict ptrA = (double *) pA;
	  double * restrict ptrB = (double *) pB;
	  double * restrict ptrC = (double *) pC;
	  double sum00r, sum00i;
	  int index;
	  int kEven = k&0xFFFE;

	  sum00r = 0.0;
	  sum00i = 0.0;

	  if(k>4) // The loop is safe for k > 4
	  {
	#pragma UNROLL(2)
	    for(index = 0; index<kEven; index++)
	    { // loop over k;
	  	  // each iteration performs rank one update of 1x1 by 1x1
		  // matrices of A and B respectively; result is
		  // accumulated over 1x1 matrix
		  double a0r, a0i;
		  double b0r, b0i;

		  a0r = *ptrA++;
		  a0i = *ptrA++;

		  b0r = *ptrB++;
		  b0i = *ptrB++;

		  sum00r += a0r*b0r;
		  sum00r -= a0i*b0i;
		  sum00i += a0r*b0i;
		  sum00i += a0i*b0r;

	    }
	    if(k&1) // odd k; one left to do
	    {
		  double a0r, a0i;
		  double b0r, b0i;

		  a0r = *ptrA++;
		  a0i = *ptrA++;

		  b0r = *ptrB++;
		  b0i = *ptrB++;

		  sum00r += a0r*b0r;
		  sum00r -= a0i*b0i;
		  sum00i += a0r*b0i;
		  sum00i += a0i*b0r;
	    }
	  }
	  else
	  {
	    if(k>0)
	    { double a0r, a0i;
		  double b0r, b0i;

		  a0r = *ptrA++;
		  a0i = *ptrA++;

		  b0r = *ptrB++;
		  b0i = *ptrB++;

		  sum00r += a0r*b0r;
		  sum00r -= a0i*b0i;
		  sum00i += a0r*b0i;
		  sum00i += a0i*b0r;
	    }
	    if(k>1)
	    { double a0r, a0i;
		  double b0r, b0i;

		  a0r = *ptrA++;
		  a0i = *ptrA++;

		  b0r = *ptrB++;
		  b0i = *ptrB++;

		  sum00r += a0r*b0r;
		  sum00r -= a0i*b0i;
		  sum00i += a0r*b0i;
		  sum00i += a0i*b0r;
	    }
	    if(k>2)
	    { double a0r, a0i;
		  double b0r, b0i;

		  a0r = *ptrA++;
		  a0i = *ptrA++;

		  b0r = *ptrB++;
		  b0i = *ptrB++;

		  sum00r += a0r*b0r;
		  sum00r -= a0i*b0i;
		  sum00i += a0r*b0i;
		  sum00i += a0i*b0r;
	    }
	    if(k>3)
	    { double a0r, a0i;
		  double b0r, b0i;

		  a0r = *ptrA++;
		  a0i = *ptrA++;

		  b0r = *ptrB++;
		  b0i = *ptrB++;

		  sum00r += a0r*b0r;
		  sum00r -= a0i*b0i;
		  sum00i += a0r*b0i;
		  sum00i += a0i*b0r;
	    }

	  }

	  if(flagisN >= 0){  // final saving Normal and transpose is the same)
			double ar, ai;
			ar = a.r;
			ai = a.i;

			*ptrC++ = (ar * sum00r - ai * sum00i) + (*ptrC);
			*ptrC   = (ar * sum00i + ai * sum00r) + (*ptrC);
	  }
	  else // conjugate form
	  {
			double ar, ai;
			ar = a.r;
			ai = -a.i;

			*ptrC++ = (ar * sum00r - ai * sum00i) + (*ptrC);
			*ptrC   = -(ar * sum00i + ai * sum00r) + (*ptrC);
	  }

} // zgemmKernelNew()


void zgemmKernelNoReadFlexSave(const doublecomplex *pA, const doublecomplex *pB, doublecomplex *pC, const doublecomplex a, const int k, const int stepC, const int saveLoc, const int flagisN)
{
  double * restrict ptrA = (double *) pA;
  double * restrict ptrB = (double *) pB;
  double * restrict ptrC = (double *) pC;
  double sum00r, sum00i;
  int index;
  int kEven = k&0xFFFE;

  sum00r = 0.0;
  sum00i = 0.0;

  if(k>4) // The loop is safe for k > 4
  {
#pragma UNROLL(2)
    for(index = 0; index<kEven; index++)
    { // loop over k;
  	  // each iteration performs rank one update of 1x1 by 1x1
	  // matrices of A and B respectively; result is
	  // accumulated over 1x1 matrix
	  double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;

    }
    if(k&1) // odd k; one left to do
    {
	  double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;
    }
  }
  else
  {
    if(k>0)
    { double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;
    }
    if(k>1)
    { double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;
    }
    if(k>2)
    { double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;
    }
    if(k>3)
    { double a0r, a0i;
	  double b0r, b0i;

	  a0r = *ptrA++;
	  a0i = *ptrA++;

	  b0r = *ptrB++;
	  b0i = *ptrB++;

	  sum00r += a0r*b0r;
	  sum00r -= a0i*b0i;
	  sum00i += a0r*b0i;
	  sum00i += a0i*b0r;
    }

  }

	  if(flagisN >= 0){  // final saving Normal and transpose is the same)
			double ar, ai;
			ar = a.r;
			ai = a.i;

			*ptrC++ = (ar * sum00r - ai * sum00i);
			*ptrC   = (ar * sum00i + ai * sum00r);
	  }
	  else // conjugate form
	  {
			double ar, ai;
			ar = a.r;
			ai = -a.i;

			*ptrC++ = (ar * sum00r - ai * sum00i);
			*ptrC   = -(ar * sum00i + ai * sum00r);
	  }

	  return;
} // zgemmKernelNoRead()

