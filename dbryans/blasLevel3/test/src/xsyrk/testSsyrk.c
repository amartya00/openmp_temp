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
 *  @file   testSsyrk.c
 *  @brief  Test bench. This is used to test SSYRK API
 *
 */

/** @defgroup testPackage test package  */

/** @ingroup testPackage */
/* @{ */

#ifdef VERIFICATION
#include "FLA_f2c.h"
extern int ssyrk_(char *uplo, char *trans, integer *n, integer *k,
	real *alpha, real *a, integer *lda, real *beta, real *c__, integer *
	ldc, ftnlen uplo_len, ftnlen trans_len);
#define FLA_F2C_INCLUDED
#endif

// include necessary single precision header files
#include "defC66.h"
#include "defSC66.h"
#include "../paramBlas3.h"
#include "../util/testUtil.h"
#include "testSsyrk.h"
#ifdef _OPENMP
#include <multiCore/xsyrk/ssyrkC66MC.h>
#else
#include <singleCore/xsyrk/ssyrkC66SC.h>
#endif

// define necessary single precision maps
#define dataType   real
#define baseType   real
#define xsyrk_     ssyrk_
#ifdef _OPENMP
#define xsyrk      ssyrk
#else
#define xsyrk      ssyrkSC
#endif

#define testXsyrk  testSsyrk
#define XSYRK      "SSYRK"
#ifdef VERIFICATION
#define compareMatrices compareSMatrices
#define randomFill randomSFill
#endif
#define M_KERNEL M_KERNEL_S
#define N_KERNEL N_KERNEL_S

#ifdef ALPHACOMPLEX
#undef ALPHACOMPLEX
#endif

#ifdef BETACOMPLEX
#undef BETACOMPLEX
#endif

#ifdef HERMITIAN
#undef HERMITIAN
#endif

#include "testXsyrk.inc"

/* @} */ /* ingroup */

/* Nothing past this point */

