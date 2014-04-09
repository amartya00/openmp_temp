/*
$Log: sphinx_post.h,v $
Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: sphinx_post.h,v 1.1.1.1 1999/05/11 16:50:02 srtaylor Exp $ */
/* SKaMPI Special Karlsruher MPI-Benchmark
   -routines for postprocessing-
   -header-
   R. Reussner, 19.02.1997

   last change:
*/
int post_processing (char *input_file_name);

int combine_lists (data_list_t *result_list);
data_t *post_process (data_t *new_data, data_t *result_data);

