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
 *  @file   ssyr2kC66SC.c
 *  @brief  This file contains basic ssyr2k implementation
 *
 */

#include "singleCore/xsyr2k/ssyr2kC66SC.h"

#include "defSC66.h"
#include "../kernels/sgemmKernel.h"
#include "../dataMove/dataMoveSgemm.h"

#define dataType real
#define baseType real
#define xsyrkInternal          ssyr2kInternal
#define xsyrkKernelFlexSave    sgemmKernelFlexSave
#define XSYRK          "SSYR2K"

#define dataMoveATsyrk dataMoveATSgemm
#define dataMoveAsyrk  dataMoveASgemm
#define dataMoveBTsyrk dataMoveBTSgemm
#define dataMoveBsyrk  dataMoveBSgemm

#define M_KERNEL M_KERNEL_S
#define N_KERNEL N_KERNEL_S

#define KPARTITION KPARTITION_S
#define MPARTITION MPARTITION_S
#define NPARTITION NPARTITION_S
#define NUMAPANELS NUMAPANELS_S
#define NUMBPANELS NUMBPANELS_S
#define BANKOFFSET 2

#ifdef COMPLEX
#undef COMPLEX
#endif

#ifdef HERMITIAN
#undef HERMITIAN
#endif

#include "../xsyrk/xsyrkInternalC66SC.inc"

void ssyr2kSC(char uplo, char trans,
		      int n, int k,
		      real alpha, real *a, int lda,
              real *b, int ldb,
              real beta, real *c, int ldc)
{
  // real case; 'C' and 'T' has same meaning
  if((trans=='c') || (trans=='C')) trans = 'T';
  ssyr2kInternal(uplo, trans, n, k, alpha, a,
		  lda, b, ldb, beta, c, ldc);
  ssyr2kInternal(uplo, trans, n, k, alpha, b,
		  ldb, a, lda, (real) 1.0, c, ldc);
}

