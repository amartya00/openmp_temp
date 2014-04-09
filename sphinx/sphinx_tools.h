/*
$Log: sphinx_tools.h,v $
Revision 1.6  2000/02/17 14:18:59  bronis
added first real non-blocking tests

Revision 1.5  1999/10/04 21:29:35  bronis
first cut at output filters

Revision 1.4  1999/09/14 16:38:53  srtaylor
First cut at multiple dimensions

Revision 1.3  1999/07/14 15:57:44  bronis
Fixed DEC text_t warnings

Revision 1.2  1999/07/13 14:49:29  bronis
increased input file size; changed Acker to ACKer as needed

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: sphinx_tools.h,v 1.6 2000/02/17 14:18:59 bronis Exp $ */
/* several tools for sphinx
   -header-

   R. Reussner, 23.01.1997, 05.02.1997


*/
/* Changed from 0x300 which was TOO small for measurements in my .sphinx! */
/* Really should do those with dynamic array... */
/* REALLY Really should get rid of text_t ugliness... */
#define TEXT_LINES 0x900          /* number of lines for parameters of
				     type text */
#define HEADER_LINES 8           /* number of lines in a meas. header 
				  (routines: read/write_header, 
				  measurement_data_to_string) */
typedef char *my_string;
typedef my_string text_t[TEXT_LINES + 1];  /* NULL-terminated pointer-array */
int    insert_in_text (char *line, text_t text, int pos);
char   *read_from_text (char *line, text_t text, int pos);
void   free_text        (text_t text);
void   write_text_to_file (text_t text, char *s,FILE **file);

FILE   *write_header (FILE *file, text_t text, char *name);
FILE   *read_header  (FILE *file, text_t text);

void   write_head_of_outfile (FILE **file, char *no_runs);


char *measurement_data_to_string (measurement_t *ms, char *string, int n);



int  *read_old_log_file (char *log_file_str, int *work_array,
			 measurement_t *ms);

int  write_to_log_file (char *msg);
int  output_file_complete (FILE *file);
int  output_file_postprocessed (FILE *file);

char *new_name (char *name);
void create_log_file (void);
void create_output_file (int *new_run);
int number_of_output_files (char *name);
char *new_name (char *name);

double linear_interpolate (double arg_inter, double arg1, double arg2, 
			   double res1, double res2);

void
filter_ACKER_root (measurement_t *ms, data_list_t *inlist, 
		   FILE *output_file, char *pattern_str, 
		   char *string, int multitiming_listnum);
