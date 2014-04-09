/*
$Log: sphinx_col.c,v $
Revision 1.20  2000/12/14 00:26:52  bronis
Added improved scan test and scalable tests for fan out collectives

Revision 1.19  2000/09/15 00:05:00  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.18  2000/08/25 23:17:17  bronis
Added OpenMP tests

Revision 1.17  2000/03/16 15:48:39  bronis
fixed mpguidec warnings

Revision 1.16  2000/02/17 14:18:58  bronis
added first real non-blocking tests

Revision 1.15  2000/01/14 23:34:55  bronis
purified recent changes

Revision 1.14  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.13  1999/10/29 00:11:10  bronis
Fixed bugs, made input case insensitive

Revision 1.12  1999/10/04 15:53:06  bronis
fixed ACKer position bugs

Revision 1.11  1999/10/01 21:36:52  bronis
Added debugged Root variation

Revision 1.10  1999/09/29 00:23:48  bronis
removed most restrictions on ACKER variation

Revision 1.9  1999/09/23 17:08:44  bronis
cleaned up multi dim stuff

Revision 1.8  1999/09/21 15:59:51  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.7  1999/09/16 23:26:02  bronis
fixed fill_dummy_values calls

Revision 1.6  1999/09/16 21:07:44  srtaylor
Added max_message_len check

Revision 1.5  1999/09/15 15:52:30  bronis
partial fix of data_list.c

Revision 1.4  1999/09/15 15:50:57  srtaylor
Structure modifications - Does not currently compile

Revision 1.3  1999/09/14 16:38:51  srtaylor
First cut at multiple dimensions

Revision 1.2  1999/07/12 15:16:21  bronis
fixed minor bug

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_aux.h"
#include "col_test1.h"
#include "pattern.h"
#include "sphinx_mem.h"
#include "sphinx_error.h"
#include "sphinx_tools.h"
#include "sphinx_params.h"
#include "automeasure.h"
#include "sphinx_aux_test.h"


#define BROADCASTRESPONSE_TAG    1673
#define DIVERGENT_SYNCH_OP_TAG   1674
#define GENERIC_BARRIER_TAG      1675
#define SCATTERRESPONSE_TAG      1676
#define SCATTERVRESPONSE_TAG     1677

void divergent_synch_op            (int root, MPI_Comm curcomm);
void generic_barrier               (MPI_Comm curcomm);

void measure_col_dummy             (int len, MPI_Comm communicator);
void measure_col_over_nodes_dummy  (int len, MPI_Comm communicator);
void measure_broadcast             (int len, MPI_Comm communicator);
void measure_broadcast_barrier     (int len, MPI_Comm communicator);
void measure_bcast_send_latency    (int len, MPI_Comm communicator);
void measure_broadcast_round       (int len, MPI_Comm communicator);
void measure_broadcast_send_ack    (int len, MPI_Comm communicator);
void measure_broadcast_with_ACKer  (int len, MPI_Comm communicator);
void measure_broadcast_recv_ack    (int len, MPI_Comm communicator);
void measure_barrier               (int len, MPI_Comm communicator);
void measure_barrier_barrier       (int len, MPI_Comm communicator);
void measure_Reduce_scale          (int len, MPI_Comm communicator);
void measure_Reduce                (int len, MPI_Comm communicator);
void measure_Reduce_upper_bound    (int len, MPI_Comm communicator);
void measure_Alltoall              (int len, MPI_Comm communicator);
void measure_Scan_with_Acker       (int len, MPI_Comm communicator);
void measure_Scan_send_latency     (int len, MPI_Comm communicator);
void measure_Scan_send_ack         (int len, MPI_Comm communicator);
void measure_Scan                  (int len, MPI_Comm communicator);
void measure_Comm_dup_scale        (int len, MPI_Comm communicator);
void measure_Comm_dup              (int len, MPI_Comm communicator);
void measure_Comm_split_scale      (int len, MPI_Comm communicator);
void measure_Comm_split            (int len, MPI_Comm communicator);
void measure_memcpy                (int len, MPI_Comm communicator);

void measure_Gather_scale          (int len, MPI_Comm communicator);
void measure_Gather                (int len, MPI_Comm communicator);
void measure_Gather_upper_bound    (int len, MPI_Comm communicator);
void measure_Scatter               (int len, MPI_Comm communicator);
void measure_Scatter_with_ACKer    (int len, MPI_Comm communicator);
void measure_Scatter_send_latency  (int len, MPI_Comm communicator);
void measure_Scatter_send_ack      (int len, MPI_Comm communicator);
void measure_Allgather             (int len, MPI_Comm communicator);
void measure_Allgather_barrier     (int len, MPI_Comm communicator);
void measure_Allreduce             (int len, MPI_Comm communicator);
void measure_Allreduce_barrier     (int len, MPI_Comm communicator);
void measure_Gatherv_scale         (int len, MPI_Comm communicator);
void measure_Gatherv               (int len, MPI_Comm communicator);
void measure_Gatherv_upper_bound   (int len, MPI_Comm communicator);
void measure_Scatterv              (int len, MPI_Comm communicator);
void measure_Scatterv_with_ACKer   (int len, MPI_Comm communicator);
void measure_Scatterv_send_latency (int len, MPI_Comm communicator);
void measure_Scatterv_send_ack     (int len, MPI_Comm communicator);
void measure_Allgatherv            (int len, MPI_Comm communicator);
void measure_Allgatherv_barrier    (int len, MPI_Comm communicator);
void measure_Alltoallv             (int len, MPI_Comm communicator);
void measure_Alltoallv_barrier     (int len, MPI_Comm communicator);
void measure_Reduce_scatter        (int len, MPI_Comm communicator);
void measure_Red_scatter_barrier   (int len, MPI_Comm communicator);
void measure_Alltoall_barrier      (int len, MPI_Comm communicator);

/* Want for loop to end at MPI_Comm_size... */
int
  num_nodes;
  
int
  *msg_displs = NULL;
  
int
  *msg_counts = NULL;

int
  global_root;
  

/* This is based directly on the MPICH bcast implementation... */
void divergent_synch_op (int root, MPI_Comm curcomm)
{
  MPI_Status status;
  int        rank, size, src, dst;
  int        relative_rank, mask;

  /* Is root within the comm and more than 1 processes involved? */
  MPI_Comm_size ( curcomm, &size );

  /* Trivial if there is only one process... */
  if (size == 1)
    return;

  MPI_Comm_rank ( curcomm, &rank );
  
  relative_rank = (rank >= root) ? rank - root : rank - root + size;

  mask = 0x1;
  while (mask < size) {
    if (relative_rank & mask) {
      src = rank - mask; 
      if (src < 0) src += size;
      MPI_Recv((void *)0,0,MPI_INT,src,DIVERGENT_SYNCH_OP_TAG,curcomm,&status);
      break;
    }
    mask <<= 1;
  }

  mask >>= 1;
  while (mask > 0) {
    if (relative_rank + mask < size) {
      dst = rank + mask;
      if (dst >= size) dst -= size;
      MPI_Send ((void *)0,0,MPI_INT,dst, DIVERGENT_SYNCH_OP_TAG,curcomm);
    }
    mask >>= 1;
  }

  return;
}

/* This is based directly on the MPICH barrier implementation... */
void generic_barrier (MPI_Comm curcomm)
{
  int        rank, size, N2_prev, surfeit;
  int        d, dst, src, temp;
  MPI_Status status;

  /* Intialize communicator size */
  (void) MPI_Comm_size ( curcomm, &size );

  /* If there's only one member, this is trivial */
  if ( size > 1 ) {

    MPI_Comm_rank ( curcomm, &rank );

    for (temp = size, N2_prev = 1; 
	 temp > 1; temp >>= 1, N2_prev <<= 1) /* NULL */;

    surfeit = size - N2_prev;

    /* Perform a combine-like operation */
    if ( rank < N2_prev ) {
      if( rank < surfeit ) {

        /* get the fanin letter from the upper "half" process: */
        dst = N2_prev + rank;

        MPI_Recv((void *)0, 0, MPI_INT, dst,
		 GENERIC_BARRIER_TAG, curcomm, &status);
      }

      /* combine on embedded N2_prev power-of-two processes */
      for (d = 1; d < N2_prev; d <<= 1) {
        dst = (rank ^ d);

        MPI_Sendrecv( (void *)0,0,MPI_INT,dst, GENERIC_BARRIER_TAG,
                     (void *)0,0,MPI_INT,dst, GENERIC_BARRIER_TAG, 
                     curcomm, &status);
      }

      /* fanout data to nodes above N2_prev... */
      if ( rank < surfeit ) {
        dst = N2_prev + rank;
        MPI_Send( (void *)0, 0, MPI_INT, dst, GENERIC_BARRIER_TAG, curcomm);
      }
    } 
    else {
      /* fanin data to power of 2 subset */
      src = rank - N2_prev;
      MPI_Sendrecv( (void *)0, 0, MPI_INT, src, GENERIC_BARRIER_TAG,
                   (void *)0, 0, MPI_INT, src, GENERIC_BARRIER_TAG, 
                   curcomm, &status);
    }
  } 
  return; 
}



/* quick and dirty flat b'cast... */
#if 0
#define MPI_Bcast(a,b,c,d,e)   flat_bcast (a,b,c,d,e)
#endif

int flat_bcast (void *buffer, int count, MPI_Datatype datatype,
		int root, MPI_Comm comm)
{
  MPI_Status status;

  if (_sphinx_myid == root) {
    int dest, size;

    MPI_Comm_size (comm, &size);
    
    for (dest = 0; dest < size; dest++) {
      if (dest != root) {
	MPI_Send (buffer, count, datatype, dest, 230, comm);
      }
    }

    return 0;
  }

  MPI_Recv (buffer, count, datatype, root, 230, comm, &status);

  return 0;
}


/* functions to test if node_to_test is on the collective */
/* communication path of node_to_reach (i.e. for broadcast: */
/* is there a send by node_to_test that is necessary for */
/* data to reach node_to_reach?). These are used to determine */
/* if OL_i measurement for node_to_reach is reliable */
/* Default: Don't know; assume it is... */
int default_onpath (int node_to_reach, int node_to_test, int root)
{
  return 1;
}

/* For linear broadcast: 0->1->2->...->n-1 */
int linear_onpath (int node_to_reach, int node_to_test, int root)
{
  /* Should this be true for node_to_reach (i.e. less than or EQUAL)? */
  return (node_to_test < node_to_reach);
}

/* For flat broadcast: 0 sends directly to all... */
int flat_onpath (int node_to_reach, int node_to_test, int root)
{
  /* Should this be true for node_to_reach? */
  return (node_to_test == 0);
}
  
long int 
mem_init_two_buffers_varops (int nor, int nom, int nop, measurement_t *ms)
{
  msg_displs = malloc (nop * sizeof(int));
  msg_counts = malloc (nop * sizeof(int));
  
  return mem_init_two_buffers_alltoall (nor, nom, nop, ms);
}
 
void
mem_release_varops (measurement_t *ms)
{
  free (msg_displs);
  msg_displs = NULL;
  
  free (msg_counts);
  msg_counts = NULL;
  
  mem_release(ms);
  
  return;
}


/*
   @FUNS:
   @NAME: col_init_...
   @DOES: the following col_init_... functions initialize the ms with
   the correct data, to measure the specific collective MPI function.
   @PARAMETERS: measurement ms and the place to hold the measured 
   results (data).
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
void 
col_init_dummy (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_col_dummy;
  ms->data.col_data.client_routine = measure_col_dummy;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  /* NOTE DO NOT USE CORRECTION ON THIS SINCE IT IS THE OVERHEAD... */

  return;
}

void 
col_init_over_nodes_dummy (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_col_over_nodes_dummy;
  ms->data.col_data.client_routine = measure_col_over_nodes_dummy;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  /* NOTE DO NOT USE CORRECTION ON THIS SINCE IT IS THE OVERHEAD... */

  return;
}

void 
col_init_Bcast (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_broadcast;
  ms->data.col_data.client_routine = measure_broadcast;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_aux (ms);

  return;
}

void 
col_init_Bcast_barrier (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_broadcast_barrier;
  ms->data.col_data.client_routine = measure_broadcast_barrier;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Bcast_send_latency (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_bcast_send_latency;
  ms->data.col_data.client_routine = measure_bcast_send_latency;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Bcast_round (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_broadcast_round;
  ms->data.col_data.client_routine = measure_broadcast_round;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_over_nodes_aux (ms);

  return;
}

void 
col_init_Bcast_with_acks (measurement_t *ms)
{
  int rank;

  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  if (rank) {
    /* Not rank zero so not root... */
    ms->data.col_data.routine_to_measure = measure_broadcast_send_ack;
    ms->data.col_data.client_routine = measure_broadcast_send_ack;
  } else {
    /* rank zero so always root... */
    ms->data.col_data.routine_to_measure = measure_broadcast_recv_ack;
    ms->data.col_data.client_routine = measure_broadcast_recv_ack;
  }

  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Bcast_with_ACKer (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->ACKer_OK = 1; /* TRUE */

  ms->data.col_data.routine_to_measure = measure_broadcast_with_ACKer;
  ms->data.col_data.client_routine = measure_bcast_send_latency;
  ms->data.col_data.ACKer_routine = measure_broadcast_send_ack;
  ms->data.col_data.notACKer_routine = measure_bcast_send_latency;
  ms->data.col_data.gap_routine_to_measure = measure_bcast_send_latency;

  ms->data.col_data.onpath = default_onpath;
  /*
  ms->data.col_data.onpath = linear_onpath;
  ms->data.col_data.onpath = flat_onpath;
  */

  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_ACKer_aux (ms);

  return;
}

void 
col_init_Barrier (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_barrier;
  ms->data.col_data.client_routine = measure_barrier;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Barrier_barrier (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_barrier_barrier;
  ms->data.col_data.client_routine = measure_barrier_barrier;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Reduce_scale (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Reduce_scale;
  ms->data.col_data.client_routine = measure_Reduce_scale;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Reduce (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Reduce;
  ms->data.col_data.client_routine = measure_Reduce;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_over_nodes_aux (ms);

  return;
}

void 
col_init_Reduce_upper_bound (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Reduce_upper_bound;
  ms->data.col_data.client_routine = measure_Reduce_upper_bound;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Scan (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Scan;
  ms->data.col_data.client_routine = measure_Scan;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;  
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_over_nodes_aux (ms);

  return;
}

void 
col_init_Scan_send_latency (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Scan_send_latency;
  ms->data.col_data.client_routine = measure_Scan_send_latency;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Scan_with_Acker (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers;
  ms->client_free = mem_release;

  ms->ACKer_OK = 1; /* TRUE */

  ms->data.col_data.routine_to_measure = measure_Scan_with_Acker;
  ms->data.col_data.client_routine = measure_Scan_send_latency;
  ms->data.col_data.ACKer_routine = measure_Scan_send_ack;
  ms->data.col_data.notACKer_routine = measure_Scan_send_latency;
  ms->data.col_data.gap_routine_to_measure = measure_Scan_send_latency;

  ms->data.col_data.onpath = default_onpath;
  /*
  ms->data.col_data.onpath = linear_onpath;
  ms->data.col_data.onpath = flat_onpath;
  */

  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;  
  ms->data.col_data.result = NULL;

  initialize_ACKer_aux (ms);

  return;
}

void 
col_init_Alltoall (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_alltoall;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers_alltoall;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Alltoall;
  ms->data.col_data.client_routine = measure_Alltoall;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Alltoall_barrier (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_alltoall;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers_alltoall;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Alltoall_barrier;
  ms->data.col_data.client_routine = measure_Alltoall_barrier;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Gather_scale (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_alltoall;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers_alltoall;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Gather_scale;
  ms->data.col_data.client_routine = measure_Gather_scale;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Gather (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_alltoall;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers_alltoall;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Gather;
  ms->data.col_data.client_routine = measure_Gather;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_over_nodes_aux (ms);

  return;
}

void 
col_init_Gather_upper_bound (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_alltoall;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers_alltoall;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Gather_upper_bound;
  ms->data.col_data.client_routine = measure_Gather_upper_bound;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Scatter (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_alltoall;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers_alltoall;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Scatter;
  ms->data.col_data.client_routine = measure_Scatter;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_over_nodes_aux (ms);

  return;
}

void 
col_init_Scatter_with_ACKer (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_alltoall;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers_alltoall;
  ms->client_free = mem_release;

  ms->ACKer_OK = 1; /* TRUE */

  ms->data.col_data.routine_to_measure = measure_Scatter_with_ACKer;
  ms->data.col_data.client_routine = measure_Scatter_send_latency;
  ms->data.col_data.ACKer_routine = measure_Scatter_send_ack;
  ms->data.col_data.notACKer_routine = measure_Scatter_send_latency;
  ms->data.col_data.gap_routine_to_measure = measure_Scatter_send_latency;

  ms->data.col_data.onpath = default_onpath;
  /*
  ms->data.col_data.onpath = linear_onpath;
  ms->data.col_data.onpath = flat_onpath;
  */

  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_ACKer_aux (ms);

  return;
}

void 
col_init_Allgather (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_alltoall;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers_alltoall;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Allgather;
  ms->data.col_data.client_routine = measure_Allgather;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Allgather_barrier (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_alltoall;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers_alltoall;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Allgather_barrier;
  ms->data.col_data.client_routine = measure_Allgather_barrier;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Allreduce (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Allreduce;
  ms->data.col_data.client_routine = measure_Allreduce;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Allreduce_barrier (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Allreduce_barrier;
  ms->data.col_data.client_routine = measure_Allreduce_barrier;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Gatherv_scale (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->data.col_data.routine_to_measure = measure_Gatherv_scale;
  ms->data.col_data.client_routine = measure_Gatherv_scale;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Gatherv (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->data.col_data.routine_to_measure = measure_Gatherv;
  ms->data.col_data.client_routine = measure_Gatherv;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_over_nodes_aux (ms);

  return;
}

void 
col_init_Gatherv_upper_bound (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->data.col_data.routine_to_measure = measure_Gatherv_upper_bound;
  ms->data.col_data.client_routine = measure_Gatherv_upper_bound;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Scatterv (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->data.col_data.routine_to_measure = measure_Scatterv;
  ms->data.col_data.client_routine = measure_Scatterv;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_over_nodes_aux (ms);

  return;
}

void 
col_init_Scatterv_with_ACKer (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->ACKer_OK = 1; /* TRUE */

  ms->data.col_data.routine_to_measure = measure_Scatterv_with_ACKer;
  ms->data.col_data.client_routine = measure_Scatterv_send_latency;
  ms->data.col_data.ACKer_routine = measure_Scatterv_send_ack;
  ms->data.col_data.notACKer_routine = measure_Scatterv_send_latency;
  ms->data.col_data.gap_routine_to_measure = measure_Scatterv_send_latency;

  ms->data.col_data.onpath = default_onpath;
  /*
  ms->data.col_data.onpath = linear_onpath;
  ms->data.col_data.onpath = flat_onpath;
  */

  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_ACKer_aux (ms);

  return;
}

void 
col_init_Allgatherv (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->data.col_data.routine_to_measure = measure_Allgatherv;
  ms->data.col_data.client_routine = measure_Allgatherv;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Allgatherv_barrier (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->data.col_data.routine_to_measure = measure_Allgatherv_barrier;
  ms->data.col_data.client_routine = measure_Allgatherv_barrier;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Alltoallv (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->data.col_data.routine_to_measure = measure_Alltoallv;
  ms->data.col_data.client_routine = measure_Alltoallv;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Alltoallv_barrier (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->data.col_data.routine_to_measure = measure_Alltoallv_barrier;
  ms->data.col_data.client_routine = measure_Alltoallv_barrier;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Reduce_scatter (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->data.col_data.routine_to_measure = measure_Reduce_scatter;
  ms->data.col_data.client_routine = measure_Reduce_scatter;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Red_scatter_barrier (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers_varops;
  ms->server_free = mem_release_varops;
  ms->client_init = mem_init_two_buffers_varops;
  ms->client_free = mem_release_varops;

  ms->data.col_data.routine_to_measure = measure_Red_scatter_barrier;
  ms->data.col_data.client_routine = measure_Red_scatter_barrier;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Comm_dup_scale (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Comm_dup_scale;
  ms->data.col_data.client_routine = measure_Comm_dup_scale;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Comm_dup (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Comm_dup;
  ms->data.col_data.client_routine = measure_Comm_dup;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_over_nodes_aux (ms);

  return;
}

void 
col_init_Comm_split_scale (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Comm_split_scale;
  ms->data.col_data.client_routine = measure_Comm_split_scale;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  initialize_col_aux (ms);

  return;
}

void 
col_init_Comm_split (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_init = mem_init_one_buffer;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_Comm_split;
  ms->data.col_data.client_routine = measure_Comm_split;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_over_nodes_aux (ms);

  return;
}

/* BRONIS: This is an old SKaMPI comment; I wouldn't put this here */
/* ok, I know: memcpy tends to be seen not as being a real collective
   operation... . But it fits best in this pattern. (In simple there
   is no variation over a parameter.) */
void 
col_init_memcpy (measurement_t *ms)
{
  ms->pattern = COLLECTIVE;
  ms->server_init = mem_init_two_buffers;
  ms->server_free = mem_release;
  ms->client_init = mem_init_two_buffers;
  ms->client_free = mem_release;

  ms->data.col_data.routine_to_measure = measure_memcpy;
  ms->data.col_data.client_routine = measure_col_dummy;
  ms->data.col_data.len = DEF_MESSAGE_LEN;
  ms->data.col_data.communicator = MPI_COMM_WORLD;
  ms->data.col_data.result = NULL;

  ms->iters_over_nodes = 1; /* TRUE */

  initialize_col_over_nodes_aux (ms);

  return;
}

/*
   @FUNS:
   @NAME: measure_...
   @DOES: call the MPI-Function to be measured. The reason not to call this
   MPI-Function directly is to achieve a function-header comman to all
   measured functions.
   @PARAMETERS: message length len, Communicator comminicator.
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: _sphinx_buffer (_sphinx_buffer_2 set correctly, done with
   mem_init_one_buffers or mem_init_two_buffers.
*/
void 
measure_col_dummy (int len, MPI_Comm communicator)
{
  /* just for dummy measurement */
  return;
}

void 
measure_col_over_nodes_dummy (int len, MPI_Comm communicator)
{
  /* just for dummy measurement */
  /* for tests that time MPI_Comm_size iterations, including */
  /* those that do not use a root node... */
  int root;
  
  for (root = 0; root < num_nodes; root++) /* NULL */ ;
  return;
}

void 
measure_broadcast (int len, MPI_Comm communicator)
{
  int root;
  
  for (root = 0; root < num_nodes; root++)
    MPI_Bcast(_sphinx_buffer, len, MPI_CHAR, root, communicator);
}

void 
measure_broadcast_barrier (int len, MPI_Comm communicator)
{
  MPI_Bcast(_sphinx_buffer, len, MPI_CHAR, global_root, communicator);
  MPI_Barrier(communicator);
}

void 
measure_bcast_send_latency (int len, MPI_Comm communicator)
{
  MPI_Bcast(_sphinx_buffer, len, MPI_CHAR, global_root, communicator);
}

void 
measure_broadcast_round (int len, MPI_Comm communicator)
{
  int root;
  
  for (root = 0; root < num_nodes; root++)
    MPI_Bcast(_sphinx_buffer, len, MPI_CHAR, root, communicator);
}

void 
measure_broadcast_with_ACKer (int len, MPI_Comm communicator)
{
  MPI_Status status;
  int        ack_buf;
  
  MPI_Bcast(_sphinx_buffer, len, MPI_CHAR, global_root, communicator);

  MPI_Recv(&ack_buf, 4, MPI_BYTE, MPI_ANY_SOURCE, BROADCASTRESPONSE_TAG, 
	   communicator, &status);
}

void 
measure_broadcast_recv_ack (int len, MPI_Comm communicator)
{
  int        ack_src;
  MPI_Status status;
  int        ack_buf;
  
  MPI_Bcast(_sphinx_buffer, len, MPI_CHAR, global_root, communicator);

  for (ack_src = 1; ack_src < num_nodes; ack_src++)
    MPI_Recv(&ack_buf, 4, MPI_BYTE, MPI_ANY_SOURCE, BROADCASTRESPONSE_TAG, 
	     communicator, &status);
}

void 
measure_broadcast_send_ack (int len, MPI_Comm communicator)
{
  int        ack_buf;
  
  MPI_Bcast(_sphinx_buffer, len, MPI_CHAR, global_root, communicator);
  MPI_Send(&ack_buf, 4, MPI_BYTE, global_root, 
	   BROADCASTRESPONSE_TAG, communicator);
}

void 
measure_barrier (int len, MPI_Comm communicator)
{
  MPI_Barrier(communicator);
}

void 
measure_barrier_barrier (int len, MPI_Comm communicator)
{
  MPI_Barrier(communicator);
  generic_barrier (communicator);
}

void 
measure_Reduce_scale (int len, MPI_Comm communicator)
{
  MPI_Reduce(_sphinx_buffer, _sphinx_buffer_2, len, MPI_BYTE, 
	     			    MPI_BOR, global_root, communicator);
}

void 
measure_Reduce (int len, MPI_Comm communicator)
{
  int root;
  
  for (root = 0; root < num_nodes; root++)
    MPI_Reduce(_sphinx_buffer, _sphinx_buffer_2, len, MPI_BYTE, 
	     			           MPI_BOR, root, communicator);
}

void 
measure_Reduce_upper_bound (int len, MPI_Comm communicator)
{
  MPI_Reduce(_sphinx_buffer, _sphinx_buffer_2, len, MPI_BYTE, 
	     MPI_BOR, global_root, communicator);
  divergent_synch_op (global_root, communicator);
}

void 
measure_Scan_with_Acker (int len, MPI_Comm communicator)
{
  MPI_Status status;
  int        ack_buf;
  
  MPI_Scan (_sphinx_buffer, _sphinx_buffer_2, len, MPI_BYTE, 
	    					   MPI_BOR, communicator);

  MPI_Recv(&ack_buf, 4, MPI_BYTE, MPI_ANY_SOURCE, BROADCASTRESPONSE_TAG, 
	   communicator, &status);
}

void 
measure_Scan_send_latency (int len, MPI_Comm communicator)
{
  MPI_Scan (_sphinx_buffer, _sphinx_buffer_2, len, MPI_BYTE, 
	    					   MPI_BOR, communicator);
}

void 
measure_Scan_send_ack (int len, MPI_Comm communicator)
{
  int        ack_buf;
  
  MPI_Scan (_sphinx_buffer, _sphinx_buffer_2, len, MPI_BYTE, 
	    					   MPI_BOR, communicator);
  MPI_Send(&ack_buf, 4, MPI_BYTE, global_root, 
	   BROADCASTRESPONSE_TAG, communicator);
}

void 
measure_Scan (int len, MPI_Comm communicator)
{
  /* Time MPI_Comm_size iterations of all collective ops, including */
  /* those that do not use a root node... */
  int root;
  
  for (root = 0; root < num_nodes; root++)
    MPI_Scan (_sphinx_buffer, _sphinx_buffer_2, len, MPI_BYTE, 
	    					   MPI_BOR, communicator);
}

void 
measure_Alltoall (int len, MPI_Comm communicator)
{
  MPI_Alltoall (_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
    						  MPI_CHAR, communicator);
}

void 
measure_Alltoall_barrier (int len, MPI_Comm communicator)
{
  MPI_Alltoall (_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
    						  MPI_CHAR, communicator);
  generic_barrier (communicator);
}

void 
measure_Gather_scale (int len, MPI_Comm communicator)
{
  MPI_Gather(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
  				     MPI_CHAR, global_root, communicator);
}

void 
measure_Gather (int len, MPI_Comm communicator)
{
  int root;
  
  for (root = 0; root < num_nodes; root++)
    MPI_Gather(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
  						MPI_CHAR, root, communicator);
}

void 
measure_Gather_upper_bound (int len, MPI_Comm communicator)
{
  MPI_Gather(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
	     MPI_CHAR, global_root, communicator);
  divergent_synch_op (global_root, communicator);
}

void 
measure_Scatter (int len, MPI_Comm communicator)
{
  int root;
  
  for (root = 0; root < num_nodes; root++)
    MPI_Scatter(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
  						MPI_CHAR, root, communicator);
}

void 
measure_Scatter_send_latency (int len, MPI_Comm communicator)
{
  MPI_Scatter(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
	      MPI_CHAR, global_root, communicator);
}

void 
measure_Scatter_with_ACKer (int len, MPI_Comm communicator)
{
  MPI_Status status;
  int        ack_buf;
  
  MPI_Scatter(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
	      MPI_CHAR, global_root, communicator);

  MPI_Recv(&ack_buf, 4, MPI_BYTE, MPI_ANY_SOURCE, SCATTERRESPONSE_TAG, 
	   communicator, &status);
}

void 
measure_Scatter_send_ack (int len, MPI_Comm communicator)
{
  int        ack_buf;
  
  MPI_Scatter(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
	      MPI_CHAR, global_root, communicator);

  MPI_Send(&ack_buf, 4, MPI_BYTE, global_root, 
	   SCATTERRESPONSE_TAG, communicator);
}

void 
measure_Allreduce (int len, MPI_Comm communicator)
{
  MPI_Allreduce(_sphinx_buffer, _sphinx_buffer_2, len, MPI_BYTE, 
	        				MPI_BOR, communicator);
}

void 
measure_Allreduce_barrier (int len, MPI_Comm communicator)
{
  MPI_Allreduce(_sphinx_buffer, _sphinx_buffer_2, len, MPI_BYTE, 
	        				MPI_BOR, communicator);
  generic_barrier (communicator);
}

void 
measure_Allgather (int len, MPI_Comm communicator)
{
  MPI_Allgather (_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
    						   MPI_CHAR, communicator);
}

void 
measure_Allgather_barrier (int len, MPI_Comm communicator)
{
  MPI_Allgather (_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, len, 
    						   MPI_CHAR, communicator);
  generic_barrier (communicator);
}

void 
measure_Gatherv_scale (int len, MPI_Comm communicator)
{
  MPI_Gatherv(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, msg_counts, 
  			   msg_displs, MPI_CHAR, global_root, communicator);
}

void 
measure_Gatherv (int len, MPI_Comm communicator)
{
  int root;
  
  for (root = 0; root < num_nodes; root++)
    MPI_Gatherv(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, msg_counts, 
  				  msg_displs, MPI_CHAR, root, communicator);
}

void 
measure_Gatherv_upper_bound (int len, MPI_Comm communicator)
{
  MPI_Gatherv(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, msg_counts, 
	      msg_displs, MPI_CHAR, global_root, communicator);
  divergent_synch_op (global_root, communicator);
}

void 
measure_Scatterv (int len, MPI_Comm communicator)
{
  int root;
  
  for (root = 0; root < num_nodes; root++)
    MPI_Scatterv(_sphinx_buffer, msg_counts, msg_displs, MPI_CHAR, 
    			_sphinx_buffer_2, len, MPI_CHAR, root, communicator);
}

void 
measure_Scatterv_send_latency (int len, MPI_Comm communicator)
{
  MPI_Scatterv(_sphinx_buffer, msg_counts, msg_displs, MPI_CHAR, 
	       _sphinx_buffer_2, len, MPI_CHAR, global_root, communicator);
}

void 
measure_Scatterv_with_ACKer (int len, MPI_Comm communicator)
{
  MPI_Status status;
  int        ack_buf;
  
  MPI_Scatterv(_sphinx_buffer, msg_counts, msg_displs, MPI_CHAR, 
	       _sphinx_buffer_2, len, MPI_CHAR, global_root, communicator);

  MPI_Recv(&ack_buf, 4, MPI_BYTE, MPI_ANY_SOURCE, SCATTERVRESPONSE_TAG, 
	   communicator, &status);
}

void 
measure_Scatterv_send_ack (int len, MPI_Comm communicator)
{
  int        ack_buf;
  
  MPI_Scatterv(_sphinx_buffer, msg_counts, msg_displs, MPI_CHAR, 
	       _sphinx_buffer_2, len, MPI_CHAR, global_root, communicator);

  MPI_Send(&ack_buf, 4, MPI_BYTE, global_root, 
	   SCATTERVRESPONSE_TAG, communicator);
}

void 
measure_Allgatherv (int len, MPI_Comm communicator)
{
  MPI_Allgatherv(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, msg_counts, 
		                          msg_displs, MPI_CHAR, communicator);
}

void 
measure_Allgatherv_barrier (int len, MPI_Comm communicator)
{
  MPI_Allgatherv(_sphinx_buffer, len, MPI_CHAR, _sphinx_buffer_2, msg_counts, 
		                          msg_displs, MPI_CHAR, communicator);
  generic_barrier (communicator);
}

void 
measure_Alltoallv (int len, MPI_Comm communicator)
{
  MPI_Alltoallv(_sphinx_buffer, msg_counts, msg_displs, MPI_CHAR, 
    			_sphinx_buffer_2, msg_counts, msg_displs, MPI_CHAR, 
    								communicator);
}

void 
measure_Alltoallv_barrier (int len, MPI_Comm communicator)
{
  MPI_Alltoallv(_sphinx_buffer, msg_counts, msg_displs, MPI_CHAR, 
    			_sphinx_buffer_2, msg_counts, msg_displs, MPI_CHAR, 
    								communicator);
  generic_barrier (communicator);
}

void 
measure_Reduce_scatter (int len, MPI_Comm communicator)
{
  MPI_Reduce_scatter(_sphinx_buffer, _sphinx_buffer_2, msg_counts, MPI_BYTE, 
    							MPI_BOR, communicator);
}

void 
measure_Red_scatter_barrier (int len, MPI_Comm communicator)
{
  MPI_Reduce_scatter(_sphinx_buffer, _sphinx_buffer_2, msg_counts, MPI_BYTE, 
		     MPI_BOR, communicator);
  generic_barrier (communicator);
}

void 
measure_Comm_dup_scale (int len, MPI_Comm communicator)
{
  MPI_Comm new_comm;
  
  MPI_Comm_dup (communicator, &new_comm);
}

void 
measure_Comm_dup (int len, MPI_Comm communicator)
{
  MPI_Comm new_comm;
  
  /* Time MPI_Comm_size iterations of all collective ops, including */
  /* those that do not use a root node... */
  int root;
  
  for (root = 0; root < num_nodes; root++)
    /* Doing this in a loop exacerbates the existing memory leak */
    /* that is implicit in creating a communicator without freeing it... */
    MPI_Comm_dup (communicator, &new_comm);
}

void 
measure_Comm_split_scale (int len, MPI_Comm communicator)
{
  MPI_Comm new_comm;
  
  MPI_Comm_split (communicator, _sphinx_myid % 2, 0, &new_comm);
}

void 
measure_Comm_split (int len, MPI_Comm communicator)
{
  MPI_Comm new_comm;
  
  /* Time MPI_Comm_size iterations of all collective ops, including */
  /* those that do not use a root node... */
  int root;
  
  for (root = 0; root < num_nodes; root++)
    /* Doing this in a loop exacerbates the existing memory leak */
    /* that is implicit in creating a communicator without freeing it... */
    MPI_Comm_split (communicator, _sphinx_myid % 2, 0, &new_comm);
}

void 
measure_memcpy (int len, MPI_Comm communicator)
{
  /* Time MPI_Comm_size iterations of all collective ops, including */
  /* those that do not use a root node... */
  int root;
  
  for (root = 0; root < num_nodes; root++)
    memcpy (_sphinx_buffer, _sphinx_buffer_2, len);
}


/* Global */

/* char msg[max_msg_len]; */

extern params_t   params;       /* the parameter block */
extern double *cur_gaps;
extern char *out_file_name;

/*
   @FUN:
   @DOES: the collective pattern for measuring gaps
   @PARAMETERS: the actual measurement (which sould be one of the 
   collective pattern with ACKer variation...).
   @RETURNS: 0 if success, 666 otherwise
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
measure_gaps (measurement_t *ms)
{
  measurement_t local_ms;

  int
    _col_myid,
    i,
    loop_iters,
    local_max_allowed_length,
    found_ACKer = 0;

  double 
    start_time,
    end_time = 0.0,
    tbm_time,
    org_time;

  data_t single_data;

  MPI_Comm_size(ms->data.col_data.communicator,&num_nodes);

  /* finish intializing... */
  local_ms.pattern = COLLECTIVE;
  local_ms.data.col_data.communicator = ms->data.col_data.communicator;
  local_ms.communicator = ms->communicator;
  local_ms.iters_per_time = ms->iters_per_time;
  local_ms.overlap_iters = ms->overlap_iters;
  local_ms.second_overlap_iters = ms->second_overlap_iters;
  local_ms.data.col_data.iters = ms->data.col_data.iters;
  local_ms.standard_deviation = ms->standard_deviation;
  local_ms.max_rep = ms->max_rep;
  local_ms.min_rep = ms->min_rep;
  local_ms.result_list = NULL;
  local_ms.result_list = init_list(local_ms.result_list);
  global_root = local_ms.root = ms->root;

  local_ms.correct_ms = FALSE;
  
  single_data.num_dims = local_ms.dimensions_count = ms->dimensions_count - 1;
  single_data.status = NULL;

  local_ms.name = (char *) malloc (sizeof(char) * (strlen(ms->name) + 4));
  strcpy (local_ms.name, ms->name);
  strcat (local_ms.name, "gap");

  for (i = 0; i < ms->dimensions_count; i++) {
    if (ms->dimensions[i].variation == ACKER) {
      found_ACKer++;
    }
    else {
      /* copy ms->dimensions[i] into local_ms using struct assignment */
      local_ms.dimensions[i - found_ACKer] = ms->dimensions[i];
      single_data.arg[i - found_ACKer] = ms->data.col_data.result->arg[i];
    }
  }

  if (!(found_ACKer)) {
    free (local_ms.name);
    ERROR(INTERN,"invalid variation occured in measure_gaps");
    output_error (TRUE);
  }

  local_ms.data.col_data.result = &single_data;

  MPI_Comm_rank(ms->data.col_data.communicator,&_col_myid);
      
  /* iters_per_time is MPI_Comm_size for collective ops... */
  loop_iters = ms->data.col_data.iters;
  
  if (_sphinx_myid == 0) {
    if (!(local_max_allowed_length = 
	  ms->server_init (ms->max_rep *
			   (ms->pattern == MASTER_WORKER ? 
			    ms->data.mw_data.chunks:1),
			   ms->dimensions[0].max_steps, num_nodes, ms))) {
      free (local_ms.name);
      ERROR (NO_MEM, "no memory for messages");
      output_error (FALSE);
      return GENERIC_ERROR;
    }
  }
  else {
    if (!(local_max_allowed_length = 
	  ms->client_init (ms->max_rep, 
			   ms->dimensions[0].max_steps, num_nodes, ms))) {
      free (local_ms.name);
      ERROR(NO_MEM,"client has not enough memory for messages");
      output_error (FALSE);
      return GENERIC_ERROR;
    }
  }

  /* Check that the max_allowed_length hasn't decreased... */
  if (local_max_allowed_length < ms->max_allowed_len) {
    ERROR (USER, "local_max_allowed length < ms->max_allowed len");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  if (cur_gaps != NULL)
    free (cur_gaps);

  if ((msg_counts != NULL) && (msg_displs != NULL)) {
    /* MPI call is a vector variant... */
    /* We don't actually use variable message lengths, but so what */
    msg_counts[0] = ms->data.col_data.len;
    msg_displs[0] = 0;
    
    for (i = 1; i < num_nodes; i++) {
      msg_counts[i] = ms->data.col_data.len;
      msg_displs[i] = msg_displs[i-1] + ms->data.col_data.len; 
    }
  }

  /* In this case, timings are discarded so don't bother to gather... */
  if (CACHE_WARMUP > 0) {
    if (_col_myid == 0) /* so Server */
      /* cache warmups, not measured */
      am_init(CACHE_WARMUP, local_ms.pattern_in_omp_parallel);
      
    do {
      org_time = (start_time = MPI_Wtime()) - end_time;
      /* measure */
      ms->data.col_data.gap_routine_to_measure(ms->data.col_data.len, 
					       ms->data.col_data.communicator);
					     
      end_time = MPI_Wtime();
      tbm_time = end_time - start_time;
    }while (am_control_end(&local_ms, CACHE_WARMUP, tbm_time, 
			   org_time, USE_COMMUNICATOR,
			   ms->data.col_data.communicator, 0, TRUE));

    if (_col_myid == 0) /* so Server */
      am_free(local_ms.pattern_in_omp_parallel);
  }

  if (_col_myid == 0) /* so Server */
    /* and now for real ! */
    am_gap_init(ms->max_rep, num_nodes, local_ms.pattern_in_omp_parallel);
      
  do {
    org_time = (start_time = MPI_Wtime()) - end_time;

    /* measure */
    /* Quick and dirty; really should do loop in routine_to_measure */
    for (i = 0; i < loop_iters; i++)
      ms->data.col_data.gap_routine_to_measure(ms->data.col_data.len, 
					       ms->data.col_data.communicator);
					   
    end_time = MPI_Wtime();
    tbm_time = end_time - start_time;

  } while (am_gap_control_end(&local_ms, num_nodes, tbm_time, org_time, 
			      ms->data.col_data.communicator, FALSE));

  if (_col_myid == 0) { /* so Server */
    FILE
      *output_file;
    char 
      *pattern_str = "col";

    cur_gaps = 
      am_gap_fill_data (&local_ms,
			(ms->iters_over_nodes ? num_nodes : 1) * loop_iters);

    am_gap_free(local_ms.pattern_in_omp_parallel);

    if ((output_file = fopen (out_file_name,"a+")) == NULL) {
      free (local_ms.name);
      ERROR(FILE_OPEN,"append of gap measurement");
      return GENERIC_ERROR;
    }

    fprintf (output_file,"\n#-------------------------------"\
	     "\n#/*@""in%s_%s-gap%d.ski*/\n%s", pattern_str,
	     ms->name, num_nodes, 
	     measurement_data_to_string(ms, expl_text, 0));

    write_to_file (local_ms.result_list, output_file, 
		   ms->dimensions_count, ms->dimensions, FALSE);
    free_data_list (local_ms.result_list, DYNAMIC);
    sprintf (_sphinx_msg,
	     "Wrote data of measurement: %s-gap%d to file %s\n",
	     ms->name, num_nodes, out_file_name);

    write_to_log_file (_sphinx_msg);       
    fclose (output_file);
  } else {
    cur_gaps = (double *) malloc(sizeof(double));
    *cur_gaps =0.0;
    free (local_ms.result_list);
  }

  if (single_data.status != NULL)
    free (single_data.status);

  free (local_ms.name);

  if (_sphinx_myid == 0) {
    ms->server_free (ms);
  }
  else {
    ms->client_free (ms);
  }

  return SUCCESS;
}


extern int max_iters;


/*
   @FUN:
   @DOES: the collective pattern.
   @PARAMETERS: the actual measurement (which sould be one of the 
   collective pattern).
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int
col_pattern (measurement_t *ms, int n)
{
  int
    _col_myid,
    i,
    loop_iters,
    arg;

  MPI_Comm_rank(ms->communicator,&_col_myid);

  MPI_Comm_size(ms->data.col_data.communicator,&num_nodes);

#ifdef _HAVE_OMP_
  if (ms->pattern_in_omp_parallel)
    {
      {
#pragma omp master
	{
	  /* iters_per_time is MPI_Comm_size for collective ops... */
	  max_iters = loop_iters = get_max_iters_value (ms);
	}
      }
      {
#pragma omp barrier
      }
    }
  else
#endif
    /* iters_per_time is MPI_Comm_size for collective ops... */
    max_iters = loop_iters = get_max_iters_value (ms);
  
  switch (ms->dimensions[n].variation) {
  case NODES:
  case ACKER:
    arg = num_nodes;
    break;
  case LENGTH:
    arg = ms->data.col_data.len;
    break;
  case THREADS:
    arg = ms->omp_data.thread_count;
    break;
  case WORK_AMOUNT:
    arg = ms->omp_data.work_amount;
    break;
  case WORK_FUNCTION:
    arg = ms->omp_data.which_work;
    break;
  case SCHED_CAP:
    arg = ms->omp_data.cap_for_schedule_loops;
    break;
  case SCHED_CHUNKS:
    arg = ms->omp_data.schedule_chunks;
    break;
  case SCHEDULE:
    arg = ms->omp_data.loop_schedule;
    break;
  case ITERS:
    arg = loop_iters;
    break;
  case NO_VARIATION:
    arg = NO_VARIATION_ARG_VALUE;
    break;
  default:
    ERROR(USER,"invalid variation occured in col_pattern");
    output_error (FALSE);
    return GENERIC_ERROR;
  }

  if ((msg_counts != NULL) && (msg_displs != NULL)) {
    /* MPI call is a vector variant... */
    /* We don't actually use variable message lengths, but so what */
    msg_counts[0] = ms->data.col_data.len;
    msg_displs[0] = 0;
    
    for (i = 1; i < num_nodes; i++) {
      msg_counts[i] = ms->data.col_data.len;
      msg_displs[i] = msg_displs[i-1] + ms->data.col_data.len; 
    }
  }

#ifdef _HAVE_OMP_
  if (ms->pattern_in_omp_parallel)
    {
      {
#pragma omp master
	{
	  global_root = ms->root;
	}
      }
      {
#pragma omp barrier
      }
    }
  else
#endif
    global_root = ms->root;
  
  if (_col_myid == global_root) /* so Server */
  {
    double 
      start_time,
      end_time = 0.0,
      tbm_time,
      org_time;

    if (CACHE_WARMUP > 0)
    {
      am_init(CACHE_WARMUP, ms->pattern_in_omp_parallel);
      
      do
      {
	org_time = (start_time = MPI_Wtime()) - end_time;
	/* measure */
	ms->data.col_data.routine_to_measure(ms->data.col_data.len, 
					     ms->data.col_data.communicator);
					     
	end_time = MPI_Wtime();
	tbm_time = end_time - start_time;
      }while (am_control_end(ms, CACHE_WARMUP, tbm_time, 
			     org_time, USE_COMMUNICATOR,
			     ms->data.col_data.communicator, 
			     global_root, TRUE));

      am_free(ms->pattern_in_omp_parallel);
    }

    /* and now for real ! */
    am_init(ms->max_rep, ms->pattern_in_omp_parallel);
      
    do
    {
      org_time = (start_time = MPI_Wtime()) - end_time;
      /* measure */
      /* Quick and dirty change; really should loop in routine_to_measure */
      for (i = 0; i < loop_iters; i++)
	ms->data.col_data.routine_to_measure(ms->data.col_data.len, 
					     ms->data.col_data.communicator);
					   
      end_time = MPI_Wtime();
      tbm_time = end_time - start_time;
    }while (am_control_end(ms, arg, tbm_time, org_time, 
			   USE_COMMUNICATOR,
			   ms->data.col_data.communicator, 
			   global_root, FALSE));

    am_fill_data (ms, ms->data.col_data.len, ms->data.col_data.result,
		  (ms->iters_over_nodes ? num_nodes : 1) * loop_iters);

    am_free(ms->pattern_in_omp_parallel);

    if (_col_myid != 0) {
      /* send results to task zero */
      send_data (ms->data.col_data.communicator, ms->data.col_data.result, 0);
    }

    return 0;
  }
  /* else client */
  if (CACHE_WARMUP > 0) {
    /* once for cache */
    do {
      ms->data.col_data.client_routine(ms->data.col_data.len, 
				       ms->data.col_data.communicator);
    }while (am_control_end(ms, 0, 0.0, 0.0, USE_COMMUNICATOR, 
			   ms->data.col_data.communicator, global_root, TRUE));
  }
  /* once for real */
  do {
    /* Quick and dirty change; really should do loop in client_routine */
    for (i = 0; i < loop_iters; i++)
      ms->data.col_data.client_routine(ms->data.col_data.len, 
				       ms->data.col_data.communicator);
  }while (am_control_end(ms, 0, 0.0, 0.0, USE_COMMUNICATOR, 
			 ms->data.col_data.communicator, global_root, FALSE));

  if (_col_myid == 0) {
    /* receive results from root */
    recv_data (ms->data.col_data.communicator, 
	       ms->data.col_data.result, global_root);
  }

  return 0;
}
