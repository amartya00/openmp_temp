/*
$Log: sphinx_params.c,v $
Revision 1.31  2000/12/14 00:26:52  bronis
Added improved scan test and scalable tests for fan out collectives

Revision 1.30  2000/08/25 23:17:18  bronis
Added OpenMP tests

Revision 1.29  2000/03/16 15:48:39  bronis
fixed mpguidec warnings

Revision 1.28  2000/02/17 14:18:59  bronis
added first real non-blocking tests

Revision 1.27  2000/01/14 23:34:55  bronis
purified recent changes

Revision 1.26  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.25  1999/10/29 00:11:10  bronis
Fixed bugs, made input case insensitive

Revision 1.24  1999/10/25 19:05:43  srtaylor
Changed output filename format

Revision 1.23  1999/10/21 22:49:57  bronis
Made overall default simple pingpong

Revision 1.22  1999/10/21 00:00:00  bronis
Finished post processing clean up

Revision 1.21  1999/09/29 16:10:41  bronis
First cut at ROOT variation

Revision 1.20  1999/09/29 00:23:49  bronis
removed most restrictions on ACKER variation

Revision 1.19  1999/09/23 17:08:45  bronis
cleaned up multi dim stuff

Revision 1.18  1999/09/21 23:28:39  bronis
fixed pthreads tests

Revision 1.17  1999/09/17 23:03:01  bronis
Split BINDING variation

Revision 1.16  1999/09/14 16:38:52  srtaylor
First cut at multiple dimensions

Revision 1.15  1999/09/07 17:24:38  bronis
Defined MPILIB_NAME in Makefile's

Revision 1.14  1999/07/29 17:02:43  bronis
Fixed bug in alignment fix

Revision 1.13  1999/07/26 23:37:10  srtaylor
Multiple dimensions free form input (compile with -DMULTI_DIM)

Revision 1.12  1999/07/14 15:57:43  bronis
Fixed DEC text_t warnings

Revision 1.11  1999/07/13 18:57:54  srtaylor
Handled DEC strcmp NULL problem

Revision 1.10  1999/07/13 14:49:28  bronis
increased input file size; changed Acker to ACKer as needed

Revision 1.9  1999/07/12 23:10:32  bronis
need DEFAULT in corrected_line

Revision 1.8  1999/07/12 21:58:04  srtaylor
Modified default value sequence

Revision 1.7  1999/07/12 18:45:32  srtaylor
Bcast new default parameters

Revision 1.6  1999/07/12 16:15:54  bronis
another minor bug

Revision 1.5  1999/07/09 22:11:45  srtaylor
Remove debug output

Revision 1.4  1999/07/08 00:10:59  srtaylor
Beta release - Single dimension free form input completed and tested

Revision 1.3  1999/05/26 00:29:42  srtaylor
Modifications to allow all default values to be @XXX specified. e.g. @VARIATION ...

Revision 1.2  1999/05/14 18:21:33  srtaylor
Free form input modification (only the "Type" field is required).

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/


#define STEPWIDTH_DEFAULT    1.0
#define MIN_DIST_DEFAULT 1 
#define MAX_DIST_DEFAULT 10
#define DIMENSIONS_COUNT_DEFAULT 1

#include "sphinx.h"
#include "sphinx_aux.h"
#include "sphinx_error.h"
#include "sphinx_tools.h"
#include "sphinx_params.h"
#include "sphinx_aux_test.h"
#include "col_test1.h"
#include "mw_test1.h"
#include "p2p_test1.h"
#include "simple_test1.h"
#include "sphinx_omp.h"

#ifndef BUILD_MPILIB_NAME
#define BUILD_MPILIB_NAME "Not_Specified"
#endif

#define BSIZE 0x1000  /* size of lexem-buffer */
#define NONE -1
#define EOT  -2  /* end of text */
#define EOS  '\0'
#define DONE -3

/* #define MY_TEST_IO */

/* tokenvalues */
#define INTEGER              256
#define FLOAT                257
#define STRING               258
#define TYPE                 259
#define VARIATION            260
#define SCALE                261
#define MAX_REPETITION       262
#define MIN_REPETITION       263
#define START_ARGUMENT       264
#define END_ARGUMENT         265
#define STEPWIDTH            266
#define MAX_STEPS            267
#define MAX_DIST             268
#define MIN_DIST             269
#define STANDARD_DEVIATION   270
#define LENGTH_VAR           271
#define NODES_VAR            272
#define CHUNKS_VAR           273
#define OVERLAP_VAR          274
#define SECOND_OVERLAP_VAR   275
#define THREADS_VAR          276
#define WORK_AMOUNT_VAR      277
#define WORK_FUNCTION_VAR    278
#define OVERLAP_FUNCTION_VAR 279
#define SCHEDULE_CAP_VAR     280
#define SCHEDULE_TYPE_VAR    281
#define SCHEDULE_CHUNKS_VAR  282
#define NO_VAR               283
#define FIXED_LIN_SCALE      284
#define FIXED_LOG_SCALE      285
#define DYN_LIN_SCALE        286
#define DYN_LOG_SCALE        287
#define MAX_VALUE            288
#define ITERS_VAR            289
#define MASTER_BINDING_VAR   290
#define SLAVE_BINDING_VAR    291
#define ACKER_VAR            292
#define ROOT_VAR             293
#define MIN_VALUE            294
#define CORRECT              295


int 
  pos = 0,
  lineno = 0;

/* eo global */

/* private */
char     *line_mode      (char *line, int *mode);
int      count_measurements (text_t text);
void     send_text (text_t text);
int      recv_text (text_t text);
void     my_initialize_type (measurement_t *ms, int index);

/* this is the perfect example of why that stupid union used in the */
/* old code results in a hideous design; it should be removed but */
/* for now we will just allow this sort of thing explode... */
int def_nodes,    /* used for the variables not varied over */
    def_chunks,
    def_len,
    def_threads,
    def_work_amount,
    def_schedule_cap,
    def_schedule_chunks;

omp_work_name_t    def_work_function;
omp_overlap_name_t def_overlap_function;
omp_schedule_t     def_loop_schedule;



/* analyses entries of the @MEASUREMENTS-Section of the parameter-file */
/* grammar */

void my_parse (measurement_t *measurements_array,
               params_t *params,
               int *measurements_count);
void my_int_or_max (char *source, int *target);
void my_int_or_min (char *source, int *target);
omp_work_name_t work_func (char *string);
omp_overlap_name_t overlap_func (char *string);
omp_schedule_t omp_sched (char *string);
char *strstr_ignore_case (char *string, char *pattern);

void write_params_to_crt (params_t *params);
void write_measurement_to_crt (measurement_t *measurement);

/*
   @FUN:
   @DOES: reads the parameter_file, fills params and returns 
   a filled measurements array, in *no_meas the number of
   measurements is given back 
   returnes NULL in case of error
   @PARAMETERS: name of parameter file, the params-struct which will be filled
   the number of measurements (*no_meas) (also filled here)
   @RETURNES: returnes to an array of *no_meas filled measurements in 
   case of success.
   @SIDEEFFECTS: in case of error it aborts the program.
   @ASSUMES: _sphinx_myid set.
*/
measurement_t *
do_pingpong_test (params_t *params, int *no_meas)
{
  measurement_t *ms;       /* measurement array - return value... */

  if (params == NULL) {
    ERROR(INTERN,"do_pingpong_test called with *params == NULL");
    output_error (TRUE);
  }

  init_params (params, NULL);

  *no_meas = 1;

  if ((ms = (measurement_t *) malloc (sizeof (measurement_t))) == NULL) {
    ERROR (NO_MEM,"no memory for the measuremnts array.");
    output_error (TRUE);
  }

  my_initialize_measurement (ms, params);

  ms->name = (char *)malloc(strlen("MPI_Send-Recv_pingpong")+1);
  strcpy (ms->name, "MPI_Send-Recv_pingpong"); 

  ms->dimensions[0].variation = LENGTH;
  ms->dimensions[0].start = 1;
  ms->dimensions[0].end = 1;
  ms->dimensions[0].max_steps = 1;

  my_initialize_type (ms, 1);

  return (ms);
}


/*
   @FUN:
   @DOES: reads the parameter_file, fills params and returns 
   a filled measurements array, in *no_meas the number of
   measurements is given back 
   returnes NULL in case of error
   @PARAMETERS: name of parameter file, the params-struct which will be filled
   the number of measurements (*no_meas) (also filled here)
   @RETURNES: returnes to an array of *no_meas filled measurements in 
   case of success.
   @SIDEEFFECTS: in case of error it aborts the program.
   @ASSUMES: _sphinx_myid set.
*/
measurement_t *
read_parameters (char *parameter_file_name, params_t *params, int *no_meas)
{
  FILE
    *parameter_file= NULL;

  measurement_t                  
    *ms;                  /* measurement array, later returned to caller */

  int
    i, j;                    /* for looping around */

  if (params == NULL)
  {
    ERROR(INTERN,"read_parameters called with *params == NULL");
    output_error (TRUE);
  }

  init_params (params, parameter_file_name);

#ifdef MY_TEST_IO
printf ("\nDefault parameters before parsing the input file: \n");
write_params_to_crt (params);
#endif

  if (parse_parameter_file (parameter_file, params, 
			    parameter_file_name) == NULL)
    output_error (TRUE);

#ifdef MY_TEST_IO
printf ("\nDefault parameters after parsing the input file: \n");
write_params_to_crt (params);
#endif

  if ((ms = malloc ((*no_meas = count_measurements (params->measurements)) 
		    * sizeof (measurement_t))) == NULL)
  {
    ERROR (NO_MEM,"no memory for the measuremnts array.");
    output_error (TRUE);
  }

{
  D1(FILE
    *hua = stderr;
    write_text_to_file (params->measurements, "measurements",&hua);)
}
  my_parse (ms, params, no_meas);

  for (i=0; i<*no_meas; i++)
  {
    for (j=0; j<ms[i].dimensions_count; j++)
    {
      /* Check that dimensions[j].stepwidth are > 0 */
      if (ms[i].dimensions[j].stepwidth <= 0)
      {
        ms[i].dimensions[j].stepwidth = STEPWIDTH_DEFAULT;
      }
  
      /* Check for valid step for the given scale and vica-versa */
      if ((ms[i].dimensions[j].scale == FIXED_LOG) ||
          (ms[i].dimensions[j].scale == DYN_LOG))
      {
        if (ms[i].dimensions[j].stepwidth <= 1)
        {
          ms[i].dimensions[j].stepwidth = sqrt (2);
        }
      }
  
      if ((ms[i].dimensions[j].scale == FIXED_LIN) ||
          (ms[i].dimensions[j].scale == DYN_LIN))
      {
        if (ms[i].dimensions[j].stepwidth <= 1)
        {
          ms[i].dimensions[j].stepwidth = 1.0;
        }
      }
  
      if (ms[i].max_rep == DEFAULT)
        ms[i].max_rep = params->max_rep_default;
  
      if (ms[i].min_rep == DEFAULT)
        ms[i].min_rep = params->min_rep_default;

      if (ms[i].dimensions[j].max_steps == DEFAULT)
        ms[i].dimensions[j].max_steps = params->max_steps_default;

      if (ms[i].standard_deviation == (double) DEFAULT)
        ms[i].standard_deviation = params->standard_deviation_default;
    }
  }

  return (ms);
}

/*
   @FUN:
   @DOES: initializes the parameter struct with its default values,
   the definition of the constants can be found in sphinx_error.h
   called by read_parameters.
   @PARAMETERS: the parameter array to be filled.
   @RETURNES:
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
params_t *
init_params (params_t *params, char *param_file_name)
{
  int i;

  params->user[0] = NULL;
  if (param_file_name == NULL)
  {
    params->out_file[0] = "sphinx.out";
    params->log_file[0] = "sphinx.log";
  }
  else
  {
    char *temp_file_name_line;
    int length = strlen (param_file_name);

    temp_file_name_line = (char *) malloc (length+5);

    strcpy (temp_file_name_line, param_file_name);
    strcat (temp_file_name_line, ".out");

    insert_in_text (temp_file_name_line, params->out_file, 0);    

    temp_file_name_line[length+1] = 'l';
    temp_file_name_line[length+2] = 'o';
    temp_file_name_line[length+3] = 'g';
 
    insert_in_text (temp_file_name_line, params->log_file, 0);
 
    free (temp_file_name_line);
  }
  params->out_file[1] = NULL;
  params->log_file[1] = NULL;
  params->machine[0] = NULL;
  params->network[0] = NULL;
  params->node[0] = NULL;
  params->memory = MEM_DEFAULT;
  params->max_steps_default = MAX_STEPS_DEFAULT;
  params->max_rep_default = MAX_REP_DEFAULT;
  params->min_rep_default = MIN_REP_DEFAULT;
  params->standard_deviation_default = STANDARD_DEVIATION_DEFAULT;
  params->correct = FALSE; /* as default */
  params->post_proc = FALSE; /* as default */
  params->comment[0] = NULL;
  params->measurements[0] = NULL;  /* or all ? */
  
  params->mpilib_name[0] = BUILD_MPILIB_NAME;
  params->mpilib_name[1] = NULL;
  params->iters_per_time_default = ITERS_PER_DEFAULT;
  params->threads_default = MAX_ARGUMENT;
  params->work_amt_default = DEFAULT_WORK_AMOUNT;
  params->schedule_cap_default = DEFAULT_SCHEDULE_CAP;
  params->schedule_chunks_default = DEFAULT_SCHEDULE_CHUNKS;

  params->work_function_default = DEFAULT_WORK_FUNCTION;
  params->overlap_function_default = DEFAULT_OVERLAP_FUNCTION;
  params->loop_schedule_default = DEFAULT_LOOP_SCHEDULE;

  params->overlap_default = DEF_OVERLAP_VALUE;

  params->dimensions_count_default = DIMENSIONS_COUNT_DEFAULT;
  params->variation_default = NO_VARIATION;
  params->scale_default = FIXED_LIN;
  params->chunks_default = DEF_CHUNKS; 
  params->message_len_default = DEF_MESSAGE_LEN;
  params->start_default = MIN_ARGUMENT;
  params->end_default = MAX_ARGUMENT;
  params->stepwidth_default = STEPWIDTH_DEFAULT;
  params->min_dist_default = MIN_DIST_DEFAULT;
  params->max_dist_default = MAX_DIST_DEFAULT;

  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    params->dimensions_defaults[i].variation = NO_VARIATION;
    params->dimensions_defaults[i].scale = FIXED_LIN;
    params->dimensions_defaults[i].start = MIN_ARGUMENT;
    params->dimensions_defaults[i].end = MAX_ARGUMENT;
    params->dimensions_defaults[i].stepwidth = STEPWIDTH_DEFAULT;
    params->dimensions_defaults[i].max_steps = MAX_STEPS_DEFAULT;
    params->dimensions_defaults[i].min_dist = MIN_DIST_DEFAULT;
    params->dimensions_defaults[i].max_dist = MAX_DIST_DEFAULT;
  }
  /* END ST */

  return (params);
}

/*
   @FUN:
   @DOES: parses the paremeter_file into the struct *params.
   @PARAMETERS: above
   @RETURNES: the filled params-struct or in case of error NULL.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
params_t *
parse_parameter_file (FILE *parameter_file, params_t *params, 
		      char *param_file_name)
{
  int i, j, k;
  char *tokens[100];

  char 
    line[MAX_LINE_LEN],
    *corrected_line;

  text_t the_file;
  
  int 
    mode = COMMENT_MODE,
    new_mode,
    comment_line_counter = 0,
    measurements_line_counter = 0,
    line_counter = 0,
    file_lines = 0;

#ifndef NO_MPI
  if (_sphinx_myid == 0) {
#endif

    if ((parameter_file = fopen (param_file_name, "r")) == NULL) {
      sprintf (_sphinx_msg,"opening parameter file %s.", param_file_name);
      ERROR (FILE_OPEN,_sphinx_msg);
      output_error (TRUE);
    }

    /* read in entire file; this kind of a kludgie way but it uses */
    /* existing code while making it much more efficient... */
    while (fgets (line, MAX_LINE_LEN, parameter_file) != NULL) {
      if (file_lines == TEXT_LINES) {
	sprintf (_sphinx_msg,
		 "too many lines in input: lines skipped starting with:\n"\
		 "%s",line);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
	break;
      }

      insert_in_text (line, the_file, file_lines++);
    }
    
#ifndef NO_MPI
    /* send input file */
    send_text (the_file);
  }
  else {
    /* receive input file */
    file_lines = recv_text (the_file);
  }
#endif

  if (params == NULL)
    if ((params = (params_t *) malloc (sizeof(params_t))) == NULL) {
      ERROR (NO_MEM,"parameter reading");
      output_error (TRUE);
    }

  for (k = 0; k < file_lines; k++) {
    read_from_text (line, the_file, k);

    corrected_line = line_mode(line, &new_mode);
    
    if (new_mode != NO_MODE)
    {
      mode = new_mode;
      line_counter = 0;
    }
    else
      line_counter++;

    switch (mode)
    {
    case COMMENT_MODE:
      insert_in_text (corrected_line, params->comment, 
		      comment_line_counter++);
      break;
            
    case USER_MODE:
      insert_in_text (corrected_line, params->user, line_counter);
      break;
      
    case MEM_MODE:
      params->memory = atoi (corrected_line);
      if (params->memory == 0)
      {
	params->memory = MEM_DEFAULT;
        sprintf (_sphinx_msg,"error parsing memory size,\n"\
		 "memory size set to default value: %d KB.", MEM_DEFAULT);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;

    case STEPS_MODE:
      params->max_steps_default = atoi (corrected_line);
      if (params->max_steps_default == 0)
      {
	params->max_steps_default = MAX_STEPS_DEFAULT;
        sprintf (_sphinx_msg,"error parsing max steps ,\n"\
		 "max steps set to default value: %d.", MAX_STEPS_DEFAULT);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;

    case MAX_REP_MODE:
      params->max_rep_default = atoi (corrected_line);
      if (params->max_rep_default == 0)
      {
	params->max_rep_default = MAX_REP_DEFAULT;
        sprintf (_sphinx_msg,"error parsing max rep,\n"\
		 "max repetitions set to default value: %d.", 
		 MAX_REP_DEFAULT);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;

    case MIN_REP_MODE:
      params->min_rep_default = atoi (corrected_line);
      if (params->min_rep_default == 0)
      {
	params->min_rep_default = MIN_REP_DEFAULT;
        sprintf (_sphinx_msg,"error parsing min steps,\n"\
		 "min steps set to default value: %d.", 
		 MIN_REP_DEFAULT);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;

    case STANDARD_DEVIATION_MODE:
      params->standard_deviation_default = atof (corrected_line);
      if (params->standard_deviation_default == 0)
      {
	params->standard_deviation_default = STANDARD_DEVIATION_DEFAULT;
        sprintf (_sphinx_msg,"error parsing standard_deviation,\n"\
		 "standard_deviation set to default value: %f.", 
		 STANDARD_DEVIATION_DEFAULT);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;
      
    case POST_MODE:
      /* If NULL is returned then "no" doesn't occur in corrected line */
      if (strstr_ignore_case (corrected_line,"no") != NULL) {
        params->post_proc = FALSE;
      }
      else      
      {
	if (strstr_ignore_case (corrected_line,"yes") == NULL)
	{
	  sprintf (_sphinx_msg, "error parsing parameter @POSTPROC:"\
			     "possible values only: \"yes\" or \"no\".\n"\
			     "set to default value %s.",
		   params->post_proc ? "yes":"no");
	  ERROR(USER,_sphinx_msg);
	  output_error (FALSE);
	  break;
	}
	
	sprintf (_sphinx_msg, "Post processing is problematic\n"\
		 "It is derived directly from existing code\n"\
		 "The mechanism makes a number of quetionable choices\n"\
		 "Its use is not recommended\n"\
		 "Do so at your own risk\n");
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
	printf ("Post processing is problematic\n");
	printf ("It is derived directly from existing code\n");
	printf ("The mechanism makes a number of quetionable choices\n");
	printf ("Its use is not recommended\n");
	printf ("Do so at your own risk\n");
        params->post_proc = TRUE;
      }
      
      break;

    case CORRECT_MS_MODE:
      /* If NULL is returned then "no" doesn't occur in corrected line... */
      if (strstr_ignore_case (corrected_line,"no") != NULL) {
        params->correct = FALSE;
      }
      else      
      {
	if (strstr_ignore_case (corrected_line,"yes") == NULL)
	{
	  sprintf (_sphinx_msg, 
		   "error parsing parameter @CORRECT_FOR_OVERHEAD:"\
		   "possible values only: \"yes\" or \"no\".\n"\
		   "set to default value %s.",
		   params->correct ? "yes":"no");
	  ERROR(USER,_sphinx_msg);
	  output_error (FALSE);

	  /* so do not manipulate params->correct */
	  break;
	}
	
        params->correct = TRUE;
      }
      
      break;

    case NETWORK_MODE:
      insert_in_text (corrected_line, params->network, line_counter);
      break;
      
    case NODE_MODE:
      insert_in_text (corrected_line, params->node, line_counter);
      break;
      
    case MACHINE_MODE:
      insert_in_text (corrected_line, params->machine, line_counter);
      break;

    case OUTFILE_MODE:
      insert_in_text (corrected_line, params->out_file, line_counter);
      break;
      
    case LOGFILE_MODE:
      insert_in_text (corrected_line, params->log_file, line_counter);
      break;
      
    case MEASUREMENTS_MODE:
      insert_in_text (corrected_line, params->measurements, 
		      measurements_line_counter++);
      break;
      
    case MPILIB_NAME_MODE:
      insert_in_text (corrected_line, params->mpilib_name, line_counter);
      break;
      
    case ITERS_PER_MODE:
      params->iters_per_time_default = atoi (corrected_line);
      if (params->iters_per_time_default == 0)
      {
	params->iters_per_time_default = ITERS_PER_DEFAULT;
        sprintf (_sphinx_msg,"error parsing iters per rep,\n"\
		 "iterations per repetition set to default value: %d.", 
		 ITERS_PER_DEFAULT);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;

    case OVERLAP_MAX_MODE:
      params->overlap_default = atoi (corrected_line);
      if (params->overlap_default == 0)
      {
	params->overlap_default = DEF_OVERLAP_VALUE;
        sprintf (_sphinx_msg,"error parsing overlap maximum,\n"\
		 "overlap maximum set to default value: %d.", 
		 DEF_OVERLAP_VALUE);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;

    case VARIATION_MODE:
      if (strstr_ignore_case  (corrected_line, "LEN")!=NULL)
      {
        params->variation_default = LENGTH;
      } 
      else if (strstr_ignore_case (corrected_line, "NOD")!=NULL)
      {
        params->variation_default = NODES;
      }
      /* this needs to be before "CHUNKS" or it matches that... */
      else if (strstr_ignore_case (corrected_line, "SCHED")!=NULL)
      {
	if (strstr_ignore_case (corrected_line, "CAP")!=NULL)
	  params->variation_default = SCHED_CAP;
	else if (strstr_ignore_case (corrected_line, "_CHU")!=NULL)
	  params->variation_default = SCHED_CHUNKS;
	else
	  params->variation_default = SCHEDULE;
      }
      else if (strstr_ignore_case (corrected_line, "CHUN")!=NULL)
      {
        params->variation_default = CHUNK;
      }
      else if ((strstr_ignore_case (corrected_line, "NO_V")!=NULL) ||
	       (strstr_ignore_case (corrected_line, "NOV")!=NULL))
      {
        params->variation_default = NO_VARIATION;
      }
      else if (strstr_ignore_case (corrected_line, "ITER")!=NULL)
      {
        params->variation_default = ITERS;
      }
      else if (strstr_ignore_case (corrected_line, "MAST")!=NULL)
      {
        params->variation_default = MASTER_BINDING;
      }
      else if (strstr_ignore_case (corrected_line, "SLAV")!=NULL)
      {
        params->variation_default = SLAVE_BINDING;
      }
      else if (strstr_ignore_case (corrected_line, "ACK")!=NULL)
      {
        params->variation_default = ACKER;
      }
      else if (strstr_ignore_case (corrected_line, "ROO")!=NULL)
      {
        params->variation_default = ROOT;
      }
      else if (strstr_ignore_case (corrected_line, "OVERL")!=NULL)
      {
	if ((strstr_ignore_case (corrected_line, "MP")!=NULL) ||
	    (strstr_ignore_case(tokens[j], "OP")!=NULL) ||
	    (strstr_ignore_case(tokens[j], "FUNC")!=NULL))
	  params->variation_default = OVERLAP_FUNCTION;
	else if (strstr_ignore_case (corrected_line, "SEC")!=NULL)
	  params->variation_default = SECOND_OVERLAP;
	else
	  params->variation_default = OVERLAP;
      }
      else if (strstr_ignore_case (corrected_line, "THR")!=NULL)
      {
        params->variation_default = THREADS;
      }
      else if (strstr_ignore_case (corrected_line, "WORK")!=NULL)
      {
	if (strstr_ignore_case (corrected_line, "A")!=NULL)
	  params->variation_default = WORK_AMOUNT;
	else
	  params->variation_default = WORK_FUNCTION;
      }
      else
      {
        params->variation_default = NO_VARIATION;
        sprintf (_sphinx_msg,"error parsing variation,\n"\
                 "variation set to default value: %d.",
                 NO_VARIATION);
        ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }

      for (i=0; i<MAX_DIMENSIONS; i++)
      {
        params->dimensions_defaults[i].variation = params->variation_default;
      }
      break;
    case SCALE_MODE:
      if (strstr_ignore_case(corrected_line, "F")!=NULL)
      {
	if (strstr_ignore_case(corrected_line, "IN")!=NULL)
	{
	  params->scale_default = FIXED_LIN;
	}
	else if (strstr_ignore_case(corrected_line, "OG")!=NULL)
	{
	  params->scale_default = FIXED_LOG;
	}
	else
	/* if (params->scale_default == 0) */
	{
	  params->scale_default = FIXED_LIN;
	  sprintf (_sphinx_msg,"error parsing scale,\n"\
		   "scale set to default value: %d.",
		   FIXED_LIN);
	  ERROR(USER,_sphinx_msg);
	  output_error (FALSE);
	}
      }
      else if (strstr_ignore_case(corrected_line, "DY")!=NULL)
      {
	if (strstr_ignore_case(corrected_line, "IN")!=NULL)
	{
	  params->scale_default = DYN_LIN;
	}
	else if (strstr_ignore_case(corrected_line, "OG")!=NULL)
	{
	  params->scale_default = DYN_LOG;
	}
	else
	/* if (params->scale_default == 0) */
	{
	  params->scale_default = FIXED_LIN;
	  sprintf (_sphinx_msg,"error parsing scale,\n"\
		   "scale set to default value: %d.",
		   FIXED_LIN);
	  ERROR(USER,_sphinx_msg);
	  output_error (FALSE);
	}
      }
      else
      /* if (params->scale_default == 0) */
      {
        params->scale_default = FIXED_LIN;
        sprintf (_sphinx_msg,"error parsing scale,\n"\
                 "scale set to default value: %d.",
                 FIXED_LIN);
        ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }

      for (i=0; i<MAX_DIMENSIONS; i++)
      {
        params->dimensions_defaults[i].scale = params->scale_default;
      }
      break;
    case CHUNKS_MODE:
      params->chunks_default = atoi (corrected_line);
      if (params->chunks_default == 0)
      {
        params->chunks_default = DEF_CHUNKS;
        sprintf (_sphinx_msg,"error parsing chunks,\n"\
                 "chunks set to default value: %d.",
                 DEF_CHUNKS);
        ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;
    case MESSAGE_LEN_MODE:
      my_int_or_max (corrected_line, &params->message_len_default);
      if (params->message_len_default == 0)
      {
        params->message_len_default = DEF_MESSAGE_LEN;
        sprintf (_sphinx_msg,"error parsing message len,\n"\
                 "message len set to default value: %d.",
                 DEF_MESSAGE_LEN);
        ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;
    case START_MODE:
      my_int_or_min (corrected_line, &params->start_default);
      if (params->start_default == 0)
      {
        params->start_default = MIN_ARGUMENT;
        sprintf (_sphinx_msg,"error parsing start,\n"\
                 "start set to default value: %d.",
                 MIN_ARGUMENT);
        ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      else
      {
        for (i=0; i<MAX_DIMENSIONS; i++)
        {
          params->dimensions_defaults[i].start = params->start_default;
        }
      }
      break;
    case END_MODE:
      my_int_or_max (corrected_line, &params->end_default);
      if (params->end_default == 0)
      {
        params->end_default = MAX_ARGUMENT;
        sprintf (_sphinx_msg,"error parsing end,\n"\
                 "end set to default value: %d.",
                 MAX_ARGUMENT);
        ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      else
      { 
        for (i=0; i<MAX_DIMENSIONS; i++)
        {
          params->dimensions_defaults[i].end = params->end_default;
        }
      }
      break;
    case STEPWIDTH_MODE:
      params->stepwidth_default = atoi (corrected_line);
      if (params->stepwidth_default == 0)
      {
        params->stepwidth_default = STEPWIDTH_DEFAULT;
        sprintf (_sphinx_msg,"error parsing stepwidth,\n"\
                 "stepwidth set to default value: %f.",
                 STEPWIDTH_DEFAULT);
        ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      else
      { 
        for (i=0; i<MAX_DIMENSIONS; i++)
        {
          params->dimensions_defaults[i].stepwidth = params->stepwidth_default;
        }
      }
      break;
    case MAX_STEPS_MODE:
      params->max_steps_default = atoi (corrected_line);
      if (params->max_steps_default == 0)
      {
        params->max_steps_default = MAX_STEPS_DEFAULT;
        sprintf (_sphinx_msg,"error parsing max steps,\n"\
                 "max steps set to default value: %d.",
                 DEFAULT);
        ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      else
      { 
        for (i=0; i<MAX_DIMENSIONS; i++)
        {
          params->dimensions_defaults[i].max_steps = params->max_steps_default;
        }
      }
      break;
    case MIN_DIST_MODE:
      params->min_dist_default = atoi (corrected_line);
      if (params->min_dist_default == 0)
      {
        params->min_dist_default = MIN_DIST_DEFAULT;
        sprintf (_sphinx_msg,"error parsing min dist,\n"\
                 "min dist set to default value: %d.",
                 MIN_DIST_DEFAULT);
        ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      else
      { 
        for (i=0; i<MAX_DIMENSIONS; i++)
        {
          params->dimensions_defaults[i].min_dist = params->min_dist_default;
        }
      }
      break;
    case MAX_DIST_MODE:
      params->max_dist_default = atoi (corrected_line);
      if (params->max_dist_default == 0)
      {
        params->max_dist_default = MAX_DIST_DEFAULT;
        sprintf (_sphinx_msg,"error parsing max dist,\n"\
                 "max dist set to default value: %d.",
                 MAX_DIST_DEFAULT);
        ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      else
      {
        for (i=0; i<MAX_DIMENSIONS; i++)
        {
          params->dimensions_defaults[i].max_dist = params->max_dist_default;
        }
      }
      break;
    case DIMENSIONS_COUNT_MODE:
      params->dimensions_count_default = atoi (corrected_line);
      break; 
    case VARIATION_LIST_MODE:
      tokens[0] = strtok (corrected_line, " ");
      for (i=1; ((tokens[i] = strtok (NULL, " "))!=NULL); i++)
      ; 
      for (j=0; j<i; j++)
      {
        params->dimensions_defaults[j].variation = atoi(tokens[j]);

        if (strstr_ignore_case(tokens[j], "LEN")!=NULL)
        {
          params->dimensions_defaults[j].variation = LENGTH;
        }
        else if (strstr_ignore_case(tokens[j], "NOD")!=NULL)
        {
          params->dimensions_defaults[j].variation = NODES;
        }
	/* this needs to be before "CHUNKS" or it matches that... */
	else if (strstr_ignore_case (corrected_line, "SCHED")!=NULL)
        {
	  if (strstr_ignore_case (corrected_line, "CAP")!=NULL)
	    params->dimensions_defaults[j].variation = SCHED_CAP;
	  else if (strstr_ignore_case (corrected_line, "CHU")!=NULL)
	    params->dimensions_defaults[j].variation = SCHED_CHUNKS;
	  else
	    params->dimensions_defaults[j].variation = SCHEDULE;
	}
        else if (strstr_ignore_case(tokens[j], "CHUN")!=NULL)
        {
          params->dimensions_defaults[j].variation = CHUNK;
        }
        else if ((strstr_ignore_case(tokens[j], "NO_V")!=NULL) ||
		 (strstr_ignore_case(tokens[j], "NOV")!=NULL))
        {
          params->dimensions_defaults[j].variation = NO_VARIATION;
        }
        else if (strstr_ignore_case(tokens[j], "ITER")!=NULL)
        {
          params->dimensions_defaults[j].variation = ITERS;
        }
        else if (strstr_ignore_case(tokens[j], "MAST")!=NULL)
        {
          params->dimensions_defaults[j].variation = MASTER_BINDING;
        }
        else if (strstr_ignore_case(tokens[j], "SLAV")!=NULL)
        {
          params->dimensions_defaults[j].variation = SLAVE_BINDING;
        }
        else if (strstr_ignore_case(tokens[j], "ACK")!=NULL)
        {
          params->dimensions_defaults[j].variation = ACKER;
        }
        else if (strstr_ignore_case(tokens[j], "ROO")!=NULL)
        {
          params->dimensions_defaults[j].variation = ROOT;
        }
        else if (strstr_ignore_case(tokens[j], "OVERL")!=NULL)
        {
	  if ((strstr_ignore_case(tokens[j], "MP")!=NULL) ||
	      (strstr_ignore_case(tokens[j], "OP")!=NULL) ||
	      (strstr_ignore_case(tokens[j], "FUNC")!=NULL))
	    params->dimensions_defaults[j].variation = OVERLAP_FUNCTION;
	  else if (strstr_ignore_case(tokens[j], "SEC")!=NULL)
	    params->dimensions_defaults[j].variation = SECOND_OVERLAP;
	  else
	    params->dimensions_defaults[j].variation = OVERLAP;
        }
        else if (strstr_ignore_case(tokens[j], "THR")!=NULL)
        {
          params->dimensions_defaults[j].variation = THREADS;
        }
	else if (strstr_ignore_case (corrected_line, "WORK")!=NULL)
	{
	  if (strstr_ignore_case (corrected_line, "A")!=NULL)
	    params->dimensions_defaults[j].variation = WORK_AMOUNT;
	  else
	    params->dimensions_defaults[j].variation = WORK_FUNCTION;
	}
        else
        {
          params->dimensions_defaults[j].variation = NO_VARIATION;
          sprintf (_sphinx_msg,"error parsing variation,\n"\
                   "variation set to default value: %d.",
                   NO_VARIATION);
          ERROR(USER,_sphinx_msg);
	  output_error (FALSE);
        }
      }
      break;
    case SCALE_LIST_MODE:
      tokens[0] = strtok (corrected_line, " ");
      for (i=1; ((tokens[i] = strtok (NULL, " "))!=NULL); i++)
      ;
      for (j=0; j<i; j++)
      {
        params->dimensions_defaults[j].scale = atoi(tokens[j]);

        if (strstr_ignore_case(tokens[j], "F")!=NULL)
        {
	  if (strstr_ignore_case(tokens[j], "IN")!=NULL)
	  {
	    params->dimensions_defaults[j].scale = FIXED_LIN;
	  }
	  else if (strstr_ignore_case(tokens[j], "OG")!=NULL)
	  {
	    params->dimensions_defaults[j].scale = FIXED_LOG;
	  }
	  else
	  {
	    params->dimensions_defaults[j].scale = FIXED_LIN;
	    sprintf (_sphinx_msg,"error parsing scale,\n"\
		     "scale set to default value: %d.",
		     FIXED_LIN);
	    ERROR(USER,_sphinx_msg);
	    output_error(FALSE);
	  }
	}
        else if (strstr_ignore_case(tokens[j], "DY")!=NULL)
        {
	  if (strstr_ignore_case(tokens[j], "IN")!=NULL)
	  {
	    params->dimensions_defaults[j].scale = DYN_LIN;
	  }
	  else if (strstr_ignore_case(tokens[j], "OG")!=NULL)
	  {
	    params->dimensions_defaults[j].scale = DYN_LOG;
	  }
	  else
	  {
	    params->dimensions_defaults[j].scale = FIXED_LIN;
	    sprintf (_sphinx_msg,"error parsing scale,\n"\
		     "scale set to default value: %d.",
		     FIXED_LIN);
	    ERROR(USER,_sphinx_msg);
	    output_error(FALSE);
	  }
	}
        else
        {
          params->dimensions_defaults[j].scale = FIXED_LIN;
          sprintf (_sphinx_msg,"error parsing scale,\n"\
                   "scale set to default value: %d.",
                   FIXED_LIN);
          ERROR(USER,_sphinx_msg);
	  output_error(FALSE);
        }
      }
      break;
    case START_LIST_MODE:
      tokens[0] = strtok (corrected_line, " ");
      for (i=1; ((tokens[i] = strtok (NULL, " "))!=NULL); i++)
      ;
      for (j=0; j<i; j++)
      {
        my_int_or_min(tokens[j],
		      &(params->dimensions_defaults[j].start));
      }
      break;
    case END_LIST_MODE:
      tokens[0] = strtok (corrected_line, " ");
      for (i=1; ((tokens[i] = strtok (NULL, " "))!=NULL); i++)
      ;
      for (j=0; j<i; j++)
      {
        my_int_or_max(tokens[j],
		      &(params->dimensions_defaults[j].end));
      }
      break;
    case STEPWIDTH_LIST_MODE:
      tokens[0] = strtok (corrected_line, " ");
      for (i=1; ((tokens[i] = strtok (NULL, " "))!=NULL); i++)
      ;
      for (j=0; j<i; j++)
      {
        params->dimensions_defaults[j].stepwidth = atof(tokens[j]);
      }
      break;
    case MAX_STEPS_LIST_MODE:
      tokens[0] = strtok (corrected_line, " ");
      for (i=1; ((tokens[i] = strtok (NULL, " "))!=NULL); i++)
      ;
      for (j=0; j<i; j++)
      {
        params->dimensions_defaults[j].max_steps = atoi(tokens[j]);
      }
      break;
    case MIN_DIST_LIST_MODE:
      tokens[0] = strtok (corrected_line, " ");
      for (i=1; ((tokens[i] = strtok (NULL, " "))!=NULL); i++)
      ;
      for (j=0; j<i; j++)
      {
        params->dimensions_defaults[j].min_dist = atoi(tokens[j]);
      }
      break;
    case MAX_DIST_LIST_MODE:
      tokens[0] = strtok (corrected_line, " ");
      for (i=1; ((tokens[i] = strtok (NULL, " "))!=NULL); i++)
      ;
      for (j=0; j<i; j++)
      {
        params->dimensions_defaults[j].max_dist = atoi(tokens[j]);
      }
      break;
      
    case THREADS_DEFAULT_MODE:
      params->threads_default = atoi (corrected_line);
      if (params->threads_default == 0)
      {
	params->threads_default = MAX_ARGUMENT;
        sprintf (_sphinx_msg,"error parsing default number of threads,\n"\
		 "default number of threads set to default value");
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;
      
    case WORK_AMOUNT_DEFAULT_MODE:
      params->work_amt_default = atoi (corrected_line);
      if (params->work_amt_default == 0)
      {
	params->work_amt_default = DEFAULT_WORK_AMOUNT;
        sprintf (_sphinx_msg,"error parsing default work amount,\n"\
		 "default work amount set to default value: %d",
		 DEFAULT_WORK_AMOUNT);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;
      
    case WORK_FUNC_DEFAULT_MODE:
      params->work_function_default = work_func (corrected_line);
      if ((params->work_function_default < 0) ||
	  (params->work_function_default >= WORK_FUNCTION_COUNT))
      {
	params->work_function_default = DEFAULT_WORK_FUNCTION;
        sprintf (_sphinx_msg,"error parsing default work function,\n"\
		 "default work function set to default value: %s",
		 translate_work_function(DEFAULT_WORK_FUNCTION));
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;
      
      
    case OVERLAP_FUNC_DEFAULT_MODE:
      params->overlap_function_default = overlap_func (corrected_line);
      if ((params->overlap_function_default < 0) ||
	  (params->overlap_function_default >= OMP_OVERLAP_FUNCTION_COUNT))
      {
	params->overlap_function_default = DEFAULT_OVERLAP_FUNCTION;
        sprintf (_sphinx_msg,"error parsing default overlap function,\n"\
		 "default overlap function set to default value: %s",
		 translate_overlap_function(DEFAULT_OVERLAP_FUNCTION));
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;
      
    case SCHED_CAP_DEFAULT_MODE:
      params->schedule_cap_default = atoi (corrected_line);
      if (params->schedule_cap_default == 0)
      {
	params->schedule_cap_default = DEFAULT_SCHEDULE_CAP;
        sprintf (_sphinx_msg,"error parsing default schedule cap,\n"\
		 "default schedule cap set to default value: %s",
		 translate_omp_schedule(DEFAULT_SCHEDULE_CAP));
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;
      
    case SCHED_CHUNKS_DEFAULT_MODE:
      params->schedule_chunks_default = atoi (corrected_line);
      if (params->schedule_chunks_default == 0)
      {
	params->schedule_chunks_default = DEFAULT_SCHEDULE_CHUNKS;
        sprintf (_sphinx_msg,"error parsing default schedule chunks,\n"\
		 "default schedule chunks set to default value: %d",
		 DEFAULT_SCHEDULE_CHUNKS);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;
      
    case SCHED_DEFAULT_MODE:
      params->loop_schedule_default = omp_sched (corrected_line);
      if ((params->loop_schedule_default < 0) ||
	  (params->loop_schedule_default >= SCHEDULE_COUNT))
      {
	params->loop_schedule_default = DEFAULT_LOOP_SCHEDULE;
        sprintf (_sphinx_msg,"error parsing default loop schedule,\n"\
		 "default loop schedule set to default value: %d",
		 DEFAULT_LOOP_SCHEDULE);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);
      }
      break;
      
    default:
      ERROR (USER,"invalid mode");
      output_error (FALSE);
      return (NULL);
    }
  }

  free_text (the_file);

  return (params);
}


char *skip_mode (char *string)
{
  char *temp;

  /* get to start of mode */
  for (temp = string; (*temp != '@') && (*temp != '\0'); temp++) /* NULL */ ;

  if (*temp == '\0') {
    sprintf (_sphinx_msg,"No mode found: %s", string);
    ERROR(USER,_sphinx_msg);
    output_error(FALSE);

    return NULL;
  }

  /* get past mode */
  for (/* NULL */; (*temp != ' ') && (*temp != '\0'); temp++) /* NULL */ ;

  return temp;
}

/*
   @FUN:
   @DOES: analyzes *line and evtl. sets *mode to a new found mode.
   @PARAMETERS: above.
   @RETURNES: a pointer to the line (without the keyword).
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
char *
line_mode (char *line, int *mode)
{
  if (strstr_ignore_case(line,"@USE") != NULL)
    *mode = USER_MODE;
  else if (strstr_ignore_case(line,"@MEM") != NULL)
    *mode = MEM_MODE;
  else if (strstr_ignore_case(line,"@MAX") != NULL) {
    if (strstr_ignore_case(line,"REP") != NULL)
      *mode = MAX_REP_MODE;
    else if (strstr_ignore_case(line,"STEP") != NULL)
      if (strstr_ignore_case(line,"LIS") != NULL)
	*mode = MAX_STEPS_LIST_MODE;
      else
	*mode = MAX_STEPS_MODE;
    else if (strstr_ignore_case(line,"DIS") != NULL) 
      if (strstr(line,"LIS") != NULL)
	*mode = MAX_DIST_LIST_MODE;
      else
	*mode = MAX_DIST_MODE;
    else if (strstr_ignore_case(line,"OVER") != NULL) 
      *mode = OVERLAP_MAX_MODE;
    else {
      sprintf (_sphinx_msg,"Unknown mode: %s"\
	       "treating as line with no @",
	       line);
      ERROR(USER,_sphinx_msg);
      output_error(FALSE);
      *mode = NO_MODE;
      return (line);
    }
  }  
  else if (strstr_ignore_case(line,"@MIN") != NULL) {
    if (strstr_ignore_case(line,"REP") != NULL)
      *mode = MIN_REP_MODE;
    else if (strstr_ignore_case(line,"DIS") != NULL) 
      if (strstr(line,"LIS") != NULL)
	*mode = MIN_DIST_LIST_MODE;
      else
	*mode = MIN_DIST_MODE;
    else {
      sprintf (_sphinx_msg,"Unknown mode: %s"\
	       "treating as line with no @",
	       line);
      ERROR(USER,_sphinx_msg);
      output_error(FALSE);
      *mode = NO_MODE;
      return (line);
    }
  }  
  else if ((strstr_ignore_case(line,"@STAND") != NULL) ||
	   (strstr_ignore_case(line,"@STD") != NULL) ||
	   (strstr_ignore_case(line,"@DEV") != NULL))
    *mode = STANDARD_DEVIATION_MODE;
  else if (strstr_ignore_case(line,"@POST") != NULL)
    *mode = POST_MODE;
  else if ((strstr_ignore_case(line,"@ABS") != NULL) ||
	   (strstr_ignore_case(line,"@COR") != NULL) ||
	   (strstr_ignore_case(line,"@OVERH") != NULL))
    *mode = CORRECT_MS_MODE;
  else if (strstr_ignore_case(line,"@NET") != NULL)
    *mode = NETWORK_MODE;
  else if (strstr_ignore_case(line,"@NOD") != NULL)
    *mode = NODE_MODE;
  else if (strstr_ignore_case(line,"@MACH") != NULL)
    *mode = MACHINE_MODE;
  else if (strstr_ignore_case(line,"@COM") != NULL)
    *mode = COMMENT_MODE;
  else if (strstr_ignore_case(line,"@OUT") != NULL)
    *mode = OUTFILE_MODE;
  else if (strstr_ignore_case(line,"@LOG") != NULL)
    *mode = LOGFILE_MODE;
  else if (strstr_ignore_case(line,"@MEAS") != NULL)
    *mode = MEASUREMENTS_MODE;
  else if (strstr_ignore_case(line,"@MPI") != NULL)
    *mode = MPILIB_NAME_MODE;
  else if (strstr_ignore_case(line,"@ITER") != NULL)
    *mode = ITERS_PER_MODE;
  else if (strstr_ignore_case(line,"@VAR") != NULL)
    if (strstr_ignore_case(line,"LIS") != NULL)
      *mode = VARIATION_LIST_MODE;
    else
      *mode = VARIATION_MODE;
  else if (strstr_ignore_case(line,"@DIM") != NULL)
    *mode = DIMENSIONS_COUNT_MODE;
  else if (strstr_ignore_case(line,"@SCA") != NULL)
    if (strstr_ignore_case(line,"LIS") != NULL) 
      *mode = SCALE_LIST_MODE;
    else  
      *mode = SCALE_MODE;
  else if (strstr_ignore_case(line,"@CHUN") != NULL)
    *mode = CHUNKS_MODE;
  else if ((strstr_ignore_case(line,"@MES") != NULL) ||
	   (strstr_ignore_case(line,"@MSG") != NULL))
    *mode = MESSAGE_LEN_MODE;
  else if (strstr_ignore_case(line,"@STAR") != NULL)
    if (strstr_ignore_case(line,"LIS") != NULL)
      *mode = START_LIST_MODE;
    else
      *mode = START_MODE;
  else if (strstr_ignore_case(line,"@END") != NULL)
    if (strstr_ignore_case(line,"LIS") != NULL)
      *mode = END_LIST_MODE;
    else
      *mode = END_MODE;
  else if (strstr_ignore_case(line,"@STEPW") != NULL)
    if (strstr_ignore_case(line,"LIS") != NULL)
      *mode = STEPWIDTH_LIST_MODE;
    else
      *mode = STEPWIDTH_MODE;
  else if (strstr_ignore_case(line,"@THR") != NULL)
    *mode = THREADS_DEFAULT_MODE;
  else if (strstr_ignore_case(line,"@WORK") != NULL)
    if (strstr_ignore_case(line,"A") != NULL)
      *mode = WORK_AMOUNT_DEFAULT_MODE;
    else
      *mode = WORK_FUNC_DEFAULT_MODE;
  else if ((strstr_ignore_case(line,"@OVERL") != NULL) ||
	   (strstr_ignore_case(line,"@OMP") != NULL) ||
	   (strstr_ignore_case(line,"@OPENMP") != NULL))
    /* THIS WILL NEED TO CHANGE IF RETAIN OLD OVERLAP MECHANISM IN */
    /* WHICH CASE WE NEED TO BE ABLE TO SPECIFY DEFAULTS FOR IT... */
    *mode = OVERLAP_FUNC_DEFAULT_MODE;
  else if (strstr_ignore_case(line,"@SCHED") != NULL)
    if (strstr_ignore_case(line,"CAP") != NULL)
      *mode = SCHED_CAP_DEFAULT_MODE;
    else if (strstr_ignore_case(line,"CHU") != NULL)
      *mode = SCHED_CHUNKS_DEFAULT_MODE;
    else
      *mode = SCHED_DEFAULT_MODE;      
  else {
    if (strstr(line,"@") != NULL) {
      sprintf (_sphinx_msg,"Unknown mode: %s"\
	       "treating as line with no @",
	       line);
      ERROR(USER,_sphinx_msg);
      output_error(FALSE);
    }
    *mode = NO_MODE;
    return (line);
  }

  return (skip_mode (line));
}


/*
   @FUN:
   @DOES: counts the number of measurements stored in text (uses that
   each measurement has one opening bracket \{ exactly). 
   @PARAMETERS:
   @RETURNES:
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
count_measurements (text_t text)  
{
  int
    i,
    counter;

  for (counter = i = 0; text[i] != NULL; i++)
    if (strstr (text[i], "{") != NULL)
      counter++;

  return (counter);
} /* }}  just for the script funlen.pl, which is confused seeing only opening 
     brackets 
     */
#ifndef NO_MPI


/*
   @FUN:
   @DOES: sends a text to all other processes in default_communicator,
   process zero is root.
   @PARAMETERS: the text to send.
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: default_communicator set.
*/
void
send_text (text_t text)
{
  int comm_size;

  MPI_Comm_size (default_communicator, &comm_size);

  /* done by defintion of MPI_Bcast if only task... */
  if (comm_size != 1) {
    int i, max_size, pos, last, len;
    char *buf;

    MPI_Pack_size (TEXT_LINES + 1, MPI_INT, default_communicator, &max_size);
    MPI_Pack_size (TEXT_LINES * MAX_LINE_LEN, MPI_CHAR, 
		   default_communicator, &pos);
    max_size += pos;

    buf = (char *) malloc (sizeof(char) * max_size);

    for (last = 0; text[last] != NULL; last++) ;

    pos = 0;

    MPI_Pack (&last, 1, MPI_INT, buf, max_size, &pos, default_communicator); 

    for (i = 0; text[i] != NULL; i++) {
      len = strlen (text[i]) + 1;

      MPI_Pack (&len, 1, MPI_INT, buf, max_size, &pos, default_communicator); 

      MPI_Pack (text[i], len, MPI_CHAR, buf, max_size, 
		&pos, default_communicator); 
    }

    MPI_Bcast (&pos, 1, MPI_INT, 0, default_communicator);
    MPI_Bcast (buf, pos, MPI_PACKED, 0, default_communicator);

    free (buf);
  }

  return;
}

/*
   @FUN:
   @DOES: receives the text which has been send via send_text.
   (process zero in default communicator is root.)
   Note: the text_t-struct has to be allocated, not the memory for
   all the strings, this is done here.
   @PARAMETERS: above.
   @RETURNS: number of lines received in structure
   @SIDEEFFECTS: none.
   @ASSUMES: default_communicator set.
*/
int
recv_text (text_t text)
{
  int i, max_size, real_size, pos, last, len;
  char *buf;

  MPI_Pack_size (TEXT_LINES + 1, MPI_INT, default_communicator, &max_size);
  MPI_Pack_size (TEXT_LINES * MAX_LINE_LEN, MPI_CHAR, 
		 default_communicator, &pos);
  max_size += pos;

  buf = (char *) malloc (sizeof(char) * max_size);

  MPI_Bcast (&real_size, 1, MPI_INT, 0, default_communicator);
  MPI_Bcast (buf, real_size, MPI_PACKED, 0, default_communicator);

  pos = 0;

  MPI_Unpack (buf, max_size, &pos, &last, 1, MPI_INT, default_communicator);

  for (i = 0; i < last; i++) {
    MPI_Unpack (buf, max_size, &pos, &len, 1, MPI_INT, default_communicator);

    if ((text[i] = malloc (len)) == NULL) {
      ERROR(NO_MEM,"for parameters - 1");
      output_error (TRUE);
    }

    MPI_Unpack (buf, max_size, &pos, text[i], len, 
		MPI_CHAR, default_communicator);
  }

  text[i] = NULL;

  free (buf);

  return last;
}

#endif


omp_work_name_t 
work_func (char *string)
{
  if (strstr_ignore_case (string, "SIM")== NULL)
    return SIMPLE_WORK;

  if (strstr_ignore_case (string, "BOR")== NULL)
    return BORS_WORK;

  if (strstr_ignore_case (string, "SPI")== NULL)
    return SPIN_TIMED_WORK;

  if (strstr_ignore_case (string, "SLE")== NULL)
    return SLEEP_TIMED_WORK;

  return (omp_work_name_t) atoi (string);
}


omp_overlap_name_t 
overlap_func (char *string)
{
  if (strstr_ignore_case (string, "SEQ")== NULL)
    return OMP_SEQUENTIAL_OVERLAP;

  if (strstr_ignore_case (string, "PAR")== NULL)
    if (strstr_ignore_case (string, "FOR")== NULL)
      if (strstr_ignore_case (string, "CHU")== NULL)
	return OMP_PARALLEL_FOR_CHUNKS_OVERLAP;
      else 
	return OMP_PARALLEL_FOR_OVERLAP;
    else 
      return OMP_PARALLEL_OVERLAP;

  return (omp_overlap_name_t) atoi (string);
}


omp_schedule_t 
omp_sched (char *string)
{
  if (strstr_ignore_case (string, "STA")== NULL)
    return STATIC_SCHED;

  if (strstr_ignore_case (string, "DYN")== NULL)
    return DYNAMIC_SCHED;

  if (strstr_ignore_case (string, "GUI")== NULL)
    return GUIDED_SCHED;

  return (omp_schedule_t) atoi (string);
}



int 
isint (char *string)
{
  return (1);
}

int 
isfloat (char *string)
{
  return (1);
}

void 
my_int_or_default (char *source, int *target)
{
  if (strstr_ignore_case (source, "DEF")== NULL)
  {
    /* If not default_value set parameter */
    if (isint(source))
    {
      *target = (atoi)(source);
    }
    else 
    {
      sprintf (_sphinx_msg,
	       "my_int_or_default: Invalid value %s: Using default",
	       source);
      ERROR(USER,_sphinx_msg);
      output_error (TRUE);
    }
  }

  return;
}

void 
my_int_or_float (char *source, int *target)
{
  return;
}

void 
my_int_or_max (char *source, int *target)
{
  if (strstr_ignore_case (source, "MAX") != NULL)
  {
    *target = MAX_ARGUMENT;
  }
  else if (isint(source))
  {
    *target = atoi (source);
  }
  else
  {
    sprintf (_sphinx_msg,
	     "my_int_or_max: Invalid value %s: Using Max",
	     source);
    ERROR(USER,_sphinx_msg);
    output_error (TRUE);
    *target = MAX_ARGUMENT;
  }

  return;
}

void 
my_int_or_min (char *source, int *target)
{
  if (strstr_ignore_case (source, "MIN") != NULL)
  {
    *target = MIN_ARGUMENT;
  }
  else if (isint(source))
  {
    *target = atoi (source);
  }
  else
  {
    sprintf (_sphinx_msg,
	     "my_int_or_min: Invalid value %s: Using Min",
	     source);
    ERROR(USER,_sphinx_msg);
    output_error (TRUE);
    *target = MIN_ARGUMENT;
  }

  return;
}

void 
my_max_or_default (char *source, int *target)
{
  return;
}

void 
my_float_or_default (char *source, double *target)
{
  if (strstr_ignore_case (source, "DEF") == NULL)
  {
    /* If not default_value set parameter */
    if (isfloat(source))
    {
      *target = (atof)(source);
    }
    else
    {
      sprintf (_sphinx_msg,
	       "my_int_or_default: Invalid value %s: Using default",
	       source);
      ERROR(USER,_sphinx_msg);
      output_error (TRUE);
    }
  }

  return;
}

void 
my_variation_style (char *source, int *target)
{
  if (strstr_ignore_case (source, "LEN") != NULL)
  {
    *target = LENGTH;
  }
  else if (strstr_ignore_case (source, "NOD") != NULL)
  {
    *target = NODES;
  }
  /* this needs to be before "CHUNKS" or it matches that... */
  else if (strstr_ignore_case (source, "SCHED") != NULL)
  {
    if (strstr_ignore_case (source, "CAP") != NULL)
      *target = SCHED_CAP;
    else if (strstr_ignore_case (source, "CHU") != NULL)
      *target = SCHED_CHUNKS;
    else
      *target = SCHEDULE;
  }
  else if (strstr_ignore_case (source, "CHUN") != NULL)
  {
    *target = CHUNK;
  }
  else if ((strstr_ignore_case (source, "NO_V") != NULL) || 
	   (strstr_ignore_case (source, "NOV") != NULL))
  {
    *target = NO_VARIATION;
  }
  else if (strstr_ignore_case (source, "ITER") != NULL)
  {
    *target = ITERS;
  }
  else if (strstr_ignore_case (source, "MAST") != NULL)
  {
    *target = MASTER_BINDING;
  }
  else if (strstr_ignore_case (source, "SLAV") != NULL)
  {
    *target = SLAVE_BINDING;
  }
  else if (strstr_ignore_case (source, "ACK") != NULL)
  {
    *target = ACKER;
  }
  else if (strstr_ignore_case (source, "ROO") != NULL)
  {
    *target = ROOT;
  }
  else if (strstr_ignore_case (source, "OVERL") != NULL)
  {
    if ((strstr_ignore_case (source, "MP") != NULL) ||
	(strstr_ignore_case (source, "MP") != NULL))      
      *target = OVERLAP_FUNCTION;
    else if (strstr_ignore_case (source, "SEC") != NULL)
      *target = SECOND_OVERLAP;
    else
      *target = OVERLAP;
  }
  else if (strstr_ignore_case (source, "THR") != NULL)
  {
    *target = THREADS;
  }
  else if (strstr_ignore_case (source, "WORK") != NULL)
  {
    if (strstr_ignore_case (source, "A") != NULL)
      *target = WORK_AMOUNT;
    else
      *target = WORK_FUNCTION;
  }
  else
  { 
    sprintf (_sphinx_msg,
	     "my_variation_style: Invalid value %s: Using No_Variation",
	     source);
    ERROR(USER,_sphinx_msg);
    output_error (TRUE);
    *target = NO_VARIATION;
  }

  return;
}

void 
my_scale_style (char *source, int *target)
{
  if (strstr_ignore_case (source, "F") != NULL)
  {
    if (strstr_ignore_case (source, "IN") != NULL)
      *target = FIXED_LIN;
    else if (strstr_ignore_case (source, "OG") != NULL)
      *target = FIXED_LOG;
    else {
      sprintf (_sphinx_msg,
	       "my_scale_style: Invalid value %s: Using FIXED_LIN",
	       source);
      ERROR(USER,_sphinx_msg);
      output_error (TRUE);
      *target = FIXED_LIN;
    }
  }
  else if (strstr_ignore_case (source, "DY") != NULL)
  {
    if (strstr_ignore_case (source, "IN") != NULL)
      *target = DYN_LIN;
    else if (strstr_ignore_case (source, "OG") != NULL)
      *target = DYN_LOG;
    else {
      sprintf (_sphinx_msg,
	       "my_scale_style: Invalid value %s: Using DYN_LIN",
	       source);
      ERROR(USER,_sphinx_msg);
      output_error (TRUE);
      *target = DYN_LIN;
    }
  }
  else
  {
    sprintf (_sphinx_msg,
	     "my_scale_style: Invalid value %s: Using FIXED_LIN",
	     source);
    ERROR(USER,_sphinx_msg);
    output_error (TRUE);
    *target = FIXED_LIN;
  }

  return;
}

void 
my_initialize_measurement (measurement_t *measurement, params_t *params)
{
  int i;

  measurement->name = (char *) NULL;
  measurement->iters_over_nodes = FALSE;
  measurement->root = 0; /* default to using root of zero... */
  measurement->destroy = generic_destroy; /* cleanup aux_tests... */
  measurement->should_call_pattern = TRUE;
  measurement->dimensions_count = params->dimensions_count_default;
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    measurement->dimensions[i].variation = params->dimensions_defaults[i].variation;
    measurement->dimensions[i].scale = params->dimensions_defaults[i].scale;
    measurement->dimensions[i].start = params->dimensions_defaults[i].start;
    measurement->dimensions[i].end = params->dimensions_defaults[i].end;
    measurement->dimensions[i].stepwidth = params->dimensions_defaults[i].stepwidth;
    measurement->dimensions[i].max_steps = params->dimensions_defaults[i].max_steps;
    measurement->dimensions[i].min_dist = params->dimensions_defaults[i].min_dist;
    measurement->dimensions[i].max_dist = params->dimensions_defaults[i].max_dist;
  }
  measurement->max_rep = params->max_rep_default;
  measurement->min_rep = params->min_rep_default;
  def_chunks = params->chunks_default;
  def_len = params->message_len_default;
  def_threads = params->threads_default;
  def_work_amount = params->work_amt_default;
  def_schedule_cap = params->schedule_cap_default;
  def_schedule_chunks = params->schedule_chunks_default;

  def_work_function = params->work_function_default;
  def_overlap_function = params->overlap_function_default;
  def_loop_schedule = params->loop_schedule_default;

  measurement->standard_deviation = params->standard_deviation_default;

  measurement->uses_proxy = 0; /* False */
  measurement->need_to_create_proxy = 0; /* False */
  measurement->client_scope_and_detachedstate = 0; /* PROCESS SCOPE DETACHED */
  measurement->iter_cleanup = NULL;

  measurement->num_aux_tests = 0;
  measurement->aux_tests = NULL;

  measurement->correct_ms = params->correct;

  measurement->ACKer_OK = 0; /* FALSE */

  measurement->communicator = default_communicator;
  MPI_Comm_size (measurement->communicator, &measurement->nodes);

  measurement->iters_per_time = params->iters_per_time_default;
  measurement->overlap_iters = params->overlap_default;
  measurement->second_overlap_iters = params->overlap_default;

  measurement->use_reference_data = FALSE;
  measurement->have_omp_params = FALSE;
  measurement->pattern_in_omp_parallel = FALSE;

  return;
}

void 
initialize_omp_ms (measurement_t *ms)
{
  ms->have_omp_params = TRUE;
  ms->omp_data.thread_count = def_threads;
  ms->omp_data.work_amount = def_work_amount;
  ms->omp_data.which_work = def_work_function;
  ms->omp_data.which_overlap = def_overlap_function;
  ms->omp_data.cap_for_schedule_loops = def_schedule_cap;
  ms->omp_data.loop_schedule = def_loop_schedule;
  ms->omp_data.schedule_chunks = def_schedule_chunks;

  return;
}

void 
my_initialize_type (measurement_t *ms, int index)
{
  switch (index)
  {
  case 1:
    p2p_init_Send_Recv (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 2:
    p2p_init_Send_Recv_AT (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 3:
    p2p_init_Send_Irecv (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 4:
    p2p_init_Send_Iprobe_Recv (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 5:
    p2p_init_Ssend_Recv (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 6:
    p2p_init_Isend_Recv (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 7:
    p2p_init_Bsend_Recv (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 8:
    p2p_init_Sendrecv (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 9:
    p2p_init_Sendrecv_replace (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 10:
    mw_init_Waitsome (ms);
    ms->data.mw_data.len = def_len;
    ms->data.mw_data.def_nodes = def_nodes;
    ms->data.mw_data.chunks = def_chunks;
    break;
  case 11:
    mw_init_Waitany (ms);
    ms->data.mw_data.len = def_len;
    ms->data.mw_data.def_nodes = def_nodes;
    ms->data.mw_data.chunks = def_chunks;
    break; 
  case 12:
    mw_init_Recv_AS (ms);
    ms->data.mw_data.len = def_len;
    ms->data.mw_data.def_nodes = def_nodes;
    ms->data.mw_data.chunks = def_chunks;
    break;
  case 13:
    mw_init_Send (ms);
    ms->data.mw_data.len = def_len;
    ms->data.mw_data.def_nodes = def_nodes;
    ms->data.mw_data.chunks = def_chunks;
    break;
  case 14:
    mw_init_Ssend (ms);
    ms->data.mw_data.len = def_len;
    ms->data.mw_data.def_nodes = def_nodes;
    ms->data.mw_data.chunks = def_chunks;
    break;
  case 15:
    mw_init_Isend (ms);
    ms->data.mw_data.len = def_len;
    ms->data.mw_data.def_nodes = def_nodes;
    ms->data.mw_data.chunks = def_chunks;
    break;
  case 16:
    mw_init_Bsend (ms);
    ms->data.mw_data.len = def_len;
    ms->data.mw_data.def_nodes = def_nodes;
    ms->data.mw_data.chunks = def_chunks;
    break;
  case 17:
    col_init_Bcast (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 18:
    col_init_Barrier (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 19:
    col_init_Reduce (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 20:    
    col_init_Alltoall (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 21:
    col_init_Scan (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 22:  
    col_init_Comm_split (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 23:  
    col_init_memcpy (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 24:
    simple_init_Wtime (ms);
    break;
  case 25:
    simple_init_Comm_rank (ms);
    break;
  case 26:
    simple_init_Comm_size (ms);
    break;
  case 27:
    simple_init_Iprobe (ms);
    break;
  case 28:
    simple_init_attach (ms);
    break;
  case 29:
    p2p_init_dummy (ms);
    break;
  case 30:
    mw_init_dummy (ms);
    break;
  case 31:
    col_init_dummy (ms);
    break;
  case 32:
    simple_init_dummy (ms);
    break;
  case 33:    
    col_init_Gather (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 34:    
    col_init_Scatter (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 35:    
    col_init_Allgather (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 36:    
    col_init_Allreduce (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 37:    
    col_init_Gatherv (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 38:    
    col_init_Scatterv (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 39:    
    col_init_Allgatherv (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 40:    
    col_init_Alltoallv (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 41:    
    col_init_Reduce_scatter (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 42:    
    col_init_Bcast_barrier (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 43:    
    col_init_Bcast_send_latency (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 44:    
    col_init_Bcast_round (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 45:    
    col_init_Bcast_with_acks (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 46:    
    col_init_Bcast_with_ACKer (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 47:    
    col_init_Alltoall_barrier (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 48:    
    col_init_Gather_upper_bound (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 49:    
    col_init_Scatter_with_ACKer (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 50:    
    col_init_Allgather_barrier (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 51:    
    col_init_Allreduce_barrier (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 52:    
    col_init_Gatherv_upper_bound (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 53:    
    col_init_Scatterv_with_ACKer (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 54:    
    col_init_Allgatherv_barrier (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 55:    
    col_init_Alltoallv_barrier (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 56:    
    col_init_Red_scatter_barrier (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 57:
    col_init_Barrier_barrier (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 58:
    col_init_Reduce_upper_bound (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 59:
    col_init_over_nodes_dummy (ms);
    break;
  case 60:
    p2p_init_overlap (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 61:
    p2p_init_Isend_Recv_overlap (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 62:
    p2p_init_Isend_Recv_both_overlaps (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 63:
    p2p_init_Irecv_Send_overlap (ms);
    ms->data.p2p_data.len = def_len;
    ms->data.p2p_data.def_nodes = def_nodes;
    break;
  case 64:
    col_init_Reduce_scale (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 65:    
    col_init_Gather_scale (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 66:    
    col_init_Gatherv_scale (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 67:  
    col_init_Comm_dup_scale (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 68:  
    col_init_Comm_split_scale (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 69:  
    col_init_Comm_dup (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 70:    
    col_init_Scan_with_Acker (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 71:    
    col_init_Scan_send_latency (ms);
    ms->data.col_data.len = def_len;
    ms->data.col_data.def_nodes = def_nodes;
    break;
  case 101:
    simple_init_condition (ms);
    break;
  case 102:
    simple_init_cond_signal (ms);
    break;
  case 103:
    simple_init_cond_signal_no_client (ms);
    break;
  case 104:
    simple_init_cond_wait_testcancel (ms);
    break;
  case 105:
    simple_init_mutex_pingpong (ms);
    break;
  case 106:
    simple_init_mutex_pingpong_no_client (ms);
    break;
  case 107:
    simple_init_mutex_lock_unlock (ms);
    break;
  case 108:
    simple_init_timeslice (ms);
    break;
  case 109:
    thread_chain_init_thread_create (ms);
    break;
  case 110:
    simple_init_yield (ms);
    break;
  case 111:
    multitiming_init_lock_unlock (ms);
    break;
  case 112:
    simple_init_mutex_lock_unlock_2locks (ms);
    break;
  case 113:
    simple_init_mutex_lock_unlock_3locks (ms);
    break;
  case 114:
    simple_init_mutex_lock_unlock_5locks (ms);
    break;
  case 115:
    simple_init_mutex_lock_unlock_6locks (ms);
    break;
  case 116:
    simple_init_mutexarray_pingpong (ms);
    break;
  case 117:
    simple_init_mutexarray_pingpong_no_client (ms);
    break;
  case 118:
    multitiming_init_mutex_pingpong_noclient (ms);
    break;
  case 119:
    simple_init_mutex_lock_unlock_7locks (ms);
    break;
  case 120:
    simple_init_mutex_lock_unlock_8locks (ms);
    break;
  case 121:
    simple_init_mutex_lock_unlock_9locks (ms);
    break;
  case 122:
    simple_init_mutex_lock_unlock_10locks (ms);
    break;
  case 123:
    multitiming_init_mutex_lock_unlock (ms);
    break;
  case 124:
    simple_init_mutex_lock_unlock_twice (ms);
    break;
  case 125:
    simple_init_mutex_lock_unlock_thrice (ms);
    break;
  case 126:
    simple_init_mutex_lock_unlock_4times (ms);
    break;
  case 127:
    proxy_init_yield (ms);
    break;
  case 128:
    thread_chain_init_thread_create_sys (ms);
    break;
  case 129:
    thread_chain_init_thread_create_u (ms);
    break;
  case 130:
    thread_chain_init_thread_create_usys (ms);
    break;
  case 131:
    simple_init_inside_dummy (ms);
    break;


#ifdef _HAVE_OMP_

  case 201:
    simple_init_omp_parallel_ref (ms);
    break;
  case 202:
    simple_init_omp_parallel (ms);
    break;
  case 203:
    simple_init_omp_parallel_for_ref (ms);
    break;
  case 204:
    simple_init_omp_parallel_for (ms);
    break;
  case 205:
    simple_init_omp_parallel_for_chunks (ms);
    break;
  case 206:
    thread_chain_init_omp_ordered_ref (ms);
    break;
  case 207:
    thread_chain_init_omp_ordered_only (ms);
    break;
  case 208:
    thread_chain_init_omp_ordered (ms);
    break;
  case 209:
    thread_chain_init_omp_single_ref (ms);
    break;
  case 210:
    thread_chain_init_omp_single (ms);
    break;
  case 211:
    thread_chain_init_omp_barrier (ms);
    break;
  case 212:
    simple_init_omp_reduction_ref (ms);
    break;
  case 213:
    simple_init_omp_reduction (ms);
    break;
  case 214:
    simple_init_omp_atomic_ref (ms);
    break;
  case 215:
    thread_chain_init_omp_atomic (ms);
    break;

  case 301:
    col_init_mixed_omp_mpi_barrier (ms);
    break;
  case 302:
    col_init_mixed_omp_mpi_barrier_only (ms);
    break;
  case 303:
    col_init_mixed_omp_mpi_allreduce (ms);
    break;
  case 304:
    col_init_mixed_omp_mpi_allreduce_only (ms);
    break;
  case 305:
    col_init_mixed_omp_mpi_allreduce_barrier_only (ms);
    break;
  case 306:
    p2p_init_omp_overlap (ms);
    break;
  case 307:
    p2p_init_Isend_Recv_omp_overlap (ms);
    break;
  case 308:
    p2p_init_Isend_Recv_both_omp_overlaps (ms);
    break;
  case 309:
    p2p_init_Irecv_Send_omp_overlap (ms);
    break;

#endif /* _HAVE_OMP_ */


  default:
    printf ("my_initialize_type: Invalid value: %d\n", index);
    exit (1);
  }

  return;
}

/* originally names were just whatever the user supplied */
/* this has several problems - the worst is that names can */
/* be absolutely unrelated (even contradictory) to what is */
/* actually measured; it also created several weird problems */
/* when the user supplied duplicate names; what is really */
/* needed is a way to build a unique name from the measurement */
/* parameters, including consideration of previous measurement */
/* names; this way the user could be assured that the name */
/* reflects exactly what was measured and run multiple */
/* instances of exactly the same measurement... */
/* this function allows the user to reuse names without */
/* the weird errors; it's not ideal but is better than what was... */
void 
get_unique_ms_name (measurement_t *ms_array, int cur_index, char *user_name)
{
  int i, 
      previous_count = 0,
      name_untested = TRUE;

  /* this allows up to 999 occurences of the same name... */
  if ((ms_array[cur_index].name=(char *)malloc(strlen(user_name)+4))==NULL) {
    ERROR (NO_MEM,"no memory for the measurement name.");
    output_error (TRUE);
  }

  /* first try user supplied name */
  strcpy (ms_array[cur_index].name, user_name); 

  while (name_untested) {
    name_untested = FALSE;

    /* would like to assume a sphinx generated name doesn't */
    /* occur for in earlier names, but the user could duplicate one... */
    for (i = 0; i < cur_index; i++) {
      if (strcmp (ms_array[i].name, ms_array[cur_index].name) == 0) {
	/* old name and current candidate match... */
	if (previous_count == 1000) {
	  /* too many matches */
	  ERROR (USER,"too many uses of the same measurement name...");
	  output_error (FALSE);
	}
	else {
	  sprintf (ms_array[cur_index].name, "%s%d", 
		   user_name, previous_count);
	  previous_count++;
	  name_untested = TRUE;
	}

	break;
      }
    }
  }

  /* got a name that we will use... */
  return;
}

void 
my_parse (measurement_t *measurements_array, 
	  params_t *params, int *measurements_count)
{
  int i = 0;
  int line = 0;
  int j, k, long_line;
  char *tokens[100];
  int type, in_measurement = FALSE;
  int end_measurement = FALSE;

#ifdef MY_TEST_IO
  printf ("\nMeasurement number : %d\n", 0);
#endif
  
  /* Initialize first measurement */
  my_initialize_measurement (measurements_array, params);

#ifdef MY_TEST_IO
  printf ("\nMeasuremnt before parsing the input file:\n");    
  write_measurement_to_crt (measurements_array);
#endif

  /* While more lines in measurements and more measurements to fill... */
  while ((i < *measurements_count) && 
	 ((params->measurements)[line] != NULL)) {
    /* Parse the line into tokens */
    tokens[0] = strtok ((params->measurements)[line], " ;=");
    for (j=1; ((tokens[j]=strtok(NULL," ;="))!=NULL); j++)
      /* NULL */ ;

    if (tokens[0] != NULL) {
      /* line has content... */
      long_line = TRUE;

      if (!in_measurement) {
	/* either a name, a "{" or a stray line */
	if ((strstr ((params->measurements)[line+1], "{")==NULL) &&
	    (strcmp (tokens[0], "{")!=0) && 
	    ((tokens[1] == NULL) || (strcmp (tokens[1], "{")!=0))) {
	  /* then we consider it a stray line... */
	  /* better would be to eliminate all white space... */
	  sprintf (_sphinx_msg,
		   "Discarded stray line in input file: %s", 
		   (params->measurements)[line]);
	  ERROR(USER,_sphinx_msg);
	  output_error (FALSE);

	  long_line = FALSE;
	}
	else if (strcmp (tokens[0], "{")!=0) {
	  /* then we have a name */

	  get_unique_ms_name (measurements_array, i, tokens[0]);

	  if (tokens[1] != NULL) {
	    /* more than just name... */
	    for (k = 1; k <= j; k++) {
	      tokens[k-1] = tokens[k];
	    }

	    j--;
	  }
	  else {
	    /* name only line */
	    long_line = FALSE;
	  }
	}
	
	if (long_line) {
	  /* more than just name or starts with "{" */
	  if (strcmp (tokens[0], "{")==0) {
	    in_measurement = TRUE;

	    if (tokens[1] != NULL) {
	      for (k = 1; k <= j; k++) {
		tokens[k-1] = tokens[k];
	      }

	      j--;
	    }
	    else {
	      long_line = FALSE;
	    }
	  }
	  else {
	    /* garbled stuff following name... */
	    sprintf (_sphinx_msg,
		     "Discarded remainder of garbled line after name: %s", 
		     (params->measurements)[line]);
	    ERROR(USER,_sphinx_msg);
	    output_error (FALSE);

	    long_line = FALSE; /* FALSE */
	  }
	}
      }

      if ((long_line) && (!in_measurement)) {
	sprintf (_sphinx_msg,
		 "Discarded long_line not in_measurement: %s", 
		 (params->measurements)[line]);
	ERROR(USER,_sphinx_msg);
	output_error (FALSE);

	long_line = FALSE;
      }

      if ((long_line) && (strcmp (tokens[j-1], "}")==0)) {
	/* this line ends the measurement */
	in_measurement = FALSE;

	if (j == 1) {
	  /* no other content in line... */
	  long_line = FALSE;
	}
	else {
	  /* "forget" the "}" */
	  j--;
	}

	/* remember to finish up this measurement... */
	end_measurement = TRUE;
      }

      if (long_line) {
	/* line has measurement parameters... */
	if (strstr_ignore_case (tokens[0], "TYP") != NULL) {
	  type = atoi(tokens[1]);
	}
	else if (strstr_ignore_case (tokens[0], "MAX") != NULL) {
	  if (strstr_ignore_case (tokens[0], "REP") != NULL) {
	    my_int_or_default (tokens[1], 
			       &(measurements_array[i].max_rep));
	  }
	  else if (strstr_ignore_case (tokens[0], "STEP") != NULL) {
	    for (k=1; k<j; k++) {
	      my_int_or_default ((tokens[k]), 
			  &(measurements_array[i].dimensions[k-1].max_steps));
		
	      if (measurements_array[i].dimensions[k-1].max_steps <= 0) {
		ERROR(USER,
		      "Must have at least one step; making Max_Steps 1");
		output_error (FALSE);
		measurements_array[i].dimensions[k-1].max_steps = 1;
	      }
	    }
	      
	    if (measurements_array[i].dimensions_count < j - 1)
	      measurements_array[i].dimensions_count = j - 1;
	  }
	  else if (strstr_ignore_case (tokens[0], "DIST") != NULL) {
	    for (k=1; k<j; k++) {
	      measurements_array[i].dimensions[k-1].max_dist = 
		atoi (tokens[k]);
	    }
	    
	    if (measurements_array[i].dimensions_count < j - 1)
	      measurements_array[i].dimensions_count = j - 1;
	  }
	  else  {
	    sprintf (_sphinx_msg,
		     "Unrecognized line in input file: %s", 
		     (params->measurements)[line]);
	    ERROR(USER,_sphinx_msg);
	    output_error (FALSE);
	  }
	}
	else if (strstr_ignore_case (tokens[0], "MIN") != NULL) {
	  if (strstr_ignore_case (tokens[0], "REP") != NULL) {
	    my_int_or_default (tokens[1], 
			       &(measurements_array[i].min_rep));
	  }
	  else if (strstr_ignore_case (tokens[0], "DIST") != NULL) {
	    for (k=1; k<j; k++) {
	      measurements_array[i].dimensions[k-1].min_dist = 
		atoi (tokens[k]);
	    }

	    if (measurements_array[i].dimensions_count < j - 1)
	      measurements_array[i].dimensions_count = j - 1;
	  }
	  else  {
	    sprintf (_sphinx_msg,
		     "Unrecognized line in input file: %s", 
		     (params->measurements)[line]);
	    ERROR(USER,_sphinx_msg);
	    output_error (FALSE);
	  }
	}
	else if (strstr_ignore_case (tokens[0], "CHUN") != NULL) {
	  def_chunks = atoi (tokens[1]);
	}
	else if ((strstr_ignore_case (tokens[0], "MES") != NULL) ||
		 (strstr_ignore_case (tokens[0], "MSG") != NULL)) {
	  my_int_or_max (tokens[1], &def_len);
	}
	else if ((strstr_ignore_case (tokens[0], "STAND") != NULL) ||
		 (strstr_ignore_case (tokens[0], "STD") != NULL) ||
		 (strstr_ignore_case (tokens[0], "DEV") != NULL)) {
	  my_float_or_default (tokens[1], 
			       &(measurements_array[i].standard_deviation));
	}
	else if (strstr_ignore_case (tokens[0], "DIM") != NULL) {
	  measurements_array[i].dimensions_count = atoi(tokens[1]);
	}
	else if (strstr_ignore_case (tokens[0], "VAR") != NULL) {
	  for (k=1; k<j; k++) {
	    my_variation_style (tokens[k], 
				&(measurements_array[i].dimensions[k-1].variation));
	  }
	    
	  if (measurements_array[i].dimensions_count < j - 1)
	    measurements_array[i].dimensions_count = j - 1;
	}
	else if (strstr_ignore_case (tokens[0], "SCA") != NULL) {
	  for (k=1; k<j; k++) {
	    my_scale_style (tokens[k], 
			    &(measurements_array[i].dimensions[k-1].scale));
	  }
	      
	  if (measurements_array[i].dimensions_count < j - 1)
	    measurements_array[i].dimensions_count = j - 1;
	}
	else if (strstr_ignore_case (tokens[0], "STAR") != NULL) {
	  for (k=1; k<j; k++) {
	    my_int_or_min (tokens[k], 
			   &(measurements_array[i].dimensions[k-1].start));
	  }
	    
	  if (measurements_array[i].dimensions_count < j - 1)
	    measurements_array[i].dimensions_count = j - 1;
	}
	else if (strstr_ignore_case (tokens[0], "END") != NULL) {
	  for (k=1; k<j; k++) {
	    my_int_or_max (tokens[k],
			   &(measurements_array[i].dimensions[k-1].end));
	  }
	  
	  if (measurements_array[i].dimensions_count < j - 1)
	    measurements_array[i].dimensions_count = j - 1;
	}
	else if (strstr_ignore_case (tokens[0], "STEPW") != NULL) {
	  for (k=1; k<j; k++) {
	    measurements_array[i].dimensions[k-1].stepwidth = 
	      atof (tokens[k]);
	  }

	  if (measurements_array[i].dimensions_count < j - 1)
	    measurements_array[i].dimensions_count = j - 1;
	}
	else if ((strstr_ignore_case (tokens[0], "ABS") != NULL) ||
		 (strstr_ignore_case (tokens[0], "COR") != NULL) ||
		 (strstr_ignore_case (tokens[0], "OVER") != NULL)) {
	  measurements_array[i].dimensions_count = atoi(tokens[1]);
	}
	else  {
	  sprintf (_sphinx_msg,
		   "Unrecognized line in input file: %s", 
		   (params->measurements)[line]);
	  ERROR(USER,_sphinx_msg);
	  output_error (FALSE);
	}
      }
    }

    if (end_measurement) {
      end_measurement = FALSE;
      /* finish up the measurement ended by "}" on this line... */
#ifdef MY_TEST_IO
      printf ("\nMeasurement after parsing the input file:\n");
      write_measurement_to_crt (&(measurements_array[i]));
#endif
 
      my_initialize_type (&(measurements_array[i]), type);

      /* prepare for next measurement... */
      i++;

      if (i < *measurements_count) {
#ifdef MY_TEST_IO
	printf ("\nMeasurement number : %d\n", i);
#endif
  
	/* Initialize the measuremnts fields */
	my_initialize_measurement (&(measurements_array[i]), params);
	  
#ifdef MY_TEST_IO
	printf ("\nMeasuremnt before parsing the input file:\n");    
	write_measurement_to_crt (&(measurements_array[i]));
#endif
      }
    }

    line++;
  }

  if (i < *measurements_count) {
    sprintf (_sphinx_msg,
	     "Expected %d measurements, parsed only %d\n", 
	     *measurements_count, i);
    ERROR(USER,_sphinx_msg);
    output_error (FALSE);
  }

  while ((params->measurements)[line] != NULL) {
    /* Check for stray lines */
    tokens[0] = strtok ((params->measurements)[line], " ;=");

    if (tokens[0] != NULL) {
      /* line has content so we consider it a stray line... */
      sprintf (_sphinx_msg,
	       "Discarded stray line in input file: %s", 
	       (params->measurements)[line]);
      ERROR(USER,_sphinx_msg);
      output_error (FALSE);
    }

    line++;
  }
#ifdef MY_TEST_IO
  printf ("I counted %d measurements in the input\n", i);
#endif

  return;
}

void 
write_text_to_crt (char *s, text_t text)
{
  int i;

  printf ("%s: ", s);
  if (text[0] != NULL)
  {
    for (i=0; text[i]!=NULL; i++)
    {
      printf ("%s", text[i]);
    }
    printf ("\n");
  }
  else
  {
    printf ("\n");
  }

  return;
}


/* THIS DOESN'T PRINT THE OPENMP PARAMETERS... */
void 
write_params_to_crt (params_t *params)
{
  int i;

  write_text_to_crt ("user", params->user);
  printf ("memory: %u\n", params->memory);
  printf ("max_rep_default: %u\n", params->max_rep_default);
  printf ("min_rep_default: %u\n", params->min_rep_default);
  printf ("standard_deviation_default: %5.2f\n", params->standard_deviation_default);
  printf ("postproc: %d\n", params->post_proc);
  printf ("correct for overhead: %s\n", params->correct ? "yes" : "no");
  write_text_to_crt ("network", params->network);
  write_text_to_crt ("node", params->node);
  write_text_to_crt ("machine", params->machine);
  write_text_to_crt ("comment", params->comment);
  write_text_to_crt ("out_file", params->out_file);
  write_text_to_crt ("log_file", params->log_file);
  write_text_to_crt ("mpilib_name", params->mpilib_name);
  printf ("iters_per_time_default: %d\n", params->iters_per_time_default);
  printf ("overlap_default: %d\n", params->overlap_default);
  printf ("chunks_default: %d\n", params->chunks_default);
  printf ("message_len_default: %d\n", params->message_len_default);
  printf ("variation_default: %d\n", params->variation_default);
  printf ("dimensions_count_default: %d\n", params->dimensions_count_default);
  printf ("variation_default_list:");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d",  params->dimensions_defaults[i].variation);
  }
  printf ("\n");
  printf ("scale_default: %d\n", params->scale_default);
  printf ("scale_default_list:");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d",  params->dimensions_defaults[i].scale);
  }
  printf ("\n");
  printf ("start_default: %d\n", params->start_default);
  printf ("start_default_list:");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", params->dimensions_defaults[i].start);
  } 
  printf ("\n");
  printf ("end_default: %d\n", params->end_default);
  printf ("end_default_list :");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", params->dimensions_defaults[i].end);
  } 
  printf ("\n");
  printf ("stepwidth_default: %5.2f\n", params->stepwidth_default);
  printf ("stepwidth_default_list");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %5.2f", params->dimensions_defaults[i].stepwidth);
  } 
  printf ("\n");
  printf ("max_steps_default: %d\n", params->max_steps_default);
  printf ("max_steps_default_list");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", params->dimensions_defaults[i].max_steps);
  } 
  printf ("\n");
  printf ("min_dist_default: %d\n", params->min_dist_default);
  printf ("min_dist_default_list");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", params->dimensions_defaults[i].min_dist);
  } 
  printf ("\n");
  printf ("max_dist_default: %d\n", params->max_dist_default);
  printf ("max_dist_default:");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", params->dimensions_defaults[i].max_dist);
  } 
  printf ("\n");
  write_text_to_crt ("measurements", params->measurements);

  return;
}

void 
write_measurement_to_crt (measurement_t *measurement)
{
  int i;

  printf ("name: %s\n", measurement->name);
  printf ("correct for overhead: %s\n", 
	  measurement->correct_ms ? "yes" : "no");
  printf ("dimensions_count : %d\n", measurement->dimensions_count);
  printf ("variation:");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", measurement->dimensions[i].variation);
  }
  printf ("\n");
  printf ("scale:");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", measurement->dimensions[i].scale);
  }
  printf ("\n");
  printf ("start:");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", measurement->dimensions[i].start);
  }
  printf ("\n");
  printf ("end:");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", measurement->dimensions[i].end);
  }
  printf ("\n");
  printf ("stepwidth:");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %5.2f", measurement->dimensions[i].stepwidth);
  }
  printf ("\n");
  printf ("max_steps");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", measurement->dimensions[i].max_steps);
  }
  printf ("\n");
  printf ("min_dist");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", measurement->dimensions[i].min_dist);
  }
  printf ("\n");
  printf ("max_dist");
  for (i=0; i<MAX_DIMENSIONS; i++)
  {
    printf (" %d", measurement->dimensions[i].max_dist);
  }
  printf ("\n");
  printf ("max_rep: %d\n", measurement->max_rep);
  printf ("min_rep: %d\n", measurement->min_rep);
  printf ("def_chunks: %d\n", def_chunks);
  printf ("def_len: %d\n", def_len);
  printf ("standard_deviation: %5.2f\n", measurement->standard_deviation);
  printf ("uses_proxy: %d\n", measurement->uses_proxy);
  printf ("nedd_to_create_proxy: %d\n", measurement->need_to_create_proxy);
  printf ("client_scope_and_detachedstate: %d\n", measurement->client_scope_and_detachedstate);
  printf ("iter_cleanup: %d\n", measurement->iter_cleanup);

  return;
}


#define FLIPCASE(c)  ((char) (isupper(c) ? tolower(c) : toupper (c)))


char *
strstr_ignore_case (char *string, char *pattern)
{
  char *temp, *temp2;
  int  i, max_pat, max_str, matched;

  max_str = strlen (string);
  max_pat = strlen (pattern);

  for (i = 0; i <= max_str - max_pat; i++) {
    for (temp = &string[i], temp2 = pattern, matched = 1; /* TRUE */
	 *temp2 != '\0'; temp++, temp2++)
      if (!((*temp == *temp2) || (*temp == FLIPCASE(*temp2)))) {
	/* Not a match */
	matched = 0; /* FALSE */
	break;
      }

    if (matched)
      return &string[i];
  }

  return NULL;
}
