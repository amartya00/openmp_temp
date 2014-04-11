#ifndef _CHERK_C66SC_H
#define _CHERK_C66SC_H

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
 *  @file   cherkC66SC.h
 *  @brief  interface to single precision complex Hermitian rank k
 *          matrix operation operating on single core C66
 *
*/

/** @defgroup herk herk  */

/** @ingroup herk */
/* @{ */

#include "defC66.h"

/** 
 * @brief cherk performs one of the Hermitian rank k operations for single precision complex numbers:
 *
 *         C := alpha*A*conjg( A' ) + beta*C
 * or
 *         C := alpha*conjg( A' )*A + beta*C.
 *
 *        alpha and beta are scalars with both alpha and beta real numbers. A is an n by k matrix in
 *        the first case and k by n matrix in the second case. C is an n by n 
 *        Hermitian matrix.
 * 
 *  @param[in]  uplo      specifies whether upper or lower traingular part of C
 *                        is referenced. \n
 *                        uplo = 'U' or 'u', upper traingular part of C is referenced. \n
 *                        uplo = 'L' or 'l', lower traingular part of C is referenced. \n
 *  @param[in]  trans     specifies operation to be performed. \n
 *                        trans = 'N' or 'n', C := alpha*A*conjg( A' ) + beta*C. \n
 *                        trans = 'C' or 'c', C := alpha*conjg( A' )*A + beta*C.
 *  @param[in]  n         specifies the number of rows/columns of C.
 *  @param[in]  k         specifies the number of colums of A if trans = 'N' or 'n' or
 *                        the number of rows of A if  trans = 'C' or 'c'.
 *  @param[in]  alpha     multiplication factor on matrix product.         
 *  @param[in]  a         pointer to matrix A.
 *  @param[in]  lda       first dimension of A.
 *  @param[in]  beta      multiplication factor on C.
 *  @param[in,out] c      pointer to matrix C.
 *  @param[in]  ldc       first dimension of C.
 *
 */

void cherkSC(char uplo, char trans,
		     int n, int k,
		     real alpha, complex *a, int lda,
             real beta,  complex *c, int ldc);

#endif // _CHERK_C66SC_H

/* @} */ /* ingroup */

/* Nothing past this point */
