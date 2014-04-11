#ifndef _MEMORY_H
#define _MEMORY_H

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
 *  @file   memory.h
 *  @brief  Contains interface to various memory functions
 *
 */

/** @defgroup util util  */

/** @ingroup util */
/* @{ */

// **************************************************************************
// the includes
// includes needed for heap/memory allocation
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/cfg/global.h>


//! \brief      allocates memory from specific MSMC heaps for this core
//!
//! \param[in]  size           size of the memory to allocate
//! \param[in]  align          alignment of the allocated memory
//!
//! \return     address of allocated memory
Ptr Memory_allocMSMC(SizeT size, SizeT align);

//! \brief      frees previously allocated memory from specific MSMC heaps for this core
//!
//! \param[in]  block          Pointer of memory block to free
//! \param[in]  size           size of the memory to free
//!
Void Memory_freeMSMC(Ptr block, SizeT size);

#endif  // _MEMORY_H

/* @} */ /* ingroup */

/* Nothing past this point */
