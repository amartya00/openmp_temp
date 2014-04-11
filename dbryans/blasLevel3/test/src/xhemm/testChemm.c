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
 *  @file   testChemm.c
 *  @brief  Test bench. This is used to test CHEMM API
 *
 */

#ifdef VERIFICATION
#include "FLA_f2c.h"
extern int chemm_(char *side, char *uplo, integer *m, integer *n,
	complex *alpha, complex *a, integer *lda, complex *b, integer *ldb, complex *beta,
	complex *c__, integer *ldc, ftnlen side_len, ftnlen uplo_len);
#define FLA_F2C_INCLUDED
#endif

// include necessary single precision header files
#include "defC66.h"
#include "defCC66.h"
#include "../paramBlas3.h"
#include "../util/testUtil.h"
#include "testChemm.h"
#ifdef _OPENMP
#include <multiCore/xhemm/chemmC66MC.h>
#else
#include <singleCore/xhemm/chemmC66SC.h>
#endif

// define necessary single precision maps
#define dataType   complex
#define baseType   real
#define xsymm_     chemm_
#ifdef _OPENMP
#define xsymm      chemm
#else
#define xsymm      chemmSC
#endif

#define testXsymm  testChemm
#define XSYMM      "CHEMM"
#ifdef VERIFICATION
#define compareMatrices compareCMatrices
#define randomFill randomCFill
#endif
#define M_KERNEL M_KERNEL_C
#define N_KERNEL N_KERNEL_C

#ifndef COMPLEX
#define COMPLEX
#endif

#ifndef HERMITIAN
#define HERMITIAN
#endif

#include "../xsymm/testXsymm.inc"

