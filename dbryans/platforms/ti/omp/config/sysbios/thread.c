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
   
   TI-specific implementation of gomp threads */ 

#include <ti/omp/libgomp.h>
#include <ti/omp/utils/OpenMP.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/omp/utils/ThreadLocal.h>

int gomp_thread_create(gomp_thread_t *thread, 
                       const gomp_thread_attr_t *attrs,
                        void *(*threadfxn)(void *), void *arg)
{
    OpenMP_createThread((Fxn)threadfxn, (Ptr)arg,
        OpenMP_stackSize);

    return (0);
}

int gomp_thread_setspecific(gomp_thread_key_t key, const void *value)
{
    return ThreadLocal_setspecific(key, value);
}

void *gomp_thread_getspecific(gomp_thread_key_t key)
{
    return ThreadLocal_getspecific(key);
}
 
int gomp_thread_key_create(gomp_thread_key_t *key, void (*destructor)(void*))
{
    return ThreadLocal_key_create(key, destructor);
}

int gomp_thread_key_delete(gomp_thread_key_t key)
{
    return ThreadLocal_key_delete(key);
}
