/* Copyright (C) 2005, 2008, 2009 Free Software Foundation, Inc.
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

/* Copyright (C) 2011
   Texas Instruments, Inc.
   Created by Shreyas Prasad <shreyasp@ti.com>. 
   
   TI-specific implementation of gomp thread APIs */ 

#ifndef GOMP_THREAD_H
#define GOMP_THREAD_H 1

#define GOMP_THREAD_CREATE_DETACHED 0

#include <ti/sysbios/knl/Task.h>
#include <ti/omp/utils/ThreadLocal.h>
#include <ti/omp/utils/OpenMP.h>
/* The attributes to be used during thread creation.  */

typedef Task_Struct gomp_thread_t;
typedef Task_Params gomp_thread_attr_t;

typedef ThreadLocal_Key gomp_thread_key_t;

/* Initialize Task params */
static inline void gomp_thread_attr_init(gomp_thread_attr_t *params) 
{
    Task_Params_init(params);
}

/* Set the stackSize attribute */
static inline int gomp_thread_attr_setstacksize(gomp_thread_attr_t *params, size_t stacksize)
{
    params->stackSize = stacksize;
    
    return 0;
}

static inline int gomp_thread_attr_getstacksize(gomp_thread_attr_t *params, 
                                         size_t *stacksize)
{
    *stacksize = params->stackSize;
    
    return 0;
}

static inline int gomp_thread_attr_setdetachstate(gomp_thread_attr_t *params, 
                                         int detachstate)
{
    /* Not supported by SYS/BIOS Tasks.  Ignore this value */
    return 0;
}

static inline void gomp_thread_attr_destroy(gomp_thread_attr_t *params) 
{
    /* Nothing to do */
}

extern int gomp_thread_create(gomp_thread_t *thread, 
                              const gomp_thread_attr_t *attrs,
                              void *(*threadfxn)(void *), void *arg);

static inline void gomp_thread_exit(void) 
{
 //OpenMP_exitThread();
   Task_exit();
}

extern int gomp_thread_setspecific(gomp_thread_key_t key, const void *value);

extern void *gomp_thread_getspecific(gomp_thread_key_t key);
 
extern int gomp_thread_key_create(gomp_thread_key_t *key, void (*destructor)(void*));

extern int gomp_thread_key_delete(gomp_thread_key_t key);

#endif /* GOMP_THREAD_H */
