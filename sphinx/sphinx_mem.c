/*
$Log: sphinx_mem.c,v $
Revision 1.7  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.6  1999/09/29 00:23:48  bronis
removed most restrictions on ACKER variation

Revision 1.5  1999/09/20 19:00:40  srtaylor
Merged measure and measure_suite

Revision 1.4  1999/09/14 16:38:51  srtaylor
First cut at multiple dimensions

Revision 1.3  1999/07/29 17:02:43  bronis
Fixed bug in alignment fix

Revision 1.2  1999/07/14 22:48:07  bronis
Fixed DEC alignment problems...

Revision 1.1.1.1  1999/05/11 16:50:03  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_aux.h"
#include "sphinx_error.h"
#include "sphinx_mem.h"

extern int 
  *_mw_index;

extern char 
  **_mw_buffer;

extern MPI_Status 
  *master_stati;

extern MPI_Request 
  *_mw_req;

/* Need to know maximum msg size in p2p_find_max_min */
/* Quick and dirty solution is to make _skib_size visible */
/* so I changed its declaration from static... */
long int 
  _skib_size = 0;   /* size of sphinx internal buffer */

/* private globals */
static char 
  *_skib; /* sphinx internal buffer, used as message buffer for 
	     communication*/ 

static long int 
  _skib_used = 0;   /* bytes used of _skib */

static long int
  _attached_buffer_len; /* used by ..._attach... and ..._detach reoutines */


/* private prototype */
long int find_mml (int nor, int nom, int nop);


/* ***************** routines called once (in main) ****************** */
/*
   @FUN:
   @DOES: allocates the memory for the internal buffer
   @PARAMETERS: the size of memory to allocate (in bytes).
   @RETURNES: TRUE iff successful, 
   FALSE otherwise.
   @SIDEEFFECTS: manipulation of the static variables.
   @ASSUMES: first call or free_mem called before.
*/
int 
allocate_mem (int memsize)
{
  D(fprintf(stderr,"proc %d: in allocate_mem\n",_sphinx_myid);)
  if (_skib_size != 0)
  {
    ERROR(INTERN,"allocate_mem called twice without free_mem between.");
    output_error(TRUE);
  }

  if (_skib_used != 0)
  {
    ERROR(INTERN,"allocate_mem called after mem_init_....");
    output_error(TRUE);
  }
   
  /* Use calloc to avoid uninitialized memory reads in purify... */
  /* Add 20 so we can assure always 64 bit aligned... */
  if ((_skib = (char *) calloc (memsize + 20, sizeof(char))) != NULL)
  {
    _skib_size = memsize;
    D(fprintf(stderr,"proc %d: in allocate_mem %d - success\n",
	      _sphinx_myid, _skib_size);)
    return (TRUE);
  }
  else
  {
    _skib_size = 0;
    D(fprintf(stderr,"proc %d: in allocate_mem - no success\n",_sphinx_myid);)
    return (FALSE);
  }
}

/*
   @FUN:
   @DOES: free-es all allocated memory.
   @PARAMETERS: none.
   @RETURNES: nothing.
   @SIDEEFFECTS: manipulation of the static variables.
   @ASSUMES: allocate_mem called before and no call of free_mem after
   that call of allocate_mem.
*/
void 
free_mem (void)
{
  D(fprintf(stderr,"proc %d: in free_mem\n",_sphinx_myid);)
  if (_skib_size != 0)
  {
    _skib_used = _skib_size = 0;
    free (_skib);
  }
}
/* ********************** routines called for suites ******************* */
/*
   @FUN:
   @DOES: sets _sphinx_buffer to _skib (i.e. a location of allocated memory.)
   @PARAMETERS: number of repetitions (nor), 
   number of measurements (nom), 
   number of processes involved in the measurement (nop).
   @RETURNES: the size of memory available at _sphinx_buffer.
   @SIDEEFFECTS: manipulation of _sphinx_buffer.
   @ASSUMES: assumes allocate_mem called once before with no
   other mem_init_... between.
*/
long int 
mem_init_one_buffer (int nor, int nom, int nop, measurement_t *ms)
{
  D(fprintf(stderr,"proc %d: in mem_init_one_buffer\n",_sphinx_myid);)
  if (_skib_size == 0)
  {
    ERROR(INTERN,"mem_init_one_buffer called without calling"\
	  " allocate_mem before.");
    output_error(TRUE);
  }

  if (_skib_used != 0)
  {
    ERROR(INTERN,"mem_init_one_buffer called after another mem_init_...\n"\
	  " without a mem_release_... between.");
    output_error(TRUE);
  }

  /* use funky assignment to assure 64 bit aligned... */
  _sphinx_buffer = _skib  - ((long)(_skib)%8L) + 8;
  _skib_used = _skib_size;
  return (_skib_size);
}

/*
   @FUN:
   @DOES: sets _sphinx_buffer and _sphinx_buffer_2 a location of allocated 
   memory.
   @PARAMETERS: number of repetitions (nor), 
   number of measurements (nom), 
   number of processes involved in the measurement (nop).
   @RETURNES: the size of memory available at _sphinx_buffer and
   _sphinx_buffer_2.
   @SIDEEFFECTS: manipulation of _sphinx_buffer.
   @ASSUMES: assumes allocate_mem called once before with no
   other mem_init_... between.
*/
long int 
mem_init_two_buffers (int nor, int nom, int nop, measurement_t *ms)
{
  D(fprintf(stderr,"proc %d: in mem_init_two_buffers\n",_sphinx_myid);)
  if (_skib_size == 0)
  {
    ERROR(INTERN,"mem_init_two_buffers called without calling"\
	  " allocate_mem before.");
    output_error(TRUE);
  }

  if (_skib_used != 0)
  {
    ERROR(INTERN,"mem_init_one_buffer called after another mem_init_...\n"\
	  " without a mem_release_... between.");
    output_error(TRUE);
  }

  /* use funky assignment to assure 64 bit aligned... */
  _sphinx_buffer = _skib  - ((long)(_skib)%8L) + 8;

  _sphinx_buffer_2 = _sphinx_buffer + _skib_size / 2; /* ?? */

  /* use funky assignment to assure 64 bit aligned... */
  _sphinx_buffer_2 = _sphinx_buffer_2  - ((long)(_sphinx_buffer_2)%8L) + 8;

  _skib_used = 2 * (_skib_size / 2); /* always precise... ;-) */
  return (_skib_size / 2);
}

/*
   @FUN:
   @DOES: sets _sphinx_buffer and _sphinx_buffer_2 a location of 
   allocated memory.
   The difference to mem_init_two_buffers is, that its result is
   divided by nop, because MPI_Alltoall need a buffer of the size
   message length * nop.
   @PARAMETERS: number of repetitions (nor), 
   number of measurements (nom), 
   number of processes involved in the measurement (nop).
   @RETURNES: the size of memory available at _sphinx_buffer and
   _sphinx_buffer_2.
   @SIDEEFFECTS: manipulation of _sphinx_buffer.
   @ASSUMES: assumes allocate_mem called once before with no
   other mem_init_... between.
*/
long int 
mem_init_two_buffers_alltoall (int nor, int nom, int nop, measurement_t *ms)
{
  int ret_val;

  D(fprintf(stderr,"proc %d: in mem_init_two_buffers_alltoall\n",
	    _sphinx_myid);)
  ret_val = mem_init_two_buffers (nor, nom, nop, ms) / nop;

  /* fix up ret_val so we don't get alignment problems... */
  return ret_val  - ((long)(ret_val)%8L);
}

/*
   @FUN:
   @DOES: sets _sphinx_buffer and _sphinx_buffer_2 a location of 
   allocated memory.
   The difference to mem_init_two_buffers is, that its result is
   divided by nop, because Bsend of the mw-pattern need a buffer of the size
   message length * nop.
   @PARAMETERS: number of repetitions (nor), 
   number of measurements (nom), 
   number of processes involved in the measurement (nop).
   @RETURNES: the size of memory available at _sphinx_buffer and
   _sphinx_buffer_2.
   @SIDEEFFECTS: manipulation of _sphinx_buffer.
   @ASSUMES: assumes allocate_mem called once before with no
   other mem_init_... between, default_communicator set
*/
long int 
mem_init_two_buffers_attach (int nor, int nom, int nop, measurement_t *ms)
{
   /* Matthias Mueller 3.3.1998 */
 int mbl;  /* max buffer length */

 long int  mml = find_mml (nor,nom,nop);  /* max message length */

 MPI_Pack_size ((int)mml * nor * nop * nom, MPI_CHAR, default_communicator, &mbl);

 mbl += (nor * nop * nom) * MPI_BSEND_OVERHEAD;

 _attached_buffer_len = mbl;

 D(fprintf(stderr,"proc %d: in mem_init_two_buffers_attach %d\n",
    _sphinx_myid, mbl);)
 if (_skib_size == 0)
 {
   ERROR(INTERN,"mem_init_two_buffers_attach called without calling"\
	  " allocate_mem before.");
   output_error(TRUE);
 }

 if (_skib_used != 0)
 {
   ERROR(INTERN,"mem_init_one_buffer_attach called after another"\
	  " mem_init_...\nwithout a mem_release_... between.");
   output_error(TRUE);
 }

 _sphinx_buffer = _skib + mbl;

 /* use funky assignment to assure 64 bit aligned... */
 _sphinx_buffer = _sphinx_buffer  - ((long)(_sphinx_buffer)%8L) + 8;

 /* use funky assignment to assure 64 bit aligned... */
 _sphinx_buffer_2 = _skib  - ((long)(_skib)%8L) + 8;

 MPI_Buffer_attach (_sphinx_buffer_2, mbl);
 D(fprintf(stderr,"proc %d: in mem_init_two_buffers_attach - done %d\n",
	    _sphinx_myid, mml);)
 return (mml); 
 /* max message length is shorter !!! */
}

/*
   @FUN:
   @DOES: computes the max message length when using MPI_Bsend
   @PARAMETERS: number of repetitions (nor), 
   number of measurements (nom), 
   number of processes involved in the measurement (nop).
   @RETURNES: above
   @SIDEEFFECTS: none.
   @ASSUMES: _skib_size, default_communicator set
*/
long int 
find_mml (int nor, int nom, int nop)
{
  static int
    l_nor = 0,
    l_nom = 0,
    l_nop = 0;
  static long int
    l_mml = 0;

  /* Matthias Mueller 3.3.1998 */
  int buf_len = 0;

  if (!(l_nor == nor && l_nom == nom && l_nop == nop))
  {  /* used not first with this arguments*/
    int
      buf_om = _skib_size / 2;
    buf_om -= (2 * nor * nom * nop) * MPI_BSEND_OVERHEAD;
    /* buffer for one message */

    /* test for max mess. len */
    for (l_mml = 0; buf_len < buf_om; l_mml++)
      MPI_Pack_size ((int)l_mml * nor * nom * nop, MPI_CHAR, 
		     default_communicator, &buf_len);
    
    l_nor = nor;
    l_nom = nom;
    l_nop = nop;
  }
  return (l_mml);   /* return last computed result */
}

/*
   @FUN:
   @DOES: sets _sphinx_buffer and _sphinx_buffer_2 a location of 
   allocated memory.
   The difference to mem_init_two_buffers is, that its result is NOT
   divided by anything (special for p2p pattern)
   @PARAMETERS: number of repetitions (nor), 
   number of measurements (nom), 
   number of processes involved in the measurement (nop).
   @RETURNES: the size of memory available at _sphinx_buffer and
   _sphinx_buffer_2.
   @SIDEEFFECTS: manipulation of _sphinx_buffer.
   @ASSUMES: assumes allocate_mem called once before with no
   other mem_init_... between, default_communicator set
*/
long int 
mem_init_two_buffers_attach_p2p (int nor, int nom, int nop, measurement_t *ms)
{
  return (mem_init_two_buffers_attach (1, 1, 1, ms));
}

/*
   @FUN:
   @DOES: sets _sphinx_buffer and _sphinx_buffer_2 a location of 
   allocated memory.
   The difference to mem_init_two_buffers is, that its result is NOT
   divided by nop and nom (special for mw pattern)
   @PARAMETERS: number of repetitions (nor), 
   number of measurements (nom), 
   number of processes involved in the measurement (nop).
   @RETURNES: the size of memory available at _sphinx_buffer and
   _sphinx_buffer_2.
   @SIDEEFFECTS: manipulation of _sphinx_buffer.
   @ASSUMES: assumes allocate_mem called once before with no
   other mem_init_... between, default_communicator set
*/
long int 
mem_init_two_buffers_attach_mw (int nor, int nom, int nop, measurement_t *ms)
{
  return (mem_init_two_buffers_attach (nor, 1, nop, ms));
}

/*
   @FUN:
   @DOES: 'releases' the _sphinx_buffers. It must be called after
   allocate_mem. It does NOT free the allocated memory of _skib.
   It is the counterpart of the mem_init_one_buffer and the
   mem_init_two_buffers functions.
   @PARAMETERS: none.
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
void
mem_release (measurement_t *ms)
{
  D(fprintf(stderr,"proc %d: in mem_release\n",_sphinx_myid);)
  if (_skib_size == 0)
  {
    ERROR(INTERN,"mem_release called without calling allocate_mem before.");
    output_error(TRUE);
  }
  
  _skib_used = 0;
}

/*
   @FUN:
   @DOES: 'releases' the _sphinx_buffers. It must be called after
   allocate_mem. It does NOT free the allocated memory of _skib.
   It is the counterpart of the mem_init_two_buffers_attach functions.
   @PARAMETERS: none.
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
void
mem_release_detach (measurement_t *ms)
{
  int
    mbl = _attached_buffer_len;
  /* max buffer length */
  D(fprintf(stderr,"proc %d: in mem_release_detach\n",_sphinx_myid);)
  if (_skib_size == 0)
  {
    ERROR(INTERN,"mem_release_detach called\n"\
	  " without calling allocate_mem before.");
    output_error(TRUE);
  }

  MPI_Buffer_detach (_sphinx_buffer_2, &mbl);
  mem_release(ms);
}


/*
   @FUN:
   @DOES: sets _sphinx_buffer and the _mw_... variable to locations of 
   allocated memory.(Special for master_dispatch_Waitsome in mw_test1.c.)
   @PARAMETERS: number of repetitions (nor), 
   number of measurements (nom), 
   number of processes involved in the measurement (nop).
   @RETURNES: the size of memory available at _sphinx_buffer.
   @SIDEEFFECTS: manipulation of the mentioned variables.
   @ASSUMES: assumes allocate_mem called once before with no
   other mem_init_... between.
*/
long int 
mem_init_mw_Waitsome (int nor, int nom, int nop, measurement_t *ms)
{ /* should only called by process 0 */

  int 
    worker,
    mml,           /* max. message length */
    overhead = 0,  /* memory overhead: _skib -space not used for messages */
    now = nop - 1; /* number of workers (one less than nop because of master */
  D(fprintf(stderr,"proc %d: in mem_init_mw_Waitsome\n",_sphinx_myid);)
  if (_skib_size == 0)
  {
    ERROR(INTERN,"mem_init_mw_Waitsome called without calling"\
	  " allocate_mem before.");
    output_error(TRUE);
  }

  if (_skib_used != 0)
  {
    ERROR(INTERN,"mem_init_mw_Waitsome called after another mem_init_...\n"\
	  " without a mem_release_... between.");
    output_error(TRUE);
  }

  /* "allocating" stuff */
  _mw_index = (int *) _skib;
  overhead += now * sizeof (int);

  /* make it so overhead doesn't cause alignment problem... */
  overhead = overhead - ((long)(overhead)%8L) + 8;

  /* clean up _skib slop... */
  overhead += 8 - ((long)(_skib)%8L);

  _mw_buffer = (char **) (_skib + overhead);
  overhead += now * sizeof (char *);

  _mw_req = (MPI_Request *) (_skib + overhead);
  overhead += now * sizeof (MPI_Request);  

  master_stati = (MPI_Status *) (_skib + overhead);
  overhead += now * sizeof (MPI_Status);

  /* make it so overhead doesn't cause alignment problem... */
  overhead = overhead - ((long)(overhead)%8L) + 8;

  mml = (_skib_size - overhead) / nop;

  /* make it so mml doesn't cause alignment problem... */
  mml = mml - ((long)(mml)%8L);

  _sphinx_buffer = _skib + overhead;
  
  /* use funky assignment to assure 64 bit aligned... */
  _sphinx_buffer = _sphinx_buffer - ((long)(_sphinx_buffer)%8L) + 8;

  for (worker = 0; worker < now; worker++)
    _mw_buffer[worker] = _sphinx_buffer + overhead + mml + (worker * mml);

  return (mml);
}

/*
   @FUN:
   @DOES: sets _sphinx_buffer and the _mw_... variable to locations of 
   allocated memory. (Special for master_dispatch_Waitany in mw_test1.c.)
   @PARAMETERS: number of repetitions (nor), 
   number of measurements (nom), 
   number of processes involved in the measurement (nop).
   @RETURNES: the size of memory available at _sphinx_buffer.
   @SIDEEFFECTS: manipulation of the mentioned variables.
   @ASSUMES: assumes allocate_mem called once before with no
   other mem_init_... between.
*/
long int 
mem_init_mw_Waitany (int nor, int nom, int nop, measurement_t *ms)
{
 /* should only called by process 0 */

  int 
    worker,
    mml,           /* max. message length */
    overhead = 0,  /* memory overhead: _skib -space not used for messages */
    now = nop - 1; /* number of workers (one less than nop because of master */
  D(fprintf(stderr,"proc %d: in mem_init_mw_Waitany \n",_sphinx_myid);)  
  if (_skib_size == 0)
  {
    ERROR(INTERN,"mem_init_mw_Waitany called without calling"\
	  " allocate_mem before.");
    output_error(TRUE);
  }

  if (_skib_used != 0)
  {
    ERROR(INTERN,"mem_init_mw_Waitany called after another mem_init_...\n"\
	  " without a mem_release_... between.");
    output_error(TRUE);
  }

  /* "allocating" stuff */
  _mw_buffer = (char **) (_skib + overhead);
  overhead += now * sizeof (char *);

  _mw_req = (MPI_Request *) (_skib + overhead);
  overhead += now * sizeof (MPI_Request);  

  /* make it so overhead doesn't cause alignment problem... */
  overhead = overhead - ((long)(overhead)%8L) + 8;

  mml = (_skib_size - overhead) / nop;

  /* make it so mml doesn't cause alignment problem... */
  mml = mml - ((long)(mml)%8L);

  _sphinx_buffer = _skib + overhead;
  
  /* use funky assignment to assure 64 bit aligned... */
  _sphinx_buffer = _sphinx_buffer  - ((long)(_sphinx_buffer)%8L) + 8;

  for (worker = 0; worker < now; worker++)
    _mw_buffer[worker] = _sphinx_buffer + overhead + mml + (worker * mml);

  return (mml);
}








