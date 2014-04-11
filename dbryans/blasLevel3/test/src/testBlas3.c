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
 *  @file   testBlas3.c
 *  @brief  Test bench. This is used to test BLAS Level 3 API
 *
 */

#include "string.h"
#include <ti/sysbios/BIOS.h>

#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/Thread.h>

#ifdef _OPENMP
#include <ti/omp/omp.h>
#include <ti/omp/libgomp_g.h>
#endif

#ifndef _OPENMP
static String mainStart = "testLoop";
#endif

#include "defC66.h"
#include "paramBlas3.h"
#include "xgemm/testSgemm.h"
#include "xgemm/testDgemm.h"
#include "xgemm/testCgemm.h"
#include "xgemm/testZgemm.h"

#include "xsymm/testSsymm.h"
#include "xsymm/testDsymm.h"
#include "xsymm/testCsymm.h"
#include "xsymm/testZsymm.h"

#include "xhemm/testChemm.h"
#include "xhemm/testZhemm.h"

#include "xsyrk/testSsyrk.h"
#include "xsyrk/testDsyrk.h"
#include "xsyrk/testCsyrk.h"
#include "xsyrk/testZsyrk.h"

#include "xherk/testCherk.h"
#include "xherk/testZherk.h"

#include "xsyr2k/testSsyr2k.h"
#include "xsyr2k/testDsyr2k.h"
#include "xsyr2k/testCsyr2k.h"
#include "xsyr2k/testZsyr2k.h"

#include "xher2k/testCher2k.h"
#include "xher2k/testZher2k.h"

#include "xtrmm/testStrmm.h"
#include "xtrmm/testDtrmm.h"
#include "xtrmm/testCtrmm.h"
#include "xtrmm/testZtrmm.h"

#include "xtrsm/testStrsm.h"
#include "xtrsm/testDtrsm.h"
#include "xtrsm/testCtrsm.h"
#include "xtrsm/testZtrsm.h"

#include "../../src/util/edma.h"

char testName[100], fileName[100];

/**
 * @brief number of threads to run
 */
#define NUM_THREADS   8

// @brief Scratch memory for storing line from parameter file
char sLineTest[MAX_LINE_LEN];
// @brief Scratch memory for storing name
char paramStTest[MAX_LINE_LEN];

// ****************************************************************************************
#ifdef _OPENMP
void main(int argc, char *argv[])
#else
void testLoop(void)
#endif
{
  FILE *fpTestList, *fpTestOut, *fpTest;
  char *pSLine = &sLineTest[0];
  char *pParamStr = &paramStTest[0];
  int nthreads;
  ParamsBlas3_t params;

#if defined(DMA_COPYA) || defined(DMA_COPYB)
  EDMA3_DRV_Result edmaResult;
  // initialize EDMA
  edmaResult = edmaInit();
  if(edmaResult != EDMA3_DRV_SOK)
  {
	System_printf("Failed to allocate DMA resources\n");
	System_abort("\n");
  }
#endif

  // test list file
#ifdef VERIFICATION
#ifdef _OPENMP
  fpTestList = fopen("..\\..\\..\\blas3_param_verification_omp.txt","rt");
#else
  fpTestList = fopen("..\\..\\..\\blas3_param_verification.txt","rt");
#endif
#else
#ifdef _OPENMP
  fpTestList = fopen("..\\..\\..\\blas3_param_performance_omp.txt","rt");
#else
  fpTestList = fopen("..\\..\\..\\blas3_param_performance.txt","rt");
#endif
#endif
  if(fpTestList == NULL)
  {
	System_printf("Cannot open input test list file");
	System_abort("\n");
  }

  fgets(pSLine, MAX_LINE_LEN, fpTestList);
  sscanf(pSLine,"%s",pParamStr);
  if(strcmp(pParamStr,"nthreads") == 0)
  { // first line is nthreads indicating number of threads
	sscanf(pSLine,"%s %d", pParamStr, &nthreads);
  }
  else
  { // nthreads not defined in file
	nthreads = NUM_THREADS;
    rewind(fpTestList);
  }

#ifdef _OPENMP
  omp_set_num_threads(nthreads);
#endif

  // loop over test cases defined
  while (! feof(fpTestList)) // for all listed in test list file
  {

	// open the list of tests
	fscanf(fpTestList,"%s\n",testName);
	sprintf(fileName,"..\\..\\..\\params\\blas3_param_%s.txt",testName);
	// now open the individual test list
	fpTest = fopen(fileName,"rt");
	if(fpTest == NULL)
	{
	  System_printf("Cannot open input test file: %s; skipping test....\n", fileName);
	  continue;
	}
	sprintf(fileName,"..\\..\\..\\params\\blas3_results_%s.txt",testName);
	fpTestOut = fopen(fileName,"wt");
	if(fpTestOut == NULL)
	{
	  System_printf("Cannot open output file: %s; skipping test....\n", fileName);
	  continue;
	}
	while (! feof(fpTest)) // for all listed in test list file
	{
	  double gFlops, err;

      readAPIparams(fpTest, &params);
      if (strcmp(params.blas3Api,"sgemm") == 0)
      {
        testSgemm(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"dgemm") == 0)
      {
        testDgemm(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"cgemm") == 0)
      {
        testCgemm(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"zgemm") == 0)
      {
        testZgemm(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"ssymm") == 0)
      {
        testSsymm(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"dsymm") == 0)
      {
        testDsymm(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"csymm") == 0)
      {
        testCsymm(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"zsymm") == 0)
      {
        testZsymm(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"chemm") == 0)
      {
        testChemm(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"zhemm") == 0)
      {
        testZhemm(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"ssyrk") == 0)
      {
        testSsyrk(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"dsyrk") == 0)
      {
        testDsyrk(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"csyrk") == 0)
      {
        testCsyrk(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"zsyrk") == 0)
      {
        testZsyrk(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"cherk") == 0)
      {
        testCherk(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"zherk") == 0)
      {
        testZherk(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"ssyr2k") == 0)
      {
        testSsyr2k(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"dsyr2k") == 0)
      {
        testDsyr2k(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"csyr2k") == 0)
      {
        testCsyr2k(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"zsyr2k") == 0)
      {
        testZsyr2k(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"cher2k") == 0)
      {
        testCher2k(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"zher2k") == 0)
      {
        testZher2k(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"strmm") == 0)
      {
        testStrmm(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"dtrmm") == 0)
      {
        testDtrmm(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"ctrmm") == 0)
      {
        testCtrmm(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"ztrmm") == 0)
      {
        testZtrmm(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"strsm") == 0)
      {
        testStrsm(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"dtrsm") == 0)
      {
        testDtrsm(&params, &gFlops, &err);
      }
      else if (strcmp(params.blas3Api,"ctrsm") == 0)
      {
        testCtrsm(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else if (strcmp(params.blas3Api,"ztrsm") == 0)
      {
        testZtrsm(&params, &gFlops, &err);
        gFlops *= 4.0;
      }
      else
      {
    	continue;
      }
#ifdef VERIFICATION
      fprintf(fpTestOut,"%e ", err);
      printf("max abs error = %e\n", err);
#endif
#ifdef PROFILE_CYCLES
      fprintf(fpTestOut,"%f ", gFlops);
      System_printf("GFLOPS (1 GHz core) = %f\n", gFlops);
#endif
      writeAPIparams(fpTestOut, &params);
      fflush(fpTestOut);
	}
	fclose(fpTest);
    fclose(fpTestOut);
  }
  fclose(fpTestList);

#if defined(DMA_COPYA) || defined(DMA_COPYB)
  edmaClose();
#endif
  System_printf("Test End\n\n");
#ifndef _OPENMP
  BIOS_exit(0);
#endif
} // main()

#ifndef _OPENMP

// start BIOS manually for non OPENMP mode
Void main(Int argc, String argv[])
{
  Thread_Params threadParams;

  // start main test thread
  Thread_Params_init(&threadParams);
  threadParams.stackSize = 24 * 1024;
  threadParams.instance->name = mainStart;
  threadParams.priority = xdc_runtime_knl_Thread_Priority_BELOW_NORMAL;
  if(Thread_create((Thread_RunFxn) testLoop, &threadParams, NULL) == NULL)
  {
    System_abort("main: failed to create MidEnd_control thread.");
  }

  BIOS_start();
}

#include <ti/csl/csl_xmcAux.h>
#include <ti/csl/csl_cacheAux.h>
#define MPAX_INDEX 3

// system initialization for non OPENMP case
// initialize L1 cache and non cache MSMCSRAM like opneMP
void initSystem(void)
{
  CSL_XMC_XMPAXH mpaxh;
  CSL_XMC_XMPAXL mpaxl;

  // first set cache size
  CACHE_wbInvAllL1d(CACHE_WAIT);
  CACHE_setL1DSize (CACHE_L1_16KCACHE);

  // now shadow MSMCSRAM
  CSL_XMC_getXMPAXL (MPAX_INDEX, &mpaxl);
  CSL_XMC_getXMPAXH (MPAX_INDEX, &mpaxh);

  mpaxh.segSize = 0x15;
  mpaxh.bAddr = 0xA0000;

  CSL_XMC_setXMPAXH (MPAX_INDEX, &mpaxh);

  mpaxl.ux = 1;
  mpaxl.uw = 1;
  mpaxl.ur = 1;
  mpaxl.sx = 1;
  mpaxl.sw = 1;
  mpaxl.sr = 1;
  mpaxl.rAddr = 0x00C000;

  CSL_XMC_setXMPAXL (MPAX_INDEX, &mpaxl);

}

// define some OMP functions interfaces
// in non-OMP mode
int omp_get_thread_num(void)
{
  return 0;
}

#else

#include <ti/csl/csl_cacheAux.h>

// initialize L1 cache;
void initSystem(void)
{
	  // first set cache size
	  CACHE_wbInvAllL1d(CACHE_WAIT);
	  CACHE_setL1DSize (CACHE_L1_16KCACHE);

}
#endif


