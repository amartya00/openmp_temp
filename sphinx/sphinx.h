/*
$Log: sphinx.h,v $
Revision 1.19  2000/08/25 23:17:16  bronis
Added OpenMP tests

Revision 1.18  2000/02/17 14:18:58  bronis
added first real non-blocking tests

Revision 1.17  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.16  1999/10/04 21:29:33  bronis
first cut at output filters

Revision 1.15  1999/10/04 15:53:06  bronis
fixed ACKer position bugs

Revision 1.14  1999/10/01 21:36:52  bronis
Added debugged Root variation

Revision 1.13  1999/09/29 16:10:41  bronis
First cut at ROOT variation

Revision 1.12  1999/09/29 00:23:48  bronis
removed most restrictions on ACKER variation

Revision 1.11  1999/09/23 17:08:44  bronis
cleaned up multi dim stuff

Revision 1.10  1999/09/21 15:59:50  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.9  1999/09/20 19:00:38  srtaylor
Merged measure and measure_suite

Revision 1.8  1999/09/17 23:03:00  bronis
Split BINDING variation

Revision 1.7  1999/09/16 16:30:30  bronis
incremental multi dim changes

Revision 1.6  1999/09/16 00:15:45  srtaylor
Outputs correct results for multiple dimensions

Revision 1.5  1999/09/15 15:50:57  srtaylor
Structure modifications - Does not currently compile

Revision 1.4  1999/09/14 16:38:51  srtaylor
First cut at multiple dimensions

Revision 1.3  1999/07/13 18:57:54  srtaylor
Handled DEC strcmp NULL problem

Revision 1.2  1999/07/08 00:10:58  srtaylor
Beta release - Single dimension free form input completed and tested

Revision 1.1.1.1  1999/05/11 16:50:03  srtaylor
CVS repository setup for sphinx

*/

static char rcsid[]="$Id: sphinx.h,v 1.19 2000/08/25 23:17:16 bronis Exp $";
#include <stdio.h>
#include <sys/utsname.h>
#include "mpi.h" 

/* check the io possibilities of the node with rank 0 */
/* #define NO_IO_CHECK  */  

#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define D(A) 
#define O(A) A
#define D1(A)
#define D2(A) 
#define D4(A)


#define MAX_DIMENSIONS          10
#define NO_VARIATION_ARG_VALUE   0
#define MAX_STATUS              80
#define SUCCESS                  0
#define GENERIC_ERROR          666

/* $Id: sphinx.h,v 1.19 2000/08/25 23:17:16 bronis Exp $ */
typedef struct
{
  double
    result,             /* mean value of measurements at arg's */
    standard_deviation, /* standard deviation of all measurements */
    reference;          /* mean value of reference test (OMP tests) */
  int
    count,                /* number of measurements performed at arg */
    arg[MAX_DIMENSIONS],  /* independent variable values */
    num_dims;             /* count of independent variables */
  char
    *status;              /* is anything wrong with data point... */
                          /* possible problems: UNRELIABLE; UNSETTLED */
                          /* if multiple problems, then we concatenate */
                          /* need to initialize to NULL; free */
}data_t;




#define DL_LINE_LEN 0x100  /* max length of one line read from a file */
/* one list element */
typedef struct DATA_ELE
{
  data_t data;        /* results of measurement */
  struct DATA_ELE         /* double-linked list */
    *prev,
    *next;
}list_item_t;


/* descriptor of list */
typedef struct DATA_LIST
{
  list_item_t
    *list_start,               /* Start of data_list */
    *list_end,                 /* actual end of data_list */
    *list_last;                /* last access */
  unsigned number;             /* number of elements */
}data_list_t;

enum {MIN, MAX, MEAN};         /* filter statistics */
enum {DL_NO_ERROR, DL_NO_ELEM, DL_NO_MEM};  /* error codes */
enum {END,START,LAST};             /* for mode in read_ele */
enum {STATIC, DYNAMIC};            /* for mode in free_list
				    STATIC == not freeing the descriptor
				    DYNAMIC == freeing the descriptor */


#define append(l,dataptr,error) add(l,END,0,dataptr,error)

/* Prototypes */

/* Initializes descriptor */
data_list_t *init_list(data_list_t *l);

data_list_t *init_list_array(int num_lists);

/* add can also used as insert: add inserts (arg,result) at pos at
   END/START (mode) in l and returns new list.
   errorcode returned in error */
data_list_t *add (data_list_t *l,  int mode, int pos, data_t *data,
		  int *error);

/* reads data in l at pos at (END/START) (mode) and returns
   NULL in error case */
data_t *read_ele (data_list_t *l, int mode, int pos, data_t *data, int *error);

/* reads data in l at pos from list_item and returns
   NULL in error case */
data_t *read_item_ele (data_list_t *l, list_item_t *list_item, int pos, 
		       data_t *data, int *error);

/* returns address of a list item, used for interaction with the 
priority queue and in postprocessing */
list_item_t *item_addr (data_list_t *l, int mode, int pos, int *error);

/* returns address of a list item, relative from list_item */
list_item_t *item_addr_at_item (data_list_t *l, list_item_t *list_item, 
				int pos, int *error);

/* returns number of elements stored in l */
int number_of_elements (data_list_t *l);

/* TRUE iff item ist last (first) element of a list */
int is_end (list_item_t *item);
int is_start (list_item_t *item);

/* removes element at pos from END/START (mode) in l and returns errorcode */
data_list_t *remove_ele (data_list_t *l,  int mode, int pos);

/* frees all ressources used by l */
void free_data_list (data_list_t *l, int mode);

void free_data_list_array (data_list_t *l_array, int mode, int num_lists);

/* statistical functions */
double variance (data_list_t *l);
double median (data_list_t *l);
double average (data_list_t *l);
double maximum (data_list_t *l, int *arg);
double minimum (data_list_t *l, int *arg);
data_list_t *average_of_lists (data_list_t **l);
int filter (int stat, data_list_t *inlist, data_list_t *outlist, int arg_num);

data_list_t *read_from_file (data_list_t *l, FILE **file, int *error);

void copy_data(data_t *dd, data_t *sd);
void mark_status (data_t *the_data, char *the_status);

int send_data (MPI_Comm comm, data_t *the_data, int dst);
int recv_data (MPI_Comm comm, data_t *the_data, int src);
int send_data_list (MPI_Comm comm, data_list_t *the_data, int dst);
int recv_data_list (MPI_Comm comm, data_list_t *the_data, int src);


char *translate_work_function (int which_work);
char *translate_omp_schedule (int which_schedule);
char *translate_overlap_function (int which_overlap);

#include <stdio.h>
/* the different patterns */
enum{P2P, MASTER_WORKER, COLLECTIVE, SIMPLE, THREAD_CHAIN, MULTITIMING};

typedef enum { STATIC_SCHED = 0,
	       DYNAMIC_SCHED,
	       GUIDED_SCHED,
               SCHEDULE_COUNT } omp_schedule_t;

typedef enum { SIMPLE_WORK = 0,
	       BORS_WORK,
	       SPIN_TIMED_WORK,
	       SLEEP_TIMED_WORK,
               WORK_FUNCTION_COUNT } omp_work_name_t;

typedef enum { OMP_SEQUENTIAL_OVERLAP = 0,
	       OMP_PARALLEL_OVERLAP,
	       OMP_PARALLEL_FOR_OVERLAP,
	       OMP_PARALLEL_FOR_CHUNKS_OVERLAP,
               OMP_OVERLAP_FUNCTION_COUNT } omp_overlap_name_t;

enum{NODES, LENGTH, CHUNK, NO_VARIATION, ITERS, MASTER_BINDING, 
     SLAVE_BINDING, ACKER, ROOT, OVERLAP, SECOND_OVERLAP, THREADS, 
     WORK_AMOUNT, WORK_FUNCTION, OVERLAP_FUNCTION, SCHED_CAP, SCHED_CHUNKS, 
     SCHEDULE };/* variation */
enum{FIXED_LIN, FIXED_LOG, DYN_LIN, DYN_LOG};     /* x_scales */
enum{SKIP, TODO, DONE, FAILED};                
enum{MEASURE_MAX, MEASURE_MIN};                   /* which_to_measure in 
						     p2p_pattern_data_t */


typedef int (*my_f_ptr_t) (void);
typedef void *(*my_f2_ptr_t) (void *);
typedef MPI_Status (*p2p_f_ptr_t) (int, int, MPI_Comm);
typedef void (*col_f_ptr_t) (int len,MPI_Comm);


typedef struct
{
  int thread_count;           /* number of threads used with OMP tests... */

  int work_amount;            /* parameter for work function */
  omp_work_name_t which_work; /* work function to use */

  omp_overlap_name_t which_overlap; /* overlap function to use */

  int cap_for_schedule_loops;
  int schedule_chunks;

  omp_schedule_t loop_schedule;
  
  void *schedule_routines_to_measure[SCHEDULE_COUNT];   
  void *schedule_routines_to_measure2[SCHEDULE_COUNT];   
} omp_data_t;

/* bundle of data reached in the p2p_pattern */
typedef struct
{
  /* Pointer to function measured by server */
  p2p_f_ptr_t server_op; 
  
  /* Pointer to client function */
  p2p_f_ptr_t client_op; 

  int which_to_measure;  /* which node should be used for measurement ?
			    the one with the max. latencie or the one
			    with the min. */

  /* both _node variables are filled in the routine p2p_find_max_min
     of module p2p.c */
  int max_node;          /* number of the node with max. latencie */
  int min_node;          /* ... with min. latentcie */

  int len;               /* the actual message length IN */
  int def_nodes;         /* the number of nodes used for this measurement IN */
  MPI_Comm communicator; /* Communicator used for measurement IN */

  data_t *result;        /* Measured results OUT */

  int iters;               /* the actual iterations per timing IN */
}p2p_pattern_data_t;

/* bundle of data reached in the mw_pattern */
typedef struct
{
  void (* master_receive_ready) (int, int len, MPI_Comm); 
  int  (* master_dispatch)      (int now, int work, int chunks, 
				 int len, MPI_Comm); 
  void (* master_worker_stop)   (int worker, int len, MPI_Comm); 
  int  (* worker_receive)       (int len, MPI_Comm); 
  void (* worker_send)          (int len, MPI_Comm); 

  MPI_Comm communicator; /* Communicator used for measurement IN */

  int len;               /* message length IN */
  int def_nodes;         /* the number of nodes used for this measurement IN */
  int chunks;            /* Number of work pieces IN */
  data_t *result;        /* Measured results  OUT */

  int iters;               /* the actual iterations per timing IN */
}mw_pattern_data_t;



typedef struct
{
  col_f_ptr_t routine_to_measure; 
  col_f_ptr_t client_routine;
  int len;               /* message length */
  int def_nodes;         /* the number of nodes used for this measurement IN */
  MPI_Comm communicator; /* Communicator used for measurement */
  data_t *result;        /* Measured results */

  int iters;               /* the actual iterations per timing IN */

  void (* gap_routine_to_measure) (int len,MPI_Comm); 
  void (* ACKer_routine) (int len,MPI_Comm); 
  void (* notACKer_routine) (int len,MPI_Comm); 
  int (* onpath) (int node_to_reach, int node_to_test, int root); 
  int ACKer;
}col_pattern_data_t;


typedef struct
{
  my_f_ptr_t routine_to_measure; 
  void *(* client_routine) (void *data); 

  data_t *result;        /* Measured results OUT */
  int server_cpu;	 /* Used with variation over binding... */
  int client_cpu;	 /* Used with variation over binding... */

  int iter_factor;       /* used to correct for multiple calls per iter... */
  int iters;             /* the actual iterations per timing IN */
}simple_pattern_data_t;


typedef struct
{
  my_f_ptr_t *routines_to_measure; 

  /* Have begun initial set up of allowing multitimings when there */
  /* are client routines; it is not fully worked out */
  /* Idea is that these are the actual client routines */

  my_f2_ptr_t *client_routines; 

  /* This allows the client to be a thread (instead of another MPI task) */
  void *(* call_client_routines) (void *data); 


  data_t *result;        /* Measured results OUT */
  int server_cpu;	 /* Used with variation over binding... */
  int client_cpu;	 /* Used with variation over binding... */
  int num_timings;

  int iter_factor;       /* used to correct for multiple calls per iter... */
  int iters;             /* the actual iterations per timing IN */
}multitiming_pattern_data_t;

typedef struct
{
  int variation;
  int scale;
  int start;
  int end;
  double stepwidth;
  int max_steps;
  int min_dist;
  int max_dist;
} dimension_t; 

typedef int (*aux_f_ptr_t) (void *ms, int the_arg, int n);

typedef struct an_aux_test
{
  aux_f_ptr_t      need_aux_f;
  aux_f_ptr_t      aux_f;
  aux_f_ptr_t      use_aux_f;
} aux_test_t;
 
typedef struct a_measurement
{
  int pattern;   /* which pattern should be applied IN */
  int dimensions_count;

  int max_rep;   /* max. number of calls of measurements in a pattern IN */
  int min_rep;   /* min. number of calls of measurements in a pattern IN */

  int max_allowed_len;

  char *name;    /* name of ths measurement IN */

  dimension_t dimensions[MAX_DIMENSIONS];

  MPI_Comm communicator;

  double
    standard_deviation; /* the max. allowed standard dev: used to determine
		       the end of measurements at one arg */		       
  data_list_t *result_list; /* list of results OUT */

  /* default values */
  int nodes;

  int should_call_pattern;    /* should this task call the pattern */
                              /* for this data point; always TRUE */
                              /* for task 0; only changed if varying */
                              /* over nodes at this point...  */

  /* routines for allocating and freeing ressources:
     nor = number of repetitions (usually max_rep)
     nom = number of measurements (usually x_max_steps)
     nop = number of processes in this communicator 
     ms = this measurement... */

  long (*server_init) (int nor, int nom, int nop, struct a_measurement *ms);
  long (*client_init) (int nor, int nom, int nop, struct a_measurement *ms);
  void (*server_free) (struct a_measurement *ms);
  void (*client_free) (struct a_measurement *ms);

  /* so far this is only used with the THREAD_CHAIN pattern... */
  void (*iter_cleanup) (void);

  union          /* pattern specific data_structures IN */
  {
    p2p_pattern_data_t         p2p_data;
    mw_pattern_data_t          mw_data;
    col_pattern_data_t         col_data;
    simple_pattern_data_t      simple_data;
    multitiming_pattern_data_t multitiming_data;
  }data;
  
  int iters_per_time;     /* accounts for multiple calls per timing */
  int iters_over_nodes;   /* accounts for multiple ops per call per timing */
  
  /* function to perform any clean up required (i.e. freeing memory) */
  /* at the very end; for example, with multitiming measurements, */
  /* need to free function pointer array */
  void (* destroy) (void *the_ms);

  int uses_proxy;
  int need_to_create_proxy;

  int root;

  int overlap_iters, second_overlap_iters;

  int client_scope_and_detachedstate;

  int num_aux_tests;
  aux_test_t *aux_tests;

  int correct_ms;

  int ACKer_OK;

  omp_data_t omp_data;   /* used with OMP tests... */

  int use_reference_data;
  int have_omp_params;
  int pattern_in_omp_parallel;
}measurement_t;

/* default values, overwritten in initialize_types (sphinx_params.c) */
#define DEF_CHUNKS_VALUE 10
#define DEF_LEN_VALUE 0x100
#define DEF_NODES_VALUE 0
#define DEF_OVERLAP_VALUE 0

/* this is really a legacy artifact; removing it everywhere isn't */
/* worth the trouble; would allow one to define it differently */
/* but should still use macros if you did... */
#define default_communicator   MPI_COMM_WORLD

/* used with p2p_latencies... */
#define UNMEASURED          -666.0

#define P2P_ACK_TAG    2315


/* file i/o */
int write_to_file (data_list_t *l, FILE *file, 
		   int expected_num_dims, dimension_t *dims, int use_ref);

int get_max_iters_value (measurement_t *ms);
