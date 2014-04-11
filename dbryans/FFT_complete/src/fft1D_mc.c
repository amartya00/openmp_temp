/*
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
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
*/

/**
 *  @file   fft1D_mc.c
 *  @brief  multi-core batch 1-D FFT implementation using openMP
 *
 */

#include "stdio.h"

#include "fft1D_mc.h"
#include "fft1D_sc.h"

static Complex_t *dataInLocal, *dataOutLocal;
static fft1Dstruct_t para1DLocal;


#ifdef _OPENMP
#include <ti/omp/omp.h>
#include <ti/omp/libgomp_g.h>
#endif

void fft_1D_mc(Complex_t * restrict datain, Complex_t * restrict dataout, fft1Dstruct_t *para)
{

	int tid;
#ifdef _OPENMP
    int numThread = omp_get_max_threads();
#else
	int numThread = 1;
#endif
    
	// move shared data to static global memory
	dataInLocal  = datain;
    dataOutLocal = dataout;
	para1DLocal.N = para->N;
	para1DLocal.pTwiddle = para->pTwiddle;
	para1DLocal.NLines = para->NLines/numThread;


#ifdef _OPENMP
	// openMP parallelization
#pragma omp parallel private(tid) shared(dataInLocal, dataOutLocal, para1DLocal)
#endif
	{
#ifdef _OPENMP
		tid = omp_get_thread_num();     // Obtain thread number
#else
		tid = 0;
#endif
		// data parallel tasking across threads
		fft_1D_batched(&dataInLocal[tid*(para1DLocal.N*para1DLocal.NLines)], &dataOutLocal[tid*(para1DLocal.N*para1DLocal.NLines)] , &para1DLocal);
	}

}
