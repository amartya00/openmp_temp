/*
$Log: automeasure.c,v $
Revision 1.11  2000/09/06 21:09:13  bronis
Added several OpenMP versions for Alpha clusters in various states of correctness

Revision 1.10  2000/08/25 23:17:16  bronis
Added OpenMP tests

Revision 1.9  2000/03/16 15:48:39  bronis
fixed mpguidec warnings

Revision 1.8  2000/01/10 21:50:23  bronis
Added full blown aux tests implementation

Revision 1.7  1999/10/29 00:11:10  bronis
Fixed bugs, made input case insensitive

Revision 1.6  1999/10/18 16:36:36  bronis
fixed multitiming bug

Revision 1.5  1999/10/01 21:36:52  bronis
Added debugged Root variation

Revision 1.4  1999/09/29 00:23:47  bronis
removed most restrictions on ACKER variation

Revision 1.3  1999/09/23 17:08:44  bronis
cleaned up multi dim stuff

Revision 1.2  1999/09/16 00:15:45  srtaylor
Outputs correct results for multiple dimensions

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_aux.h"
#include "automeasure.h"
#include "sphinx_error.h"
#include "sphinx_tools.h"

int double_cmp (const void *d1,const void *d2);

static double 
  *tbm_buffer,
  org_time_sum,
  org_square_time_sum,
  /* the following values concern the tbm times */
  square_result_sum,
  result_sum,
  mean_value,
  standard_deviation;

static int
  buffer_size,
  counter; /* number of measurements */

/* kind of hideous but very useful... */
extern double last_measured_time;

static int retval;

/*
   @FUN:
   @DOES: initializes all private (static) variables
   allocates memory.
   @PARAMETERS: the size (in bytes) of memeory to bel allocated.
   @RETURNES: TRUE iff allocation ok, FALSE otherwise.
   @SIDEEFFECTS: changing the mentioned variables.
   @ASSUMES: nothing.
*/
void
real_am_init (size)
{
  counter = 0;
  org_square_time_sum = org_time_sum = 0.0;
  square_result_sum = result_sum = mean_value = standard_deviation = 0.0;
  buffer_size = size;
  
  tbm_buffer = (double *) malloc (sizeof (double) * size);
}

int 
am_init (int size, int in_omp_parallel)
{
#ifdef _HAVE_OMP_
  if (in_omp_parallel)
  {
    {
#pragma omp master
      {
	real_am_init(size);
      }
    }

    {
#pragma omp barrier
    }
  } 
  else
#endif
    real_am_init(size);

  return (tbm_buffer != NULL);
}

/*
   @FUN:
   @DOES: free-es the allocated buffers
   @PARAMETERS: none.
   @RETURNES: nothing.
   @SIDEEFFECTS: memory free-ed, variables set back to zero.
   @ASSUMES: tbm_buffer has been allocated before.
*/
void 
real_am_free (void)
{
  counter = 0;
  buffer_size = 0;

  free (tbm_buffer);

  return;
}

void 
am_free (int in_omp_parallel)
{
#ifdef _HAVE_OMP_
  if (in_omp_parallel)
  {
#pragma omp master
    {
      real_am_free();
    }
  }
  else
#endif
    real_am_free();

  return;
}

/*
   @FUN:
   @DOES: controles whether the ms at arg arg should be repeated 
   (returnes TRUE) or not (returnes FALSE).
   @PARAMETERS: the actual measurement ms, the actual argument arg,
   the measured time (tbm_time), the time measured with the dummy routine
   (organizational time, org_time), the partner (-prozess) also involved into
   this measurement. If there is no other process involved, partner is
   set to NO_COMMUNICATION.  If it is set to USE_COMMUNICATOR, the the argument
   local_communicator will be used. (for communication to more than one 
   other processes. The root is process 0).
   @RETURNES: see above.
   @SIDEEFFECTS: on the static variables.
   @ASSUMES: _sphinx_myid set.
   am_init has been called before.
*/
#define SQUARE(a) ((a)*(a))
/* returnes true iff measurement has to be repeated */
int 
real_am_control_end (measurement_t *ms, int arg, double tbm_time, 
		     double org_time, 
		int partner, MPI_Comm local_communicator, int server_id,
		int cold_cache)
{
  int loc_retval;

  if (_sphinx_myid == server_id) {
    int		i;
    double	diff;
    double	roundoff_correction = 0.0;
    double	sigma_squared = 0.0;
    
    /* store the result time */
    tbm_buffer[counter] = tbm_time;

    /* update variables */
    
    result_sum += tbm_time;
    square_result_sum += SQUARE(tbm_time);
    
    if (counter++ > 0) { /* the first org_time is invalid */
      org_time_sum += org_time;
      org_square_time_sum += SQUARE(org_time);
    }
    
    mean_value = result_sum / counter;

    if (counter == 1) { /* cannot do calculation of standard_deviation 
			   (division by zero) */
      loc_retval = TRUE; /* do not stop */
    } else {
      /* use "corrected" formula from Num. Recipes in C 2nd edition p. 613 */
      for (i = 0; i < counter; i++) {
	roundoff_correction += (diff = tbm_buffer[i] - mean_value);
	sigma_squared += SQUARE(diff);
      }
    
      sigma_squared = 
	(sigma_squared-(SQUARE(roundoff_correction)/counter))/(counter-1);
      
      standard_deviation = sqrt (sigma_squared);    

      if (cold_cache) { /* only dummy measurement */
	/* here arg is used to determine the number of dummy-measurements */
	/* Continue CACHE_WARMUP until complete arg iters */
	/* or out of space */
	if ((counter <= arg) && (counter < buffer_size))
	  loc_retval = TRUE; /* repeat meas. */
	else
	  loc_retval = FALSE; /* stop meas. */
      } else
	/* Instead, test for last measurement after test for threshhold */
	/* However, must test still have space if haven't done min_rep... */
	if (counter < ms->min_rep) {
	  if (counter == buffer_size) {
	    sprintf (_sphinx_msg,
		     "Cannot do %d reps for %s w/arg %d; buffer limit: %d\n",
		     ms->min_rep, ms->name, arg, buffer_size);
	    ERROR (INTERN,_sphinx_msg);
	    output_error (TRUE);
	  }
	  loc_retval = TRUE; /* repeat */
	} else
	  if (standard_deviation < ms->standard_deviation * mean_value) {
	    loc_retval = FALSE;  /* then stop measurements */
	  } else
	    if (counter == buffer_size) {
	      data_t *data;
	      sprintf (_sphinx_msg,
		       "The measurement %s with arg %d did not achieve \n"\
		       "cut off of the std. dev. < %f%% of mean.\n"\
		       "std. dev. is %f; mean is %f\n"\
		       "(i.e. std. dev. is %f%% of mean)\n"\
		       "The measurement has been repeated %d times.\n" ,
		       ms->name, arg, 100 * ms->standard_deviation, 
		       standard_deviation, mean_value, 
		       (standard_deviation * 100) / 
		       (mean_value == 0 ? 1 : mean_value), counter);
	      
	      write_to_log_file (_sphinx_msg);

	      /* mark status as "UNSETTLED" */
	      /* assume this is "first" marking - which */
	      /* simplifies code in am_multi_control_end... */
	      switch (ms->pattern) {
	      case COLLECTIVE:
		data = ms->data.col_data.result;
		break;
	      case P2P:
		data = ms->data.p2p_data.result;
		break;
	      case MASTER_WORKER:
		data = ms->data.mw_data.result;
		break;
	      case SIMPLE:
	      case THREAD_CHAIN:
		data = ms->data.simple_data.result;
		break;
	      case MULTITIMING:
		for (i = 0; i < ms->data.multitiming_data.num_timings; i++) {
		  data = &(ms->data.multitiming_data.result[i]);
		    
		  /* if already marked, did so in loop for this time... */
		  if (data->status == NULL) 
		    mark_status (data, "UNSETTLED");
		}
		break;
	      default:
		ERROR(INTERN,"invalid pattern occurred in am_control_end");
		output_error (TRUE);
	      }

	      /* if already marked, did so in loop for this time... */
	      if (data->status == NULL)
		mark_status (data, "UNSETTLED");
	      
	      loc_retval = FALSE; /* stop */
	    } else
	      /* repeat the measurement */
	      loc_retval = TRUE;
    } /* Close else preceding assignment to standard_deviation... */
  
    if (partner != NO_COMMUNICATION) {
      if (partner == USE_COMMUNICATOR) {
	MPI_Bcast (&loc_retval, 1, MPI_INT, server_id, local_communicator);
	MPI_Barrier (local_communicator);
      }
      else /* then you are the sender (because you are server_id) 
	      and you have to send to partner */
	MPI_Ssend (&loc_retval, 1, MPI_INT, partner, 0, ms->communicator);
    }
  }
  else { /* so not process server_id */
    if (partner != NO_COMMUNICATION) {
      if (partner == USE_COMMUNICATOR) {
	MPI_Bcast (&loc_retval, 1, MPI_INT, server_id, local_communicator);
	MPI_Barrier (local_communicator);
      }
      else { /* you are the client and have to receive from proc 0 */
	MPI_Status status;

	MPI_Recv (&loc_retval, 1, MPI_INT, server_id, 0, 
		  ms->communicator, &status);
      }
    }
  }

  return (loc_retval);
}

int 
am_control_end (measurement_t *ms, int arg, double tbm_time, double org_time, 
		int partner, MPI_Comm local_communicator, int server_id,
		int cold_cache)
{
#ifdef _HAVE_OMP_
  if (ms->pattern_in_omp_parallel)
  {
    {
#pragma omp master
      {
	retval = real_am_control_end (ms, arg, tbm_time, org_time, 
				      partner, local_communicator, 
				      server_id, cold_cache);
      }
    }

    {
#pragma omp barrier
    }
  }
  else
#endif
    retval = real_am_control_end (ms, arg, tbm_time, org_time, partner,
				  local_communicator, server_id, cold_cache);

  return (retval);
}

/*
   @FUN:
   @DOES: fills the data (the actual measured data) into the local tbm_buffer.
   @PARAMETERS: (additional to above)
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: am_init has been called before.
*/
void 
real_am_fill_data (measurement_t *ms, int arg, 
	      data_t *data, int num_iters_per_time)
{
  double   *tbm_buffer_ptr = tbm_buffer;

  qsort (tbm_buffer_ptr, counter, sizeof(double), double_cmp);

  /* Need to correct mean for the multiple calls per iteration: */
  mean_value /= num_iters_per_time;
    
  /* fill the data struct: note times in micro sec. now */
  last_measured_time = data->result = mean_value * 1000000;

  /* Should correct standard_deviation for mult. calls per iteration... */
  /* But what is the right correction??? */
  data->standard_deviation = standard_deviation * 1000000;

  data->count = counter;

  return;
}

void 
am_fill_data (measurement_t *ms, int arg, 
	      data_t *data, int num_iters_per_time)
{
#ifdef _HAVE_OMP_
  if (ms->pattern_in_omp_parallel)
  {
#pragma omp master
    {
      real_am_fill_data (ms, arg, data, num_iters_per_time);
    }
  }
  else
#endif
    real_am_fill_data (ms, arg, data, num_iters_per_time);

  return;
}

/*
   @FUN:
   @DOES: compares to doubles, used for qsort-calls
   @PARAMETERS: two pointers to doubles d1, d2
   @RETURNES: 0 iff equal, -1 iff d1 < d2, 1 else
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int 
double_cmp (const void *d1,const void *d2)
{
  if (*(double *)d1 < *(double *)d2)
    return (-1);
  else
    return (*(double *)d1 > *(double *)d2);
}


static double 
  **tbm_buffer_array,
  *cur_times_array,
  *cur_org_array,
  *org_time_sum_array,
  *org_square_time_sum_array,
  /* the following values concern the tbm times */
  *square_result_sum_array,
  *result_sum_array,
  *mean_value_array,
  *standard_deviation_array;

static int
  array_size;

int 
real_am_gap_init (int size, int comm_size)
{
  int i, loc_retval;

  /* in_omp_parallel here is FALSE since already in omp master if TRUE */
  /* for the actual measurement; thus the overheads unnecessary... */
  loc_retval = am_multi_init (size, comm_size, FALSE);

  if (loc_retval) {
    if ((cur_times_array=(double*)malloc(sizeof(double)*comm_size))
	== NULL) {
      free (org_square_time_sum_array);
      free (org_time_sum_array);
      free (square_result_sum_array);
      free (result_sum_array);
      free (mean_value_array);
      free (standard_deviation_array);
 
      for (i = 0; i < comm_size; i++) {
	free (tbm_buffer_array[i]);
      }

      free (tbm_buffer_array);
      loc_retval = 0;
    }
  }

  if (loc_retval) {
    if ((cur_org_array=(double*)malloc(sizeof(double)*comm_size))
	== NULL) {
      free (org_square_time_sum_array);
      free (org_time_sum_array);
      free (square_result_sum_array);
      free (result_sum_array);
      free (mean_value_array);
      free (standard_deviation_array);
 
      for (i = 0; i < comm_size; i++) {
	free (tbm_buffer_array[i]);
      }

      free (tbm_buffer_array);
      free (cur_times_array);
      loc_retval = 0;
    }
  }

  return loc_retval;
}

int 
am_gap_init (int size, int comm_size, int in_omp_parallel)
{
#ifdef _HAVE_OMP_
  if (in_omp_parallel)
  {
    {
#pragma omp master
      {
	retval = real_am_gap_init (size, comm_size);
      }
    }

    {
#pragma omp barrier
    }
  }
  else
#endif 
    retval = real_am_gap_init (size, comm_size);

  return retval;
}

int 
real_am_multi_init (int size, int timing_count)
{
  int i, j, loc_retval = 1;

  array_size = timing_count;

  if ((org_square_time_sum_array = 
       (double*)malloc(sizeof(double)*timing_count))
      == NULL) {
    loc_retval = 0;
  }

  if ((loc_retval) &&
      ((org_time_sum_array=(double*)malloc(sizeof(double)*timing_count))
       == NULL)) {
    free (org_square_time_sum_array);
    loc_retval = 0;
  }

  if ((loc_retval) &&
      ((square_result_sum_array=(double*)malloc(sizeof(double)*timing_count))
       == NULL)) {
    free (org_square_time_sum_array);
    free (org_time_sum_array);
    loc_retval = 0;
  }

  if ((loc_retval) &&
      ((result_sum_array=(double*)malloc(sizeof(double)*timing_count))
       == NULL)) {
    free (org_square_time_sum_array);
    free (org_time_sum_array);
    free (square_result_sum_array);
    loc_retval = 0;
  }

  if ((loc_retval) &&
      ((mean_value_array=(double*)malloc(sizeof(double)*timing_count))
       == NULL)) {
    free (org_square_time_sum_array);
    free (org_time_sum_array);
    free (square_result_sum_array);
    free (result_sum_array);
    loc_retval = 0;
  }

  if ((loc_retval) &&
      ((standard_deviation_array = 
	(double*)malloc(sizeof(double)*timing_count))
       == NULL)) {
    free (org_square_time_sum_array);
    free (org_time_sum_array);
    free (square_result_sum_array);
    free (result_sum_array);
    free (mean_value_array);
    loc_retval = 0;
  }

  if ((loc_retval) &&
      ((tbm_buffer_array=(double **)malloc(sizeof(double *)*timing_count))
       == NULL)) {
    free (org_square_time_sum_array);
    free (org_time_sum_array);
    free (square_result_sum_array);
    free (result_sum_array);
    free (mean_value_array);
    free (standard_deviation_array);
    loc_retval = 0;
  }

  for (i = 0; ((loc_retval) && (i < timing_count)); i++) {
    if ((tbm_buffer_array[i] = (double *) malloc (sizeof (double) * size))
	== NULL) {
      free (org_square_time_sum_array);
      free (org_time_sum_array);
      free (square_result_sum_array);
      free (result_sum_array);
      free (mean_value_array);
      free (standard_deviation_array);

      for (j = 0; j < i; j++) {
	free (tbm_buffer_array[j]);
      }

      free (tbm_buffer_array);

      loc_retval = 0;
    }

    org_square_time_sum_array[i] = org_time_sum_array[i] = 0.0;
    square_result_sum_array[i] = result_sum_array[i] = 0.0;
    mean_value_array[i] = standard_deviation_array[i] = 0.0;
  }

  /* as before, already in omp master if in_omp_parallel is TRUE */
  /* for actual measurement, so overhead is unnecessary... */
  if (loc_retval = am_init(size, FALSE)) {
    free (tbm_buffer);
  }

  return loc_retval;
}

int 
am_multi_init (int size, int timing_count, int in_omp_parallel)
{
#ifdef _HAVE_OMP_
  if (in_omp_parallel)
  {
    {
#pragma omp master
      {
	retval = real_am_multi_init (size, timing_count);
      }
    }

    {
#pragma omp barrier
    }
  }
  else 
#endif
    retval = real_am_multi_init (size, timing_count);

  return retval;
}

void 
real_am_gap_free (void)
{
  /* as before, already in omp master if in_omp_parallel is TRUE */
  /* for actual measurement, so overhead is unnecessary... */
  am_multi_free(FALSE);

  free (cur_times_array);
  free (cur_org_array);

  return;
}

void 
am_gap_free (int in_omp_parallel)
{
#ifdef _HAVE_OMP_
  if (in_omp_parallel)
  {
#pragma omp master
    {
      real_am_gap_free();
    }
  }
  else
#endif
    real_am_gap_free();

  return;
}

void 
real_am_multi_free (void)
{
  int j;

  free (org_square_time_sum_array);
  free (org_time_sum_array);
  free (square_result_sum_array);
  free (result_sum_array);
  free (mean_value_array);
  free (standard_deviation_array);
    
  for (j = 0; j < array_size; j++) {
    free (tbm_buffer_array[j]);
  }

  free (tbm_buffer_array);

  array_size = 0;

  counter = 0;
  buffer_size = 0;

  return;
}

void 
am_multi_free (int in_omp_parallel)
{
#ifdef _HAVE_OMP_
  if (in_omp_parallel)
  {
#pragma omp master
    {
      real_am_multi_free();
    }
  }
  else
#endif 
    real_am_multi_free();

  return;
}

/* this function collects up a set of (gap) measurements and */
/* decides if all are done; if not it returns false... */
/* it does some kludgy things so it can use am_control_end... */
int real_am_gap_control_end (measurement_t *ms, int arg, double time, 
			double org_time, MPI_Comm communicator,
			int cold_cache)
{
  int comm_size;

  if (_sphinx_myid == 0) {
    MPI_Comm_size (communicator, &comm_size);
    
    if (comm_size != array_size) {
      ERROR (INTERN,"Mismatched comm_size in am_gap_control_end");
      output_error (TRUE);
    }
  }

  MPI_Gather (&time, 1, MPI_DOUBLE, cur_times_array, 1, MPI_DOUBLE, 0, 
	      communicator);
      					   
  MPI_Gather (&org_time, 1, MPI_DOUBLE, cur_org_array, 1, MPI_DOUBLE, 0, 
	      communicator);

  return am_multi_control_end (ms, arg, cur_times_array, cur_org_array, 
			       USE_COMMUNICATOR, communicator, cold_cache);
}

int am_gap_control_end (measurement_t *ms, int arg, double time, 
			double org_time, MPI_Comm communicator,
			int cold_cache)
{
#ifdef _HAVE_OMP_
  if (ms->pattern_in_omp_parallel)
  {
    {
#pragma omp master
      {
	retval = real_am_gap_control_end (ms, arg, time, org_time, 
					  communicator, cold_cache);
      }
    }

    {
#pragma omp barrier
    }

    return retval;
  }
#endif

  return real_am_gap_control_end (ms, arg, time, org_time, 
				  communicator, cold_cache);
}


/* this function decides if a set of measurements are all done; */
/* if not it returns false; it assumes that am_gap_init has been called */
/* so that array_size equals the number of measurements being tested... */
/* it does some kludgy things so it can use am_control_end... */
int real_am_multi_control_end (measurement_t *ms, int arg, double *time, 
			       double *org_time, int partner, MPI_Comm comm,
			       int cold_cache)
{
  int i, loc_retval;

  if (_sphinx_myid == 0) {
    loc_retval = 0;

    for (i = 0; i < array_size; i++) {
      tbm_buffer = tbm_buffer_array[i];
      org_square_time_sum = org_square_time_sum_array[i];
      org_time_sum = org_time_sum_array[i];
      square_result_sum = square_result_sum_array[i];
      result_sum = result_sum_array[i];
      mean_value = mean_value_array[i];
      standard_deviation = standard_deviation_array[i];
    
      loc_retval |= am_control_end (ms, arg, time[i], org_time[i],
				    NO_COMMUNICATION, comm, 0, cold_cache);

      /* need to have same counter for each am_control_end call... */
      counter--;

      org_square_time_sum_array[i] = org_square_time_sum;
      org_time_sum_array[i] = org_time_sum;
      square_result_sum_array[i] = square_result_sum;
      result_sum_array[i] = result_sum;
      mean_value_array[i] = mean_value;
      standard_deviation_array[i] = standard_deviation;
    }

    /* Now we really want counter at its new value... */
    counter++;
  }
  
  if (partner != NO_COMMUNICATION) {
    if (partner == USE_COMMUNICATOR) {
      MPI_Bcast (&loc_retval, 1, MPI_INT, 0, comm);
      MPI_Barrier (comm);
    }
    else {
      if (_sphinx_myid == 0) {
	MPI_Ssend (&loc_retval, 1, MPI_INT, partner, 0, ms->communicator);
      }
      else {
	/* you are the client and have to receive from proc 0 */
	MPI_Status status;

	MPI_Recv (&loc_retval, 1, MPI_INT, 0, 0, ms->communicator, &status);
      }
    }
  }

  return loc_retval;
}

int am_multi_control_end (measurement_t *ms, int arg, double *time, 
			  double *org_time, int partner, MPI_Comm comm,
			  int cold_cache)
{
#ifdef _HAVE_OMP_
  if (ms->pattern_in_omp_parallel)
  {
    {
#pragma omp master
      {
	retval = real_am_multi_control_end (ms, arg, time, org_time,
					    partner, comm, cold_cache);
      }
    }

    {
#pragma omp barrier
    }

    return retval;
  }
#endif

  return real_am_multi_control_end (ms, arg, time, org_time,
				    partner, comm, cold_cache);
}

static double *dretval;


double * 
real_am_gap_fill_data (measurement_t *ms, int num_iters_per_time)
{
  double *loc_retval;
  int i, error;
  data_t data;

  data.status = NULL;

  switch (ms->pattern) {
  case COLLECTIVE:
    data.num_dims = ms->data.col_data.result->num_dims + 1;
    for (i = 0; i < ms->data.col_data.result->num_dims; i++) {
      data.arg[i] = ms->data.col_data.result->arg[i];
    }
    if (ms->data.col_data.result->status != NULL)
      mark_status (&data, ms->data.col_data.result->status);
    break;
  case P2P:
    data.num_dims = ms->data.p2p_data.result->num_dims + 1;
    for (i = 0; i < ms->data.p2p_data.result->num_dims; i++) {
      data.arg[i] = ms->data.p2p_data.result->arg[i];
    }
    if (ms->data.p2p_data.result->status != NULL)
      mark_status (&data, ms->data.p2p_data.result->status);
    break;
  case MASTER_WORKER:
    data.num_dims = ms->data.mw_data.result->num_dims + 1;
    for (i = 0; i < ms->data.mw_data.result->num_dims; i++) {
      data.arg[i] = ms->data.mw_data.result->arg[i];
    }
    if (ms->data.mw_data.result->status != NULL)
      mark_status (&data, ms->data.mw_data.result->status);
    break;
  case SIMPLE:
  case THREAD_CHAIN:
    data.num_dims = ms->data.simple_data.result->num_dims + 1;
    for (i = 0; i < ms->data.simple_data.result->num_dims; i++) {
      data.arg[i] = ms->data.simple_data.result->arg[i];
    }
    if (ms->data.simple_data.result->status != NULL)
      mark_status (&data, ms->data.simple_data.result->status);
    break;
  case MULTITIMING:
    data.num_dims = ms->data.multitiming_data.result->num_dims + 1;
    for (i = 0; i < ms->data.multitiming_data.result->num_dims; i++) {
      /* technically this is not correct since result is an array */
      /* when pattern is MULTITIMING; I think it is harmless */
      /* for a couple of reasons: 1) at worst it just ignores */
      /* the args in other than result[0]; and 2) this is unlikely */
      /* to be called with pattern == MULTITIMING... */
      data.arg[i] = ms->data.multitiming_data.result->arg[i];
    }
    if (ms->data.multitiming_data.result->status != NULL)
      mark_status (&data, ms->data.multitiming_data.result->status);
    break;
  default:
    ERROR(USER,"invalid pattern occurred in am_gap_fill_data");
    output_error(TRUE);
  }

  if ((loc_retval = 
       (double *) malloc (array_size * sizeof (double))) == NULL) {
    ERROR (NO_MEM,"in am_gap_fill_data");
    output_error (TRUE);
  }

  for (i = 0; i < array_size; i++) {
    tbm_buffer = tbm_buffer_array[i];
    org_square_time_sum = org_square_time_sum_array[i];
    org_time_sum = org_time_sum_array[i];
    square_result_sum = square_result_sum_array[i];
    result_sum = result_sum_array[i];
    mean_value = mean_value_array[i];
    standard_deviation = standard_deviation_array[i];

    data.arg[data.num_dims - 1] = i;

    am_fill_data (ms, i, &data, num_iters_per_time);
    loc_retval[i] = data.result;
    
    append(ms->result_list,&data,&error);
  }

  if (data.status != NULL) {
    free (data.status);
    data.status = NULL;
  }

  return loc_retval;
}

double * 
am_gap_fill_data (measurement_t *ms, int num_iters_per_time)
{
#ifdef _HAVE_OMP_
  if (ms->pattern_in_omp_parallel)
  {
    {
#pragma omp master
      {
	dretval = real_am_gap_fill_data (ms, num_iters_per_time);
      }
    }

    {
#pragma omp barrier
    }

    return dretval;
  }
#endif

  return real_am_gap_fill_data (ms, num_iters_per_time);
}

void
real_am_multi_fill_data (measurement_t *ms, int arg,
		    data_t *data, int num_iters_per_time)
{ 
  int i;

  for (i = 0; i < array_size; i++) {
    tbm_buffer = tbm_buffer_array[i];
    org_square_time_sum = org_square_time_sum_array[i];
    org_time_sum = org_time_sum_array[i];
    square_result_sum = square_result_sum_array[i];
    result_sum = result_sum_array[i];
    mean_value = mean_value_array[i];
    standard_deviation = standard_deviation_array[i];

    am_fill_data (ms, i, &data[i], num_iters_per_time);
  }

  return;
}

void
am_multi_fill_data (measurement_t *ms, int arg,
		    data_t *data, int num_iters_per_time)
{ 
#ifdef _HAVE_OMP_
  if (ms->pattern_in_omp_parallel)
  {
#pragma omp master
    {
      real_am_multi_fill_data (ms, arg, data, num_iters_per_time);
    }
  }
  else 
#endif
    real_am_multi_fill_data (ms, arg, data, num_iters_per_time);

  return;
}


