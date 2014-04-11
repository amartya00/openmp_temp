#ifndef _DEF_C66_H
#define _DEF_C66_H

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
 *  @file   defC66.h
 *  @brief  Contains some generic definitions used across BLAS APIs 
 *
*/

/** @defgroup c66params c66params */

/** @ingroup c66params */
/* @{ */

#ifndef FLA_F2C_INCLUDED
/** 
 * @brief define real as float.
 */
typedef float real;
/**
 * @brief define complex.
 */
typedef struct { real r, i; } complex;
/**
 * @brief define double complex.
 */
typedef struct { double r, i; } doublecomplex;
#endif

/**
 * @brief DDR cache alignment
 */
#define CACHELINE 128

/**
 * @brief maximum DMA stride
 */
#define MAXDMASTRIDE 0x7FFF

/**
 * @brief buffer alignment
 */
#define BUFALIGN    8

#define MAX_NUM_CORES 8

#endif // _DEF_C66_H

/* @} */ /* ingroup */

/* Nothing past this point */

