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
 *  @file   fft2D_mc.c
 *  @brief  multi-core 2-D FFT implementation using openMP
 *
 */

#include "fft2D_mc.h"


#ifdef _OPENMP
#include <ti/omp/omp.h>
#include <ti/omp/libgomp_g.h>
#endif

static Complex_t *dataLocal, *dataTempLocal;
static fft1DTransstruct_t para1DLocal;

void fft_2D_mc(Complex_t * restrict data, Complex_t * restrict dataTemp, fft2Dstruct_t *para)
{

	int tid;
#ifdef _OPENMP
    int numThread = omp_get_max_threads();;
#else
	int numThread = 1;
#endif
    
	// move shared data to static global memory
	dataLocal  = data;
    dataTempLocal = dataTemp;
	para1DLocal.Nx = para->Nx;
	para1DLocal.Ny = para->Ny;
	para1DLocal.pTwiddle = para->xTwiddle;
	para1DLocal.NLines = para->Ny/numThread;

	// row wise tranform; save transpose
#ifdef _OPENMP
#pragma omp parallel private(tid) shared(dataLocal, dataTempLocal, para1DLocal)
#endif
	{
#ifdef _OPENMP
		tid = omp_get_thread_num();     // Obtain thread number
#else
		tid = 0;
#endif
		// data parallel tasking across threads
		fft_1D_batched_trans(&dataLocal[tid*(para1DLocal.Nx*para1DLocal.NLines)], &dataTempLocal[tid*(para1DLocal.NLines)] , &para1DLocal);
	}

	// move shared data to static global memory
	para1DLocal.Nx = para->Ny;
	para1DLocal.Ny = para->Nx;
	para1DLocal.pTwiddle = para->yTwiddle;
	para1DLocal.NLines = para->Nx/numThread;

	// column wise transform; save transpose
#ifdef _OPENMP
#pragma omp parallel private(tid) shared(dataLocal, dataTempLocal, para1DLocal)
#endif
	{
#ifdef _OPENMP
		tid = omp_get_thread_num();     // Obtain thread number
#else
		tid = 0;
#endif
		// data parallel tasking across threads
	    fft_1D_batched_trans(&dataTempLocal[tid*(para1DLocal.Nx*para1DLocal.NLines)], &dataLocal[tid*(para1DLocal.NLines)] , &para1DLocal);
	}

}
