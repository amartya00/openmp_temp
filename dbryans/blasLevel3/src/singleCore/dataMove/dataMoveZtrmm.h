#ifndef _DATAMOVEZTRMM_H
#define _DATAMOVEZTRMM_H

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
 *  @file   dataMoveZtrmm.h
 *  @brief  This file contains definitions of various data movement functions needed for ZTRMM
 *
 */

#include "defC66.h"

/** @defgroup dataMove dataMove  */

/** @ingroup dataMove */
/* @{ */

/**
 *  @brief zero out lower part of A moved to internal memory (size MPARTITION by KPARTITION)
 *         for upper triangular A. This function also sets diagonal elements to unity if
 *         necessary. This function is used to properly properly arrange A in L2 memory
 *         for upper triangular A when C is calculated.
 *
 *  @param[in, out]  ptrA       pointer to A
 *  @param[in]  kLoc            location of start of triangular part;
 *                              zero means upper left; positive value shows offset on the upper side
 *                              negative value indicate offset on the left side
 *  @param[in]  mCnt            number of rows in A
 *  @param[in]  kCnt            number of columns in A
 *  @param[in]  flagDiagisU     flag to indicate if A is unit triangular or not
 *
 */
void arrangeDataUAZtrmm(doublecomplex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU);

/**
 *  @brief zero out lower part of A moved to internal memory (size KPARTITION by MPARTITION)
 *         for lower triangular A. This function also sets diagonal elements to unity if
 *         necessary. This function is used to properly properly arrange A in L2 memory
 *         for lower triangular A when the transpose of C is calculated.
 *
 *  @param[in, out]  ptrA       pointer to A
 *  @param[in]  kLoc            location of start of triangular part;
 *                              zero means upper left; positive value shows offset on the upper side
 *                              negative value indicate offset on the left side
 *  @param[in]  mCnt            number of rows in A
 *  @param[in]  kCnt            number of columns in A
 *  @param[in]  flagDiagisU     flag to indicate if A is unit triangular or not
 *
 */
void arrangeDataLTAZtrmm(doublecomplex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU);

/**
 *  @brief zero out lower part of A moved to internal memory (size MPARTITION by KPARTITION)
 *         for lower triangular A. This function also sets diagonal elements to unity if
 *         necessary. This function is used to properly properly arrange A in L2 memory
 *         for lower triangular A when C is calculated.
 *
 *  @param[in, out]  ptrA       pointer to A
 *  @param[in]  kLoc            location of start of triangular part;
 *                              zero means upper left; positive value shows offset on the upper side
 *                              negative value indicate offset on the left side
 *  @param[in]  mCnt            number of rows in A
 *  @param[in]  kCnt            number of columns in A
 *  @param[in]  flagDiagisU     flag to indicate if A is unit triangular or not
 *
 */
void arrangeDataLAZtrmm(doublecomplex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU);

/**
 *  @brief zero out lower part of A moved to internal memory (size MPARTITION by KPARTITION)
 *         for upper triangular A. This function also sets diagonal elements to unity if
 *         necessary. This function is used to properly properly arrange A in L2 memory
 *         for upper triangular A when the transpose of C is calculated.
 *
 *  @param[in, out]  ptrA       pointer to A
 *  @param[in]  kLoc            location of start of triangular part;
 *                              zero means upper left; positive value shows offset on the upper side
 *                              negative value indicate offset on the left side
 *  @param[in]  mCnt            number of rows in A
 *  @param[in]  kCnt            number of columns in A
 *  @param[in]  flagDiagisU     flag to indicate if A is unit triangular or not
 *
 */
void arrangeDataUTAZtrmm(doublecomplex * restrict ptrA, int kLoc, int mCnt, int kCnt, int flagDiagisU);

#endif // _DATAMOVEZTRMM_H


/* @} */ /* ingroup */

/* Nothing past this point */
