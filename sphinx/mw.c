/*
$Log: mw.c,v $
Revision 1.11  2000/09/15 00:04:59  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.10  2000/08/25 23:17:16  bronis
Added OpenMP tests

Revision 1.9  2000/02/17 14:18:58  bronis
added first real non-blocking tests

Revision 1.8  2000/01/10 21:50:23  bronis
Added full blown aux tests implementation

Revision 1.7  1999/10/01 21:36:52  bronis
Added debugged Root variation

Revision 1.6  1999/09/29 00:23:47  bronis
removed most restrictions on ACKER variation

Revision 1.5  1999/09/21 15:59:50  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.4  1999/09/16 23:57:23  bronis
Fixed pattern return values...

Revision 1.3  1999/09/16 21:07:43  srtaylor
Added max_message_len check

Revision 1.2  1999/09/14 16:38:50  srtaylor
First cut at multiple dimensions

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_aux.h"
#include "mw_test1.h"
#include "pattern.h"
#include "sphinx_mem.h"
#include "sphinx_error.h"
#include "automeasure.h"
#include "sphinx_aux_test.h"

int 
  *_mw_index,
  *_worker_orders;

char 
  **_mw_buffer;

MPI_Status 
  *master_stati;

MPI_Request 
  *_mw_req;


int  master_init_Waitsome       (int mw_numprocs);
void master_free_Waitsome       (int mw_numprocs);
int  master_init_Waitany        (int mw_numprocs);
void master_free_Waitany        (int mw_numprocs);

void master_receive_ready_test  (int, int len, MPI_Comm);
void master_receive_ready_empty (int, int len, MPI_Comm);

int master_dispatch_dummy       (int, int, int, int len, MPI_Comm);
int master_dispatch_Waitsome    (int, int, int, int len, MPI_Comm);
int master_dispatch_Waitany     (int, int, int, int len, MPI_Comm);
int master_dispatch_Recv_AS     (int, int, int, int len, MPI_Comm);
int master_dispatch_Send        (int, int, int, int len, MPI_Comm);
int master_dispatch_Ssend       (int, int, int, int len, MPI_Comm);
int master_dispatch_Isend       (int, int, int, int len, MPI_Comm);
int master_dispatch_Bsend       (int, int, int, int len, MPI_Comm);

void master_worker_stop_wait    (int worker, int len, MPI_Comm);
void master_worker_stop_recv    (int worker, int len, MPI_Comm);
void master_worker_stop_test    (int worker, int len, MPI_Comm);
void master_worker_stop_empty   (int worker, int len, MPI_Comm);

int worker_receive_test         (int len, MPI_Comm comm);

void worker_send_test           (int len, MPI_Comm communicator);
void worker_send_empty          (int len, MPI_Comm communicator);


/*
   @FUNS:
   @NAME: mw_init_...
   @DOES: initialize the measurement *ms (address for measrued results
   is data.)
   @PARAMETERS: above
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
void 
mw_init_dummy (measurement_t *ms)
{
  ms->pattern = MASTER_WORKER;
  ms->data.mw_data.master_receive_ready = master_receive_ready_empty;
  ms->data.mw_data.master_dispatch = master_dispatch_dummy;

  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.mw_data.master_worker_stop = master_worker_stop_recv;
  ms->data.mw_data.worker_receive = worker_receive_test;
  ms->data.mw_data.worker_send = worker_send_test;
  ms->data.mw_data.communicator = MPI_COMM_WORLD;
  ms->data.mw_data.result = NULL;
  ms->data.mw_data.chunks = DEF_CHUNKS_VALUE;
  ms->data.mw_data.len = DEF_LEN_VALUE;
  ms->data.mw_data.def_nodes = DEF_NODES_VALUE;

  /* NOTE DO NOT USE CORRECTION ON THIS SINCE IT IS THE OVERHEAD... */

  return;
}

void 
mw_init_Waitsome (measurement_t *ms)
{
  ms->pattern = MASTER_WORKER;
  ms->data.mw_data.master_receive_ready = master_receive_ready_test; 
  /* not _Wait ? */
  ms->data.mw_data.master_dispatch = master_dispatch_Waitsome;

  ms->server_init = mem_init_mw_Waitsome;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.mw_data.master_worker_stop = master_worker_stop_wait;
  ms->data.mw_data.worker_receive = worker_receive_test;
  ms->data.mw_data.worker_send = worker_send_test;
  ms->data.mw_data.communicator = MPI_COMM_WORLD;
  ms->data.mw_data.result = NULL;
  ms->data.mw_data.chunks = DEF_CHUNKS_VALUE;
  ms->data.mw_data.len = DEF_LEN_VALUE;
  ms->data.mw_data.def_nodes = DEF_NODES_VALUE;

  initialize_mw_aux (ms);

  return;
}

void 
mw_init_Waitany (measurement_t *ms)
{
  ms->pattern = MASTER_WORKER;
  ms->data.mw_data.master_receive_ready = master_receive_ready_test;
  ms->data.mw_data.master_dispatch = master_dispatch_Waitany;

  ms->server_init = mem_init_mw_Waitany;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.mw_data.master_worker_stop = master_worker_stop_test;
  ms->data.mw_data.worker_receive = worker_receive_test;
  ms->data.mw_data.worker_send = worker_send_test;
  ms->data.mw_data.communicator = MPI_COMM_WORLD;
  ms->data.mw_data.result = NULL;
  ms->data.mw_data.chunks = DEF_CHUNKS_VALUE;
  ms->data.mw_data.len = DEF_LEN_VALUE;
  ms->data.mw_data.def_nodes = DEF_NODES_VALUE;

  initialize_mw_aux (ms);

  return;
}

void 
mw_init_Recv_AS (measurement_t *ms)
{
  ms->pattern = MASTER_WORKER;
  ms->data.mw_data.master_receive_ready = master_receive_ready_empty;
  ms->data.mw_data.master_dispatch = master_dispatch_Recv_AS;

  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.mw_data.master_worker_stop = master_worker_stop_recv;
  ms->data.mw_data.worker_receive = worker_receive_test;
  ms->data.mw_data.worker_send = worker_send_test;
  ms->data.mw_data.communicator = MPI_COMM_WORLD;
  ms->data.mw_data.result = NULL;
  ms->data.mw_data.chunks = DEF_CHUNKS_VALUE;
  ms->data.mw_data.len = DEF_LEN_VALUE;
  ms->data.mw_data.def_nodes = DEF_NODES_VALUE;

  initialize_mw_aux (ms);

  return;
}

void 
mw_init_Send (measurement_t *ms)
{
  ms->pattern = MASTER_WORKER;
  ms->data.mw_data.master_receive_ready = master_receive_ready_empty;
  ms->data.mw_data.master_dispatch = master_dispatch_Send;

  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.mw_data.master_worker_stop = master_worker_stop_recv;
  ms->data.mw_data.worker_receive = worker_receive_test;
  ms->data.mw_data.worker_send = worker_send_test;
  ms->data.mw_data.communicator = MPI_COMM_WORLD;
  ms->data.mw_data.result = NULL;
  ms->data.mw_data.chunks = DEF_CHUNKS_VALUE;
  ms->data.mw_data.len = DEF_LEN_VALUE;
  ms->data.mw_data.def_nodes = DEF_NODES_VALUE;

  initialize_mw_aux (ms);

  return;
}

void 
mw_init_Ssend (measurement_t *ms)
{
  ms->pattern = MASTER_WORKER;
  ms->data.mw_data.master_receive_ready = master_receive_ready_empty;
  ms->data.mw_data.master_dispatch = master_dispatch_Ssend;

  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.mw_data.master_worker_stop = master_worker_stop_recv;
  ms->data.mw_data.worker_receive = worker_receive_test;
  ms->data.mw_data.worker_send = worker_send_test;
  ms->data.mw_data.communicator = MPI_COMM_WORLD;
  ms->data.mw_data.result = NULL;
  ms->data.mw_data.chunks = DEF_CHUNKS_VALUE;
  ms->data.mw_data.len = DEF_LEN_VALUE;
  ms->data.mw_data.def_nodes = DEF_NODES_VALUE;

  initialize_mw_aux (ms);

  return;
}

void 
mw_init_Isend (measurement_t *ms)
{
  ms->pattern = MASTER_WORKER;
  ms->data.mw_data.master_receive_ready = master_receive_ready_empty;
  ms->data.mw_data.master_dispatch = master_dispatch_Isend;

  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.mw_data.master_worker_stop = master_worker_stop_recv;
  ms->data.mw_data.worker_receive = worker_receive_test;
  ms->data.mw_data.worker_send = worker_send_test;
  ms->data.mw_data.communicator = MPI_COMM_WORLD;
  ms->data.mw_data.result = NULL;
  ms->data.mw_data.chunks = DEF_CHUNKS_VALUE;
  ms->data.mw_data.len = DEF_LEN_VALUE;
  ms->data.mw_data.def_nodes = DEF_NODES_VALUE;

  initialize_mw_aux (ms);

  return;
}

void 
mw_init_Bsend (measurement_t *ms)
{
  ms->pattern = MASTER_WORKER;
  ms->data.mw_data.master_receive_ready = master_receive_ready_empty;
  ms->data.mw_data.master_dispatch = master_dispatch_Bsend;

  ms->server_init = mem_init_two_buffers_attach_mw;
  ms->server_free = mem_release_detach;
  ms->client_init = mem_init_two_buffers_attach_mw;
  ms->client_free = mem_release_detach;

  ms->data.mw_data.master_worker_stop = master_worker_stop_recv;
  ms->data.mw_data.worker_receive = worker_receive_test;
  ms->data.mw_data.worker_send = worker_send_test;
  ms->data.mw_data.communicator = MPI_COMM_WORLD;
  ms->data.mw_data.result = NULL;
  ms->data.mw_data.chunks = DEF_CHUNKS_VALUE;
  ms->data.mw_data.len = DEF_LEN_VALUE;
  ms->data.mw_data.def_nodes = DEF_NODES_VALUE;

  initialize_mw_aux (ms);

  return;
}

/*
   @FUNS:
   @NAME master_...
   @DOES: call the MPI-Function to be measured. The reason not to call this
   MPI-Function directly is to achieve a function-header comman to all
   measured functions.
   @PARAMETERS: message length len, Communicator comminicator.
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: the buffers set correctly, done with the routines called through
   ms->server_init /ms->client_init
   
*/
void 
master_receive_ready_test (int worker, int len, 
			   MPI_Comm communicator)
{  
  MPI_Irecv (_mw_buffer[worker - 1], 0, MPI_CHAR, 
	     worker, MPI_ANY_TAG, 
	     communicator, _mw_req + worker - 1);
}

void 
master_worker_stop_wait (int worker, int len, 
			 MPI_Comm communicator)
{
  MPI_Wait (_mw_req + (worker - 1), 
	    master_stati + (worker - 1));
  MPI_Ssend (_sphinx_buffer, 0, MPI_CHAR, 
	     worker, 0, communicator);
}

void 
master_worker_stop_test (int worker, int len, MPI_Comm communicator)
{
  MPI_Ssend (_sphinx_buffer, 0, MPI_CHAR, 
	     worker, 0, communicator);
}


void 
master_worker_stop_recv (int worker, int len, MPI_Comm communicator)
{
  MPI_Status
    status;
  MPI_Recv (_sphinx_buffer, 0, MPI_CHAR, 
	    worker, 1, communicator, &status);
  MPI_Ssend (_sphinx_buffer, 0, MPI_CHAR, 
	     worker, 0, communicator);
}


int 
worker_receive_test (int len, MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Recv (_sphinx_buffer, len, MPI_CHAR, 0, 
	    MPI_ANY_TAG, communicator, &status); 

  if (status.MPI_TAG == 0)  /* STOP working */
    return (FALSE);
  
  return (TRUE);
}

void 
worker_send_test (int len, MPI_Comm communicator)
{
  MPI_Ssend (_sphinx_buffer, 0, MPI_CHAR, 
	     0, 1, communicator);
}


void 
master_receive_ready_empty (int worker, int len, 
			    MPI_Comm communicator)
{  
  return;
}

void 
master_worker_stop_empty (int worker, int len, 
			  MPI_Comm communicator)
{
  return;
}


void 
worker_send_empty (int len, MPI_Comm communicator)
{
  return;
}

int 
master_dispatch_dummy (int number_of_workers, int work, 
		       int chunks, int len, 
		       MPI_Comm communicator)
{
  return (1);
}


/* ---------------------- W a i t s o m e ----------------------- */
int 
master_dispatch_Waitsome (int number_of_workers, int work, 
			  int chunks,
			  int len, MPI_Comm communicator)
{
  int 
    i,
    worker,
    eingaenge;

  MPI_Waitsome (number_of_workers, _mw_req, &eingaenge, 
		_mw_index, master_stati);


  D1(fprintf (stderr, "master: eingaenge: %d at len %d\n", 
	      eingaenge, len);)

  
  for (i = 0; i < eingaenge; i++)
  {
    worker = _mw_index[i] + 1;

    /* posting new recv for this worker, because the old one has been used */
    MPI_Irecv (_mw_buffer[worker - 1], 0, MPI_CHAR, 
	       worker, MPI_ANY_TAG, communicator, 
	       _mw_req + worker - 1);


    /* sending next chunk of work to this worker */
    MPI_Send (_sphinx_buffer, len, MPI_CHAR, 
	      worker, 1, communicator);

    D1(fprintf (stderr, "master: sending job_no %d to worker %d\n",\
	     work,worker);)
#if 0
    if (++work == chunks)
    {
      return (chunks);
    }
#endif
  }
  return (eingaenge);
}
#if 0
int 
master_init_Waitsome (int mw_numprocs)
{
  int 
    worker;
  
  /* size of array depends on number of processe started, so they are
     allocated dynamically */
  
  if (((_mw_index = (int *) malloc (sizeof(int) * 
		    (mw_numprocs - 1))) == NULL)
      || ((_mw_buffer = (char **) malloc (sizeof(char *) * 
			(mw_numprocs - 1))) == NULL)
      || ((_mw_req = (MPI_Request *) malloc (sizeof (MPI_Request) * 
		     (mw_numprocs - 1))) == NULL)
      || ((master_stati = (MPI_Status *) malloc (sizeof (MPI_Status) * 
			  (mw_numprocs - 1))) == NULL))
    
  {
    ERROR(NO_MEM,"mw_pattern");
    return (FALSE);
  }
  
  for (worker = 0; worker < mw_numprocs - 1; worker++)
    if ((_mw_buffer[worker] = 
	 (char *) malloc (max_msg_len)) == NULL)
    {
      ERROR(NO_MEM,"mw_pattern");
      return (FALSE);
    }


  return (TRUE);
}

void 
master_free_Waitsome (int mw_numprocs)
{
  int worker;

  free (_mw_index);
  free (_mw_req);
  free (master_stati);
  
  for (worker = 0; worker < mw_numprocs - 1; worker++)
    free (_mw_buffer[worker]);
  
  free (_mw_buffer);
}
#endif
/* ---------------------- W a i t a n y ----------------------- */

int 
master_dispatch_Waitany (int number_of_workers, 
			 int work, int chunks, int len, 
			 MPI_Comm communicator)
{
  int 
    worker;

  MPI_Status
    status;

  MPI_Waitany (number_of_workers, _mw_req, 
	       &worker, &status);
  
  worker++;
    
  /* posting new recv for this worker, 
     because the old one has been used */
  MPI_Irecv (_mw_buffer[worker - 1], 0, MPI_CHAR, worker, 
	     MPI_ANY_TAG, communicator, _mw_req + worker - 1);
  
  /* sending next chunk of work to this worker */
  MPI_Send (_sphinx_buffer, len, MPI_CHAR, 
	    worker, 1, communicator);

  D(fprintf (stderr, "master: sending job_no %d to worker %d\n",
	   work,worker);)
  
  return (1);
}
#if 0
int 
master_init_Waitany (int mw_numprocs)
{
  int 
    worker;
  /* size of array depends on number of processe 
     started, so they are allocated dynamically */
  
  if (((_mw_req = (MPI_Request *) malloc (sizeof (MPI_Request) * 
		  (mw_numprocs - 1))) == NULL)|| 
      ((_mw_buffer = (char **) malloc (sizeof(char *) * 
		     (mw_numprocs - 1))) == NULL))    
  {
    ERROR(NO_MEM,"mw_pattern");
    return (FALSE);
  }

  for (worker = 0; worker < mw_numprocs - 1; worker++)
    if ((_mw_buffer[worker] = 
	 (char *) malloc (max_msg_len)) == NULL)
    {
      ERROR(NO_MEM,"mw_pattern");
      return (FALSE);
    }

  return (TRUE);
}


void 
master_free_Waitany (int mw_numprocs)
{
  int worker;

  free (_mw_req);

  for (worker = 0; worker < mw_numprocs - 1; worker++)
    free (_mw_buffer[worker]);
  
  free (_mw_buffer);

}
#endif
/* --------------------------- Recv A n y S o ur c e ---------------- */
int 
master_dispatch_Recv_AS (int number_of_workers, 
			 int work, int chunks, int len, 
			 MPI_Comm communicator)
{
  int 
    worker;

  MPI_Status
    status;

  MPI_Recv (_sphinx_buffer, 0, MPI_CHAR, MPI_ANY_SOURCE, 
	     MPI_ANY_TAG, communicator, &status);

  worker = status.MPI_SOURCE;

  /* sending next chunk of work to this worker */
  MPI_Send (_sphinx_buffer, len, MPI_CHAR, 
	    worker, 1, communicator);

  D(fprintf (stderr, "master: sending job_no %d to worker %d\n",
	   work,worker);)

  if (++work == chunks)
  {
    return (chunks);
  }
  
  return (1);
}

/* --------------------- Master sends: MPI_Send -------------------- */
int 
master_dispatch_Send (int number_of_workers, 
		      int work, int chunks, int len, 
		      MPI_Comm communicator)
{
  MPI_Status
    status;
  
  MPI_Recv (_sphinx_buffer, len, MPI_CHAR, (work % number_of_workers) + 1, 
	    1, communicator, &status);
  /* sending next chunk of work to this worker */
  MPI_Send (_sphinx_buffer, len, MPI_CHAR, (work % number_of_workers) + 1, 
	    1, communicator);

  D(fprintf (stderr, "master: sending job_no %d to worker %d\n",
	   work,(work % number_of_workers) + 1);)

  return (1);
}



/* --------------------- Master sends: MPI_Ssend -------------------- */
int 
master_dispatch_Ssend (int number_of_workers, 
		       int work, int chunks, int len, 
		       MPI_Comm communicator)
{
  MPI_Status
    status;
  
  MPI_Recv (_sphinx_buffer, len, MPI_CHAR, (work % number_of_workers) + 1, 
	    1, communicator, &status);
  /* sending next chunk of work to this worker */
  MPI_Ssend (_sphinx_buffer, len, MPI_CHAR, 
	     (work % number_of_workers) + 1, 
	    1, communicator);

  D(fprintf (stderr, "master: sending job_no %d to worker %d\n",
	   work,(work % number_of_workers) + 1);)

  return (1);
}
/* --------------------- Master sends: MPI_Isend -------------------- */
int 
master_dispatch_Isend (int number_of_workers, 
		       int work, int chunks, int len, 
		       MPI_Comm communicator)
{
  MPI_Request
    req;

  MPI_Status
    status;
  
  MPI_Recv (_sphinx_buffer, len, MPI_CHAR, (work % number_of_workers) + 1, 
	    1, communicator, &status);
  /* sending next chunk of work to this worker */
  MPI_Isend (_sphinx_buffer, len, MPI_CHAR, 
	     (work % number_of_workers) + 1, 
	     1, communicator, &req);


  D(fprintf (stderr, "master: sending job_no %d to worker %d\n",
	   work,(work % number_of_workers) + 1);)

  return (1);
}

/* --------------------- Master sends: MPI_Bsend -------------------- */
int 
master_dispatch_Bsend (int number_of_workers, 
		       int work, int chunks, int len, 
		       MPI_Comm communicator)
{
  MPI_Status
    status;

  MPI_Recv (_sphinx_buffer, len, MPI_CHAR, (work % number_of_workers) + 1, 
	    1, communicator, &status);
  /* sending next chunk of work to this worker */
  MPI_Bsend (_sphinx_buffer, len, MPI_CHAR, 
	     (work % number_of_workers) + 1, 
	    1, communicator);

  D(fprintf (stderr, "master: sending job_no %d to worker %d\n",
	   work,(work % number_of_workers) + 1);)

  return (1);
}



/*
   @FUN:
   @DOES: executes the master-worker pattern
   @PARAMETERS: the actual measurement
   @RETURNES: TRUE in case if success
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int 
mw_pattern (measurement_t *ms, int n)
{
  int 
    mw_numprocs,
    local_myid;
  

  MPI_Comm_rank(ms->data.mw_data.communicator,&local_myid);
  MPI_Comm_size(ms->data.mw_data.communicator,&mw_numprocs);

  D1(fprintf (stderr,"mw_numprocs: %d\n",mw_numprocs);)

  if (mw_numprocs == 1)
  {
    ERROR(INTERN,"master worker pattern started with only one process\n"\
	  "no worker available.");
    output_error (TRUE);
  }

  if (local_myid == 0) /* so master */
  {
    int 
      worker,
      work,
      i,
      arg;

    double 
      start_time,
      end_time = 0.0,
      org_time,
      tbm_time;

    switch (ms->dimensions[n].variation) {
    case NODES:
      MPI_Comm_size(ms->data.mw_data.communicator,&arg);
      break;
    case LENGTH:
      arg = ms->data.mw_data.len;
      break;
    case CHUNK:
      arg = ms->data.mw_data.chunks;
      break;
    case ITERS:
      arg = ms->data.mw_data.iters;
      break;
    case NO_VARIATION:
      arg = NO_VARIATION_ARG_VALUE;
      break;
    default:
      ERROR(USER,"invalid variation occured in mw_pattern");
      return GENERIC_ERROR;
    }

    D1(fprintf (stderr, "master: putting rec. ready  !\n");)

    if (CACHE_WARMUP > 0)
    {
      /* for cache warmup */
      /* post ready to receive */
      for (worker = 1; worker < mw_numprocs; worker++)
	ms->data.mw_data.master_receive_ready (worker, ms->data.mw_data.len, 
					       ms->data.mw_data.communicator);
      work = 0;
      while (work < CACHE_WARMUP)
	work += (ms->data.mw_data.master_dispatch (mw_numprocs - 1, work, 
					CACHE_WARMUP, ms->data.mw_data.len, 
					ms->data.mw_data.communicator));
    }
    /* for real */
    am_init(ms->max_rep, ms->pattern_in_omp_parallel);
    do
    {
      org_time = (start_time = MPI_Wtime()) - end_time;
      /* measure */
      /* BRONIS */
      /* Quick and dirty change; really should do loop in master_dispatch */
      for (i = 0; i < ms->data.mw_data.iters; i++) {
      /* END BRONIS */
        work = 0;

        while (work < ms->data.mw_data.chunks)
	  work += (ms->data.mw_data.master_dispatch (mw_numprocs - 1, work, 
		   ms->data.mw_data.chunks, ms->data.mw_data.len, 
		   ms->data.mw_data.communicator));
      }
      
      end_time = MPI_Wtime();
      tbm_time = end_time - start_time;
    }while (am_control_end(ms, arg, tbm_time, org_time, NO_COMMUNICATION, 
			   MPI_COMM_NULL, 0, FALSE));

    am_fill_data (ms, ms->data.mw_data.len, 
		  ms->data.mw_data.result, ms->data.mw_data.iters);
    am_free(ms->pattern_in_omp_parallel);

    /* sending stop signal to each worker */


    D1(fprintf (stderr, "master: sending stop signals!\n");)

    for (worker = 1; worker < mw_numprocs ; worker ++)
      ms->data.mw_data.master_worker_stop (worker, ms->data.mw_data.len,
					   ms->data.mw_data.communicator);
  }
  else /* so worker */
  {
    for (;;)
    {
      /* sending the work done, ordering new work */
      D1(fprintf (stderr,"Worker %d: sending with len %d\n",local_myid,
	       ms->data.mw_data.len);)

      ms->data.mw_data.worker_send (ms->data.mw_data.len, 
				    ms->data.mw_data.communicator);

      D1(fprintf (stderr,"Worker %d: sended with len %d\n",local_myid,
	       ms->data.mw_data.len);)

      if (ms->data.mw_data.worker_receive (ms->data.mw_data.len,
				   ms->data.mw_data.communicator) == FALSE)
      {
     	break;
      }
    }    
  }
  return 0;
}






