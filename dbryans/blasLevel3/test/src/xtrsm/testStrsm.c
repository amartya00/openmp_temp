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
 *  @file   testStrsm.c
 *  @brief  Test bench. This is used to test STRSM API
 *
 */

#ifdef VERIFICATION
#include "FLA_f2c.h"
extern int strsm_(char *side, char *uplo, char *transa, char *diag,
		integer *m, integer *n, real *alpha, real *a, integer *lda, real *b,
		integer *ldb, ftnlen side_len, ftnlen uplo_len, ftnlen transa_len,
		ftnlen diag_len);
#define FLA_F2C_INCLUDED
#endif

// include necessary single precision header files
#include "defC66.h"
#include "defSC66.h"
#include "../paramBlas3.h"
#include "../util/testUtil.h"
#include "testStrsm.h"
#ifdef _OPENMP
#include <multiCore/xtrsm/strsmC66MC.h>
#else
#include <singleCore/xtrsm/strsmC66SC.h>
#endif

// define necessary single precision maps
#define dataType   real
#define baseType   real
#define xtrsm_     strsm_
#ifdef _OPENMP
#define xtrsm      strsm
#else
#define xtrsm      strsmSC
#endif

#define testXtrsm  testStrsm
#define XTRSM      "STRSM"
#ifdef VERIFICATION
#define compareMatrices compareSMatrices
#define randomFill randomSFill
#endif
#define M_KERNEL M_KERNEL_S
#define N_KERNEL N_KERNEL_S

#ifdef COMPLEX
#undef COMPLEX
#endif

#include "testXtrsm.inc"
