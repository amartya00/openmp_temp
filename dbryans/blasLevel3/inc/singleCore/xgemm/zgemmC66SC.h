#ifndef _ZGEMM_C66SC_H
#define _ZGEMM_C66SC_H

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
 *  @file   zgemmC66SC.h
 *  @brief  interface to double precision complex generalized
 *          matrix multiplication operating on single core C66
 *
*/

/** @defgroup gemm gemm  */

/** @ingroup gemm */
/* @{ */

#include "defC66.h"

/** 
 * @brief sgemm performs one of the generalized matrix-matrix multiplications for double precision complex numbers:
 *
 *         C := alpha * op( A) * op( B) + beta * C.
 *
 *        alpha and beta are scalars. A, B and C are matrices, with
 *        op( A ) an m by k matrix, op( B ) a k by n matrix and
 *        C an m by n matrix.
 * 
 *  @param[in]  transa    specifies the form of op( A ). \n
 *                        TRANSA = 'N' or 'n', op( A ) = A. \n
 *                        TRANSA = 'T' or 't', op( A ) = A'. \n
 *                        TRANSA = 'C' or 'C', op( A ) = A'.
 *  @param[in]  transb    specifies the form of op( A ). \n
 *                        TRANSB = 'N' or 'n', op( B ) = B. \n
 *                        TRANSB = 'T' or 't', op( B ) = B'. \n
 *                        TRANSB = 'C' or 'C', op( B ) = B'.
 *  @param[in]  m         specifies the number of rows of op( A ) and of C.
 *  @param[in]  n         specifies the number of colums op( B ) and of C.
 *  @param[in]  k         specifies the number of colums in op( A ) and the 
 *                        number of rows in op( B ).
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

void zgemmSC(char transa, char transb,
		     int m, int n, int k,
		     doublecomplex alpha, doublecomplex *a, int lda,
             doublecomplex *b, int ldb,
             doublecomplex beta,  doublecomplex *c, int ldc);

#endif // _ZGEMM_C66SC_H

/* @} */ /* ingroup */

/* Nothing past this point */
