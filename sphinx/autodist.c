/*
$Log: autodist.c,v $
Revision 1.33  2000/11/17 21:56:02  bronis
eliminated minor warnings

Revision 1.32  2000/11/15 00:00:39  bronis
made changes to improve scalability

Revision 1.31  2000/09/15 00:04:59  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.30  2000/09/06 21:09:12  bronis
Added several OpenMP versions for Alpha clusters in various states of correctness

Revision 1.29  2000/08/25 23:17:15  bronis
Added OpenMP tests

Revision 1.28  2000/03/16 15:48:38  bronis
fixed mpguidec warnings

Revision 1.27  2000/02/17 14:18:57  bronis
added first real non-blocking tests

Revision 1.26  2000/01/18 18:42:10  bronis
Added MPI_Comm_free calls

Revision 1.25  2000/01/14 23:34:55  bronis
purified recent changes

Revision 1.24  2000/01/10 21:50:23  bronis
Added full blown aux tests implementation

Revision 1.23  1999/10/29 00:11:09  bronis
Fixed bugs, made input case insensitive

Revision 1.22  1999/10/19 20:41:00  srtaylor
Fixed dynamic scales

Revision 1.21  1999/10/19 16:27:50  bronis
fixed scale case statement

Revision 1.20  1999/10/12 22:57:14  srtaylor
Added fixed log scale and multi-dimension output description

Revision 1.19  1999/10/04 21:29:32  bronis
first cut at output filters

Revision 1.18  1999/10/04 15:53:05  bronis
fixed ACKer position bugs

Revision 1.17  1999/10/01 21:36:52  bronis
Added debugged Root variation

Revision 1.16  1999/09/29 16:10:41  bronis
First cut at ROOT variation

Revision 1.15  1999/09/29 00:23:47  bronis
removed most restrictions on ACKER variation

Revision 1.14  1999/09/23 17:08:43  bronis
cleaned up multi dim stuff

Revision 1.13  1999/09/21 23:28:38  bronis
fixed pthreads tests

Revision 1.12  1999/09/21 15:59:50  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.11  1999/09/20 19:00:36  srtaylor
Merged measure and measure_suite

Revision 1.10  1999/09/17 23:02:59  bronis
Split BINDING variation

Revision 1.9  1999/09/16 23:26:01  bronis
fixed fill_dummy_values calls

Revision 1.8  1999/09/16 21:07:43  srtaylor
Added max_message_len check

Revision 1.7  1999/09/16 16:17:49  bronis
incremental multi dim changes

Revision 1.6  1999/09/16 00:15:45  srtaylor
Outputs correct results for multiple dimensions

Revision 1.5  1999/09/15 15:50:56  srtaylor
Structure modifications - Does not currently compile

Revision 1.4  1999/09/14 16:38:50  srtaylor
First cut at multiple dimensions

Revision 1.3  1999/08/19 20:55:04  bronis
made old/new examples agree fully

Revision 1.2  1999/07/13 18:57:54  srtaylor
Handled DEC strcmp NULL problem

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_aux.h"
#include "autodist.h"
#include "pqtypes.h"
#include "sphinx_error.h"
#include "sphinx_tools.h"
#include "sphinx_threads.h"
#include "pattern.h"
#include "sphinx_params.h"
#include "sphinx_call.h"
#include "sphinx_omp.h"

/* internal Prototypes */
double calculate_key (measurement_t *ms, PqData prio_data, int log_flag);
double min3 (double a, double b, double c);
int double_round (double f);

extern int	min_node;
extern int	max_node;
extern double   *cur_gaps;
extern params_t params;


#ifdef _HAVE_OMP_

extern int sphinx_omp_max_num_threads;

#endif

/* forward definition */
int
get_ms_steps (measurement_t *ms, double **ms_steps, 
	      int *ms_count, int *ms_nop, int n);

int
call_pattern  (measurement_t *ms, int n)
{
  if (ms->have_omp_params) {
    int temp_retval;

#ifdef _HAVE_OMP_
    if (ms->pattern_in_omp_parallel)
#pragma omp single
      {	    
	temp_retval = set_up_omp_parameters (ms);
      }
    else
#endif
      temp_retval = set_up_omp_parameters (ms);

    if (temp_retval) return temp_retval;
  }
	  
  switch (ms->pattern) {
  case P2P:
    return p2p_pattern (ms, n);
  case MASTER_WORKER:
    return mw_pattern (ms, n);
  case COLLECTIVE:
    return col_pattern (ms, n);
  case SIMPLE:
    return simple_pattern (ms, n);
  case THREAD_CHAIN:
    return thread_chain_pattern (ms, n);
  case MULTITIMING:
    return multitiming_pattern (ms, n);
  default:
    ERROR(USER,"invalid pattern occured in measure");
    output_error(FALSE);
    return GENERIC_ERROR;
  }
}


/*
   @FUN:
   @DOES: computes all arguments, where to measure the measurement ms and calls
   it via the routine tbm (to_be_measured).
   @PARAMETERS: above.
   @RETURNES: nothing
   @SIDEEFFECTS: sets ms->dimensions[n].end to effective value, if it is initialized to\\
   MAX_ARGUMENT, 
   exits in case of error.
   @ASSUMES: _sphinx_myid set.
*/
int
measure (measurement_t *ms, int n)
{
  signed int error;
  int        nop;
  int        max_allowed_length, Root_var = FALSE;
  double     arg, *steps;
  int        index, measurements_count, ad_retval = 0; 
  data_t     single_data, *multi_data = NULL;
  int        j, wrote_data = FALSE;

  if ((ms->uses_proxy) && (ms->need_to_create_proxy)) {
    /* initial/main thread doesn't do measurement; create the */
    /* measurement thread, wait for it to finish and then return... */
    return create_and_use_proxy_thread (ms, n);
  }

  if (n == 0) {
    if (!ms->ACKer_OK) {
      for (j = 0; j < ms->dimensions_count; j++) {
	if (ms->dimensions[j].variation == ACKER) {
	  ERROR (USER, "Invalid test type for ACKer variation");
	  output_error (FALSE);
	  return GENERIC_ERROR;
	}
      }
    }

    if (ms->pattern == MULTITIMING) {
      /* this is kludgie but it works... */
      multi_data = (data_t *)
	malloc (sizeof(data_t) * ms->data.multitiming_data.num_timings);

      for (j = 0; j < ms->data.multitiming_data.num_timings; j++) {
	multi_data[j].num_dims = ms->dimensions_count;
	multi_data[j].status = NULL;
	multi_data[j].reference = UNMEASURED;
      }	
      if ((_sphinx_myid == 0) &&
	  ((ms->result_list =
	    init_list_array (ms->data.multitiming_data.num_timings)) == NULL))
	return GENERIC_ERROR;  /* other processes ?? */
    }
    else {
      if ((_sphinx_myid == 0) &&
	  ((ms->result_list = init_list (NULL)) == NULL))
	return GENERIC_ERROR;  /* other processes ?? */

      single_data.num_dims = ms->dimensions_count;
      single_data.status = NULL;
      single_data.reference = UNMEASURED;
    }

    O(if (_sphinx_myid == 0) printf ("starting measurement %s\n", ms->name);)

    switch (ms->pattern) {
    case COLLECTIVE:
      ms->data.col_data.result = &single_data;
      break;
    case P2P:
      ms->data.p2p_data.result = &single_data;
      break;
    case MASTER_WORKER:
      ms->data.mw_data.result = &single_data;
      break;
    case SIMPLE:
    case THREAD_CHAIN:
      ms->data.simple_data.result = &single_data;
      break;
    case MULTITIMING:
      ms->data.multitiming_data.result = multi_data;
      break;
    default:
      ERROR(USER,"invalid pattern occurred in measure");
      output_error(FALSE);
      return GENERIC_ERROR;
    }
  }

  MPI_Comm_size (ms->communicator, &nop);

  /* Only calculate max_allowed_length once - when n == 0 */
  if (n == 0) {
    if (!(max_allowed_length = 
	  ms->server_init (ms->max_rep * 
			   (ms->pattern == MASTER_WORKER ? 
			    ms->data.mw_data.chunks:1),
			   ms->dimensions[n].max_steps, nop, ms))) {
      ERROR (NO_MEM, "no memory for messages");

      return GENERIC_ERROR;
    }

    /* this assumes we get the same answer everywhere */
    /* which should be true outside of errors... */
    ms->max_allowed_len = max_allowed_length;

    ms->server_free(ms);

    if (!(max_allowed_length = 
	  ms->client_init (ms->max_rep *
			   (ms->pattern == MASTER_WORKER ? 
			    ms->data.mw_data.chunks:1),
			   ms->dimensions[n].max_steps, nop, ms))) {
      sprintf (_sphinx_msg, 
	       "no memory for messages: ms = %s", ms->name);
      ERROR(NO_MEM,_sphinx_msg);
      output_error (TRUE);
    }

    if (max_allowed_length < ms->max_allowed_len)
      ms->max_allowed_len = max_allowed_length;
	    
    ms->client_free(ms);
  }

  /* Determine data points */ 
  if (ad_retval = get_ms_steps (ms, &steps, &measurements_count, &nop, n))
    return ad_retval;

  /* Do the measurements */
  for (index=0; index< measurements_count; index++) {
    arg = steps[index];

    if (_sphinx_myid == 0)
      printf("- %d - measuring at arg %d.\n", n, double_round (arg));

    /* Damn union makes this ugly */
    switch (ms->pattern) {
    case COLLECTIVE:
      ms->data.col_data.result->arg[n] = double_round (arg);
      break;
    case P2P:
      ms->data.p2p_data.result->arg[n] = double_round (arg);
      break;
    case MASTER_WORKER:
      ms->data.mw_data.result->arg[n] = double_round (arg);
      break;
    case SIMPLE:
    case THREAD_CHAIN:
      ms->data.simple_data.result->arg[n] = double_round (arg);
      break;
    case MULTITIMING:
      for (j =0; j < ms->data.multitiming_data.num_timings; j++)
	/* this is kludgie but it works... */
	ms->data.multitiming_data.result[j].arg[n] =  double_round (arg);
      break;
    default:
      ERROR(USER,"invalid pattern occurred in measure");
      output_error(FALSE);
      return GENERIC_ERROR;
    }

    ad_retval = call_variation_prologue (ms, double_round (arg), n, index);

    /* here we assume prologue failure is universal... */
    /* this means prologues should not require communication */
    if (ad_retval) return ad_retval;

    if (need_to_do_aux_tests (ms, double_round (arg), n)) {
      ad_retval = do_aux_tests (ms, double_round (arg), n, nop);

      if (ad_retval) {
	sprintf (_sphinx_msg,"measurement %s failed do_aux_tests.\n",
		 ms->name);
	write_to_log_file (_sphinx_msg);
	ERROR(INTERN,_sphinx_msg);
	output_error (TRUE);
      }
    }

    if (n < ms->dimensions_count - 1) {
      /* recurse to finish setting up data point... */
      ad_retval = measure (ms, n + 1);
    }
    else {
      if (ms->should_call_pattern) {
	if (!ad_retval) 
#ifdef _HAVE_OMP_
	  if (ms->pattern_in_omp_parallel)
#pragma omp parallel reduction (|: ad_retval)
	    {	    
	      ad_retval = call_pattern (ms, n);
	    }
	  else
#endif
	    ad_retval = call_pattern (ms, n);
      }
      else {
	/* if don't participate then no error by definition... */
	ad_retval = 0;
      }

      for (j = 0; j < ms->dimensions_count; j++)
	if (ms->dimensions[j].variation == ROOT) {
	  Root_var = TRUE;
	  break;
	}

      /* need to select between server/client... */
      if ((!Root_var && (_sphinx_myid == 0)) || 
	  (Root_var && (_sphinx_myid == ms->root)))
	ms->server_free(ms);
      else
	/* use client_free if ROOT_VAR and not root... */
	ms->client_free(ms);
    }

    /* assume task zero learns about any errors in the pattern routine */
    if (ad_retval) {
      sprintf (_sphinx_msg,"measurement %s failed with %dth arg %d.\n",
	       ms->name, n, double_round (arg));
      write_to_log_file (_sphinx_msg);

      ERROR(INTERN,_sphinx_msg);
      output_error (TRUE);
    }

    /* For now we assume failure in use_aux_tests just marks */
    /* the result as odd (UNRELIABLE, maybe others...) */
    /* to remove assumption catch return value of use_aux_tests */
    /* and call MPI_Abort if it is non-zero */
    use_aux_tests (ms, double_round (arg), n);

    if ((_sphinx_myid == 0) && (ms->dimensions_count == n + 1)) {
      switch (ms->pattern) {
      case COLLECTIVE:
	append(ms->result_list,ms->data.col_data.result,&error);
	if (ms->data.col_data.result->status != NULL) {
	  free (ms->data.col_data.result->status);
	  ms->data.col_data.result->status = NULL;
	}
	break;
      case P2P:
	append(ms->result_list,ms->data.p2p_data.result,&error);
	if (ms->data.p2p_data.result->status != NULL) {
	  free (ms->data.p2p_data.result->status);
	  ms->data.p2p_data.result->status = NULL;
	}
	break;
      case MASTER_WORKER:
	append(ms->result_list,ms->data.mw_data.result,&error);
	if (ms->data.mw_data.result->status != NULL) {
	  free (ms->data.mw_data.result->status);
	  ms->data.mw_data.result->status = NULL;
	}
	break;
      case SIMPLE:
      case THREAD_CHAIN:
	append(ms->result_list,ms->data.simple_data.result,&error);
	if (ms->data.simple_data.result->status != NULL) {
	  free (ms->data.simple_data.result->status);
	  ms->data.simple_data.result->status = NULL;
	}
	break;
      case MULTITIMING:
	for (j = 0; j < ms->data.multitiming_data.num_timings; j++) {
	  append(&(ms->result_list[j]),
		 &(ms->data.multitiming_data.result[j]),&error);
	  if (ms->data.multitiming_data.result[j].status != NULL) {
	    free (ms->data.multitiming_data.result[j].status);
	    ms->data.multitiming_data.result[j].status = NULL;
	  }
	}
	break;
      default:
	ERROR(USER,"invalid pattern occurred in measure");
	output_error (TRUE);
      }
   
      if (error != DL_NO_ERROR) {
	ERROR(NO_MEM,"no memory for results");
	output_error (TRUE);
      }
    }
  } /* for */

  free (steps);
   
  if (multi_data != NULL)
    free (multi_data);

  /* Prepare output */
  if ((n == 0) && (_sphinx_myid == 0)) {
    char *pattern_str = "";

    if (ms->name != NULL) {
      FILE *output_file;

      if ((output_file = fopen (out_file_name,"a+")) == NULL) {
        ERROR(FILE_OPEN,"append of measurement");
	output_error (FALSE);
        return GENERIC_ERROR;
      }

      switch (ms->pattern) {
      case P2P:
        pattern_str = "p2p";
        break;
      case MASTER_WORKER:
        pattern_str = "mw";
        break;
      case COLLECTIVE:
        pattern_str = "col";
        break;
      case SIMPLE:
        pattern_str = "simple";
        break;
      case THREAD_CHAIN:
        pattern_str = "thr_chain";
        break;
      case MULTITIMING:
        pattern_str = "multitiming";
        break;
      default:
        ERROR(INTERN,"unknown pattern");
        output_error (TRUE);
      }

      if (ms->pattern == MULTITIMING) {
        /* this is quick; really should have separate names per timing */
        for (j = 0; j < ms->data.multitiming_data.num_timings; j++) {
          if (number_of_elements(&(ms->result_list[j])) != 0) {
            wrote_data = TRUE;
            fprintf (output_file,"\n#-------------------------------"\
                     "\n#/*@""in%s_%s.%d.ski*/\n%s", pattern_str,
                     ms->name, j, measurement_data_to_string(ms,expl_text,n));
            write_to_file (&(ms->result_list[j]), output_file, 
			   ms->dimensions_count, ms->dimensions,
			   ms->use_reference_data);

	    /* first cut at filtering */
	    filter_ACKER_root (ms, &(ms->result_list[j]),
			       output_file, pattern_str, expl_text, j);
          }
        }

        free_data_list_array (ms->result_list, DYNAMIC,
                              ms->data.multitiming_data.num_timings);
      }
      else {
        if (number_of_elements(ms->result_list) != 0) {
          wrote_data = TRUE;
          fprintf (output_file,"\n#-------------------------------"\
                   "\n#/*@""in%s_%s.ski*/\n%s", pattern_str,
                   ms->name, measurement_data_to_string(ms, expl_text, n));
          write_to_file (ms->result_list, output_file, 
			 ms->dimensions_count, ms->dimensions,
			 ms->use_reference_data);
  
	  /* first cut at filtering */
	  filter_ACKER_root (ms, ms->result_list, 
			     output_file, pattern_str, expl_text, -1);
        }

        free_data_list (ms->result_list, DYNAMIC);
      }

      if (wrote_data) {
        sprintf (_sphinx_msg,"Wrote data of measurement: %s to file %s\n",
                 ms->name, out_file_name);
        write_to_log_file (_sphinx_msg);
      }

      fclose (output_file);
    }
  }

  return ad_retval;
}


/*
   @FUN:
   @DOES: determines data points for nth variation of ms
   @PARAMETERS: the actual measurement, the measure recursion level
   @RETURNS: TRUE if need to do any thing with a distributed error condition
   @SIDEEFFECTS: sets nop and max_allowed_len for NODES pattern
   @ASSUMES: 
*/
int
get_ms_steps (measurement_t *ms, double **ms_steps, 
	      int *ms_count, int *ms_nop, int n)
{
  double start = (double)ms->dimensions[n].start;
  double end = (double)ms->dimensions[n].end;
  double stepwidth = (double)ms->dimensions[n].stepwidth;
  double next_step, *steps;
  int    nop = *ms_nop;
  int    index, need_to_skip_one = FALSE;
  int    local_nop, one_to_skip, j;

  switch (ms->dimensions[n].variation) {
  case  NODES:
    if (ms->dimensions[n].end != MAX_ARGUMENT) {
      nop = SPHINX_MIN (end, nop);
    }
    else {
      ms->dimensions[n].end = nop;
    }

    end = (double)nop;

    if (ms->dimensions[n].start == MIN_ARGUMENT) {
      ms->dimensions[n].start = 2;
      start = 2.0;
    }

    /* Damn union makes this ugly... */
    /* Avoid Comm_size errors when NODES preceded by ACKER or ROOT */
    for (j = 0; j < n; j++) {
      if ((ms->dimensions[j].variation == ACKER) ||
	  (ms->dimensions[j].variation == ROOT)) {
	switch (ms->pattern) {
	case COLLECTIVE:
	  start = (double) SPHINX_MAX(start, 
				      ms->data.col_data.result->arg[j] + 1);
	  break;
	case P2P:
	  start = (double) SPHINX_MAX(start, 
				      ms->data.p2p_data.result->arg[j] + 1);
	  break;
	case MASTER_WORKER:
	  start = (double) SPHINX_MAX(start, 
				      ms->data.mw_data.result->arg[j] + 1);
	  break;
	case SIMPLE:
	case THREAD_CHAIN:
	  start = 
	    (double) SPHINX_MAX(start, 
				ms->data.simple_data.result->arg[j] + 1);
	  break;
	case MULTITIMING:
	  /* this is kludgie but it works... */
	  start = 
	    (double)SPHINX_MAX(start, 
			       ms->data.multitiming_data.result[0].arg[j]+1);
	  break;
	default:
	  ERROR(USER,"invalid pattern occurred in get_ms_steps");
	  output_error(FALSE);
	  return GENERIC_ERROR;
	}
      }
    }
    break;

  case LENGTH:
    if (ms->dimensions[n].end == MAX_ARGUMENT)
      end = ms->max_allowed_len;
    else
      end = SPHINX_MIN (ms->max_allowed_len, end);

    ms->dimensions[n].end = (int) end;  
    
    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 1.0;

    break;

  case CHUNK:
    if (ms->dimensions[n].end == MAX_ARGUMENT) 
      end = params.chunks_default;
    else
      end = SPHINX_MIN (params.chunks_default, end);
    
    end = ms->dimensions[n].end;

    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 1.0;

    break;

  case NO_VARIATION:
    /* start and end not used... */
    break;

  case ITERS:
    if (ms->dimensions[n].end != MAX_ARGUMENT)
      end = ms->dimensions[n].end;
    else
      end = params.iters_per_time_default;

    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 1.0;

    break;

  case MASTER_BINDING: /* uses fall through... */
  case SLAVE_BINDING:
    if (ms->dimensions[n].end == MAX_ARGUMENT)
      end = GETMAXPROCS(ONLINE) - 1;
    else
      end = SPHINX_MIN (GETMAXPROCS(ONLINE) - 1, end);

    if (ms->dimensions[n].start == MIN_ARGUMENT) {
      ms->dimensions[n].start = UNBIND;
      start = (double)ms->dimensions[n].start;
    }

    break;

  case ACKER: /* uses fall through... */
  case ROOT:
    MPI_Comm_size (ms->data.col_data.communicator, &local_nop);
    
    if (ms->dimensions[n].end != MAX_ARGUMENT) {
      end = (double) SPHINX_MIN (end, local_nop - 1);
    }
    else {
      end = (double) local_nop - 1;
    }

    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 0.0;

    /* tests assume don't measure same ACKer and root... */
    /* determine one_to_skip, if any */
    for (j = 0; j < n; j++) {
      if ((ms->dimensions[n].variation == ACKER) && 
	  (ms->dimensions[j].variation == ROOT)) {
	need_to_skip_one = TRUE;
	one_to_skip = ms->root;
      }
      else if ((ms->dimensions[j].variation == ACKER) && 
	       (ms->dimensions[n].variation == ROOT)) {
	/* this assumes ACKER implies ms->pattern == COLLECTIVE */
	need_to_skip_one = TRUE;
	one_to_skip = ms->data.col_data.ACKer;
      }
    }

    if ((!need_to_skip_one) && (ms->dimensions[n].variation == ACKER)) {
      /* if no ROOT variation then need to skip default root... */
      for (j = n + 1; j < ms->dimensions_count; j++) {
	if (ms->dimensions[j].variation == ROOT) {
	  /* don't need to skip one; kind of kludgie but it works... */
	  need_to_skip_one = TRUE;
	  break;
	}
      }

      /* see, it is kludgie... */
      if (need_to_skip_one) {
	need_to_skip_one = FALSE;
      }
      else {
	need_to_skip_one = TRUE;
	one_to_skip = ms->root;
      }
    }

    break;

  case OVERLAP: /* uses fall through... */
  case SECOND_OVERLAP:
    if (ms->dimensions[n].end != MAX_ARGUMENT)
      end = ms->dimensions[n].end;
    else
      end = params.overlap_default;
    
    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 0.0;

    break;

  case WORK_AMOUNT:
    if (ms->dimensions[n].end != MAX_ARGUMENT)
      end = ms->dimensions[n].end;
    else
      end = params.work_amt_default;

    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 0.0;

    break;

  case WORK_FUNCTION:
    if (ms->dimensions[n].end != MAX_ARGUMENT)
      end = SPHINX_MIN (ms->dimensions[n].end, WORK_FUNCTION_COUNT - 1);
    else
      end = WORK_FUNCTION_COUNT - 1;

    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 0.0;

    break;

  case OVERLAP_FUNCTION:
    if (ms->dimensions[n].end != MAX_ARGUMENT)
      end = SPHINX_MIN (ms->dimensions[n].end, 
			OMP_OVERLAP_FUNCTION_COUNT - 1);
    else
      end = OMP_OVERLAP_FUNCTION_COUNT - 1;
    
    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 0.0;
    
    break;

  case SCHED_CAP:
    if (ms->dimensions[n].end != MAX_ARGUMENT)
      end = ms->dimensions[n].end;
    else
      end = params.schedule_cap_default;

    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 0.0;

    break;

  case SCHED_CHUNKS:
    if (ms->dimensions[n].end != MAX_ARGUMENT)
      end = ms->dimensions[n].end;
    else
      end = params.schedule_chunks_default;

    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 1.0;

    break;

  case SCHEDULE:
    if (ms->dimensions[n].end != MAX_ARGUMENT)
      end = SPHINX_MIN (ms->dimensions[n].end, SCHEDULE_COUNT - 1);
    else
      end = SCHEDULE_COUNT - 1;

    if (ms->dimensions[n].start == MIN_ARGUMENT)
      start = ms->dimensions[n].start = 0.0;

    break;

  case THREADS:

#ifdef _HAVE_OMP_
    if (ms->dimensions[n].end == MAX_ARGUMENT)
      end = sphinx_omp_max_num_threads;
    else
      end = SPHINX_MIN (sphinx_omp_max_num_threads, end);
#else
    end = ms->dimensions[n].end = 1.0;
#endif

#ifdef _HAVE_OMP_
    if (ms->dimensions[n].start == MIN_ARGUMENT)
#endif
      start = ms->dimensions[n].start = 1.0;

    break;

  default:
    ERROR(USER,"invalid variation occurred in get_ms_steps");
    output_error(FALSE);
    return GENERIC_ERROR;
  }

  if (_sphinx_myid == 0)
    fprintf (stderr, "in autodist - 1: start %f, end %f, stw %f\n", 
	     start, end, stepwidth);

  if (ms->dimensions[n].variation != NO_VARIATION) {
    int slots_open, steps_count, k;
    steps = (double *) malloc (sizeof(double)*ms->dimensions[n].max_steps);

    switch (ms->dimensions[n].scale) {
    case FIXED_LIN: 
    case DYN_LIN: 
      next_step = start;
      index = 0;

      while ((next_step <= end) && (index < ms->dimensions[n].max_steps)) {
	/* use it unless we should skip it... */
	if ((!need_to_skip_one) || 
	    (one_to_skip != double_round (next_step))) {
	  steps[index] = next_step;
	  index++;
	}
	next_step += ms->dimensions[n].stepwidth;
      }
 
      /* The last step must be set to "end" regardless of scale type */
      if ((!need_to_skip_one) || (one_to_skip != double_round (end))) {
	/* don't overwrite last loop value if more room */
	if ((index < ms->dimensions[n].max_steps) && 
	    (double_round (steps[index-1]) != end))
	  index++;

	steps[index-1] = end;
      }

      if (ms->dimensions[n].scale == FIXED_LIN) 
	/* have all the data points that we'll use */
	break;
        
      /* Save the number of elements specified by the user */
      steps_count = index-1;
 
      /* While there are still open slots and space for more steps*/
      slots_open = steps_count;

      while ((index < ms->dimensions[n].max_steps) && (slots_open > 0)) {
	slots_open = steps_count;

	for (j=1; j < (steps_count * 2); j++) {
	  /* If there is space to insert a new step insert in the middle */
	  if ((steps[j] - steps[j-1]) > 1) {
	    /* Shuffle each of the steps one step to the right */
	    for (k= (index-1); k >= j; k--) {
	      steps[k+1] = steps[k];
	    }

	    steps[j] = steps[j-1] + ((steps[j]-steps[j-1])/2);
	    index++;
	    j++;
	    
	    if (index == ms->dimensions[n].max_steps) {
	      break;
	    }
	  }
	  else {
	    slots_open--;
	  }
	}

	steps_count = index-1;
      }

      break;

    case FIXED_LOG: 
    case DYN_LOG: 
      /* should already have detected this, but to be safe: */
      if (ms->dimensions[n].max_steps == 0) {
	ERROR(INTERN,"no steps for log scale occurred in measure");
	output_error(TRUE);
      }

      next_step = start * ms->dimensions[n].stepwidth;

      /* get first data point */
      if ((!need_to_skip_one) || 
	  (one_to_skip != double_round (start))) {
	steps[0] = start;
      }
      else {
	/* need to skip start... */
	while ((next_step <= end) &&
	       (double_round (next_step) == double_round (start)))
	  /* haven't "skipped" it yet... */
	  next_step *= ms->dimensions[n].stepwidth;
	
	if (next_step > end) {
	  if (double_round (end) == double_round (start)) {
	    /* One could argue that this is a user error */
	    ERROR(INTERN,"no valid data points for log scale");
	    output_error(TRUE);
	  }

	  steps[0] = end;
	}
	else {
	  steps[0] = next_step;
	  next_step *= ms->dimensions[n].stepwidth;
	}
      }
	    
      index = 1;

      while ((next_step <= end) && (index < ms->dimensions[n].max_steps)) {
	/* use it unless we should skip it... */
	if (((!need_to_skip_one) || 
	     (one_to_skip != double_round (next_step))) &&
	    (double_round (next_step) != double_round (steps[index-1]))) {
	  steps[index] = next_step;
	  index++;
	}

	next_step *= ms->dimensions[n].stepwidth;
      }

      /* The last step must be set to "end" regardless of scale type */
      if ((!need_to_skip_one) || (one_to_skip != double_round (end))) {
	/* don't overwrite last loop value if more room */
	if ((index < ms->dimensions[n].max_steps) && 
	    (double_round (steps[index-1]) != end)) 
	  index++;

	steps[index-1] = end;
      }

      if (ms->dimensions[n].scale == FIXED_LOG) 
	/* have all the data points that we'll use */
	break;

      /* Save the number of elements specified by the user */
      steps_count = index - 1;

      /* While there are still open slots and space for more steps*/
      slots_open = steps_count;

      while ((index < ms->dimensions[n].max_steps) && (slots_open > 0)) {
	slots_open = steps_count;

	for (j=1; j<(steps_count*2); j++) {
	  /* Is there space to insert a new step in the middle? */
	  if ((double_round(steps[j]) - double_round(steps[j-1])) > 1) {
	    /* Shuffle each of the steps one step to the right */
	    for (k=(index-1); k>=j; k--) {
	      steps[k+1] = steps[k];
	    }

	    steps[j] = sqrt(steps[j-1]) * sqrt(steps[j]);
	    index++;
	    j++;

	    if (index == ms->dimensions[n].max_steps) {
	      break;
	    }
	  }
	  else {
	    slots_open--;
	  }
	}

	steps_count = index-1;
      }

      break;

    default:
      ERROR(INTERN,"invalid scale occurred in get_ms_steps");
      output_error(TRUE);
    }

    *ms_count = index;
  }
  else {
    /* measure exactly one data point for NO_VARIATION */
    steps = (double *)malloc (sizeof (double));
    steps[0] = NO_VARIATION_ARG_VALUE;
    *ms_count = 1;
  }

  /* fix up return values; this is easiest way to move code out of measure */
  *ms_nop = nop;
  *ms_steps = steps;

  return 0;
}

/*
   @FUN:
   @DOES: determines if any auxilliary measurements are required
   @PARAMETERS: the actual measurement, the measure recursion level
   @RETURNS: TRUE if need to do any thing with a distributed error condition
   @SIDEEFFECTS: 
   @ASSUMES: 
*/
int
need_to_do_aux_tests (measurement_t *ms, int the_arg, int n)
{
  int  i;

  /* first, see if we need to do server/client_init function... */
  if (n + 1 == ms->dimensions_count) {
    return TRUE;
  }

  /* second, see if we need to do p2p_find_max_min... */
  if ((ms->pattern == P2P) && ((max_node == -1) || (min_node == -1))) {
    return TRUE;
  }

  /* next determine if we need to do create_communicator now */
  if (ms->dimensions[n].variation == NODES) {
    return TRUE;
  }
  
  if (ms->aux_tests == NULL) {
    return FALSE;
  }

  for (i = 0; i < ms->num_aux_tests; i++) {
    if (ms->aux_tests[i].need_aux_f(ms, the_arg, n)) {
      return TRUE;
    }
  }

  return FALSE;
}

/*
   @FUN:
   @DOES: does any required auxilliary measurements
   @PARAMETERS: the actual measurement, the measure recursion level
   @RETURNS: 0 if succcessful; error code (GENERIC_ERROR?) otherwise
   @SIDEEFFECTS: 
   @ASSUMES: 
*/
int
do_aux_tests (measurement_t *ms, int the_arg, int n, int nop)
{
  int  i, local_max_allowed_length, retval, Root_var = FALSE;

  /* first, do p2p_find_max_min if necessary... */
  if ((ms->pattern == P2P) && ((max_node == -1) || (min_node == -1))) {
    /* the P2P tests should really use the MAX or MIN */
    /* PAIR - which may not involve task zero... */
    /* Of course, I don't care enough right now to bother... */
    retval = p2p_find_max_min (ms);
    if (retval) return retval;
  }

  /* next determine if we need to do create_communicator now */
  if (ms->dimensions[n].variation == NODES) {
    retval = call_create_communicator (ms, the_arg, n);
    if (retval) return retval;
  }
  
  if (ms->aux_tests != NULL) {
    for (i = 0; i < ms->num_aux_tests; i++) {
      if (ms->aux_tests[i].need_aux_f(ms, the_arg, n)) {
	retval = ms->aux_tests[i].aux_f(ms, the_arg, n);
	if (retval) return retval;
      }
    }
  }

  /* last, do server/client_init function if necessary... */
  /* needs to be last so aux tests can assume not yet done... */
  if (n + 1 != ms->dimensions_count) {
    /* don't need to do server/client_init function */
    return SUCCESS;
  }

  for (i = 0; i < ms->dimensions_count; i++)
    if (ms->dimensions[i].variation == ROOT) {
      Root_var = TRUE;
      break;
    }

  /* need to select between server/client... */
  if ((Root_var && (_sphinx_myid == ms->root)) ||
      (!Root_var && (_sphinx_myid == 0))) {
    if (!(local_max_allowed_length = 
	  ms->server_init (ms->max_rep *
			   (ms->pattern == MASTER_WORKER ? 
			    ms->data.mw_data.chunks:1),
			   ms->dimensions[n].max_steps, nop, ms))) {
      ERROR (NO_MEM, "no memory for messages");
      output_error (FALSE);
      return GENERIC_ERROR;
    }
  }
  else {
    if (!(local_max_allowed_length = 
	  ms->client_init (ms->max_rep, 
			   ms->dimensions[n].max_steps, nop, ms))) {
      ERROR(NO_MEM,"client has not enough memory for messages");
      output_error (FALSE);
      retval = GENERIC_ERROR;
    }
  }

  /* Check that the max_allowed_length hasn't decreased... */
  if (local_max_allowed_length < ms->max_allowed_len) {
    ERROR (USER, "local_max_allowed length < ms->max_allowed len");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  return SUCCESS;
}


/*
   @FUN:
   @DOES: uses auxilliary measurements as appropriate
   @PARAMETERS: the actual measurement, the measure recursion level
   @RETURNS: 0 if succcessful; error code (GENERIC_ERROR?) otherwise
   @SIDEEFFECTS: 
   @ASSUMES: only one variation is ACKER... 
*/
int
use_aux_tests (measurement_t *ms, int the_arg, int n)
{
  int  i, retval;

  /* next determine if we need to do create_communicator now */
  if (ms->dimensions[n].variation == NODES) {
    retval = call_destroy_communicator (ms, the_arg, n);

    /* this should probably be fatal since we don't check across tasks... */
    if (retval) return retval;
  }
  
  if (ms->aux_tests == NULL) {
    return SUCCESS;
  }

  for (i = 0; i < ms->num_aux_tests; i++) {
    retval = ms->aux_tests[i].use_aux_f(ms, the_arg, n);

    /* this should probably be fatal since we don't check across tasks... */
    if (retval) return retval;
  }

  return SUCCESS;
}

/*
   @FUN:
   @DOES: computes the key for the x_axis - segment for inserting it into the
   Priority-queue.
   @PARAMETERS: the actual measurement,
   the x_axis segment pqdata.
   @RETURNES: the key
   @SIDEEFFECTS: none.
   @ASSUMES: MACRO FUN defined.
*/
#define FUN(a,b) (SPHINX_MAX((a),(b)))
#if 0
double calculate_key (measurement_t *ms, PqData pqdata, int log_flag)
{
  data_t
    *me,
    left,
    right1,
    right2;

  double 
    min_diff,
    diff_left,
    diff_right,
    horizontal,
    a,   /* args */
    l,
    r1,
    r2;

  int 
    error;

  /* does not matter if pqdata is the the leftmost data-element,
     then left will be a pointer to it. */
  read_item_ele (ms->result_list, pqdata, -1, &left, &error);
  read_item_ele (ms->result_list, pqdata, 1, &right1, &error);
  read_item_ele (ms->result_list, pqdata, 2, &right2, &error);
  me = &(pqdata->data);

  a = me->arg;
  l = left.arg;
  r1 = right1.arg;
  r2 = right2.arg;

  diff_left = fabs (linear_interpolate (a, r1, r2,
					right1.result, right2.result) - 
		    me->result) / (me->result == 0 ? 1 : me->result);
  
  diff_right = fabs (linear_interpolate (r1, l, a,
					 left.result, me->result) - 
		     right1.result) / (right1.result == 0 ? 1 : right1.result);

  horizontal = ((double) r1) / ((double) (a == 0 ? 1.0 : a)) - 1.0;

  min_diff = min3 (horizontal, diff_left, diff_right);



#if 0 
  sprintf (_sphinx_msg,"**autodist** at arg: %f (l: %f r1: %f r2: %f)"\
           "min_diff: %f diff_left: %f diff_right: %f horizontal: %f \n", 
           a, l, r1, r2, min_diff, diff_left, diff_right, horizontal);
  write_to_log_file (_sphinx_msg);
#endif

#if 0 /* Verfeinerung besser, wenn abgeschaltet */
  if (min_diff < me->standard_error / me->result)
    return (PQMINUSINFINITY);
#endif

  return (min_diff);
}
#endif

double min3 (double a, double b, double c)
{
  if (a < b)
  {
    if (c < a)
      return (c);
    else
      return (a);
  }
  else
  {
    if (c < b)
      return (c);
    else
      return (b);
  }
}

int double_round (double f)
{
  return (f < 0 ? (int) f : (int) (f + 0.5));
}
