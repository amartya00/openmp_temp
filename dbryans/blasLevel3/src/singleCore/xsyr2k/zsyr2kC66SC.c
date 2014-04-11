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
 *  @file   zsyr2kC66SC.c
 *  @brief  This file contains basic zsyr2k implementation
 *
 */

#include "singleCore/xsyr2k/zsyr2kC66SC.h"

#include "defZC66.h"
#include "../kernels/zgemmKernel.h"
#include "../dataMove/dataMoveZgemm.h"

#define dataType doublecomplex
#define baseType double
#define xsyrkInternal          zsyr2kInternal
#define xsyrkKernelFlexSave    zgemmKernelFlexSave
#define XSYRK          "ZSYR2K"

#define dataMoveATsyrk dataMoveATZgemm
#define dataMoveAsyrk  dataMoveAZgemm
#define dataMoveBTsyrk dataMoveBTZgemm
#define dataMoveBsyrk  dataMoveBZgemm

#define M_KERNEL M_KERNEL_Z
#define N_KERNEL N_KERNEL_Z

#define KPARTITION KPARTITION_Z
#define MPARTITION MPARTITION_Z
#define NPARTITION NPARTITION_Z
#define NUMAPANELS NUMAPANELS_Z
#define NUMBPANELS NUMBPANELS_Z
#define BANKOFFSET 0

#ifndef COMPLEX
#define COMPLEX
#endif

#ifdef HERMITIAN
#undef HERMITIAN
#endif

#include "../xsyrk/xsyrkInternalC66SC.inc"

void zsyr2kSC(char uplo, char trans,
		      int n, int k,
		      doublecomplex alpha, doublecomplex *a, int lda,
              doublecomplex *b, int ldb,
              doublecomplex beta, doublecomplex *c, int ldc)
{
  doublecomplex betaC;

  zsyr2kInternal(uplo, trans, n, k, alpha, a,
		  lda, b, ldb, beta, c, ldc);

  betaC.r = (double) 1.0;
  betaC.i = (double) 0.0;
  zsyr2kInternal(uplo, trans, n, k, alpha, b,
		  ldb, a, lda, betaC, c, ldc);
}
