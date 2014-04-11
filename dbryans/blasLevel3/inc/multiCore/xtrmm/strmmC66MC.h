#ifndef _STRMM_C66MC_H
#define _STRMM_C66MC_H

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
 *  @file   strmmC66MC.h
 *  @brief  interface to single precision triangular
 *          matrix multiplication operating on multi core C66
 *
*/

/** @defgroup trmm trmm  */

/** @ingroup trmm */
/* @{ */

#include "defC66.h"

/** 
 * @brief strmm performs one of the triangular matrix-matrix multiplications for single precision real numbers:
 *
 *        C := alpha * op( A) * B,
 *
 *         or
 *
 *        C := alpha * B * op( A)
 *
 *       alpha is a scalar. B is an m by n matrix, 
 *       A is a unit, or non-unit, upper or lower
 *       triangular matrix.
 * 
 *  @param[in]  side      specifies whether A appears on left or right. \n
 *                        side = 'L' or 'l', C := alpha * op( A) * B. \n
 *                        side = 'R' or 'r', C := alpha * B * op( A). \n
 *  @param[in]  uplo      specifies whether upper or lower traingular part of A
 *                        is referenced. \n
 *                        uplo = 'U' or 'u', upper traingular part of A is referenced. \n
 *                        uplo = 'L' or 'l', lower traingular part of A is referenced. \n
 *  @param[in]  transa    specifies the form of op( A ). \n
 *                        TRANSA = 'N' or 'n', op( A ) = A. \n
 *                        TRANSA = 'T' or 't', op( A ) = A'. \n
 *                        TRANSA = 'C' or 'C', op( A ) = A'.
 *  @param[in]  diag      specifies whether A is unit traingular or not. \n
 *                        diag = 'U' or 'u', A is unit triangular. \n
 *                        diag = 'N' or 'n', A is not unit triangular. \n
 *  @param[in]  m         specifies the number of rows of B.
 *  @param[in]  n         specifies the number of colums B.
 *  @param[in]  alpha     multiplication factor on matrix product.         
 *  @param[in]  a         pointer to matrix A.
 *  @param[in]  lda       first dimension of A.
 *  @param[in,out]  b         pointer to matrix B.
 *  @param[in]  ldb       first dimension of B.
 *
 */

void strmm(char side, char uplo, char transa, char diag,
		   int m, int n,
		   real alpha, real *a, int lda,
           real *b, int ldb);

#endif // _STRMM_C66MC_H

/* @} */ /* ingroup */

/* Nothing past this point */
