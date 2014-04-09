/*
$Log: data_list.c,v $
Revision 1.14  2000/09/06 21:09:13  bronis
Added several OpenMP versions for Alpha clusters in various states of correctness

Revision 1.13  2000/08/25 23:17:16  bronis
Added OpenMP tests

Revision 1.12  2000/03/16 15:48:39  bronis
fixed mpguidec warnings

Revision 1.11  2000/01/10 21:50:23  bronis
Added full blown aux tests implementation

Revision 1.10  1999/10/29 00:11:10  bronis
Fixed bugs, made input case insensitive

Revision 1.9  1999/10/20 23:02:47  bronis
Fixed post processing core dumps

Revision 1.8  1999/10/04 21:29:33  bronis
first cut at output filters

Revision 1.7  1999/10/04 15:53:05  bronis
fixed ACKer position bugs

Revision 1.6  1999/10/01 21:36:52  bronis
Added debugged Root variation

Revision 1.5  1999/09/29 00:23:47  bronis
removed most restrictions on ACKER variation

Revision 1.4  1999/09/16 00:15:45  srtaylor
Outputs correct results for multiple dimensions

Revision 1.3  1999/09/15 15:52:29  bronis
partial fix of data_list.c

Revision 1.2  1999/07/09 22:11:44  srtaylor
Remove debug output

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_error.h"
#include "sphinx_threads.h"


/*
   @FUN:
   @DOES: initializes the data list l to the empty list.
   @PARAMETERS: pointer to tghe list l.
   @RETURNES: the adress of the list, or
   NULL iff no memory available.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
data_list_t *
init_list(data_list_t *l)
{
  if (l == NULL)
    if ((l = (data_list_t *) malloc (sizeof (data_list_t))) == NULL)
    {
#if 0
      *error = DL_NO_MEM;
#endif
      return (NULL);
    }

  l->list_start = l->list_end =l->list_last = NULL;
  l->number = 0;

  return (l);
}

/*
   @FUN:
   @DOES: initializes the data list l to num_lists empty lists.
   @PARAMETERS: number of lists
   @RETURNES: the address of the list, or
   NULL iff no memory available or num_lists is not positive.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
data_list_t *
init_list_array(int num_lists)
{
  data_list_t *l;
  int          i;

  if (num_lists < 1) {
    /* complain */
    fprintf (stderr, "Number of lists must be positive in multi_init_list\n");
    return (NULL);
  }

  if ((l = (data_list_t *) malloc (sizeof(data_list_t)*num_lists)) == NULL) {
#if 0
    *error = DL_NO_MEM;
#endif
    return (NULL);
  }

  for (i = 0; i < num_lists; i++) {
    l[i].list_start = l[i].list_end =l[i].list_last = NULL;
    l[i].number = 0;
  }

  return (l);
}

/*
   @FUN:
   @DOES: adds data data element (*data) to the list *l at the position
   pos relative to start or list (mode == START), or end (mode == END), or
   to last accessed alement (mode == LAST).
   @PARAMETERS: (add. to above) *error, in which the error code is
   retuned.
   @RETURNES: pointer to list, or
   NULL in case of error.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
data_list_t *
add (data_list_t *l, int mode, signed int pos, data_t *data, int *error)
{
  list_item_t
    *local_data = NULL,           /* stores new data */
    *local_ptr = NULL;            /* moving around in list */

  signed int i;

  if (l == NULL)           /* nothing allocated so far */
  {
    if ((l = (data_list_t *) malloc (sizeof (data_list_t))) == NULL)
    {
      *error = DL_NO_MEM;
      return (NULL);
    }
    init_list (l);
  }


  if ((local_data = (list_item_t *) malloc (sizeof (list_item_t))) == NULL)
  {
    *error = DL_NO_MEM;
    return (l);
  }

  switch (mode)
  {
  case START:
    local_ptr = l->list_start;
    break;
  case LAST:
    local_ptr = l->list_last;
    break;
  case END:
    local_ptr = l->list_end;
    break;
  }

  /* THIS COMMENT IS MISLEADING */
  /* NEW ELEMENT IS INSERTED NEARER TO TAIL... */
  /* findung right position in the list
     local_data is inserted BEHIND local_ptr,
     so local_ptr may be NULL (if local_ptr should be new start of list)
     but may NEVER exceed the list */
  if (pos >= 0)
  {
    for (i = 0; i < pos; i++)
      if (local_ptr->next == NULL)
	break;
      else
	local_ptr = local_ptr->next;
  }
  else
  {
    for (i = 0; i < (-1)*pos; i++)
      if ((local_ptr = local_ptr->prev) == NULL)
	break;
  }

  /* inserting new data */

  copy_data (&(local_data->data), data);
  local_data->prev = local_ptr;
  local_data->next = NULL;

  if (local_ptr != NULL) /* not first element */
  {
    local_data->next = local_ptr->next;
    if (local_ptr->next != NULL)
      local_ptr->next->prev = local_data;

    local_ptr->next = local_data;
  }
  else
  {
    if (l->list_start != NULL) {
      local_data->next = l->list_start;
      l->list_start->prev = local_data;
    }
    l->list_start = local_data;
  }


  /* updating descriptor information */
  l->number++;

  if ((mode == END) && (pos == 0))
    l->list_end = local_data;

  l->list_last = local_data;

  *error = DL_NO_ERROR;
  return (l);
}

/*
   @FUN:
   @DOES: reads data data element (*data) of the list *l at the position
   pos relative to start or list (mode == START), or end (mode == END), or
   to last accessed element (mode == LAST).
   @PARAMETERS: (add. to above) *error, in which the error code is
   retuned.
   @RETURNES: pointer to list, or
   NULL in case of error.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
data_t *
read_ele (data_list_t *l, int mode, signed int pos,
	  data_t *data, int *error)
{
  list_item_t *local_ptr = NULL;
  signed int i;

  if (l == NULL)
  {
    *error = DL_NO_MEM;
    return (NULL);
  }

  if (l->list_start == NULL || l->list_start == NULL)
  {
    *error = DL_NO_MEM;
    return (NULL);
  }

  switch (mode)
  {
  case START:
    local_ptr = l->list_start;
    break;
  case LAST:
    local_ptr = l->list_last;
    break;
  case END:
    local_ptr = l->list_end;
    break;
  }


  /* findung right position in the list */
  if (pos >= 0)
  {
    for (i = 0; i < pos; i++)
      if (local_ptr->next == NULL)
	break;
      else
	local_ptr = local_ptr->next;
  }
  else
  {
    for (i = 0; i < (-1)*pos; i++)
      if (local_ptr->prev == NULL)
	break;
      else
	local_ptr = local_ptr->prev;
  }

  copy_data (data, &(local_ptr->data));

  l->list_last = local_ptr;

  return (data);
}

/*
   @FUN:
   @DOES: reads data data element (*data) of the list *l at the position
   pos relative to the element pointed to with local_ptr.
   @PARAMETERS: (add. to above) *error, in which the error code is
   retuned.
   @RETURNES: pointer to list, or
   NULL in case of error.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
data_t *
read_item_ele (data_list_t *l, list_item_t *local_ptr, signed int pos,
	       data_t *data, int *error)
{
  signed int i;

  if (l == NULL)
  {
    *error = DL_NO_MEM;
    return (NULL);
  }

  if (l->list_start == NULL || l->list_start == NULL || local_ptr == NULL)
  {
    *error = DL_NO_MEM;
    return (NULL);
  }

  /* finding right position in the list */
  if (pos >= 0)
  {
    for (i = 0; i < pos; i++)
      if (local_ptr->next == NULL)
	break;
      else
	local_ptr = local_ptr->next;
  }
  else
  {
    for (i = 0; i < (-1)*pos; i++)
      if (local_ptr->prev == NULL)
	break;
      else
	local_ptr = local_ptr->prev;
  }

  copy_data (data, &(local_ptr->data));

  l->list_last = local_ptr;

  return (data);
}

/*
   @FUN:
   @DOES: returns the address of the data element of the list *l 
   at the position
   pos relative to start or list (mode == START), or end (mode == END), or
   to last accessed element (mode == LAST).
   @PARAMETERS: (add. to above) *error, in which the error code is
   returned.
   @RETURNES: pointer to list, or
   NULL in case of error.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
list_item_t *
item_addr (data_list_t *l, int mode, signed int pos, int *error)
{
  list_item_t *local_ptr = NULL;
  signed int i;

  if (l == NULL)
  {
    *error = DL_NO_MEM;
    return (NULL);
  }

  if (l->list_start == NULL || l->list_start == NULL)
  {
    *error = DL_NO_MEM;
    return (NULL);
  }

  switch (mode)
  {
  case START:
    local_ptr = l->list_start;
    break;
  case LAST:
    local_ptr = l->list_last;
    break;
  case END:
    local_ptr = l->list_end;
    break;
  }


  /* findung right position in the list */
  if (pos >= 0)
  {
    for (i = 0; i < pos; i++)
      if (local_ptr->next == NULL)
	break;
      else
	local_ptr = local_ptr->next;
  }
  else
  {
    for (i = 0; i < (-1)*pos; i++)
      if (local_ptr->prev == NULL)
	break;
      else
	local_ptr = local_ptr->prev;
  }

  l->list_last = local_ptr;

  return (local_ptr);
}

/*
   @FUN:
   @DOES: returns the address of the data element of the list *l 
   at the position
   pos relative to the element pointed to with local_ptr.
   @PARAMETERS: (add. to above) *error, in which the error code is
   retuned.
   @RETURNS: pointer to list, or
   NULL in case of error.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
list_item_t *
item_addr_at_item (data_list_t *l, list_item_t *local_ptr, signed int pos, 
		   int *error)
{
  signed int 
    i;

  if (l == NULL)
  {
    *error = DL_NO_MEM;
    return (NULL);
  }

  if (l->list_start == NULL || l->list_start == NULL || local_ptr == NULL)
  {
    *error = DL_NO_MEM;
    return (NULL);
  }

  /* findung right position in the list */
  if (pos >= 0)
  {
    for (i = 0; i < pos; i++)
      if (local_ptr->next == NULL)
	break;
      else
	local_ptr = local_ptr->next;
  }
  else
  {
    for (i = 0; i < (-1)*pos; i++)
      if (local_ptr->prev == NULL)
	break;
      else
	local_ptr = local_ptr->prev;
  }

  return (local_ptr);
}

/*
   @FUN:
   @DOES: tests if *item is the last elemnt of its list
   @PARAMETERS: item of a list *item
   @RETURNES: TRUE iff last element
   @SIDEEFFECTS: none.
   @ASSUMES: item != NULL.
*/
int
is_end (list_item_t *item)
{
  return (item->next == NULL);
}

/*
   @FUN:
   @DOES: tests if *item is the first elemnt of its list
   @PARAMETERS: item of a list *item
   @RETURNES: TRUE iff first element
   @SIDEEFFECTS: none.
   @ASSUMES: item != NULL.
*/
int
is_start (list_item_t *item)
{
  return (item->prev == NULL);
}

/*
   @FUN:
   @DOES: returnes number of elements of the list *l.
   @PARAMETERS: above
   @RETURNES: above
   @SIDEEFFECTS: none
   @ASSUMES: nothing.
*/
int 
number_of_elements (data_list_t *l)
{
  if (l == NULL)
    return (0);
  else
    return (l->number);
}


/*
   @FUN:
   @DOES: removes data data element of the list *l at the position
   pos relative to start or list (mode == START), or end (mode == END), or
   to last accessed alement (mode == LAST).
   @PARAMETERS: above.
   @RETURNES: pointer to list, or
   NULL in case of error.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
data_list_t *
remove_ele (data_list_t *l, int mode, signed int pos)
{
  signed int i;
  list_item_t *local_ptr = NULL;

  if (l == NULL)
    return (NULL);

  if (l->list_start == NULL || l->list_start == NULL)
    return (NULL);

  switch (mode)
  {
  case START:
    local_ptr = l->list_start;
    break;
  case LAST:
    local_ptr = l->list_last;
    break;
  case END:
    local_ptr = l->list_end;
    break;
  }

  /* finding right position in the list */
  if (pos >= 0)
  {
    for (i = 0; i < pos; i++)
      if (local_ptr->next == NULL)
	break;
      else
	local_ptr = local_ptr->next;
  }
  else
  {
    for (i = 0; i < (-1)*pos; i++)
      if (local_ptr->prev == NULL)
	break;
      else
	local_ptr = local_ptr->prev;
  }

  if (local_ptr->next != NULL) /* if not last element */
    local_ptr->next->prev = local_ptr->prev;
  else /* so last ele */
  {
    if (local_ptr->prev != NULL)  /* if not first element */
      local_ptr->prev->next = NULL;
    l->list_end = local_ptr->prev;
  }

  if (local_ptr->prev != NULL)  /* if not first element */
    local_ptr->prev->next = local_ptr->next;
  else /* so first ele */
  {
    if (local_ptr->next != NULL) /* if not last element */
      local_ptr->next->prev = NULL;
    l->list_start = local_ptr->next;
  }

  if (local_ptr->data.status != NULL)
    free (local_ptr->data.status);

  free (local_ptr);

  l->number--;

  return (l);
}

/*
   @FUN:
   @DOES: free-es all elements of the datalist *l and (only if 
   mode == DYNAMIC) also the memory pointed by l. If ths in not
   wanted (e.g. because l is adress of statically allocated variable)
   call with mode == STATIC.
   @PARAMETERS: above
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
void 
free_data_list (data_list_t *l, int mode)
{
  if (l == NULL)
    return;

  if ((l->list_start == NULL) || (l->list_start == NULL))
    return;

  if (l->list_start->data.status != NULL)
    free (l->list_start->data.status);

  while ((l->list_start = l->list_start->next) != NULL) {
    if (l->list_start->data.status != NULL)
      free (l->list_start->data.status);

    free (l->list_start->prev);
  }

  /* freeing last element */
  free (l->list_end);

  if (mode == DYNAMIC)
    free (l);
  else
    init_list (l);
}

/*
   @FUN:
   @DOES: frees all elements of the datalist *l and (only if 
   mode == DYNAMIC) also the memory pointed to by l. If this is not
   wanted (e.g. because l is address of statically allocated variable)
   call with mode == STATIC.
   @PARAMETERS: above
   @RETURNES: nothing.
   @SIDEEFFECTS: none (The whole thing is a side effect; ...)
   @ASSUMES: num_lists is correct...
*/
void 
free_data_list_array (data_list_t *l_array, int mode, int num_lists)
{
  int i;

  if (l_array == NULL)
    return;

  for (i = 0; i < num_lists; i++) {
    if ((l_array[i].list_start == NULL) || (l_array[i].list_start == NULL))
      continue;

    if (l_array[i].list_start->data.status != NULL)
      free (l_array[i].list_start->data.status);

    while ((l_array[i].list_start = l_array[i].list_start->next) != NULL) {
      if (l_array[i].list_start->data.status != NULL)
	free (l_array[i].list_start->data.status);

      free (l_array[i].list_start->prev);
    }

    /* freeing last element */
    free (l_array[i].list_end);

    if (mode != DYNAMIC)
      init_list (&l_array[i]);
  }

  if (mode == DYNAMIC)
    free (l_array);
}

/* ********* statistical routines **************** */


/*
   @FUN:
   @DOES: find the minimum of the list *l, returnes the argument, of the 
   minimal element.
   (needs the structure of the data stored in a list element)
   @PARAMETERS: above.
   @RETURNES: above.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
#define square(a) ((a)*(a))

double 
minimum (data_list_t *l, int *arg)
{
  list_item_t *local;
  double mini = -1.0;

  if (l != NULL)
  {
    if (l->list_start != NULL)
    {
      local = l->list_start;
      mini = local->data.result;
      /* this is a hack; really need new parameter specifying which arg */
      *arg = local->data.arg[0];
      while ((local = local->next) != NULL)
	if (local->data.result < mini)
	{
	  mini = local->data.result;
	  *arg = local->data.arg[0];
	}
    }
  }
  return (mini);
}

/*
   @FUN:
   @DOES: find the maximum of the list *l, returnes the argument, of the 
   maximal element.
   (needs the structure of the data stored in a list element)
   @PARAMETERS: above.
   @RETURNES: above.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
double 
maximum (data_list_t *l,int *arg)
{
  list_item_t *local;
  double maxi = -1.0; /* we assume only positive results !!! */

  if (l != NULL)
  {
    if (l->list_start != NULL)
    {
      local = l->list_start;
      maxi = local->data.result;
      /* this is a hack; really need new parameter specifying which arg */
      *arg = local->data.arg[0];
      while ((local = local->next) != NULL)
	if (local->data.result > maxi)
	{
	  maxi = local->data.result;
	  *arg = local->data.arg[0];
	}
    }
  }
  return (maxi);
}

/*
   @FUN:
   @DOES: returnes the variance of the list *l
   (needs the structure of the data stored in a list element)
   @PARAMETERS: above.
   @RETURNES: above.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
double 
variance (data_list_t *l)
{
  list_item_t *local;
  double sum=0.0,
    avg;

  if (l == NULL)
    return (-1.0);

  if (l->list_start == NULL)
    return (-1.0);

  avg = average (l);
  local = l->list_start;
  sum = square(local->data.result - avg);
  while ((local = local->next) != NULL)
    sum += square(local->data.result - avg);

  return (sum / (l->number - 1));
}

/*
   @FUN:
   @DOES: creates a new list, where the i-th data element it the
   average of all i-th elements of the datalists given in the 
   (NULL-terminated!) array of lists l.
   (needs the structure of the data stored in a list element)
   @PARAMETERS: above.
   @RETURNES: new list,
   NULL in case if error.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
data_list_t *
average_of_lists (data_list_t **l)
{
  data_list_t 
    *avg_list;

  double
    avg = 0.0;

  int
    n = 0,
    i,
    j,
    list_error;

  data_t
    data;

  if ((avg_list = init_list (NULL)) == NULL)
    return (NULL);

  while (l[n] != NULL)
  {
    read_ele(l[n++], START, 0, &data, &list_error);
    avg += data.result;
  }

  avg /= n;

  data.result = avg;

  append (avg_list, &data, &list_error);
  if (list_error != DL_NO_ERROR)
    return (NULL);

  for (i = 0; i < l[0]->number - 1; i++)
  {
    avg = 0.0;
    for (j = 0; j < n; j++)
    {
      read_ele(l[j], LAST, 1, &data, &list_error);
      avg += data.result;
    }

    avg /= n;

    data.result = avg;
    append (avg_list, &data, &list_error);
    if (list_error != DL_NO_ERROR)
      return (NULL);

  }
  return (avg_list);
}


double 
median (data_list_t *l)
{ /* dummy */
  return (0.0);
}

/*
   @FUN:
   @DOES: returnes the average of the list *l.
   (needs the structure of the data stored in a list element)
   @PARAMETERS: above.
   @RETURNES: above.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
double 
average (data_list_t *l)
{
  list_item_t *local;
  double sum;

  if (l == NULL)
    return (-1.0);

  if (l->list_start == NULL)
    return (-1.0);

  local = l->list_start;
  sum = local->data.result;
  while ((local = local->next) != NULL)
    sum += local->data.result;
  
  return (sum / l->number);
}


/* ****************** file I/O ****************** */
/*
   @FUN:
   @DOES: writes data list *l to the file *file.
   @PARAMETERS: above
   @RETURNES: TRUE iff successful, FALSE otherwise
   @SIDEEFFECTS: none
   @ASSUMES: *file is valid handle of an open file.
*/
int 
write_to_file (data_list_t *l, FILE *file, 
	       int expected_num_dims, dimension_t *dims, int use_ref)
{
  list_item_t *local;
  int         i;

  if (l == NULL)
    return (DL_NO_ELEM);

  fprintf (file,"#");

  for (i = 0; i < expected_num_dims; i++)
    fprintf (file,"arg[%d] ", i);
    
  fprintf (file,"result standard_deviation count");

  if (use_ref)
    fprintf (file, " reference overhead percent-overhead");

  fprintf (file,"\n");      

  for (local = l->list_start; local != NULL; local = local->next) {
    if (local->data.num_dims != expected_num_dims) {
      ERROR(INTERN, "data dims different from expected");
      output_error(TRUE);
    }

    for (i = 0; i < expected_num_dims; i++)
      if ((local->data.arg[i] == UNBIND) && (dims != NULL) &&
	  ((dims[i].variation == MASTER_BINDING) ||
	   (dims[i].variation == SLAVE_BINDING)))
	/* this will break the poorly thought out post processing */
	fprintf (file, "UNBOUND ");
      else if (dims[i].variation == WORK_FUNCTION)
	fprintf (file, "%s ", translate_work_function (local->data.arg[i]));
      else if (dims[i].variation == OVERLAP_FUNCTION)
	fprintf (file, "%s ", translate_overlap_function (local->data.arg[i]));
      else if (dims[i].variation == SCHEDULE)
	fprintf (file, "%s ", translate_omp_schedule (local->data.arg[i]));
      else
	fprintf (file,"%d ",local->data.arg[i]);

    fprintf (file,"%f %f %d", local->data.result, 
	     local->data.standard_deviation, local->data.count);
    
    if (use_ref) {
      double local_ref = local->data.reference;
 
      if (local_ref != 0.0) {
	double overhead = local->data.result - local_ref;

	fprintf (file," %f %f %2f", local_ref, overhead,
		 (overhead/local_ref) * 100.0);
      }
      else {
	fprintf (file," 0.0 %f UNDEFINED", local->data.result);
      }
    }

    if (local->data.status != NULL) {
      fprintf (file," %s", local->data.status);
    }
      
    fprintf (file, "\n");
    /* output is written in microsec. */
  }

  fprintf (file,"#eol\n");
  return (DL_NO_ERROR);
}


/*
   @FUN:
   @DOES: determines stat data items for data.arg[arg_num] held constant
   in inlist and copies them into outlist with data.arg[arg_num] omitted
   @PARAMETERS: above
   @RETURNES: TRUE iff successful, FALSE otherwise (error checking soso)
   @SIDEEFFECTS: modifies outlist
   @ASSUMES: 
*/
int 
filter (int stat, data_list_t *inlist, data_list_t *outlist, int arg_num)
{
  list_item_t *local;
  int         *used;
  int         i, j, k, error, cur_index, num_dims, adj, match;
  data_t      single_data;

  if (inlist == NULL)
    return (DL_NO_ELEM);

  switch (stat) {
  case MIN:
  case MAX:
    break;
  case MEAN:
    /* should calculate standard deviation using std. dev of coalesced */
    /* data points and their counts, but I don't feel like bothering */
    single_data.standard_deviation = 0.0;
    break;
  default:
    ERROR(INTERN,"unknown statistic");
    output_error (TRUE);
  }
    
  num_dims = inlist->list_start->data.num_dims;

  single_data.num_dims = num_dims - 1;
  single_data.status = NULL;

  used = (int *) calloc (inlist->number, sizeof(int)); 

  for (i = 0; i < inlist->number; i++) {
    if (!used[i]) {
      used[i] = 1;
      
      /* get local equal to element i */
      for (local = inlist->list_start, j = 0; local != NULL && j != i; 
	   local = local->next, j++) /* NULL */;

      if (stat == MEAN) {
	/* use cur_index to count number of matching elements... */
	cur_index = 1;
      }
      else {
	/* cur_index holds index of MAX or MIN matching element... */
	cur_index = i;

	single_data.standard_deviation = local->data.standard_deviation;
      }

      single_data.result = local->data.result;
      single_data.count = local->data.count;

      if (local->data.status != NULL)
	mark_status (&single_data, local->data.status);

      /* copy current arguments into single_data */
      adj = 0;
      for (k = 0; k < num_dims; k++) 
	if (k != arg_num)
	  single_data.arg[k - adj] = local->data.arg[k];
	else
	  adj++;
      
      single_data.count = local->data.count;

      /* find stat result for this arg set... */
      for (local = local->next; local != NULL; local = local->next) {
	j++;

	match = TRUE;
	adj = 0;

	for (k = 0; k < num_dims; k++) {
	  if (k != arg_num) {
	    if (single_data.arg[k - adj] != local->data.arg[k]) {
	      match = FALSE;
	      break;
	    }
	  }
	  else {
	    adj++;
	  }
	}
	
	if (match) {
	  /* this element will not be a new arg_num value... */
	  used[j] = 1;

	  switch (stat) {
	  case MIN:
	    if (local->data.result < single_data.result) {
	      /* remember new min and its position */
	      cur_index = j;
	      single_data.result = local->data.result;
	      single_data.standard_deviation = local->data.standard_deviation;
	      single_data.count = local->data.count;

	      if (single_data.status != NULL) {
		free (single_data.status);
		single_data.status = NULL;
	      }

	      if (local->data.status != NULL)
		mark_status (&single_data, local->data.status);
	    }
	    break;
	  case MAX:
	    if (local->data.result > single_data.result) {
	      /* remember new max and its position */
	      cur_index = j;
	      single_data.result = local->data.result;
	      single_data.standard_deviation = local->data.standard_deviation;
	      single_data.count = local->data.count;

	      if (single_data.status != NULL) {
		free (single_data.status);
		single_data.status = NULL;
	      }

	      if (local->data.status != NULL)
		mark_status (&single_data, local->data.status);
	    }
	    break;
	  case MEAN:
	    /* increment count and running total */
	    cur_index++;
	    single_data.result += local->data.result;
	    single_data.count += local->data.count;
	    break;
	  default:
	    ERROR(INTERN,"unknown statistic");
	    output_error (TRUE);
	  }
	}
      }

      if (stat == MEAN)
	single_data.result = single_data.result/cur_index;
  
      append (outlist, &single_data, &error);

      if (single_data.status != NULL) {
	free (single_data.status);
	single_data.status = NULL;
      }
    }
  }

  free (used);

  return (DL_NO_ERROR);
}


/* THIS ROUTINE IS BROKEN BY REFERENCE STUFF; USE OF */
/* TRANSLATED INDEPENDENT VARIABLES... */
/*
   @FUN:
   @DOES: reads data list *l from the file **file.
   note: file is ** so that reading in file changes the filepointer,
   useful for reading consecutive lists in one file.
   @PARAMETERS: above
   @RETURNES: adress of the list read, NULL in case of error.
   @SIDEEFFECTS: none
   @ASSUMES: **file is valid handle of an open file.
*/
data_list_t * 
read_from_file (data_list_t *l, FILE **file, int *error)
{
  data_t 
    data;

  char 
    line[DL_LINE_LEN];

  char
    *temp_line;

  int
    i;

  data.num_dims = 0;
  
  if (l == NULL)           /* nothing allocated so far */
  {
    if ((l = (data_list_t *) malloc (sizeof (data_list_t))) == NULL)
    {
      *error = DL_NO_MEM;
      return (NULL);
    }
    init_list (l);
  }

  while (fgets (line, DL_LINE_LEN, *file) != NULL)  /* while not EOF */
  {
    D4(fprintf(stderr,"*** read_from_file *** line: %s\n",line);)
    if (strstr(line,"#eol"))  /* reached end of list */
      break;

    if (strstr (line,"#") == NULL && strlen (line) > 1) { 
      /* if no comment line and has content */
      data.arg[0] = atoi (strtok (line, " "));
      for (i = 1; i < data.num_dims; i++)
	data.arg[i] = atoi (strtok (NULL, " "));

      data.result = atof(strtok (NULL, " "));
      data.standard_deviation = atof(strtok (NULL, " "));

      data.count = atoi(strtok (NULL, " "));

      /* want to set status to rest of line... */
      data.status = strtok (NULL, "\0");

      append(l,&data,error);
      D4(fprintf(stderr,"** read_from_file after append**\n");)

      /* THIS CALL WOULD BE BROKEN... */
      D4(write_to_file (l,stderr, data.num_dims, the_dims, FALSE);)

    }
    else {
      /* figure num_dims (== num occurrences string arg) in output... */
      temp_line = strtok (line, " ");
      if (strstr (temp_line,"#arg") != NULL) {
	data.num_dims = 1;
	while (((temp_line = strtok (NULL, " ")) != NULL) &&
	       (strstr (temp_line,"arg") != NULL)) {
	  data.num_dims++;
	}
      }
    }
  }
  D4(fprintf(stderr,"*************** read_from_file ***************\n");)

  /* THIS CALL WOULD BE BROKEN... */
  D4(write_to_file (l,stderr, data.num_dims, the_dims, FALSE);)
  return (l);
}

void
copy_data(data_t *dd, data_t *sd) 
{
  int copy_data_index;

  (dd)->result = (sd)->result;
  (dd)->standard_deviation = (sd)->standard_deviation;
  (dd)->count = (sd)->count;
  (dd)->num_dims = (sd)->num_dims;
  (dd)->reference = (sd)->reference;

  for (copy_data_index=0; copy_data_index<(dd)->num_dims; copy_data_index++)
    (dd)->arg[copy_data_index] = (sd)->arg[copy_data_index];
  if ((sd)->status == NULL) 
    (dd)->status = NULL;
  else {
    (dd)->status = (char *) malloc (sizeof(char)*(strlen((sd)->status)+1));
    strcpy ((dd)->status, (sd)->status);
  }

  return;
}

void
mark_status (data_t *the_data, char *the_status)
{
  int slength = 0;
  char *old_status = NULL;

  /* add one to lengths for '\0'... */
  if (the_data->status != NULL) {
    old_status = the_data->status;

    /* add another one for space */
    slength = strlen(old_status) + strlen(the_status) + 2;
  }
  else {
    slength = strlen(the_status) + 1;
  }   

  the_data->status = (char *) malloc (sizeof(char) * slength);

  if (old_status != NULL) {
    strcpy (the_data->status, old_status);
    free (old_status);

    strcat (the_data->status, " ");
    strcat (the_data->status, the_status);
  }
  else {
    strcpy (the_data->status, the_status);
  }

  return;
}

#define DATA_T_MSG_TAG         27634   /* semi-random value... */
#define DATA_LIST_T_MSG_TAG    27635   /* semi-random value... */

int
get_data_pack_size (MPI_Comm comm)
{
  int dsize, isize;

  /* we use 1 for incount size packed separately... */
  MPI_Pack_size (1, MPI_DOUBLE, comm, &dsize);
  MPI_Pack_size (1, MPI_INT, comm, &isize);

  return 2 * dsize + (3 + MAX_DIMENSIONS) * isize;
}

int
pack_data (MPI_Comm comm, data_t *the_data, char *abuf, int bsize, int *pos)
{
  int status_flag, retval;

  retval = MPI_Pack (&(the_data->result), 1, MPI_DOUBLE, 
		     abuf, bsize, pos, comm);
  if (retval) return retval;

  retval = MPI_Pack (&(the_data->standard_deviation), 1, MPI_DOUBLE, 
		     abuf, bsize, pos, comm);
  if (retval) return retval;

  retval = MPI_Pack (&(the_data->count), 1, MPI_INT, abuf, bsize, pos, comm);
  if (retval) return retval;

  retval = MPI_Pack (the_data->arg, MAX_DIMENSIONS, MPI_INT, 
		     abuf, bsize, pos, comm);
  if (retval) return retval;

  retval = MPI_Pack (&(the_data->num_dims), 1, MPI_INT, 
		     abuf, bsize, pos, comm);
  if (retval) return retval;

  status_flag = (the_data->status != NULL);

  retval = MPI_Pack (&status_flag, 1, MPI_INT, abuf, bsize, pos, comm);

  return retval;
}

int
unpack_data (MPI_Comm comm, data_t *the_data, char *abuf, int bsize, int *pos)
{
  int status_flag, retval;

  retval = MPI_Unpack (abuf, bsize, pos, 
		       &(the_data->result), 1, MPI_DOUBLE, comm);
  if (retval) return retval;

  retval = MPI_Unpack (abuf, bsize, pos,
		       &(the_data->standard_deviation), 1, MPI_DOUBLE, comm);
  if (retval) return retval;

  retval = MPI_Unpack (abuf, bsize, pos, 
		       &(the_data->count), 1, MPI_INT, comm);
  if (retval) return retval;

  retval = MPI_Unpack (abuf, bsize, pos, 
		       the_data->arg, MAX_DIMENSIONS, MPI_INT, comm);
  if (retval) return retval;

  retval = MPI_Unpack (abuf, bsize, pos, 
		       &(the_data->num_dims), 1, MPI_INT, comm);
  if (retval) return retval;

  retval = MPI_Unpack (abuf, bsize, pos, &status_flag, 1, MPI_INT, comm);
  if (retval) return retval;

  /* here we assume UNSETTLED is only sendable status */
  /* really should send the string but that would be harder... */
  if (status_flag)
    mark_status (the_data, "UNSETTLED");

  return SUCCESS;
}

int
send_data (MPI_Comm comm, data_t *the_data, int dst)
{
  char *abuf;
  int position = 0;
  int retval, packsize;

  packsize = get_data_pack_size(comm);

  abuf = (char *) malloc (sizeof(char) * packsize);

  retval = pack_data (comm, the_data, abuf, 200, &position);
  if (retval) {
    free (abuf);
    return retval;
  }

  retval = MPI_Send (abuf, position, MPI_PACKED, dst, DATA_T_MSG_TAG, comm);

  free (abuf);

  if (retval) return retval;

  return SUCCESS;
}

int
recv_data (MPI_Comm comm, data_t *the_data, int src)
{
  char *abuf;
  int position = 0;
  int retval, packsize;
  MPI_Status status;

  packsize = get_data_pack_size(comm);

  abuf = (char *) malloc (sizeof(char) * packsize);

  retval = MPI_Recv (abuf, packsize, MPI_PACKED, src, 
		     DATA_T_MSG_TAG, comm, &status);
  if (retval) {
    free (abuf);
    return retval;
  }

  retval = unpack_data (comm, the_data, abuf, 200, &position);

  free (abuf);
  return retval;
}

/* in the following we assume 200 bytes is enough to pack */
/* 2 doubles and 4 ints... */
int
send_data_list (MPI_Comm comm, data_list_t *the_data_list, int dst)
{
  char *abuf;
  int position = 0;
  int retval, packsize, i;
  list_item_t *the_item;  /* ugh */

  retval = MPI_Pack_size (1, MPI_INT, comm, &packsize);
  if (retval) return retval;

  packsize += the_data_list->number * get_data_pack_size(comm);

  abuf = (char *) malloc (sizeof(char) * packsize);

  retval = MPI_Pack (&(the_data_list->number), 1, MPI_INT, 
		     abuf, packsize, &position, comm);
  if (retval) return retval;

  the_item = the_data_list->list_start;

  for (i = 0; i < the_data_list->number; i++) {
    if (the_item == NULL) return GENERIC_ERROR;

    retval = pack_data (comm, &(the_item->data), abuf, packsize, &position);
    if (retval) {
      free (abuf);
      return retval;
    }

    the_item = the_item->next;
  }

  retval = MPI_Send (abuf, position, MPI_PACKED, dst, 
		     DATA_LIST_T_MSG_TAG, comm);
  free (abuf);

  if (retval) return retval;

  return SUCCESS;
}

int
recv_data_list (MPI_Comm comm, data_list_t *the_data_list, int src)
{
  char *abuf;
  int position = 0;
  int packsize, i, num_recvd, retval;
  MPI_Status status;
  data_t the_data;

  the_data.status = NULL;

  retval = MPI_Probe (src, DATA_LIST_T_MSG_TAG, comm, &status);
  if (retval) return retval;

  MPI_Get_count (&status, MPI_PACKED, &packsize);

  abuf = (char *) malloc (sizeof(char) * packsize);

  retval = MPI_Recv (abuf, packsize, MPI_PACKED, src, 
		     DATA_LIST_T_MSG_TAG, comm, &status);
  if (retval) {
    free (abuf);
    return retval;
  }

  retval = MPI_Unpack (abuf, packsize, &position,
		       &num_recvd, 1, MPI_INT, comm);
  if (retval) {
    free (abuf);
    return retval;
  }

  for (i = 0; i < num_recvd; i++) {
    retval = unpack_data (comm, &the_data, abuf, packsize, &position);
    if (retval) {
      free (abuf);
      return retval;
    }

    append (the_data_list, &the_data, &retval);
    if (retval) {
      free (abuf);
      return retval;
    }

    if (the_data.status != NULL) {
      free (the_data.status);
      the_data.status = NULL;
    }
  }

  free (abuf);

  return SUCCESS;
}
