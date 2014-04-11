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

#include "string.h"
#include "edma.h"

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

#define STRUCT_EDMAXFER_LEN (sizeof(unsigned int)+sizeof(unsigned int)+sizeof(EDMA3_DRV_PaRAMRegs))

typedef struct _EdmaXfer_ {
  /// channel Id
  volatile unsigned int chId;
  /// TCC assigned
  volatile unsigned int tcc;
  // param set used for this channel
  volatile EDMA3_DRV_PaRAMRegs paramSet;
  // for cache alignment
  char extra[(CACHELINESIZE*((STRUCT_EDMAXFER_LEN+CACHELINESIZE-1)/CACHELINESIZE))-STRUCT_EDMAXFER_LEN];
} EdmaXfer_t;

#define NUM_CORES 1
#define BASE_CH   32
// globally define this variable for use in this file
#pragma DATA_SECTION(gEdmaXfer, ".dmaMem");
volatile EdmaXfer_t gEdmaXfer[NUM_CORES][EDMA_CHANNELS];

/// edma handle
#pragma DATA_SECTION(gHEdma, ".dmaMem");
volatile EDMA3_DRV_Handle gHEdma[2];

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
    if (edmaResult == EDMA3_DRV_SOK)
    {

      if(chCnt==2)
      {
        // link channel
        gEdmaXfer[coreCnt][chCnt].tcc = EDMA3_DRV_TCC_ANY;
        gEdmaXfer[coreCnt][chCnt].chId = EDMA3_DRV_LINK_CHANNEL;
      }
      else
      {
        // fix channel id and corresponding tcc
        gEdmaXfer[coreCnt][chCnt].tcc = BASE_CH+2*(coreCnt)+chCnt; //EDMA3_DRV_TCC_ANY;
        gEdmaXfer[coreCnt][chCnt].chId = BASE_CH+2*(coreCnt)+chCnt; //EDMA3_DRV_DMA_CHANNEL_ANY;
      }

      // Request any DMA channel and any TCC
      // no callback function is registered, we will be polling
      edmaResult = EDMA3_DRV_requestChannel (gHEdma[coreCnt/4],
                                             (unsigned int *) &gEdmaXfer[coreCnt][chCnt].chId,
                                             (unsigned int *) &gEdmaXfer[coreCnt][chCnt].tcc,
                                             (EDMA3_RM_EventQueue) (coreCnt&3), // separate event queue for each core
                                             NULL, NULL);

      // Fill the PaRAM Set with transfer specific information
      gEdmaXfer[coreCnt][chCnt].paramSet.srcAddr    = (unsigned int) NULL; // dummy
      gEdmaXfer[coreCnt][chCnt]. paramSet.destAddr   = (unsigned int) NULL; // dummy

      gEdmaXfer[coreCnt][chCnt].paramSet.srcBIdx    = 1;
      gEdmaXfer[coreCnt][chCnt].paramSet.destBIdx   = 1;
      gEdmaXfer[coreCnt][chCnt].paramSet.srcCIdx    = 1;
      gEdmaXfer[coreCnt][chCnt].paramSet.destCIdx   = 1;

      gEdmaXfer[coreCnt][chCnt].paramSet.aCnt       = 1;
      gEdmaXfer[coreCnt][chCnt].paramSet.bCnt       = 1;
      gEdmaXfer[coreCnt][chCnt].paramSet.cCnt       = 1;

      // For AB-synchronized transfers, BCNTRLD is not used.
      gEdmaXfer[coreCnt][chCnt].paramSet.bCntReload = 0;

      gEdmaXfer[coreCnt][chCnt].paramSet.linkAddr   = 0xFFFFu;

      // Src & Dest are in INCR modes
      //gEdmaXfer[chCnt].paramSet.opt &= 0xFFFFFFFCu;
      gEdmaXfer[coreCnt][chCnt].paramSet.opt = 0x00000000u;

      // disable intermediate chaining
      gEdmaXfer[coreCnt][0].paramSet.opt &= ~(1 << OPT_ITCCHEN_SHIFT);
      // disable final chaining
      gEdmaXfer[coreCnt][chCnt].paramSet.opt &= ~(1 << OPT_TCCHEN_SHIFT);
      // disable intermediate interrupt
      gEdmaXfer[coreCnt][chCnt].paramSet.opt &= ~(1 << OPT_ITCINTEN_SHIFT);
      // enable final interrupt
      gEdmaXfer[coreCnt][chCnt].paramSet.opt |= (1 << OPT_TCINTEN_SHIFT);
      // set TCC
      gEdmaXfer[coreCnt][chCnt].paramSet.opt |= ((gEdmaXfer[coreCnt][chCnt].tcc << OPT_TCC_SHIFT) & OPT_TCC_MASK);

      // AB Sync Transfer Mode
      gEdmaXfer[coreCnt][chCnt].paramSet.opt |= (1 << OPT_SYNCDIM_SHIFT);
    }
  }
  }

  return(edmaResult);
} // edmaInit()

// **************************************************************************************
EDMA3_DRV_Result edmaInitiateXfer(const void *dst, const void *src, const int aCnt,
                                       const int bCnt, const int cCnt, const int srcBIdx, 
                                       const int destBIdx, const int srcCIdx, 
                                       const int destCIdx, const int chCnt,
                                       const int flagXfer)
{
  EDMA3_DRV_Result edmaResult = EDMA3_DRV_SOK;
  signed char *srcBuf, *dstBuf;
  volatile int coreCnt = determineProcId();

  srcBuf = (signed char*) getGlobalAddr((signed char *) src);
  dstBuf = (signed char*) getGlobalAddr((signed char *) dst);

  // set source address
  if(edmaResult == EDMA3_DRV_SOK)
  {

    gEdmaXfer[coreCnt][chCnt].paramSet.srcAddr  = (unsigned int) srcBuf;
    gEdmaXfer[coreCnt][chCnt].paramSet.destAddr = (unsigned int) dstBuf;
    gEdmaXfer[coreCnt][chCnt].paramSet.aCnt     = aCnt;
    gEdmaXfer[coreCnt][chCnt].paramSet.bCnt     = bCnt;
    gEdmaXfer[coreCnt][chCnt].paramSet.cCnt     = cCnt;
    gEdmaXfer[coreCnt][chCnt].paramSet.srcBIdx  = srcBIdx;
    gEdmaXfer[coreCnt][chCnt].paramSet.destBIdx = destBIdx;
    gEdmaXfer[coreCnt][chCnt].paramSet.srcCIdx  = srcCIdx;
    gEdmaXfer[coreCnt][chCnt].paramSet.destCIdx = destCIdx;
    // prevent a NULL transfer from being submitted; convert it into a dummy transfer
    if((aCnt==0) && (bCnt==0)) gEdmaXfer[coreCnt][chCnt].paramSet.aCnt     = 1;
    /* Now, write the PaRAM Set. */
    edmaResult = EDMA3_DRV_setPaRAM(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][chCnt].chId, (EDMA3_DRV_PaRAMRegs *) &gEdmaXfer[coreCnt][chCnt].paramSet);
  }


  // start transfer
  if(edmaResult == EDMA3_DRV_SOK)
  {
    if(flagXfer)
      {
      edmaResult = EDMA3_DRV_enableTransfer (gHEdma[coreCnt/4],
                                           gEdmaXfer[coreCnt][chCnt].chId,
                                           EDMA3_DRV_TRIG_MODE_MANUAL);
      }
  }      
  return(edmaResult);

} // edmaInitiateXfer

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

void edmaLinkXfer()
{
  volatile int coreCnt = determineProcId();

  // link channel (0 to 2)
  EDMA3_DRV_linkChannel(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][0].chId, gEdmaXfer[coreCnt][2].chId);

  // setup channel 0 params
  EDMA3_DRV_getPaRAM(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][0].chId, (EDMA3_DRV_PaRAMRegs *) &gEdmaXfer[coreCnt][0].paramSet);
  //gEdmaXfer[coreCnt][0].tcc = gEdmaXfer[coreCnt][0].tcc;
  gEdmaXfer[coreCnt][0].paramSet.opt |= ((gEdmaXfer[coreCnt][0].tcc << OPT_TCC_SHIFT) & OPT_TCC_MASK);
  // disable intermediate chain
  gEdmaXfer[coreCnt][0].paramSet.opt &= ~(1 << OPT_ITCCHEN_SHIFT);
  // enable final chain
  gEdmaXfer[coreCnt][0].paramSet.opt |= (1 << OPT_TCCHEN_SHIFT);
  // disable intermediate interrupt
  gEdmaXfer[coreCnt][0].paramSet.opt &= ~(1 << OPT_ITCINTEN_SHIFT);
  // disable final interrupt
  gEdmaXfer[coreCnt][0].paramSet.opt &= ~(1 << OPT_TCINTEN_SHIFT);
  // AB Sync Transfer Mode
  gEdmaXfer[coreCnt][0].paramSet.opt |= (1 << OPT_SYNCDIM_SHIFT);

  // setup channel 2 params
  EDMA3_DRV_getPaRAM(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][2].chId, (EDMA3_DRV_PaRAMRegs *) &gEdmaXfer[coreCnt][2].paramSet);
  gEdmaXfer[coreCnt][2].tcc = gEdmaXfer[coreCnt][0].tcc;
  gEdmaXfer[coreCnt][2].paramSet.opt |= ((gEdmaXfer[coreCnt][0].tcc << OPT_TCC_SHIFT) & OPT_TCC_MASK);
  // disable intermediate chain
  gEdmaXfer[coreCnt][2].paramSet.opt &= ~(1 << OPT_ITCCHEN_SHIFT);
  // disable final chain
  gEdmaXfer[coreCnt][2].paramSet.opt &= ~(1 << OPT_TCCHEN_SHIFT);
  // disable intermediate interrupt
  gEdmaXfer[coreCnt][2].paramSet.opt &= ~(1 << OPT_ITCINTEN_SHIFT);
  // enable final interrupt
  gEdmaXfer[coreCnt][2].paramSet.opt |= (1 << OPT_TCINTEN_SHIFT);
  // AB Sync Transfer Mode
  gEdmaXfer[coreCnt][2].paramSet.opt |= (1 << OPT_SYNCDIM_SHIFT);
  // make it final transfer
  gEdmaXfer[coreCnt][2].paramSet.linkAddr   = 0xFFFFu;

  return;
}

void edmaUnLinkXfer()
{
  volatile int coreCnt = determineProcId();

  // remove link from channel 0
  EDMA3_DRV_unlinkChannel(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][0].chId);

  // reset channel 0 param
  EDMA3_DRV_getPaRAM(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][0].chId, (EDMA3_DRV_PaRAMRegs *) &gEdmaXfer[coreCnt][0].paramSet);
  gEdmaXfer[coreCnt][0].paramSet.opt |= ((gEdmaXfer[coreCnt][0].tcc << OPT_TCC_SHIFT) & OPT_TCC_MASK);
  // disable intermediate chain
  gEdmaXfer[coreCnt][0].paramSet.opt &= ~(1 << OPT_ITCCHEN_SHIFT);
  // disable final chain
  gEdmaXfer[coreCnt][0].paramSet.opt &= ~(1 << OPT_TCCHEN_SHIFT);
  // disable intermediate interrupt
  gEdmaXfer[coreCnt][2].paramSet.opt &= ~(1 << OPT_ITCINTEN_SHIFT);
  // enable final interrupt
  gEdmaXfer[coreCnt][0].paramSet.opt |= (1 << OPT_TCINTEN_SHIFT);
  // AB Sync Transfer Mode
  gEdmaXfer[coreCnt][0].paramSet.opt |= (1 << OPT_SYNCDIM_SHIFT);
  // make it final transfer
  gEdmaXfer[coreCnt][0].paramSet.linkAddr   = 0xFFFFu;

  // reset channel 2 param
  EDMA3_DRV_getPaRAM(gHEdma[coreCnt/4], gEdmaXfer[coreCnt][2].chId, (EDMA3_DRV_PaRAMRegs *) &gEdmaXfer[coreCnt][2].paramSet);
  gEdmaXfer[coreCnt][2].tcc = EDMA3_DRV_TCC_ANY;
  gEdmaXfer[coreCnt][2].paramSet.opt |= ((gEdmaXfer[coreCnt][2].tcc << OPT_TCC_SHIFT) & OPT_TCC_MASK);
  // disable intermediate interrupt
  gEdmaXfer[coreCnt][2].paramSet.opt &= ~(1 << OPT_ITCINTEN_SHIFT);
  // disable final interrupt
  gEdmaXfer[coreCnt][2].paramSet.opt &= ~(1 << OPT_TCINTEN_SHIFT);
  // disable intermediate chain
  gEdmaXfer[coreCnt][2].paramSet.opt &= ~(1 << OPT_ITCCHEN_SHIFT);
  // disable final chain
  gEdmaXfer[coreCnt][2].paramSet.opt &= ~(1 << OPT_TCCHEN_SHIFT);
  // AB Sync Transfer Mode
  gEdmaXfer[coreCnt][2].paramSet.opt |= (1 << OPT_SYNCDIM_SHIFT);

  return;

}
