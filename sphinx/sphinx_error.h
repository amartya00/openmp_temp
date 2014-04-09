/*
$Log: sphinx_error.h,v $
Revision 1.6  2000/08/25 23:17:17  bronis
Added OpenMP tests

Revision 1.5  1999/09/29 00:23:48  bronis
removed most restrictions on ACKER variation

Revision 1.4  1999/09/20 19:00:39  srtaylor
Merged measure and measure_suite

Revision 1.3  1999/09/16 23:26:02  bronis
fixed fill_dummy_values calls

Revision 1.2  1999/07/30 16:55:13  bronis
Fixed conflict between STOP_SIGNAL and UNBIND

Revision 1.1.1.1  1999/05/11 16:50:03  srtaylor
CVS repository setup for sphinx

*/

/* $Id: sphinx_error.h,v 1.6 2000/08/25 23:17:17 bronis Exp $ */

enum {NO_ERROR, USER, NO_MEM, FILE_OPEN, FILE_READ, FILE_WRITE, INTERN };

#ifndef NULL
  #define NULL ((void *) 0)
#endif

#ifndef FALSE
  #define FALSE 0
#endif

#ifndef TRUE
  #define TRUE 1
#endif

#define SPHINX_VER 1.0   /* the actual version as a float */
#define DEF_CHUNKS 6
#define DEF_MESSAGE_LEN 256
/* #define MAX_MSG_LEN 0x1000 */
#define CACHE_WARMUP 5
/* #define MAX_REP 20 */
#define MEM_DEFAULT 4096 /* 4 MB assumed */
#define MAX_REP_DEFAULT 20
#define MIN_REP_DEFAULT 4
#define MAX_STEPS_DEFAULT 16
#define ITERS_PER_DEFAULT 1
#define DEFAULT_WORK_AMOUNT 10
#define DEFAULT_SCHEDULE_CAP 10
#define DEFAULT_SCHEDULE_CHUNKS 1
#define DEFAULT_WORK_FUNCTION SIMPLE_WORK
#define DEFAULT_OVERLAP_FUNCTION OMP_SEQUENTIAL_OVERLAP
#define DEFAULT_LOOP_SCHEDULE STATIC_SCHED


#define STANDARD_DEVIATION_DEFAULT 0.05
#define SPHINX_TAG 99 /* tags for messages of internal use of the benchmark */
#define MY_OVERHEAD 6  /* ibm sp2 laesst gruessen */
#define INVALID_ORG_TIME -1.0
#define STOP_SIGNAL -333.0
#define ERROR_SIGNAL -666.0

#define SPHINX_OMP_UNSET         -1

#define USE_COMMUNICATOR -1 /* for am_control_end in automeasure.c */
#define NO_COMMUNICATION -2 /* for am_control_end in automeasure.c */

#define MAX_ARGUMENT -1      /* indicates in measurement_t.x_end that x_end 
			       should be filled with the max number of nodes
			       / max message length during runtime */
#define MIN_ARGUMENT -2      /* indicates in measurement_t.x_start that x_start 
			       should be filled with the min number of nodes
			       / min message length during runtime */
#define DEFAULT -3           /* use the defualt value for this parameter
				(used for measurement.x_max/min_rep */

#define PARAMETER_FILE ".sphinx"
#define FINISHED_MSG "sphinx finished."  /* last string in log and output file,
					    in case of success */
#define LINE_LEN 0x100               /* max len. of lines in opened files */
#define FN_LEN 0x100                 /* max len of filenames (incl path)  */

#define SPHINX_MAX(a,b) (((a)<(b))?(b):(a))
#define SPHINX_MIN(a,b) (((a)>(b))?(b):(a))


extern int sphinx_error; /* texts for the errornummbers are stored in the
			    array error_text in the module sphinx_err.c */

extern char *message; /* special errortext giving more exact information */

extern char *user_message; 
extern char pos_message[]; /* Position of  errorsymptom */

extern char eht[]; /* errorhelptext, only used as buffer, when creating the
		      error text. */


/* end == TRUE, then exit will be called! */
void output_error (int end);

/* As Macro, that  __LINE__ and __FILE__ are effective */
#define ERROR(n,str) {sprintf(pos_message,"Line %d in Module %s.",__LINE__,__FILE__);sphinx_error=(n);message=(str);}












