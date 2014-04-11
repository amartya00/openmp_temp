#ifndef _DTRSN_KERNEL_H
#define _DTRSN_KERNEL_H

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
 *  @file   dtrsmKernel.h
 *  @brief  Contains interfaces to core triangular double precision matrix inversion
 *
*/

/** @defgroup kernel kernel  */

/** @ingroup kernel */
/* @{ */

#include "defC66.h"
/**
 *  @brief Core traingular matrix inversionroutine; First performs C += A*B either to or from
 *         followed by C=A^{-1}(4,4)*B. That is it accumulates the necessary C and finalluy performs
 *         inverse multiplications by a 4x4 matrix. The 4x4 matrix was already inverted in the data
 *         movement routine and hence. This kernel only performs the multplications. The multiplication can
 *         be pre or post depending on whether we are saving the transpose form of the output or not. Also note 
 *         that the inverted matrix can be lower or upper triangular.
 *         A is 4xk matrix of reals; B os kx4 matrix of reals;
 *         C is 4x4 matrix; It is actually a sub-matrix of larger matrix;
 *         the number of columns in original C is stepC; stepC thus indicates the number of
 *         elements to skip to write the next column. 
 *         A is assumed to be stored in column major
 *         B is assumed to be stored in row major
 *
 *  @param[in]  pA              Pointer to matrix A
 *  @param[in]  pB              Pointer to matrix B
 *  @param[in]  pBHat           Pointer to intermediate matrix B if used
 *  @param[out] pC              Pointer to matrix C
 *  @param[in]  k               length of matrices (A is 4xk and B is kx4)
 *  @param[in]  stepC           number of elements to skip to write the next column in C
 *  @param[in]  flagisN         flag to indicate if C is saved in normal form or transposed form.
 *  @param[in]  flagisL         flag to indicate if A is in upper or lower triangular format.
 *
 */

void dtrsmKernel(const double *pA, double *pB, double *pC, double *pBHat, const int k, const int stepC, const int flagisN, const int flagisL);

#endif // _DTRSN_KERNEL_H

/* @} */ /* ingroup */

/* Nothing past this point */

