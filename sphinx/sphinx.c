/*
$Log: sphinx.c,v $
Revision 1.23  2000/09/15 00:05:00  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.22  2000/08/25 23:17:16  bronis
Added OpenMP tests

Revision 1.21  2000/02/17 14:18:58  bronis
added first real non-blocking tests

Revision 1.20  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.19  1999/10/29 00:11:10  bronis
Fixed bugs, made input case insensitive

Revision 1.18  1999/10/21 22:49:56  bronis
Made overall default simple pingpong

Revision 1.17  1999/10/21 00:00:00  bronis
Finished post processing clean up

Revision 1.16  1999/09/29 00:23:48  bronis
removed most restrictions on ACKER variation

Revision 1.15  1999/09/21 15:59:50  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.14  1999/09/20 19:00:38  srtaylor
Merged measure and measure_suite

Revision 1.13  1999/09/17 23:03:00  bronis
Split BINDING variation

Revision 1.12  1999/09/16 23:26:02  bronis
fixed fill_dummy_values calls

Revision 1.11  1999/09/16 00:15:45  srtaylor
Outputs correct results for multiple dimensions

Revision 1.10  1999/09/15 15:50:57  srtaylor
Structure modifications - Does not currently compile

Revision 1.9  1999/09/14 16:38:51  srtaylor
First cut at multiple dimensions

Revision 1.8  1999/08/19 20:55:04  bronis
made old/new examples agree fully

Revision 1.7  1999/07/29 17:02:42  bronis
Fixed bug in alignment fix

Revision 1.6  1999/07/12 18:45:32  srtaylor
Bcast new default parameters

Revision 1.5  1999/07/09 22:11:44  srtaylor
Remove debug output

Revision 1.4  1999/07/08 00:10:58  srtaylor
Beta release - Single dimension free form input completed and tested

Revision 1.3  1999/05/26 00:29:42  srtaylor
Modifications to allow all default values to be @XXX specified. e.g. @VARIATION ...

Revision 1.2  1999/05/14 18:21:33  srtaylor
Free form input modification (only the "Type" field is required).

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "autodist.h"
#include "automeasure.h"
#include "sphinx_call.h"
#include "sphinx_error.h"
#include "sphinx_tools.h"
#include "sphinx_params.h"
#include "sphinx_mem.h"
#include "sphinx_aux_test.h"
#include "sphinx_post.h"

#define MPI_PROC_NAME_MSG    2008 /* semi-randomly picked value... */

/* #define MY_TEST_IO */

/* Globals */
char *parameter_file;

int 
  _sphinx_myid,
  number_of_measurements, /* to be filled in read_parameter_file */
  numprocs,
  max_msg_len;

char 
  expl_text[0x1000],
  _sphinx_msg[0x800],
  *log_file_name,
  *out_file_name,
  *_sphinx_buffer, 
  *_sphinx_buffer_2,
  processor_name[MPI_MAX_PROCESSOR_NAME],
  old_log_file_name[0x100],
  new_out_file_name[0x100];


params_t 
  params;       /* the parameter block */


/*
   @FUN:
   @DOES: reads parameters, creates log_file, output_file, calls all
   selected measurements, logs measurements,
   calls postprocessing (if wanted).
   @PARAMETERS: standard command line (arc, argv)
   @RETURNES: 0 if success
   @SIDEEFFECTS: sets all global variables 
   @ASSUMES:nothing.
*/
int 
main(int argc, char **argv)
{
  /* characteristics of all measurements */
  measurement_t *measurements_array = NULL; 

  int 
#ifdef IO_CHECK
    io_flag,      /* dummy flag for MPI_Attr_get-Call */
    io_node,      /* node, which can perform ANSI-C - IO */
#endif
    namelen,      /* used as dummy from MPI_Get_processor_name */
    i,            /* for loops */           
    new_run,      /* TRUE iff sphinx started after another completed run */
    first_pass = TRUE,    
    retval,
    num_left,
    /* each entry corresponds to a measurement, 
       saying SKIP or TODO or DONE or FAILED */
    *work_array = NULL;

  MPI_Status
    sphinx_local_status;

  max_msg_len = 0x100000;

  MPI_Init(&argc,&argv);      
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD,&_sphinx_myid);
  MPI_Get_processor_name(processor_name,&namelen);

#ifdef IO_CHECK
  MPI_Attr_get (MPI_COMM_WORLD, MPI_IO, &io_node, &io_flag);

  if (_sphinx_myid == 0 && io_flag)
    if (*io_node != 0 && *io_node != MPI_ANY_SOURCE) {
      ERROR(INTERN,"node 0 has no IO facility");
      output_error(TRUE);
    }
#endif   

  if (argc == 2) {
    /* The user specified an input file */
    parameter_file = argv[1];

    measurements_array = read_parameters (parameter_file, &params, 
					  &number_of_measurements);
  }
  else {
    parameter_file = NULL;
    measurements_array = do_pingpong_test (&params, &number_of_measurements);
  }

  if ((work_array = malloc (number_of_measurements * sizeof (int))) == NULL) {
    ERROR (NO_MEM,"for work_array");
    output_error (TRUE);
  }

  out_file_name = params.out_file[0];
  log_file_name = params.log_file[0];

  strcpy (old_log_file_name,log_file_name);
  strcat (old_log_file_name,".old");

  create_log_file();

  /* record ALL processor names in log file!!! */
  if (_sphinx_myid == 0) {
    char rprocessor_name[MPI_MAX_PROCESSOR_NAME];

    if (params.post_proc) {
	sprintf (_sphinx_msg, "Post processing is problematic\n"\
		 "It is derived directly from existing code\n"\
		 "The mechanism makes a number of quetionable choices\n"\
		 "Its use is not recommended\n"\
		 "Do so at your own risk\n");
	write_to_log_file (_sphinx_msg);
    }

    sprintf (_sphinx_msg,"Process %d on %s\n", _sphinx_myid, processor_name);
    write_to_log_file (_sphinx_msg);

    for (i = 1; i < numprocs; i++) {
      MPI_Recv (rprocessor_name, MPI_MAX_PROCESSOR_NAME, MPI_CHAR, i, 
		MPI_PROC_NAME_MSG, MPI_COMM_WORLD, &sphinx_local_status);
      sprintf (_sphinx_msg,"Process %d on %s\n", i, rprocessor_name);
      write_to_log_file (_sphinx_msg);
    }
  }
  else {
    MPI_Send(processor_name, MPI_MAX_PROCESSOR_NAME, 
	     MPI_CHAR, 0, MPI_PROC_NAME_MSG, MPI_COMM_WORLD);
  }

  create_output_file(&new_run);

  if (_sphinx_myid == 0)
    O(printf("proc.: %d: allocating %d Kbytes global memory\n", 
	     _sphinx_myid, params.memory);)

  if (!allocate_mem (params.memory * 1024)) {
    ERROR(NO_MEM,"allocating global buffers");
    output_error(TRUE);
  }
  
  for (i = 0; i< number_of_measurements; i++)
    work_array[i] = TODO;
  
  if (!new_run) {
    O(if (_sphinx_myid == 0) printf("reading old log file\n");)
    read_old_log_file (old_log_file_name, work_array, measurements_array);
  }
  D2(fprintf(stderr,"proc.:%d: here at 1.\n", _sphinx_myid);)

  /* Do measurements */
  num_left = number_of_measurements;

  while (num_left) {
    for (i = 0; i< number_of_measurements; i++) {
      MPI_Barrier(MPI_COMM_WORLD);
      
      if (work_array[i] == SKIP) {
	if (first_pass) {
	  num_left--;

	  if (_sphinx_myid == 0) {
	    sprintf (_sphinx_msg,"%s skipped\n", measurements_array[i].name);
	    write_to_log_file (_sphinx_msg);
	  }
	}
      }
      else if (work_array[i] == DONE) {
	if (first_pass) {
	  num_left--;
	}
      }
      else if (work_array[i] == FAILED) {
	work_array[i] = TODO;
	if (_sphinx_myid == 0) {
	  if (parameter_file == NULL) {
	    fprintf(stderr,
		    "It seems that the measurement %s has been failed\n",
		    measurements_array[i].name);
	    fprintf(stderr,
		    "in the last run. Now it will be repeated.\n" );
	  }
	  else {
	    fprintf(stderr,
		    "It seems that the measurement %s has been failed\n",
		    measurements_array[i].name);
	    fprintf(stderr,
		    "in the last run. It will be repeated after all other\n" );
	    fprintf(stderr,"selected measurements.\n");
	    fprintf(stderr,
		    "If you want to omit it, you may delete the entry\n");
	    fprintf(stderr,
		    "%s\nin the section @MEASUREMENTS of the file %s.\n",
		    measurements_array[i].name,  parameter_file);
	  }          
	  sprintf (_sphinx_msg,"%s failed\n", 
		   measurements_array[i].name);
	  write_to_log_file (_sphinx_msg);
	}
	continue;   /* so the failed measurement will be attempted in the
		       next (!) turn (after number_of_measurements steps) */
      }
      else if (work_array[i] == TODO) {
	time_t time_buf;
	char *time_str;
	
	if (_sphinx_myid == 0) {	
	  /* time stamp start */
	  if (time (&time_buf) == ((time_t) (-1)))
	    time_str = "**no time available**\n";
	  else
	    time_str = asctime (localtime (&time_buf));
	  
	  sprintf (_sphinx_msg,"%s started at %s\n", 
		   measurements_array[i].name, time_str);
	  write_to_log_file (_sphinx_msg);
	}
	
	retval = measure ((measurements_array + i), 0);
	
	if ((_sphinx_myid == 0) && (!retval)) {      
	  /* time stamp end */
	  if (time (&time_buf) == ((time_t) (-1)))
	    time_str = "**no time available**\n";
	  else
	    time_str = asctime (localtime (&time_buf));
	  
	  sprintf (_sphinx_msg,"%s ended at %s\n", 
		   measurements_array[i].name, time_str);
	  write_to_log_file (_sphinx_msg);
	}
	work_array[i] = DONE;
	num_left--;
      }  
    }

    first_pass = FALSE;
  }

  D2(printf("Proc.: %d:before last barrier\n",_sphinx_myid);)
  MPI_Barrier (MPI_COMM_WORLD);
  D2(printf("Proc.: %d:behind last barrier\n",_sphinx_myid);)

  clean_up_aux_tests ();

  if (_sphinx_myid == 0)
  {
    FILE
      *output_file;

    if ((output_file = fopen (out_file_name,"a+")) != NULL) {
      /* try to guarantee this is this last write completed... */
      fflush (output_file);

      fprintf (output_file,"/*@no*/\n%s", FINISHED_MSG);
      fclose (output_file);
    }

    sprintf (_sphinx_msg, "%s", FINISHED_MSG);
    write_to_log_file (_sphinx_msg);

    /* call postprocessing */
    if (params.post_proc)
    {
      O(printf("starting post processing.\n");)
      post_processing (out_file_name);
      O(printf("post processing done.\n");)
    }
  }
  free_mem();

  if (_sphinx_myid == 0) {
    O(printf("Proc.: %d: %s\n",_sphinx_myid, FINISHED_MSG););
  }

  MPI_Finalize();

  if (measurements_array != NULL) {
    for (i = 0; i < number_of_measurements; i++) {
      if (measurements_array[i].name != NULL)
        free (measurements_array[i].name);
    
      if (measurements_array[i].destroy != NULL) {
	measurements_array[i].destroy(&measurements_array[i]);
      }
    }
    free (measurements_array);
  }

  if (work_array != NULL)
    free (work_array);
    
  return (NO_ERROR);
}




