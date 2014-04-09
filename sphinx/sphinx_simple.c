/*
$Log: sphinx_simple.c,v $
Revision 1.11  2000/09/15 00:05:00  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.10  2000/08/25 23:17:18  bronis
Added OpenMP tests

Revision 1.9  2000/03/16 15:48:40  bronis
fixed mpguidec warnings

Revision 1.8  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.7  1999/10/01 21:36:53  bronis
Added debugged Root variation

Revision 1.6  1999/09/29 00:23:49  bronis
removed most restrictions on ACKER variation

Revision 1.5  1999/09/21 15:59:51  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.4  1999/09/16 23:26:02  bronis
fixed fill_dummy_values calls

Revision 1.3  1999/09/16 21:07:44  srtaylor
Added max_message_len check

Revision 1.2  1999/09/14 16:38:52  srtaylor
First cut at multiple dimensions

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_aux.h"
#include "simple_test1.h"
#include "pattern.h"
#include "sphinx_error.h"
#include "sphinx_mem.h"
#include "automeasure.h"
#include "sphinx_aux_test.h"

int measure_dummy ();
int measure_Wtime ();
int measure_2Wtime ();
int measure_Comm_size ();
int measure_Comm_rank ();
int measure_Iprobe ();
int measure_attach ();
int measure_simple_test (void);





/*
   @FUNS:
   @NAME: simple_init_...
   @DOES: the following simple_init_... functions initialize the ms with
   the correct data, to measure the specific simple MPI function.
   @PARAMETERS: measurement ms and the place to hold the measured 
   results (data).
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/

void 
simple_init_dummy (measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;
 
  ms->data.simple_data.routine_to_measure = measure_dummy;
  ms->data.simple_data.result = NULL;

  /* NOTE DO NOT USE CORRECTION ON THIS SINCE IT IS THE OVERHEAD... */

  return;
}

void 
simple_init_Wtime (measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;
  
  ms->data.simple_data.routine_to_measure = measure_Wtime;
  ms->data.simple_data.result = NULL;

  initialize_simple_aux (ms);

  return;
}
void 
simple_init_2Wtime (measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;
  
  ms->data.simple_data.routine_to_measure = measure_2Wtime;
  ms->data.simple_data.result = NULL;

  initialize_simple_aux (ms);

  return;
}

void 
simple_init_Comm_size (measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;
 
  ms->data.simple_data.routine_to_measure = measure_Comm_size;
  ms->data.simple_data.result = NULL;

  initialize_simple_aux (ms);

  return;
}

void 
simple_init_Comm_rank (measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;
 
  ms->data.simple_data.routine_to_measure = measure_Comm_rank;
  ms->data.simple_data.result = NULL;

  initialize_simple_aux (ms);

  return;
}

void 
simple_init_Iprobe (measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;
 
  ms->data.simple_data.routine_to_measure = measure_Iprobe;
  ms->data.simple_data.result = NULL;
}

void 
simple_init_attach (measurement_t *ms)
{
  ms->pattern = SIMPLE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;
 
  ms->data.simple_data.routine_to_measure = measure_attach;
  ms->data.simple_data.result = NULL;

  initialize_simple_aux (ms);

  return;
}

/*
   @FUNS:
   @NAME: measure_...
   @DOES: call the MPI-Function to be measured. The reason not to call this
   MPI-Function directly is to achieve a function-header comman to all
   measured functions.
   @PARAMETERS: message length len, Communicator comminicator.
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: the routines pointed by ms->server_init ms->client_init
   are called.
*/
int
measure_dummy ()
{
  return 0;
}

int
measure_Wtime ()
{
  double _dummy;

  /* this can lead to compiler warnings... */
  _dummy = MPI_Wtime();

  return 0;
}

int
measure_2Wtime ()
{
  double _dummy;

  /* this can lead to compiler warnings... */
  _dummy = MPI_Wtime();
  _dummy = MPI_Wtime();

  return 0;
}

int
measure_Comm_size ()
{
  int _dummy;
  MPI_Comm_size (MPI_COMM_WORLD, &_dummy);
  return 0;
}

int
measure_Comm_rank ()
{
  int _dummy;
  MPI_Comm_rank (MPI_COMM_WORLD, &_dummy);
  return 0;
}

int
measure_Iprobe ()
{
  MPI_Status
    status;
  int 
    _dummy;

  MPI_Iprobe (1, 0, MPI_COMM_WORLD, &_dummy, &status);
  return 0;
}

int
measure_attach ()
{
  int buflen = MPI_BSEND_OVERHEAD + MY_OVERHEAD;

  MPI_Buffer_attach (_sphinx_buffer, buflen);
  MPI_Buffer_detach (&_sphinx_buffer, &buflen);
  return 0;
}


/*
   @FUN:
   @DOES: the simple pattern.
   @PARAMETERS: th actual measurement (which sould be one of the 
   simple pattern).
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: none.
*/
int
simple_pattern (measurement_t *ms, int n)
{
  int
    _simple_myid,
    i,
    arg;

  double 
    start_time,
    end_time = 0,
    org_time,
    tbm_time;

  MPI_Comm_rank(ms->communicator,&_simple_myid);

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
    ERROR(USER,"invalid variation occured in simple_pattern");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  if (_simple_myid == 0)
  {
    if (CACHE_WARMUP > 0)
    {
      /* cache warmups, not measured */
      am_init(CACHE_WARMUP, ms->pattern_in_omp_parallel);
      do
      {
	org_time = (start_time = MPI_Wtime()) - end_time;
	/* measure */
	ms->data.simple_data.routine_to_measure();
	end_time = MPI_Wtime();
	tbm_time = end_time - start_time;
      }while (am_control_end(ms, CACHE_WARMUP, tbm_time, org_time, 
			     NO_COMMUNICATION, MPI_COMM_NULL, 0, TRUE));
      am_free(ms->pattern_in_omp_parallel);
    }
    /* and now for real ! */
    am_init(ms->max_rep, ms->pattern_in_omp_parallel);

    do
    {
      org_time = (start_time = MPI_Wtime()) - end_time;
      /* measure */

      /* Quick and dirty change; really should do loop in routine_to_measure */
      for (i = 0; i < ms->data.simple_data.iters; i++)
        ms->data.simple_data.routine_to_measure();

      end_time = MPI_Wtime();
      tbm_time = end_time - start_time;
    }while (am_control_end(ms, arg, tbm_time, org_time, 
			   NO_COMMUNICATION, MPI_COMM_NULL, 0, FALSE));
    am_fill_data (ms, 0, ms->data.simple_data.result, 
		  (ms->iters_over_nodes ? ms->data.simple_data.iter_factor : 1)
		  * ms->data.simple_data.iters);
    am_free(ms->pattern_in_omp_parallel);
  }

  return 0;
}
