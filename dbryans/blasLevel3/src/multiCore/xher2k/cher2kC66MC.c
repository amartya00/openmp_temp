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
 *  @file   cher2kC66MC.c
 *  @brief  This file contains multi-core cher2k implementation
 *
 */

// include necessary single precision header files
#include "defC66.h"
#include "defCC66.h"
#include "multiCore/xher2k/cher2kC66MC.h"
#include "singleCore/xher2k/cher2kC66SC.h"
#include "singleCore/xgemm/cgemmC66SC.h"

// define necessary single precision maps
#define dataType   complex
#define baseType   real
#define xsyr2k     cher2k
#define xsyr2kSC   cher2kSC
#define xgemmSC    cgemmSC
#define XSYR2K      "CHER2K"
#define M_KERNEL M_KERNEL_C
#define N_KERNEL N_KERNEL_C

#ifdef BETACOMPLEX
#undef BETACOMPLEX
#endif

#ifndef HERMITIAN
#define HERMITIAN
#endif

#include "../xsyr2k/xsyr2kC66MC.inc"

