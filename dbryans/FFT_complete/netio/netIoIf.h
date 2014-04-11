#ifndef _NETIOIF_H
#define _NETIOIF_H

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
 *  @file   netIoIf.h
 *  @brief  interface definitions for ethernet I/O based on TFTP protocol
 *
 */

// C++ / C Function Declarations
#ifdef __cplusplus
#define _extern extern "C"
#define _externfar extern "C" far
#else
#define _extern extern
#define _externfar extern far
#endif

//#include <common/types/types.h>

/**
 *  @brief Get a file into local buffer
 *  @param[in] fileName             Filename
 *  @param[out] buf                 Pointer to buffer to put the data
 *  @param[in] bytesToRead          number fo bytes to read
 *
 */
uint_least32_t netIOGetBuf(const uint_least8_t *fileName, uint_least8_t *buf, const int_least32_t bytesToRead);

/**
 *  @brief Put a local buffer into a file
 *  @param[in] fileName             Filename
 *  @param[in] buf                  Pointer to buffer to read the data
 *  @param[in] bytesToRead          number fo bytes to put
 *
 */
uint_least32_t netIOPutBuf(const uint_least8_t *fileName, const uint_least8_t *buf, const int_least32_t bytesToSend);

/**
 *  @brief initialize IO with ip address
 *
 */
void netIOInit(const uint_least8_t *pIpAddr );

/**
 *  @brief close the session
 */
void netIOClose();

#endif // _NETIOIF_H
