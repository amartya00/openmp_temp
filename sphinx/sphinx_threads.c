/*
$Log: sphinx_threads.c,v $
Revision 1.20  2000/09/15 00:05:00  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.19  2000/09/06 21:09:13  bronis
Added several OpenMP versions for Alpha clusters in various states of correctness

Revision 1.18  2000/08/25 23:17:18  bronis
Added OpenMP tests

Revision 1.17  2000/03/16 15:48:40  bronis
fixed mpguidec warnings

Revision 1.16  2000/01/14 23:34:55  bronis
purified recent changes

Revision 1.15  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.14  1999/10/18 16:36:36  bronis
fixed multitiming bug

Revision 1.13  1999/10/01 21:36:53  bronis
Added debugged Root variation

Revision 1.12  1999/09/29 00:23:49  bronis
removed most restrictions on ACKER variation

Revision 1.11  1999/09/21 15:59:51  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.10  1999/09/20 19:00:40  srtaylor
Merged measure and measure_suite

Revision 1.9  1999/09/17 23:03:01  bronis
Split BINDING variation

Revision 1.8  1999/09/16 23:26:03  bronis
fixed fill_dummy_values calls

Revision 1.7  1999/09/16 21:07:44  srtaylor
Added max_message_len check

Revision 1.6  1999/09/14 16:38:52  srtaylor
First cut at multiple dimensions

Revision 1.5  1999/08/13 17:14:18  bronis
Added PDPTA input files

Revision 1.4  1999/08/10 20:51:04  bronis
Added priority chart

Revision 1.3  1999/07/30 19:49:54  bronis
Eliminated minor bug in Pthread_mt_mutex_pingpong_no_client-binding

Revision 1.2  1999/07/30 16:55:13  bronis
Fixed conflict between STOP_SIGNAL and UNBIND

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#include "sphinx.h"
#include "sphinx_aux.h"
#include "simple_test1.h"
#include "pattern.h"
#include "sphinx_error.h"
#include "sphinx_mem.h"
#include "sphinx_threads.h"
#include "automeasure.h"
#include "autodist.h"
#include "sphinx_aux_test.h"


#define ITERS_PER_TESTCANCEL     1000
#define NUM_LOCKS                4

#define CLIENT_SCOPE_SYSTEM      1
#define CLIENT_STATE_UNDETACHED  2

int iter_count, max_iters;
volatile int ready;
pthread_cond_t condition;
pthread_cond_t discard_condition;
pthread_mutex_t mutex;
pthread_mutex_t mutex_array_0;
pthread_mutex_t mutex_array_1;
pthread_mutex_t mutex_array_2;
pthread_mutex_t mutex_array_3;
pthread_mutex_t mutex_array_4;
pthread_mutex_t mutex_array_5;
pthread_mutex_t mutex_array_6;
pthread_mutex_t mutex_array_7;
pthread_mutex_t mutex_array_8;
pthread_mutex_t mutex_array_9;
pthread_mutex_t mutex_true_array[NUM_LOCKS];
pthread_mutex_t *mutex_ptr;
pthread_attr_t client_attr;

/* I use this to be able to cancel the spawned thread */
/* Using a global works as long as there is only one thread at a time */
/* that you will want to cancel; should eventually save in ms... */
static pthread_t	client;

/* I use this for the pthread_create tests... */
static pthread_t	*clients = NULL;
static void             *client_status;

int measure_inside_dummy ();

static void * create_client_func( void * data );
int measure_create( void );

static void * condition_client_func( void * data );
int measure_condition( void );

static void * cond_signal_client_func( void * data );
int measure_cond_signal( void );

static void * cond_wait_client_func( void * data );
static void * cond_wait_testcancel_client_func( void * data );
int measure_cond_wait( void );

int measure_lock_unlock( void );
int measure_lock_unlock_twice( void );
int measure_lock_unlock_thrice( void );
int measure_lock_unlock_4times( void );

static void * timeslice_client_func( void * data );
int measure_timeslice( void );

static void * yield_client_func( void * data );
int measure_yield( void );

static void * mutex_pingpong_client_func( void * data );
int measure_mutex_pingpong( void );
int measure_mutex_lock_unlock_2locks( void );
int measure_mutex_lock_unlock_3locks( void );
int measure_mutex_lock_unlock_5locks( void );
int measure_mutex_lock_unlock_6locks( void );
int measure_mutex_lock_unlock_7locks( void );
int measure_mutex_lock_unlock_8locks( void );
int measure_mutex_lock_unlock_9locks( void );
int measure_mutex_lock_unlock_10locks( void );
static void * mutexarray_pingpong_client_func( void * data );
int measure_mutexarray_pingpong( void );
int measure_mt_mutex_pingpong( void );
int measure_mt_mutex_lock_unlock( void );

int measure_lock( void );
int measure_unlock( void );


void
multitiming_destroy (void *the_ms)
{
  measurement_t *ms = (measurement_t *) the_ms;

  generic_destroy (the_ms);

  if (ms->data.multitiming_data.routines_to_measure != NULL)
    free (ms->data.multitiming_data.routines_to_measure);

  if (ms->data.multitiming_data.client_routines != NULL)
    free (ms->data.multitiming_data.client_routines);

  return;
}


int
get_max_iters_value (measurement_t *ms)
{
  switch (ms->pattern) {
  case COLLECTIVE:
    /* this isn't really set up yet... */
    return ms->data.col_data.iters;
  case SIMPLE:
  case THREAD_CHAIN:
    return ms->iters_per_time * 
      (ms->iters_over_nodes ? ms->data.simple_data.iter_factor : 1);
  case MULTITIMING:
    return ms->iters_per_time * 
      (ms->iters_over_nodes ? ms->data.multitiming_data.iter_factor : 1);
  default:
    ERROR (INTERN, "Invalid pattern in get_max_iters_value");
    output_error (FALSE);
    return ms->iters_per_time;
  }
}


/* this is a server_init function; it will spawn threads and */
/* bind them to processors as necessary... */
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
thread_init_one_buffer (int nor, int nom, int nop, measurement_t *ms)
{
  int	error;
  int	server_cpu, client_cpu;
  
  D(fprintf(stderr,"proc %d: in thread_init_one_buffer\n",_sphinx_myid);)

  /* Get desired cpu bindings... */  
  if (ms == NULL)  {
    sprintf (_sphinx_msg,
             "NULL ms in thread_init_one_buffer; not binding threads\n");
    ERROR (INTERN,_sphinx_msg);
    output_error (FALSE);
    
    server_cpu = client_cpu = UNBIND;
  }
  else {
    if (ms->pattern == SIMPLE) {
      server_cpu = ms->data.simple_data.server_cpu;
      client_cpu = ms->data.simple_data.client_cpu;
    }
    else if (ms->pattern == MULTITIMING) {
      server_cpu = ms->data.multitiming_data.server_cpu;
      client_cpu = ms->data.multitiming_data.client_cpu;
    }
    else {
      /* default to unbound... */
      server_cpu = client_cpu = UNBIND;
    }
  }
      
  ready = 0;

  error = BIND( server_cpu );
  if( error ) printf( "Server error from BIND is %d\n", error );

  pthread_mutex_init( &mutex, NULL );
  pthread_cond_init( &condition, NULL );

  pthread_mutex_lock( &mutex );

  if (((ms->pattern == SIMPLE) && 
       (ms->data.simple_data.client_routine != NULL)) ||
      ((ms->pattern == MULTITIMING) && 
       (ms->data.multitiming_data.client_routines != NULL))) {
    if (ms->pattern == SIMPLE) {
      pthread_create( &client, NULL, 
		      ms->data.simple_data.client_routine, 
		      (void *) &client_cpu );
    }
    else if (ms->pattern == MULTITIMING) {
      pthread_create( &client, NULL, 
		      ms->data.multitiming_data.call_client_routines, 
		      (void *) &client_cpu );
    }

/**
    printf( "Server running on CPU %d\n", GETCPU() );
**/

    /* Wait for ping from client */
    while( !ready ) {
      pthread_cond_wait( &condition, &mutex );
    }
    ready = 0;
  }
	
  return (mem_init_one_buffer(nor, nom, nop, ms));
}

long int 
thread_init_no_create (int nor, int nom, int nop, measurement_t *ms)
{
  int	error;
  int	server_cpu;
  
  D(fprintf(stderr,"proc %d: in thread_init_no_create\n",_sphinx_myid);)

  /* Get desired cpu bindings... */  
  if (ms == NULL)  {
    sprintf (_sphinx_msg,
             "NULL ms in thread_init_one_buffer; not binding threads\n");
    ERROR (INTERN,_sphinx_msg);
    output_error (FALSE);
    
    server_cpu = UNBIND;
  }
  else {
    if (ms->pattern == SIMPLE) {
      server_cpu = ms->data.simple_data.server_cpu;
    }
    else if (ms->pattern == MULTITIMING) {
      server_cpu = ms->data.multitiming_data.server_cpu;
    }
    else {
      /* default to unbound... */
      server_cpu = UNBIND;
    }
  }
      
  ready = 0;

  error = BIND( server_cpu );
  if( error ) printf( "Server error from BIND is %d\n", error );

  pthread_mutex_init( &mutex, NULL );
  pthread_cond_init( &condition, NULL );

  pthread_attr_init( &client_attr );

  if (ms->client_scope_and_detachedstate & CLIENT_SCOPE_SYSTEM) 
    pthread_attr_setscope (&client_attr, PTHREAD_SCOPE_SYSTEM);
  else
    pthread_attr_setscope (&client_attr, PTHREAD_SCOPE_PROCESS);

  if (ms->client_scope_and_detachedstate & CLIENT_STATE_UNDETACHED) 
    pthread_attr_setdetachstate (&client_attr, PTHREAD_CREATE_JOINABLE);
  else
    pthread_attr_setdetachstate (&client_attr, PTHREAD_CREATE_DETACHED);

  pthread_mutex_lock( &mutex );

  return (mem_init_one_buffer(nor, nom, nop, ms));
}

long int 
thread_init_multi_clients (int nor, int nom, int nop, measurement_t *ms)
{
  max_iters = get_max_iters_value (ms);

  clients = (pthread_t *) malloc (sizeof(pthread_t) * max_iters);

  return thread_init_no_create (nor, nom, nop, ms);
}

/* Not currently used... */
long int 
thread_init_one_buffer_pass_iters (int nor, int nom, int nop, measurement_t *ms)
{
  int	error;
  int	server_cpu, client_data[2];
  
  D(fprintf(stderr,"proc %d: in thread_init_one_buffer\n",_sphinx_myid);)

  /* Get desired cpu bindings... */  
  if (ms == NULL)  {
    sprintf (_sphinx_msg,
             "NULL ms in thread_init_one_buffer_pass_iters!!!!\n");
    ERROR (INTERN,_sphinx_msg);
    output_error (TRUE);
  }
  else {
    if (ms->pattern == SIMPLE) {
      server_cpu = ms->data.simple_data.server_cpu;
      client_data[0] = ms->data.simple_data.client_cpu;
    }
    else if (ms->pattern == MULTITIMING) {
      server_cpu = ms->data.multitiming_data.server_cpu;
      client_data[0] = ms->data.multitiming_data.client_cpu;
    }
    else {
      /* default to unbound... */
      server_cpu = client_data[0] = UNBIND;
    }

    client_data[1] = ms->iters_per_time;
  }
      
  ready = 0;

  error = BIND( server_cpu );
  if( error ) printf( "Server error from BIND is %d\n", error );

  pthread_mutex_init( &mutex, NULL );
  pthread_cond_init( &condition, NULL );

  pthread_mutex_lock( &mutex );

  if (((ms->pattern == SIMPLE) && 
       (ms->data.simple_data.client_routine != NULL)) ||
      ((ms->pattern == MULTITIMING) && 
       (ms->data.multitiming_data.client_routines != NULL))) {
    if (ms->pattern == SIMPLE) {
      pthread_create( &client, NULL, 
		      ms->data.simple_data.client_routine, 
		      (void *) client_data );
    }
    else if (ms->pattern == MULTITIMING) {
      pthread_create( &client, NULL, 
		      ms->data.multitiming_data.call_client_routines, 
		      (void *) client_data );
    }

/**
    printf( "Server running on CPU %d\n", GETCPU() );
**/

    /* Wait for ping from client */
    while( !ready ) {
      pthread_cond_wait( &condition, &mutex );
    }
    ready = 0;
  }
	
  return (mem_init_one_buffer(nor, nom, nop, ms));
}

long int 
thread_init_two_conds (int nor, int nom, int nop, measurement_t *ms)
{
  pthread_cond_init( &discard_condition, NULL );

  return thread_init_one_buffer (nor, nom, nop, ms);
}

long int 
thread_init_lock_array (int nor, int nom, int nop, measurement_t *ms)
{
  pthread_mutex_init( &mutex_array_0, NULL );
  pthread_mutex_init( &mutex_array_1, NULL );
  pthread_mutex_init( &mutex_array_2, NULL );
  pthread_mutex_init( &mutex_array_3, NULL );
  pthread_mutex_init( &mutex_array_4, NULL );
  pthread_mutex_init( &mutex_array_5, NULL );
  pthread_mutex_init( &mutex_array_6, NULL );
  pthread_mutex_init( &mutex_array_7, NULL );
  pthread_mutex_init( &mutex_array_8, NULL );
  pthread_mutex_init( &mutex_array_9, NULL );

  pthread_mutex_lock( &mutex_array_0 );
  pthread_mutex_lock( &mutex_array_2 );
  pthread_mutex_lock( &mutex_array_4 );
  pthread_mutex_lock( &mutex_array_6 );
  pthread_mutex_lock( &mutex_array_8 );

  return thread_init_one_buffer (nor, nom, nop, ms);
}

long int 
thread_init_lock_true_array (int nor, int nom, int nop, measurement_t *ms)
{
  int  i;

  for (i = 0; i < NUM_LOCKS; i++) {
    pthread_mutex_init( &mutex_true_array[i], NULL );

    if (!(i % 2)) {
      /* lock the even ones... */
      pthread_mutex_lock( &mutex_true_array[i] );
    }
  }

  return thread_init_one_buffer (nor, nom, nop, ms);
}

long int 
thread_init_lotsa_locks (int nor, int nom, int nop, measurement_t *ms)
{
  int	i;
  
  max_iters = get_max_iters_value (ms);

  mutex_ptr = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) * max_iters);

  for (i = 0; i < max_iters; i++) {
    pthread_mutex_init( &mutex_ptr[i], NULL );
  }

  return thread_init_one_buffer (nor, nom, nop, ms);
}

long int 
thread_init_lotsa_locks_b (int nor, int nom, int nop, measurement_t *ms)
{
  int	i;

  max_iters = get_max_iters_value (ms);

  if (max_iters % 2) {
    fprintf (stderr,
	     "Even number of iterations expected in %s\n", ms->name);
    fprintf (stderr, "Increasing max_iters; results may be incorrect\n");
    max_iters++;
  }
  
  mutex_ptr = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) * max_iters);

  for (i = 0; i < max_iters; i++) {
    pthread_mutex_init( &mutex_ptr[i], NULL );

    if (!(i % 2)) {
      pthread_mutex_lock ( &mutex_ptr[i] );
    }
  }

  return thread_init_one_buffer (nor, nom, nop, ms);
}

/* This routine cancels the client thread and then releases sphinx memory */
/* It assumes that the server thread is (or soon will be) at a cancellation */
/* point; this is true for pthread_cond_wait by defintion... */
void
thread_mem_release (measurement_t *ms)
{
  int	error;
  
  if (((ms->pattern == SIMPLE) && 
       (ms->data.simple_data.client_routine != NULL)) ||
      ((ms->pattern == MULTITIMING) && 
       (ms->data.multitiming_data.client_routines != NULL))) {
    error = pthread_cancel (client);
    if( error ) printf( "Server error from pthread_cancel is %d\n", error );

    ready = 0;

    /* signal condition to wake up client if necessary... */
    pthread_cond_signal( &condition );
  
    /* Wait for ping from client */
    while(ready != 2) {
      /* printf ("Waiting on client...\n"); */
      pthread_cond_wait( &condition, &mutex );
    }
  
/*    if (!(pthread_kill (client, 0))) 
      printf ("Client still valid tid...\n");
    else 
      printf ("Client no longer valid tid...\n"); */
  }

  pthread_mutex_unlock( &mutex );
    
  pthread_mutex_destroy( &mutex );
  pthread_cond_destroy( &condition );
  
  mem_release(ms);
}

void
thread_mem_release_no_cancel (measurement_t *ms)
{
  if (clients != NULL) {
    free (clients);
    clients = NULL;
  }

  pthread_mutex_unlock( &mutex );
    
  pthread_mutex_destroy( &mutex );
  pthread_cond_destroy( &condition );
  
  pthread_attr_destroy( &client_attr );

  mem_release(ms);
}

/*this routine assumes max_iters is correctly set... */
void
thread_chain_join (void)
{
  int	i;
  
  if (clients != NULL) {
    for (i = 0; i < max_iters; i++)
      pthread_join (clients[i], &client_status);
  }

  return;
}

/*this routine assumes max_iters is correctly set... */
void
thread_chain_cancel (void)
{
  int	i;
  
  if (clients != NULL) {
    for (i = 0; i < max_iters; i++)
      pthread_cancel (clients[i]);
  }

  return;
}

void
thread_mem_release_two_conds (measurement_t *ms)
{
  thread_mem_release(ms);
  
  pthread_cond_destroy( &discard_condition );

  return;
}  

void
thread_mem_release_lock_array (measurement_t *ms)
{
  /* give up locks so client can reach cancellation point */
  pthread_mutex_unlock( &mutex_array_0 );
  pthread_mutex_unlock( &mutex_array_2 );
  pthread_mutex_unlock( &mutex_array_4 );
  pthread_mutex_unlock( &mutex_array_6 );
  pthread_mutex_unlock( &mutex_array_8 );

  thread_mem_release(ms);
  
  /* destroy lock array... */
  pthread_mutex_destroy( &mutex_array_0 );
  pthread_mutex_destroy( &mutex_array_1 );
  pthread_mutex_destroy( &mutex_array_2 );
  pthread_mutex_destroy( &mutex_array_3 );
  pthread_mutex_destroy( &mutex_array_4 );
  pthread_mutex_destroy( &mutex_array_5 );
  pthread_mutex_destroy( &mutex_array_6 );
  pthread_mutex_destroy( &mutex_array_7 );
  pthread_mutex_destroy( &mutex_array_8 );
  pthread_mutex_destroy( &mutex_array_9 );

  return;
}

void
thread_mem_release_lock_true_array (measurement_t *ms)
{
  int	i;
  
  /* give up locks so client can reach cancellation point */
  for (i = 0; i < NUM_LOCKS; i += 2) {
    pthread_mutex_unlock( &mutex_true_array[i] );
  }

  thread_mem_release(ms);
  
  /* destroy lock array... */
  for (i = 0; i < NUM_LOCKS; i++) {
    pthread_mutex_destroy( &mutex_true_array[i] );
  }

  return;
}

void
thread_mem_release_lotsa_locks (measurement_t *ms)
{
  int	i;
  
  thread_mem_release(ms);
  
  /* destroy locks... */
  for (i = 0; i < max_iters; i++) {
    pthread_mutex_destroy( &mutex_ptr[i] );
  }

  free (mutex_ptr);

  return;
}

void
thread_mem_release_lotsa_locks_b (measurement_t *ms)
{
  int	i;
    
  /* give up locks so client can reach cancellation point */
  for (i = 0; i < max_iters; i += 2) {
    pthread_mutex_unlock( &mutex_ptr[i] );
  }

  thread_mem_release(ms);
  
  /* destroy locks... */
  for (i = 0; i < max_iters; i++) {
    pthread_mutex_destroy( &mutex_ptr[i] );
  }

  free (mutex_ptr);

  return;
}

void 
simple_init_inside_dummy (measurement_t *ms)
{
  ms->pattern = THREAD_CHAIN;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;
 
  ms->data.simple_data.routine_to_measure = measure_inside_dummy;
  ms->data.simple_data.result = NULL;

  /* NOTE DO NOT USE CORRECTION ON THIS SINCE IT IS THE OVERHEAD... */

  return;
}

void thread_chain_init_thread_create( measurement_t * ms )
{
  ms->pattern = THREAD_CHAIN;
  ms->server_init = thread_init_multi_clients;
  ms->server_free = thread_mem_release_no_cancel;
  ms->iter_cleanup = thread_chain_cancel;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_create;
  ms->data.simple_data.client_routine = create_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  initialize_simple_inside_aux (ms);

  return;
}

void thread_chain_init_thread_create_sys( measurement_t * ms )
{
  ms->pattern = THREAD_CHAIN;
  ms->server_init = thread_init_multi_clients;
  ms->server_free = thread_mem_release_no_cancel;
  ms->iter_cleanup = thread_chain_cancel;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_create;
  ms->data.simple_data.client_routine = create_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* make use system scope... */
  ms->client_scope_and_detachedstate |= CLIENT_SCOPE_SYSTEM;

  initialize_simple_inside_aux (ms);

  return;
}

void thread_chain_init_thread_create_u( measurement_t * ms )
{
  ms->pattern = THREAD_CHAIN;
  ms->server_init = thread_init_multi_clients;
  ms->server_free = thread_mem_release_no_cancel;
  ms->iter_cleanup = thread_chain_join;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_create;
  ms->data.simple_data.client_routine = create_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* make use undetached state... */
  ms->client_scope_and_detachedstate |= CLIENT_STATE_UNDETACHED;

  initialize_simple_inside_aux (ms);

  return;
}

void thread_chain_init_thread_create_usys( measurement_t * ms )
{
  ms->pattern = THREAD_CHAIN;
  ms->server_init = thread_init_multi_clients;
  ms->server_free = thread_mem_release_no_cancel;
  ms->iter_cleanup = thread_chain_join;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_create;
  ms->data.simple_data.client_routine = create_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* make use system scope, undetached state... */
  ms->client_scope_and_detachedstate |= 
    CLIENT_SCOPE_SYSTEM | CLIENT_STATE_UNDETACHED;

  initialize_simple_inside_aux (ms);

  return;
}

void multitiming_init_lock_unlock( measurement_t * ms )
{
  ms->pattern = MULTITIMING;
  ms->destroy = multitiming_destroy;
  ms->server_init = thread_init_lotsa_locks;
  ms->server_free = thread_mem_release_lotsa_locks;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.multitiming_data.num_timings = 2;
  ms->data.multitiming_data.routines_to_measure =
    (my_f_ptr_t *) malloc (sizeof(my_f_ptr_t) * 2);
  ms->data.multitiming_data.routines_to_measure[0] = measure_lock;
  ms->data.multitiming_data.routines_to_measure[1] = measure_unlock;
  ms->data.multitiming_data.client_routines = NULL;
  ms->data.multitiming_data.call_client_routines = NULL;
  ms->data.multitiming_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.multitiming_data.server_cpu = UNBIND;
  ms->data.multitiming_data.client_cpu = UNBIND;

  initialize_simple_aux (ms);

  return;
}

void multitiming_init_mutex_pingpong_noclient(measurement_t *ms)
{
  ms->pattern = MULTITIMING;
  ms->destroy = multitiming_destroy;
  ms->server_init = thread_init_lotsa_locks_b;
  ms->server_free = thread_mem_release_lotsa_locks_b;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  /* ensure max_iters is even... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.multitiming_data.iter_factor = 2; 

  ms->data.multitiming_data.num_timings = 1;
  ms->data.multitiming_data.routines_to_measure =
    (my_f_ptr_t *) malloc (sizeof(my_f_ptr_t));
  ms->data.multitiming_data.routines_to_measure[0] = 
    measure_mt_mutex_pingpong;
  ms->data.multitiming_data.client_routines = NULL;
  ms->data.multitiming_data.call_client_routines = NULL;
  ms->data.multitiming_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.multitiming_data.server_cpu = UNBIND;
  ms->data.multitiming_data.client_cpu = UNBIND;

  initialize_simple_aux (ms);

  return;
}

void multitiming_init_mutex_lock_unlock (measurement_t *ms)
{
  ms->pattern = MULTITIMING;
  ms->destroy = multitiming_destroy;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.multitiming_data.num_timings = 1;
  ms->data.multitiming_data.routines_to_measure =
    (my_f_ptr_t *) malloc (sizeof(my_f_ptr_t));
  ms->data.multitiming_data.routines_to_measure[0] = 
    measure_mt_mutex_lock_unlock;
  ms->data.multitiming_data.client_routines = NULL;
  ms->data.multitiming_data.call_client_routines = NULL;
  ms->data.multitiming_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.multitiming_data.server_cpu = UNBIND;
  ms->data.multitiming_data.client_cpu = UNBIND;

  initialize_simple_aux (ms);

  return;
}

void simple_init_condition( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_condition;
  ms->data.simple_data.client_routine = condition_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  initialize_simple_aux (ms);

  return;
}

/* This is a funky test; results when threads are bound to */
/* different CPU's are architecture dependent... */
void simple_init_timeslice( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_timeslice;
  ms->data.simple_data.client_routine = timeslice_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to binding to CPU 0; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = 0;
  ms->data.simple_data.client_cpu = 0;

  /* This makes reported number be time/2... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 2;

  initialize_simple_aux (ms);

  return;
}

void simple_init_cond_signal( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_two_conds;
  ms->server_free = thread_mem_release_two_conds;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_cond_signal;
  ms->data.simple_data.client_routine = cond_signal_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_pingpong( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_array;
  ms->server_free = thread_mem_release_lock_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutex_pingpong;
  ms->data.simple_data.client_routine = mutex_pingpong_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/4... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 4;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_pingpong_no_client( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_array;
  ms->server_free = thread_mem_release_lock_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutex_pingpong;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/4... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 4;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutexarray_pingpong( measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_true_array;
  ms->server_free = thread_mem_release_lock_true_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutexarray_pingpong;
  ms->data.simple_data.client_routine = mutexarray_pingpong_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/NUM_LOCKS... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = NUM_LOCKS;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutexarray_pingpong_no_client(measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_true_array;
  ms->server_free = thread_mem_release_lock_true_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutexarray_pingpong;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/NUM_LOCKS... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = NUM_LOCKS;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_2locks(measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_array;
  ms->server_free = thread_mem_release_lock_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutex_lock_unlock_2locks;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/2, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 2;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_3locks(measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_array;
  ms->server_free = thread_mem_release_lock_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutex_lock_unlock_3locks;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/3, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 3;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_5locks(measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_array;
  ms->server_free = thread_mem_release_lock_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutex_lock_unlock_5locks;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/5, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 5;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_6locks(measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_array;
  ms->server_free = thread_mem_release_lock_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutex_lock_unlock_6locks;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/6, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 6;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_7locks(measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_array;
  ms->server_free = thread_mem_release_lock_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutex_lock_unlock_7locks;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/7, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 7;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_8locks(measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_array;
  ms->server_free = thread_mem_release_lock_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutex_lock_unlock_8locks;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/8, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 8;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_9locks(measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_array;
  ms->server_free = thread_mem_release_lock_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutex_lock_unlock_9locks;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/9, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 9;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_10locks(measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_lock_array;
  ms->server_free = thread_mem_release_lock_array;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_mutex_lock_unlock_10locks;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/10, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 10;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock (measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_lock_unlock;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_twice (measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_lock_unlock_twice;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/2, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 2;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_thrice (measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_lock_unlock_thrice;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/3, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 3;

  initialize_simple_aux (ms);

  return;
}

void simple_init_mutex_lock_unlock_4times( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_lock_unlock_4times;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  /* This makes reported number be time/4, the cost per lock/unlock pair... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 4;

  initialize_simple_aux (ms);

  return;
}

void simple_init_cond_signal_no_client( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_two_conds;
  ms->server_free = thread_mem_release_two_conds;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_cond_signal;
  ms->data.simple_data.client_routine = NULL;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  initialize_simple_aux (ms);

  return;
}

void simple_init_yield( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_yield;
  ms->data.simple_data.client_routine = yield_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to binding to CPU 0; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = 0;
  ms->data.simple_data.client_cpu = 0;

  /* This makes reported number be time/2... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 2;

  initialize_simple_aux (ms);

  return;
}

void proxy_init_yield( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_yield;
  ms->data.simple_data.client_routine = yield_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to binding to CPU 0; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = 0;
  ms->data.simple_data.client_cpu = 0;

  /* make it so the initial thread will NOT do measurement... */
  ms->uses_proxy = 1; /* TRUE */
  ms->need_to_create_proxy = 1; /* TRUE */

  /* This makes reported number be time/2... */
  ms->iters_over_nodes = 1; /* TRUE */
  ms->data.simple_data.iter_factor = 2;

  initialize_simple_aux (ms);

  return;
}

/* This doesn't seem to work (see note with cond_wait_client_func) */
/* I'll leave it here, but it is unaccessible since no measurement type */
/* is defined that uses this... */
void simple_init_cond_wait( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_cond_wait;
  ms->data.simple_data.client_routine = cond_wait_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  initialize_simple_aux (ms);

  return;
}

void simple_init_cond_wait_testcancel( measurement_t * ms )
{
  ms->pattern = SIMPLE;
  ms->server_init = thread_init_one_buffer;
  ms->server_free = thread_mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.simple_data.routine_to_measure = measure_cond_wait;
  ms->data.simple_data.client_routine = cond_wait_testcancel_client_func;
  ms->data.simple_data.result = NULL;
	
  /* Default to unbound threads; reset in call_binding functions... */
  ms->data.simple_data.server_cpu = UNBIND;
  ms->data.simple_data.client_cpu = UNBIND;

  initialize_simple_aux (ms);

  return;
}

int
measure_inside_dummy ()
{
  int i;

  for (i = 0; i < max_iters; i++);

  return i;
}

int measure_create()
{
  pthread_create( &clients[0], &client_attr, create_client_func, NULL);

  /* Wait for ping from last client... */
  while( !ready ) {
    pthread_cond_wait( &condition, &mutex );
  }
  ready = 0;
  return 0;
}


int measure_condition()
{
  /* Ping the client */
  pthread_cond_signal( &condition );

  /* Wait for ping from client */
  while( !ready ) {
    pthread_cond_wait( &condition, &mutex );
  }
  ready = 0;
  return 0;
}

int measure_timeslice()
{
  /* Spin until it's my turn... */
  while( !ready ) /* NULL */;
  ready = 0;
  return 0;
}


int measure_cond_signal()
{
  /* Ping the client */
  pthread_cond_signal( &discard_condition );
  return 0;
}

int measure_mutex_pingpong()
{
  pthread_mutex_unlock( &mutex_array_0 );
  pthread_mutex_lock( &mutex_array_1 );
  pthread_mutex_unlock( &mutex_array_2 );
  pthread_mutex_lock( &mutex_array_3 );
  pthread_mutex_unlock( &mutex_array_1 );
  pthread_mutex_lock( &mutex_array_0 );
  pthread_mutex_unlock( &mutex_array_3 );
  pthread_mutex_lock( &mutex_array_2 );
  return 0;
}

int measure_mutexarray_pingpong()
{
  int  i;

  for (i = 0; i < NUM_LOCKS; i += 2) {
    pthread_mutex_unlock( &mutex_true_array[i] );
    pthread_mutex_lock( &mutex_true_array[i+1] );
  }

  for (i = 0; i < NUM_LOCKS; i += 2) {
    pthread_mutex_unlock( &mutex_true_array[i+1] );
    pthread_mutex_lock( &mutex_true_array[i] );
  }
  return 0;
}

int measure_mutex_lock_unlock_2locks()
{
  pthread_mutex_unlock( &mutex_array_0 );
  pthread_mutex_lock( &mutex_array_1 );
  pthread_mutex_lock( &mutex_array_0 );
  pthread_mutex_unlock( &mutex_array_1 );
  return 0;
}

int measure_mutex_lock_unlock_3locks()
{
  pthread_mutex_unlock( &mutex_array_0 );
  pthread_mutex_lock( &mutex_array_1 );
  pthread_mutex_unlock( &mutex_array_2 );
  pthread_mutex_lock( &mutex_array_0 );
  pthread_mutex_unlock( &mutex_array_1 );
  pthread_mutex_lock( &mutex_array_2 );
  return 0;
}

int measure_mutex_lock_unlock_5locks()
{
  pthread_mutex_unlock( &mutex_array_0 );
  pthread_mutex_lock( &mutex_array_1 );
  pthread_mutex_unlock( &mutex_array_2 );
  pthread_mutex_lock( &mutex_array_3 );
  pthread_mutex_unlock( &mutex_array_4 );
  pthread_mutex_lock( &mutex_array_0 );
  pthread_mutex_unlock( &mutex_array_1 );
  pthread_mutex_lock( &mutex_array_2 );
  pthread_mutex_unlock( &mutex_array_3 );
  pthread_mutex_lock( &mutex_array_4 );
  return 0;
}

int measure_mutex_lock_unlock_6locks()
{
  pthread_mutex_unlock( &mutex_array_0 );
  pthread_mutex_lock( &mutex_array_1 );
  pthread_mutex_unlock( &mutex_array_2 );
  pthread_mutex_lock( &mutex_array_3 );
  pthread_mutex_unlock( &mutex_array_4 );
  pthread_mutex_lock( &mutex_array_5 );
  pthread_mutex_unlock( &mutex_array_1 );
  pthread_mutex_lock( &mutex_array_0 );
  pthread_mutex_unlock( &mutex_array_3 );
  pthread_mutex_lock( &mutex_array_2 );
  pthread_mutex_unlock( &mutex_array_5 );
  pthread_mutex_lock( &mutex_array_4 );
  return 0;
}

int measure_mutex_lock_unlock_7locks()
{
  pthread_mutex_unlock( &mutex_array_0 );
  pthread_mutex_lock( &mutex_array_1 );
  pthread_mutex_unlock( &mutex_array_2 );
  pthread_mutex_lock( &mutex_array_3 );
  pthread_mutex_unlock( &mutex_array_4 );
  pthread_mutex_lock( &mutex_array_5 );
  pthread_mutex_unlock( &mutex_array_6 );
  pthread_mutex_lock( &mutex_array_0 );
  pthread_mutex_unlock( &mutex_array_1 );
  pthread_mutex_lock( &mutex_array_2 );
  pthread_mutex_unlock( &mutex_array_3 );
  pthread_mutex_lock( &mutex_array_4 );
  pthread_mutex_unlock( &mutex_array_5 );
  pthread_mutex_lock( &mutex_array_6 );
  return 0;
}

int measure_mutex_lock_unlock_8locks()
{
  pthread_mutex_unlock( &mutex_array_0 );
  pthread_mutex_lock( &mutex_array_1 );
  pthread_mutex_unlock( &mutex_array_2 );
  pthread_mutex_lock( &mutex_array_3 );
  pthread_mutex_unlock( &mutex_array_4 );
  pthread_mutex_lock( &mutex_array_5 );
  pthread_mutex_unlock( &mutex_array_6 );
  pthread_mutex_lock( &mutex_array_7 );
  pthread_mutex_unlock( &mutex_array_1 );
  pthread_mutex_lock( &mutex_array_0 );
  pthread_mutex_unlock( &mutex_array_3 );
  pthread_mutex_lock( &mutex_array_2 );
  pthread_mutex_unlock( &mutex_array_5 );
  pthread_mutex_lock( &mutex_array_4 );
  pthread_mutex_unlock( &mutex_array_7 );
  pthread_mutex_lock( &mutex_array_6 );
  return 0;
}

int measure_mutex_lock_unlock_9locks()
{
  pthread_mutex_unlock( &mutex_array_0 );
  pthread_mutex_lock( &mutex_array_1 );
  pthread_mutex_unlock( &mutex_array_2 );
  pthread_mutex_lock( &mutex_array_3 );
  pthread_mutex_unlock( &mutex_array_4 );
  pthread_mutex_lock( &mutex_array_5 );
  pthread_mutex_unlock( &mutex_array_6 );
  pthread_mutex_lock( &mutex_array_7 );
  pthread_mutex_unlock( &mutex_array_8 );
  pthread_mutex_lock( &mutex_array_0 );
  pthread_mutex_unlock( &mutex_array_1 );
  pthread_mutex_lock( &mutex_array_2 );
  pthread_mutex_unlock( &mutex_array_3 );
  pthread_mutex_lock( &mutex_array_4 );
  pthread_mutex_unlock( &mutex_array_5 );
  pthread_mutex_lock( &mutex_array_6 );
  pthread_mutex_unlock( &mutex_array_7 );
  pthread_mutex_lock( &mutex_array_8 );
  return 0;
}

int measure_mutex_lock_unlock_10locks()
{
  pthread_mutex_unlock( &mutex_array_0 );
  pthread_mutex_lock( &mutex_array_1 );
  pthread_mutex_unlock( &mutex_array_2 );
  pthread_mutex_lock( &mutex_array_3 );
  pthread_mutex_unlock( &mutex_array_4 );
  pthread_mutex_lock( &mutex_array_5 );
  pthread_mutex_unlock( &mutex_array_6 );
  pthread_mutex_lock( &mutex_array_7 );
  pthread_mutex_unlock( &mutex_array_8 );
  pthread_mutex_lock( &mutex_array_9 );
  pthread_mutex_unlock( &mutex_array_1 );
  pthread_mutex_lock( &mutex_array_0 );
  pthread_mutex_unlock( &mutex_array_3 );
  pthread_mutex_lock( &mutex_array_2 );
  pthread_mutex_unlock( &mutex_array_5 );
  pthread_mutex_lock( &mutex_array_4 );
  pthread_mutex_unlock( &mutex_array_7 );
  pthread_mutex_lock( &mutex_array_6 );
  pthread_mutex_unlock( &mutex_array_9 );
  pthread_mutex_lock( &mutex_array_8 );
  return 0;
}

int measure_lock_unlock()
{
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &mutex );
  return 0;
}

int measure_lock_unlock_twice()
{
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &mutex );
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &mutex );
  return 0;
}

int measure_lock_unlock_thrice()
{
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &mutex );
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &mutex );
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &mutex );
  return 0;
}

int measure_lock_unlock_4times()
{
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &mutex );
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &mutex );
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &mutex );
  pthread_mutex_unlock( &mutex );
  pthread_mutex_lock( &mutex );
  return 0;
}

int measure_lock()
{
  int i;

  for (i = 0; i < max_iters; i++)
    pthread_mutex_lock( &mutex_ptr[i] );
  return 0;
}

int measure_unlock()
{
  int i;

  for (i = 0; i < max_iters; i++)
    pthread_mutex_unlock( &mutex_ptr[i] );
  return 0;
}

int measure_mt_mutex_pingpong()
{
  int  i;

  for (i = 0; i < max_iters; i += 2) {
    pthread_mutex_unlock( &mutex_ptr[i] );
    pthread_mutex_lock( &mutex_ptr[i+1] );
  }

  for (i = 0; i < max_iters; i += 2) {
    pthread_mutex_unlock( &mutex_ptr[i+1] );
    pthread_mutex_lock( &mutex_ptr[i] );
  }
  return 0;
}

int measure_mt_mutex_lock_unlock()
{
  int  i;

  for (i = 0; i < max_iters; i += 2) {
    pthread_mutex_unlock( &mutex );
    pthread_mutex_lock( &mutex );
  }

  for (i = 0; i < max_iters; i += 2) {
    pthread_mutex_unlock( &mutex );
    pthread_mutex_lock( &mutex );
  }
  return 0;
}

int measure_cond_wait()
{
  pthread_cond_wait( &condition, &mutex );
  return 0;
}

int measure_yield()
{
#ifdef SUN
  thr_yield();
#else
  sched_yield();
#endif
  return 0;
}

/* This thread will be killed by a call to pthread_cancel in */
/* thread_mem_release; the only cancellation point occurs at the */
/* pthread_cond_wait. Need a cancellation  handler that frees the */
/* mutex with pthread_mutex_unlock( &mutex ); Also want to signal */
/* server that cancel handling is in progress...*/
void client_func_cancel_handler (void *handler_arg)
{
  ready = 2;
  pthread_cond_signal( &condition ); 
  pthread_mutex_unlock( &mutex );
}

/* Use this handler if client doesn't own lock when receives cancel */
void client_func_cancel_handler_need_lock (void *handler_arg)
{
  pthread_mutex_lock( &mutex );
  client_func_cancel_handler (handler_arg);
}

void mutex_pingpong_client_func_cancel_handler (void *handler_arg)
{
  pthread_mutex_unlock( &mutex_array_1 );
  pthread_mutex_unlock( &mutex_array_3 );
  pthread_mutex_unlock( &mutex_array_5 );
  pthread_mutex_unlock( &mutex_array_7 );
  pthread_mutex_unlock( &mutex_array_9 );

  client_func_cancel_handler_need_lock (handler_arg);
}

void mutexarray_pingpong_client_func_cancel_handler (void *handler_arg)
{
  int  i;

  for (i = 1; i < NUM_LOCKS; i += 2) {
    pthread_mutex_unlock( &mutex_true_array[i] );
  }

  client_func_cancel_handler_need_lock (handler_arg);
}

void set_up_client (int client_cpu)
{
  int error;

  error = BIND( client_cpu );
  if( error ) printf( "Client error from BIND is %d errno = %d\n", 
		      error, errno );

  /* Get ready to ping the server */ 
  pthread_mutex_lock( &mutex );
  ready = 1;
	
  return;
}

void set_up_mutex_pingpong_client (int client_cpu)
{
  set_up_client(client_cpu);
	
  /* Get ready to ping the server */
  pthread_mutex_lock( &mutex_array_1 );
  pthread_mutex_lock( &mutex_array_3 );
  pthread_mutex_lock( &mutex_array_5 );
  pthread_mutex_lock( &mutex_array_7 );
  pthread_mutex_lock( &mutex_array_9 );
	
  return;
}


void * condition_client_func( void * data )
{
  int *client_cpu_ptr;
  
  client_cpu_ptr = (int *)data;
  set_up_client (*client_cpu_ptr);

  pthread_cleanup_push(client_func_cancel_handler, (void *) NULL);

  /* this can lead to compiler warnings; pthread_cancel terminates... */
  for( ; ; ) {
    /* Ping the server */
    pthread_cond_signal( &condition );

    while( ready ) {
      pthread_cond_wait( &condition, &mutex );
    }
    ready = 1;
  }
	
  /* This is never executed */
  printf ("EXECUTING DEAD CODE!!!\n");	
  pthread_cond_signal( &condition );
	
  /* Non-zero arg would do unlock in cancel handler... */
  pthread_cleanup_pop (0);
	
  pthread_mutex_unlock( &mutex );

  return 0;
}

void * create_client_func( void * data )
{
  /* this should probably be wrapped in a master construct for OpenMP */
  /* however, it currently should never be relevant... */
  if (++iter_count < max_iters) {
    /* Not done; create another and die... */
    pthread_create( &clients[iter_count], &client_attr, 
		    create_client_func, NULL);

    pthread_exit (NULL);
  }

  /* that's it; stop it now... */
  /* technically, could skip getting lock, but just to be sure... */
  pthread_mutex_lock( &mutex );

  ready = 1;
  pthread_cond_signal( &condition );

  pthread_mutex_unlock( &mutex );

  pthread_exit (NULL);

  /* because SGI's cc complains... */
  return NULL;
}

void * timeslice_client_func( void * data )
{
  int *client_cpu_ptr = (int *)data;

  set_up_client (*client_cpu_ptr);

  /* Ping the server */
  pthread_cond_signal( &condition );

  /* give up lock so server can receive signal */
  pthread_mutex_unlock( &mutex );

  pthread_cleanup_push(client_func_cancel_handler_need_lock, 
		       (void *) NULL);

  /* this can lead to compiler warnings; pthread_cancel terminates... */
  for( ; ; ) {
    /* Spin until it's my turn... */
    while( ready == 1) /* NULL */;
    pthread_testcancel ();
    ready = 1;
  }
	
  /* This is never executed */
  printf ("EXECUTING DEAD CODE!!!\n");	

  /* Non-zero arg would do unlock in cancel handler... */
  pthread_cleanup_pop (0);
	
  pthread_mutex_lock( &mutex );
  pthread_cond_signal( &condition );
	
  pthread_mutex_unlock( &mutex );

  return 0;
}

void * cond_signal_client_func( void * data )
{
  int *client_cpu_ptr;

  client_cpu_ptr = (int *)data;
  set_up_client (*client_cpu_ptr);

  pthread_cleanup_push(client_func_cancel_handler, (void *) NULL);

  /* Ping the server */
  pthread_cond_signal( &condition );

  /* this can lead to compiler warnings; pthread_cancel terminates... */
  for( ; ; ) {
    while( ready ) {
      pthread_cond_wait( &condition, &mutex );
    }
    ready = 1;
  }
	
  /* This is never executed */
  printf ("EXECUTING DEAD CODE!!!\n");	
  pthread_cond_signal( &condition );
	
  /* Non-zero arg would do unlock in cancel handler... */
  pthread_cleanup_pop (0);
	
  pthread_mutex_unlock( &mutex );

  return 0;
}

void * mutex_pingpong_client_func( void * data )
{
  int i;
  int *client_cpu_ptr;

  client_cpu_ptr = (int *)data;
  set_up_mutex_pingpong_client (*client_cpu_ptr);

  pthread_cleanup_push(mutex_pingpong_client_func_cancel_handler, 
		       (void *) NULL);

  /* Ping the server */
  pthread_cond_signal( &condition );

  /* give up lock so server can receive signal */
  pthread_mutex_unlock( &mutex );

  /* this can lead to compiler warnings; pthread_cancel terminates... */
  for( ; ; ) {
    for (i = 0; i < ITERS_PER_TESTCANCEL; i++) {
      pthread_mutex_lock( &mutex_array_0 );
      pthread_mutex_unlock( &mutex_array_1 );
      pthread_mutex_lock( &mutex_array_2 );
      pthread_mutex_unlock( &mutex_array_3 );
      pthread_mutex_lock( &mutex_array_1 );
      pthread_mutex_unlock( &mutex_array_0 );
      pthread_mutex_lock( &mutex_array_3 );
      pthread_mutex_unlock( &mutex_array_2 );
    }

    pthread_testcancel ();
  }
	
  /* This is never executed */
  printf ("EXECUTING DEAD CODE!!!\n");	
  pthread_cond_signal( &condition );
  
  /* Non-zero arg would do unlock in cancel handler... */
  pthread_cleanup_pop (0);
	
  pthread_mutex_unlock( &mutex_array_1 );
  pthread_mutex_unlock( &mutex_array_3 );
  pthread_mutex_unlock( &mutex_array_5 );
  pthread_mutex_unlock( &mutex_array_7 );
  pthread_mutex_unlock( &mutex_array_9 );

  return 0;
}

void * mutexarray_pingpong_client_func( void * data )
{
  int i, j;
  int *client_cpu_ptr;

  client_cpu_ptr = (int *)data;
  set_up_client(*client_cpu_ptr);

  for (j = 0; j < NUM_LOCKS; j += 2)
    pthread_mutex_lock( &mutex_true_array[j+1] );

  pthread_cleanup_push(mutexarray_pingpong_client_func_cancel_handler, 
		       (void *) NULL);

  /* Ping the server */
  pthread_cond_signal( &condition );

  /* give up lock so server can receive signal */
  pthread_mutex_unlock( &mutex );

  /* this can lead to compiler warnings; pthread_cancel terminates... */
  for( ; ; ) {
    for (i = 0; i < ITERS_PER_TESTCANCEL; i++) {
      for (j = 0; j < NUM_LOCKS; j += 2) {
	pthread_mutex_lock( &mutex_true_array[j] );
	pthread_mutex_unlock( &mutex_true_array[j+1] );
      }

      for (j = 0; j < NUM_LOCKS; j += 2) {
	pthread_mutex_lock( &mutex_true_array[j+1] );
	pthread_mutex_unlock( &mutex_true_array[j] );
      }
    }

    pthread_testcancel ();
  }
	
  /* This is never executed */
  printf ("EXECUTING DEAD CODE!!!\n");	
  pthread_cond_signal( &condition );
  
  /* Non-zero arg would do unlock in cancel handler... */
  pthread_cleanup_pop (0);
	
  for (j = 0; j < NUM_LOCKS; j += 2)
    pthread_mutex_unlock( &mutex_true_array[j+1] );

  return 0;
}

/* This doesn't seem to work; Is pthread_cond_signal asynchronous */
/* cancel safe? I get strange errors on the platform I've tried (DEC) */
void * cond_wait_client_func( void * data )
{
  int *client_cpu_ptr;

  client_cpu_ptr = (int *)data;
  set_up_client (*client_cpu_ptr);

  pthread_cleanup_push(client_func_cancel_handler_need_lock, (void *) NULL);

  /* Catch cancel immediately, so don't need pthread_testcancel... */
  pthread_setcanceltype (PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

  /* Ping the server */
  pthread_cond_signal( &condition );

  /* give up lock so server can receive signal */
  pthread_mutex_unlock( &mutex );

  /* this can lead to compiler warnings; pthread_cancel terminates... */
  for( ; ; ) {
    /* Ping the server */
    pthread_cond_signal( &condition );
  }
	
  /* This is never executed */
  printf ("EXECUTING DEAD CODE!!!\n");	
  pthread_cond_signal( &condition );
	
  /* Non-zero arg would do unlock in cancel handler... */
  pthread_cleanup_pop (0);
	
  pthread_mutex_unlock( &mutex );

  return 0;
}

void * cond_wait_testcancel_client_func( void * data )
{
  int i;
  int *client_cpu_ptr;

  client_cpu_ptr = (int *)data;
  set_up_client (*client_cpu_ptr);

  /* Ping the server */
  pthread_cond_signal( &condition );

  /* give up lock so server can receive signal */
  pthread_mutex_unlock( &mutex );

  pthread_cleanup_push(client_func_cancel_handler_need_lock, (void *) NULL);

  /* this can lead to compiler warnings; pthread_cancel terminates... */
  for( ; ; ) {
    for (i = 0; i < ITERS_PER_TESTCANCEL; i++) {
      /* Ping the server */
      pthread_cond_signal( &condition );
    }

    pthread_testcancel ();
  }
	
  /* This is never executed */
  printf ("EXECUTING DEAD CODE!!!\n");	

  /* Non-zero arg would do unlock in cancel handler... */
  pthread_cleanup_pop (0);
	
  pthread_mutex_lock( &mutex );
  pthread_cond_signal( &condition );
	
  pthread_mutex_unlock( &mutex );

  return 0;
}

void * yield_client_func( void * data )
{
  int i;
  int *client_cpu_ptr;

  client_cpu_ptr = (int *)data;
  set_up_client (*client_cpu_ptr);

  /* Ping the server */
  pthread_cond_signal( &condition );

  /* give up lock so server can receive signal */
  pthread_mutex_unlock( &mutex );

  pthread_cleanup_push(client_func_cancel_handler_need_lock, 
		       (void *) NULL);

  /* this can lead to compiler warnings; pthread_cancel terminates... */
  for( ; ; ) {
    for (i = 0; i < ITERS_PER_TESTCANCEL; i++) {
      /* Ping the server */
#ifdef SUN
      thr_yield();
#else
      sched_yield();
#endif
    }

    pthread_testcancel ();
  }
	
  /* This is never executed */
  printf ("EXECUTING DEAD CODE!!!\n");	

  /* Non-zero arg would do unlock in cancel handler... */
  pthread_cleanup_pop (0);
	
  pthread_mutex_lock( &mutex );
  pthread_cond_signal( &condition );
	
  pthread_mutex_unlock( &mutex );

  return 0;
}

int  _threadchain_myid;
 

/*
   @FUN:
   @DOES: the thread chain pattern.
   @PARAMETERS: th actual measurement (which sould be one of the 
   simple pattern).
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: none.
*/
int
thread_chain_pattern (measurement_t *ms, int n)
{
  int
    arg;

  double 
    start_time,
    end_time = 0,
    org_time,
    tbm_time;

#ifdef _HAVE_OMP_
  if (ms->pattern_in_omp_parallel)
    {
      {
#pragma omp master
	{
	  MPI_Comm_rank(ms->communicator,&_threadchain_myid);
	}
      }
      {
#pragma omp barrier
      }
    }
  else
#endif
    MPI_Comm_rank(ms->communicator,&_threadchain_myid);

  switch (ms->dimensions[n].variation) {
  case MASTER_BINDING:
    arg = ms->data.simple_data.server_cpu;
    break;
  case SLAVE_BINDING:
    arg = ms->data.simple_data.client_cpu;
    break;
  case THREADS:
    arg = ms->omp_data.thread_count;
    break;
  case WORK_AMOUNT:
    arg = ms->omp_data.work_amount;
    break;
  case WORK_FUNCTION:
    arg = ms->omp_data.which_work;
    break;
  case OVERLAP_FUNCTION:
    arg = ms->omp_data.which_overlap;
    break;
  case SCHED_CAP:
    arg = ms->omp_data.cap_for_schedule_loops;
    break;
  case SCHED_CHUNKS:
    arg = ms->omp_data.schedule_chunks;
    break;
  case SCHEDULE:
    arg = ms->omp_data.loop_schedule;
    break;
  case ITERS:
    arg = ms->data.simple_data.iters;
    break;
  case NO_VARIATION:
    arg = NO_VARIATION_ARG_VALUE;
    break;
  default:
    ERROR(USER,"invalid variation occured in thread_chain_pattern");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  if (_threadchain_myid == 0)
  {
    if (CACHE_WARMUP > 0)
    {
      /* cache warmups, not measured */
#ifdef _HAVE_OMP_
      if (ms->pattern_in_omp_parallel)
	{
#pragma omp master
	  {
	    max_iters = 1;
	  }
	}
      else
#endif
	max_iters = 1;

      am_init(CACHE_WARMUP, ms->pattern_in_omp_parallel);

      do
      {
#ifdef _HAVE_OMP_
      if (ms->pattern_in_omp_parallel)
	{
#pragma omp master
	  {
	    iter_count = 0;
	  }
	}
      else
#endif
	iter_count = 0;

	org_time = (start_time = MPI_Wtime()) - end_time;
	/* measure */
	ms->data.simple_data.routine_to_measure();
	end_time = MPI_Wtime();
	tbm_time = end_time - start_time;

	if (ms->iter_cleanup != NULL)
	  ms->iter_cleanup();
      }while (am_control_end(ms, CACHE_WARMUP, tbm_time, org_time, 
			     NO_COMMUNICATION, MPI_COMM_NULL, 0, TRUE));

      am_free(ms->pattern_in_omp_parallel);
    }

    /* restore max_iters... */
#ifdef _HAVE_OMP_
    if (ms->pattern_in_omp_parallel)
      {
#pragma omp master
	{
	  max_iters = get_max_iters_value (ms);
	}
      }
    else
#endif
      max_iters = get_max_iters_value (ms);

    /* and now for real ! */
    am_init(ms->max_rep, ms->pattern_in_omp_parallel);

    do
    {
#ifdef _HAVE_OMP_
      if (ms->pattern_in_omp_parallel)
	{
#pragma omp master
	  {
	    iter_count = 0;
	  }
	}
      else
#endif
	iter_count = 0;

      org_time = (start_time = MPI_Wtime()) - end_time;
      /* measure */
      ms->data.simple_data.routine_to_measure();
      end_time = MPI_Wtime();
      tbm_time = end_time - start_time;

      if (ms->iter_cleanup != NULL)
	ms->iter_cleanup();
    }while (am_control_end(ms, arg, tbm_time, org_time, 
			   NO_COMMUNICATION, MPI_COMM_NULL, 0, FALSE));
    am_fill_data (ms, 0, ms->data.simple_data.result, max_iters);

    am_free(ms->pattern_in_omp_parallel);
  }

  return 0;
}


/*
   @FUN:
   @DOES: the multitiming pattern.
   @PARAMETERS: th actual measurement (which sould be one of the 
   multitiming pattern).
   @RETURNS: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: none.
*/
int
multitiming_pattern (measurement_t *ms, int n)
{
  int
    _multi_myid, arg,
    i, num_times;

  double 
    last_time = 0,
    *start_time,
    *end_time,
    *org_time,
    *tbm_time;

  MPI_Comm_rank(ms->communicator,&_multi_myid);

  switch (ms->dimensions[n].variation) {
  case MASTER_BINDING:
    arg = ms->data.multitiming_data.server_cpu;
    break;
  case SLAVE_BINDING:
    arg = ms->data.multitiming_data.client_cpu;
    break;
  case THREADS:
    arg = ms->omp_data.thread_count;
    break;
  case WORK_AMOUNT:
    arg = ms->omp_data.work_amount;
    break;
  case WORK_FUNCTION:
    arg = ms->omp_data.which_work;
    break;
  case OVERLAP_FUNCTION:
    arg = ms->omp_data.which_overlap;
    break;
  case SCHED_CAP:
    arg = ms->omp_data.cap_for_schedule_loops;
    break;
  case SCHED_CHUNKS:
    arg = ms->omp_data.schedule_chunks;
    break;
  case SCHEDULE:
    arg = ms->omp_data.loop_schedule;
    break;
  case ITERS:
    arg = ms->data.multitiming_data.iters;
    break;
  case NO_VARIATION:
    arg = NO_VARIATION_ARG_VALUE;
    break;
  default:
    ERROR(USER,"invalid variation occured in col_pattern");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  if (_multi_myid == 0)
  {
    /* restore max_iters... */
    max_iters = get_max_iters_value (ms);

    num_times = ms->data.multitiming_data.num_timings;
    
    start_time = (double *) malloc (sizeof(double) * num_times);
    end_time = (double *) malloc (sizeof(double) * num_times);
    org_time = (double *) malloc (sizeof(double) * num_times);
    tbm_time = (double *) malloc (sizeof(double) * num_times);

    if (CACHE_WARMUP > 0)
    {
      /* cache warmups, not measured */
      am_multi_init(CACHE_WARMUP, num_times, ms->pattern_in_omp_parallel);
      do
      {
	for (i = 0; i < num_times; i++) {
	  /* measure */
	  start_time[i] = MPI_Wtime();
	  ms->data.multitiming_data.routines_to_measure[i]();
	  end_time[i] = MPI_Wtime();
	}

	/* use two loops so most overhead is outside of timings... */
	org_time[0] = start_time[0] - last_time;
	tbm_time[0] = end_time[0] - start_time[0];

	for (i = 1; i < num_times; i++) {
	  org_time[i] = start_time[i] - end_time[i - 1];
	  tbm_time[i] = end_time[i] - start_time[i];
	}

	last_time = end_time[num_times - 1];
      }while (am_multi_control_end(ms, CACHE_WARMUP, tbm_time, org_time,
				   NO_COMMUNICATION, MPI_COMM_NULL, TRUE));
      am_multi_free(ms->pattern_in_omp_parallel);
    }
    /* and now for real ! */
    am_multi_init(ms->max_rep, num_times, ms->pattern_in_omp_parallel);
    do
    {
      /* Still need to make take multiple timings; pass into am stuff... */
      for (i = 0; i < num_times; i++) {
	/* measure */
	start_time[i] = MPI_Wtime();
	ms->data.multitiming_data.routines_to_measure[i]();
	end_time[i] = MPI_Wtime();
      }

      /* use two loops so most overhead is outside of timings... */
      org_time[0] = start_time[0] - last_time;
      tbm_time[0] = end_time[0] - start_time[0];

      for (i = 1; i < num_times; i++) {
	org_time[i] = start_time[i] - end_time[i - 1];
	tbm_time[i] = end_time[i] - start_time[i];
      }

      last_time = end_time[num_times - 1];
    }while (am_multi_control_end(ms, 0, tbm_time, org_time, 
				 NO_COMMUNICATION, MPI_COMM_NULL, FALSE));
    am_multi_fill_data (ms, arg, ms->data.multitiming_data.result, max_iters);

    am_multi_free(ms->pattern_in_omp_parallel);

    free (start_time);
    free (end_time);
    free (org_time);
    free (tbm_time);
  }

  return 0;
}


pthread_cond_t      proxy_condition;
pthread_mutex_t     proxy_mutex;
int                 proxy_ready;
int                 proxy_n;
int                 proxy_retval;

void *be_proxy(void *threadarg)
{
  measurement_t *ms = (measurement_t *) threadarg;

  /* just created proxy; don't create another one... */
  ms->need_to_create_proxy = 0; /* FALSE */

  /* get lock so guaranteed initial thread is waiting on condition */
  pthread_mutex_lock( &proxy_mutex );

  /* have proxy do the measurement... */
  proxy_retval = measure (ms, proxy_n);

  pthread_cond_signal( &proxy_condition );
  proxy_ready = 1;

  /* just case ever want to reuse this measurement... */
  ms->need_to_create_proxy = 1; /* TRUE */

  /* give up lock so parent can receive signal... */
  pthread_mutex_unlock( &proxy_mutex );
  
  pthread_exit(NULL);

  /* because SGI's cc complains... */
  return NULL;
}

int
create_and_use_proxy_thread (measurement_t *ms, int n)
{
  pthread_attr_t      attr;
  pthread_t           proxy_thread;
  int                 rc;

  proxy_n = n;

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

  pthread_mutex_init( &proxy_mutex, NULL );
  pthread_cond_init( &proxy_condition, NULL );

  pthread_mutex_lock( &proxy_mutex );

  proxy_ready = 0;

  rc = pthread_create(&proxy_thread, &attr, be_proxy, (void *) ms);
  if (rc) {
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
  }

  /* Wait until proxy finishes the measurement */
  while( !proxy_ready ) {
    pthread_cond_wait( &proxy_condition, &proxy_mutex );
  }

  pthread_mutex_unlock( &proxy_mutex );
    
  pthread_mutex_destroy( &proxy_mutex );
  pthread_cond_destroy( &proxy_condition );

  pthread_attr_destroy(&attr);

  return proxy_retval;
}
