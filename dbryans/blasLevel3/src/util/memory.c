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
 *  @file   memory.c
 *  @brief  implementation of various memory functions
 *
 */

#include "c6x.h"
#include "memory.h"
#ifdef _OPENMP
#include <ti/omp/omp.h>
#include <ti/omp/libgomp_g.h>
#endif

Ptr Memory_allocMSMC(SizeT size, SizeT align)
{
  IHeap_Handle heap;
  int coreId;

#ifdef _OPENMP
  coreId = omp_get_thread_num();
#else
  coreId = 0;
#endif

  switch(coreId)
  {
  case 0:
	heap = (IHeap_Handle) msmcHeap0;
	break;
  case 1:
	heap = (IHeap_Handle) msmcHeap1;
	break;
  case 2:
	heap = (IHeap_Handle) msmcHeap2;
	break;
  case 3:
	heap = (IHeap_Handle) msmcHeap3;
	break;
  case 4:
	heap = (IHeap_Handle) msmcHeap4;
	break;
  case 5:
	heap = (IHeap_Handle) msmcHeap5;
	break;
  case 6:
	heap = (IHeap_Handle) msmcHeap6;
	break;
  case 7:
	heap = (IHeap_Handle) msmcHeap7 ;
	break;
  default:
	heap = (IHeap_Handle) msmcHeap0;
	break;
  }
  return Memory_alloc(heap, size, align, NULL);
}

Void Memory_freeMSMC(Ptr block, SizeT size)
{
  IHeap_Handle heap;
  int coreId;

#ifdef _OPENMP
  coreId = omp_get_thread_num();
#else
  coreId = 0;
#endif

  switch(coreId)
  {
  case 0:
	heap = (IHeap_Handle) msmcHeap0;
	break;
  case 1:
	heap = (IHeap_Handle) msmcHeap1;
	break;
  case 2:
	heap = (IHeap_Handle) msmcHeap2;
	break;
  case 3:
	heap = (IHeap_Handle) msmcHeap3;
	break;
  case 4:
	heap = (IHeap_Handle) msmcHeap4;
	break;
  case 5:
	heap = (IHeap_Handle) msmcHeap5;
	break;
  case 6:
	heap = (IHeap_Handle) msmcHeap6;
	break;
  case 7:
	heap = (IHeap_Handle) msmcHeap7 ;
	break;
  default:
	heap = (IHeap_Handle) msmcHeap0;
	break;
  }
  Memory_free(heap, block, size);

}

