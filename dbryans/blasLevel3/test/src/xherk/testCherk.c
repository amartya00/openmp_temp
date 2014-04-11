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
 *  @file   testCherk.c
 *  @brief  Test bench. This is used to test CHERK API
 *
 */

#ifdef VERIFICATION
#include "FLA_f2c.h"
extern int cherk_(char *uplo, char *trans, integer *n, integer *k,
	real *alpha, complex *a, integer *lda, real *beta, complex *c__, integer *
	ldc, ftnlen uplo_len, ftnlen trans_len);
#define FLA_F2C_INCLUDED
#endif

// include necessary single precision header files
#include "defC66.h"
#include "defCC66.h"
#include "../paramBlas3.h"
#include "../util/testUtil.h"
#include "testCherk.h"
#ifdef _OPENMP
#include <multiCore/xherk/cherkC66MC.h>
#else
#include <singleCore/xherk/cherkC66SC.h>
#endif

// define necessary single precision maps
#define dataType   complex
#define baseType   real
#define xsyrk_     cherk_
#ifdef _OPENMP
#define xsyrk      cherk
#else
#define xsyrk      cherkSC
#endif

#define testXsyrk  testCherk
#define XSYRK      "CHERK"
#ifdef VERIFICATION
#define compareMatrices compareCMatrices
#define randomFill randomCFill
#endif
#define M_KERNEL M_KERNEL_C
#define N_KERNEL N_KERNEL_C

#ifdef ALPHACOMPLEX
#undef ALPHACOMPLEX
#endif

#ifdef BETACOMPLEX
#undef BETACOMPLEX
#endif

#ifndef HERMITIAN
#define HERMITIAN
#endif

#include "../xsyrk/testXsyrk.inc"
