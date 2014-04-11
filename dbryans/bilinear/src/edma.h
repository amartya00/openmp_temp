#ifndef _EDMA_H
#define _EDMA_H

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
 *  @file   edma.h
 *  @brief  Contains public interface to edma3 util functions 
 *
 */

/** @defgroup util util  */

/** @ingroup util */
/* @{ */

// **************************************************************************
// the includes
#include <ti/sdo/edma3/drv/sample/bios6_edma3_drv_sample.h>

// **************************************************************************
// the defines; need 2 channels
// 2 EDMA channels; channel 0 for transferring A; channel 1 for B
// 1 linked channel (chennal 2) to be used to link with channel 0 as desired
#define EDMA_CHANNELS 3

//! \brief      initilizes edma transfer for 
//!
EDMA3_DRV_Result edmaInit(void);

//! \brief      waits for completion of edma transfer on given channel
//! \param[in]  chCnt          channel number on which the transfer is initiated
//!
EDMA3_DRV_Result edmaWait4Completion(const int chCnt);

//! \brief      initiates a new transfer
//! \param[in]  dst            destination address
//! \param[in]  src            source address
//! \param[in]  aCnt           number of element (bytes) to transfer in 1st dimension
//! \param[in]  bCnt           number of elements to transfer in 2nd dimension
//! \param[in]  cCnt           number of elements to transfer in 3rd dimension
//! \param[in]  srcBidx        source address increment in bytes for 1st dimension
//! \param[in]  destBidx       destination address increment in bytes for 1st dimension
//! \param[in]  srcCidx        source address increment in bytes for 2nd dimension
//! \param[in]  destCidx       destination address increment in bytes for 2nd dimension
//! \param[in]  chCnt          channel number on which the transfer is to be initiated
//! \param[in]  flagXfer       flag to indicate if a immediate transfer is to be 
//!                            initiated on this channel
EDMA3_DRV_Result edmaInitiateXfer(const void *dst, const void *src, const int aCnt, 
									   const int bCnt, const int cCnt, const int srcBidx, 
									   const int destBidx, const int srcCidx, 
									   const int destCidx, const int chCnt,
									   const int flagXfer);

///! \brief      initilizes closes and releases all edma channels for 
//!
EDMA3_DRV_Result edmaClose(void);

///! \brief     links channel 0 to channel 2
//!
void edmaLinkXfer();

///! \brief     removes link between channel 0 and channel 2
//!
void edmaUnLinkXfer();

#endif  // _EDMA_H

/* @} */ /* ingroup */

/* Nothing past this point */
