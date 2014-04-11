/* Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
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
 *  @file   xsymmC66MC.inc
 *  @brief  This file includes multi core xsymm implementation.
 *          The functions has been been independent of data type.
 *          Proper renaming with #define is necessary.
 *
 */

/** @defgroup testPackage test package  */

/** @ingroup testPackage */
/* @{ */

#include <xdc/std.h>
#include "stdio.h"

#include <ti/csl/csl_cacheAux.h>
#include <xdc/runtime/System.h>

#ifdef _OPENMP
#include <ti/omp/omp.h>
#include <ti/omp/libgomp_g.h>
#endif

// These variables are made global and static
// These variables shared by OMP threads across cores
// and defined in the testSymm functions
static int xLocal[MAX_NUM_CORES];
static int mLocal, nLocal;
static int ldaLocal, ldbLocal, ldcLocal, flagSideIsL;
static char sideLocal, uploLocal;
static dataType alphaLocal, betaLocal;
static dataType *aLocal, *bLocal, *cLocal;

// ****************************************************************************************
// xsymm interface (designed to work with xhemm as well)
void xsymm(char side, char uplo,
		   int m, int n,
		   dataType alpha, dataType * restrict a, int lda,
           dataType * restrict b, int ldb,
           dataType beta,  dataType * restrict c, int ldc)
{
  int tid, nthreads, xStart, xEnd;
  int cacheSize = CACHELINE/sizeof(dataType);

  // parameter checking
  if((m & (M_KERNEL-1)) != 0)
  {
	System_printf("%s:m (%d) must be a multiple of m_kernel (%d). Skipping test\n", XSYMM, m, M_KERNEL);
	return;
  }
  if((n & (N_KERNEL-1)) != 0)
  {
	System_printf("%s:n (%d) must be a multiple of n_kernel (%d). Skipping test\n", XSYMM, n, N_KERNEL);
	return;
  }
  if((m & (CACHELINE/sizeof(dataType)-1)) != 0)
  {
    System_printf("%s:m (%d) must be a multiple of cacheline size (%d). Skipping test\n", XSYMM, m, CACHELINE/sizeof(dataType));
    return;
  }
  if((ldc & (cacheSize-1)) != 0)
  {
      System_printf("%s:ldc (%d) must be a multiple of cache line (%d).\n", XSYMM, ldc, cacheSize);
	  return;
  }
  if(((int) c & (CACHELINE-1)) != 0)
  {
      System_printf("%s:c (%x) must be at a multiple of cache line (%d).\n", XSYMM, c, CACHELINE);
	  return;
  }

  flagSideIsL = ((side == 'L') || (side == 'l')) ? 1 : 0;

#ifdef _OPENMP
  // number of threads
  nthreads = omp_get_max_threads();
#else
  nthreads = 1;
#endif


#ifdef _OPENMP
  // divide A equally across cores
  for(tid=0;tid<nthreads;tid++)
  {
	int xTemp1, xTemp2, factor;

	if(flagSideIsL)
	{ // C = AB
	  xTemp1 = n/N_KERNEL;
	  xTemp2 = xTemp1/nthreads;
	  xTemp1 = xTemp1 - xTemp2*nthreads;
      xStart = (tid < xTemp1) ?  (tid*(xTemp2+1)*N_KERNEL) : (((tid-xTemp1)*xTemp2+xTemp1*(xTemp2+1))*N_KERNEL);
      xEnd = ((tid+1) < xTemp1) ?  ((tid+1)*(xTemp2+1)*N_KERNEL) : (((tid+1-xTemp1)*xTemp2+xTemp1*(xTemp2+1))*N_KERNEL);
      xLocal[tid] = xEnd-xStart;
	}
	else
	{ // C = BA

		factor = CACHELINE/sizeof(dataType);
		xTemp1 = m/factor;
		xTemp2 = xTemp1/nthreads;
		xTemp1 = xTemp1 - xTemp2*nthreads;
	    xStart = (tid < xTemp1) ?  (tid*(xTemp2+1)*factor) : (((tid-xTemp1)*xTemp2+xTemp1*(xTemp2+1))*factor);
	    xEnd = ((tid+1) < xTemp1) ?  ((tid+1)*(xTemp2+1)*factor) : (((tid+1-xTemp1)*xTemp2+xTemp1*(xTemp2+1))*factor);

	    xLocal[tid] = xEnd-xStart;

	}
  }
#else
  xStart = 0;
  xEnd = (flagSideIsL) ? n : m;
  xLocal[0] = xEnd-xStart;
#endif

  // get parameters
  mLocal = m;
  nLocal = n;
  sideLocal = side;
  uploLocal = uplo;
  alphaLocal = alpha;
  betaLocal = beta;

  ldaLocal = lda;
  ldbLocal = ldb;
  ldcLocal = ldc;

  aLocal = a;
  bLocal = b;
  cLocal = c;

  // data cache invalidate from master core
  CACHE_wbInvAllL1d(CACHE_WAIT);
  CACHE_wbInvAllL2(CACHE_WAIT);
#ifdef _OPENMP
#pragma omp parallel private(tid, xStart) \
	shared(sideLocal, uploLocal, mLocal, nLocal, xLocal, aLocal, bLocal, cLocal, alpha, \
			betaLocal, ldaLocal, ldbLocal, ldcLocal, flagSideIsL)
#endif
  {
    int cnt;
#ifdef _OPENMP
    /* Obtain thread number */
    tid = omp_get_thread_num();
#else
    tid=0;
#endif
    xStart = 0;
    for(cnt = 0; cnt<tid;cnt++) xStart += xLocal[cnt];
    // optimized xsymm

    xsymmSC(sideLocal, uploLocal, (flagSideIsL ? mLocal : xLocal[tid]),
    		(flagSideIsL ? xLocal[tid] : nLocal), alphaLocal, aLocal, ldaLocal,
      		bLocal+(flagSideIsL ? xStart*ldbLocal : xStart), ldbLocal, betaLocal,
      		cLocal+(flagSideIsL ? xStart*ldcLocal : xStart), ldcLocal);
  }


} // xsymm()

/* @} */ /* ingroup */

/* Nothing past this point */
