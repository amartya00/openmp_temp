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
 *  @file   dtrmmC66SC.c
 *  @brief  This file contains basic dtrmm implementation
 *
 */

#include "singleCore/xtrmm/dtrmmC66SC.h"

#include "defDC66.h"
#include "../kernels/dgemmKernel.h"
#include "../dataMove/dataMoveDgemm.h"
#include "../dataMove/dataMoveDtrmm.h"

#define dataType double
#define xtrmmKernelNoReadFlexSave   dgemmKernelNoReadFlexSave
#define xtrmmKernelFlexSave         dgemmKernelFlexSave
#define xtrmmUpper                  dtrmmUpper
#define xtrmmLower                  dtrmmLower

#define XTRMM          "DTRMM"

#define dataMoveAHtrmm dataMoveATDgemm
#define dataMoveATtrmm dataMoveATDgemm
#define dataMoveAtrmm  dataMoveADgemm
#define dataMoveBHtrmm dataMoveBTDgemm
#define dataMoveBTtrmm dataMoveBTDgemm
#define dataMoveBtrmm  dataMoveBDgemm

#define arrangeDataLAtrmm   arrangeDataLADtrmm
#define arrangeDataLTAtrmm  arrangeDataLTADtrmm
#define arrangeDataUAtrmm   arrangeDataUADtrmm
#define arrangeDataUTAtrmm  arrangeDataUTADtrmm

#define M_KERNEL M_KERNEL_D
#define N_KERNEL N_KERNEL_D

#define KPARTITION KPARTITION_D
#define MPARTITION MPARTITION_D
#define NPARTITION NPARTITION_D
#define NUMAPANELS NUMAPANELS_D
#define NUMBPANELS NUMBPANELS_D
#define BANKOFFSET 2

#include "xtrmmC66SC.inc"

void dtrmmSC(char side, char uplo, char transa, char diag,
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
    dtrmmUpper(side, uplo, transa, diag, m, n, alpha,
			a, lda, b, ldb);
  }
  else
  {
    dtrmmLower(side, uplo, transa, diag, m, n, alpha,
			a, lda, b, ldb);
  }
}

