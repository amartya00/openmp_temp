#ifndef _DEFD_C66_H
#define _DEFD_C66_H

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
 *  @file   defDC66.h
 *  @brief  Contains definitions for double precision
 *
*/

/** @defgroup kernel kernel  */

/** @ingroup kernel */
/* @{ */

/**
 * @brief number of rows to process by core kernel for double precision
 */
#define M_KERNEL_D 4
/**
 * @brief number of columns to process by core kernel for double precision
 */
#define N_KERNEL_D 4

/**
 *  @brief partition in k dimension for double precision
 */
#define KPARTITION_D 256
/**
 *  @brief number of panels of A to keep in MCMS/L2 for double precision
 */
#define NUMAPANELS_D 32
/**
 *  @brief number of panels of B to keep in MCMS for double precision
 */
#define NUMBPANELS_D 8

/**
 *  @brief partition in m dimension for double precision  (MPARTITION_D <= KPARTITION_D)
 */
#define MPARTITION_D (NUMAPANELS_D*M_KERNEL_D)
/**
 *  @brief partition in n dimension for double precision
 */
#define NPARTITION_D (NUMBPANELS_D*N_KERNEL_D)

#endif // _DEFD_C66_H

/* @} */ /* ingroup */

/* Nothing past this point */
