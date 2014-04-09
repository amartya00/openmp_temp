

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>

#ifdef _HAVE_OMP_

#include "omp.h"

#endif /* _HAVE_OMP_ */

#include "sphinx.h"
#include "sphinx_aux.h"
#include "simple_test1.h"
#include "pattern.h"
#include "sphinx_error.h"
#include "sphinx_mem.h"
#include "sphinx_aux_test.h"
#include "sphinx_tools.h"
#include "sphinx_params.h"
#include "sphinx_omp.h"




extern int max_iters;

#ifdef _HAVE_OMP_


int measure_omp_parallel_ref( void );
int measure_omp_parallel( void );
int measure_omp_parallel_for_ref( void );
int measure_omp_parallel_for_static( void );
int measure_omp_parallel_for_dynamic( void );
int measure_omp_parallel_for_guided( void );
int measure_omp_parallel_for_chunks_static( void );
int measure_omp_parallel_for_chunks_dynamic( void );
int measure_omp_parallel_for_chunks_guided( void );
int measure_omp_ordered_ref( void );
int measure_omp_ordered_only( void );
int measure_omp_ordered( void );
int measure_omp_single_ref( void );
int measure_omp_single( void );
int measure_omp_barrier( void );
int measure_omp_reduction_ref( void );
int measure_omp_reduction( void );
int measure_omp_atomic_ref( void );
int measure_omp_atomic( void );
void measure_mixed_omp_mpi_barrier( int len, MPI_Comm communicator );
void measure_mixed_omp_mpi_barrier_only( int len, MPI_Comm communicator );
void measure_mixed_omp_mpi_allreduce( int len, MPI_Comm communicator );
void measure_mixed_omp_mpi_allreduce_only( int len, MPI_Comm communicator );
void measure_mixed_omp_mpi_allreduce_barrier_only( int len, 
						   MPI_Comm communicator );
MPI_Status server_omp_overlap( int msglen, int node, MPI_Comm communicator );
MPI_Status server_Irecv_omp_overlap( int msglen, int node, 
				     MPI_Comm communicator );
MPI_Status server_Isend_omp_overlap( int msglen, int max_node, 
				     MPI_Comm communicator );
MPI_Status server_Isend_both_omp_overlaps( int msglen, int max_node, 
					   MPI_Comm communicator );


int sphinx_omp_max_num_threads = SPHINX_OMP_UNSET;

int sphinx_omp_thread_count = SPHINX_OMP_UNSET;

int  (* omp_overlap) (void);

/* I'll eventually need these for the lock pingpong test... */
omp_lock_t sphinx_omp_lock_0;
omp_lock_t sphinx_omp_lock_1;
omp_lock_t sphinx_omp_lock_2;
omp_lock_t sphinx_omp_lock_3;

#endif /* _HAVE_OMP_ */


int  (* work) (int work_size);
int  work_param = SPHINX_OMP_UNSET; 

int schedule_loop_cap = SPHINX_OMP_UNSET;
int schedule_chunks = SPHINX_OMP_UNSET;
int sphinx_omp_reduce_var = SPHINX_OMP_UNSET;
int sphinx_mixed_omp_mpi_reduce_var = SPHINX_OMP_UNSET;

static int sphinx_int_size = sizeof(int);


/* these assume variation prologues are already called... */
int
get_which_work (measurement_t *ms)
{
  if (ms->have_omp_params)
    return ms->omp_data.which_work;

  /* probably should exit, but we could continue... */
  ERROR (INTERN, "Bad measurement for get_which_work");
  output_error(FALSE);

  return WORK_FUNCTION_COUNT;
}

int
get_work_param (measurement_t *ms)
{
  if (ms->have_omp_params)
    return ms->omp_data.work_amount;

  /* probably should exit, but we could continue... */
  ERROR (INTERN, "Bad measurement for get_work_param");
  output_error(FALSE);

  return GENERIC_ERROR;
}

int
get_thread_count (measurement_t *ms)
{
  if (ms->have_omp_params)
    return ms->omp_data.thread_count;

  /* probably should exit, but we could continue... */
  ERROR (INTERN, "Bad pattern for get_thread_count");
  output_error(FALSE);

  return GENERIC_ERROR;
}

int
get_sched_cap (measurement_t *ms)
{
  if (ms->have_omp_params)
    return ms->omp_data.cap_for_schedule_loops;

  /* probably should exit, but we could continue... */
  ERROR (INTERN, "Bad pattern for get_sched_cap");
  output_error(FALSE);

  return GENERIC_ERROR;
}

int
get_schedule_chunks (measurement_t *ms)
{
  if (ms->have_omp_params)
    return ms->omp_data.schedule_chunks;

  /* probably should exit, but we could continue... */
  ERROR (INTERN, "Bad pattern for get_schedule_chunks");
  output_error(FALSE);

  return GENERIC_ERROR;
}

int
get_loop_schedule (measurement_t *ms)
{
  if (ms->have_omp_params)
    return ms->omp_data.loop_schedule;

  /* probably should exit, but we could continue... */
  ERROR (INTERN, "Bad pattern for get_loop_schedule");
  output_error(FALSE);

  return GENERIC_ERROR;
}

int
get_which_overlap (measurement_t *ms)
{
  if (ms->have_omp_params)
    return ms->omp_data.which_overlap;

  /* probably should exit, but we could continue... */
  ERROR (INTERN, "Bad measurement for get_which_overlap");
  output_error(FALSE);

  return OMP_OVERLAP_FUNCTION_COUNT;
}

int set_up_omp_parameters (measurement_t *ms)
{
  int i;

  /* only guaranteed work stuff are set correctly for OMP tests */
  /* to use them in other measurements would require minor changes... */
  work_param = get_work_param(ms);
  switch (get_which_work(ms)) {
  case SIMPLE_WORK:
    work = simple_work;
    break;
  case BORS_WORK:
    work = bors_work;
    break;
  case SPIN_TIMED_WORK:
    work = spin_timed_work;
    break;
  case SLEEP_TIMED_WORK:
    work = sleep_timed_work;
    break;
  default:
#ifdef _HAVE_OMP_
    ERROR(USER,
	  "invalid which_work parameter occurred in set_up_omp_parameters");
    output_error (FALSE);
    return GENERIC_ERROR;
#else
    work = simple_work;
#endif
  }

#ifdef _HAVE_OMP_

  switch (get_which_overlap(ms)) {
  case OMP_SEQUENTIAL_OVERLAP:
    omp_overlap = measure_omp_parallel_ref;
    break;
  case OMP_PARALLEL_OVERLAP:
    omp_overlap = measure_omp_parallel;
    break;
  case OMP_PARALLEL_FOR_OVERLAP:
    switch (get_loop_schedule (ms)) {
    case STATIC_SCHED:
      omp_overlap = measure_omp_parallel_for_static;
      break;
    case DYNAMIC_SCHED:
      omp_overlap = measure_omp_parallel_for_dynamic;
      break;
    case GUIDED_SCHED:
      omp_overlap = measure_omp_parallel_for_guided;
      break;
    default:
      ERROR(USER,
	    "invalid schedule parameter occurred in set_up_omp_parameters");
      output_error (FALSE);
      return GENERIC_ERROR;
    }
    break;
  case OMP_PARALLEL_FOR_CHUNKS_OVERLAP:
    switch (get_loop_schedule (ms)) {
    case STATIC_SCHED:
      omp_overlap = measure_omp_parallel_for_chunks_static;
      break;
    case DYNAMIC_SCHED:
      omp_overlap = measure_omp_parallel_for_chunks_dynamic;
      break;
    case GUIDED_SCHED:
      omp_overlap = measure_omp_parallel_for_chunks_guided;
      break;
    default:
      ERROR(USER,
	    "invalid schedule parameter occurred in set_up_omp_parameters");
      output_error (FALSE);
      return GENERIC_ERROR;
    }
    break;
  default:
    ERROR(USER,
	  "invalid which_overlap parameter occurred in set_up_omp_parameters");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  sphinx_omp_thread_count = get_thread_count(ms);
  omp_set_num_threads(sphinx_omp_thread_count);

#endif

  schedule_loop_cap = get_sched_cap (ms);
  schedule_chunks = get_schedule_chunks(ms);

  i = get_loop_schedule(ms);

  switch (ms->pattern) {
  case P2P:
    ms->data.p2p_data.server_op = (p2p_f_ptr_t)
      ms->omp_data.schedule_routines_to_measure[i];
    ms->data.p2p_data.client_op = (p2p_f_ptr_t)
      ms->omp_data.schedule_routines_to_measure2[i];
    break;
  case COLLECTIVE:
    ms->data.col_data.routine_to_measure = (col_f_ptr_t) 
      ms->omp_data.schedule_routines_to_measure[i];
    ms->data.col_data.client_routine = (col_f_ptr_t) 
      ms->omp_data.schedule_routines_to_measure2[i];
    break;
  case THREAD_CHAIN:
  case SIMPLE:
    ms->data.simple_data.routine_to_measure =  (my_f_ptr_t)
      ms->omp_data.schedule_routines_to_measure[i];
    break;
  case MULTITIMING:
    ms->data.multitiming_data.routines_to_measure = (my_f_ptr_t *)
      ms->omp_data.schedule_routines_to_measure[i];
     ms->data.multitiming_data.client_routines = (my_f2_ptr_t *)
      ms->omp_data.schedule_routines_to_measure2[i];
   break;
  default:
    ERROR(USER,"invalid pattern occured in set_up_omp_parameters");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  return SUCCESS;
}


#ifdef _HAVE_OMP_

static int gretval;

int
mixed_omp_mpi_barrier (MPI_Comm comm) 
{
  {
#pragma omp barrier
  }

#pragma omp master
  {
    gretval = MPI_Barrier (comm);
  }

  {
#pragma omp barrier
  }

  return gretval;
}

int
mixed_omp_mpi_allreduce_only (MPI_Comm comm) 
{
  int j;

#pragma omp for reduction(+: sphinx_omp_reduce_var)
  for(j=0; j < sphinx_omp_thread_count; j++) {
    sphinx_omp_reduce_var += j;
  }

#pragma omp master
  {
    gretval = MPI_Allreduce(&sphinx_omp_reduce_var, 
			    &sphinx_mixed_omp_mpi_reduce_var, 
			    1, MPI_INT, MPI_SUM, comm);
  }

  {
#pragma omp barrier
  }

  return gretval;
}

extern void generic_barrier (MPI_Comm curcomm);

int
mixed_omp_mpi_allreduce_barrier_only (MPI_Comm comm) 
{
  int j;

#pragma omp for reduction(+: sphinx_omp_reduce_var)
  for(j=0; j < sphinx_omp_thread_count; j++) {
    sphinx_omp_reduce_var += j;
  }

#pragma omp master
  {
    gretval = MPI_Allreduce(&sphinx_omp_reduce_var, 
			    &sphinx_mixed_omp_mpi_reduce_var, 
			    1, MPI_INT, MPI_SUM, comm);

    generic_barrier (comm);
  }

  {
#pragma omp barrier
  }

  return gretval;
}


/* this is both a server_init and a client_init function */
/*
   @FUN:
   @DOES: sets _sphinx_buffer to _skib (i.e. a location of allocated memory.)
   @PARAMETERS: number of repetitions (nor), 
   number of measurements (nom), 
   number of processes involved in the measurement (nop).
   @RETURNES: the size of memory available at _sphinx_buffer.
   @SIDEEFFECTS: manipulation of _sphinx_buffer.
   @ASSUMES: assumes allocate_mem called once before with no
   other mem_init_... between.
*/
long int 
omp_init_one_buffer (int nor, int nom, int nop, measurement_t *ms)
{
  D(fprintf(stderr,"proc %d: in omp_init_one_buffer\n",_sphinx_myid);)

  if (sphinx_omp_max_num_threads == SPHINX_OMP_UNSET) 
    /* set num threads */
#pragma omp parallel
#pragma omp master
    sphinx_omp_max_num_threads = omp_get_num_threads();
  /* end omp parallel, master */

  return (mem_init_one_buffer(nor, nom, nop, ms));
}


#endif /* _HAVE_OMP_ */


#define BORS_BASIC_WORK(for_limit)   \
{ \
  for(i=0; i<for_limit; i++) { \
     d[i] = i+1; \
     for(j=0; j<for_limit; j++) { \
        a[i][j] = i + j + 1; \
        b[i][j] = (i+1)*(i+1) + j; \
        c[i][j] = i + (j+1)*(j+1); \
     } \
  } \
  for(i=1; i<for_limit; i++) { \
     for(j=1; j<for_limit; j++) { \
        a[i][j] += b[i-1][j-1]; \
        b[i][j] /= d[i-1]; \
        c[i][j] += a[i-1][j-1] + b[i][j-1]*2; \
        d[i] += c[i][j] + a[i][j] -b[i][j]; \
     } \
  } \
}
/* end BORS_BASIC_WORK */


#define ARRAY_SIZE   512


int bors_work (int work_size)
{
  double a[ARRAY_SIZE][ARRAY_SIZE],
         b[ARRAY_SIZE][ARRAY_SIZE],
         c[ARRAY_SIZE][ARRAY_SIZE],
         d[ARRAY_SIZE];
  int cap, times, i = 0,
      j = 0,
      k = 0;

  times = work_size/ARRAY_SIZE;

  cap = ARRAY_SIZE;

  for (k = 0; k < times - 1; k++)
    BORS_BASIC_WORK(cap);

  /* yes. I mean assignment... */
  if (cap = (work_size % ARRAY_SIZE))
    BORS_BASIC_WORK(cap);
    
  if (work_size != 0) {
    i = rand();
    while(i > (work_size-1)) i /= 10;
    i = (int) d[i];
  }
  else 
    i = 0;

  return i;
}


#define MAX_REPS_PER_SIMPLE_WORK_CYCLE 20


int simple_work (int work_size)
{
  int i;
  double sw_retval = 1.0;

  for (i = 0; i < work_size; i++) {
    if (i % 2)
      sw_retval += i * 3.1415;
    else
      sw_retval += (i >> 1) * 3.1415;

    if (i % MAX_REPS_PER_SIMPLE_WORK_CYCLE)
      sw_retval = 1.0;
  }

  return (int) sw_retval;
}


int spin_timed_work (int work_size)
{
  double init_time, stop = ((double) work_size)/1000000000.0;
  int    i = 2;

  init_time = MPI_Wtime();

  while (MPI_Wtime() - init_time < stop)
    i++;

  return i;
}


int sleep_timed_work (int work_size)
{
  double last_time[2], work_time;
  int    secs, usecs, i = 0;

  last_time[0] = MPI_Wtime();

  work_time = ((double) work_size)/1000000000.0;

  while (work_time > 0) {
    secs = (int) work_time;
    usecs = (int) ((work_time - (double) secs) * 1000);

    sleep (secs);
    usleep (usecs);

    work_time -= ((last_time[(i+1)%2] = MPI_Wtime()) - last_time[i%2]);

    i++;
  }

  return i;
}


#ifdef _HAVE_OMP_


void simple_init_omp_parallel_ref( measurement_t * ms )
{
  int i;

  ms->pattern = SIMPLE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_parallel_ref;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_parallel_ref;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;

  initialize_simple_aux (ms);

  initialize_omp_ms (ms);

  return;
}

void simple_init_omp_parallel( measurement_t * ms )
{
  int i;

  ms->pattern = SIMPLE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_parallel;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_parallel;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;
	
  initialize_omp_parallel_aux (ms);

  initialize_omp_ms (ms);

  return;
}

void simple_init_omp_parallel_for_ref( measurement_t * ms )
{
  int i;

  ms->pattern = SIMPLE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_parallel_for_ref;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_parallel_for_ref;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;
	
  initialize_simple_aux (ms);

  initialize_omp_ms (ms);

  return;
}

void simple_init_omp_parallel_for( measurement_t * ms )
{
  int i;
  
  ms->pattern = SIMPLE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_parallel_for_static;

  ms->omp_data.schedule_routines_to_measure[STATIC_SCHED] =
    (void *) measure_omp_parallel_for_static;
  ms->omp_data.schedule_routines_to_measure[DYNAMIC_SCHED] =
    (void *) measure_omp_parallel_for_dynamic;
  ms->omp_data.schedule_routines_to_measure[GUIDED_SCHED] =
    (void *) measure_omp_parallel_for_guided;

  /* make sure we don't use unset array elements... */
  if (3 < SCHEDULE_COUNT) {
    ERROR(INTERN,"too many schedule types");
    output_error(TRUE);
  }

  for (i = 0; i < SCHEDULE_COUNT; i++)
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;

  ms->data.simple_data.result = NULL;
	
  initialize_omp_parallel_for_aux (ms);

  initialize_omp_ms (ms);

  return;
}

void simple_init_omp_parallel_for_chunks( measurement_t * ms )
{
  int i;
  
  ms->pattern = SIMPLE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = 
    measure_omp_parallel_for_chunks_static;

  ms->omp_data.schedule_routines_to_measure[STATIC_SCHED] =
    (void *) measure_omp_parallel_for_chunks_static;
  ms->omp_data.schedule_routines_to_measure[DYNAMIC_SCHED] =
    (void *) measure_omp_parallel_for_chunks_dynamic;
  ms->omp_data.schedule_routines_to_measure[GUIDED_SCHED] =
    (void *) measure_omp_parallel_for_chunks_guided;

  /* make sure we don't use unset array elements... */
  if (3 < SCHEDULE_COUNT) {
    ERROR(INTERN,"too many schedule types");
    output_error(TRUE);
  }

  for (i = 0; i < SCHEDULE_COUNT; i++)
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;

  ms->data.simple_data.result = NULL;
	
  initialize_omp_parallel_for_aux (ms);

  initialize_omp_ms (ms);

  return;
}

void thread_chain_init_omp_ordered_ref( measurement_t * ms )
{
  int i;

  ms->pattern = THREAD_CHAIN;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_ordered_ref;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_ordered_ref;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;

  initialize_simple_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}

void thread_chain_init_omp_ordered_only( measurement_t * ms )
{
  int i;

  ms->pattern = THREAD_CHAIN;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_ordered_only;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_ordered_only;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;
	
  initialize_omp_ordered_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}

void thread_chain_init_omp_ordered( measurement_t * ms )
{
  int i;

  ms->pattern = THREAD_CHAIN;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_ordered;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_ordered;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;
	
  initialize_omp_ordered_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}

void thread_chain_init_omp_single_ref( measurement_t * ms )
{
  int i;

  ms->pattern = THREAD_CHAIN;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_single_ref;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_single_ref;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;

  initialize_simple_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}

void thread_chain_init_omp_single( measurement_t * ms )
{
  int i;

  ms->pattern = THREAD_CHAIN;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_single;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_single;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;
	
  initialize_omp_single_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}

void thread_chain_init_omp_barrier( measurement_t * ms )
{
  int i;

  ms->pattern = THREAD_CHAIN;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_barrier;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_barrier;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;
	
  initialize_omp_single_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}

void simple_init_omp_reduction_ref( measurement_t * ms )
{
  int i;

  ms->pattern = SIMPLE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_reduction_ref;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_reduction_ref;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;
	
  initialize_simple_aux (ms);

  initialize_omp_ms (ms);

  return;
}

void simple_init_omp_reduction( measurement_t * ms )
{
  int i;
  
  ms->pattern = SIMPLE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_reduction;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_reduction;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;
	
  initialize_omp_reduction_aux (ms);

  initialize_omp_ms (ms);

  return;
}

void simple_init_omp_atomic_ref( measurement_t * ms )
{
  int i;

  ms->pattern = SIMPLE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_atomic_ref;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_atomic_ref;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;
	
  initialize_simple_aux (ms);

  initialize_omp_ms (ms);

  return;
}

void thread_chain_init_omp_atomic( measurement_t * ms )
{
  int i;

  ms->pattern = THREAD_CHAIN;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_omp_atomic;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_omp_atomic;
    ms->omp_data.schedule_routines_to_measure2[i] = NULL;
  }

  ms->data.simple_data.result = NULL;
	
  initialize_omp_atomic_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}


void col_init_mixed_omp_mpi_barrier( measurement_t * ms )
{
  int i;

  ms->pattern = COLLECTIVE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_mixed_omp_mpi_barrier;
  ms->data.col_data.client_routine = measure_mixed_omp_mpi_barrier;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_mixed_omp_mpi_barrier;
    ms->omp_data.schedule_routines_to_measure2[i] = 
      (void *) measure_mixed_omp_mpi_barrier;
  }

  ms->data.col_data.result = NULL;
	
  initialize_omp_ordered_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}

void col_init_mixed_omp_mpi_barrier_only( measurement_t * ms )
{
  int i;

  ms->pattern = COLLECTIVE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_mixed_omp_mpi_barrier_only;
  ms->data.col_data.client_routine = measure_mixed_omp_mpi_barrier_only;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_mixed_omp_mpi_barrier_only;
    ms->omp_data.schedule_routines_to_measure2[i] = 
      (void *) measure_mixed_omp_mpi_barrier_only;
  }

  ms->data.col_data.result = NULL;
	
  initialize_col_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}

void col_init_mixed_omp_mpi_allreduce( measurement_t * ms )
{
  int i;

  ms->pattern = COLLECTIVE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_mixed_omp_mpi_allreduce;
  ms->data.col_data.client_routine = measure_mixed_omp_mpi_allreduce;

  /* for now, OpenMP only supports scalar reductions... */
  ms->data.col_data.len = sphinx_int_size;
  ms->data.col_data.communicator = MPI_COMM_WORLD;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_mixed_omp_mpi_allreduce;
    ms->omp_data.schedule_routines_to_measure2[i] = 
      (void *) measure_mixed_omp_mpi_allreduce;
  }

  ms->data.col_data.result = NULL;
	
  initialize_omp_reduction_aux (ms);

  initialize_omp_ms (ms);

  return;
}

void col_init_mixed_omp_mpi_allreduce_only( measurement_t * ms )
{
  int i;

  ms->pattern = COLLECTIVE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_mixed_omp_mpi_allreduce_only;
  ms->data.col_data.client_routine = measure_mixed_omp_mpi_allreduce_only;

  /* for now, OpenMP only supports scalar reductions... */
  ms->data.col_data.len = sphinx_int_size;
  ms->data.col_data.communicator = MPI_COMM_WORLD;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_mixed_omp_mpi_allreduce_only;
    ms->omp_data.schedule_routines_to_measure2[i] = 
      (void *) measure_mixed_omp_mpi_allreduce_only;
  }

  ms->data.col_data.result = NULL;
	
  initialize_col_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}

void col_init_mixed_omp_mpi_allreduce_barrier_only( measurement_t * ms )
{
  int i;

  ms->pattern = COLLECTIVE;
  ms->server_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = omp_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = 
    measure_mixed_omp_mpi_allreduce_barrier_only;
  ms->data.col_data.client_routine = 
    measure_mixed_omp_mpi_allreduce_barrier_only;

  /* for now, OpenMP only supports scalar reductions... */
  ms->data.col_data.len = sphinx_int_size;
  ms->data.col_data.communicator = MPI_COMM_WORLD;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) measure_mixed_omp_mpi_allreduce_barrier_only;
    ms->omp_data.schedule_routines_to_measure2[i] = 
      (void *) measure_mixed_omp_mpi_allreduce_barrier_only;
  }

  ms->data.col_data.result = NULL;
	
  initialize_col_aux (ms);

  initialize_omp_ms (ms);

  ms->pattern_in_omp_parallel = TRUE;

  return;
}

void 
p2p_init_omp_overlap (measurement_t *ms)
{
  int i;

  ms->pattern = P2P;
  ms->server_init = omp_init_one_buffer;
  ms->client_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;

  ms->data.p2p_data.server_op = server_omp_overlap;
  ms->data.p2p_data.client_op = server_omp_overlap;

  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) server_omp_overlap;
    ms->omp_data.schedule_routines_to_measure2[i] = 
      (void *) server_omp_overlap;
  }

  ms->data.p2p_data.result = NULL;

  initialize_p2p_aux (ms);

  initialize_omp_ms (ms);

  return;
}

extern MPI_Status client_Recv_and_ACK  (int msglen, 
					int node, MPI_Comm communicator);

void 
p2p_init_Isend_Recv_omp_overlap (measurement_t *ms)
{
  int i;

  ms->pattern = P2P;
  ms->server_init = omp_init_one_buffer;
  ms->client_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;

  ms->data.p2p_data.server_op = server_Isend_omp_overlap;
  ms->data.p2p_data.client_op = client_Recv_and_ACK;

  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) server_Isend_omp_overlap;
    ms->omp_data.schedule_routines_to_measure2[i] = 
      (void *) client_Recv_and_ACK;
  }

  ms->data.p2p_data.result = NULL;

  initialize_p2p_omp_overlap_aux (ms);

  initialize_omp_ms (ms);

  return;
}

void 
p2p_init_Isend_Recv_both_omp_overlaps (measurement_t *ms)
{
  int i;

  ms->pattern = P2P;
  ms->server_init = omp_init_one_buffer;
  ms->client_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;

  ms->data.p2p_data.server_op = server_Isend_both_omp_overlaps;
  ms->data.p2p_data.client_op = client_Recv_and_ACK;

  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) server_Isend_both_omp_overlaps;
    ms->omp_data.schedule_routines_to_measure2[i] = 
      (void *) client_Recv_and_ACK;
  }

  ms->data.p2p_data.result = NULL;

  initialize_p2p_both_omp_overlaps_aux (ms);

  initialize_omp_ms (ms);

  return;
}

extern MPI_Status client_Send_and_recv_ACK  (int msglen, int node, 
					     MPI_Comm communicator);

void 
p2p_init_Irecv_Send_omp_overlap (measurement_t *ms)
{
  int i;

  ms->pattern = P2P;
  ms->server_init = omp_init_one_buffer;
  ms->client_init = omp_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;

  ms->data.p2p_data.server_op = server_Irecv_omp_overlap;
  ms->data.p2p_data.client_op = client_Send_and_recv_ACK;

  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  for (i = 0; i < SCHEDULE_COUNT; i++) {
    ms->omp_data.schedule_routines_to_measure[i] = 
      (void *) server_Irecv_omp_overlap;
    ms->omp_data.schedule_routines_to_measure2[i] = 
      (void *) client_Send_and_recv_ACK;
  }

  ms->data.p2p_data.result = NULL;

  initialize_p2p_omp_overlap_and_ack_aux (ms);

  initialize_omp_ms (ms);

  return;
}


int measure_omp_parallel_ref (void)
{
  work(work_param);

  return 0;
}

int measure_omp_parallel (void)
{
#pragma omp parallel
  {
    work(work_param);
  }

  return 0;
}

int measure_omp_parallel_for_ref (void)
{
  int j;

  for(j=0; j < schedule_loop_cap; j++) {
    work(work_param);
  }

  return 0;
}

int measure_omp_parallel_for_static (void)
{
  int j;

#pragma omp parallel for schedule(static)
  for(j=0; j < sphinx_omp_thread_count * schedule_loop_cap; j++) {
    work(work_param);
  }

  return 0;
}

int measure_omp_parallel_for_dynamic (void)
{
  int j;

#pragma omp parallel for schedule(dynamic)
  for(j=0; j < sphinx_omp_thread_count * schedule_loop_cap; j++) {
    work(work_param);
  }

  return 0;
}

int measure_omp_parallel_for_guided (void)
{
  int j;

#pragma omp parallel for schedule(guided)
  for(j=0; j < sphinx_omp_thread_count * schedule_loop_cap; j++) {
    work(work_param);
  }

  return 0;
}

int measure_omp_parallel_for_chunks_static (void)
{
  int j;

#pragma omp parallel for schedule(static,schedule_chunks)
  for(j=0; j < sphinx_omp_thread_count * schedule_loop_cap; j++) {
    work(work_param);
  }

  return 0;
}

int measure_omp_parallel_for_chunks_dynamic (void)
{
  int j;

#pragma omp parallel for schedule(dynamic,schedule_chunks)
  for(j=0; j < sphinx_omp_thread_count * schedule_loop_cap; j++) {
    work(work_param);
  }

  return 0;
}

int measure_omp_parallel_for_chunks_guided (void)
{
  int j;

#pragma omp parallel for schedule(guided,schedule_chunks)
  for(j=0; j < sphinx_omp_thread_count * schedule_loop_cap; j++) {
    work(work_param);
  }

  return 0;
}

int measure_omp_ordered_ref (void)
{
  int i;

#pragma omp for schedule(dynamic)
  for (i = 0; i < max_iters; i++)
    work(work_param);

  return 0;
}

int measure_omp_ordered_only (void)
{
  int i;

#pragma omp for ordered schedule(dynamic)
  for (i = 0; i < max_iters; i++)
    work(work_param);

  return 0;
}

int measure_omp_ordered (void)
{
  int i;

#pragma omp for ordered schedule(dynamic)
  for (i = 0; i < max_iters; i++)
#pragma omp ordered
    work(work_param);

  return 0;
}

int measure_omp_single_ref (void)
{
  int i;

  for (i = 0; i < max_iters; i++)
    work(work_param);

  return 0;
}

int measure_omp_single (void)
{
  int i;

  for (i = 0; i < max_iters; i++)
#pragma omp single
    work(work_param);

  return 0;
}

int measure_omp_barrier (void)
{
  int i;

  for (i = 0; i < max_iters; i++) {
#pragma omp barrier
    work(work_param);
  }

  return 0;
}

int measure_omp_reduction_ref (void)
{
  int j, retval = 0;

  for(j=0; j < schedule_loop_cap; j++) {
    retval += (work(work_param) == 0 ? 0: 1);
  }

  return retval;
}

int measure_omp_reduction (void)
{
  int j, retval = 0;

#pragma omp parallel for reduction(+: retval)
  for(j=0; j < schedule_loop_cap * sphinx_omp_thread_count; j++) {
    retval += (work(work_param) == 0 ? 0: 1);
  }

  return retval;
}

int measure_omp_atomic_ref (void)
{
  sphinx_omp_reduce_var += 1;
  return work(work_param);
}

int measure_omp_atomic (void)
{
  int retval, i;

  for (i = 0; i < max_iters; i++) {
#pragma omp atomic
    sphinx_omp_reduce_var += 1;
    
    retval = work(work_param);
  }

  return retval;
}

void measure_mixed_omp_mpi_barrier (int len, MPI_Comm communicator)
{
  int i;

  for (i = 0; i < max_iters; i++) {
    mixed_omp_mpi_barrier (communicator);
    work(work_param);
  }
}

void measure_mixed_omp_mpi_barrier_only (int len, MPI_Comm communicator)
{
  mixed_omp_mpi_barrier (communicator);
}

void measure_mixed_omp_mpi_allreduce (int len, MPI_Comm communicator)
{
  int j;

  sphinx_omp_reduce_var = 0;

#pragma omp parallel for reduction(+: sphinx_omp_reduce_var)
  for(j=0; j < schedule_loop_cap * sphinx_omp_thread_count; j++) {
    sphinx_omp_reduce_var = sphinx_omp_reduce_var + 1;
    work(work_param);
  }

  gretval = MPI_Allreduce(&sphinx_omp_reduce_var, 
			  &sphinx_mixed_omp_mpi_reduce_var, 
			  1, MPI_INT, MPI_SUM, communicator);
}

void measure_mixed_omp_mpi_allreduce_only (int len, MPI_Comm communicator)
{
  mixed_omp_mpi_allreduce_only (communicator);
}

void measure_mixed_omp_mpi_allreduce_barrier_only (int len, 
						   MPI_Comm communicator)
{
  mixed_omp_mpi_allreduce_barrier_only (communicator);
}

MPI_Status 
server_omp_overlap (int msglen, int node, MPI_Comm communicator)
{
  MPI_Status  status;

  sphinx_omp_reduce_var = omp_overlap();

  /* this can lead to compiler warnings... */
  return (status);
}

MPI_Status 
server_Irecv_omp_overlap (int msglen, int node, MPI_Comm communicator)
{
  MPI_Status  status;
  MPI_Request req;
  int         ack_buf;

  MPI_Irecv (_sphinx_buffer, msglen, MPI_CHAR, 
	     node, 0, communicator, &req);

  sphinx_omp_reduce_var = omp_overlap();

  MPI_Wait (&req, &status);

  MPI_Send (&ack_buf, 4, MPI_BYTE, node, P2P_ACK_TAG, communicator);
  
  return (status);
}

MPI_Status 
server_Isend_omp_overlap (int msglen, int max_node, MPI_Comm communicator)
{
  MPI_Status  status;
  MPI_Request req;
  int         ack_buf;

  MPI_Isend (_sphinx_buffer, msglen, MPI_CHAR, 
	     max_node, 0, communicator, &req);

  sphinx_omp_reduce_var = omp_overlap();

  MPI_Wait (&req, &status);
  MPI_Recv(&ack_buf, 4, MPI_BYTE, max_node, 
	   P2P_ACK_TAG, communicator, &status);

  return (status);
}

/* THIS REALLY NEEDS A DUPLICATE omp_parallel_overlap */
/* THAT USES ALTERNATE PARAMETERS AND VARIABLES... */
MPI_Status 
server_Isend_both_omp_overlaps (int msglen, int max_node, 
				MPI_Comm communicator)
{
  MPI_Status  status;
  MPI_Request req;
  int         ack_buf;

  MPI_Isend (_sphinx_buffer, msglen, MPI_CHAR, 
	     max_node, 0, communicator, &req);

  sphinx_omp_reduce_var = omp_overlap();

  MPI_Wait (&req, &status);

  sphinx_omp_reduce_var = omp_overlap();

  MPI_Recv(&ack_buf, 4, MPI_BYTE, max_node, P2P_ACK_TAG, 
	   communicator, &status);

  return (status);
}


#endif /* _HAVE_OMP_ */
