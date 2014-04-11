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
 *  @file   ctrsmC66SC.c
 *  @brief  This file contains basic ctrsm implementation
 *
 */

#include "singleCore/xtrsm/ctrsmC66SC.h"

#include "defCC66.h"
#include "../kernels/cgemmKernel.h"
#include "../kernels/ctrsmKernel.h"
#include "../dataMove/dataMoveCgemm.h"
#include "../dataMove/dataMoveCtrsm.h"

#define dataType complex
#define baseType real
#define xtrsmKernel                 ctrsmKernel
#define xtrsmKernelFlexSave         cgemmKernelFlexSave
#define xtrsmUpper                  ctrsmUpper
#define xtrsmLower                  ctrsmLower

#define XTRSM          "CTRSM"

#define dataMoveAHtrsm dataMoveAHCgemm
#define dataMoveATtrsm dataMoveATCgemm
#define dataMoveAtrsm  dataMoveACgemm
#define dataMoveBHtrsm dataMoveBHCgemm
#define dataMoveBTtrsm dataMoveBTCgemm
#define dataMoveBtrsm  dataMoveBCgemm

#define arrangeDataLAtrsm   arrangeDataLACtrsm
#define arrangeDataLTAtrsm  arrangeDataLTACtrsm
#define arrangeDataUAtrsm   arrangeDataUACtrsm
#define arrangeDataUTAtrsm  arrangeDataUTACtrsm

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

#include "xtrsmC66SC.inc"

void ctrsmSC(char side, char uplo, char transa, char diag,
		     int m, int n,
		     complex alpha, complex *a, int lda,
             complex *b, int ldb)
{
  int flagSideisL = 0, flagUploisL = 0, flagTransAisN = 0;
  if((side=='l') || (side=='L')) flagSideisL=1;
  if((uplo=='l') || (uplo=='L')) flagUploisL=1;
  if((transa=='n') || (transa=='N')) flagTransAisN=1;

  if((flagSideisL && flagUploisL && flagTransAisN) ||
	 (flagSideisL && !flagUploisL && !flagTransAisN) ||
	 (!flagSideisL && !flagUploisL && flagTransAisN) ||
     (!flagSideisL && flagUploisL && !flagTransAisN))
  {
    ctrsmLower(side, uplo, transa, diag, m, n, alpha,
			a, lda, b, ldb);
  }
  else
  {
    ctrsmUpper(side, uplo, transa, diag, m, n, alpha,
			a, lda, b, ldb);
  }
}

