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
   Modifications by Shreyas Prasad <shreyasp@ti.com>. 
   
   Changes from original:
   - This is a TI-specific implementation of the gomp barrier APIs */ 
   
#include <ti/omp/libgomp.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Diags.h>

void
gomp_barrier_init (gomp_barrier_t *bar, unsigned count)
{
    Log_print2(Diags_USER1, 
            "gomp_barrier_init start, barrier = 0x%x, t_id = %d\n", 
            (IArg)bar, gomp_thread()->ts.team_id); 
    gomp_mutex_init (&bar->mutex1);
    gomp_mutex_init (&bar->mutex2);
    gomp_sem_init (&bar->sem1, 0);
    gomp_sem_init (&bar->sem2, 0);
    bar->total = count;
    bar->arrived = 0;
    bar->generation = 0;
    Log_print2(Diags_USER1, 
            "gomp_barrier_init end, barrier = 0x%x, t_id = %d\n", 
            (IArg)bar, gomp_thread()->ts.team_id); 
}

void
gomp_barrier_destroy (gomp_barrier_t *bar)
{
  /* Before destroying, make sure all threads have left the barrier.  */
  gomp_mutex_lock (&bar->mutex1);
  gomp_mutex_unlock (&bar->mutex1);

  gomp_mutex_destroy (&bar->mutex1);
  gomp_mutex_destroy (&bar->mutex2);
  gomp_sem_destroy (&bar->sem1);
  gomp_sem_destroy (&bar->sem2);
}

void
gomp_barrier_reinit (gomp_barrier_t *bar, unsigned count)
{
  gomp_mutex_lock (&bar->mutex1);
  bar->total = count;
  gomp_mutex_unlock (&bar->mutex1);
}

void
gomp_barrier_wait_end (gomp_barrier_t *bar, gomp_barrier_state_t state)
{
  unsigned int n;

  if (state & 1)
    {
      n = --bar->arrived;
      if (n > 0)
	{
	  do
	    gomp_sem_post (&bar->sem1);
	  while (--n != 0);
	  gomp_sem_wait (&bar->sem2);
	}
      gomp_mutex_unlock (&bar->mutex1);
    }
  else
    {
      gomp_mutex_unlock (&bar->mutex1);
      gomp_sem_wait (&bar->sem1);

      gomp_mutex_lock (&bar->mutex2);
      n = --bar->arrived;
      gomp_mutex_unlock (&bar->mutex2);

      if (n == 0)
	gomp_sem_post (&bar->sem2);
    }

  /* OMP v3.1, 2.8.6, p81, 
     l16 - "At entry to parallel region" 
     l18 - "At entry to combined parallel worksharing regions (loop)" */
  gomp_flush0();  
}

void
gomp_barrier_wait (gomp_barrier_t *barrier)
{
  Log_print2(Diags_USER1, "gomp_barrier_start start, bar = 0x%x, t_id = %d\n", 
            (IArg)barrier, gomp_thread()->ts.team_id); 
  gomp_barrier_wait_end (barrier, gomp_barrier_wait_start (barrier));
  Log_print2(Diags_USER1, "gomp_barrier_start end, bar = 0x%x, t_id = %d\n", 
            (IArg)barrier, gomp_thread()->ts.team_id); 
}

void
gomp_team_barrier_wait_end (gomp_barrier_t *bar, gomp_barrier_state_t state)
{
  unsigned int n;
  struct gomp_thread *thr;
  struct gomp_team *team;

  if (state & 1)
    {
      n = --bar->arrived;
      thr = gomp_thread ();
      team = thr->ts.team;

      if (team->task_count)
	{
	  gomp_barrier_handle_tasks (state);
	  if (n > 0)
	    gomp_sem_wait (&bar->sem2);
	  gomp_mutex_unlock (&bar->mutex1);
          gomp_flush0();
	  return;
	}

      bar->generation = state + 3;
  
      if (n > 0)
	{
	  do
	    gomp_sem_post (&bar->sem1);
	  while (--n != 0);
	  gomp_sem_wait (&bar->sem2);
	}
      gomp_mutex_unlock (&bar->mutex1);
    }
  else
    {
      gomp_mutex_unlock (&bar->mutex1);
      do
	{
	  gomp_sem_wait (&bar->sem1);
	  if (bar->generation & 1)
	    gomp_barrier_handle_tasks (state);
	}
      while (bar->generation != state + 4);

      gomp_mutex_lock (&bar->mutex2);
      n = --bar->arrived;
      gomp_mutex_unlock (&bar->mutex2);

      if (n == 0)
	gomp_sem_post (&bar->sem2);
    }

  /* OMP v3.1, 2.8.6, p81
     l15 - "During a barrier region" 
     l16 - "At exit from parallel region" 
     l17 - "At exit from worksharing regions unless a nowait is present"
           loop, section and single */
  /* Flush after all threads have reached the barrier. This handles a 
   * corner case where a shared variable on the stack is on the same cache
   * line as the location of the return address on the stack. The read of the
   * return address during function epilog also reads in the shared variable
   * into the cache and marks it as valid. Because of this inadvertent read of
   * the shared variable, we need to ensure that writes to the shared variable 
   * from all threads have landed before we return from the flush.
   */
  gomp_flush0();
}

void
gomp_team_barrier_wait (gomp_barrier_t *barrier)
{
  gomp_team_barrier_wait_end (barrier, gomp_barrier_wait_start (barrier));
}

void
gomp_team_barrier_wake (gomp_barrier_t *bar, int count)
{
  if (count == 0)
    count = bar->total - 1;
  while (count-- > 0)
    gomp_sem_post (&bar->sem1);
}
