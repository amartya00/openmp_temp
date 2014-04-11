#ifndef _DSYMM_C66MC_H
#define _DSYMM_C66MC_H

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
 *  @file   dsymmC66MC.h
 *  @brief  interface to double precision
 *          symmetric matrix multiplication operating on multi core C66
 *
*/

/** @defgroup symm symm  */

/** @ingroup symm */
/* @{ */

#include "defC66.h"

/** 
 * @brief dsymm performs one of the symmetric matrix-matrix multiplications for double precision real numbers:
 *
 *         C := alpha * A * B + beta * C.
 *       
 *        or
 *
 *         C := alpha * B * A + beta * C.
 *
 *        alpha and beta are scalars. A is an symmetric matrix, and 
 *        B and C are m by n matrices.
 * 
 *  @param[in]  side      specifies whether A appears on left or right. \n
 *                        side = 'L' or 'l', C := alpha * A * B + beta * C.. \n
 *                        side = 'R' or 'r', C := alpha * B * A + beta * C.. \n
 *  @param[in]  uplo      specifies whether upper or lower traingular part of A
 *                        is referenced. \n
 *                        uplo = 'U' or 'u', upper traingular part of A is referenced. \n
 *                        uplo = 'L' or 'l', lower traingular part of A is referenced. \n
 *  @param[in]  m         specifies the number of rows of C.
 *  @param[in]  n         specifies the number of colums of C.
 *  @param[in]  alpha     multiplication factor on matrix product.         
 *  @param[in]  a         pointer to matrix A.
 *  @param[in]  lda       first dimension of A.
 *  @param[in]  b         pointer to matrix B.
 *  @param[in]  ldb       first dimension of B.
 *  @param[in]  beta      multiplication factor on C.
 *  @param[in,out] c      pointer to matrix C.
 *  @param[in]  ldc       first dimension of C.
 *
 */

void dsymm(char side, char uplo,
		   int m, int n,
		   double alpha, double *a, int lda,
           double *b, int ldb,
           double beta,  double *c, int ldc);

#endif // _DSYMM_C66MC_H

/* @} */ /* ingroup */

/* Nothing past this point */
