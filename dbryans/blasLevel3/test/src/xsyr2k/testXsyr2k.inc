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
 *  @file   testXsyr2k.inc
 *  @brief  Test bench. This is used to test XSYR2K/XHER2K API. This is generic
 *          code that cannot be compiled by itself and only included
 *          in proper files.
 *
 */

/** @defgroup testPackage test package  */

/** @ingroup testPackage */
/* @{ */

#include <xdc/runtime/System.h>

// includes needed for heap/memory allocation
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/cfg/global.h>

#ifdef _OPENMP
#include <ti/omp/omp.h>
#include <ti/omp/libgomp_g.h>
#endif

#ifdef PROFILE_CYCLES
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>
#endif

#include "math.h"

// ****************************************************************************************
void testXsyr2k(ParamsBlas3_t * pParams, double *gFlops, double *err)
{
  int nthreads;
  int n, k, nAligned, lda, ldb, ldc;
  char trans, uplo;
  #ifdef ALPHACOMPLEX
  dataType alpha;
  #else
  baseType alpha;
  #endif
  #ifdef BETACOMPLEX
  dataType beta;
  #else
  baseType beta;
  #endif
  dataType *matA, *matB, *matC;

#ifdef VERIFICATION
  dataType *matCref;
#endif

#ifdef PROFILE_CYCLES
  double cpuCycles = 0;
  Types_Timestamp64 timeIn, timeOut;
#endif

  *gFlops = 0;
  *err = 0;

#ifdef _OPENMP
  // number of threads
  nthreads = omp_get_max_threads();
#else
  nthreads = 1;
#endif

  // get parameters
  n = pParams->n;
  k = pParams->k;
  trans = pParams->trans;
  uplo = pParams->uplo;
#ifdef ALPHACOMPLEX
  alpha.r = (baseType) pParams->alpha;
  alpha.i = (baseType) pParams->alpha_i;
#else
  alpha = (baseType) pParams->alpha;
#endif
#ifdef BETACOMPLEX
  beta.r = (baseType) pParams->beta;
  beta.i = (baseType) pParams->beta_i;
#else
  beta = (baseType) pParams->beta;
#endif

  // define dependent parameters
  lda = ((trans == 'N') || (trans == 'n')) ? n : k;
  // define dependent parameters
  ldb = ((trans == 'N') || (trans == 'n')) ? n : k;
  // ldc multiple of M_KERNEL
  ldc = M_KERNEL*((n+(M_KERNEL-1))/M_KERNEL);

  matA = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, n*k*sizeof(dataType), CACHELINE, NULL);
  matB = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, n*k*sizeof(dataType), CACHELINE, NULL);

  System_printf("%s for n=%d, k=%d, trans=%c, uplo=%c\n", XSYR2K,
    n, k, trans, uplo);

  nAligned = N_KERNEL*((n+(N_KERNEL-1))/N_KERNEL);
  matC = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, ldc*nAligned*sizeof(dataType), CACHELINE, NULL);

#ifdef VERIFICATION
  // set memory with random number
  System_printf("filling memory with random pattern\n");
  randomFill(matA, n*k);
  randomFill(matB, n*k);
  randomFill(matC, ldc*n);

#ifdef HERMITIAN
  {
	int cnt;
	// diagonal part of Hermitian matrix C is real
	for(cnt = 0; cnt < n; cnt++) matC[ldc*cnt+cnt].i = (baseType) 0.0;
  }
#endif

  matCref = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, ldc*nAligned*sizeof(dataType), CACHELINE, NULL);

  // copy matC to matCref
  memcpy(matCref,matC,ldc*n*sizeof(dataType));

  // vanilla sgemm
  System_printf("Running reference %s.....\n", XSYR2K);
  xsyr2k_(&uplo, &trans, (integer *) &n, (integer *) &k, &alpha, matA, (integer *) &lda,
		  matB, (integer *) &ldb, &beta, matCref, (integer *) &ldc, (ftnlen)1, (ftnlen)1);
#endif
  System_printf("Now Running Optimized %s over %d core(s).....\n", XSYR2K, nthreads);

#ifdef PROFILE_CYCLES
    Timestamp_get64(&timeIn);
#endif

    // optimized xsyr2k
    xsyr2k(uplo, trans, n, k, alpha, matA,
    		lda, matB, ldb, beta, matC, ldc);

#ifdef PROFILE_CYCLES
  Timestamp_get64(&timeOut);
#endif

#ifdef PROFILE_CYCLES
  cpuCycles = (((double) ((unsigned int) timeOut.hi)) *  2.0 * ((double) ((unsigned int) (1<<31))) +
  	((double) ((unsigned int) timeOut.lo))) -
  	(((double) ((unsigned int) timeIn.hi)) *  2.0 * ((double) ((unsigned int) (1<<31))) +
  	((double) ((unsigned int) timeIn.lo)));
  *gFlops =  (2.0 * ((double) (n+1))* ((double) n)* ((double)k))/ cpuCycles;
#endif

#ifdef VERIFICATION
  // compare output
  *err=compareMatrices(n, n, matC, ldc, matCref, ldc);
  Memory_free((IHeap_Handle) dataHeap, matCref, ldc*nAligned*sizeof(dataType));
#endif

  Memory_free((IHeap_Handle) dataHeap, matA, n*k*sizeof(dataType));
  Memory_free((IHeap_Handle) dataHeap, matB, n*k*sizeof(dataType));
  Memory_free((IHeap_Handle) dataHeap, matC, ldc*nAligned*sizeof(dataType));

} // testXsyr2k()

/* @} */ /* ingroup */

/* Nothing past this point */

