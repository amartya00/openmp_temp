#include <stdlib.h>

#include "sphinx.h"
#include "sphinx_aux.h"
#include "sphinx_error.h"
#include "sphinx_tools.h"
#include "sphinx_aux_test.h"
#include "sphinx_params.h"
#include "col_test1.h"
#include "mw_test1.h"
#include "p2p_test1.h"
#include "simple_test1.h"
#include "autodist.h"
#include "pattern.h"
#include "sphinx_omp.h"


/* kind of hideous but very useful... */
double last_measured_time = UNMEASURED;
double last_corrected_time = UNMEASURED;

/* this assumes DUMMY_COUNT == 4... */
double dummies[DUMMY_COUNT] = { UNMEASURED,
				UNMEASURED,
				UNMEASURED,
				UNMEASURED };

double *col_over_nodes_dummies = NULL;
int    comm_world_size;

data_list_t *inside_list = NULL;
int         append_to_inside_list = TRUE;

data_list_t *p2p_overlap_list = NULL;
int         append_to_p2p_overlap_list = TRUE;

/* globals for ACKer tests... */
double *cur_gaps = NULL;
double *p2p_latencies = NULL;

extern params_t params;

#ifdef _HAVE_OMP_

/* need lists for OMP aux test results... */
data_list_t **omp_aux_lists = NULL;
int         *append_to_omp_aux_lists = NULL;

extern int sphinx_omp_max_num_threads;

#endif /* _HAVE_OMP_ */


aux_test_t simple_dummy_aux = { need_simple_dummy_test,
				simple_dummy_test,
				use_simple_dummy_test};

aux_test_t mw_dummy_aux = { need_mw_dummy_test,
			    mw_dummy_test,
			    use_mw_dummy_test};

aux_test_t p2p_dummy_aux = { need_p2p_dummy_test,
			     p2p_dummy_test,
			     use_p2p_dummy_test};

aux_test_t p2p_overlap_aux = { need_p2p_overlap_test,
			       p2p_overlap_test,
			       use_p2p_overlap_test};

aux_test_t p2p_second_overlap_aux = { need_p2p_second_overlap_test,
			              p2p_second_overlap_test,
			              use_p2p_second_overlap_test};

aux_test_t col_dummy_aux = { need_col_dummy_test,
			     col_dummy_test,
			     use_col_dummy_test};

aux_test_t col_over_nodes_dummy_aux = { need_col_over_nodes_dummy_test,
					col_over_nodes_dummy_test,
					use_col_over_nodes_dummy_test};

aux_test_t simple_inside_dummy_aux = { need_simple_inside_dummy_test,
				       simple_inside_dummy_test,
				       use_simple_inside_dummy_test};

aux_test_t ACKer_latencies_aux = { need_ACKer_latencies,
			           do_ACKer_latencies,
			           use_ACKer_latencies};

aux_test_t p2p_ACK_latency_aux = { need_p2p_ACK_latency,
			           do_p2p_ACK_latency,
			           use_p2p_ACK_latency};

aux_test_t gaps_aux = { need_gaps,
			do_gaps,
			use_gaps};


#ifdef _HAVE_OMP_

aux_test_t omp_parallel_aux = { need_omp_parallel_ref_test,
				omp_parallel_ref_test,
				use_omp_parallel_ref_test};

aux_test_t omp_parallel_for_aux = { need_omp_parallel_for_ref_test,
				    omp_parallel_for_ref_test,
				    use_omp_parallel_for_ref_test};

aux_test_t omp_ordered_aux = { need_omp_ordered_ref_test,
			       omp_ordered_ref_test,
			       use_omp_ordered_ref_test};

aux_test_t omp_single_aux = { need_omp_single_ref_test,
			      omp_single_ref_test,
			      use_omp_single_ref_test};

aux_test_t omp_reduction_aux = { need_omp_reduction_ref_test,
				 omp_reduction_ref_test,
				 use_omp_reduction_ref_test};

aux_test_t omp_atomic_aux = { need_omp_atomic_ref_test,
			      omp_atomic_ref_test,
			      use_omp_atomic_ref_test};

aux_test_t omp_overlap_aux = { need_omp_overlap_ref_test,
			       omp_overlap_ref_test,
			       use_omp_overlap_ref_test};

#endif /* _HAVE_OMP_ */


void
generic_destroy (void *the_ms)
{
  measurement_t *ms = (measurement_t *) the_ms;

  if (ms->aux_tests != NULL)
    free (ms->aux_tests);

  return;
}



int
initialize_basic_aux (measurement_t *ms)
{
  int test_count;

  /* use dummy correction as last aux_test if correcting for overhead... */
  if (ms->correct_ms)
    test_count = ms->num_aux_tests = ms->num_aux_tests + 1;
  else
    test_count = ms->num_aux_tests;

  /* don't malloc if no aux_tests... */
  if (test_count > 0)
    if ((ms->aux_tests = 
	 (aux_test_t *) malloc (sizeof(aux_test_t) * test_count)) == NULL) {
      ERROR (NO_MEM,"No space for aux_tests");
      output_error(TRUE);
    }
  
  return test_count - 1;
}

/* this routine is called by measurements that use */
/* simple_dummy_aux as their overhead correction... */
void
initialize_simple_aux (measurement_t *ms)
{
  int index_to_use = initialize_basic_aux (ms);

  /* use simple_dummy_aux as last aux_test ifcorrecting for overhead... */
  if (ms->correct_ms)
    ms->aux_tests[index_to_use] = simple_dummy_aux;
  
  return;
}

/* this routine is called by measurements that use */
/* mw_dummy_aux as their overhead correction... */
void
initialize_mw_aux (measurement_t *ms)
{
  int index_to_use = initialize_basic_aux (ms);

  /* use mw_dummy_aux as last aux_test if correcting for overhead... */
  if (ms->correct_ms)
    ms->aux_tests[index_to_use] = mw_dummy_aux;
  
  return;
}

/* this routine is called by measurements that use */
/* p2p_dummy_aux as their overhead correction... */
void
initialize_p2p_aux (measurement_t *ms)
{
  int index_to_use = initialize_basic_aux (ms);

  /* use p2p_dummy_aux as last aux_test if correcting for overhead... */
  if (ms->correct_ms)
    ms->aux_tests[index_to_use] = p2p_dummy_aux;
  
  return;
}

/* this routine is called by measurements that use */
/* p2p_overlap_aux as one of their overhead corrections... */
void
initialize_p2p_overlap_aux (measurement_t *ms)
{
  int index_to_use = ms->num_aux_tests;

  if (ms->correct_ms)
    ms->num_aux_tests++;

  initialize_p2p_aux (ms);

  /* use p2p_overlap_aux as next to last aux_test... */
  if (ms->correct_ms) {
    ms->aux_tests[index_to_use] = p2p_overlap_aux;

    if (p2p_overlap_list == NULL) {
      p2p_overlap_list = init_list(NULL);
       
      if (p2p_overlap_list == NULL) {
	ERROR(NO_MEM,"no memory for p2p_overlaps");
	output_error(TRUE);
      }
    }
  }
  
  return;
}

/* this routine is called by measurements that use an ACK that is */
/* not overlapped with other parts of the measurment and */
/* p2p_overlap_aux is one of their overhead corrections... */
/* not that p2p_latencies_aux corrects for basic call overhead... */ 
void
initialize_p2p_overlap_and_ack_aux (measurement_t *ms)
{
  int index_to_use = ms->num_aux_tests;

  if (ms->correct_ms)
    ms->num_aux_tests = ms->num_aux_tests + 2;

  initialize_p2p_aux (ms);

  /* use p2p_overlap_aux as second to last aux_test... */
  /* use p2p_latencies as last aux_test... */
  if (ms->correct_ms) {
    ms->aux_tests[index_to_use] = p2p_overlap_aux;

    if (p2p_overlap_list == NULL) {
      p2p_overlap_list = init_list(NULL);
       
      if (p2p_overlap_list == NULL) {
	ERROR(NO_MEM,"no memory for p2p_overlaps");
	output_error(TRUE);
      }
    }

    ms->aux_tests[index_to_use + 1] = p2p_ACK_latency_aux;
  }
  
  return;
}

/* this routine is called by measurements that use */
/* p2p_overlap_aux twice as overhead corrections... */
void
initialize_p2p_both_overlaps_aux (measurement_t *ms)
{
  int index_to_use = ms->num_aux_tests;

  if (ms->correct_ms)
    ms->num_aux_tests++;

  initialize_p2p_overlap_aux (ms);

  /* use p2p_second_overlap_aux as an aux_test... */
  if (ms->correct_ms)
    ms->aux_tests[index_to_use] = p2p_second_overlap_aux;
  
  return;
}

/* this routine is called by measurements that use */
/* col_dummy_aux as their overhead correction... */
void
initialize_col_aux (measurement_t *ms)
{
  int index_to_use = initialize_basic_aux (ms);

  /* use mw_dummy_aux as last aux_test if correcting for overhead... */
  if (ms->correct_ms)
     ms->aux_tests[index_to_use] = col_dummy_aux;
  
  return;
}

/* this routine is called by measurements that use */
/* col_dummy_aux as their overhead correction... */
void
initialize_col_over_nodes_aux (measurement_t *ms)
{
  int index_to_use = initialize_basic_aux (ms);

  /* use mw_dummy_aux as last aux_test if correcting for overhead... */
  if (ms->correct_ms) {
    ms->aux_tests[index_to_use] = col_over_nodes_dummy_aux;

    if (col_over_nodes_dummies == NULL) {
      int i;

      MPI_Comm_size (MPI_COMM_WORLD, &comm_world_size);

      if ((col_over_nodes_dummies = 
	   (double *) malloc (comm_world_size * sizeof (double))) == NULL) {
	ERROR(NO_MEM,"no memory for col_over_nodes_dummies");
	output_error(TRUE);
      }

      for (i = 0; i < comm_world_size; i++)
	col_over_nodes_dummies[i] = UNMEASURED;
    }
  }
  
  return;
}

/* this routine is called by measurements that use */
/* simple_inside_dummy_aux as their overhead correction... */
void
initialize_simple_inside_aux (measurement_t *ms)
{
  int index_to_use = initialize_basic_aux (ms);

  /* simple_inside_dummy_aux is overhead correction... */
  if (ms->correct_ms) {
    ms->aux_tests[index_to_use] = simple_inside_dummy_aux;
    
    if (inside_list == NULL) {
      inside_list = init_list(NULL);
       
      if (inside_list == NULL) {
	ERROR(NO_MEM,"no memory for simple_inside_dummies");
	output_error(TRUE);
      }
    }
  }
  
  return;
}

void
initialize_ACKer_aux (measurement_t *ms)
{
  int test_count;

  /* gaps_aux is last aux_test before overhead correction */
  /* ACKer_latencies_aux is overhead correction... */
  if (ms->correct_ms) {
    test_count = ms->num_aux_tests = ms->num_aux_tests + 2;

    if (test_count < 2) {
      ERROR (INTERN,"Unexpected test count");
      output_error(TRUE);
    }
  }
  else {
    test_count = ms->num_aux_tests = ms->num_aux_tests + 1;

    if (test_count < 1) {
      ERROR (INTERN,"Unexpected test count");
      output_error(TRUE);
    }
  }

  if ((ms->aux_tests = 
       (aux_test_t *) malloc (sizeof(aux_test_t) * test_count)) == NULL) {   
    ERROR (NO_MEM,"No space for aux_tests");
    output_error(TRUE);
  }

  if (ms->correct_ms) {
    /* the order is important here since we want to check reliability */
    /* using the gaps before correcting for acknowledgement latency... */
    ms->aux_tests[test_count - 2] = gaps_aux;
    ms->aux_tests[test_count - 1] = ACKer_latencies_aux;
  }
  else {
    ms->aux_tests[test_count - 1] = gaps_aux;
  }

  return;
}


#ifdef _HAVE_OMP_


int
initialize_omp_basic_aux (measurement_t *ms)
{
  /* use minus one to do correct for call overhead before */
  /* omp overhead calculations... */
  int ret_val = initialize_basic_aux (ms);

  /* use simple_dummy_aux as last aux_test ifcorrecting for overhead... */
  if (ms->correct_ms)
    switch (ms->pattern) {
    case P2P:
      ms->aux_tests[ret_val - 1] = p2p_dummy_aux;
      break;
    case MASTER_WORKER:
      ms->aux_tests[ret_val - 1] = mw_dummy_aux;
      break;
    case COLLECTIVE:
      ms->aux_tests[ret_val - 1] = col_dummy_aux;
      break;
    case SIMPLE:
    case MULTITIMING:
      ms->aux_tests[ret_val - 1] = simple_dummy_aux;
      break;
    case THREAD_CHAIN:
      ms->aux_tests[ret_val - 1] = simple_inside_dummy_aux;
      if (inside_list == NULL) {
	inside_list = init_list(NULL);
       
	if (inside_list == NULL) {
	  ERROR(NO_MEM,"no memory for simple_inside_dummies");
	  output_error(TRUE);
	}
      }
      break;
    default:
      ERROR(USER,"invalid pattern occured in initialize_omp_basic_aux");
      output_error(FALSE);
      return GENERIC_ERROR;
    }
  
  return ret_val;
}

/* this routine is called by the initialize_omp_*_aux functions... */
void
setup_omp_aux_lists (omp_aux_t which_omp_aux)
{
  if (which_omp_aux >= OMP_AUX_COUNT) {
    ERROR (INTERN,"Invalid omp_aux_t in setup_omp_aux_lists");
    output_error(TRUE);
  }

  if (omp_aux_lists == NULL) {
    int i;

    if ((omp_aux_lists = 
	 (data_list_t **) malloc (OMP_AUX_COUNT * sizeof (data_list_t *))) 
	== NULL) {
      ERROR(NO_MEM,"no memory for omp_aux_lists");
      output_error(TRUE);
    }

    if ((append_to_omp_aux_lists = 
	 (int *) malloc (OMP_AUX_COUNT * sizeof (int))) == NULL) {
      ERROR(NO_MEM,"no memory for append_to_omp_aux_lists");
      output_error(TRUE);
    }

    for (i = 0; i < OMP_AUX_COUNT; i++) {
      omp_aux_lists[i] = NULL;
      append_to_omp_aux_lists[i] = TRUE;
    }
  }

  if (omp_aux_lists[which_omp_aux] == NULL) {
    omp_aux_lists[which_omp_aux] = init_list(omp_aux_lists[which_omp_aux]);
       
    if (omp_aux_lists[which_omp_aux] == NULL) {
      ERROR(NO_MEM,"no memory for member of omp_aux_lists");
      output_error(TRUE);
    }
  }
  
  return;
}

/* this routine is called by the initialize_omp_*_aux functions... */
int
initialize_omp_aux (measurement_t *ms, omp_aux_t which_omp_aux)
{
  setup_omp_aux_lists (which_omp_aux);

  ms->num_aux_tests++;

  return initialize_omp_basic_aux (ms);
}


/* Do omp overhead tests/calculations regardless of ms->correct_ms... */
void 
initialize_omp_parallel_aux (measurement_t *ms)
{
  int index_to_use = initialize_omp_aux (ms, OMP_PARALLEL_AUX);
  
  /* omp_parallel_aux is omp overhead auxilliary... */
  ms->aux_tests[index_to_use] = omp_parallel_aux;
    
  return;
}

void 
initialize_omp_parallel_for_aux (measurement_t *ms)
{
  int index_to_use = initialize_omp_aux (ms, OMP_PARALLEL_FOR_AUX);
  
  /* omp_parallel_for_aux is omp overhead auxilliary... */
  ms->aux_tests[index_to_use] = omp_parallel_for_aux;
    
  return;
}

void 
initialize_omp_ordered_aux (measurement_t *ms)
{
  int index_to_use = initialize_omp_aux (ms, OMP_ORDERED_AUX);
  
  /* omp_ordered_aux is omp overhead auxilliary... */
  ms->aux_tests[index_to_use] = omp_ordered_aux;
    
  return;
}

void 
initialize_omp_single_aux (measurement_t *ms)
{
  int index_to_use = initialize_omp_aux (ms, OMP_SINGLE_AUX);
  
  /* omp_single_aux is omp overhead auxilliary... */
  ms->aux_tests[index_to_use] = omp_single_aux;
    
  return;
}

void 
initialize_omp_reduction_aux (measurement_t *ms)
{
  int index_to_use = initialize_omp_aux (ms, OMP_REDUCTION_AUX);
  
  /* omp_parallel_for_aux is omp overhead auxilliary... */
  ms->aux_tests[index_to_use] = omp_reduction_aux;
    
  return;
}

void 
initialize_omp_atomic_aux (measurement_t *ms)
{
  int index_to_use = initialize_omp_aux (ms, OMP_ATOMIC_AUX);
  
  /* omp_parallel_for_aux is omp overhead auxilliary... */
  ms->aux_tests[index_to_use] = omp_atomic_aux;
    
  return;
}

/* this routine is called by measurements that use */
/* omp_overlap_aux as one of their overhead corrections... */
void
initialize_p2p_omp_overlap_aux (measurement_t *ms)
{
  int index_to_use = ms->num_aux_tests;

  if (ms->correct_ms)
    ms->num_aux_tests++;

  initialize_p2p_aux (ms);

  /* use omp_overlap_aux as next to last aux_test... */
  if (ms->correct_ms) {
    ms->aux_tests[index_to_use] = omp_overlap_aux;

    setup_omp_aux_lists (OMP_OVERLAP_AUX);
  }
  
  return;
}

/* this routine is called by measurements that use an ACK that is */
/* not overlapped with other parts of the measurment and */
/* p2p_overlap_aux is one of their overhead corrections... */
/* not that p2p_latencies_aux corrects for basic call overhead... */ 
void
initialize_p2p_omp_overlap_and_ack_aux (measurement_t *ms)
{
  int index_to_use = ms->num_aux_tests;

  if (ms->correct_ms)
    ms->num_aux_tests = ms->num_aux_tests + 2;

  initialize_p2p_aux (ms);

  /* use omp_overlap_aux as second to last aux_test... */
  /* use p2p_latencies as last aux_test... */
  if (ms->correct_ms) {
    ms->aux_tests[index_to_use] = omp_overlap_aux;

    setup_omp_aux_lists (OMP_OVERLAP_AUX);

    ms->aux_tests[index_to_use + 1] = p2p_ACK_latency_aux;
  }
  
  return;
}

/* this routine is called by measurements that use */
/* p2p_overlap_aux twice as overhead corrections... */
void
initialize_p2p_both_omp_overlaps_aux (measurement_t *ms)
{
  int index_to_use = ms->num_aux_tests;

  if (ms->correct_ms)
    ms->num_aux_tests++;

  initialize_p2p_omp_overlap_aux (ms);

  /* use omp_overlap_aux twice as an aux_test... */
  /* (eventually use omp_second_overlap_aux for one...) */
  if (ms->correct_ms)
    ms->aux_tests[index_to_use] = omp_overlap_aux;
  
  return;
}

#endif /* _HAVE_OMP_ */


#define need_dummy(which_dummy) (dummies[which_dummy] == UNMEASURED)

int
need_simple_dummy_test (void *ms, int the_arg, int n)
{
  return (need_dummy(SIMPLE_DUMMY));
}

int
need_mw_dummy_test (void *ms, int the_arg, int n)
{
  return (need_dummy(MW_DUMMY));
}

int
need_p2p_dummy_test (void *ms, int the_arg, int n)
{
  return (need_dummy(P2P_DUMMY));
}

int
need_col_dummy_test (void *ms, int the_arg, int n)
{
  return (need_dummy(COL_DUMMY));
}

int
need_col_over_nodes_dummy_test (void *ms, int the_arg, int n)
{
  measurement_t *local_ms = (measurement_t *) ms;
  int i;

  if (n + 1 != local_ms->dimensions_count)
    return FALSE;

  for (i = 0; i < local_ms->dimensions_count; i++)
    if (local_ms->dimensions[i].variation == NODES)
      /* index is minus one since comm_size == 0 is irrelevant... */
      return (col_over_nodes_dummies[the_arg - 1] == UNMEASURED);

  MPI_Comm_size (local_ms->communicator, &i);
  
  /* index is minus one since comm_size == 0 is irrelevant... */
  return (col_over_nodes_dummies[i - 1] == UNMEASURED);
}

int
array_on_aux_list (int *indices, int num_dims, 
		   data_list_t *aux_list, int *append_flag)
{
  int           i, j, error;
  data_t        ldata;

  read_ele (aux_list, START, 0, &ldata, &error);

  /* assume put on in lexicographically increasing order... */
  for (i = 0; i < aux_list->number; i++) {
    for (j = 0; j < num_dims; j++) {
      if (ldata.arg[j] < indices[j])
	/* not far enough */
	break;

      if (ldata.arg[j] > indices[j]) {
	/* it can't be there since we've passed it's spot... */
	*append_flag = FALSE;
	return FALSE;
      }

      /* ldata.arg[j] == indices[j] */
      if (j == num_dims - 1)
	/* it's already there so we don't need to measure it... */
	return TRUE;
    }

    read_ele (aux_list, LAST, 1, &ldata, &error);
  }

  /* we're out of elements without finding it so we need to append it... */
  *append_flag = TRUE;
  return FALSE;
}

int
on_aux_list (int index, data_list_t *aux_list, int *append_flag)
{
  return array_on_aux_list (&index, 1, aux_list, append_flag);
}

int
need_simple_inside_dummy_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  int           index;

  if (n + 1 != lms->dimensions_count)
    return FALSE;

  if (inside_list->number == 0) {
    append_to_inside_list = TRUE;
    return TRUE;
  }

  switch (lms->pattern) {
  case SIMPLE:
  case THREAD_CHAIN:
    index = lms->iters_per_time * 
      (lms->iters_over_nodes ? lms->data.simple_data.iter_factor : 1);
    break;
  case MULTITIMING:
    index = lms->iters_per_time * 
      (lms->iters_over_nodes ? lms->data.multitiming_data.iter_factor : 1);
    break;
  default:
    ERROR (INTERN, "Invalid pattern in need_simple_inside_dummy_test");
    output_error (FALSE);
    return FALSE;
  }

  return (!on_aux_list (index, inside_list, &append_to_inside_list));
}

int
need_a_p2p_overlap_test (measurement_t *ms, int real_arg, int n)
{
  if (n + 1 != ms->dimensions_count)
    return FALSE;

  if (p2p_overlap_list->number == 0) {
    append_to_p2p_overlap_list = TRUE;
    return TRUE;
  }

  return 
    (!on_aux_list (real_arg, p2p_overlap_list, &append_to_p2p_overlap_list));
}

int
need_p2p_overlap_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;

  return need_a_p2p_overlap_test (lms, lms->overlap_iters, n);
}

int
need_p2p_second_overlap_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;

  return need_a_p2p_overlap_test (lms, lms->second_overlap_iters, n);
}

int
need_ACKer_latencies (void *ms, int the_arg, int n)
{
  measurement_t *local_ms = (measurement_t *) ms;
  int           world_size;

  if (n + 1 != local_ms->dimensions_count)
    return FALSE;

  if (p2p_latencies == NULL)
    return TRUE;

  MPI_Comm_size (MPI_COMM_WORLD, &world_size);

  return (p2p_latencies[local_ms->root * world_size] == UNMEASURED);
}

int
need_p2p_ACK_latency (void *ms, int the_arg, int n)
{
  measurement_t *local_ms = (measurement_t *) ms;

  if (n + 1 != local_ms->dimensions_count)
    return FALSE;

  if (p2p_latencies == NULL)
    return TRUE;

  /* here's a place where we assume one of the pair is task zero... */
  return (p2p_latencies[0] == UNMEASURED);
}

int
need_gaps (void *ms, int the_arg, int n)
{
  measurement_t *local_ms = (measurement_t *) ms;
  int           dim_count = local_ms->dimensions_count;

  if (local_ms->dimensions[dim_count - 1].variation  == ACKER) {
    /* measure gaps if second to last dimension... */
    return (n + 2 == dim_count);
  }

  /* last variation is not ACKer; is this the last? */
  return (n + 1 == dim_count);
}


#ifdef _HAVE_OMP_



int
need_omp_parallel_ref_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[OMP_PARALLEL_AUX];
  int           indices[2];

  if (n + 1 != lms->dimensions_count)
    return FALSE;

  if (tlist->number == 0) {
    append_to_omp_aux_lists[OMP_PARALLEL_AUX] = TRUE;
    return TRUE;
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);

  return (!array_on_aux_list (indices, 2, tlist, 
			      &append_to_omp_aux_lists[OMP_PARALLEL_AUX]));
}

int
need_omp_parallel_for_ref_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[OMP_PARALLEL_FOR_AUX];
  int           indices[3];

  if (n + 1 != lms->dimensions_count)
    return FALSE;

  if (tlist->number == 0) {
    append_to_omp_aux_lists[OMP_PARALLEL_FOR_AUX] = TRUE;
    return TRUE;
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);
  indices[2] = get_sched_cap (lms);

  return (!array_on_aux_list (indices, 3, tlist, 
			      &append_to_omp_aux_lists[OMP_PARALLEL_FOR_AUX]));
}

int
need_omp_ordered_ref_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[OMP_ORDERED_AUX];
  int           indices[2];

  if (n + 1 != lms->dimensions_count)
    return FALSE;

  if (tlist->number == 0) {
    append_to_omp_aux_lists[OMP_ORDERED_AUX] = TRUE;
    return TRUE;
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);

  return (!array_on_aux_list (indices, 2, tlist, 
			      &append_to_omp_aux_lists[OMP_ORDERED_AUX]));
}

int
need_omp_single_ref_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[OMP_SINGLE_AUX];
  int           indices[2];

  if (n + 1 != lms->dimensions_count)
    return FALSE;

  if (tlist->number == 0) {
    append_to_omp_aux_lists[OMP_SINGLE_AUX] = TRUE;
    return TRUE;
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);

  return (!array_on_aux_list (indices, 2, tlist, 
			      &append_to_omp_aux_lists[OMP_SINGLE_AUX]));
}

int
need_omp_reduction_ref_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[OMP_REDUCTION_AUX];
  int           indices[3];

  if (n + 1 != lms->dimensions_count)
    return FALSE;

  if (tlist->number == 0) {
    append_to_omp_aux_lists[OMP_REDUCTION_AUX] = TRUE;
    return TRUE;
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);
  indices[2] = get_sched_cap (lms);

  return (!array_on_aux_list (indices, 3, tlist, 
			      &append_to_omp_aux_lists[OMP_REDUCTION_AUX]));
}

int
need_omp_atomic_ref_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[OMP_ATOMIC_AUX];
  int           indices[2];

  if (n + 1 != lms->dimensions_count)
    return FALSE;

  if (tlist->number == 0) {
    append_to_omp_aux_lists[OMP_ATOMIC_AUX] = TRUE;
    return TRUE;
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);

  return (!array_on_aux_list (indices, 2, tlist, 
			      &append_to_omp_aux_lists[OMP_ATOMIC_AUX]));
}

int
need_omp_overlap_ref_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[OMP_OVERLAP_AUX];
  int           indices[7];

  if (n + 1 != lms->dimensions_count)
    return FALSE;

  if (tlist->number == 0) {
    append_to_omp_aux_lists[OMP_OVERLAP_AUX] = TRUE;
    return TRUE;
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);
  indices[2] = get_which_overlap (lms);

  switch (indices[2]) {
  case OMP_SEQUENTIAL_OVERLAP:
    /* no other relevant parameters for measure_omp_parallel_ref... */
    indices[3] = sphinx_omp_max_num_threads;
    indices[4] = SCHEDULE_COUNT - 1;
    indices[5] = params.schedule_cap_default;
    indices[6] = params.schedule_chunks_default;
    break;
  case OMP_PARALLEL_OVERLAP:
    indices[3] = get_thread_count (lms);
    /* no other relevant parameters for measure_omp_parallel... */
    indices[4] = SCHEDULE_COUNT - 1;
    indices[5] = params.schedule_cap_default;
    indices[6] = params.schedule_chunks_default;
    break;
  case OMP_PARALLEL_FOR_OVERLAP:
    indices[3] = get_thread_count (lms);
    indices[4] = get_loop_schedule (lms);
    indices[5] = get_sched_cap (lms);
    /* schedule_chunks is not relevant to measure_omp_parallel_for... */
    indices[6] = params.schedule_chunks_default;
    break;
  case OMP_PARALLEL_FOR_CHUNKS_OVERLAP:
    indices[3] = get_thread_count (lms);
    indices[4] = get_loop_schedule (lms);
    indices[5] = get_sched_cap (lms);
    indices[6] = get_schedule_chunks (lms);
    break;
  default:
    ERROR (INTERN, "Invalid overlap type in need_omp_overlap_ref_test");
    output_error (FALSE);
    return FALSE;
  }

  return (!array_on_aux_list (indices, 7, tlist, 
			      &append_to_omp_aux_lists[OMP_OVERLAP_AUX]));
}


#endif /* _HAVE_OMP_ */


extern params_t params;       /* the parameter block */

int
do_dummy (dummy_t which_dummy)
{
  measurement_t dummy_ms;
  int ret_val;

  my_initialize_measurement (&dummy_ms, &params);
  dummy_ms.dimensions_count = 1;
  dummy_ms.dimensions[0].variation = NO_VARIATION;

  switch (which_dummy) {
  case SIMPLE_DUMMY:
    dummy_ms.name = "simple_dummy";
    simple_init_dummy (&dummy_ms);
    break;

  case MW_DUMMY:
    dummy_ms.name = "mw_dummy";
    mw_init_dummy (&dummy_ms);
    break;

  case P2P_DUMMY:
    dummy_ms.name = "p2p_dummy";
    p2p_init_dummy (&dummy_ms);
    break;

  case COL_DUMMY:
    dummy_ms.name = "col_dummy";
    col_init_dummy (&dummy_ms);
    break;

  default:
    ERROR(INTERN,"unknown dummy occurred in do_dummy");
    output_error(FALSE);
    return GENERIC_ERROR;
  }
    
  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  if (_sphinx_myid == 0)
    dummies[which_dummy] = last_measured_time;
  else
    dummies[which_dummy] = 0.0;
    
  return SUCCESS;
}

int
simple_dummy_test (void *ms, int the_arg, int n)
{
  return do_dummy (SIMPLE_DUMMY);
}

int
mw_dummy_test (void *ms, int the_arg, int n)
{
  return do_dummy (MW_DUMMY);
}

int
p2p_dummy_test (void *ms, int the_arg, int n)
{
  return do_dummy (P2P_DUMMY);
}

int
col_dummy_test (void *ms, int the_arg, int n)
{
  return do_dummy (COL_DUMMY);
}

int
col_over_nodes_dummy_test (void *ms, int the_arg, int n)
{
  measurement_t dummy_ms, *local_ms = (measurement_t *) ms;
  int           ret_val, index;

  /* index is minus one since comm_size == 0 is irrelevant... */
  if (local_ms->dimensions[n].variation == NODES)
    index = the_arg - 1;
  else {
    MPI_Comm_size (local_ms->communicator, &index);
    index--;
  }

  my_initialize_measurement (&dummy_ms, &params);
  dummy_ms.dimensions_count = 1;
  dummy_ms.dimensions[0].variation = NO_VARIATION;
  dummy_ms.name = "col_over_nodes_dummy";
  col_init_over_nodes_dummy (&dummy_ms);
    
  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  if (_sphinx_myid == 0)
    col_over_nodes_dummies[index] = last_measured_time;
  else
    col_over_nodes_dummies[index] = 0.0;
    
  return SUCCESS;
}

int
simple_inside_dummy_test (void *ms, int the_arg, int n)
{
  measurement_t dummy_ms, *lms = (measurement_t *) ms;
  int           ret_val, index, error;
  data_t        ldata;

  index = get_max_iters_value (lms);

  my_initialize_measurement (&dummy_ms, &params);
  dummy_ms.dimensions_count = 1;
  dummy_ms.dimensions[0].variation = NO_VARIATION;
  dummy_ms.iters_per_time = lms->iters_per_time;
  dummy_ms.iters_over_nodes = lms->iters_over_nodes;

  switch (lms->pattern) {
  case SIMPLE:
  case THREAD_CHAIN:
    dummy_ms.data.simple_data.iter_factor = 
      lms->data.simple_data.iter_factor;
    break;
  case MULTITIMING:
    dummy_ms.data.simple_data.iter_factor = 
      lms->data.multitiming_data.iter_factor;
    break;
  default:
    ERROR (INTERN, "Invalid pattern in simple_inside_dummy_test");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  dummy_ms.name = "simple_inside_dummy";
  simple_init_inside_dummy (&dummy_ms);
    
  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  ldata.num_dims = 1;
  ldata.arg[0] = index;

  /* really unsaved but why quibble? */
  ldata.standard_deviation = UNMEASURED; 
  ldata.count = 0;
  ldata.status = NULL;
  ldata.reference = UNMEASURED;

  if (_sphinx_myid == 0)
    ldata.result = last_measured_time;
  else
    ldata.result = 0.0; 

  if (append_to_inside_list)
    append (inside_list, &ldata, &error);
  else { /* add old_data behind next new measurement */
    add(inside_list, LAST, -1, &ldata, &error);

    /* put "last" item back to one that was copied into data... */
    inside_list->list_last = inside_list->list_last->next;
  }
    
  return SUCCESS;
}

int
a_p2p_overlap_test (measurement_t *ms, int real_arg, int n)
{
  measurement_t dummy_ms;
  int           ret_val, error;
  data_t        ldata;

  /* need to "find" measurement so we insert in order... */
  /* as long as we're doing that check for it one last time... */
  if (!need_a_p2p_overlap_test(ms, real_arg, n))
    return SUCCESS;

  my_initialize_measurement (&dummy_ms, &params);
  dummy_ms.dimensions_count = 1;
  dummy_ms.dimensions[0].variation = NO_VARIATION;
  dummy_ms.name = "p2p_overlap";
  p2p_init_overlap (&dummy_ms);

  dummy_ms.overlap_iters = real_arg;

  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  ldata.num_dims = 1;
  ldata.arg[0] = real_arg;

  /* really unsaved but why quibble? */
  ldata.standard_deviation = UNMEASURED; 
  ldata.count = 0;
  ldata.status = NULL;
  ldata.reference = UNMEASURED;

  if (_sphinx_myid == 0)
    /* use last_corrected_time to fix for function call overhead... */
    ldata.result = last_corrected_time;
  else
    ldata.result = 0.0; 

  if (append_to_p2p_overlap_list)
    append (p2p_overlap_list, &ldata, &error);
  else { /* add old_data behind next new measurement */
    add(p2p_overlap_list, LAST, -1, &ldata, &error);

    /* put "last" item back to one that was copied into data... */
    p2p_overlap_list->list_last = p2p_overlap_list->list_last->next;
  }
    
  return SUCCESS;
}

int
p2p_overlap_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;

  return a_p2p_overlap_test (lms, lms->overlap_iters, n);
}

int
p2p_second_overlap_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;

  return a_p2p_overlap_test (lms, lms->second_overlap_iters, n);
}

int
do_ACKer_latencies (void *ms, int the_arg, int n)
{
  measurement_t *local_ms = (measurement_t *) ms;

  /* expectation is that we know we need to measure them... */
  return measure_p2p_latencies(local_ms->root);
}

int
do_p2p_ACK_latency (void *ms, int the_arg, int n)
{
  /* here's a place where we assume one of the pair is task zero... */
  /* expectation is that we know we need to measure them... */
  return measure_p2p_latencies(0);
}

int
do_gaps (void *ms, int the_arg, int n)
{
  measurement_t *local_ms = (measurement_t *) ms;

  /* actually measure gaps only if in the root's communicator */
  if (local_ms->should_call_pattern)
    return measure_gaps (local_ms);
  else
    return SUCCESS;
}


#ifdef _HAVE_OMP_


int
add_last_omp_ref_result (omp_aux_t which_omp_aux, data_t *ldata)
{
  data_list_t   *tlist = omp_aux_lists[which_omp_aux];
  int           error;

  /* really unsaved but why quibble? */
  ldata->standard_deviation = UNMEASURED; 
  ldata->count = 0;
  ldata->status = NULL;
  ldata->reference = UNMEASURED;

  if (_sphinx_myid == 0)
    ldata->result = last_measured_time;
  else
    ldata->result = 0.0; 

  if (append_to_omp_aux_lists[which_omp_aux])
    append (tlist, ldata, &error);
  else { /* add old_data behind next new measurement */
    add(tlist, LAST, -1, ldata, &error);

    /* put "last" item back to one that was copied into data... */
    tlist->list_last = tlist->list_last->next;
  }
    
  return SUCCESS;
}

int
set_common_omp_dummy_params (measurement_t *lms, 
			     measurement_t *dummy_ms, data_t *ldata)
{
  my_initialize_measurement (dummy_ms, &params);
  dummy_ms->dimensions[0].max_steps = dummy_ms->dimensions[1].max_steps = 1;
  dummy_ms->dimensions[0].variation = WORK_FUNCTION;
  ldata->arg[0] = dummy_ms->dimensions[0].start = 
    dummy_ms->dimensions[0].end = get_which_work (lms);
  dummy_ms->dimensions[1].variation = WORK_AMOUNT;
  ldata->arg[1] = dummy_ms->dimensions[1].start = 
    dummy_ms->dimensions[1].end = get_work_param (lms);
  dummy_ms->iters_per_time = lms->iters_per_time;
  dummy_ms->iters_over_nodes = lms->iters_over_nodes;
  dummy_ms->correct_ms = lms->correct_ms;

  switch (lms->pattern) {
  /* uses fall through... */
  case P2P:
  case MASTER_WORKER:
  case COLLECTIVE:
    dummy_ms->data.simple_data.iter_factor = 1;
    break;
  case SIMPLE:
  case THREAD_CHAIN:
    dummy_ms->data.simple_data.iter_factor = 
      lms->data.simple_data.iter_factor;
    break;
  case MULTITIMING:
    dummy_ms->data.simple_data.iter_factor = 
      lms->data.multitiming_data.iter_factor;
    break;
  default:
    ERROR (INTERN, "Invalid pattern in set_common_omp_dummy_params");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  return SUCCESS;
}

int
omp_parallel_ref_test (void *ms, int the_arg, int n)
{
  measurement_t dummy_ms, *lms = (measurement_t *) ms;
  int           ret_val;
  data_t        ldata;

  set_common_omp_dummy_params (lms, &dummy_ms, &ldata);
  ldata.num_dims = dummy_ms.dimensions_count = 2;

  dummy_ms.name = "omp_parallel_ref";
  simple_init_omp_parallel_ref (&dummy_ms);

  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  return add_last_omp_ref_result (OMP_PARALLEL_AUX, &ldata);
}

int
omp_parallel_for_ref_test (void *ms, int the_arg, int n)
{
  measurement_t dummy_ms, *lms = (measurement_t *) ms;
  int           ret_val;
  data_t        ldata;

  set_common_omp_dummy_params (lms, &dummy_ms, &ldata);
  ldata.num_dims = dummy_ms.dimensions_count = 3;

  /* extra dimension... */
  dummy_ms.dimensions[2].variation = SCHED_CAP;
  ldata.arg[2] = dummy_ms.dimensions[2].start = 
    dummy_ms.dimensions[2].end = get_sched_cap (lms);

  dummy_ms.name = "omp_parallel_for_ref";
  simple_init_omp_parallel_for_ref (&dummy_ms);
    
  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  return add_last_omp_ref_result (OMP_PARALLEL_FOR_AUX, &ldata);
}

int
omp_ordered_ref_test (void *ms, int the_arg, int n)
{
  measurement_t dummy_ms, *lms = (measurement_t *) ms;
  int           ret_val;
  data_t        ldata;

  set_common_omp_dummy_params (lms, &dummy_ms, &ldata);
  ldata.num_dims = dummy_ms.dimensions_count = 2;

  dummy_ms.name = "omp_ordered_ref";
  thread_chain_init_omp_ordered_ref (&dummy_ms);

  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  return add_last_omp_ref_result (OMP_ORDERED_AUX, &ldata);
}

int
omp_single_ref_test (void *ms, int the_arg, int n)
{
  measurement_t dummy_ms, *lms = (measurement_t *) ms;
  int           ret_val;
  data_t        ldata;

  set_common_omp_dummy_params (lms, &dummy_ms, &ldata);
  ldata.num_dims = dummy_ms.dimensions_count = 2;

  dummy_ms.name = "omp_single_ref";
  thread_chain_init_omp_single_ref (&dummy_ms);

  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  return add_last_omp_ref_result (OMP_SINGLE_AUX, &ldata);
}

int
omp_reduction_ref_test (void *ms, int the_arg, int n)
{
  measurement_t dummy_ms, *lms = (measurement_t *) ms;
  int           ret_val;
  data_t        ldata;

  set_common_omp_dummy_params (lms, &dummy_ms, &ldata);
  ldata.num_dims = dummy_ms.dimensions_count = 3;

  /* extra dimension... */
  dummy_ms.dimensions[2].variation = SCHED_CAP;
  ldata.arg[2] = dummy_ms.dimensions[2].start = 
    dummy_ms.dimensions[2].end = get_sched_cap (lms);

  dummy_ms.name = "omp_reduction_ref";
  simple_init_omp_reduction_ref (&dummy_ms);
    
  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  return add_last_omp_ref_result (OMP_REDUCTION_AUX, &ldata);
}

int
omp_atomic_ref_test (void *ms, int the_arg, int n)
{
  measurement_t dummy_ms, *lms = (measurement_t *) ms;
  int           ret_val;
  data_t        ldata;

  set_common_omp_dummy_params (lms, &dummy_ms, &ldata);
  ldata.num_dims = dummy_ms.dimensions_count = 2;

  dummy_ms.name = "omp_atomic_ref";
  simple_init_omp_atomic_ref (&dummy_ms);

  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  return add_last_omp_ref_result (OMP_ATOMIC_AUX, &ldata);
}

int
omp_overlap_ref_test (void *ms, int the_arg, int n)
{
  measurement_t dummy_ms, *lms = (measurement_t *) ms;
  int           ret_val;
  data_t        ldata;

  set_common_omp_dummy_params (lms, &dummy_ms, &ldata);
  ldata.num_dims = dummy_ms.dimensions_count = 7;

  /* extra dimensions... */
  dummy_ms.dimensions[2].variation = OVERLAP_FUNCTION;
  ldata.arg[2] = dummy_ms.dimensions[2].start = 
    dummy_ms.dimensions[2].end = get_which_overlap (lms);
  dummy_ms.dimensions[3].variation = THREADS;
  dummy_ms.dimensions[4].variation = SCHEDULE;
  dummy_ms.dimensions[5].variation = SCHED_CAP;
  dummy_ms.dimensions[6].variation = SCHED_CHUNKS;

  dummy_ms.name = "omp_overlap_ref";

  switch (ldata.arg[2]) {
  case OMP_SEQUENTIAL_OVERLAP:
    /* no other relevant parameters for measure_omp_parallel_ref... */
    ldata.arg[3] = dummy_ms.dimensions[3].start = 
      dummy_ms.dimensions[3].end = sphinx_omp_max_num_threads;
    ldata.arg[4] = dummy_ms.dimensions[4].start = 
      dummy_ms.dimensions[4].end = SCHEDULE_COUNT - 1;
    ldata.arg[5] = dummy_ms.dimensions[5].start = 
      dummy_ms.dimensions[5].end = params.schedule_cap_default;
    ldata.arg[6] = dummy_ms.dimensions[6].start = 
      dummy_ms.dimensions[6].end = params.schedule_chunks_default;

    simple_init_omp_parallel_ref (&dummy_ms);
    break;

  case OMP_PARALLEL_OVERLAP:
    ldata.arg[3] = dummy_ms.dimensions[3].start = 
      dummy_ms.dimensions[3].end = get_thread_count (lms);
    /* no other relevant parameters for measure_omp_parallel... */
    ldata.arg[4] = dummy_ms.dimensions[4].start = 
      dummy_ms.dimensions[4].end = SCHEDULE_COUNT - 1;
    ldata.arg[5] = dummy_ms.dimensions[5].start = 
      dummy_ms.dimensions[5].end = params.schedule_cap_default;
    ldata.arg[6] = dummy_ms.dimensions[6].start = 
      dummy_ms.dimensions[6].end = params.schedule_chunks_default;

    simple_init_omp_parallel (&dummy_ms);
    break;

  case OMP_PARALLEL_FOR_OVERLAP:
    ldata.arg[3] = dummy_ms.dimensions[3].start = 
      dummy_ms.dimensions[3].end = get_thread_count (lms);
    ldata.arg[4] = dummy_ms.dimensions[4].start = 
      dummy_ms.dimensions[4].end = get_loop_schedule (lms);
    ldata.arg[5] = dummy_ms.dimensions[5].start = 
      dummy_ms.dimensions[5].end  = get_sched_cap (lms);
    /* schedule_chunks is not relevant to measure_omp_parallel_for... */
    ldata.arg[6] = dummy_ms.dimensions[6].start = 
      dummy_ms.dimensions[6].end = params.schedule_chunks_default;

    simple_init_omp_parallel_for (&dummy_ms);
    break;

  case OMP_PARALLEL_FOR_CHUNKS_OVERLAP:
    ldata.arg[3] = dummy_ms.dimensions[3].start = 
      dummy_ms.dimensions[3].end = get_thread_count (lms);
    ldata.arg[4] = dummy_ms.dimensions[4].start = 
      dummy_ms.dimensions[4].end = get_loop_schedule (lms);
    ldata.arg[5] = dummy_ms.dimensions[5].start = 
      dummy_ms.dimensions[5].end  = get_sched_cap (lms);
    ldata.arg[6] = dummy_ms.dimensions[6].start = 
      dummy_ms.dimensions[6].end = get_schedule_chunks (lms);

    simple_init_omp_parallel_for_chunks (&dummy_ms);
    break;

  default:
    ERROR (INTERN, "Invalid overlap type in omp_overlap_ref_test");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  ret_val = measure (&dummy_ms, 0);

  if (ret_val) 
    /* measurement failed, just return error code... */
    return ret_val;

  return add_last_omp_ref_result (OMP_OVERLAP_AUX, &ldata);
}


#endif /* _HAVE_OMP_ */

/* subtract correction from result of ms */
void
correct_result (measurement_t *ms, double correction)
{
  int i;

  switch (ms->pattern) {
  case P2P:
    if ((last_corrected_time = 
	 ms->data.p2p_data.result->result -= correction) < 0.0)
      /* Make it jump out in the output file!!!! */
      mark_status (ms->data.p2p_data.result, "UNRELIABLE");
    break;
  case MASTER_WORKER:
    if ((last_corrected_time = 
	 ms->data.mw_data.result->result -= correction) < 0.0)
      /* Make it jump out in the output file!!!! */
      mark_status (ms->data.mw_data.result, "UNRELIABLE");
    break;
  case COLLECTIVE:
    if ((last_corrected_time = 
	 ms->data.col_data.result->result -= correction) < 0.0)
      /* Make it jump out in the output file!!!! */
      mark_status (ms->data.col_data.result, "UNRELIABLE");
    break;
  case SIMPLE:
    /* need to reduce correction by iter_factor for some tests... */
    if (ms->iters_over_nodes)
      correction /= ms->data.simple_data.iter_factor;

    if ((last_corrected_time = 
	 ms->data.simple_data.result->result -= correction) < 0.0)
      /* Make it jump out in the output file!!!! */
      mark_status (ms->data.simple_data.result, "UNRELIABLE");
    break;
  case THREAD_CHAIN:
    if ((last_corrected_time = 
	 ms->data.simple_data.result->result -= correction) < 0.0)
      /* Make it jump out in the output file!!!! */
      mark_status (ms->data.simple_data.result, "UNRELIABLE");
    break;
  case MULTITIMING:
    /* do the full set... */
    for (i =0; i < ms->data.multitiming_data.num_timings; i++)
      if ((last_corrected_time = 
	   ms->data.multitiming_data.result[i].result -= correction) < 0.0)
	/* Make it jump out in the output file!!!! */
	mark_status (&(ms->data.multitiming_data.result[i]), "UNRELIABLE");
    break;
  default:
    ERROR(INTERN,"unknown pattern");
    output_error (TRUE);
  }

  return;
}

int
use_dummy_test (measurement_t *ms, int n, dummy_t which_dummy)
{
  if ((_sphinx_myid == 0) && (n + 1 == ms->dimensions_count))
    if (dummies[which_dummy] == UNMEASURED) {
      ERROR(INTERN,"dummy measurement undone; measurement not corrected");
      output_error (FALSE);
    }
    else 
      correct_result (ms, dummies[which_dummy]);

  return SUCCESS;
}

int
use_simple_dummy_test (void *ms, int the_arg, int n)
{
  return use_dummy_test ((measurement_t *) ms, n, SIMPLE_DUMMY);
}

int
use_mw_dummy_test (void *ms, int the_arg, int n)
{
  return use_dummy_test ((measurement_t *) ms, n, MW_DUMMY);
}

int
use_p2p_dummy_test (void *ms, int the_arg, int n)
{
  return use_dummy_test ((measurement_t *) ms, n, P2P_DUMMY);
}

int
use_col_dummy_test (void *ms, int the_arg, int n)
{
  return use_dummy_test ((measurement_t *) ms, n, COL_DUMMY);
}

int
use_col_over_nodes_dummy_test (void *ms, int the_arg, int n)
{
  measurement_t *local_ms = (measurement_t *) ms;
  int           index;

  if ((_sphinx_myid != 0) || (n + 1 != local_ms->dimensions_count))
    return SUCCESS;

  /* index is minus one since comm_size == 0 is irrelevant... */
  if (local_ms->dimensions[n].variation == NODES)
    index = the_arg - 1;
  else {
    MPI_Comm_size (local_ms->communicator, &index);
    index--;
  }

  if (col_over_nodes_dummies[index] == UNMEASURED) {
    ERROR(INTERN,"dummy measurement undone; measurement not corrected");
    output_error (FALSE);
  }
  else 
    correct_result (local_ms, col_over_nodes_dummies[index]);

  return SUCCESS;
}

int 
get_array_indexed_result (int *indices, int num_dims, 
			  data_list_t *aux_list, double *result)
{
  int           i, j, error;
  data_t        ldata;

  /* find the required element on aux_list... */
  read_ele (aux_list, START, 0, &ldata, &error);

  /* assume put on in increasing iters order, which is what we do... */
  for (i = 0; i < aux_list->number; i++) {
    for (j = 0; j < num_dims; j++) {
      if (ldata.arg[j] < indices[j])
	/* not far enough */
	break;

      if (ldata.arg[j] > indices[j])
	/* it can't be there since we've passed it's spot... */
	return FALSE;

      /* ldata.arg[j] == indices[j] */
      if (j == num_dims - 1) {
	/* found it */
	*result = ldata.result;
	return TRUE;
      }
    }

    read_ele (aux_list, LAST, 1, &ldata, &error);
  }

  /* it can't be there since we're out of elements... */
  return FALSE;
}

int 
get_indexed_result (int index, data_list_t *aux_list, double *result)
{
  return get_array_indexed_result (&index, 1, aux_list, result);
}

int
use_simple_inside_dummy_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  double        result;
  int           index;

  if (n + 1 != lms->dimensions_count)
    return SUCCESS;

  if (inside_list->number == 0) {
    ERROR(INTERN,"dummy measurement undone; measurement not corrected");
    output_error (FALSE);
    return SUCCESS;
  }

  switch (lms->pattern) {
  case SIMPLE:
  case THREAD_CHAIN:
    index = lms->iters_per_time * 
      (lms->iters_over_nodes ? lms->data.simple_data.iter_factor : 1);
    break;
  case MULTITIMING:
    index = lms->iters_per_time * 
      (lms->iters_over_nodes ? lms->data.multitiming_data.iter_factor : 1);
    break;
  default:
    ERROR (INTERN, "Invalid pattern in use_simple_inside_dummy_test");
    output_error (FALSE);
    return SUCCESS;
  }

  if (get_indexed_result (index, inside_list, &result))
    correct_result (lms, result);
  else {
    /* index wasn't found... */
    ERROR(INTERN,"dummy measurement undone; measurement not corrected");
    output_error (FALSE);
  }

  return SUCCESS;
}

int
use_a_p2p_overlap_test (measurement_t *ms, int real_arg, int n)
{
  double        result;

  if (n + 1 != ms->dimensions_count)
    return SUCCESS;

  if (p2p_overlap_list->number == 0) {
    ERROR(INTERN,"p2p overlap measurement undone; measurement not corrected");
    output_error (FALSE);
    return SUCCESS;
  }

  if (get_indexed_result (real_arg, p2p_overlap_list, &result))
    correct_result (ms, result);
  else {
    /* index wasn't found... */
    ERROR(INTERN,"p2p overlap measurement undone; measurement not corrected");
    output_error (FALSE);
  }

  return SUCCESS;
}

int
use_p2p_overlap_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;

  return use_a_p2p_overlap_test (lms, lms->overlap_iters, n);
}

int
use_p2p_second_overlap_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;

  return use_a_p2p_overlap_test (lms, lms->second_overlap_iters, n);
}

int
use_ACKer_latencies (void *ms, int the_arg, int n)
{
  measurement_t *local_ms = (measurement_t *) ms;
  int           dim_count = local_ms->dimensions_count;

  /* make correction only at task 0 and only if last variation.. */
  if ((_sphinx_myid == 0) && (n + 1 == dim_count)) {
    /* correct the measurement for the ACK latency... */
    int           i, ACKer, world_size, got_ACKer = FALSE;

    /* need world_size and ACKer to locate correction... */
    MPI_Comm_size (MPI_COMM_WORLD, &world_size);

    /* this should already have been caught well before now */
    /* but check it for safety in accessing union (ugh!) */
    if (local_ms->pattern != COLLECTIVE) {
      ERROR(USER,"invalid pattern in use_ACKer_latencies");
      output_error (FALSE);
      return GENERIC_ERROR;
    }
  
    /* find ACKer to use in checking reliability */
    for (i = 0; i < dim_count; i++) {
      if (local_ms->dimensions[i].variation == ACKER) {
	got_ACKer = TRUE;

	/* here we assume this is the only ACKER variation... */
	ACKer = local_ms->data.col_data.result->arg[i];

	break;
      }
    }

    if (!got_ACKer) {
      sprintf (_sphinx_msg,
	       "No ACKer found in use_ACKer_latencies for %s; using zero\n", 
	       local_ms->name);

      write_to_log_file (_sphinx_msg);

      ACKer = 0;
    }
    
    correct_result (local_ms, 
		    (p2p_latencies[local_ms->root * world_size + ACKer]/2));
  }

  return SUCCESS;
}

int
use_p2p_ACK_latency (void *ms, int the_arg, int n)
{
  measurement_t *local_ms = (measurement_t *) ms;
  int           dim_count = local_ms->dimensions_count;

  /* make correction only at task 0 and only if last variation.. */
  if ((_sphinx_myid == 0) && (n + 1 == dim_count)) {
    /* correct the measurement for the ACK latency... */
    int           ACKer;

    /* this should already have been caught well before now */
    /* but check it for safety in accessing union (ugh!) */
    if (local_ms->pattern != P2P) {
      ERROR(USER,"invalid pattern in use_p2p_ACK_latency");
      output_error (FALSE);
      return GENERIC_ERROR;
    }
  
    /* find ACKer to use in checking reliability */
    if (local_ms->data.p2p_data.which_to_measure == MEASURE_MAX)
      ACKer = local_ms->data.p2p_data.max_node;
    else
      ACKer = local_ms->data.p2p_data.min_node;

    /* here's a place where we assume one of the pair is task zero... */
    correct_result (local_ms, (p2p_latencies[ACKer]/2));
  }

  return SUCCESS;
}

int
use_gaps (void *ms, int the_arg, int n)
{
  measurement_t *local_ms = (measurement_t *) ms;
  int           dim_count = local_ms->dimensions_count;
  int           i, nodes, ACKer, got_ACKer = FALSE;

  /* Can either need to check reliability or to discard gaps */
  /* check reliability immediately after last variation */
  /* (should be after measurement but before correction) */
  /* discard gaps then also unless last variation is ACKER */
  /* when we can reuse the gaps. If so discard them immediately */
  /* after the penultimate variation... */
  if (n + 1 != dim_count) {
    /* discard gaps if appropriate */
    if ((n + 2 == dim_count) && 
	(local_ms->dimensions[n + 1].variation == ACKER) 
	&& (cur_gaps != NULL)) {
      free (cur_gaps);
      cur_gaps = NULL;
    }

    return SUCCESS;
  }

  /* must be last variation from here down... */

  /* this should already have been caught well before now */
  /* but check it for safety in accessing union (ugh!) */
  if (local_ms->pattern != COLLECTIVE) {
    ERROR(USER,"invalid pattern in use_gaps");
    output_error (FALSE);
    return GENERIC_ERROR;
  }
  
  /* find ACKer to use in checking reliability */
  for (i = 0; i < dim_count; i++) {
    if (local_ms->dimensions[i].variation == ACKER) {
      got_ACKer = TRUE;

      /* here we assume this is the only ACKER variation... */
      ACKer = local_ms->data.col_data.result->arg[i];

      break;
    }
  }

  if (!got_ACKer) {
    sprintf (_sphinx_msg,
	     "No ACKer found in use_gaps for %s; using zero\n", 
	     local_ms->name);

    write_to_log_file (_sphinx_msg);

    ACKer = 0;
  }

  MPI_Comm_size (local_ms->data.col_data.communicator, &nodes);

  /* check reliability of measurement (actually use gaps...) */
  if (_sphinx_myid == 0) {
    int reliable = TRUE;

    for (i = 0; i < nodes; i++) {
      /* check for unreliable result */
      if ((local_ms->data.col_data.onpath(ACKer, i, local_ms->root)) &&
	  (local_ms->data.col_data.result->result <= cur_gaps[i])) {
	reliable = 0; /* FALSE */
	break;
      }
    }

    if (!reliable) {
      sprintf (_sphinx_msg,
               "The measurement %s with %d nodes, ACKer = %d is unreliable\n",
               local_ms->name, nodes, ACKer);

      write_to_log_file (_sphinx_msg);

      /* Make it jump out in the output file!!!! */
      mark_status (local_ms->data.col_data.result, "UNRELIABLE");
    }
  }

  /* discard gaps if appropriate */
  if ((local_ms->dimensions[n].variation != ACKER) && (cur_gaps != NULL)) {
    free (cur_gaps);
    cur_gaps = NULL;
  }

  return SUCCESS;
}


#ifdef _HAVE_OMP_


void save_reference_result (measurement_t *ms, double reference)
{
  int i;

  switch (ms->pattern) {
  case P2P:
    ms->data.p2p_data.result->reference = reference;
    break;
  case MASTER_WORKER:
    ms->data.mw_data.result->reference = reference;
    break;
  case COLLECTIVE:
    ms->data.col_data.result->reference = reference;
    break;
  case SIMPLE:
  case THREAD_CHAIN:
    ms->data.simple_data.result->reference = reference;
    break;
  case MULTITIMING:
    /* do the full set... */
    for (i =0; i < ms->data.multitiming_data.num_timings; i++)
      ms->data.multitiming_data.result[i].reference = reference;
    break;
  default:
    ERROR(INTERN,"unknown pattern");
    output_error (TRUE);
  }

  ms->use_reference_data = TRUE;

  return;
}



int
use_basic_omp_ref_test (void *ms, int the_arg, int n, omp_aux_t which_omp_aux)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[which_omp_aux];
  double        result;
  int           indices[2];

  if (n + 1 != lms->dimensions_count)
    return SUCCESS;

  if (tlist->number == 0) {
    ERROR(INTERN,"reference measurement undone");
    output_error (TRUE);
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);

  if (get_array_indexed_result (indices, 2, tlist, &result))
    save_reference_result (lms, result);
  else {
    /* index wasn't found... */
    ERROR(INTERN,"reference measurement undone");
    output_error (TRUE);
  }

  return SUCCESS;
}

int
use_omp_parallel_ref_test (void *ms, int the_arg, int n)
{
  return use_basic_omp_ref_test (ms, the_arg, n, OMP_PARALLEL_AUX);
}

int
use_omp_parallel_for_ref_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[OMP_PARALLEL_FOR_AUX];
  double        result;
  int           indices[3];

  if (n + 1 != lms->dimensions_count)
    return SUCCESS;

  if (tlist->number == 0) {
    ERROR(INTERN,"reference measurement undone");
    output_error (TRUE);
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);
  indices[2] = get_sched_cap (lms);

  if (get_array_indexed_result (indices, 3, tlist, &result))
    save_reference_result (lms, result);
  else {
    /* index wasn't found... */
    ERROR(INTERN,"reference measurement undone");
    output_error (TRUE);
  }

  return SUCCESS;
}

int
use_omp_ordered_ref_test (void *ms, int the_arg, int n)
{
  return use_basic_omp_ref_test (ms, the_arg, n, OMP_ORDERED_AUX);
}

int
use_omp_single_ref_test (void *ms, int the_arg, int n)
{
  return use_basic_omp_ref_test (ms, the_arg, n, OMP_SINGLE_AUX);
}

int
use_omp_reduction_ref_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[OMP_REDUCTION_AUX];
  double        result;
  int           indices[3];

  if (n + 1 != lms->dimensions_count)
    return SUCCESS;

  if (tlist->number == 0) {
    ERROR(INTERN,"reference measurement undone");
    output_error (TRUE);
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);
  indices[2] = get_sched_cap (lms);

  if (get_array_indexed_result (indices, 3, tlist, &result))
    save_reference_result (lms, result);
  else {
    /* index wasn't found... */
    ERROR(INTERN,"reference measurement undone");
    output_error (TRUE);
  }

  return SUCCESS;
}

int
use_omp_atomic_ref_test (void *ms, int the_arg, int n)
{
  return use_basic_omp_ref_test (ms, the_arg, n, OMP_ATOMIC_AUX);
}

int
use_omp_overlap_ref_test (void *ms, int the_arg, int n)
{
  measurement_t *lms = (measurement_t *) ms;
  data_list_t   *tlist = omp_aux_lists[OMP_OVERLAP_AUX];
  double        result;
  int           indices[7];

  if (n + 1 != lms->dimensions_count)
    return SUCCESS;

  if (tlist->number == 0) {
    ERROR(INTERN,"reference measurement undone");
    output_error (TRUE);
  }

  indices[0] = get_which_work (lms);
  indices[1] = get_work_param (lms);
  indices[2] = get_which_overlap (lms);

  switch (indices[2]) {
  case OMP_SEQUENTIAL_OVERLAP:
    /* no other relevant parameters for measure_omp_parallel_ref... */
    indices[3] = sphinx_omp_max_num_threads;
    indices[4] = SCHEDULE_COUNT - 1;
    indices[5] = params.schedule_cap_default;
    indices[6] = params.schedule_chunks_default;
    break;
  case OMP_PARALLEL_OVERLAP:
    indices[3] = get_thread_count (lms);
    /* no other relevant parameters for measure_omp_parallel... */
    indices[4] = SCHEDULE_COUNT - 1;
    indices[5] = params.schedule_cap_default;
    indices[6] = params.schedule_chunks_default;
    break;
  case OMP_PARALLEL_FOR_OVERLAP:
    indices[3] = get_thread_count (lms);
    indices[4] = get_loop_schedule (lms);
    indices[5] = get_sched_cap (lms);
    /* schedule_chunks is not relevant to measure_omp_parallel_for... */
    indices[6] = params.schedule_chunks_default;
    break;
  case OMP_PARALLEL_FOR_CHUNKS_OVERLAP:
    indices[3] = get_thread_count (lms);
    indices[4] = get_loop_schedule (lms);
    indices[5] = get_sched_cap (lms);
    indices[6] = get_schedule_chunks (lms);
    break;
  default:
    ERROR (INTERN, "Invalid overlap type in need_omp_overlap_ref_test");
    output_error (FALSE);
    return FALSE;
  }

  if (get_array_indexed_result (indices, 7, tlist, &result))
    save_reference_result (lms, result);
  else {
    /* index wasn't found... */
    ERROR(INTERN,"reference measurement undone");
    output_error (TRUE);
  }

  return SUCCESS;
}


#endif /* _HAVE_OMP_ */


int print_aux_array (measurement_t *aux_ms, double *the_array, 
		     int max_index, int arg_displacement)
{
  FILE *output_file;
  int i;

  if (the_array == NULL)
    return SUCCESS;

  if ((output_file = fopen (out_file_name,"a+")) == NULL) {
    ERROR(FILE_OPEN,"append of measurement");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  fprintf (output_file,"\n#-------------------------------"\
	   "\n#/*@""in%s.ski*/\n%s", aux_ms->name, 
	   measurement_data_to_string(aux_ms, expl_text, 0));

  if (aux_ms->dimensions_count != 1) {
    ERROR(INTERN,"too many dimensions");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  fprintf (output_file,"arg[0] result");

  for (i = 0; i < max_index; i++)
    fprintf (output_file,"%d %f\n", i + arg_displacement, the_array[i]);
    
  fflush (output_file);

  return SUCCESS;
}

int print_col_over_nodes_dummies (void)
{
  measurement_t dummy_ms;

  my_initialize_measurement (&dummy_ms, &params);
  dummy_ms.dimensions_count = 1;
  dummy_ms.dimensions[0].variation = NODES;
  dummy_ms.name = "col_over_nodes_dummy";
  col_init_over_nodes_dummy (&dummy_ms);

  /* args are 1 more than index in col_over_nodes_dummies... */
  return print_aux_array (&dummy_ms, col_over_nodes_dummies, 
			  comm_world_size, 1);
}

int print_aux_list (measurement_t *aux_ms, data_list_t *the_list)
{
  FILE *output_file;

  if ((the_list == NULL) ||
      (number_of_elements(the_list) == 0))
    return SUCCESS;

  if ((output_file = fopen (out_file_name,"a+")) == NULL) {
    ERROR(FILE_OPEN,"append of measurement");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  fprintf (output_file,"\n#-------------------------------"\
	   "\n#/*@""in%s.ski*/\n%s", aux_ms->name, 
	   measurement_data_to_string(aux_ms, expl_text, 0));
  write_to_file (the_list, output_file, 
		 aux_ms->dimensions_count, aux_ms->dimensions, FALSE);
    
  fflush (output_file);

  return SUCCESS;
}

int print_simple_insides (void)
{
  measurement_t dummy_ms;

  my_initialize_measurement (&dummy_ms, &params);
  dummy_ms.dimensions_count = 1;
  dummy_ms.dimensions[0].variation = ITERS;
  dummy_ms.name = "simple_inside_dummy";
  simple_init_inside_dummy (&dummy_ms);

  return print_aux_list (&dummy_ms, inside_list);
}

int print_p2p_overlaps (void)
{
  measurement_t dummy_ms;

  my_initialize_measurement (&dummy_ms, &params);
  dummy_ms.dimensions_count = 1;
  dummy_ms.dimensions[0].variation = OVERLAP;
  dummy_ms.name = "p2p_overlap";
  p2p_init_overlap (&dummy_ms);

  return print_aux_list (&dummy_ms, p2p_overlap_list);
}


#ifdef _HAVE_OMP_

int print_omp_aux_lists (void)
{
  int           i;

  if (omp_aux_lists == NULL)
    return SUCCESS;

  for (i = 0; i < OMP_AUX_COUNT; i++) {
    measurement_t dummy_ms;
    data_list_t   *tlist = omp_aux_lists[i];
    int           retval;

    if (tlist == NULL)
      break;

    my_initialize_measurement (&dummy_ms, &params);

    switch (i) {
    case OMP_PARALLEL_AUX:
      dummy_ms.dimensions_count = 2;
      dummy_ms.dimensions[0].variation = WORK_FUNCTION;
      dummy_ms.dimensions[1].variation = WORK_AMOUNT;
      dummy_ms.name = "simple_omp_parallel_ref";
      simple_init_omp_parallel_ref (&dummy_ms);
      break;
    case OMP_PARALLEL_FOR_AUX:
      dummy_ms.dimensions_count = 3;
      dummy_ms.dimensions[0].variation = WORK_FUNCTION;
      dummy_ms.dimensions[1].variation = WORK_AMOUNT;
      dummy_ms.dimensions[2].variation = SCHED_CAP;
      dummy_ms.name = "simple_omp_parallel_for_ref";
      simple_init_omp_parallel_for_ref (&dummy_ms);
      break;
    case OMP_ORDERED_AUX:
      dummy_ms.dimensions_count = 2;
      dummy_ms.dimensions[0].variation = WORK_FUNCTION;
      dummy_ms.dimensions[1].variation = WORK_AMOUNT;
      dummy_ms.name = "simple_omp_ordered_ref";
      thread_chain_init_omp_ordered_ref (&dummy_ms);
      break;
    case OMP_SINGLE_AUX:
      dummy_ms.dimensions_count = 2;
      dummy_ms.dimensions[0].variation = WORK_FUNCTION;
      dummy_ms.dimensions[1].variation = WORK_AMOUNT;
      dummy_ms.name = "simple_omp_single_ref";
      thread_chain_init_omp_single_ref (&dummy_ms);
      break;
    case OMP_REDUCTION_AUX:
      dummy_ms.dimensions_count = 3;
      dummy_ms.dimensions[0].variation = WORK_FUNCTION;
      dummy_ms.dimensions[1].variation = WORK_AMOUNT;
      dummy_ms.dimensions[2].variation = SCHED_CAP;
      dummy_ms.name = "simple_omp_reduction_ref";
      simple_init_omp_reduction_ref (&dummy_ms);
      break;
    case OMP_ATOMIC_AUX:
      dummy_ms.dimensions_count = 2;
      dummy_ms.dimensions[0].variation = WORK_FUNCTION;
      dummy_ms.dimensions[1].variation = WORK_AMOUNT;
      dummy_ms.name = "simple_omp_atomic_ref";
      thread_chain_init_omp_single_ref (&dummy_ms);
      break;
    default:
      ERROR(USER,"invalid omp_aux_t occurred in print_omp_aux_lists");
      output_error(FALSE);
      return GENERIC_ERROR;
    }

    retval = print_aux_list (&dummy_ms, tlist);

    if (retval) return retval;
  }

  return SUCCESS;
}

void free_omp_aux_lists (void)
{
  int           i;

  if (append_to_omp_aux_lists != NULL)
    free (append_to_omp_aux_lists);

  if (omp_aux_lists == NULL)
    return;

  for (i = 0; i < OMP_AUX_COUNT; i++) {
    data_list_t   *tlist = omp_aux_lists[i];

    if (tlist == NULL)
      break;

    free_data_list (tlist, DYNAMIC);
  }

  free (omp_aux_lists);

  return;
}

#endif /* _HAVE_OMP_ */



void clean_up_aux_tests (void)
{
  /* need to call the print_* functions before MPI_Finalize... */
  if (col_over_nodes_dummies != NULL) {
    if (_sphinx_myid == 0)
      print_col_over_nodes_dummies();
    free (col_over_nodes_dummies);
  }
    
  if (inside_list != NULL) {
    if (_sphinx_myid == 0)
      print_simple_insides ();
    free_data_list (inside_list, DYNAMIC);
  }

  if (p2p_overlap_list != NULL) {
    if (_sphinx_myid == 0)
      print_p2p_overlaps ();
    free_data_list (p2p_overlap_list, DYNAMIC);
  }

#ifdef _HAVE_OMP_

  if (omp_aux_lists != NULL) {
    if (_sphinx_myid == 0)
      print_omp_aux_lists ();
    free_omp_aux_lists ();
  }

#endif /* _HAVE_OMP_ */

  if (p2p_latencies != NULL)
    free (p2p_latencies);
    
  return;
}
