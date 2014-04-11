/* Copyright (C) 2005, 2009 Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@redhat.com>.

   This file is part of the GNU OpenMP Library (libgomp).

   Libgomp is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

/* This file contains wrappers for the system allocation routines.  Most
   places in the OpenMP API do not make any provision for failure, so in
   general we cannot allow memory allocation to fail.  */
   
/* Copyright (C) 2011
   Texas Instruments, Inc.
   Modifications by Shreyas Prasad <shreyasp@ti.com>. 
   
   Changes from original:
   - gomp_alloc modified to use TI Memory APIs
   - gomp_free added
   - gomp_realloc modified to use gomp_alloc/free
   - TI headers added */

#include "libgomp.h"

#include <ti/ipc/SharedRegion.h>
#include <ti/sdo/ipc/_Ipc.h>

#include <xdc/runtime/Memory.h>

#include <stdlib.h>

#define LIBGOMP_IPC_HEAP 	0

void *
gomp_malloc (size_t size)
{
    SizeT allocSize, cacheLineSize;
    void *ptr, *newptr;
    
    cacheLineSize = SharedRegion_getCacheLineSize(LIBGOMP_IPC_HEAP);
    allocSize = size + cacheLineSize;
    
    ptr = Memory_calloc(SharedRegion_getHeap(LIBGOMP_IPC_HEAP), allocSize, 0, NULL);
    *((SizeT *)ptr) = allocSize;
    
    newptr = (void *)((UInt32)ptr + cacheLineSize);
    
    return ((void *)newptr);
}

void
gomp_free (void *ptr)
{
    SizeT allocSize, cacheLineSize;
    void *oldptr;
    
    if (ptr == NULL) {
        /* no operation is performed if 'ptr' is NULL */
        return;
    }

    cacheLineSize = SharedRegion_getCacheLineSize(LIBGOMP_IPC_HEAP);
    
    oldptr = (void *)((UInt32)ptr - cacheLineSize);
    
    allocSize = *((SizeT *)oldptr);
    Memory_free(SharedRegion_getHeap(LIBGOMP_IPC_HEAP), oldptr, allocSize);
}

void *
gomp_malloc_cleared (size_t size)
{
  void *ret = calloc (1, size);
  if (ret == NULL)
    gomp_fatal ("Out of memory allocating %lu bytes", (unsigned long) size);
  return ret;
}

void *
gomp_realloc (void *old, size_t size)
{
    void *ret;

    ret = gomp_malloc(size);
    if (ret == NULL) {
        gomp_fatal ("Out of memory allocating %lu bytes", (unsigned long) size);
    }
    
    if (old != NULL) {
        memcpy(ret, old, size);
        gomp_free(old);
    }

    return ret;
}
