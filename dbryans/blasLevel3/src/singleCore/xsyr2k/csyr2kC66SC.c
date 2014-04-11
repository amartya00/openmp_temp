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
 *  @file   csyr2kC66SC.c
 *  @brief  This file contains basic csyr2k implementation
 *
 */

#include "singleCore/xsyr2k/csyr2kC66SC.h"

#include "defCC66.h"
#include "../kernels/cgemmKernel.h"
#include "../dataMove/dataMoveCgemm.h"

#define dataType complex
#define baseType real
#define xsyrkInternal          csyr2kInternal
#define xsyrkKernelFlexSave    cgemmKernelFlexSave
#define XSYRK          "CSYR2K"

#define dataMoveATsyrk dataMoveATCgemm
#define dataMoveAsyrk  dataMoveACgemm
#define dataMoveBTsyrk dataMoveBTCgemm
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

#ifdef HERMITIAN
#undef HERMITIAN
#endif

#include "../xsyrk/xsyrkInternalC66SC.inc"

void csyr2kSC(char uplo, char trans,
		      int n, int k,
		      complex alpha, complex *a, int lda,
              complex *b, int ldb,
              complex beta, complex *c, int ldc)
{
  complex betaC;

  csyr2kInternal(uplo, trans, n, k, alpha, a,
		  lda, b, ldb, beta, c, ldc);

  betaC.r = (real) 1.0;
  betaC.i = (real) 0.0;
  csyr2kInternal(uplo, trans, n, k, alpha, b,
		  ldb, a, lda, betaC, c, ldc);
}

