/* Copyright (C) 2011
   Texas Instruments, Inc.
   Modifications by Wajdi Darmoul <x0141387@ti.com>. 
   
   Changes from original:
   - This is a TI-specific implementation of the gomp barrier APIs */ 
   
#ifndef GOMP_BARRIER_H
#define GOMP_BARRIER_H 1

typedef struct
{
  unsigned total;
  unsigned arrived;
  UInt32 Hnd;
  Uint32 all_arrived;
  unsigned generation;
} gomp_barrier_t;
typedef unsigned int gomp_barrier_state_t;
void Queue_Barrier_wait(gomp_barrier_t *bar);
void Queue_Barrier_init( gomp_barrier_t *bar, unsigned count );
void	Queue_barrier_reinit (gomp_barrier_t *bar,  Uint32 count);
void Queue_Barrier_destroy(gomp_barrier_t *bar);
void wait_for_release(gomp_barrier_t *bar);
void wait_threads_release(gomp_barrier_t *bar);
void gomp_team_barrier_wake (gomp_barrier_t *, int);
void gomp_team_barrier_set_task_pending (gomp_barrier_t *bar);

#endif /* GOMP_BARRIER_H */
