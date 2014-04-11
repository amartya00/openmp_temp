#ifndef _TESTUTIL_H
#define _TESTUTIL_H

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
 *  @file   testUtil.h
 *  @brief  some test utility function definitions
 *
*/

/** @defgroup testPackage test package  */

/** @ingroup testPackage */
/* @{ */

#include "defC66.h"

/**
 *  @brief     find maximum absolute difference between two single precision matrices
 *
 *  @param[in] m       number of rows to compare
 *  @param[in] n       number of cols to compare
 *  @param[in] a       pointer to first matrix
 *  @param[in] lda     first dimension of matrix a
 *  @param[in] b       pointer to second matrix
 *  @param[in] ldb     first dimension of matrix b
 *
 *  @return            returns maximum absolute error
 */
double compareSMatrices( int m, int n, real *a, int lda, real *b, int ldb );

/**
 *  @brief     find maximum absolute difference between two double precision matrices
 *
 *  @param[in] m       number of rows to compare
 *  @param[in] n       number of cols to compare
 *  @param[in] a       pointer to first matrix
 *  @param[in] lda     first dimension of matrix a
 *  @param[in] b       pointer to second matrix
 *  @param[in] ldb     first dimension of matrix b
 *
 *  @return            returns maximum absolute error
 */
double compareDMatrices( int m, int n, double *a, int lda, double *b, int ldb );

/**
 *  @brief     find maximum absolute difference between two single precision complex matrices
 *
 *  @param[in] m       number of rows to compare
 *  @param[in] n       number of cols to compare
 *  @param[in] a       pointer to first matrix
 *  @param[in] lda     first dimension of matrix a
 *  @param[in] b       pointer to second matrix
 *  @param[in] ldb     first dimension of matrix b
 *
 *  @return            returns maximum absolute error
 */
double compareCMatrices( int m, int n, complex *a, int lda, complex *b, int ldb );

/**
 *  @brief     find maximum absolute difference between two double precision complex matrices
 *
 *  @param[in] m       number of rows to compare
 *  @param[in] n       number of cols to compare
 *  @param[in] a       pointer to first matrix
 *  @param[in] lda     first dimension of matrix a
 *  @param[in] b       pointer to second matrix
 *  @param[in] ldb     first dimension of matrix b
 *
 *  @return            returns maximum absolute error
 */
double compareZMatrices( int m, int n, doublecomplex *a, int lda, doublecomplex *b, int ldb );

/**
 *  @brief     randomly fill memory area with single precision values
 *
 *  @param[in] a       pointer to area to fill
 *  @param[in] len     number of elements to fill
 *
 */
void randomSFill(real *a, int len);

/**
 *  @brief     randomly fill memory area with double precision values
 *
 *  @param[in] a       pointer to area to fill
 *  @param[in] len     number of elements to fill
 *
 */
void randomDFill(double *a, int len);

/**
 *  @brief     randomly fill memory area with single precision complex values
 *
 *  @param[in] a       pointer to area to fill
 *  @param[in] len     number of elements to fill
 *
 */
void randomCFill(complex *a, int len);

/**
 *  @brief     randomly fill memory area with double precision complex values
 *
 *  @param[in] a       pointer to area to fill
 *  @param[in] len     number of elements to fill
 *
 */
void randomZFill(doublecomplex *a, int len);

#endif

/* @} */ /* ingroup */

/* Nothing past this point */
