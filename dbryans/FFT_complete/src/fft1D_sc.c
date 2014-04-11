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
 *  @file   fft1D_sc.c
 *  @brief  single-core batch 1-D FFT implementation 
 *
 */

#include "fft1D_sc.h"
#include "util/edma.h"

#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/cfg/global.h>
#include <inc/dsplib.h>
#include <c6x.h>

// *************************************************************************************************************
void fft_1D_batched_trans(Complex_t *inPtr, Complex_t *outPtr, fft1DTransstruct_t *para)
{

int patch_size, lengthRbyte;
int i_patch, N_patch, Extra_lines;
int num_lines, total_lines;
short indCurrent;
int j_col;
int indx;
int N, N_C;

float *pTwiddleFFT;
float *ptrBuff1;
float *ptrBuff2;
float *ptrBuff3;
float *ptrBuffTemp;

float *ptrIn, *ptrOut, *ptrProc;
float *ptrFFTout, *ptrFFTin;


N = para->Nx;

total_lines =	para->Ny;
num_lines =  para->NLines; // Number of lines to be processed per core

if(num_lines==0) return; // nothing to do

lengthRbyte = N*sizeof(Complex_t);
N_C = (L2MEMSIZE-2*lengthRbyte)/(4*N*sizeof(Complex_t)); // Number of lines in each patch
patch_size = lengthRbyte*N_C;
N_patch = num_lines/N_C;
Extra_lines = num_lines - N_patch*N_C;

// allocate all internal buffers
ptrBuff1 = (float *) Memory_alloc((IHeap_Handle) l2Heap, patch_size, BUFALIGN, NULL);
ptrBuff2 = (float *) Memory_alloc((IHeap_Handle) l2Heap, patch_size, BUFALIGN, NULL);
ptrBuff3 = (float *) Memory_alloc((IHeap_Handle) l2Heap, patch_size, BUFALIGN, NULL);
ptrBuffTemp  = (float *) Memory_alloc((IHeap_Handle) l2Heap, patch_size, BUFALIGN, NULL);
pTwiddleFFT =(float *) Memory_alloc((IHeap_Handle) l2Heap, 2*lengthRbyte, BUFALIGN, NULL);

// transfer twiddle factor to L2;
edmaInitiateXfer(pTwiddleFFT, para->pTwiddle, 2*lengthRbyte, 1, 1, 1, 1, 1, 1, 0);
edmaWait4Completion(0);

// initial transfer
if(N_patch == 0) edmaInitiateXfer(ptrBuff1, inPtr, lengthRbyte, Extra_lines, 1, lengthRbyte, lengthRbyte, 1, 1, 0);
else edmaInitiateXfer(ptrBuff1, inPtr, lengthRbyte, N_C, 1, lengthRbyte, lengthRbyte, 1, 1, 0);

indCurrent= -1;

for (i_patch=0; i_patch<N_patch; i_patch++)

{
	indCurrent = (indCurrent+1);
	if(indCurrent > 2) indCurrent = 0;

	if (indCurrent == 0)
	{
		ptrIn   = ptrBuff2;
		ptrProc = ptrBuff1;
		ptrOut  = ptrBuff1;
	}

	if (indCurrent == 1)
	{
		ptrIn   = ptrBuff3;
		ptrProc = ptrBuff2;
	    ptrOut  = ptrBuff2;
	}

	if (indCurrent == 2)
	{
		ptrIn   = ptrBuff1;
		ptrProc = ptrBuff3;
	    ptrOut  = ptrBuff3;
	}

	edmaWait4Completion(0);

	if (i_patch<N_patch-1 )
	{
	    edmaInitiateXfer(ptrIn, &(inPtr[N*N_C*(i_patch+1)]), lengthRbyte, N_C, 1, lengthRbyte, lengthRbyte, 1, 1, 0);
	}
	else if(Extra_lines != 0) // last transfer if needed
	{
	    edmaInitiateXfer(ptrIn, &(inPtr[N*N_C*(i_patch+1)]), lengthRbyte, Extra_lines, 1, lengthRbyte, lengthRbyte, 1, 1, 0);
	}

	// line by line processing
	for (j_col=0; j_col<N_C; j_col++)
	{
		indx = j_col*N*2;
		ptrFFTin =  &(ptrProc[indx]);
		ptrFFTout = &(ptrBuffTemp[indx]);  //  FFT output would be stored in a temporary location
		DSPF_sp_fftSPxSP(N, ptrFFTin, pTwiddleFFT, ptrFFTout, 0 , 2, 0, N);
	}

	DSPF_sp_mat_trans_cplx(ptrBuffTemp, N_C, N, ptrProc); // Takes the transpose of the patch

	if (i_patch > 0 )
	{
		edmaWait4Completion(2);
	}


	edmaInitiateXfer(&(outPtr[N_C*i_patch]), ptrOut,  2*N_C*sizeof(float) , N, 1, 2*N_C*sizeof(float), 2*total_lines*sizeof(float), 1, 1, 2);
}

if(Extra_lines != 0) // additional lines to process
{
	indCurrent = (indCurrent+1);
	if(indCurrent > 2) indCurrent = 0;

	if (indCurrent == 0)
	{
		ptrIn   = ptrBuff2;
		ptrProc = ptrBuff1;
		ptrOut  = ptrBuff1;
	}

	if (indCurrent == 1)
	{
		ptrIn   = ptrBuff3;
		ptrProc = ptrBuff2;
	    ptrOut  = ptrBuff2;
	}

	if (indCurrent == 2)
	{
		ptrIn   = ptrBuff1;
		ptrProc = ptrBuff3;
	    ptrOut  = ptrBuff3;
	}

	edmaWait4Completion(0);

	// line by line processing
	for (j_col=0; j_col<Extra_lines; j_col++)
	{
		indx = j_col*N*2;
		ptrFFTin =  &(ptrProc[indx]);
		ptrFFTout = &(ptrBuffTemp[indx]);  //  FFT output would be stored in a temporary location
		DSPF_sp_fftSPxSP(N, ptrFFTin, pTwiddleFFT, ptrFFTout, 0 , 2, 0, N);
	}

	DSPF_sp_mat_trans_cplx(ptrBuffTemp, Extra_lines, N, ptrProc); // Takes the transpose of the patch

	if (N_patch != 0 )
	{
		edmaWait4Completion(2);
	}

	// output transfer
	edmaInitiateXfer(&(outPtr[N_C*N_patch]), ptrOut,  2*Extra_lines*sizeof(float) , N, 1, 2*Extra_lines*sizeof(float), 2*total_lines*sizeof(float), 1, 1, 2);

}
edmaWait4Completion(2);

/////////////////////////////////////////////////////////
Memory_free((IHeap_Handle) l2Heap, pTwiddleFFT, 2*lengthRbyte);
Memory_free((IHeap_Handle) l2Heap, ptrBuffTemp, patch_size);
Memory_free((IHeap_Handle) l2Heap, ptrBuff3, patch_size);
Memory_free((IHeap_Handle) l2Heap, ptrBuff2, patch_size);
Memory_free((IHeap_Handle) l2Heap, ptrBuff1, patch_size);

}

// *************************************************************************************************************
void fft_1D_batched(Complex_t *inPtr, Complex_t *outPtr, fft1Dstruct_t *para)
{

int patch_size, lengthRbyte;
int i_patch, N_patch, Extra_lines;
int num_lines;
short indCurrent;
int j_col;
int indx;
int N, N_C;

float *pTwiddleFFT;
float *ptrBuff0;
float *ptrBuff1;
float *ptrBuff2;
float *ptrBuff3;

float *ptrIn, *ptrOut, *ptrProc;
float *ptrFFTout, *ptrFFTin;

N = para->N;
num_lines = para->NLines;   // Number of lines to be processed per core
if(num_lines==0) return; // nothing to do

lengthRbyte = N*sizeof(Complex_t);
N_C = (L2MEMSIZE-2*lengthRbyte)/(4*N*sizeof(Complex_t)); // Number of lines in each patch
patch_size = lengthRbyte*N_C;
N_patch = num_lines/N_C;
Extra_lines = num_lines - N_patch*N_C;

// allocate all internal buffers
ptrBuff0 = (float *) Memory_alloc((IHeap_Handle) l2Heap, patch_size, BUFALIGN, NULL);
ptrBuff1 = (float *) Memory_alloc((IHeap_Handle) l2Heap, patch_size, BUFALIGN, NULL);
ptrBuff2 = (float *) Memory_alloc((IHeap_Handle) l2Heap, patch_size, BUFALIGN, NULL);
ptrBuff3 = (float *) Memory_alloc((IHeap_Handle) l2Heap, patch_size, BUFALIGN, NULL);
pTwiddleFFT = (float *) Memory_alloc((IHeap_Handle) l2Heap, 2*lengthRbyte, BUFALIGN, NULL);

// transfer twiddle factor to L2; 
edmaInitiateXfer(pTwiddleFFT, para->pTwiddle, 2*lengthRbyte, 1, 1, 1, 1, 1, 1, 0);
edmaWait4Completion(0);

// initial transfer
if(N_patch == 0) edmaInitiateXfer(ptrBuff0, inPtr, lengthRbyte, Extra_lines, 1, lengthRbyte, lengthRbyte, 1, 1, 0);
else edmaInitiateXfer(ptrBuff0, inPtr, lengthRbyte, N_C, 1, lengthRbyte, lengthRbyte, 1, 1, 0);

indCurrent= -1;

for (i_patch=0; i_patch<N_patch; i_patch++)

{
	indCurrent = (indCurrent+1)&3;
	// buffer assignments
	if (indCurrent == 0)
	{
		ptrIn   = ptrBuff1;
		ptrProc = ptrBuff0;
		ptrOut  = ptrBuff3;
	}

	if (indCurrent == 1)
	{
		ptrIn   = ptrBuff2;
		ptrProc = ptrBuff1;
	    ptrOut  = ptrBuff0;
	}

	if (indCurrent == 2)
	{
		ptrIn   = ptrBuff3;
		ptrProc = ptrBuff2;
	    ptrOut  = ptrBuff1;
	}

	if (indCurrent == 3)
	{
		ptrIn   = ptrBuff0;
		ptrProc = ptrBuff3;
	    ptrOut  = ptrBuff2;
	}

	edmaWait4Completion(0);

	if (i_patch<N_patch-1 )
	{
	    edmaInitiateXfer(ptrIn, &(inPtr[N*N_C*(i_patch+1)]), lengthRbyte, N_C, 1, lengthRbyte, lengthRbyte, 1, 1, 0);
	}
	else if(Extra_lines != 0) // last transfer if needed
	{
	    edmaInitiateXfer(ptrIn, &(inPtr[N*N_C*(i_patch+1)]), lengthRbyte, Extra_lines, 1, lengthRbyte, lengthRbyte, 1, 1, 0);
	}

	// line by line processing
	for (j_col=0; j_col<N_C; j_col++)
	{
		indx = j_col*N*2;
		ptrFFTin =  &(ptrProc[indx]);
		ptrFFTout = &(ptrOut[indx]);
		DSPF_sp_fftSPxSP(N, ptrFFTin, pTwiddleFFT, ptrFFTout, 0 , 2, 0, N);
	}

	if (i_patch > 0 )
	{
		edmaWait4Completion(2);
	}

	// output transfer
	edmaInitiateXfer(&(outPtr[N*N_C*i_patch]), ptrOut,  lengthRbyte, N_C, 1, lengthRbyte, lengthRbyte, 1, 1, 2);
}

  if(Extra_lines != 0) // additional lines to process
  {
		indCurrent = (indCurrent+1)&3;
		// buffer assignments
		if (indCurrent == 0)
		{
			ptrIn   = ptrBuff1;
			ptrProc = ptrBuff0;
			ptrOut  = ptrBuff3;
		}

		if (indCurrent == 1)
		{
			ptrIn   = ptrBuff2;
			ptrProc = ptrBuff1;
		    ptrOut  = ptrBuff0;
		}

		if (indCurrent == 2)
		{
			ptrIn   = ptrBuff3;
			ptrProc = ptrBuff2;
		    ptrOut  = ptrBuff1;
		}

		if (indCurrent == 3)
		{
			ptrIn   = ptrBuff0;
			ptrProc = ptrBuff3;
		    ptrOut  = ptrBuff2;
		}

		edmaWait4Completion(0);

		// line by line processing
		for (j_col=0; j_col<Extra_lines; j_col++)
		{
			indx = j_col*N*2;
			ptrFFTin =  &(ptrProc[indx]);
			ptrFFTout = &(ptrOut[indx]);
			DSPF_sp_fftSPxSP(N, ptrFFTin, pTwiddleFFT, ptrFFTout, 0 , 2, 0, N);
		}

		if (N_patch != 0 )
		{
			edmaWait4Completion(2);
		}

		// output transfer
		edmaInitiateXfer(&(outPtr[N*N_C*N_patch]), ptrOut,  lengthRbyte, Extra_lines, 1, lengthRbyte, lengthRbyte, 1, 1, 2);

  }
edmaWait4Completion(2);

// free all allocated memory
Memory_free((IHeap_Handle) l2Heap, pTwiddleFFT, 2*lengthRbyte);
Memory_free((IHeap_Handle) l2Heap, ptrBuff3, patch_size);
Memory_free((IHeap_Handle) l2Heap, ptrBuff2, patch_size);
Memory_free((IHeap_Handle) l2Heap, ptrBuff1, patch_size);
Memory_free((IHeap_Handle) l2Heap, ptrBuff0, patch_size);

}




