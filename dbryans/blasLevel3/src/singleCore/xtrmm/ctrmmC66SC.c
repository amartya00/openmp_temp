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
 *  @file   ctrmmC66SC.c
 *  @brief  This file contains basic ctrmm implementation
 *
 */

#include "singleCore/xtrmm/ctrmmC66SC.h"

#include "defCC66.h"
#include "../kernels/cgemmKernel.h"
#include "../dataMove/dataMoveCgemm.h"
#include "../dataMove/dataMoveCtrmm.h"

#define dataType complex
#define xtrmmKernelNoReadFlexSave   cgemmKernelNoReadFlexSave
#define xtrmmKernelFlexSave         cgemmKernelFlexSave
#define xtrmmUpper                  ctrmmUpper
#define xtrmmLower                  ctrmmLower

#define XTRMM          "CTRMM"

#define dataMoveAHtrmm dataMoveAHCgemm
#define dataMoveATtrmm dataMoveATCgemm
#define dataMoveAtrmm  dataMoveACgemm
#define dataMoveBHtrmm dataMoveBHCgemm
#define dataMoveBTtrmm dataMoveBTCgemm
#define dataMoveBtrmm  dataMoveBCgemm

#define arrangeDataLAtrmm   arrangeDataLACtrmm
#define arrangeDataLTAtrmm  arrangeDataLTACtrmm
#define arrangeDataUAtrmm   arrangeDataUACtrmm
#define arrangeDataUTAtrmm  arrangeDataUTACtrmm

#define M_KERNEL M_KERNEL_C
#define N_KERNEL N_KERNEL_C

#define KPARTITION KPARTITION_C
#define MPARTITION MPARTITION_C
#define NPARTITION NPARTITION_C
#define NUMAPANELS NUMAPANELS_C
#define NUMBPANELS NUMBPANELS_C
#define BANKOFFSET 0

#include "xtrmmC66SC.inc"

void ctrmmSC(char side, char uplo, char transa, char diag,
		     int m, int n,
		     dataType alpha, dataType *a, int lda,
             dataType *b, int ldb)
{
  int flagSideisL = 0, flagUploisU = 0, flagTransAisN = 0;
  if((side=='l') || (side=='L')) flagSideisL=1;
  if((uplo=='u') || (uplo=='U')) flagUploisU=1;
  if((transa=='n') || (transa=='N')) flagTransAisN=1;

  if((flagSideisL && flagUploisU && flagTransAisN) ||
	 (flagSideisL && !flagUploisU && !flagTransAisN) ||
	 (!flagSideisL && !flagUploisU && flagTransAisN) ||
     (!flagSideisL && flagUploisU && !flagTransAisN))
  {
    ctrmmUpper(side, uplo, transa, diag, m, n, alpha,
			a, lda, b, ldb);
  }
  else
  {
    ctrmmLower(side, uplo, transa, diag, m, n, alpha,
			a, lda, b, ldb);
  }
}

