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

/* This is the default PTHREADS implementation of the public OpenMP
   locking primitives.

   Because OpenMP uses different entry points for normal and recursive
   locks, and pthreads uses only one entry point, a system may be able
   to do better and streamline the locking as well as reduce the size
   of the types exported.  */

/* Copyright (C) 2011
   Texas Instruments, Inc.
   Modifications by Shreyas Prasad <shreyasp@ti.com>. 
   
   Changes from original:
   - This is a TI-specific implementation of the gomp lock APIs */ 
   
#ifndef __osf__
#define _XOPEN_SOURCE 500
#endif

#include "proc.h"

#include <xdc/std.h>
#include <ti/omp/libgomp.h>
#define ti_sdo_ipc_GateMP__internalaccess
#include <ti/sdo/ipc/_GateMP.h>

void
gomp_init_lock_30 (omp_lock_t *lock)
{
    lock->key = NULL;
    lock->entered = false;
}

void
gomp_destroy_lock_30 (omp_lock_t *lock)
{
    /* Nothing to do here */

}

void
gomp_set_lock_30 (omp_lock_t *lock)
{
	GateMP_Handle gateHandle = GateMP_getDefaultRemote();
	
    lock->key = GateMP_enter(gateHandle);
    lock->entered = true;

    /* OMP v3.1, 2.8.6 p81
       l19 "During omp_set_lock and omp_set_unlock regions"
       l20 "During omp_test_lock,... if the region causes the lock to be 
           set or unset" */
    gomp_flush0();
}

void
gomp_unset_lock_30 (omp_lock_t *lock)
{
    /* OMP v3.1, 2.8.6 p81
       l19 "During omp_set_lock and omp_set_unlock regions"
       l20 "During omp_test_lock,... if the region causes the lock to be 
           set or unset" */
    gomp_flush0();

	GateMP_Handle gateHandle = GateMP_getDefaultRemote();
    UInt key = lock->key;

    lock->key = NULL;
    lock->entered = false;

    GateMP_leave(gateHandle, key);
}

int
gomp_test_lock_30 (omp_lock_t *lock)
{
   if (lock->entered) {
       return 0;
   }
   else {
       omp_set_lock(lock);
       return 1;
   }
}

void
gomp_init_nest_lock_30 (omp_nest_lock_t *lock)
{
  lock->count = 0;
  lock->owner = NULL;
  omp_init_lock(&(lock->lock));
}

void
gomp_destroy_nest_lock_30 (omp_nest_lock_t *lock)
{
    /* Nothing to do here */
}

void
gomp_set_nest_lock_30 (omp_nest_lock_t *lock)
{
  void *me = gomp_icv (true);

  if (lock->owner != me)
    {
      omp_set_lock(&lock->lock);
      lock->owner = me;
    }
  lock->count++;
}

void
gomp_unset_nest_lock_30 (omp_nest_lock_t *lock)
{
  if (--lock->count == 0)
    {
      lock->owner = NULL;
      omp_unset_lock(&lock->lock);
    }
}

int
gomp_test_nest_lock_30 (omp_nest_lock_t *lock)
{
  void *me = gomp_icv (true);

  if (lock->owner != me)
    {
      if (omp_test_lock (&lock->lock) == 0)
	return 0;
      lock->owner = me;
    }

  return ++lock->count;
}

ialias (omp_init_lock)
ialias (omp_init_nest_lock)
ialias (omp_destroy_lock)
ialias (omp_destroy_nest_lock)
ialias (omp_set_lock)
ialias (omp_set_nest_lock)
ialias (omp_unset_lock)
ialias (omp_unset_nest_lock)
ialias (omp_test_lock)
ialias (omp_test_nest_lock)
