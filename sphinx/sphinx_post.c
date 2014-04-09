/*
$Log: sphinx_post.c,v $
Revision 1.9  2000/08/25 23:17:18  bronis
Added OpenMP tests

Revision 1.8  2000/03/16 15:48:40  bronis
fixed mpguidec warnings

Revision 1.7  2000/02/17 14:18:59  bronis
added first real non-blocking tests

Revision 1.6  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.5  1999/10/20 23:02:47  bronis
Fixed post processing core dumps

Revision 1.4  1999/09/29 00:23:49  bronis
removed most restrictions on ACKER variation

Revision 1.3  1999/09/16 00:15:45  srtaylor
Outputs correct results for multiple dimensions

Revision 1.2  1999/07/14 15:57:44  bronis
Fixed DEC text_t warnings

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_aux.h"
#include "sphinx_error.h"
#include "sphinx_tools.h"
#include "sphinx_post.h"

/* private prototypes */
static char   *read_all_lists_of_next_meas (void);
static int     read_one_list_of_meas       (int index, char *meas);
static int     find_meas                   (int index, char *search);
static char   *skip_to_next_meas           (int index);
static int     init_post_proc              (char *input_file_name);
static void    free_post_proc              (void);
static void    free_all_lists              (void);
static data_t *interpolate_data            (int value, data_t *left, 
					    data_t *right, data_t *data);
static int     all_finished                (int *vector);
       int     data_cmp (const void *d1,const void *d2); /* for qsort */
					 

/* private globals */
static int
  nif,                      /* number of input files */
  *finished;                /* used to determine termination in 
			       combine_lists */
static FILE 
  **input_files;            /* array of nif input files */

static data_list_t          
  *lists;                   /* array of nif data_lists */ 

static list_item_t
  **items;                  /* array of nif pointers to list_items */

static data_t
  *new_data;                /* array of nif data elements */

static text_t               
  header;                   /* the textlines of the header */

static char
  m_name[FN_LEN];         /* name of measurement */


/* THIS ROUTINE IS BROKEN - IT DOES NOT UNDERSTAND SOME OF CURRENT OUTPUT */

/*
   @FUN:
   @DOES: complete postprocessing.
   @PARAMETERS: name of input_file (which is the outputfile in sphinx usually)
   a pointer to the array of measurements (not needed now, because
   measurement_data_to_gpl_command_file and  measurement_data_to_tex_module
   have been eliminated since now implemented in the perl-script dorep.pl.
   nom: number of measurements. (some as with ms).
   @RETURNES: TRUE. (return-type is int for further errormamagement)
   @SIDEEFFECTS: aborts in case of error.
   @ASSUMES: params-struct is filled when called.
*/
int
post_processing (char *input_file_name)
{
  FILE
    *output_file;
  
  data_list_t
    result_list;

  char
    no_runs_str[0x100];

  init_post_proc (input_file_name);

  if (nif == 0)  
    return (TRUE); /* nothing to do, if only one outputfile exists */

  init_list (&result_list);

  if ((output_file = fopen (input_file_name,"w")) == NULL)
  {
    sprintf (_sphinx_msg,"opening output file %s\n", input_file_name);
    ERROR (FILE_OPEN,_sphinx_msg);
    output_error (TRUE);
  }

  sprintf (no_runs_str,"%d times.", nif);

  write_head_of_outfile (&output_file,no_runs_str);
  
  while (read_all_lists_of_next_meas() != NULL)  /* the header is read here */
  {
#ifndef MODULE_TEST
    combine_lists (&result_list);
    free_all_lists ();
    output_file = write_header (output_file, header, m_name);
    free_text (header);
    if (write_to_file (&result_list, output_file,
                       result_list.list_start->data.num_dims, NULL, FALSE) != 
	DL_NO_ERROR)
    {
      ERROR (FILE_WRITE,"postprocessing output\n");
      output_error (TRUE);
    }
    free_data_list (&result_list, STATIC);
#else
    int
      a;
    for (a = 0; a < nif; a++)
      write_to_file (lists + a, stderr, *(lists + a).yarg_valid, NULL, FALSE);
    write_header (stderr, header, m_name);
    free_all_lists ();
    free_data_list (&result_list, STATIC);
#endif

  }
  fprintf (output_file,"/*@""no*/\n%s-postprocessed", FINISHED_MSG);  
  fclose (output_file);
  
  free_post_proc();
  return (TRUE);
}

/*
   @FUN:
   @DOES: initializes all static variables of this module and
   opens all input_files (== output_files of sphinx).
   @PARAMETERS: name of input_file.
   @RETURNES: TRUE. (return-type is int for further errormamagement)
   @SIDEEFFECTS: aborts in case of error.
   @ASSUMES: nothing.
*/
int 
init_post_proc (char *input_file_name)
{
  FILE
    *file;
  
  int
    i;

  char
    n_name[FN_LEN];
 
  nif = number_of_output_files (input_file_name);
  /* note that nomenclatura in module sphinx_tools is reverse
     to here: output_files there are the input_files here */
    
  /* if there are other output-files and 
     if input_file exists and is not a previous postprocessed file
     rename it to input_file_name.<nif + 1> */
  if ((nif > 0) && ((file = fopen (input_file_name,"r")) != NULL))
  {
    if (!output_file_postprocessed (file))
    {
      fclose (file);
      rename (input_file_name, new_name (input_file_name));
      nif++;
    }
    else
      fclose (file);
  }

  if (nif == 0)
    return (TRUE);

  /* allocating around */
  if ((input_files = malloc (nif * sizeof (FILE *))) == NULL)
  {
    ERROR(NO_MEM,"for postprocessing - 1");
    output_error (TRUE);
  }

  if ((lists = malloc (nif * sizeof (data_list_t))) == NULL)
  {
    ERROR(NO_MEM,"for postprocessing - 2");
    output_error (TRUE);
  }

  if ((items =  malloc (nif * sizeof (list_item_t *))) == NULL)
  {
    ERROR(NO_MEM,"for postprocessing - 3");
    output_error (TRUE);
  }

  if ((new_data = malloc (nif * sizeof (data_t))) == NULL)
  {
    ERROR(NO_MEM,"for postprocessing - 4");
    output_error (TRUE);
  }

  if ((finished = malloc (nif * sizeof (int))) == NULL)
  {
    ERROR(NO_MEM,"for postprocessing - 5");
    output_error (TRUE);
  }

  /* initialize the whole stuff */
  for (i = 0; i < nif; i++)
  {
    new_data[i].status = NULL;

    sprintf (n_name,"%s.%d", input_file_name, i + 1);
    if ((input_files[i] = fopen (n_name,"r")) == NULL)
    {
      sprintf (_sphinx_msg,"file: %s\n", n_name);
      ERROR(FILE_OPEN,_sphinx_msg);
      output_error (TRUE);
    }
    init_list (lists + i);
    items[i] = NULL;
  }

  return (TRUE);
}


/*
   @FUN:
   @DOES: free-es all allocated memory for internal use and closes all
   here opened files
   @PARAMETERS: none.
   @RETURNES: nothing.
   @SIDEEFFECTS: on the internal variables.
   @ASSUMES: init_post_proc run before.
*/
void
free_post_proc (void)
{
  int
    i;

  for (i = 0; i < nif; i++) {
    fclose (input_files[i]);
    if (new_data[i].status != NULL)
      free (new_data[i].status);
  }

  free (finished);
  free (new_data);
  free (items);
  free (input_files);
  free (lists);  /* the single lists are freeed in free_all_lists */
}

/*
   @FUN:
   @DOES: free-es all data elements of every list.
   It does NOT free the array of lists (this is done in free_post_proc.)
   @PARAMETERS: none.
   @RETURNES: nothing
   @SIDEEFFECTS: on the data stored in the lists.
   @ASSUMES: nothing.
*/
void
free_all_lists (void)
{
  int
    i;

  for (i = 0; i < nif; i++)
    free_data_list (lists + i, STATIC);
}

/*
   @FUN:
   @DOES: skips to next measurement of file input_files[index]
   returnes name of that measurement
   @PARAMETERS: above.
   @RETURNES: name of the measurement found or NULL in case of EOF.
   @SIDEEFFECTS: on file pointer input_files[index]
   @ASSUMES: input_file[index] open (i.e. init_post_proc called before).
*/
char *
skip_to_next_meas (int index)
{
  static char
    line[LINE_LEN];

  char
    *local;
    
  do
    if (fgets (line, LINE_LEN, input_files[index]) == NULL)
      return (NULL);  /* eof reached */
  while ((local = strstr (line,"@in")) == NULL);

  return (local + strlen ("@in"));
}

/*
   @FUN:
   @DOES: finds measurement with the name *search in input_file[index]
   @PARAMETERS: additional: name of measurement to look for.
   @RETURNES:    returns TRUE iff found FALSE otherwise
   @SIDEEFFECTS: on file pointer input_files[index]
   @ASSUMES: input_file[index] open (i.e. init_post_proc called before).
*/
int
find_meas (int index, char *search)
{
  static char
    line[LINE_LEN];

  do
    if (fgets (line, LINE_LEN, input_files[index]) == NULL)
      return (FALSE);  /* eof reached */
  while (strstr (line,search) == NULL);

  return (TRUE);
}


/*
   @FUN:
   @DOES: reads measurement with the name *meas in input_file[index]
   into the list addressed by lists[index].
   @PARAMETERS: additional: name of measurement to look for.
   @RETURNES:    returns TRUE iff found FALSE otherwise
   @SIDEEFFECTS: on file pointer input_files[index] and on lists[index]
   @ASSUMES: input_file[index] open (i.e. init_post_proc called before).
*/
int
read_one_list_of_meas (int index, char *meas)
{
  int
    error = DL_NO_ELEM;

  char
    *next_meas;
  
#ifdef POSIX
  fpos_t
    fpos;

  fgetpos (input_files[index], &fpos);
#else
  long int
    filepos = ftell (input_files[index]);
#endif

  next_meas = skip_to_next_meas (index);

  if (next_meas == NULL) /* eof reached */
    return (FALSE);

  if (!strcmp (next_meas, meas))  /* next meas is the wanted */
    read_from_file (lists + index, input_files + index, &error);
  else /* so we have to find it */
  {
#ifdef POSIX
    fsetpos (input_files[index], &fpos); 
#else
    fseek (input_files[index], filepos, 0); /* 0 == SEEK_SET */
#endif
    if (find_meas (index, meas))
      read_from_file (lists + index, input_files + index, &error);

#ifdef POSIX
    fsetpos (input_files[index], &fpos); 
#else
    fseek (input_files[index], filepos, 0); /* 0 == SEEK_SET */
#endif
    /* jump back to old pos, because the next measurement tends to be there */
  }
  return (error == DL_NO_ERROR);
}


/*  */
/*
   @FUN:
   @DOES: reads all lists of next measurtement (the next means the next in 
   input_files[0]) and stores the read data in the lists **lists.
   @PARAMETERS: additional: name of measurement to look for.
   @RETURNES: returnes name of that meas iff success
   @SIDEEFFECTS: on file pointers input_files and on lists.
   @ASSUMES: init_post_proc called before.
*/
char *
read_all_lists_of_next_meas (void)
{
  int
    i,
    error;

  char
    *name;

  /* get the name of the next meas */
  if ((name = skip_to_next_meas (0)) == NULL)
    return (NULL); /* eof reached */

  strcpy (m_name,name);
  read_header (input_files[0], header);
  read_from_file (lists, input_files, &error);
  D4(fprintf(stderr,"*************** 0000 ***************\n");)
  D4(write_to_file (lists,stderr, lists->yarg_valid, NULL, FALSE);)
  /* read them all */
  for (i = 1; i < nif; i++)
  {
    if (!read_one_list_of_meas (i, m_name))
    {
      sprintf (_sphinx_msg,"input_files %d, at measurement %s\n", i, m_name);
      ERROR(FILE_READ,_sphinx_msg);
      output_error (TRUE);
    }
    D4(fprintf(stderr,"*************** %d%d%d%d ***************\n",i,i,i,i);)
    D4(write_to_file (lists,stderr, lists->yarg_valid, NULL, FALSE);)
  }
  return (m_name);
}

/*
   @FUN:
   @DOES: combines all lists of the **lists-array to one new result_list.
   @PARAMETERS: above.
   @RETURNES: TRUE if result_list conaines really data elements.
   @SIDEEFFECTS: if result_list == NULL it is allocated and initialized.
   Aborts in case of error.
   @ASSUMES: result list is initialized unless it is NULL.
*/
int 
combine_lists (data_list_t *result_list)
{
  int
    i,
    error,
    inter_arg;   /* the argument where to interpolate */

  /* the usual checks... */
  if (result_list == NULL)
    if ((result_list = init_list (NULL)) == NULL)
    {
      ERROR(NO_MEM,"for result_list");
      output_error (TRUE);
    }
  

  /* fill items with the first list elements */
  for (i = 0; i < nif; i++)
  {
    items[i] = item_addr (lists + i, START, 0, &error); 
    finished[i] = FALSE;
  }
 

  while (! all_finished (finished))
  {
    data_t
      result_data;

    result_data.status = NULL;

    /* find min arg: the arg where to interpolate */
    inter_arg = (items[0])->data.arg[0];
    for (i = 1; i < nif; i++)
      if (finished[i] != TRUE)
	/* THIS IS A HACK - ASSUMES ONE INDEPENDENT VARIABLE... */
	if ((items[i])->data.arg[0] < inter_arg)
	  inter_arg = (items[i])->data.arg[0];
    
    for (i = 0; i < nif; i++)  /* for all lists */
    {
      list_item_t
	*left;

      /* find the right arg (need for interpolation) */
      if (finished[i] != TRUE)
	/* find ele right of inter_arg */
	while ((items[i])->data.arg[0] <= inter_arg) 
	{
	  /* read next ele */
	  items[i] = item_addr_at_item (lists + i, items[i], 1, &error);
	  if (is_end (items[i]))
	    break;  /* the while loop */
	}

      if (is_end (items[i]) && (items[i])->data.arg[0] == inter_arg)
      {
	copy_data(new_data + i, &(items[i]->data));  /* last ele */
	finished[i] = TRUE;  /* this list reached its end */
      }
      else
      {
	if (((items[i])->data.arg[0] <= inter_arg) || (finished[i] == TRUE))  
	{  
	  /* there no right ele, so mark as invalid */
	  new_data[i].arg[0] = -1;  
	  new_data[i].count = 0;
	  new_data[i].result = 0.0;
	  new_data[i].standard_deviation = 0.0;
	  new_data[i].num_dims = 0;
	  finished[i] = TRUE;  /* this list reached its end */
	}
	else /* so found a 'right' element */
	{	
	  if (is_start (items[i])) 
	  {  /* right ele is the first (so no real left) */
	    new_data[i].arg[0] = -1; /* mark as invalid */
	    new_data[i].count = 0;
	    new_data[i].result = 0.0;
	    new_data[i].standard_deviation = 0.0;
	    new_data[i].num_dims = 0;
	  }
	  else /* found left and right */
	  {
	    left = item_addr_at_item (lists + i, items[i], -1, &error);
	    if (left->data.arg[0] != inter_arg)  /* have to interpolate */
	      interpolate_data (inter_arg, &(left->data), &((items[i])->data), 
				new_data + i);
	    else /* so nothing to interpolate */
	    {
	      new_data[i].arg[0] = inter_arg;
	      new_data[i].count = left->data.count;
	      new_data[i].result = left->data.result;
	      new_data[i].standard_deviation = left->data.standard_deviation;
	      new_data[i].num_dims = left->data.num_dims;
	      if (left->data.status != NULL)
		mark_status (&new_data[i], left->data.status);
	    }
	  }
	}
      }
    }

    if (post_process (new_data, &result_data) != NULL)
      append(result_list, &result_data, &error);

    for (i = 0; i < nif; i++) { /* for all lists */
      if (new_data[i].status != NULL) {
	free (new_data[i].status);
	new_data[i].status = NULL;
      }
    }

    if (result_data.status != NULL) {
      free (result_data.status);
      result_data.status = NULL;
    }
  }
  return (number_of_elements (result_list) > 0);
}

/*
   @FUN:
   @DOES: tests if all entries in vector are TRUE.
   @PARAMETERS: above.
   @RETURNES: TRUE iff all elements of vector are TRUE,
   FALSE otherwise.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
all_finished (int *vector)
{
  int
    i;

  for (i = 0; i < nif; i++)
    if (vector[i] == FALSE)
      return (FALSE);

  return (TRUE);
}

/*
   @FUN:
   @DOES: interpolates a complete data_t-struct at value (relative to 
   entry arg) between left and right.
   @PARAMETERS: bove.
   @RETURNES: pointer to the interpolated data-struct.
   @SIDEEFFECTS: allocates new data element if data == NULL.
   @ASSUMES: nothing.
*/
data_t *
interpolate_data (int value, data_t *left, data_t *right, data_t *data)
{
  if (data == NULL)
    if ((data = malloc (sizeof (data_t))) == NULL)
    {
      ERROR(NO_MEM,"in interpolate_data");
      output_error (TRUE);
    }
 
  /* ALERT - HACK!!!!! */
  data->arg[0] = value;
  data->result = linear_interpolate (value, left->arg[0], right->arg[0],
				     left->result, right->result);
  /* lin._inter. is found in sphinx_tools.c */

  data->count = SPHINX_MIN(left->count,right->count);
  data->standard_deviation = SPHINX_MIN(left->standard_deviation,
					right->standard_deviation);

  return (data);
}

/*
   @FUN:
   @DOES: this is the founction which really decides how to merge
   several data-struct (stored in the array new_data) to one (result_data).
   @PARAMETERS: above.
   @RETURNES: a pointer to result_data.
   @SIDEEFFECTS: none.
   @ASSUMES: nif set.
*/
data_t *
post_process (data_t *new_data, data_t *result_data)
{
  int
    i,
    median_at, 
    rep_sum = 0;
  
  /* find median, ignore invalid data-eles */

  qsort (new_data, nif, sizeof (data_t), &data_cmp);
  for (i = 0; i < nif; i++)
    rep_sum += new_data[i].count;

  median_at = rep_sum / 2;
  
  /* if all elements are invalid, the for loop quits immediately */
  /* WHICH LEAVES i = 0 WHICH CAUSES A BAD REFERENCE! UGH! */
  /* KNOWINGLY LEAVING BAD CODE AS IF IT WERE GOOD IS RIDICULUS */
  for (rep_sum = i = 0; rep_sum < median_at; i++)
    rep_sum += new_data[i].count;

  /* LET'S TRY SHORT CIRCUITING THIS BUG */
  if (i == 0)
    return NULL;

  copy_data(result_data, new_data + (i - 1));

  return (result_data);
}

/*
   @FUN:
   @DOES: compares the results of two data_t-structs, used for qsort-calls
   @PARAMETERS: two pointers to data_t-structs d1, d2
   @RETURNES: 0 iff equal, -1 iff d1 < d2, 1 else
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
data_cmp (const void *d1,const void *d2)
{
  if (((data_t *)d1)->result < ((data_t *)d2)->result)
    return (-1);
  else
    return (((data_t *)d1)->result > ((data_t *)d2)->result);
}






