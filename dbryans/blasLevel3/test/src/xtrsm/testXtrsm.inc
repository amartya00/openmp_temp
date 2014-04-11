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

#define ARBITRARY_FACTOR 10.0

// ****************************************************************************************
void testXtrsm(ParamsBlas3_t * pParams, double *gFlops, double *err)
{
  int nthreads;
  int m, n, nAligned, lda, ldb;
  char side, uplo, transA, diag;
  dataType alpha;
  dataType *matA, *matB;

#ifdef VERIFICATION
  dataType *matBref;
  int iCnt, jCnt;
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
  side = pParams->side;
  uplo = pParams->uplo;
  transA = pParams->transa;
  diag = pParams->diag;
#ifdef COMPLEX
  alpha.r = (baseType) pParams->alpha;
  alpha.i = (baseType) pParams->alpha_i;
#else
  alpha = (baseType) pParams->alpha;
#endif

  // define dependent parameters
  lda = ((side == 'L') || (side == 'l')) ? m : n;
  // for trsm, make sure lda is a multiple of N_KERNEL
  // (for trsm all sizes are made multiple of N_KERNEL since N_KERNEL >= M_KERNEL)
  lda = N_KERNEL*((lda+(N_KERNEL-1))/N_KERNEL);

  // ldb multiple of M_KERNEL if side is l; otherwise, it must be multiple of N_KERNEL since we are computing the transpose
  if((side == 'L') || (side == 'l')) ldb = M_KERNEL*((m+(M_KERNEL-1))/M_KERNEL);
  else ldb = N_KERNEL*((m+(N_KERNEL-1))/N_KERNEL);

  matA = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, lda*lda*sizeof(dataType), CACHELINE, NULL);

  System_printf("%s for m=%d, n=%d, side=%c, uplo=%c, transA=%c, diag=%c\n", XTRSM,
    m, n, side, uplo, transA, diag);

  nAligned = N_KERNEL*((n+(N_KERNEL-1))/N_KERNEL);
  matB = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, ldb*nAligned*sizeof(dataType), CACHELINE, NULL);

#ifdef VERIFICATION
  // set memory with random number
  System_printf("filling memory with random pattern\n");
  // ensure that matA is fully filled
  randomFill(matA, lda*lda);
  randomFill(matB, ldb*n);
  // ensure there is no small element in diag(matA)
#ifdef COMPLEX
  if((diag == 'u') || (diag == 'U')) // reduce each element proportional to matrix size to make it stable
  {
	baseType temp;
	temp = ((baseType) ARBITRARY_FACTOR/(baseType) lda);
    for(jCnt = 0; jCnt < lda; jCnt++)
	  for(iCnt = 0; iCnt < lda; iCnt++)
	  {
	    matA[jCnt*lda+iCnt].r = temp * matA[jCnt*lda].r;
		matA[jCnt*lda+iCnt].i = temp * matA[jCnt*lda].i;
	  }
  }
  else  // ensure large values in diagonal part to make it stable
  {
    for(jCnt = 0; jCnt < lda; jCnt++)
    {
     dataType temp;

  	  temp.r = 0;
	  temp.i = 0;
	  for(iCnt = 0; iCnt < lda; iCnt++)
	  {
	    temp.r += matA[jCnt*lda+iCnt].r * matA[jCnt*lda+iCnt].r;
	    temp.i += matA[jCnt*lda+iCnt].i * matA[jCnt*lda+iCnt].i;
	  }
	  for(iCnt = 0; iCnt < lda; iCnt++)
	  {
	    temp.r += matA[iCnt*lda+jCnt].r * matA[iCnt*lda+jCnt].r;
	    temp.i += matA[iCnt*lda+jCnt].i * matA[iCnt*lda+jCnt].i;
	  }
	  matA[jCnt*lda+jCnt].r = ((baseType) ARBITRARY_FACTOR/(baseType) lda)  * temp.r;
	  matA[jCnt*lda+jCnt].i = ((baseType) ARBITRARY_FACTOR/(baseType) lda)  * temp.i;
    }
  }
#else
  if((diag == 'u') || (diag == 'U')) // reduce each element proportional to matrix size to make it stable
  {
    baseType temp;
    temp = ((baseType) ARBITRARY_FACTOR/(baseType) lda);
    for(jCnt = 0; jCnt < lda; jCnt++)
      for(iCnt = 0; iCnt < lda; iCnt++)
      {
  	    matA[jCnt*lda+iCnt] = temp * matA[jCnt*lda+iCnt];
      }
    }
  else  // ensure large values in diagonal part to make it stable
  {
    for(jCnt = 0; jCnt < lda; jCnt++)
    {
	  dataType temp;

	  temp = 0;
	  for(iCnt = 0; iCnt < lda; iCnt++)
	  {
	    temp += matA[jCnt*lda+iCnt] * matA[jCnt*lda+iCnt];
	  }
	  for(iCnt = 0; iCnt < lda; iCnt++)
	  {
	    temp += matA[iCnt*lda+jCnt] * matA[iCnt*lda+jCnt];
	  }
	  matA[jCnt*lda+jCnt] = ((baseType) ARBITRARY_FACTOR/(baseType) lda) * temp;
    }
  }
#endif

  matBref = (dataType *) Memory_alloc((IHeap_Handle) dataHeap, ldb*nAligned*sizeof(dataType), CACHELINE, NULL);

  // copy matC to matCref
  memcpy(matBref,matB,ldb*n*sizeof(dataType));

  // vanilla sgemm
  System_printf("Running reference %s.....\n", XTRSM);
  xtrsm_(&side, &uplo, &transA, &diag, (integer *) &m, (integer *) &n, &alpha, matA,
    (integer *) &lda, matBref, (integer *) &ldb, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);

#endif
  System_printf("Now Running Optimized %s over %d core(s).....\n", XTRSM, nthreads);

#ifdef PROFILE_CYCLES
    Timestamp_get64(&timeIn);
#endif

    // optimized xtrmm
    xtrsm(side, uplo, transA, diag, m, n,
    		alpha, matA, lda, matB, ldb);

#ifdef PROFILE_CYCLES
  Timestamp_get64(&timeOut);
#endif

#ifdef PROFILE_CYCLES
  cpuCycles = (((double) ((unsigned int) timeOut.hi)) *  2.0 * ((double) ((unsigned int) (1<<31))) +
  	((double) ((unsigned int) timeOut.lo))) -
  	(((double) ((unsigned int) timeIn.hi)) *  2.0 * ((double) ((unsigned int) (1<<31))) +
  	((double) ((unsigned int) timeIn.lo)));
  if((side=='l') || (side=='L')) *gFlops =  (((double) m)* ((double) (m+1))* ((double)n))/ cpuCycles;
  else *gFlops =  (((double) m)* ((double) n)* ((double) (n+1)))/ cpuCycles;
#endif

#ifdef VERIFICATION
    // compare output
  *err=compareMatrices(m, n, matB, ldb, matBref, ldb);
  Memory_free((IHeap_Handle) dataHeap, matBref, ldb*nAligned*sizeof(dataType));
#endif

  Memory_free((IHeap_Handle) dataHeap, matA, lda*lda*sizeof(dataType));
  Memory_free((IHeap_Handle) dataHeap, matB, ldb*nAligned*sizeof(dataType));

} // main()

