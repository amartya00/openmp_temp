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
 *  @file   testZsymm.c
 *  @brief  Test bench. This is used to test ZSYMM API
 *
 */

#ifdef VERIFICATION
#include "FLA_f2c.h"
extern int zsymm_(char *side, char *uplo, integer *m, integer *n,
	doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, doublecomplex *beta,
	doublecomplex *c__, integer *ldc, ftnlen side_len, ftnlen uplo_len);
#define FLA_F2C_INCLUDED
#endif

// include necessary single precision header files
#include "defC66.h"
#include "defZC66.h"
#include "../paramBlas3.h"
#include "../util/testUtil.h"
#include "testZsymm.h"
#ifdef _OPENMP
#include <multiCore/xsymm/zsymmC66MC.h>
#else
#include <singleCore/xsymm/zsymmC66SC.h>
#endif

// define necessary single precision maps
#define dataType   doublecomplex
#define baseType   double
#define xsymm_     zsymm_
#ifdef _OPENMP
#define xsymm      zsymm
#else
#define xsymm      zsymmSC
#endif

#define testXsymm  testZsymm
#define XSYMM      "ZSYMM"
#ifdef VERIFICATION
#define compareMatrices compareZMatrices
#define randomFill randomZFill
#endif
#define M_KERNEL M_KERNEL_Z
#define N_KERNEL N_KERNEL_Z

#ifndef COMPLEX
#define COMPLEX
#endif

#ifdef HERMITIAN
#undef HERMITIAN
#endif

#include "testXsymm.inc"

