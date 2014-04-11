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
 *  @file   testXgemm.inc
 *  @brief  Test bench. This is used to test XGEMM API. This is generic
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

// ****************************************************************************************
void testXgemm(ParamsBlas3_t * pParams, double *gFlops, double *err)
{
  int nthreads;
  int m, n, k, nAligned, lda, ldb, ldc;
  char transA, transB;
  dataType alpha, beta;
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
  m = pParams->m;
  n = pParams->n;
  k = pParams->k;
  transA = pParams->transa;
  transB = pParams->transb;

#ifdef COMPLEX
    alpha.r = (baseType) pParams->alpha;
    beta.r = (baseType) pParams->beta;  
    alpha.i = (baseType) pParams->alpha_i;
    beta.i = (baseType) pParams->beta_i;  
#else
    alpha = (baseType) pParams->alpha;
    beta = (baseType) pParams->beta;
#endif

  // define dependent parameters
  lda = ((transA == 'N') || (transA == 'n')) ? m : k;
  ldb = ((transB == 'N') || (transB == 'n')) ? k : n;
  // ldc multiple of M_KERNEL
  ldc = M_KERNEL*((m+(M_KERNEL-1))/M_KERNEL);

  matA = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, m*k*sizeof(dataType), CACHELINE, NULL);
  matB = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, n*k*sizeof(dataType), CACHELINE, NULL);

  System_printf("%s for m=%d, n=%d, k=%d, transA=%c, transB=%c\n", XGEMM,
    m, n, k, transA, transB);

  nAligned = N_KERNEL*((n+(N_KERNEL-1))/N_KERNEL);
  matC = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, ldc*nAligned*sizeof(dataType), CACHELINE, NULL);

#ifdef VERIFICATION
  // set memory with random number
  System_printf("filling memory with random pattern\n");
  randomFill(matA, m*k);
  randomFill(matB, n*k);
  randomFill(matC, ldc*n);

  matCref = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, ldc*nAligned*sizeof(dataType), CACHELINE, NULL);

  // copy matC to matCref
  memcpy(matCref,matC, ldc*n*sizeof(dataType));

  // vanilla xgemm
  System_printf("Running reference %s.....\n", XGEMM);
  xgemm_(&transA, &transB, (integer *) &m, (integer *) &n, (integer *) &k, &alpha, matA,
    (integer *) &lda, matB, (integer *) &ldb, &beta, matCref, (integer *) &ldc, (ftnlen)1, (ftnlen)1);

#endif
  System_printf("Now Running Optimized %s over %d core(s).....\n", XGEMM, nthreads);

#ifdef PROFILE_CYCLES
    Timestamp_get64(&timeIn);
#endif

    // optimized xgemm
    xgemm(transA, transB, m, n, k, alpha, matA,
      lda, matB, ldb, beta, matC, ldc);

#ifdef PROFILE_CYCLES
  Timestamp_get64(&timeOut);
#endif

#ifdef PROFILE_CYCLES
  cpuCycles = (((double) ((unsigned int) timeOut.hi)) *  2.0 * ((double) ((unsigned int) (1<<31))) +
  	((double) ((unsigned int) timeOut.lo))) -
  	(((double) ((unsigned int) timeIn.hi)) *  2.0 * ((double) ((unsigned int) (1<<31))) +
  	((double) ((unsigned int) timeIn.lo)));
  *gFlops =  (2.0* ((double) m)* ((double) n)* ((double)k))/ cpuCycles;
#endif

#ifdef VERIFICATION
    // compare output
  *err=compareMatrices(m, n, matC, ldc, matCref, ldc);
  Memory_free((IHeap_Handle) dataHeap, matCref, ldc*nAligned*sizeof(dataType));
#endif

  Memory_free((IHeap_Handle) dataHeap, matA, m*k*sizeof(dataType));
  Memory_free((IHeap_Handle) dataHeap, matB, n*k*sizeof(dataType));
  Memory_free((IHeap_Handle) dataHeap, matC, ldc*nAligned*sizeof(dataType));

} // testXgemm()

/* @} */ /* ingroup */

/* Nothing past this point */
