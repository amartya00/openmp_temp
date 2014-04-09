/*
$Log: sphinx_params.h,v $
Revision 1.11  2000/08/25 23:17:18  bronis
Added OpenMP tests

Revision 1.10  2000/02/17 14:18:59  bronis
added first real non-blocking tests

Revision 1.9  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.8  1999/10/29 00:11:10  bronis
Fixed bugs, made input case insensitive

Revision 1.7  1999/10/25 19:05:43  srtaylor
Changed output filename format

Revision 1.6  1999/10/21 22:49:57  bronis
Made overall default simple pingpong

Revision 1.5  1999/09/29 00:23:49  bronis
removed most restrictions on ACKER variation

Revision 1.4  1999/09/14 16:38:52  srtaylor
First cut at multiple dimensions

Revision 1.3  1999/07/08 00:10:59  srtaylor
Beta release - Single dimension free form input completed and tested

Revision 1.2  1999/05/26 00:29:43  srtaylor
Modifications to allow all default values to be @XXX specified. e.g. @VARIATION ...

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: sphinx_params.h,v 1.11 2000/08/25 23:17:18 bronis Exp $ */

#define MAX_LINE_LEN 0x200        /* max. length of a line of the parameter
				     file */
				     
enum{NO_MODE, USER_MODE, MEM_MODE, STEPS_MODE, NETWORK_MODE, NODE_MODE, 
       MACHINE_MODE, COMMENT_MODE, OUTFILE_MODE, LOGFILE_MODE, MAX_REP_MODE,
       MIN_REP_MODE, STANDARD_DEVIATION_MODE,POST_MODE, MEASUREMENTS_MODE,
       CORRECT_MS_MODE, MPILIB_NAME_MODE, ITERS_PER_MODE, VARIATION_MODE, 
       DIMENSIONS_COUNT_MODE, SCALE_MODE, CHUNKS_MODE, MESSAGE_LEN_MODE, 
       START_MODE, END_MODE, STEPWIDTH_MODE, MAX_STEPS_MODE, MIN_DIST_MODE, 
       MAX_DIST_MODE, VARIATION_LIST_MODE, SCALE_LIST_MODE, START_LIST_MODE, 
       END_LIST_MODE, STEPWIDTH_LIST_MODE, MAX_STEPS_LIST_MODE, 
       MIN_DIST_LIST_MODE, MAX_DIST_LIST_MODE, OVERLAP_MAX_MODE,
       THREADS_DEFAULT_MODE, WORK_AMOUNT_DEFAULT_MODE, WORK_FUNC_DEFAULT_MODE,
       OVERLAP_FUNC_DEFAULT_MODE, SCHED_CAP_DEFAULT_MODE, 
       SCHED_CHUNKS_DEFAULT_MODE, SCHED_DEFAULT_MODE };


typedef struct 
{
  text_t user;
  text_t out_file;
  text_t log_file;
  text_t machine;
  text_t network;
  text_t node;
  unsigned memory;
  unsigned max_steps_default;
  unsigned max_rep_default;
  unsigned min_rep_default;
  double standard_deviation_default;
  int correct;
  int post_proc;
  text_t comment;
  text_t measurements;
  text_t mpilib_name;
  unsigned iters_per_time_default;
  unsigned overlap_default;
  int dimensions_count_default;
  int variation_default;
  int scale_default;
  int chunks_default;
  int message_len_default;
  int start_default;
  int end_default;
  double stepwidth_default;
  int min_dist_default;
  int max_dist_default;
  dimension_t dimensions_defaults[MAX_DIMENSIONS];
  int threads_default;
  int work_amt_default;
  int schedule_cap_default;
  int schedule_chunks_default;
  omp_work_name_t work_function_default;
  omp_overlap_name_t overlap_function_default;
  omp_schedule_t  loop_schedule_default;
}params_t;

measurement_t *do_pingpong_test (params_t *params, int *no_meas);
measurement_t *read_parameters (char *parameter_file_name, 
				params_t *params, int *no_meas);

params_t *init_params    (params_t *params, char *param_file_name);
params_t *parse_parameter_file (FILE *parameter_file, params_t *params,
				char *param_file_name);

void     my_initialize_measurement (measurement_t *measurement, 
				    params_t *params);

void initialize_omp_ms (measurement_t *ms);


