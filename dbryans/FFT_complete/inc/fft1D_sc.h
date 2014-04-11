#ifndef _FFT1D_SC_H
#define _FFT1D_SC_H

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
 *  @file   fft1D_sc.h
 *  @brief  header file for single-core batch 1-D FFT  
 *
 */

/** @defgroup FFT FFT  */

/** @ingroup FFT */
/* @{ */


#define L2MEMSIZE (256*1024)
#define BUFALIGN  8

//! \brief      complex data type
typedef struct _Complex_ {
  /// real part
  float re;
  /// complex part
  float im;
} Complex_t;

//! \brief      1-D FFT structure 
typedef struct _fft1Dstruct_ {
  // FFT size
  unsigned int N;
  // number of lines to process in this call
  unsigned int NLines;
  // pointer to twiddle factors
  Complex_t *pTwiddle;      
} fft1Dstruct_t;

//! \brief      1-D FFT structure for transpose output
typedef struct _fft1DTransstruct_ {
  // FFT size (1st dimension)
  unsigned int Nx;
  // 2nd dimension size for transpose)
  unsigned int Ny;
  // number of lines to process in this call
  unsigned int NLines;
  // pointer to twiddle factors
  Complex_t *pTwiddle;      
} fft1DTransstruct_t;

//! \brief      batched 1-D FFT transform 
//! \param[in]  inPtr          input data buffer
//! \param[out] outPtr         output data buffer
//! \param[in]  para           FFT parameter structure
void fft_1D_batched(Complex_t *inPtr, Complex_t *outPtr, fft1Dstruct_t *para);

//! \brief      batched 1-D FFT transform (output is transposed)
//! \param[in]  inPtr          input data buffer
//! \param[out] outPtr         output data buffer
//! \param[in]  para           FFT parameter structure
void fft_1D_batched_trans(Complex_t *inPtr, Complex_t *outPtr, fft1DTransstruct_t *para);

#endif  // _FFT1D_SC_H

/* @} */ /* ingroup */

/* Nothing past this point */
