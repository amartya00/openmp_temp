/**
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
 *  @file   edma.c
 *  @brief  implementation of edma3 util functions 
 *          (adapted from example supplied with EDMA LLD)
 *
 */

#include <xdc/runtime/System.h>
#include <ti/sysbios/family/c66/Cache.h>

#include "string.h"
#include "util/edma.h"

// OPT Field specific defines
#define OPT_SYNCDIM_SHIFT                   (0x00000002u)
#define OPT_STATIC_SHIFT                    (0x00000003u)
#define OPT_TCC_MASK                        (0x0003F000u)
#define OPT_TCC_SHIFT                       (0x0000000Cu)
#define OPT_TCCMODE_SHIFT                   (0x0000000Bu)
#define OPT_ITCCHEN_SHIFT                   (0x00000017u)
#define OPT_TCCHEN_SHIFT                    (0x00000016u)
#define OPT_ITCINTEN_SHIFT                  (0x00000015u)
#define OPT_TCINTEN_SHIFT                   (0x00000014u)

// extern definitions used from EDMA3 LLD
extern signed char*  getGlobalAddr(signed char* addr);
extern unsigned short determineProcId();

#define CACHELINESIZE  (128)

#define STRUCT_EDMAXFER_LEN (sizeof(unsigned int)+sizeof(unsigned int))

typedef struct _EdmaXfer_ {
  /// channel Id
  volatile unsigned int chId;
  /// TCC assigned
  volatile unsigned int tcc;
  // for cache alignment
  char extra[(CACHELINESIZE*((STRUCT_EDMAXFER_LEN+CACHELINESIZE-1)/CACHELINESIZE))-STRUCT_EDMAXFER_LEN];
} EdmaXfer_t;

#define NUM_CORES 8
#define BASE_CH   32
#define MAX_PARAMS 256

// globally define this variable for use in this file
#pragma DATA_SECTION(gEdmaXfer, ".dmaMem");
volatile EdmaXfer_t gEdmaXfer[NUM_CORES][EDMA_CHANNELS];

/// edma handle
#pragma DATA_SECTION(gHEdma, ".dmaMem");
volatile EDMA3_DRV_Handle gHEdma[2];

#pragma DATA_SECTION(globalParamSet, ".dmaParamMem");
#pragma DATA_ALIGN(globalParamSet, CACHELINESIZE);
EDMA3_DRV_PaRAMRegs globalParamSet[NUM_CORES*MAX_PARAMS*EDMA_CHANNELS/2];

// **************************************************************************************
EDMA3_DRV_Result edmaInit(void)
{
  EDMA3_DRV_Result edmaResult = EDMA3_DRV_SOK;
  int chCnt, coreCnt;
  extern EDMA3_DRV_InstanceInitConfig sampleInstInitConfig[][EDMA3_MAX_REGIONS];

  // modify the dma sample configuration so that DSP zero owns
  // channels from 32 to 49
  sampleInstInitConfig[1][0].ownDmaChannels[1]=0xFFFF;
  sampleInstInitConfig[1][0].ownTccs[1]=0xFFFF;
  sampleInstInitConfig[1][0].ownPaRAMSets[1]=0xFFFF;
  sampleInstInitConfig[2][0].ownDmaChannels[1]=0x0FFFF;
  sampleInstInitConfig[2][0].ownTccs[1]=0x0FFFF;
  sampleInstInitConfig[2][0].ownPaRAMSets[1]=0x0FFFF;

  memset(gEdmaXfer, 0, NUM_CORES*EDMA_CHANNELS*sizeof(EdmaXfer_t));

  // use EDMA instance #1
  gHEdma[0] = edma3init(1, &edmaResult);
  gHEdma[1] = edma3init(2, &edmaResult);

  for(coreCnt=0; coreCnt<NUM_CORES;coreCnt++)
  {
    for(chCnt = 0; chCnt < EDMA_CHANNELS; chCnt++) // initialize all channels
    {
      // fix channel id and corresponding tcc
      gEdmaXfer[coreCnt][chCnt].tcc = BASE_CH+EDMA_CHANNELS*(coreCnt&3)+chCnt; //EDMA3_DRV_TCC_ANY;
      gEdmaXfer[coreCnt][chCnt].chId = BASE_CH+EDMA_CHANNELS*(coreCnt&3)+chCnt; //EDMA3_DRV_DMA_CHANNEL_ANY;

      // Request any DMA channel with given TCC and channel
      // no callback function is registered, we will be polling
      edmaResult = EDMA3_DRV_requestChannel (gHEdma[coreCnt/4],
		                                     (unsigned int *) &gEdmaXfer[coreCnt][chCnt].chId,
		                                     (unsigned int *) &gEdmaXfer[coreCnt][chCnt].tcc,
                                             (EDMA3_RM_EventQueue) (coreCnt&3), // separate event queue for each core
                                             NULL, NULL);

      // if failure to allocate, don't continue
      if(edmaResult != EDMA3_DRV_SOK) return(edmaResult);
    }
  }
  return(edmaResult);
} // edmaInit()


// **************************************************************************************
EDMA3_DRV_Result edmaInitiateXfer(const void *dst, const void *src, const int aCnt,
									   const int bCnt, const int cCnt, const int srcBIdx,
									   const int destBIdx, const int srcCIdx,
									   const int destCIdx, const int chCnt)
{
  EDMA3_DRV_Result edmaResult = EDMA3_DRV_SOK;
  signed char *srcBuf, *dstBuf;
  volatile int coreCnt = determineProcId();
  EDMA3_DRV_PaRAMRegs paramSet;

  srcBuf = (signed char*) getGlobalAddr((signed char *) src);
  dstBuf = (signed char*) getGlobalAddr((signed char *) dst);

  paramSet.srcAddr  = (unsigned int) srcBuf;
  paramSet.destAddr = (unsigned int) dstBuf;
  paramSet.aCnt     = aCnt;
  paramSet.bCnt     = bCnt;
  paramSet.cCnt     = cCnt;
  paramSet.srcBIdx  = srcBIdx;
  paramSet.destBIdx = destBIdx;
  paramSet.srcCIdx  = srcCIdx;
  paramSet.destCIdx = destCIdx;
  paramSet.bCntReload = 0;
  paramSet.linkAddr   = 0xFFFFu;
  paramSet.opt = 0x00000000u;
  // enable final interrupt
  paramSet.opt |= (1 << OPT_TCINTEN_SHIFT);
  // set TCC
  paramSet.opt |= ((gEdmaXfer[coreCnt][chCnt].tcc << OPT_TCC_SHIFT) & OPT_TCC_MASK);
  // AB Sync Transfer Mode
  paramSet.opt |= (1 << OPT_SYNCDIM_SHIFT);
  // prevent a NULL transfer from being submitted; convert it into a dummy transfer
  if((aCnt==0) && (bCnt==0)) paramSet.aCnt     = 1;

  /* Now, write the PaRAM Set. */
  edmaResult = EDMA3_DRV_setPaRAM(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][chCnt].chId,
		  (EDMA3_DRV_PaRAMRegs *) &paramSet);

  // start transfer
  if(edmaResult == EDMA3_DRV_SOK)
  {
    edmaResult = EDMA3_DRV_enableTransfer (gHEdma[coreCnt/4], gEdmaXfer[coreCnt][chCnt].chId,
    	    EDMA3_DRV_TRIG_MODE_MANUAL);
  }      
  return(edmaResult);

} // edmaInitiateXfer

// **************************************************************************************
EDMA3_DRV_Result edmaInitiateXferDoubleChain(const void *dst, const void *src, const int aCnt,
									   const int bCnt, const int cCnt, const int srcBIdx,
									   const int destBIdx, const int srcCIdx,
									   const int destCIdx, const int chCnt)
{
  EDMA3_DRV_PaRAMRegs paramSet, *gParamSet;
  uint32_t addr;
  EDMA3_DRV_Result edmaResult = EDMA3_DRV_SOK;
  signed char *srcBuf, *dstBuf;
  volatile int coreCnt = determineProcId();
  int bIndex; //, cIndex;

  if((chCnt<0) || (chCnt>2) || ((chCnt&1) != 0))
  {
	System_printf("DMA channel (%d) not valid", chCnt);
	System_abort("\n");
  }

  if(bCnt * cCnt > MAX_PARAMS-1)
  {
	System_printf("Can't handle bCnt(%d)*cCnt(%); max allowed is %d", bCnt, cCnt, MAX_PARAMS-1);
	System_abort("\n");
  }
  srcBuf = (signed char*) getGlobalAddr((signed char *) src);
  dstBuf = (signed char*) getGlobalAddr((signed char *) dst);

  // set paramSet
  paramSet.srcAddr  = (unsigned int) srcBuf;
  paramSet.destAddr = (unsigned int) dstBuf;
  paramSet.aCnt     = aCnt;
  paramSet.bCnt     = 1;
  paramSet.cCnt     = 1;
  paramSet.srcBIdx  = 0;
  paramSet.destBIdx = 0;
  paramSet.srcCIdx  = 0;
  paramSet.destCIdx = 0;
  paramSet.bCntReload = 0;
  paramSet.linkAddr   = 0xFFFFu;
  paramSet.opt = 0x00000000u;
  // enable final TCC chaining; only one transfer
  paramSet.opt |= (1 << OPT_TCCHEN_SHIFT);
  // set TCC to chained channel
  paramSet.opt |= ((gEdmaXfer[coreCnt][chCnt+1].tcc << OPT_TCC_SHIFT) & OPT_TCC_MASK);

  gParamSet = &globalParamSet[(coreCnt*(EDMA_CHANNELS>>1)+(chCnt>>1))*MAX_PARAMS];
  // now write the paramsets to be used by the first of the doubly chained channels
  for(bIndex = 0; bIndex <= bCnt; bIndex++)
  {
	// table of paramSet
	gParamSet[bIndex] = paramSet;
	// update src and dst address;
	paramSet.srcAddr += srcBIdx;
	paramSet.destAddr += destBIdx;
	if(bIndex == (bCnt-1)) // last in the set
	{
		// set to be a dummy transfer
		paramSet.aCnt = 1;
		paramSet.bCnt = 0;
		paramSet.cCnt = 0;
		// disable chaining
		paramSet.opt &= ~(1 << OPT_TCCHEN_SHIFT);
	}
  }

  // ensure gParamSet is written to cache
  Cache_wbInv(gParamSet, (bCnt+1)*sizeof(EDMA3_DRV_PaRAMRegs), Cache_Type_ALLD, 1);
  // set paramSet; src is global param set; dst is chained PARAMset;
  // src increment is size of PARAMset and dst address is always the same
  paramSet.srcAddr  = (uint32_t) getGlobalAddr((signed char *) &gParamSet[0]);
  EDMA3_DRV_getPaRAMPhyAddr(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][chCnt].chId, &addr);
  paramSet.destAddr = (uint32_t) getGlobalAddr((signed char *) addr);
  paramSet.aCnt     = sizeof(EDMA3_DRV_PaRAMRegs);
  paramSet.bCnt     = bCnt+1;
  paramSet.cCnt     = 1;
  paramSet.srcBIdx  = sizeof(EDMA3_DRV_PaRAMRegs);
  paramSet.destBIdx = 0;
  paramSet.srcCIdx  = 0;
  paramSet.destCIdx = 0;
  paramSet.bCntReload = 0;
  paramSet.linkAddr   = 0xFFFFu;
  paramSet.opt = 0x00000000u;
  // both intermediate and final chaining enabled
  paramSet.opt |= (1 << OPT_TCCHEN_SHIFT);
  paramSet.opt |= (1 << OPT_ITCCHEN_SHIFT);
  // final interrupt enabled
  paramSet.opt |= (1 << OPT_TCINTEN_SHIFT);
  // set TCC to chained channel
  paramSet.opt |= ((gEdmaXfer[coreCnt][chCnt].tcc << OPT_TCC_SHIFT) & OPT_TCC_MASK);

  /* Now, write the PaRAM Set to the second of the doubly chained channels */
  edmaResult = EDMA3_DRV_setPaRAM(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][chCnt+1].chId, (EDMA3_DRV_PaRAMRegs *) &paramSet);


  // start transfer on the second of the doubly chained channels
  if(edmaResult == EDMA3_DRV_SOK)
  {
    edmaResult = EDMA3_DRV_enableTransfer (gHEdma[coreCnt/4],
			                               gEdmaXfer[coreCnt][chCnt+1].chId,
	                                       EDMA3_DRV_TRIG_MODE_MANUAL);
  }
  return(edmaResult);

} // edmaInitiateXferDoubleChain

// ******************************************************************************************
EDMA3_DRV_Result edmaClose(void)
{
  EDMA3_DRV_Result edmaResult = EDMA3_DRV_SOK;
  int chCnt, coreCnt;

  for(coreCnt=0; coreCnt<NUM_CORES;coreCnt++)
  {
  for(chCnt = 0; chCnt < EDMA_CHANNELS; chCnt++)
    {
      // Free the previously allocated channel.
      edmaResult = EDMA3_DRV_freeChannel(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][chCnt].chId);
    }
  }
  // deinit the handle
  edmaResult = edma3deinit(1, gHEdma[0]);
  edmaResult = edma3deinit(2, gHEdma[1]);

  // zero out memory
  memset(gEdmaXfer, 0, NUM_CORES*EDMA_CHANNELS*sizeof(EdmaXfer_t));

  return edmaResult;
} // edmaClose

// ******************************************************************************************
EDMA3_DRV_Result edmaWait4Completion(const int chCnt)
{
  EDMA3_DRV_Result edmaResult = EDMA3_DRV_SOK;
  volatile int coreCnt = determineProcId();
  volatile EdmaXfer_t *pEdmaXfer = (volatile EdmaXfer_t *) &gEdmaXfer[coreCnt][chCnt];

  // wait till DMA completes and clear the
  edmaResult = EDMA3_DRV_waitAndClearTcc(gHEdma[coreCnt/4], pEdmaXfer->chId);
  return edmaResult;

} // edmaWait4Completion
