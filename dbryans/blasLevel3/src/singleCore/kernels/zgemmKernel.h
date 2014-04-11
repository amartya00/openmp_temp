#ifndef _ZGEMN_KERNEL_H
#define _ZGEMN_KERNEL_H

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

#include "defC66.h"

/**
 *  @file   zgemmKernel.h
 *  @brief  Contains interfaces to core double precision complex matrix multiplication.
 *
*/

/** @defgroup kernel kernel  */

/** @ingroup kernel */
/* @{ */

/**
 *  @brief Core matrix multiplication routine; performs C += a*A*B.
 *         A is 4xk matrix of doublecomplex numbers; B os kx8 matrix of doublecomplex numbers;
 *         a is scalar multiplicative constant;
 *         C is 4x8 matrix; It is actually a sub-matrix of larger marger matrix;
 *         the number of columns in original C is stepC; stepC thus indicates the number of
 *         elements to skip to write the next column. 
 *         A is assumed to be stored in column major
 *         B is assumed to be stored in row major
 *         C will be saved as column major
 *
 *  @param[in]  pA              Pointer to matrix A
 *  @param[in]  pB              Pointer to matrix B
 *  @param[out] pC              Pointer to matrix C
 *  @param[in]  k               length of matrices (A is 4xk and B is kx8)
 *  @param[in]  a               scalar muliplicative constant
 *  @param[in]  stepC           number of elements to skip to write the next column in C
 *
 */
void zgemmKernel(const doublecomplex *pA, const doublecomplex *pB, doublecomplex *pC, const doublecomplex a, const int k, const int stepC);

/**
 *  @brief Core matrix multiplication routine; performs C += a*A*B. This particular functions flexible saving
 *         of the 4 x 8 output. It can save as 8 x 4 transposed ouput. In addition, it can also save only the 
 *         lower/upper traingular part of the output.
 *         A is 4xk matrix of doublecomplex numbers; B os kx8 matrix of doublecomplex numbers;
 *         a is scalar multiplicative constant;
 *         C is 4x8 matrix; It is actually a sub-matrix of larger marger matrix;
 *         the number of columns in original C is stepC; stepC thus indicates the number of
 *         elements to skip to write the next column. 
 *         A is assumed to be stored in column major
 *         B is assumed to be stored in row major
 *         C will be saved as column major
 *
 *  @param[in]  pA              Pointer to matrix A
 *  @param[in]  pB              Pointer to matrix B
 *  @param[out] pC              Pointer to matrix C
 *  @param[in]  k               length of matrices (A is 4xk and B is kx8)
 *  @param[in]  a               scalar muliplicative constant
 *  @param[in]  stepC           number of elements to skip to write the next column in C
 *  @param[in]  saveLoc         location from where the trangular parts needs to be saved.
 *                              A value of zero indicates upper left corner. A negative value indicate
 *                              part of the matrix below the upper left corner and positive value
 *                              indicates part of the matrix right of upper left corner.
 *  @param[in]  flagisN         flag to indicate if C is saved in normal form or transposed form.
 *
 */
void zgemmKernelFlexSave(const doublecomplex *pA, const doublecomplex *pB, doublecomplex *pC, const doublecomplex a, const int k, const int stepC, const int saveLoc, const int flagisN);

/**
 *  @brief Core matrix multiplication routine; performs C = a*A*B. This particular functions flexible saving
 *         of the 4 x 8 output. It can save as 8 x 4 transposed ouput. In addition, it can also save only the 
 *         lower/upper traingular part of the output. This variation of the kernel do not read from C.
 *         A is 4xk matrix of doublecomplex numbers; B os kx8 matrix of doublecomplex numbers;
 *         a is scalar multiplicative constant;
 *         C is 4x8 matrix; It is actually a sub-matrix of larger marger matrix;
 *         the number of columns in original C is stepC; stepC thus indicates the number of
 *         elements to skip to write the next column. 
 *         A is assumed to be stored in column major
 *         B is assumed to be stored in row major
 *         C will be saved as column major
 *
 *  @param[in]  pA              Pointer to matrix A
 *  @param[in]  pB              Pointer to matrix B
 *  @param[out] pC              Pointer to matrix C
 *  @param[in]  k               length of matrices (A is 4xk and B is kx8)
 *  @param[in]  a               scalar muliplicative constant
 *  @param[in]  stepC           number of elements to skip to write the next column in C
 *  @param[in]  saveLoc         location from where the trangular parts needs to be saved.
 *                              A value of zero indicates upper left corner. A negative value indicate
 *                              part of the matrix below the upper left corner and positive value
 *                              indicates part of the matrix right of upper left corner.
 *  @param[in]  flagisN         flag to indicate if C is saved in normal form or transposed form.
 *
 */
void zgemmKernelNoReadFlexSave(const doublecomplex *pA, const doublecomplex *pB, doublecomplex *pC, const doublecomplex a, const int k, const int stepC, const int saveLoc, const int flagisN);

#endif // _ZGEMN_KERNEL_H

/* @} */ /* ingroup */

/* Nothing past this point */
