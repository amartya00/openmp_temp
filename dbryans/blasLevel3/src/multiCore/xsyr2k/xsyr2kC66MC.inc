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
 *  @file   xsyr2kC66MC.inc
 *  @brief  This file includes multi core xsyr2k implementation.
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

#include "math.h"
// These variables are made global and static
// These variables shared by OMP threads across cores
// and defined in the testSymm functions
static int mLocal[MAX_NUM_CORES];
static int nLocal, kLocal;
static int ldaLocal, ldbLocal, ldcLocal;
static int flagUploIsL, flagTranIsN;
static char transLocal, transRLocal, uploLocal;
static dataType alphaLocal;
#ifdef BETACOMPLEX
static dataType betaLocal;
#else
static baseType betaLocal;
#endif
static dataType *aLocal, *bLocal, *cLocal;

// ****************************************************************************************
void xsyr2k(char uplo, char trans,
		   int n, int k,
		   dataType alpha, dataType *a, int lda,
		   dataType *b,
		   int ldb,
#ifdef BETACOMPLEX
		   dataType beta,
#else
		   baseType beta,
#endif
		   dataType *c, int ldc)
{
  int nthreads, tid, mStart, mEnd;
  int cacheSize = CACHELINE/sizeof(dataType);
#ifdef _OPENMP
  int factor;
  double area, mTemp1, mTemp2;
#endif

  // parameter checking
  if((n & (cacheSize-1)) != 0)
  {
      System_printf("%s:n (%d) must be a multiple of cache line (%d). Skipping test\n", XSYR2K, n, cacheSize);
	  return;
  }
  if((ldc & (cacheSize-1)) != 0)
  {
      System_printf("%s:ldc (%d) must be a multiple of cache line (%d).\n", XSYR2K, ldc, cacheSize);
	  return;
  }
  if(((int) c & (CACHELINE-1)) != 0)
  {
      System_printf("%s:c (%x) must be at a multiple of cache line (%d).\n", XSYR2K, c, CACHELINE);
	  return;
  }

  flagUploIsL = ((uplo == 'L') || (uplo == 'l')) ? 1 : 0;

  if((trans == 'N') || (trans == 'n'))
  {
	flagTranIsN = 1;
#ifdef HERMITIAN
	transRLocal = 'C';
#else
	transRLocal = 'T';
#endif
  }
  else
  {
	flagTranIsN = 0;
	transRLocal = 'N';
  }

#ifdef _OPENMP
  // number of threads
  nthreads = omp_get_max_threads();
#else
  nthreads = 1;
#endif

#ifdef _OPENMP
  factor = CACHELINE/sizeof(dataType);
  // total area to distribute equally
  area = (double) (n/factor)*(n/factor);
  area = area/((double) nthreads);
  mTemp1 = (double) 0.0;
  mStart = 0;
  // divide C equally across cores based on areas assigned to each core
  for(tid=0;tid<nthreads;tid++)
  {
    mTemp2 = sqrt(area + mTemp1*mTemp1) - mTemp1;
    mTemp1 = mTemp2 + mTemp1;
    mLocal[tid] = ((int) (mTemp2+0.5))*factor;
    mStart += mLocal[tid];
  }
  // now adjust so that sum equals n
  mEnd = n-mStart;
  mStart = 0;
  if(mEnd < 0)
  {
    while(mEnd != 0)
    {
      if(mLocal[mStart] > 0) mLocal[mStart] -= factor;
      mStart++;
      mEnd += factor;
      if(mStart >= nthreads) mStart = 0;
    }
  }
  else if (mEnd > 0)
  {
	while(mEnd != 0)
	{
	   mLocal[mStart++] += factor;
	   mEnd -= factor;
       if(mStart >= nthreads) mStart = 0;
	}
  }

  // reverse allocated rows for uplo=u
  if(flagUploIsL == 0)
  {
	for(tid=0;tid<nthreads/2;tid++)
	{
	  mStart = mLocal[tid];
	  mLocal[tid] = mLocal[nthreads-1-tid];
	  mLocal[nthreads-1-tid] = mStart;
	}
  }
  // divide C equally across cores
  /*for(tid=0;tid<nthreads;tid++)
  {
	int mTemp1, mTemp2, factor;
	factor = CACHELINE/sizeof(dataType);
	mTemp1 = n/factor;
	mTemp2 = mTemp1/nthreads;
	mTemp1 = mTemp1 - mTemp2*nthreads;
    mStart = (tid < mTemp1) ?  (tid*(mTemp2+1)*factor) : (((tid-mTemp1)*mTemp2+mTemp1*(mTemp2+1))*factor);
    mEnd = ((tid+1) < mTemp1) ?  ((tid+1)*(mTemp2+1)*factor) : (((tid+1-mTemp1)*mTemp2+mTemp1*(mTemp2+1))*factor);

    mLocal[tid] = mEnd-mStart;
  }*/
#else
  mStart = 0;
  mEnd = n;
  mLocal[0] = mEnd-mStart;
#endif

  // get parameters
  nLocal = n;
  kLocal = k;
  transLocal = trans;
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
#pragma omp parallel private(tid, mStart) \
	shared(uploLocal, transLocal, transRLocal, mLocal, nLocal, kLocal, aLocal, bLocal, cLocal, \
			alphaLocal, betaLocal, ldaLocal, ldcLocal, flagUploIsL, flagTranIsN)
#endif
  {
    int cnt, nStart, nLen;
    dataType betaN, alphaN;

#ifdef _OPENMP
    /* Obtain thread number */
    tid = omp_get_thread_num();
#else
    tid=0;
#endif
    mStart = 0;
    for(cnt = 0; cnt<tid;cnt++) mStart += mLocal[cnt];

    nStart = (flagUploIsL ? 0 : mStart+mLocal[tid]);
    nLen = (flagUploIsL ? mStart : nLocal-mStart-mLocal[tid]);

    // first do optimized gemm
#ifdef HERMITIAN
    betaN.r = betaLocal;
    betaN.i = (baseType) 0.0;
#else
    betaN = betaLocal;
#endif
    alphaN = alphaLocal;
    // first run xgemms on non-diagonal block
    xgemmSC(transLocal, transRLocal, mLocal[tid], nLen, kLocal, alphaN,
    		aLocal+(flagTranIsN ? mStart :  mStart*ldaLocal),
    		ldaLocal,
    		bLocal+(flagTranIsN ? nStart :  nStart*ldaLocal),
    		ldaLocal, betaN,
    		cLocal+(mStart + nStart*ldcLocal),
    		ldcLocal);
#ifdef HERMITIAN
    alphaN.i = -alphaN.i;
    betaN.r = (baseType) 1.0;
    betaN.i = (baseType) 0.0;
#else
#ifdef BETACOMPLEX
    betaN.r = (baseType) 1.0;
    betaN.i = (baseType) 0.0;
#else
    betaN = (baseType) 1.0;
#endif
#endif
    xgemmSC(transLocal, transRLocal, mLocal[tid], nLen, kLocal, alphaN,
    		bLocal+(flagTranIsN ? mStart :  mStart*ldaLocal),
    		ldaLocal,
    		aLocal+(flagTranIsN ? nStart :  nStart*ldaLocal),
    		ldaLocal, betaN,
    		cLocal+(mStart + nStart*ldcLocal),
    		ldcLocal);
    // optimized xsyr2k on diagonal block
    xsyr2kSC(uploLocal, transLocal, mLocal[tid], kLocal, alphaLocal,
    		aLocal+(flagTranIsN ? mStart :  mStart*ldaLocal),
    		ldaLocal,
    		bLocal+(flagTranIsN ? mStart :  mStart*ldbLocal),
    		ldbLocal, betaLocal,
    		cLocal+mStart+mStart*ldcLocal,
    		ldcLocal);
  }

} // xsyr2k()

/* @} */ /* ingroup */

/* Nothing past this point */

