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
 *  @file   testDtrmm.c
 *  @brief  Test bench. This is used to test DTRMM API
 *
 */

#ifdef VERIFICATION
#include "FLA_f2c.h"
extern int dtrmm_(char *side, char *uplo, char *transa, char *diag,
		integer *m, integer *n, doublereal *alpha, doublereal *a, integer *
		lda, doublereal *b, integer *ldb, ftnlen side_len, ftnlen uplo_len,
		ftnlen transa_len, ftnlen diag_len);
#define FLA_F2C_INCLUDED
#endif

// include necessary single precision header files
#include "defC66.h"
#include "defDC66.h"
#include "../paramBlas3.h"
#include "../util/testUtil.h"
#include "testDtrmm.h"
#ifdef _OPENMP
#include <multiCore/xtrmm/dtrmmC66MC.h>
#else
#include <singleCore/xtrmm/dtrmmC66SC.h>
#endif

// define necessary single precision maps
#define dataType   double
#define baseType   double
#define xtrmm_     dtrmm_
#ifdef _OPENMP
#define xtrmm      dtrmm
#else
#define xtrmm      dtrmmSC
#endif

#define testXtrmm  testDtrmm
#define XTRMM      "DTRMM"
#ifdef VERIFICATION
#define compareMatrices compareDMatrices
#define randomFill randomDFill
#endif
#define M_KERNEL M_KERNEL_D
#define N_KERNEL N_KERNEL_D

#ifdef COMPLEX
#undef COMPLEX
#endif

#include "testXtrmm.inc"

