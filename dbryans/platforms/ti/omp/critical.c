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

/* Copyright (C) 2011
   Texas Instruments, Inc.
   Modifications by Shreyas Prasad <shreyasp@ti.com>. 
   
   Changes from original:
   - "static void __attribute__((constructor))"
      removed from initialize_critical */
   
/* This file handles the CRITICAL construct.  */

#include "libgomp.h"
#include <stdlib.h>

static gomp_mutex_t default_lock;
#pragma DATA_SECTION(default_lock, "gomp_data")

void
GOMP_critical_start (void)
{
  gomp_mutex_lock (&default_lock);

  /* OMP v3.1, 2.8.6 p81,l16 - "At entry to critical regions" */
  gomp_flush0();
}

void
GOMP_critical_end (void)
{
  /* OMP v3.1, 2.8.6 p81,l16 - "At exit from critical regions"
     Flush and then unlock to ensure all writes land before lock is released */
  gomp_flush0(); 

  gomp_mutex_unlock (&default_lock);
}

#ifndef HAVE_SYNC_BUILTINS
static gomp_mutex_t create_lock_lock;
#pragma DATA_SECTION(create_lock_lock, "gomp_data")
#endif

void
GOMP_critical_name_start (void **pptr)
{
  gomp_mutex_t *plock;

  /* If a mutex fits within the space for a pointer, and is zero initialized,
     then use the pointer space directly.  */
  if (GOMP_MUTEX_INIT_0
      && sizeof (gomp_mutex_t) <= sizeof (void *)
      && __alignof (gomp_mutex_t) <= sizeof (void *))
    plock = (gomp_mutex_t *)pptr;

  /* Otherwise we have to be prepared to malloc storage.  */
  else
    {
      plock = *pptr;

      if (plock == NULL)
	{
#ifdef HAVE_SYNC_BUILTINS
	  gomp_mutex_t *nlock = gomp_malloc (sizeof (gomp_mutex_t));
	  gomp_mutex_init (nlock);

	  plock = __sync_val_compare_and_swap (pptr, NULL, nlock);
	  if (plock != NULL)
	    {
	      gomp_mutex_destroy (nlock);
	      gomp_free (nlock);
	    }
	  else
	    plock = nlock;
#else
	  gomp_mutex_lock (&create_lock_lock);
	  plock = *pptr;
	  if (plock == NULL)
	    {
	      plock = gomp_malloc (sizeof (gomp_mutex_t));
	      gomp_mutex_init (plock);
	      __sync_synchronize ();
	      *pptr = plock;
	    }
	  gomp_mutex_unlock (&create_lock_lock);
#endif
	}
    }

  gomp_mutex_lock (plock);

  /* OMP v3.1, 2.8.6 p81,l16 - "At entry to critical regions" */
  gomp_flush0();
}

void
GOMP_critical_name_end (void **pptr)
{
  gomp_mutex_t *plock;

  /* OMP v3.1, 2.8.6 p81,l16 - "At exit from critical regions"
     Flush and then unlock to ensure all writes land before lock is released */
  gomp_flush0(); 

  /* If a mutex fits within the space for a pointer, and is zero initialized,
     then use the pointer space directly.  */
  if (GOMP_MUTEX_INIT_0
      && sizeof (gomp_mutex_t) <= sizeof (void *)
      && __alignof (gomp_mutex_t) <= sizeof (void *))
    plock = (gomp_mutex_t *)pptr;
  else
    plock = *pptr;

  gomp_mutex_unlock (plock);
}

/* This mutex is used when atomic operations don't exist for the target
   in the mode requested.  The result is not globally atomic, but works so
   long as all parallel references are within #pragma omp atomic directives.
   According to responses received from omp@openmp.org, appears to be within
   spec.  Which makes sense, since that's how several other compilers 
   handle this situation as well.  */

static gomp_mutex_t atomic_lock;
#pragma DATA_SECTION(atomic_lock, "gomp_data")

void
GOMP_atomic_start (void)
{
  gomp_mutex_lock (&atomic_lock);

  /* OMP v3.1, 2.8.6 p82,l1 - "At entry to atomic operation"
     TODO: Replace gomp_flush0 with a targeted flush containing just the 
     storage locations involved in the atomic construct */
  gomp_flush0();
}

void
GOMP_atomic_end (void)
{
  /* OMP v3.1, 2.8.6 p82,l1 - "At exit from atomic operation"
     Flush and then unlock to ensure all writes land before lock is released */
  gomp_flush0();

  gomp_mutex_unlock (&atomic_lock);
}

#if !GOMP_MUTEX_INIT_0
void initialize_critical (void)
{
  gomp_mutex_init (&default_lock);
  gomp_mutex_init (&atomic_lock);
#ifndef HAVE_SYNC_BUILTINS
  gomp_mutex_init (&create_lock_lock);
#endif
}
#endif
