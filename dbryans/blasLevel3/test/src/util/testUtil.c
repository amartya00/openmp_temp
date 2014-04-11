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
 *  @file   testUtil.c
 *  @brief  some utility functions used in BLAS3 test bench
 *
 */

#include "stdio.h"
#include "testUtil.h"
#include "stdlib.h"

// *************************************************************************
double compareSMatrices( int m, int n, real *a, int lda, real *b, int ldb )
{
  int i, j;//, iMax, jMax;
  double max_diff = 0.0, diff;

  for ( j=0; j<n; j++ ) {
    for ( i=0; i<m; i++ ){
      diff = fabs( (a[j*lda+i] - b[j*ldb+i]) );
      //if(diff > 0.1) printf("error: %d %d %f %f\n",i, j, a[j*lda+i], b[j*ldb+i]);
      if(diff > max_diff)
      {
        max_diff = diff;
        //iMax = i;
        //jMax = j;
      }
    }
  }

  //printf("%e %e %e %d %d\n", max_diff, b[jMax*ldb+iMax], a[jMax*ldb+iMax], iMax, jMax);
  return max_diff;
}

// *************************************************************************
double compareDMatrices( int m, int n, double *a, int lda, double *b, int ldb )
{
  int i, j;//, iMax, jMax;
  double max_diff = 0.0, diff;

  for ( j=0; j<n; j++ ) {
    for ( i=0; i<m; i++ ){
      diff = fabs( (a[j*lda+i] - b[j*ldb+i]) );
      //if(diff > 0.1) printf("error: %d %d %f %f\n",i, j, a[j*lda+i], b[j*ldb+i]);
      if(diff > max_diff)
      {
        max_diff = diff;
        //iMax = i;
        //jMax = j;
      }
    }
  }

  //printf("%e %e %e %d %d\n", max_diff, b[jMax*ldb+iMax], a[jMax*ldb+iMax], iMax, jMax);
  return max_diff;
}

// *************************************************************************
double compareCMatrices( int m, int n, complex *a, int lda, complex *b, int ldb )
{
  int i, j;//, iMax, jMax;
  double max_diff = 0.0, diff;

  for ( j=0; j<n; j++ ) {
    for ( i=0; i<m; i++ ){
      diff = fabs( (a[j*lda+i].r - b[j*ldb+i].r) );
      //if(diff > 0.1) printf("error: %d %d %f %f\n",i, j, a[j*lda+i].r, b[j*ldb+i].r);
      if(diff > max_diff)
      {
        max_diff = diff;
        //iMax = i;
        //jMax = j;
      }
      diff = fabs( (a[j*lda+i].i - b[j*ldb+i].i) );
      //if(diff > 0.1) printf("error: %d %d %f %f\n",i, j, a[j*lda+i].i, b[j*ldb+i].i);
      if(diff > max_diff)
      {
        max_diff = diff;
        //iMax = i;
        //jMax = j;
      }
    }
  }

  //printf("%e %e %e %d %d\n", max_diff, b[jMax*ldb+iMax], a[jMax*ldb+iMax], iMax, jMax);
  return max_diff;
}

// *************************************************************************
double compareZMatrices( int m, int n, doublecomplex *a, int lda, doublecomplex *b, int ldb )
{
  int i, j;//, iMax, jMax;
  double max_diff = 0.0, diff;

  for ( j=0; j<n; j++ ) {
    for ( i=0; i<m; i++ ){
      diff = fabs( (a[j*lda+i].r - b[j*ldb+i].r) );
      //if(diff > 0.1) printf("error: %d %d %f %f\n",i, j, a[j*lda+i].r, b[j*ldb+i].r);
      if(diff > max_diff)
      {
        max_diff = diff;
        //iMax = i;
        //jMax = j;
      }
      diff = fabs( (a[j*lda+i].i - b[j*ldb+i].i) );
      //if(diff > 0.1) printf("error: %d %d %f %f\n",i, j, a[j*lda+i].i, b[j*ldb+i].i);
      if(diff > max_diff)
      {
        max_diff = diff;
        //iMax = i;
        //jMax = j;
      }
    }
  }

  //printf("%e %e %e %d %d\n", max_diff, b[jMax*ldb+iMax], a[jMax*ldb+iMax], iMax, jMax);
  return max_diff;
}

// *************************************************************************
void randomSFill(real *a, int len)
{
  real recipRAND_MAX = 1.0f / ((real) RAND_MAX);
  int index;

  for(index = 0; index<len; index++)
  {
    a[index]=2.0f * ((real) rand())*((real) recipRAND_MAX) - 1.0f;
  }
}

// *************************************************************************
void randomDFill(double *a, int len)
{
  double recipRAND_MAX = 1.0 / ((double) RAND_MAX);
  int index;

  for(index = 0; index<len; index++)
  {
    a[index]=2.0 * ((double) rand())*((double) recipRAND_MAX) - 1.0;
  }
}

// *************************************************************************
void randomCFill(complex *a, int len)
{
  real recipRAND_MAX = 1.0f / ((real) RAND_MAX);
  int index;

  for(index = 0; index<len; index++)
  {
    a[index].r = 2.0f * ((real) rand())*((real) recipRAND_MAX) - 1.0f;
    a[index].i = 2.0f * ((real) rand())*((real) recipRAND_MAX) - 1.0f;
  }
}

// *************************************************************************
void randomZFill(doublecomplex *a, int len)
{
  double recipRAND_MAX = 1.0 / ((double) RAND_MAX);
  int index;

  for(index = 0; index<len; index++)
  {
    a[index].r = 2.0 * ((double) rand())*((double) recipRAND_MAX) - 1.0;
    a[index].i = 2.0 * ((double) rand())*((double) recipRAND_MAX) - 1.0;
  }
}


