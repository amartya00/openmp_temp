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
 *  @file   xgemmC66MC.inc
 *  @brief  This file includes multi core xgemm implementation.
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
// and defined in the testXgemm functions
static int mLocal[MAX_NUM_CORES];
static int nLocal, kLocal;
static int ldaLocal, ldbLocal, ldcLocal;
static char transALocal, transBLocal;
static dataType alphaLocal, betaLocal;
static dataType *aLocal, *bLocal, *cLocal;

// ****************************************************************************************
void xgemm(char transa, char transb,
		   int m, int n, int k,
		   dataType alpha, dataType * restrict a, int lda,
           dataType * restrict b, int ldb,
           dataType beta,  dataType * restrict c, int ldc)
{
  int nthreads, tid, mStart, mEnd;
  int cacheSize = CACHELINE/sizeof(dataType);

  // parameter checking
  if((m & (M_KERNEL-1)) != 0)
  {
	System_printf("%s: m (%d) must be a multiple of m_kernel (%d).\n", XGEMM, m, M_KERNEL);
	return;
  }
  if((n & (N_KERNEL-1)) != 0)
  {
	System_printf("%s:n (%d) must be a multiple of n_kernel (%d).\n", XGEMM, n, N_KERNEL);
	return;
  }
  if((m & (cacheSize-1)) != 0)
  {
      System_printf("%s:m (%d) must be a multiple of cache line (%d).\n", XGEMM, m, cacheSize);
	  return;
  }
  if((ldc & (cacheSize-1)) != 0)
  {
      System_printf("%s:ldc (%d) must be a multiple of cache line (%d).\n", XGEMM, ldc, cacheSize);
	  return;
  }
  if(((int) c & (CACHELINE-1)) != 0)
  {
      System_printf("%s:c (%x) must be at a multiple of cache line (%d).\n", XGEMM, c, CACHELINE);
	  return;
  }

#ifdef _OPENMP
  // number of threads
  nthreads = omp_get_max_threads();
#else
  nthreads = 1;
#endif

  // divide A equally across cores
  for(tid=0;tid<nthreads;tid++)
  {
	int mTemp1, mTemp2, factor;
	// individual m made multiple of cacheline size (which also a multiple of m_kernel)
	factor = CACHELINE/sizeof(dataType);
	mTemp1 = m/factor;
	mTemp2 = mTemp1/nthreads;
	mTemp1 = mTemp1 - mTemp2*nthreads;
    mStart = (tid < mTemp1) ?  (tid*(mTemp2+1)*factor) : (((tid-mTemp1)*mTemp2+mTemp1*(mTemp2+1))*factor);
    mEnd = ((tid+1) < mTemp1) ?  ((tid+1)*(mTemp2+1)*factor) : (((tid+1-mTemp1)*mTemp2+mTemp1*(mTemp2+1))*factor);

    mLocal[tid] = mEnd-mStart;

  }

  aLocal = a;
  bLocal = b;
  cLocal = c;
  transALocal = transa;
  transBLocal = transb;
  nLocal = n;
  kLocal = k;
  alphaLocal = alpha;
  betaLocal  = beta;
  ldaLocal = lda;
  ldbLocal = ldb;
  ldcLocal = ldc;

  // data cache invalidate from master core
  CACHE_wbInvAllL1d(CACHE_WAIT);
  CACHE_wbInvAllL2(CACHE_WAIT);
#ifdef _OPENMP
#pragma omp parallel private(tid, mStart) shared(transALocal, transBLocal, mLocal, nLocal, kLocal, aLocal, bLocal, cLocal, alphaLocal, betaLocal, ldaLocal, ldbLocal, ldcLocal)
#endif
  {
    int cnt;
#ifdef _OPENMP
      /* Obtain thread number */
    tid = omp_get_thread_num();
#else
    tid=0;
#endif
    mStart = 0;
    for(cnt = 0; cnt<tid;cnt++) mStart += mLocal[cnt];

    // optimized xgemm
    xgemmSC(transALocal, transBLocal, mLocal[tid], nLocal, kLocal, alphaLocal,
    	    aLocal+(((transALocal == 'N') || (transALocal == 'n')) ? mStart : mStart*ldaLocal),
            ldaLocal, bLocal, ldbLocal, betaLocal, cLocal+mStart, ldcLocal);
  }

} // xgemm()

/* @} */ /* ingroup */

/* Nothing past this point */

