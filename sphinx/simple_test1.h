/*
$Log: simple_test1.h,v $
Revision 1.5  2000/09/15 00:05:00  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.4  2000/08/25 23:17:16  bronis
Added OpenMP tests

Revision 1.3  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.2  1999/09/29 00:23:48  bronis
removed most restrictions on ACKER variation

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: simple_test1.h,v 1.5 2000/09/15 00:05:00 bronis Exp $ */

void simple_init_dummy (measurement_t *ms);
void simple_init_inside_dummy (measurement_t *ms);
void simple_init_Wtime (measurement_t *ms);
void simple_init_2Wtime (measurement_t *ms);
void simple_init_Comm_size (measurement_t *ms);
void simple_init_Comm_rank (measurement_t *ms);
void simple_init_Iprobe (measurement_t *ms);
void simple_init_attach (measurement_t *ms);
void simple_init_condition (measurement_t *ms);
void simple_init_cond_signal (measurement_t *ms);
void simple_init_cond_signal_no_client (measurement_t *ms);
void simple_init_cond_wait (measurement_t *ms);
void simple_init_cond_wait_testcancel(measurement_t * ms);
void simple_init_mutex_lock_unlock (measurement_t *ms);
void simple_init_mutex_lock_unlock_twice (measurement_t *ms);
void simple_init_mutex_lock_unlock_thrice (measurement_t *ms);
void simple_init_mutex_lock_unlock_4times (measurement_t *ms);
void simple_init_mutex_pingpong (measurement_t *ms);
void simple_init_mutex_pingpong_no_client (measurement_t *ms);
void simple_init_timeslice (measurement_t *ms);
void simple_init_yield (measurement_t *ms);
void simple_init_mutex_lock_unlock_2locks (measurement_t *ms);
void simple_init_mutex_lock_unlock_3locks (measurement_t *ms);
void simple_init_mutex_lock_unlock_5locks (measurement_t *ms);
void simple_init_mutex_lock_unlock_6locks (measurement_t *ms);
void simple_init_mutex_lock_unlock_7locks (measurement_t *ms);
void simple_init_mutex_lock_unlock_8locks (measurement_t *ms);
void simple_init_mutex_lock_unlock_9locks (measurement_t *ms);
void simple_init_mutex_lock_unlock_10locks (measurement_t *ms);
void simple_init_mutexarray_pingpong (measurement_t *ms);
void simple_init_mutexarray_pingpong_no_client (measurement_t *ms);


void thread_chain_init_thread_create (measurement_t * ms);
void thread_chain_init_thread_create_sys (measurement_t * ms);
void thread_chain_init_thread_create_u (measurement_t * ms);
void thread_chain_init_thread_create_usys (measurement_t * ms);


void multitiming_init_lock_unlock (measurement_t * ms);
void multitiming_init_mutex_pingpong_noclient (measurement_t *ms);
void multitiming_init_mutex_lock_unlock (measurement_t *ms);

void proxy_init_yield (measurement_t * ms);
