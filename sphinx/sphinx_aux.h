/*
$Log: sphinx_aux.h,v $
Revision 1.7  2000/08/25 23:17:16  bronis
Added OpenMP tests

Revision 1.6  2000/02/17 14:18:58  bronis
added first real non-blocking tests

Revision 1.5  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.4  1999/09/21 15:59:51  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.3  1999/09/20 19:00:39  srtaylor
Merged measure and measure_suite

Revision 1.2  1999/07/29 17:02:42  bronis
Fixed bug in alignment fix

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

int create_and_use_proxy_thread (measurement_t *ms, int n);

/* Globals */
extern char *parameter_file;


extern int 
  _sphinx_myid,
  number_of_measurements, /* to be filled in read_parameter_file */
  numprocs,
  max_msg_len;

extern char 
  expl_text[0x1000],
  _sphinx_msg[0x800],
  *log_file_name,
  *out_file_name,
  *_sphinx_buffer, 
  *_sphinx_buffer_2,
  processor_name[MPI_MAX_PROCESSOR_NAME],
  old_log_file_name[0x100],
  new_out_file_name[0x100];



