#ifndef _PARAMBLAS3_H
#define _PARAMBLAS3_H

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
 *  @file   paramBlas3.h
 *  @brief  parameter definitions for BLAS3 used in test bench
 *
*/

/** @defgroup testPackage test package  */

/** @ingroup testPackage */
/* @{ */


#include "defC66.h"
#include "stdio.h"

// @brief maximum character length
#define MAX_LINE_LEN 100

/**
 *  @brief BLAS level 3 parameter structure.
 *         Refer to standard BLAS level 3 API for porper definitions
 */
typedef struct _ParamsBlas3_ {
  /// API name
  char     blas3Api[MAX_LINE_LEN];
  /// side info (left or right)
  char     side;
  /// matrix form (upper or lower)
  char     uplo;
  /// matrix form (normal or transposed or hermitian)
  char     trans;
  /// matrix form of A (normal or transposed or hermitian)
  char     transa;
  /// matrix form of B (normal or transposed or hermitian)
  char     transb;
  /// diagonal form (diags are unity or not)
  char     diag;
  /// first dimension of first matrix; first dimension of output
  int      m;
  /// second dimension of first matrix; first dimension of second matrix
  int      k;
  /// second dimension of second matrix; second dimension of output
  int      n;
  /// multiplicative factor alpha (real part for complex values)
  double     alpha;
  /// multiplicative factor beta (real part for complex values)
  double     beta;
  /// multiplicative factor alpha (imaginary part for complex values)
  double     alpha_i;
  /// multiplicative factor beta (imaginary part for complex values)
  double     beta_i;
} ParamsBlas3_t;

/**
 *  @brief      reads parameters from file
 *
 *  @param[in]  pFid            file containing parameters
 *  @param[in]  pParam_s        Pointer to BLAS3 parameter structure
 */
void readAPIparams(FILE *pFid,  ParamsBlas3_t *pParam_s);

/**
 *  @brief      write parameters from file along with some results
 *
 *  @param[in]  pFid            file id to write to
 *  @param[in]  pParam_s        Pointer to BLAS3 parameter structure
 */
void writeAPIparams(FILE *pFid,  ParamsBlas3_t *pParam_s);

#endif

/* @} */ /* ingroup */

/* Nothing past this point */

