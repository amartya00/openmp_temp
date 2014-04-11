#ifndef _DEFZ_C66_H
#define _DEFZ_C66_H

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
 *  @file   defCC66.h
 *  @brief  Contains definitions for double precision complex
 *
*/

/** @defgroup kernel kernel  */

/** @ingroup kernel */
/* @{ */

/**
 * @brief number of rows to process by core kernel for double precision complex
 */
#define M_KERNEL_Z 1
/**
 * @brief number of columns to process by core kernel for double precision complex
 */
#define N_KERNEL_Z 1

/**
 *  @brief partition in k dimension for double precision complex
 */
#define KPARTITION_Z 512
/**
 *  @brief number of panels of A to keep in MCMS/L2 for double precision complex
 */
#define NUMAPANELS_Z 32
/**
 *  @brief number of panels of B to keep in MCMS for double precision complex
 */
#define NUMBPANELS_Z 8

/**
 *  @brief partition in m dimension for double precision complex  (MPARTITION_Z <= KPARTITION_Z)
 */
#define MPARTITION_Z (NUMAPANELS_Z*M_KERNEL_Z)
/**
 *  @brief partition in n dimension for double precision complex
 */
#define NPARTITION_Z (NUMBPANELS_Z*N_KERNEL_Z)

#endif // _DEFZ_C66_H

/* @} */ /* ingroup */

/* Nothing past this point */
