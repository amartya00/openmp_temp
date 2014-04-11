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
 *  @file   cherkC66SC.c
 *  @brief  This file contains basic cherk implementation
 *
 */

#include "singleCore/xherk/cherkC66SC.h"

#include "defCC66.h"
#include "../kernels/cgemmKernel.h"
#include "../dataMove/dataMoveCgemm.h"

#define dataType complex
#define baseType real
#define xsyrkInternal          cherkInternal
#define xsyrkKernelFlexSave    cgemmKernelFlexSave
#define XSYRK          "CHERK"

#define dataMoveATsyrk dataMoveAHCgemm
#define dataMoveAsyrk  dataMoveACgemm
#define dataMoveBTsyrk dataMoveBHCgemm
#define dataMoveBsyrk  dataMoveBCgemm

#define M_KERNEL M_KERNEL_C
#define N_KERNEL N_KERNEL_C

#define KPARTITION KPARTITION_C
#define MPARTITION MPARTITION_C
#define NPARTITION NPARTITION_C
#define NUMAPANELS NUMAPANELS_C
#define NUMBPANELS NUMBPANELS_C
#define BANKOFFSET 0

#ifndef COMPLEX
#define COMPLEX
#endif

#ifndef HERMITIAN
#define HERMITIAN
#endif

#include "../xsyrk/xsyrkInternalC66SC.inc"

void cherkSC(char uplo, char trans, int n, int k,
		     real alpha, complex * restrict a, int lda,
             real beta,  complex * restrict c, int ldc)
{
  complex betaC, alphaC;

  betaC.r = beta;
  betaC.i = 0.0f;

  alphaC.r = alpha;
  alphaC.i = 0.0f;
  cherkInternal(uplo, trans, n, k, alphaC, a,
		  lda, a, lda, betaC, c, ldc);
}

