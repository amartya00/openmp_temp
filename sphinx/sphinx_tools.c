/*
$Log: sphinx_tools.c,v $
Revision 1.19  2000/08/25 23:17:19  bronis
Added OpenMP tests

Revision 1.18  2000/03/16 15:48:42  bronis
fixed mpguidec warnings

Revision 1.17  2000/02/17 14:18:59  bronis
added first real non-blocking tests

Revision 1.16  2000/01/14 23:34:56  bronis
purified recent changes

Revision 1.15  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.14  1999/10/29 00:11:10  bronis
Fixed bugs, made input case insensitive

Revision 1.13  1999/10/20 23:02:47  bronis
Fixed post processing core dumps

Revision 1.12  1999/10/12 22:57:15  srtaylor
Added fixed log scale and multi-dimension output description

Revision 1.11  1999/10/04 21:29:34  bronis
first cut at output filters

Revision 1.10  1999/10/01 21:36:53  bronis
Added debugged Root variation

Revision 1.9  1999/09/29 16:10:41  bronis
First cut at ROOT variation

Revision 1.8  1999/09/29 00:23:49  bronis
removed most restrictions on ACKER variation

Revision 1.7  1999/09/17 23:03:01  bronis
Split BINDING variation

Revision 1.6  1999/09/16 00:15:46  srtaylor
Outputs correct results for multiple dimensions

Revision 1.5  1999/09/14 16:38:52  srtaylor
First cut at multiple dimensions

Revision 1.4  1999/08/19 20:55:04  bronis
made old/new examples agree fully

Revision 1.3  1999/07/29 17:02:43  bronis
Fixed bug in alignment fix

Revision 1.2  1999/07/14 15:57:44  bronis
Fixed DEC text_t warnings

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_aux.h"
#include "sphinx_error.h"
#include "sphinx_tools.h"
#include "sphinx_params.h"

extern params_t 
  params;       /* the parameter block */


char *translate_work_function (int which_work)
{
  switch (which_work) {
  case SIMPLE_WORK:
    return "simple work function";
  case BORS_WORK:
    return "bor's work function";
  case SPIN_TIMED_WORK:
    return "timed work function (spin)";
  case SLEEP_TIMED_WORK:
    return "timed work function (sleep)";
  default:
    return "unknown";
  }
}

char *translate_overlap_function (int which_work)
{
  switch (which_work) {
  case OMP_SEQUENTIAL_OVERLAP:
    return "sequential overlap function";
  case OMP_PARALLEL_OVERLAP:
    return "OpenMP parallel overlap function";
  case OMP_PARALLEL_FOR_OVERLAP:
    return "OpenMP parallel for overlap function (schedule dependent)";
  case OMP_PARALLEL_FOR_CHUNKS_OVERLAP:
    return "OpenMP parallel for chunks overlap function (schedule dependent)";
  default:
    return "unknown";
  }
}

char *translate_omp_schedule (int which_schedule)
{
  switch (which_schedule) {
  case STATIC_SCHED:
    return "static";
  case DYNAMIC_SCHED:
    return "dynamic";
  case GUIDED_SCHED:
    return "guided";
  default:
    return "unknown";
  }
}




/*
   @FUN:
   @DOES: writes the message msg to the logfile (which also can be
   stdout or stderr. If it is really a file it will be opend and closed.
   @PARAMETERS: above.
   @RETURNES: TRUE iff successful,
   FALSE in case of error.
   @SIDEEFFECTS: none.
   @ASSUMES: _sphinx_myid and log_file_name set.
*/
int 
write_to_log_file (char *msg)
{
  if (_sphinx_myid == 0)
  {
    FILE 
      *log_file = NULL;
    
    if (!strcmp (  log_file_name,"stderr"))
      log_file = stderr;
    else if (!strcmp (  log_file_name,"stdout"))
      log_file = stdout;
    else
      log_file = fopen (log_file_name,"a+");
    
    if (log_file == NULL)
    {
      fprintf (stderr,"***Error opening log file %s.\n"\
	       "logging only on stderr\n%s\n***",
	       log_file_name, msg);
      return (FALSE);
    }
    fprintf (log_file,"Process %d: %s", _sphinx_myid, msg);
    fclose (log_file);
  }
  else
    printf ("Process %d: %s", _sphinx_myid, msg);
  return (TRUE);
}


#define MY_STRING_SIZE   0x1000

/* **************** routines for logging *************************** */
/*
   @FUN:
   @DOES: builds a printable string string containing most of the data stored
   in *ms.
   @PARAMETERS: above.
   @RETURNES: pointer to this string.
   @SIDEEFFECTS: uses _sphinx_msg (as little buffer...)
   @ASSUMES: nothing.
*/
char *
measurement_data_to_string (measurement_t *ms, char *string, int n)
{
  char 
    *temp_string = NULL,
    *pattern_str = NULL,
    **var_str = NULL,
    **scale_str = NULL;

  char 
    default_values_str[0xFF];

  int
    message_len = -1,
    chunks = -1,
    i, cur_len;
  

  if (string == NULL)
    if ((string = (char *) malloc (MY_STRING_SIZE)) == NULL)
      return ("");

  if ((temp_string = (char *) malloc (MY_STRING_SIZE)) == NULL)
    return ("");

  switch (ms->pattern) {
  case P2P:
    pattern_str = "Point-to-Point";
    message_len = ms->data.p2p_data.len;
    break;
  case SIMPLE:
    pattern_str = "Simple";
    break;
  case MASTER_WORKER:
    pattern_str = "Master-Worker";
    message_len = ms->data.mw_data.len;
    chunks = ms->data.mw_data.chunks;
    break;
  case COLLECTIVE:
    pattern_str = "Collective";
    message_len = ms->data.col_data.len;
    break;
  case THREAD_CHAIN:
    pattern_str = "Thread chain";
    message_len = ms->data.col_data.len;
    break;
  case MULTITIMING:
    pattern_str = "Multi-timing";
    message_len = ms->data.col_data.len;
    break;
  default:
    pattern_str = "unknown";
    message_len = -1;
    break;
  }

  var_str = (char **) malloc (ms->dimensions_count*sizeof(char *));

  for (i = 0; i < ms->dimensions_count; i++) {
    switch (ms->dimensions[i].variation) {
    case LENGTH:
      var_str[i] = "message length";
      message_len = -1;
      break;
    case CHUNK:
      var_str[i] = "chunks (number of pieces of work)";
      chunks = -1;
      break;
    case NODES:
      var_str[i] = "number of nodes";
      break;
    case ACKER:
      var_str[i] = "task sending acknowledgement";
      break;
    case ROOT:
      var_str[i] = "root of collective communication";
      break;
    case MASTER_BINDING:
      var_str[i] = "master CPU binding";
      break;
    case SLAVE_BINDING:
      var_str[i] = "slave CPU binding";
      break;
    case ITERS:
      var_str[i] = "iterations";
      break;
    case OVERLAP:
      var_str[i] = "computation overlap time";
      break;
    case SECOND_OVERLAP:
      var_str[i] = "second computation overlap time";
      break;
    case THREADS:
      var_str[i] = "number of threads";
      break;
    case WORK_AMOUNT:
      var_str[i] = "work amount parameter of work function";
      break;
    case WORK_FUNCTION:
      var_str[i] = "work function";
      break;
    case OVERLAP_FUNCTION:
      var_str[i] = "overlap function";
      break;
    case SCHED_CAP:
      var_str[i] = "number of iterations in OMP scheduled loop";
      break;
    case SCHED_CHUNKS:
      var_str[i] = "OMP loop schedule chunks parameter";
      break;
    case SCHEDULE:
      var_str[i] = "OMP loop schedule";
      break;
    default:
      var_str[i] = "unknown";
      break;
    }
  }

  default_values_str[0] = 0;
  if (message_len != -1)
    sprintf (default_values_str,", message length %d bytes",message_len);

  if (chunks != -1) {
    sprintf (_sphinx_msg,", chunks %d",chunks);
    strcat (default_values_str, _sphinx_msg);
  }

  scale_str = (char **) malloc (ms->dimensions_count*sizeof(char *));

  for (i = 0; i < ms->dimensions_count; i++) {
    switch (ms->dimensions[i].scale) {
    case FIXED_LIN:  
      scale_str[i] = "linear, no automatic data point selection";
      break;
    case FIXED_LOG:
      scale_str[i] = "logarithmical, no automatic data point selection";
      break;
    case DYN_LIN:
      scale_str[i] = "linear, automatic data point selection";
      break;
    case DYN_LOG:
      scale_str[i] = "logarithmical, automatic data point selection";
      break;
    default:
      scale_str[i] = "unknown";
      break;
    }
  }

  sprintf (string,"#Description of the %s measurement:\n", ms->name);

  /* include EOS... */
  cur_len = strlen (string) + 1;
    
  sprintf (temp_string, "#Pattern: %s varied over %d dimensions:\n",
	   pattern_str, ms->dimensions_count);

  cur_len += strlen (temp_string);
  if (cur_len > MY_STRING_SIZE) {
    free (var_str);
    free (scale_str);
    free (temp_string);
    return (string);
  }   
    
  string = strcat (string, temp_string);

  for (i=0; i<ms->dimensions_count; i++) {
    sprintf (temp_string, "#\tDimension %d is %s\n", i, var_str[i]);

    cur_len += strlen (temp_string);
    if (cur_len > MY_STRING_SIZE) {
      free (var_str);
      free (scale_str);
      free (temp_string);
      return (string);
    }   
    
    string = strcat (string, temp_string);
    sprintf (temp_string, "#\t\tScale: %s\n", scale_str[i]);

    cur_len += strlen (temp_string);
    if (cur_len > MY_STRING_SIZE) {
      free (var_str);
      free (scale_str);
      free (temp_string);
      return (string);
    }   
    
    string = strcat (string, temp_string);
    sprintf (temp_string, "#\t\trange: %d - %d, stwpwidth = %f\n", 
	     ms->dimensions[i].start, ms->dimensions[i].end, 
	     ms->dimensions[i].stepwidth);

    cur_len += strlen (temp_string);
    if (cur_len > MY_STRING_SIZE) {
      free (var_str);
      free (scale_str);
      free (temp_string);
      return (string);
    }   
    
    string = strcat (string, temp_string);
  }

  if (ms->pattern == COLLECTIVE) { /* print root info... */
    sprintf (temp_string, "#\t\tThe root is %d\n", ms->root);
      
    cur_len += strlen (temp_string);
    if (cur_len > MY_STRING_SIZE) {
      free (var_str);
      free (scale_str);
      free (temp_string);
      return (string);
    }   
    
    string = strcat (string, temp_string);
  }

  sprintf (temp_string, "#\t\tdefault values %d nodes:%s.\n", 
	   ms->nodes, default_values_str);

  cur_len += strlen (temp_string);
  if (cur_len > MY_STRING_SIZE) {
    free (var_str);
    free (scale_str);
    free (temp_string);
    return (string);
  }   
    
  string = strcat (string, temp_string);

  sprintf (temp_string, 
	   "#\t\tmax. allowed standard deviation is %3.2f %%\n",
	   ms->standard_deviation * 100);

  cur_len += strlen (temp_string);

  if (cur_len > MY_STRING_SIZE) {
    free (var_str);
    free (scale_str);
    free (temp_string);
    return (string);
  }   
    
  string = strcat (string, temp_string);

  sprintf (temp_string, 
	   "#\t\tmeasurements ARE%s corrected for overhead\n",
	   ms->correct_ms ? " " : " NOT");

  cur_len += strlen (temp_string);

  if (cur_len <= MY_STRING_SIZE) {
    string = strcat (string, temp_string);
  }   

  free (var_str);
  free (scale_str);
  free (temp_string);
  return (string);
}

/* ******************* routines for output processing **************** */
/*
   @FUN:
   @DOES: reads header (containing HEADER_LINES lines)
   of the measurement at the current position of
   the file-pointer into text.
   @PARAMETERS: above.
   @RETURNES: the manipulated file_handle.
   @SIDEEFFECTS: none.
   @ASSUMES: *file is a valid file handle of on open file, and ist file-pointer
   really points to a header.
*/
FILE * 
read_header (FILE *file, text_t text)
{
  char line[LINE_LEN];

  int i = 0;
  int pos_to_use = 1;
  int both_used = 0;

  fpos_t the_pos[2];

  fgetpos (file, &the_pos[0]);

  if (fgets (line, LINE_LEN, file) == NULL)
    return (NULL);

  while (strstr (line, "#") != NULL) {
    line[LINE_LEN - 1] = '\0';
    insert_in_text (line, text, i);

    fgetpos (file, &the_pos[pos_to_use]);

    pos_to_use = (pos_to_use + 1) % 2;
    both_used = 1;

    if (fgets (line, LINE_LEN, file) == NULL)
      return (NULL);

    i++;
  }    

  if (both_used)
    fsetpos (file, &the_pos[pos_to_use]);
  else
    fsetpos (file, &the_pos[0]);

  insert_in_text (NULL, text, i);

  return (file);
}

/*
   @FUN:
   @DOES: writes the header (containing HEADER_LINES lines)
   stored in *text in the file,
   this header will be named name there.
   @PARAMETERS: above.
   @RETURNES: the manipulated file-handel.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
FILE * 
write_header (FILE *file, text_t text, char *name)
{
  char 
    line[LINE_LEN];

  int
    i = 0;
  
  fprintf (file,"/*@""in%s ",name);  /* space after %s important for
		                          dorep.pl !!! */

  while (read_from_text (line, text, i++) != NULL) {
    if ((fprintf (file, "%s\n",line)) == 0)
    {
      ERROR(FILE_WRITE,"writing header");
      output_error (TRUE);
    }
  }
  return (file);
}
    
/*
   @FUN:
   @DOES: writes text to file *file in a section s.
   note: file is ** so that writing in file changes the filepointer! 
   @PARAMETERS: above.
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
void 
write_text_to_file (text_t text, char *s, FILE **file)
{
  int
    i;

  if (text[0] != NULL)
  {
    fprintf (*file, "#%s %s\n", s, text[0]);
    for (i = 1; text[i] != NULL; i++)
      fprintf (*file, "#%s\n",text[i]);
  }
}


/*
   @FUN:
   @DOES: inserts line into array text at position pos.
   (Note: text is (should) always (be) an NULL-Pointer terminated array.
   @PARAMETERS: above.
   @RETURNES: pointer to text,
   or NULL in case of error.
   @SIDEEFFECTS: none.
   @ASSUMES: text points to array of TEXT_LINES char *
   or is NULL (than allocates).
*/
int
insert_in_text (char *line, text_t text, int pos)
{
  int len;

  if (pos >= TEXT_LINES) {
    ERROR (USER,"too many text lines ");
    return 666;
  }

  if (line == NULL) {
    text[pos] = NULL;
    return 0;
  }

  len = strlen (line);

  /* adding +1 for the '\0' */
  if ((text[pos] = (char *)malloc (len + 1)) == NULL) {
    ERROR (NO_MEM,"parameter inserting");
    return 666;
  }
  
  strcpy (text[pos], line); 

  /* do not copy the \n character */
  if ((len > 0) && (text[pos][len - 1] == '\n'))
    text[pos][len - 1] = '\0';  

  text[pos + 1] = NULL;

  return 0;
}

/*
   @FUN:
   @DOES: reads the textline at position pos from text and stores it 
   at line.
   @PARAMETERS: above.
   @RETURNES: pointer to line.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
char *
read_from_text (char *line, text_t text, int pos)
{
  if (pos >= TEXT_LINES)
  {
    ERROR (USER,"too many text lines ");
    return (NULL);
  }

  strcpy (line,text[pos]); 
  return (line);
}

/*
   @FUN:
   @DOES: free-es all memory occupied by the textlines. If mode == DYNAMIC
   it free-es also the pointer-array text. (Call with mode == STATIC if not
   wanted.)
   @PARAMETERS: above.
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
void
free_text (text_t text)
{
  int 
    i = 0;

  while (text[i] != NULL)
    free (text[i++]);

  return;
}


  
/*
   @FUN:
   @DOES: reads the old log_file (which is the log_file of the previous run),
   to analyze which measurements run before, and which failed.
   The results are send from process 0 to all others in default_communicator.
   @PARAMETERS: name of the old log_file (log_file_str),
   an integer array (work_array), which will be filled with control-info.
   the initialized array of all measurements.
   @RETURNES: pointer to modified work_array.
   @SIDEEFFECTS: none.
   @ASSUMES: _sphinx_myid and default_communicator set.
*/
int *
read_old_log_file (char *log_file_str, int *work_array, measurement_t *ms)
{
  if (_sphinx_myid == 0)
  {
    FILE 
      *log_file;
    int 
      i,
      start_found = number_of_measurements;
    
    char 
      line[LINE_LEN];
    
    if (work_array == NULL)
      if ((work_array = (int *) malloc (sizeof (int) * number_of_measurements))
	  == NULL)
      {
	ERROR (NO_MEM,"read_old_log_file");
	output_error (TRUE);
      }
    
    if (!strcmp (log_file_str,"stdout") || !strcmp (log_file_str,"stderr"))
      goto send_array;    /* no old info accessible */

    if ((log_file = fopen (log_file_str, "r")) == NULL)
      goto send_array;    /* no old info accessible */

    
    while (fgets(line, LINE_LEN, log_file) != NULL)
    {
      char 
	buf[0x500];
      
      for (i = 0; i < number_of_measurements; i++)
      {
	sprintf (buf,"%s failed", ms[i].name);
	if (strstr(line,buf) != NULL)
	{
	  /* only mark a benchmark as failed, if the
	     user wants to run also in this run. */
	  if (work_array[i] == TODO)  					 
	    work_array[i] = FAILED;
	  break;
	}	
	     
	/* Once skipped, keep skipping!!! */
	sprintf (buf,"%s skipped", ms[i].name);
	if (strstr(line,buf) != NULL)
	{
	  work_array[i] = SKIP;
	  break;
	}
	
	sprintf (buf,"%s started", ms[i].name);
	if (strstr(line,buf) != NULL)
	{
	  start_found = i;

	  /* only mark a benchmark as failed, if the
	     user wants to run also in this run. */
	  if (work_array[i] == TODO)  					 
	    work_array[i] = FAILED;
	  break;
	}	
	
	sprintf (buf,"%s ended", ms[i].name);
	if (strstr(line,buf) != NULL)
	{
	  if (start_found == i)
	  {
	    work_array[i] = SKIP;
	    break;
	  }
	  else
	  {
	    fprintf (stderr,"corrupted log file %s\nskip reading!\n",
		     log_file_str);
	    fclose (log_file);
	    return (work_array);
	  }	
	} 
      }
    } 
    fclose (log_file);
  send_array:
    MPI_Bcast (work_array, number_of_measurements, MPI_INT, 0, 
	       default_communicator);
  }
  else /* so not process 0 */
    MPI_Bcast (work_array, number_of_measurements, MPI_INT, 0, 
	       default_communicator);
  
  return (work_array);
}

/* ******************* output file management ************************* */
/*
   @FUN:
   @DOES: returnes a new output_file_name which is name.<number> with number
   high enough, the the returned name is new.
   @PARAMETERS: the name which to append with the number.
   @RETURNES: a pointer to the new name.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
char *
new_name (char *name)
{
  static char
    n_name[FN_LEN];

  sprintf (n_name,"%s.%d", name, number_of_output_files (name) + 1);

  return (n_name);
}

/*
   @FUN:
   @DOES: returnes max value for files existing in working directory
   with <name>.<return_value> 
   assumed that if <name>.n exists than also <name>.n - 1 exists, 
   unless n = 1 
   @PARAMETERS: above.
   @RETURNES: above. (or NULL in case of error.)
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int 
number_of_output_files (char *name)
{
  FILE
    *file_dummy;

  int 
    appendix = 1;
 
  char 
    n_name[0x100];

  if (name == NULL) /* for safety */
    return (FALSE);

  for (;; appendix++)
  {
    sprintf (n_name,"%s.%d", name, appendix);
    if ((file_dummy = fopen (n_name,"r")) != NULL)
      fclose (file_dummy);
    else
      break;
  }
  /* fopen failed at last call, so decrease appendix */
  return (--appendix); 
}

/*
   @FUN:
   @DOES: tests if file is a complete sphinx output file.
   @PARAMETERS: above.
   @RETURNES: TRUE iff complete, FALSE otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int 
output_file_complete (FILE *file)
{
  char 
    line[LINE_LEN];
  
  int 
    slen = strlen (FINISHED_MSG);

  /* move to last line*/
#if 0
  fseek (file, SEEK_CUR, (-1) * slen);
  fgets (line, 0x100, file);
#else
  rewind (file);
  while (fgets (line, 0x100, file) != NULL)
    ;
#endif
  return (strncmp (line, FINISHED_MSG, slen) == 0);
}

/*
   @FUN:
   @DOES: tests if file is a sphinx output file, which was
   created by postprocessing.
   @PARAMETERS: above.
   @RETURNES: TRUE iff postprocessed, FALSE otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int 
output_file_postprocessed (FILE *file)
{
  char 
    line[LINE_LEN];
  
  /* move to last line*/
#if 0
  fseek (file, SEEK_CUR, (-1) * slen);
  fgets (line, 0x100, file);
#else
  rewind (file);
  while (fgets (line, 0x100, file) != NULL)
    if (strstr (line, "postproc") != NULL)
	return (TRUE);
#endif
  return (FALSE);
}

/*
   @FUN:
   @DOES: creates log file and renames evtl existing log file of previous
   run.
   @PARAMETERS: none.
   @RETURNES: nothing.
   @SIDEEFFECTS: prints error messages in case of trouble.
   @ASSUMES: _sphinx_myid set.
*/
void 
create_log_file (void)
{
  FILE 
    *log_file = NULL;

  int
    remove_flag = FALSE,  /* stores result of remove(log_file) */
    rename_flag= FALSE;   /* stores result of rename 
			     log_file to <log_file>.old */

  char 
    new_log_file_name[0x100];

  if ((_sphinx_myid == 0) && strcmp ( log_file_name,"stderr")
      && strcmp ( log_file_name,"stdout"))
  {
    strcpy (new_log_file_name, new_name(log_file_name));
    rename (old_log_file_name, new_log_file_name);
    remove_flag = remove (old_log_file_name);
    /* order of parameters of rename is ok !! */
    rename_flag = rename (log_file_name, old_log_file_name); 

    if ((log_file = fopen (log_file_name,"w+")) == NULL)
    {
      ERROR(FILE_OPEN,"creating log file");
      output_error(FALSE);
    }

/*    fprintf (stdout,"log file %s successfully created.\n",
	     log_file_name); */
    fclose (log_file);

    if (remove_flag == 0) /* that means remove has been successful */
    {
      sprintf (_sphinx_msg, "old log-file %s removed\n",old_log_file_name);
      write_to_log_file (_sphinx_msg);
    }
    
    if (rename_flag == 0) /* that means rename has been successful */
    {
      sprintf (_sphinx_msg, "renamed old log-file %s to %s\n",
	       log_file_name, old_log_file_name);
      write_to_log_file (_sphinx_msg);
    }
  }
}

/*
   @FUN:
   @DOES: creates new output file and determines if a complete previous run
   has been performed. (then *new_run is set to TRUE.) The value of 
   new_run is sent to all other processes in default_communicator.
   @PARAMETERS: above.
   @RETURNES: nothing.
   @SIDEEFFECTS: prints error messages in case of trouble.
   @ASSUMES: _sphinx_myid and default_communicator set.
*/
void 
create_output_file (int *new_run)
{
  FILE
    *output_file;

  if (_sphinx_myid == 0)
  {
    /* test if file exists */

    if ((output_file = fopen (out_file_name,"r")) == NULL)
    {
      /* fclose (output_file); fixed RR 23.4.98 */
      
      if ((output_file = fopen (out_file_name,"a+")) == NULL)
      {
	ERROR(FILE_OPEN,"creating output file");
	output_error(TRUE);
      }
      write_head_of_outfile (&output_file,"");
      *new_run = TRUE;
    }
    else
    {
      /* if output_file exists and is complete */
      if (output_file_complete (output_file))  
      {
	*new_run = TRUE;
	if (!output_file_postprocessed (output_file))
	{
	  /* rename it to oldname ++ ".<newnumber>" */
	  fclose (output_file);
	  strcpy (new_out_file_name, new_name (out_file_name));
	  rename (out_file_name, new_out_file_name);
	  sprintf (_sphinx_msg,"Output file %s renamed to %s.\n",
		   out_file_name, new_out_file_name);
	  write_to_log_file (_sphinx_msg);
	}
	/* create new output file */
	if ((output_file = fopen (out_file_name,"w+")) == NULL)
	{
	  ERROR(FILE_OPEN,"creating output file");
	  output_error(TRUE);
	}
	write_head_of_outfile (&output_file,"");
      }
      else
	*new_run = FALSE;
    }

    fclose (output_file);
    sprintf (_sphinx_msg,"Output file %s successfully created.\n",
	     out_file_name);
    write_to_log_file (_sphinx_msg);
    MPI_Bcast (new_run, 1, MPI_INT, 0, default_communicator);
  }
  else
    MPI_Bcast (new_run, 1 ,MPI_INT, 0, default_communicator);
}

/*
   @FUN:
   @DOES: extracts from the RCS id string the version number 
   @PARAMETERS: Pointer to the target string and pointer to 
   rcsstring
   @RETURNES: Pointer to target string
   @SIDEEFFECTS: writes to targetpointer the version number
   @ASSUMES: nothing.
*/
char *
ExtractVersionNumber ( char * PtrTarget, char * PtrSource )
{
  int i,j;
  
  for (i=0; !isdigit ( PtrSource[i] ); i++ );
  
  for (j=0 ; !isspace ( PtrSource[i] ); 
       PtrTarget[j]=PtrSource[i], i++, j++ );
  
  PtrTarget[j] = 0;
  return PtrTarget;
}

/*
   @FUN:
   @DOES: writes the head of the outfile (i.e. the machine, node, 
   network, user and correct for overhead -section of the params file.
   @PARAMETERS: a pointer to a filehandle, and a string (no_runs), which 
   can contain the number of sphinx-runs used for postprecessing. 
   (This option is only used by postprocessing.)
   @RETURNES: nothing.
   @SIDEEFFECTS: manipulates file (sets the filepointer ahead).
   @ASSUMES: nothing.
*/

void
write_head_of_outfile (FILE **file, char *no_runs)
{
  time_t time_buf;
  char *time_str;
  char version[100];
  struct utsname MyName;
/*  struct tm localdate;
  int err=0; */

  extern char **environ;
  char **ep;

  write_text_to_file (params.machine, "@MACHINE", file);  
  write_text_to_file (params.node, "@NODE", file);
  write_text_to_file (params.network, "@NETWORK", file);
  write_text_to_file (params.user, "@USER", file);
  
  write_text_to_file (params.mpilib_name, "@MPILIB_NAME", file);

  fprintf (*file,"#@SPHINXVERSION %s\n", ExtractVersionNumber ( version, rcsid ) );
  
  if ( uname ( &MyName ) == -1 )
    {
      fprintf ( stdout, "uname failed. Filling with dummy values.\n" );
      fprintf ( *file, "#@OSNAME none\n" );
      fprintf ( *file, "#@OSRELEASE none\n"  );
      fprintf ( *file, "#@OSVERSION none\n" );
      fprintf ( *file, "#@HOSTNAME none\n" );
      fprintf ( *file, "#@ARCHITECTURE none\n" );
    }
  else
    {
      fprintf ( *file, "#@OSNAME %s\n", MyName.sysname );
      fprintf ( *file, "#@OSRELEASE %s\n", MyName.release );
      fprintf ( *file, "#@OSVERSION %s\n", MyName.version );
      fprintf ( *file, "#@HOSTNAME %s\n", MyName.nodename );
      fprintf ( *file, "#@ARCHITECTURE %s\n", MyName.machine );
    }

  fprintf (*file,"#@CORRECT_FOR_OVERHEAD %s\n",
	   (params.correct == 1) ? "yes":"no");
	
  /* Print the environment to the output file */
  /* This is very useful on some machines, like the SP-2... */
  fprintf (*file, "#@ENVIRONMENT\n");
  
  for (ep = environ; *ep; ep++)
    fprintf (*file, "#%s\n", *ep);
  
  /* time stamp */
  if (time (&time_buf) == ((time_t) (-1)))
    time_str = "**no time available**\n";
  else
    time_str = asctime (localtime (&time_buf));
  
  fprintf (*file, "#@TIME %s\n", time_str);

  if (strlen (no_runs) > 0)
    fprintf (*file,"#@POSTPROC %s\n",
	     (params.post_proc == 1) ? no_runs:"no");

}

/*
   @FUN:
   @DOES: interpolates a double at value between (arg1,res1) and (arg2,res2).
   @PARAMETERS: above.
   @RETURNES: pointer to the interpolated data-struct.
   @SIDEEFFECTS: allocates new data element if data == NULL.
   @ASSUMES: nothing.
*/
double 
linear_interpolate (double arg_inter, double arg1, double arg2, 
			   double res1, double res2)
{
  if (arg1 == arg2)
    return ((res1 + res2) / 2);

  return (res1 + (arg_inter - arg1) * 
	  (res2 - res1) / (arg2 - arg1));
}

void
filter_ACKER_root (measurement_t *ms, data_list_t *inlist, 
		   FILE *output_file, char *pattern_str, 
		   char *string, int multitiming_listnum)
{
  /* first cut at filter implementation; should really allow user input */
  /* not right way but a good start... */
  data_list_t retlist;
  int  index, ACKER_var = -1;
  int  Root_var = -1;
  dimension_t filter_dims[MAX_DIMENSIONS];

  for (index = 0; index < ms->dimensions_count; index++) {
    if (ms->dimensions[index].variation == ACKER)
      ACKER_var = index;
    else if (ms->dimensions[index].variation == ROOT)
      Root_var = index;

    filter_dims[index] = ms->dimensions[index];
  }

  if ((ACKER_var == -1) && (Root_var == -1))
    /* don't need to filter... */
    return;

  init_list (&retlist);

  if (ACKER_var != -1) {
    /* filter ACKER */
    filter (MAX, inlist, &retlist, ACKER_var);

    if (multitiming_listnum != -1)
      fprintf (output_file,"\n#-------------------------------"\
	       "\n#/*@""in%s_%s_max_ACKER.%d.ski*/\n%s", 
	       pattern_str, ms->name, multitiming_listnum, string);
    else 
      fprintf (output_file,"\n#-------------------------------"\
	       "\n#/*@""in%s_%s_max_ACKER.ski*/\n%s", 
	       pattern_str, ms->name, string);

    /* remove ACKER_var from filter_dims... */
    for (index = ACKER_var; index < ms->dimensions_count - 1; index++)
      filter_dims[index] = filter_dims[index + 1];


    write_to_file (&retlist, output_file, 
		   ms->dimensions_count - 1, filter_dims, 
		   ms->use_reference_data);

    if (Root_var != -1) {
      /* filter Root over ACKER-filtered list... */
      data_list_t retlist2;
		  
      init_list (&retlist2);
		  
      if (Root_var > ACKER_var)
	/* Root arg is one less in ret_list since removed ACKER */
	Root_var--;

      /* remove Root_var from filter_dims... */
      for (index = Root_var; index < ms->dimensions_count - 2; index++)
	filter_dims[index] = filter_dims[index + 1];

      /* inefficient: could do in one pass... */
      filter (MAX, &retlist, &retlist2, Root_var);
      if (multitiming_listnum != -1)
	fprintf (output_file,"\n#-------------------------------"\
		 "\n#/*@""in%s_%s_max_Root_max_ACKER.%d.ski*/\n%s", 
		 pattern_str, ms->name, multitiming_listnum, string);
      else 
	fprintf (output_file,"\n#-------------------------------"\
		 "\n#/*@""in%s_%s_max_Root_max_ACKER.ski*/\n%s", 
		 pattern_str, ms->name, string);
      write_to_file (&retlist2, output_file, 
		     ms->dimensions_count - 2, filter_dims, 
		     ms->use_reference_data);
      free_data_list (&retlist2, STATIC);

      filter (MIN, &retlist, &retlist2, Root_var);
      if (multitiming_listnum != -1)
	fprintf (output_file,"\n#-------------------------------"\
		 "\n#/*@""in%s_%s_min_Root_max_ACKER.%d.ski*/\n%s", 
		 pattern_str, ms->name, multitiming_listnum, string);
      else 
	fprintf (output_file,"\n#-------------------------------"\
		 "\n#/*@""in%s_%s_min_Root_max_ACKER.ski*/\n%s", 
		 pattern_str, ms->name, string);
      write_to_file (&retlist2, output_file, 
		     ms->dimensions_count - 2, filter_dims, 
		     ms->use_reference_data);
      free_data_list (&retlist2, STATIC);

      filter (MEAN, &retlist, &retlist2, Root_var);
      if (multitiming_listnum != -1)
	fprintf (output_file,"\n#-------------------------------"\
		 "\n#/*@""in%s_%s_mean_Root_max_ACKER.%d.ski*/\n%s", 
		 pattern_str, ms->name, multitiming_listnum, string);
      else 
	fprintf (output_file,"\n#-------------------------------"\
		 "\n#/*@""in%s_%s_mean_Root_max_ACKER.ski*/\n%s", 
		 pattern_str, ms->name, string);
      write_to_file (&retlist2, output_file, 
		     ms->dimensions_count - 2, filter_dims, 
		     ms->use_reference_data);
      free_data_list (&retlist2, STATIC);
    }
		
    free_data_list (&retlist, STATIC);

    return;
  }
	
  /* else Root_var != -1 */
  /* filter Root only... */
  /* remove Root_var from filter_dims... */
  for (index = Root_var; index < ms->dimensions_count - 2; index++)
    filter_dims[index] = filter_dims[index + 1];

  /* inefficient: could do in one pass... */
  filter (MAX, inlist, &retlist, Root_var);
  if (multitiming_listnum != -1)
    fprintf (output_file,"\n#-------------------------------"\
	     "\n#/*@""in%s_%s_max_Root.%d.ski*/\n%s", 
	     pattern_str, ms->name, multitiming_listnum, string);
  else 
    fprintf (output_file,"\n#-------------------------------"\
	     "\n#/*@""in%s_%s_max_Root.ski*/\n%s", 
	     pattern_str, ms->name, string);
  write_to_file (&retlist, output_file, 
		 ms->dimensions_count - 1, filter_dims, 
		 ms->use_reference_data);
  free_data_list (&retlist, STATIC);

  filter (MIN, inlist, &retlist, Root_var);
  if (multitiming_listnum != -1)
    fprintf (output_file,"\n#-------------------------------"\
	     "\n#/*@""in%s_%s_min_Root.%d.ski*/\n%s", 
	     pattern_str, ms->name, multitiming_listnum, string);
  else 
    fprintf (output_file,"\n#-------------------------------"\
	     "\n#/*@""in%s_%s_min_Root.ski*/\n%s", 
	     pattern_str, ms->name, string);
  write_to_file (&retlist, output_file, 
		 ms->dimensions_count - 1, filter_dims, 
		 ms->use_reference_data);
  free_data_list (&retlist, STATIC);

  filter (MEAN, inlist, &retlist, Root_var);
  if (multitiming_listnum != -1)
    fprintf (output_file,"\n#-------------------------------"\
	     "\n#/*@""in%s_%s_mean_Root.%d.ski*/\n%s", 
	     pattern_str, ms->name, multitiming_listnum, string);
  else 
    fprintf (output_file,"\n#-------------------------------"\
	     "\n#/*@""in%s_%s_mean_Root.ski*/\n%s", 
	     pattern_str, ms->name, string);
  write_to_file (&retlist, output_file, 
		 ms->dimensions_count - 1, filter_dims, 
		 ms->use_reference_data);
  free_data_list (&retlist, STATIC);
}
