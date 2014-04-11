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

#include "stdlib.h"
#include "string.h"

#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/Thread.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IHeap.h>

#include <xdc/cfg/global.h>

#include <ti/csl/csl_cacheAux.h>

#ifdef _OPENMP
#include <ti/omp/omp.h>
#include <ti/omp/libgomp_g.h>
#endif

#ifndef _OPENMP
static String mainStart = "testLoop";
#endif

#include "util/gen_twiddle_fftf.h"

#include "fft1D_mc.h"
#include "fft2D_mc.h"

#include "util/edma.h"

#ifdef PROFILE_CYCLES
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>
#endif

#define MAX_CHAR_LEN 100
#define CACHELINE 128

#ifdef NETIO
#include <xdc/runtime/knl/Thread.h>
#include <xdc/runtime/Error.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <xdc/runtime/Error.h>
#include "c6x.h"

#include "../../netio/netIoIf.h"
#include "../../netio/netStaticIp.h"

Semaphore_Handle gSemNetIfSync;
#endif

/**
 * @brief number of threads to run
 */
#define NUM_THREADS   8

// @brief test parameter
typedef struct _paramsTEST_ {
	/// input filename
	char fileName[MAX_CHAR_LEN];
	/// first data buffer
	Complex_t *data1;
	/// second data buffer
	Complex_t *data2;
	/// corresponding parameter structure will go here
	void *params;
} ParamsTest_t;

// @brief read parameters
void readAPIparams(FILE *pFid, char *testName, ParamsTest_t * para);
void readInput(char * fileName, char * data, int dataLen);
void writeOutput(char * fileName, char * data, int dataLen);

// ****************************************************************************************
#ifdef _OPENMP
void main(int argc, char *argv[])
#else
void testLoop(void)
#endif
{
  FILE *fpTestList, *fpTest;
  char *pSLine;
  char *pParamStr;
  char *testName;
  char *fileName;

  int nthreads;
  ParamsTest_t params;
  fft1Dstruct_t para1D;
  fft2Dstruct_t para2D;

  pSLine = (char *) Memory_alloc((IHeap_Handle) dataHeap, MAX_CHAR_LEN, 1, NULL);
  pParamStr = (char *) Memory_alloc((IHeap_Handle) dataHeap, MAX_CHAR_LEN, 1, NULL);
  testName = (char *) Memory_alloc((IHeap_Handle) dataHeap, MAX_CHAR_LEN, 1, NULL);
  fileName = (char *) Memory_alloc((IHeap_Handle) dataHeap, MAX_CHAR_LEN, 1, NULL);

#ifdef NETIO
	extern int netStart();
    Task_Handle task;
    Task_Params task_params;
    Error_Block eb;
    Semaphore_Params semParams;
#endif

#ifdef PROFILE_CYCLES
  Types_Timestamp64 timeIn, timeOut;
#endif

#ifdef NETIO
	  // Create a Semaphore to signal completion of NDK initialization
	  Semaphore_Params_init(&semParams);
	  semParams.mode = Semaphore_Mode_BINARY;

	  gSemNetIfSync = Semaphore_create(0, &semParams, NULL);

	  if (DNUM == 0) {
        Error_init(&eb);
        Task_Params_init(&task_params);
        task_params.priority = 5;
        task = Task_create((ti_sysbios_knl_Task_FuncPtr)netStart, &task_params, &eb);
        if (task == NULL) {
            System_printf("Task_create() failed!\n");
            return;
        }
    }

  Semaphore_pend(gSemNetIfSync, BIOS_WAIT_FOREVER);
  netIOInit((uint_least8_t *) PCSTATIC_IP_ADDRESS);
#endif

  EDMA3_DRV_Result edmaResult;
  // initialize EDMA
  edmaResult = edmaInit();
  if(edmaResult != EDMA3_DRV_SOK)
  {
	System_printf("Failed to allocate DMA resources\n");
	System_abort("\n");
  }

  // test list file
  fpTestList = fopen("..\\..\\..\\fft_test_param.txt","rt");

  if(fpTestList == NULL)
  {
	System_printf("Cannot open input test list file");
	System_abort("\n");
  }

  fgets(pSLine, MAX_CHAR_LEN, fpTestList);
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
#pragma omp parallel // dummy thread creation;
  {
	  int tid;
	  tid = omp_get_thread_num();
  }
#endif

  // loop over test cases defined
  while (! feof(fpTestList)) // for all listed in test list file
  {

	// open the list of tests
	fscanf(fpTestList,"%s\n",testName);
	System_printf("\nCurrently testing case: %s\n", testName);
	System_flush();
	sprintf(fileName,"../../../params/%s_param.txt",testName);
	// now open the individual test list
	fpTest = fopen(fileName,"rt");
	if(fpTest == NULL)
	{
	  System_printf("Cannot open input test file: %s; skipping test....\n", fileName);
	  continue;
	}

	memset(&params, 0, sizeof(ParamsTest_t));

    if (strncmp(testName,"fft1d",strlen("fft1d")) == 0)
    {
      params.params = (void *) &para1D;
      // read parameters
      readAPIparams(fpTest, testName, &params);
  	  // allocate memory
      params.data1 = (Complex_t *) Memory_alloc((IHeap_Handle) dataHeap, para1D.N * para1D.NLines * sizeof(Complex_t), CACHELINE, NULL);
      params.data2 = (Complex_t *) Memory_alloc((IHeap_Handle) dataHeap, para1D.N * para1D.NLines * sizeof(Complex_t), CACHELINE, NULL);
      para1D.pTwiddle = (Complex_t *) Memory_alloc((IHeap_Handle) dataHeap, 2 * para1D.N * sizeof(Complex_t), CACHELINE, NULL);


      readInput(params.fileName, (char *) params.data1, para1D.N * para1D.NLines * sizeof(Complex_t));

	  gen_twiddle_fftSP((float *) para1D.pTwiddle, para1D.N);
	  // make data available to DDR3 memory
      CACHE_wbInvAllL1d(CACHE_WAIT);
	  CACHE_wbInvAllL2(CACHE_WAIT);
#ifdef PROFILE_CYCLES
      Timestamp_get64(&timeIn);
#endif
      fft_1D_mc(params.data1, params.data2, (fft1Dstruct_t *) params.params);
#ifdef PROFILE_CYCLES
      Timestamp_get64(&timeOut);
#endif

	  // make data available to DDR3 memory
      CACHE_wbInvAllL1d(CACHE_WAIT);
	  CACHE_wbInvAllL2(CACHE_WAIT);
	  writeOutput(params.fileName, (char *) params.data2, para1D.N * para1D.NLines * sizeof(Complex_t));

	  Memory_free((IHeap_Handle) dataHeap, para1D.pTwiddle, 2 * para1D.N * sizeof(Complex_t));
	  Memory_free((IHeap_Handle) dataHeap, params.data2, para1D.N * para1D.NLines * sizeof(Complex_t));
	  Memory_free((IHeap_Handle) dataHeap, params.data1, para1D.N * para1D.NLines * sizeof(Complex_t));
   }
    else if (strncmp(testName,"fft2d",strlen("fft2d")) == 0)
    {
      params.params = (void *) &para2D;
      // read parameters
      readAPIparams(fpTest, testName, &params);
      params.data1 = (Complex_t *) Memory_alloc((IHeap_Handle) dataHeap, para2D.Nx * para2D.Ny * sizeof(Complex_t), CACHELINE, NULL);
      params.data2 = (Complex_t *) Memory_alloc((IHeap_Handle) dataHeap, para2D.Nx * para2D.Ny * sizeof(Complex_t), CACHELINE, NULL);
      para2D.xTwiddle = (Complex_t *) Memory_alloc((IHeap_Handle) dataHeap, 2 * para2D.Nx * sizeof(Complex_t), CACHELINE, NULL);
      para2D.yTwiddle = (Complex_t *) Memory_alloc((IHeap_Handle) dataHeap, 2 * para2D.Ny * sizeof(Complex_t), CACHELINE, NULL);

      readInput(params.fileName, (char *) params.data1, para2D.Nx * para2D.Ny * sizeof(Complex_t));

	  gen_twiddle_fftSP((float *) para2D.xTwiddle, para2D.Nx);
	  gen_twiddle_fftSP((float *) para2D.yTwiddle, para2D.Ny);

	  // make data available to DDR3 memory
      CACHE_wbInvAllL1d(CACHE_WAIT);
	  CACHE_wbInvAllL2(CACHE_WAIT);
#ifdef PROFILE_CYCLES
    Timestamp_get64(&timeIn);
#endif
      // output will be overwritten in data1, data2 is used as scratch pad buffer
      fft_2D_mc(params.data1, params.data2, (fft2Dstruct_t *) params.params);
#ifdef PROFILE_CYCLES
      Timestamp_get64(&timeOut);
#endif

	  // make data available to DDR3 memory
      CACHE_wbInvAllL1d(CACHE_WAIT);
	  CACHE_wbInvAllL2(CACHE_WAIT);
	  writeOutput(params.fileName, (char *) params.data1, para2D.Nx * para2D.Ny * sizeof(Complex_t));

	  Memory_free((IHeap_Handle) dataHeap, para2D.yTwiddle, 2 * para2D.Ny * sizeof(Complex_t));
	  Memory_free((IHeap_Handle) dataHeap, para2D.xTwiddle, 2 * para2D.Nx * sizeof(Complex_t));
	  Memory_free((IHeap_Handle) dataHeap, params.data2, para2D.Nx * para2D.Ny * sizeof(Complex_t));
	  Memory_free((IHeap_Handle) dataHeap, params.data1, para2D.Nx * para2D.Ny * sizeof(Complex_t));
    }
    else
    {
      continue;
    }
#ifdef PROFILE_CYCLES
      System_printf("cycle count = %ld\n", ((long) _itoll(timeOut.hi, timeOut.lo) - (long) _itoll(timeIn.hi, timeIn.lo)));
#endif
	fclose(fpTest);
  }
  fclose(fpTestList);

  edmaClose();

  Memory_free((IHeap_Handle) dataHeap, fileName, MAX_CHAR_LEN);
  Memory_free((IHeap_Handle) dataHeap, testName, MAX_CHAR_LEN);
  Memory_free((IHeap_Handle) dataHeap, pParamStr, MAX_CHAR_LEN);
  Memory_free((IHeap_Handle) dataHeap, pSLine, MAX_CHAR_LEN);

  System_printf("Test End\n\n");
#ifndef _OPENMP
  BIOS_exit(0);
#endif
} // main()

#ifndef _OPENMP
// ****************************************************************************************
// start BIOS manually for non OPENMP mode
Void main(Int argc, String argv[])
{
  Thread_Params threadParams;

  // start main test thread
  Thread_Params_init(&threadParams);
  threadParams.stackSize = 4096;
  threadParams.instance->name = mainStart;
  threadParams.priority = xdc_runtime_knl_Thread_Priority_BELOW_NORMAL;
  if(Thread_create((Thread_RunFxn) testLoop, &threadParams, NULL) == NULL)
  {
    System_abort("main: failed to create MidEnd_control thread.");
  }

  BIOS_start();
}
#endif

// ****************************************************************************************
void readAPIparams(FILE *pFid, char *testName, ParamsTest_t * para)
{
  char *pSLine;
  fft1Dstruct_t *para1D;
  fft2Dstruct_t *para2D;

  pSLine = (char *) Memory_alloc((IHeap_Handle) dataHeap, MAX_CHAR_LEN, 1, NULL);

  memset(pSLine, 0, MAX_CHAR_LEN);

  fgets(pSLine, MAX_CHAR_LEN, pFid);

  if (strncmp(testName,"fft1d",strlen("fft1d")) == 0)
  {
	para1D = (fft1Dstruct_t *) para->params;
	sscanf(pSLine,"%s %d %d",
			para->fileName,
			&para1D->N,
			&para1D->NLines);
  }
  else if (strncmp(testName,"fft2d",strlen("fft2d")) == 0)
  {
	para2D = (fft2Dstruct_t *) para->params;
	sscanf(pSLine,"%s %d %d",
			para->fileName,
			&para2D->Nx,
			&para2D->Ny);
  }
  Memory_free((IHeap_Handle) dataHeap, pSLine, MAX_CHAR_LEN);
}

// ****************************************************************************************
void readInput(char * fileName, char * data, int dataLen)
{
#ifndef NETIO
  FILE *fpData;
#endif
  char *dataFileName;
  dataFileName = (char *) Memory_alloc((IHeap_Handle) dataHeap, MAX_CHAR_LEN, 1, NULL);
  System_printf("Reading input file...\n");
  System_flush();
#ifdef NETIO
  sprintf(dataFileName,"%s%s","vectors/inp/",fileName);
  netIOGetBuf((unsigned char *) dataFileName, (unsigned char *) data, dataLen);
#else
  //read input data from file
  sprintf(dataFileName,"%s%s","../../../vectors/inp/",fileName);
  fpData=fopen(dataFileName, "rb");
  if(fpData==NULL)
  {
	System_printf("reading error!\n");
  }
  fread(data,1,dataLen,fpData);
  fclose(fpData);
#endif
  Memory_free((IHeap_Handle) dataHeap, dataFileName, MAX_CHAR_LEN);
}

// ****************************************************************************************
void writeOutput(char * fileName, char * data, int dataLen)
{
#ifndef NETIO
  FILE *fpData;
#endif
  char *dataFileName;
  dataFileName = (char *) Memory_alloc((IHeap_Handle) dataHeap, MAX_CHAR_LEN, 1, NULL);
  System_printf("Writing output to file...\n");
  System_flush();
#ifdef NETIO
  sprintf(dataFileName,"%s%s","vectors/out/",fileName);
  netIOPutBuf((unsigned char *) dataFileName, (unsigned char *) data, dataLen);
#else
  //print out result for validation
  sprintf(dataFileName,"%s%s","../../../vectors/out/",fileName);
  fpData=fopen(dataFileName, "wb");
  if(fpData==NULL)
  {
	System_printf("writing error!\n");
  }
  fwrite(data,1,dataLen,fpData);
  fclose(fpData);
#endif
  Memory_free((IHeap_Handle) dataHeap, dataFileName, MAX_CHAR_LEN);
}
