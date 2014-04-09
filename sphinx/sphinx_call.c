/*
$Log: sphinx_call.c,v $
Revision 1.22  2000/09/19 17:34:36  chanbor
Fixed part of ITERS var problem

Revision 1.21  2000/09/15 00:05:00  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.20  2000/08/25 23:17:17  bronis
Added OpenMP tests

Revision 1.19  2000/03/16 15:48:39  bronis
fixed mpguidec warnings

Revision 1.18  2000/02/17 14:18:58  bronis
added first real non-blocking tests

Revision 1.17  2000/01/18 18:42:11  bronis
Added MPI_Comm_free calls

Revision 1.16  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.15  1999/10/18 16:36:36  bronis
fixed multitiming bug

Revision 1.14  1999/10/01 21:36:52  bronis
Added debugged Root variation

Revision 1.13  1999/09/29 16:10:41  bronis
First cut at ROOT variation

Revision 1.12  1999/09/29 00:23:48  bronis
removed most restrictions on ACKER variation

Revision 1.11  1999/09/23 17:08:44  bronis
cleaned up multi dim stuff

Revision 1.10  1999/09/21 15:59:51  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.9  1999/09/20 19:00:39  srtaylor
Merged measure and measure_suite

Revision 1.8  1999/09/17 23:03:00  bronis
Split BINDING variation

Revision 1.7  1999/09/16 23:26:02  bronis
fixed fill_dummy_values calls

Revision 1.6  1999/09/16 21:07:44  srtaylor
Added max_message_len check

Revision 1.5  1999/09/16 16:17:50  bronis
incremental multi dim changes

Revision 1.4  1999/09/15 15:50:57  srtaylor
Structure modifications - Does not currently compile

Revision 1.3  1999/09/14 16:38:51  srtaylor
First cut at multiple dimensions

Revision 1.2  1999/07/30 16:55:13  bronis
Fixed conflict between STOP_SIGNAL and UNBIND

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* The current design is intended to make the prologue functions set */
/* the appropriate members of the measurement structure and to */
/* check that the pattern/variation combination is valid */
/* All have the form "Here are the patterns for which this */
/* variation is valid. If the pattern is not one of these, complain. */

#include "sphinx.h"
#include "sphinx_aux.h"
#include "pattern.h"
#include "sphinx_call.h"
#include "sphinx_error.h"
#include "sphinx_tools.h"
#include "sphinx_params.h"

extern params_t  params;       /* the parameter block */

int	min_node = -1;
int	max_node = -1;


int call_omp_prologue (measurement_t *ms, int n);


#ifdef _HAVE_OMP_
extern int sphinx_omp_max_num_threads;
#endif

int
call_pattern_prologue (measurement_t *ms, int n)
{
  switch (ms->pattern) {
  case P2P:
    return call_p2p_prologue (ms, n);
  case MASTER_WORKER:
    return call_mw_prologue (ms, n);
  case COLLECTIVE:
    return call_col_prologue (ms, n);
  case SIMPLE:
    return call_simple_prologue (ms, n);
  case MULTITIMING:
    return call_multitiming_prologue (ms, n);
  case THREAD_CHAIN:
    return SUCCESS;
  default:
    return SUCCESS;
  }
}


/*
   @FUN:
   @DOES: call the appropriate prologue for the nth variation
   @PARAMETERS: additional: none.
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_variation_prologue (measurement_t *ms, int the_arg, int n, int dp_num)
{
  if (ms->have_omp_params) {
    int retval = call_omp_prologue(ms, n);
    if (retval) return retval;
  }

  switch (ms->dimensions[n].variation)
  {
  case NODES:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over nodes.\n"););
    return call_nodes_prologue (ms, the_arg, n);
  case LENGTH:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over length.\n"););
    return call_length_prologue (ms, the_arg, n);
  case CHUNK:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over chunks.\n"););
    return call_chunks_prologue (ms, the_arg, n);
  case NO_VARIATION:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("no variation.\n"););
    return call_pattern_prologue (ms, n);
  case ITERS:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over iterations.\n"););
    return call_iters_prologue (ms, the_arg, n);
  case MASTER_BINDING:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over master thread CPU binding.\n"););
    return call_master_binding_prologue (ms, the_arg, n);
  case SLAVE_BINDING:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over slave thread CPU binding.\n"););
    return call_slave_binding_prologue (ms, the_arg, n);
  case ACKER:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over ACKer.\n"););
    return call_ACKer_prologue (ms, the_arg, n);
  case ROOT:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over Root.\n"););
    return call_root_prologue (ms, the_arg, n);
  case OVERLAP:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over computation overlap time.\n"););
    return call_overlap_prologue (ms, the_arg, n);
  case SECOND_OVERLAP:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over second computation overlap time.\n"););
    return call_second_overlap_prologue (ms, the_arg, n);
  case THREADS:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over number of threads.\n"););
    return call_threads_prologue (ms, the_arg, n);
  case WORK_AMOUNT:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over work amount parameter.\n"););
    return call_work_amount_prologue (ms, the_arg, n);
  case WORK_FUNCTION:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over work function.\n"););
    return call_work_function_prologue (ms, the_arg, n);
  case OVERLAP_FUNCTION:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over OpenMP overlap function.\n"););
    return call_overlap_function_prologue (ms, the_arg, n);
  case SCHED_CAP:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over omp scheduling cap.\n"););
    return call_sched_cap_prologue (ms, the_arg, n);
  case SCHED_CHUNKS:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over omp scheduling chunks.\n"););
    return call_sched_chunks_prologue (ms, the_arg, n);
  case SCHEDULE:
    O(if ((_sphinx_myid == 0) && (dp_num == 0))
      printf ("varied over omp loop schedule.\n"););
    return call_schedule_prologue (ms, the_arg, n);
  default:
    ERROR(INTERN,"invalid variation occured in call_variation_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }
}  

int
call_p2p_prologue (measurement_t *ms, int n)
{
  if (ms->pattern != P2P) {
    ERROR(INTERN,"invalid pattern occured in call_p2p_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  ms->data.p2p_data.iters = ms->iters_per_time;

  /* set max_node and min_node if known... */
  if ((max_node != -1) && (min_node != -1)) {
    ms->data.p2p_data.max_node = max_node;
    ms->data.p2p_data.min_node = min_node;
  }

  return SUCCESS;
}

int
call_mw_prologue (measurement_t *ms, int n)
{
  if (ms->pattern != MASTER_WORKER) {
    ERROR(INTERN,"invalid pattern occured in call_mw_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  ms->data.mw_data.iters = ms->iters_per_time;

  return SUCCESS;
}

int
call_col_prologue (measurement_t *ms, int n)
{
  if (ms->pattern != COLLECTIVE) {
    ERROR(INTERN,"invalid pattern occured in call_col_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  ms->data.col_data.iters = ms->iters_per_time;

  return SUCCESS;
}

int
call_omp_prologue (measurement_t *ms, int n)
{
#ifdef _HAVE_OMP_
  if (ms->omp_data.thread_count == MAX_ARGUMENT)
    ms->omp_data.thread_count = sphinx_omp_max_num_threads;
#endif

  return SUCCESS;
}

int
call_simple_prologue (measurement_t *ms, int n)
{
  if (ms->pattern != SIMPLE) {
    ERROR(INTERN,"invalid pattern occured in call_simple_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  ms->data.simple_data.iters = ms->iters_per_time;

  return SUCCESS;
}

int
call_multitiming_prologue (measurement_t *ms, int n)
{
  if (ms->pattern != MULTITIMING) {
    ERROR(INTERN,"invalid pattern occured in call_multitiming_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  ms->data.multitiming_data.iters = ms->iters_per_time;

  return SUCCESS;
}

/*
   @FUN:
   @DOES: set the message length variables
   @PARAMETERS: additional: none.
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_length_prologue (measurement_t *ms, int length, int n)
{
  int retval;

  switch (ms->pattern)
  {
  case P2P:   
    retval = call_p2p_prologue (ms, n);

    if (retval) return retval;

    ms->data.p2p_data.len = length;

    D2(fprintf (stderr,"proc %d: in call_length_prologue with arg %d\n",
		_sphinx_myid, length);)

    break;

  case MASTER_WORKER:
    retval = call_mw_prologue (ms, n);

    if (retval) return retval;

    ms->data.mw_data.len = length;
    break;
  case COLLECTIVE:
    retval = call_col_prologue (ms, n);

    if (retval) return retval;

    ms->data.col_data.len = length;
    break;
  default:
    ERROR(INTERN,"invalid pattern in call_length_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  return SUCCESS;
}

/*
   @FUN:
   @DOES: create the actual communicator used in tests w/nodes variation
   @PARAMETERS: additional: none.
   @RETURNS: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_create_communicator (measurement_t *ms, int nodes, int n)
{
  MPI_Comm local_communicator;
  int      retval;

  /* Don't ask me why this is necessary; it's how it was... */
  local_communicator = ms->communicator;

  retval = MPI_Comm_split (ms->communicator, _sphinx_myid < nodes, 
			   _sphinx_myid, &local_communicator);

  if (retval) return retval;

  if (_sphinx_myid < nodes) {
    ms->should_call_pattern = TRUE;

    switch(ms->pattern)
    {
    case MASTER_WORKER:
      ms->data.mw_data.communicator = local_communicator;
      break;
    case COLLECTIVE:
      ms->data.col_data.communicator = local_communicator;
      break;
    default:
      ERROR(INTERN,"invalid pattern in call_create_communicator");
      output_error(FALSE);
      return GENERIC_ERROR;
    }
  }
  else {
    ms->should_call_pattern = FALSE;

    retval = MPI_Comm_free (&local_communicator);

    if (retval) return retval;
  }

  return SUCCESS;
}


/*
   @FUN:
   @DOES: destroy the actual communicator used in tests w/nodes variation
   @PARAMETERS: additional: none.
   @RETURNS: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_destroy_communicator (measurement_t *ms, int nodes, int n)
{
  int      retval;

  if (_sphinx_myid < nodes) {
    switch(ms->pattern)
    {
    case MASTER_WORKER:
      retval = MPI_Comm_free (&(ms->data.mw_data.communicator));
      break;
    case COLLECTIVE:
      retval = MPI_Comm_free (&(ms->data.col_data.communicator));
      break;
    default:
      ERROR(USER,"invalid pattern in call_create_communicator");
      output_error(FALSE);
      return GENERIC_ERROR;
    }

    if (retval) return retval;
  }

  return SUCCESS;
}

/*
   @FUN:
   @DOES: set the nodes variables
   @PARAMETERS: additional: none.
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_nodes_prologue (measurement_t *ms, int nodes, int n)
{
  int retval;

  switch(ms->pattern)
  {
  case MASTER_WORKER:
    retval = call_mw_prologue (ms, n);

    if (retval) return retval;

    ms->data.mw_data.len = SPHINX_MIN(ms->max_allowed_len,
				      ms->data.mw_data.len);
    break;
  case COLLECTIVE:
    retval = call_col_prologue (ms, n);

    if (retval) return retval;

    ms->data.col_data.len = SPHINX_MIN(ms->max_allowed_len,
				       ms->data.col_data.len);
    break;
  default:
    ERROR(INTERN,"invalid pattern in call_nodes_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  return SUCCESS;
}

/*
   @FUN:
   @DOES: set the chunk variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: _sphinx_myid set.
*/
int
call_chunks_prologue (measurement_t *ms, int chunks, int n)
{
  int retval;

  if (ms->pattern == MASTER_WORKER)
  {
    retval = call_mw_prologue (ms, n);

    if (retval) return retval;

    ms->data.mw_data.chunks = chunks;
    return SUCCESS;
  }

  ERROR(USER,"invalid pattern in call_chunks_prologue");
  output_error(FALSE);
  return GENERIC_ERROR;
}

/*
   @FUN:
   @DOES: set the ACKer variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: _sphinx_myid set.
*/
int
call_ACKer_prologue (measurement_t *ms, int ACKer, int n)
{
  if (ms->pattern != COLLECTIVE) {
    ERROR(INTERN,"invalid pattern in call_ACKer_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }
  
  if (_sphinx_myid == ACKer) {
    /* I'm the ACKer; use special client_routine */
    ms->data.col_data.client_routine = ms->data.col_data.ACKer_routine;
  }
  else {
    /* I'm not the ACKer; use "real" client_routine */
    ms->data.col_data.client_routine = ms->data.col_data.notACKer_routine;
  }

  ms->data.col_data.ACKer = ACKer;

  return call_col_prologue (ms, n);
}

/*
   @FUN:
   @DOES: set the root variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: _sphinx_myid set.
*/
int
call_root_prologue (measurement_t *ms, int root, int n)
{
  if (ms->pattern != COLLECTIVE) {
    ERROR(INTERN,"invalid pattern in call_root_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }
  
  ms->root = root;

  return call_col_prologue (ms, n);
}

/*
   @FUN:
   @DOES: set the server cpu variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: _sphinx_myid set.
*/
int
call_master_binding_prologue (measurement_t *ms, int master_cpu, int n)
{
  if (ms->pattern == SIMPLE) {
    if (_sphinx_myid == 0) 
      ms->data.simple_data.server_cpu = master_cpu;

    return call_simple_prologue (ms, n);
  }

  if (ms->pattern != MULTITIMING) {
    ERROR(INTERN,"invalid pattern in call_master_binding_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }
  
  if (_sphinx_myid == 0) 
    ms->data.multitiming_data.server_cpu = master_cpu;

  return call_multitiming_prologue (ms, n);
}

/*
   @FUN:
   @DOES: set the client cpu variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: _sphinx_myid set.
*/
int
call_slave_binding_prologue (measurement_t *ms, int slave_cpu, int n)
{
  if (ms->pattern == SIMPLE) {
    if (_sphinx_myid == 0) 
      ms->data.simple_data.client_cpu = slave_cpu;

    return call_simple_prologue (ms, n);
  }

  if (ms->pattern != MULTITIMING) {
    ERROR(INTERN,"invalid pattern in call_master_binding_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }
  
  if (_sphinx_myid == 0) 
    ms->data.multitiming_data.client_cpu = slave_cpu;

  return call_multitiming_prologue (ms, n);
}

/*
   @FUN:
   @DOES: set the iters variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_iters_prologue (measurement_t *ms, int iters, int n)
{
  int retval;

  switch (ms->pattern) {
  case P2P:   
    retval = call_p2p_prologue (ms, n);

    if (retval) return retval;

    ms->data.p2p_data.iters = iters;
    ms->iters_per_time = iters;

    D2(fprintf (stderr,"proc %d: in call_iters_prologue with arg %d\n",
		_sphinx_myid, iters);)

    break;

  case MASTER_WORKER:
    ms->data.mw_data.iters = iters;
    ms->iters_per_time = iters;
    break;
  case COLLECTIVE:
    ms->data.col_data.iters = iters;
    /* ms->iters_per_time is MPI_Comm_size for collective ops... */
    break;
  case SIMPLE:
    ms->data.simple_data.iters = iters;
    ms->iters_per_time = iters;
    break;
  default:
    ERROR(USER,"invalid pattern in call_iters_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  return SUCCESS;
}

int
call_overlap_prologue (measurement_t *ms, int cap, int n)
{

  if (ms->pattern != P2P) {
    ERROR(INTERN,"invalid pattern in call_overlap_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  ms->overlap_iters = cap;

  return call_p2p_prologue (ms, n);
}

int
call_second_overlap_prologue (measurement_t *ms, int cap, int n)
{
  if (ms->pattern != P2P) {
    ERROR(INTERN,"invalid pattern in call_overlap_prologue");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  ms->second_overlap_iters = cap;

  return call_p2p_prologue (ms, n);
}


/*
   @FUN:
   @DOES: set the number of threads variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_threads_prologue (measurement_t *ms, int num_threads, int n)
{
  ms->omp_data.thread_count = num_threads;

  return call_pattern_prologue (ms, n);
}


/*
   @FUN:
   @DOES: set the work function parameter variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_work_function_prologue (measurement_t *ms, int work_f, int n)
{
  ms->omp_data.which_work = (omp_work_name_t) work_f;

  return call_pattern_prologue (ms, n);
}


/*
   @FUN:
   @DOES: set the overlap fucntion parameter variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_overlap_function_prologue (measurement_t *ms, int overlap_f, int n)
{
  ms->omp_data.which_overlap = (omp_overlap_name_t) overlap_f;

  return call_pattern_prologue (ms, n);
}


/*
   @FUN:
   @DOES: set the work amount parameter variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_work_amount_prologue (measurement_t *ms, int work_amt, int n)
{
  ms->omp_data.work_amount = work_amt;

  return call_pattern_prologue (ms, n);
}


/*
   @FUN:
   @DOES: set the OMP loop schedule cap parameter variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_sched_cap_prologue (measurement_t *ms, int cap, int n)
{
  ms->omp_data.cap_for_schedule_loops = cap;

  return call_pattern_prologue (ms, n);
}


/*
   @FUN:
   @DOES: set the OMP loop schedule chunks parameter variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_sched_chunks_prologue (measurement_t *ms, int chunks, int n)
{
  ms->omp_data.schedule_chunks = chunks;

  return call_pattern_prologue (ms, n);
}


/*
   @FUN:
   @DOES: set the OMP loop schedule variables
   @PARAMETERS: additional: none
   @RETURNES: 0 in case of success, GENERIC_ERROR otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
call_schedule_prologue (measurement_t *ms, int sched, int n)
{
  ms->omp_data.loop_schedule = (omp_schedule_t) sched;

  return call_pattern_prologue (ms, n);
}
