/*
$Log: sphinx_p2p.c,v $
Revision 1.17  2000/09/15 00:05:00  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.16  2000/08/25 23:17:17  bronis
Added OpenMP tests

Revision 1.15  2000/03/16 15:48:39  bronis
fixed mpguidec warnings

Revision 1.14  2000/02/17 14:18:59  bronis
added first real non-blocking tests

Revision 1.13  2000/01/14 23:34:55  bronis
purified recent changes

Revision 1.12  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.11  1999/10/04 15:53:06  bronis
fixed ACKer position bugs

Revision 1.10  1999/10/01 21:36:53  bronis
Added debugged Root variation

Revision 1.9  1999/09/29 00:23:49  bronis
removed most restrictions on ACKER variation

Revision 1.8  1999/09/23 17:08:45  bronis
cleaned up multi dim stuff

Revision 1.7  1999/09/21 15:59:51  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.6  1999/09/16 23:57:23  bronis
Fixed pattern return values...

Revision 1.5  1999/09/16 21:07:44  srtaylor
Added max_message_len check

Revision 1.4  1999/09/16 00:15:45  srtaylor
Outputs correct results for multiple dimensions

Revision 1.3  1999/09/15 15:52:30  bronis
partial fix of data_list.c

Revision 1.2  1999/09/14 16:38:51  srtaylor
First cut at multiple dimensions

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_aux.h"
#include "p2p_test1.h"
#include "pattern.h"
#include "sphinx_error.h"
#include "sphinx_mem.h"
#include "sphinx_tools.h"
#include "sphinx_params.h"
#include "automeasure.h"
#include "sphinx_aux_test.h"



/* would like to eventually replace these with short assembler routines */
/* for specific platforms so we can guarantee takes an exact number of */
/* cycles; then we would only need to measure the clock rate  */
/* to determine the overlap time implied by a number of repetitions... */ 
#define COMPUTE_OVERLAP  for (_overlap_index_ = 0; \
                              _overlap_index_ < overlap_cap; \
			      _overlap_index_++);

#define COMPUTE_SECOND_OVERLAP  for (_overlap_index_ = 0; \
			             _overlap_index_ < second_overlap_cap; \
			             _overlap_index_++);

static int overlap_cap, second_overlap_cap, _overlap_index_;

MPI_Status p2p_dummy (int msglen, int node, MPI_Comm communicator);

MPI_Status server_Send_Recv     (int msglen, int node, MPI_Comm communicator);
MPI_Status server_Send_Iprobe_Recv (int msglen, int node, MPI_Comm com);
MPI_Status server_Send_Irecv    (int msglen, int node, MPI_Comm communicator);
MPI_Status server_Send_Recv_AT  (int msglen, int node, MPI_Comm communicator);
MPI_Status server_Isend_Recv    (int msglen, int node, MPI_Comm communicator);
MPI_Status server_Ssend_Recv    (int msglen, int node, MPI_Comm communicator);
MPI_Status server_Bsend_Recv    (int msglen, int node, MPI_Comm communicator);
MPI_Status client_Recv_Send     (int msglen, int node, MPI_Comm communicator);
MPI_Status client_Iprobe_Recv_Send (int msglen, int node, MPI_Comm com);
MPI_Status client_Irecv_Send    (int msglen, int node, MPI_Comm communicator);
MPI_Status client_Recv_AT_Send  (int msglen, int node, MPI_Comm communicator);
MPI_Status client_Recv_Ssend    (int msglen, int node, MPI_Comm communicator);
MPI_Status client_Recv_Isend    (int msglen, int node, MPI_Comm communicator);
MPI_Status client_Recv_Bsend    (int msglen, int node, MPI_Comm communicator);

MPI_Status server_Send          (int msglen, int node, MPI_Comm communicator);
MPI_Status server_Isend         (int msglen, int node, MPI_Comm communicator);

MPI_Status server_overlap       (int msglen, int node, MPI_Comm communicator);
MPI_Status server_Irecv_overlap (int msglen, int node, MPI_Comm communicator);
MPI_Status server_Isend_overlap (int msglen, int node, MPI_Comm communicator);
MPI_Status server_Isend_both_overlaps (int msglen, 
				       int node, MPI_Comm communicator);
MPI_Status server_Ssend         (int msglen, int node, MPI_Comm communicator);
MPI_Status client_Recv          (int msglen, int node, MPI_Comm communicator);
MPI_Status client_Recv_and_ACK  (int msglen, int node, MPI_Comm communicator);
MPI_Status client_Send_and_recv_ACK  (int msglen, int node, 
				      MPI_Comm communicator);

MPI_Status server_Sendrecv      (int msglen, int node, MPI_Comm communicator);
MPI_Status client_Sendrecv      (int msglen, int node, MPI_Comm communicator);

MPI_Status server_Sendrecv_replace (int msglen, int node, MPI_Comm com);
MPI_Status client_Sendrecv_replace (int msglen, int node, MPI_Comm com);

/*
   @FUNS:
   @NAME: p2p_init_...
   @DOES: the following p2p_init_... functions initialize the ms with
   the correct data, to measure the specific point-to-point MPI function.
   @PARAMETERS: measurement ms and the place to hold the measured 
   results (data).
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/

void 
p2p_init_dummy (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = p2p_dummy;
  ms->data.p2p_data.client_op = p2p_dummy;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  /* NOTE DO NOT USE CORRECTION ON THIS SINCE IT IS THE OVERHEAD... */

  return;
}

void 
p2p_init_Send_Recv (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Send_Recv;
  ms->data.p2p_data.client_op = client_Recv_Send;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_aux (ms);

  return;
}

void 
p2p_init_Send_Iprobe_Recv (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Send_Iprobe_Recv;
  ms->data.p2p_data.client_op = client_Iprobe_Recv_Send;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_aux (ms);

  return;
}

void 
p2p_init_Send_Irecv (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Send_Irecv;
  ms->data.p2p_data.client_op = client_Irecv_Send;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_aux (ms);

  return;
}


void 
p2p_init_Send_Recv_AT (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Send_Recv_AT;
  ms->data.p2p_data.client_op = client_Recv_AT_Send;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_aux (ms);

  return;
}


void 
p2p_init_Ssend_Recv (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Ssend_Recv;
  ms->data.p2p_data.client_op = client_Recv_Ssend;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_aux (ms);

  return;
}

void 
p2p_init_Isend_Recv (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Isend_Recv;
  ms->data.p2p_data.client_op = client_Recv_Isend;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_aux (ms);

  return;
}

void 
p2p_init_Bsend_Recv (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_two_buffers_attach_p2p;
  ms->client_init = mem_init_two_buffers_attach_p2p;
  ms->server_free = mem_release_detach;
  ms->client_free = mem_release_detach;
  ms->data.p2p_data.server_op = server_Bsend_Recv;
  ms->data.p2p_data.client_op = client_Recv_Bsend;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_aux (ms);

  return;
}

void 
p2p_init_Sendrecv (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_two_buffers;
  ms->client_init = mem_init_two_buffers;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Sendrecv;
  ms->data.p2p_data.client_op = client_Sendrecv;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_aux (ms);

  return;
}

void 
p2p_init_Sendrecv_replace (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Sendrecv_replace;
  ms->data.p2p_data.client_op = client_Sendrecv_replace;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_aux (ms);

  return;
}

void 
p2p_init_overlap (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_overlap;
  ms->data.p2p_data.client_op = server_overlap;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_aux (ms);

  return;
}

void 
p2p_init_Isend_Recv_overlap (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Isend_overlap;
  ms->data.p2p_data.client_op = client_Recv_and_ACK;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_overlap_aux (ms);

  return;
}

void 
p2p_init_Isend_Recv_both_overlaps (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Isend_both_overlaps;
  ms->data.p2p_data.client_op = client_Recv_and_ACK;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_both_overlaps_aux (ms);

  return;
}

void 
p2p_init_Irecv_Send_overlap (measurement_t *ms)
{
  ms->pattern = P2P;
  ms->server_init = mem_init_one_buffer;
  ms->client_init = mem_init_one_buffer;
  ms->server_free = mem_release;
  ms->client_free = mem_release;
  ms->data.p2p_data.server_op = server_Irecv_overlap;
  ms->data.p2p_data.client_op = client_Send_and_recv_ACK;
  ms->data.p2p_data.which_to_measure = MEASURE_MAX;
  ms->data.p2p_data.len = DEF_MESSAGE_LEN;
  ms->data.p2p_data.result = NULL;
  ms->data.p2p_data.communicator = MPI_COMM_WORLD;

  initialize_p2p_overlap_and_ack_aux (ms);

  return;
}

MPI_Status 
p2p_dummy (int msglen, int max_node, 
	   MPI_Comm communicator)
{
  MPI_Status status;
  /* be dummy; this can lead to compiler warnings... */
  return (status);
}

/*
   @FUNS:
   @NAME: server_...
   @DOES: call the MPI-Function to be measured by the 
   process 0 (sometimes named server). The reason not to call this
   MPI-Function directly is to achieve a function-header comman to all
   measured functions.
   @PARAMETERS: message length len, number of the node to communicate with,
   Communicator comminicator.
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: _sphinx_buffer (_sphinx_buffer_2 set correctly, done with
   mem_init_one_buffers or mem_init_two_buffers.
*/
MPI_Status 
server_Send_Recv(int msglen, int max_node, 
		 MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Send (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, 0, communicator);
  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, 1, communicator,
	    &status);

  return (status);
}

MPI_Status 
server_Send_Iprobe_Recv(int msglen, int max_node, 
			MPI_Comm communicator)
{
  MPI_Status status;
  int flag;

  MPI_Send (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, 0, communicator);
  
  do {
    MPI_Iprobe (max_node, 1, communicator, 
		&flag, &status);
  }while (!flag);

  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, 1, communicator, &status);

  return (status);
}

MPI_Status 
server_Send_Irecv(int msglen, int max_node, 
		  MPI_Comm communicator)
{
  MPI_Status status;
  MPI_Request req;

  MPI_Send (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, 0, communicator);
  MPI_Irecv (_sphinx_buffer, msglen, MPI_CHAR,
	     max_node, 1, communicator, &req);
  MPI_Wait (&req, &status);

  return (status);
}

MPI_Status 
server_Send_Recv_AT(int msglen, int max_node, 
		    MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Send (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, 0, communicator);
  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, MPI_ANY_TAG, 
	    communicator, &status);

  return (status);
}

MPI_Status 
server_Bsend_Recv(int msglen, int max_node, 
		  MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Bsend (_sphinx_buffer, msglen, MPI_CHAR, 
	     max_node, 0, communicator);

  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, 1, communicator, &status);

  return (status);
}

MPI_Status 
server_Isend_Recv (int msglen, int max_node, 
		   MPI_Comm communicator)
{
  MPI_Status status;
  MPI_Request req;

  MPI_Isend (_sphinx_buffer, msglen, MPI_CHAR, 
	     max_node, 0, communicator, &req);
  MPI_Wait (&req, &status);
  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, 1, communicator,&status);

  return (status);
}

MPI_Status 
server_overlap (int msglen, int node, MPI_Comm communicator)
{
  MPI_Status  status;

  COMPUTE_OVERLAP

  /* this can lead to compiler warnings... */
  return (status);
}

MPI_Status 
server_Irecv_overlap (int msglen, int node, MPI_Comm communicator)
{
  MPI_Status  status;
  MPI_Request req;
  int         ack_buf;

  MPI_Irecv (_sphinx_buffer, msglen, MPI_CHAR, 
	     node, 0, communicator, &req);
  COMPUTE_OVERLAP
  MPI_Wait (&req, &status);

  MPI_Send (&ack_buf, 4, MPI_BYTE, node, P2P_ACK_TAG, communicator);
  
  return (status);
}

MPI_Status 
server_Isend_overlap (int msglen, int max_node, 
		      MPI_Comm communicator)
{
  MPI_Status  status;
  MPI_Request req;
  int         ack_buf;

  MPI_Isend (_sphinx_buffer, msglen, MPI_CHAR, 
	     max_node, 0, communicator, &req);
  COMPUTE_OVERLAP
  MPI_Wait (&req, &status);
  MPI_Recv(&ack_buf, 4, MPI_BYTE, max_node, 
	   P2P_ACK_TAG, communicator, &status);

  return (status);
}

MPI_Status 
server_Isend_both_overlaps (int msglen, int max_node, 
			    MPI_Comm communicator)
{
  MPI_Status  status;
  MPI_Request req;
  int         ack_buf;

  MPI_Isend (_sphinx_buffer, msglen, MPI_CHAR, 
	     max_node, 0, communicator, &req);
  COMPUTE_OVERLAP
  MPI_Wait (&req, &status);
  COMPUTE_SECOND_OVERLAP
  MPI_Recv(&ack_buf, 4, MPI_BYTE, max_node, P2P_ACK_TAG, 
	   communicator, &status);

  return (status);
}



/*
   @FUNS:
   @NAME: client_...
   @DOES: call the MPI-Function to be measured by the 
   processes not 0 (sometimes named clients). The reason not to call this
   MPI-Function directly is to achieve a function-header comman to all
   measured functions.
   @PARAMETERS: message length len, number of the node to communicate with,
   Communicator comminicator.
   @RETURNES: nothing.
   @SIDEEFFECTS: none.
   @ASSUMES: _sphinx_buffer (_sphinx_buffer_2 set correctly, done with
   mem_init_one_buffers or mem_init_two_buffers.
*/
MPI_Status 
client_Recv_Send (int msglen, int node, 
		  MPI_Comm communicator)
{
  MPI_Status status;
  
  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    0, 0, communicator, &status);
  
  MPI_Send (_sphinx_buffer, msglen, MPI_CHAR, 
	    0, 1, communicator);
  
  return (status);
}

MPI_Status 
client_Iprobe_Recv_Send (int msglen, int node, 
			 MPI_Comm communicator)
{
  MPI_Status status;
  int flag;

  MPI_Iprobe (0, 0, communicator, &flag, &status);
  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    0, 0, communicator, &status);
  MPI_Send (_sphinx_buffer, msglen, MPI_CHAR, 
	    0, 1, communicator);
  
  return (status);
}

MPI_Status 
client_Irecv_Send (int msglen, int node, 
		   MPI_Comm communicator)
{
  MPI_Status status;
  MPI_Request req;

  MPI_Irecv (_sphinx_buffer, msglen, MPI_CHAR, 
	     0, 0, communicator,
	    &req);
  MPI_Wait (&req, &status);

  MPI_Send (_sphinx_buffer, msglen, MPI_CHAR, 
	    0, 1, communicator);
  
  return (status);
}


MPI_Status 
client_Recv_AT_Send (int msglen, int node, 
		     MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    0, MPI_ANY_TAG, communicator, &status);
  MPI_Send (_sphinx_buffer, msglen, MPI_CHAR, 
	    0, 1, communicator);
  
  return (status);
}

MPI_Status 
client_Recv_Bsend (int msglen, int node, 
		   MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    0, 0, communicator, &status);

  MPI_Bsend (_sphinx_buffer, msglen, MPI_CHAR, 
	     0, 1, communicator);
  
  return (status);
}


MPI_Status 
client_Recv_Isend (int msglen, int node, 
		   MPI_Comm communicator)
{
  MPI_Status status;
  MPI_Request req;

  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    0, 0, communicator, &status);
  MPI_Isend (_sphinx_buffer, msglen, MPI_CHAR, 
	     0, 1, communicator, &req);
  MPI_Wait (&req, &status);
  
  return (status);
}

MPI_Status 
server_Ssend_Recv(int msglen, int max_node, 
		  MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Ssend (_sphinx_buffer, msglen, MPI_CHAR, 
	     max_node, 0, communicator);
  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, 1, communicator,
	    &status);

  return (status);
}

MPI_Status 
client_Recv_Ssend (int msglen, int node, 
		   MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 0, 0, communicator,
	    &status);
  MPI_Ssend (_sphinx_buffer, msglen, MPI_CHAR, 0, 1, communicator);
  
  return (status);
}

MPI_Status 
server_Send(int msglen, int max_node, 
	    MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Send (_sphinx_buffer, msglen, MPI_CHAR, 
	    max_node, 0, communicator);

  /* this can lead to compiler warnings... */
  return (status);
}

MPI_Status 
server_Isend(int msglen, int max_node, 
	     MPI_Comm communicator)
{
  MPI_Status status;
  MPI_Request req;

  MPI_Isend (_sphinx_buffer, msglen, MPI_CHAR, 
	     max_node, 0, communicator, &req);
  MPI_Wait (&req, &status);

  return (status);
}


MPI_Status 
server_Ssend (int msglen, int max_node, 
	      MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Ssend (_sphinx_buffer, msglen, MPI_CHAR, 
	     max_node, 0, communicator);

  /* this can lead to compiler warnings... */
  return (status);
}

MPI_Status 
client_Recv (int msglen, int node, 
	     MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 
	    0, 0, communicator, &status);
  
  return (status);
}

MPI_Status 
client_Recv_and_ACK (int msglen, int node, 
		     MPI_Comm communicator)
{
  MPI_Status status;
  int        ack_buf;
  
  MPI_Recv (_sphinx_buffer, msglen, MPI_CHAR, 0, 0, communicator, &status);
  MPI_Send (&ack_buf, 4, MPI_BYTE, 0, P2P_ACK_TAG, communicator);
  
  return (status);
}

MPI_Status 
client_Send_and_recv_ACK (int msglen, int node, 
			  MPI_Comm communicator)
{
  MPI_Status status;
  int        ack_buf;
  
  MPI_Send (_sphinx_buffer, msglen, MPI_CHAR, 0, 0, communicator);

  MPI_Recv (&ack_buf, 4, MPI_BYTE, MPI_ANY_SOURCE, P2P_ACK_TAG, 
	    communicator, &status);

  return (status);
}

MPI_Status 
server_Sendrecv_replace (int msglen, int node, 
			 MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Sendrecv_replace (_sphinx_buffer, msglen, MPI_CHAR, 
			node, 0, node, 1, communicator, &status);
  return (status);
}

MPI_Status 
client_Sendrecv_replace (int msglen, int node, 
			 MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Sendrecv_replace (_sphinx_buffer, msglen, MPI_CHAR, 
			0, 1, 0, 0, communicator, &status);
  return (status);
}

MPI_Status 
server_Sendrecv (int msglen, int node, 
		 MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Sendrecv (_sphinx_buffer, msglen, MPI_CHAR, node, 0, 
		_sphinx_buffer_2, msglen, MPI_CHAR, node, 1, 
		communicator, &status);
  return (status);
}

MPI_Status 
client_Sendrecv (int msglen, int node, 
		 MPI_Comm communicator)
{
  MPI_Status status;

  MPI_Sendrecv (_sphinx_buffer, msglen, MPI_CHAR, 0, 1, 
		_sphinx_buffer_2, msglen, MPI_CHAR, 0, 0, 
		communicator, &status);
  return (status);
}


extern long int 
  _skib_size;   /* size of sphinx internal buffer */

/*
#define NO_BCAST
*/
/*
#define NO_COM
*/
#define MSG_LEN_TEST SPHINX_MIN(1024, _skib_size/2)

extern int
  _sphinx_myid;

#ifdef MODULE_TEST
extern char 
  _sphinx_buffer[0x1000];
#else
extern char
  *_sphinx_buffer;
#endif


extern params_t params;       /* need iters_per_time_default... */
extern double *p2p_latencies;
extern char *out_file_name;

#define P2P_MSG_LEN_TEST       4
/*
   @FUN:
   @DOES: finds latency between task source and all other tasks
   @PARAMETERS: source id
   @RETURNS: 0 if success, 666 otherwise
   @SIDEEFFECTS: sets values in p2p_latencies...
   @ASSUMES: _sphinx_myid set
*/
int
measure_p2p_latencies (int source)
{
  int receiver, error, numprocs, i, base;

  double start_time, org_time, tbm_time, end_time = 0.0;
  
  data_list_t liste;

  data_t data;

  measurement_t local_ms;

  MPI_Status status;

  char p2p_buf[P2P_MSG_LEN_TEST];
    
  char	local_name[] = "measure_p2p_latencies";
  
  data.num_dims = 1;
  data.status = NULL;
  data.reference = UNMEASURED;
  local_ms.data.p2p_data.result = &data;
  local_ms.name = local_name;
  local_ms.data.p2p_data.communicator = 
    local_ms.communicator = MPI_COMM_WORLD;
  local_ms.iters_per_time = local_ms.data.p2p_data.iters = 
    params.iters_per_time_default;
  local_ms.overlap_iters = local_ms.second_overlap_iters = 
    params.overlap_default;
  local_ms.standard_deviation = params.standard_deviation_default;
  local_ms.max_rep = params.max_rep_default;
  local_ms.min_rep = params.min_rep_default;
  local_ms.pattern = P2P;
  local_ms.dimensions[0].variation = ACKER;
  local_ms.dimensions[0].start = 1;
  local_ms.data.p2p_data.len = P2P_MSG_LEN_TEST;
  local_ms.dimensions[0].scale = FIXED_LIN;
  local_ms.dimensions_count = 1;
  local_ms.correct_ms = FALSE;
  local_ms.pattern_in_omp_parallel = FALSE;

  MPI_Comm_size (MPI_COMM_WORLD, &numprocs);

  local_ms.nodes = numprocs;
  local_ms.dimensions[0].end = numprocs - 1;
  local_ms.dimensions[0].stepwidth  = 1.0;

  if (p2p_latencies == NULL) {
    p2p_latencies = (double *) malloc (numprocs * numprocs * sizeof(double));
    for (i = 0; i < numprocs * numprocs; i++) {
      p2p_latencies[i] = UNMEASURED;
    }
  }

  base = source * numprocs;
  
  /* latency between source and itself as measured... */
  p2p_latencies[base + source] = 1.0;

  if (_sphinx_myid == source) {        
    init_list (&liste);
    for (receiver = 0; receiver < numprocs; receiver++) {
      /* measure only if not previously measured the other way... */
      if (p2p_latencies[receiver * numprocs + source] != UNMEASURED) {
	p2p_latencies[base + receiver] = 
	  p2p_latencies[receiver * numprocs + source];
	
	if ((_sphinx_myid == 0) && (receiver != source)) {
	  data.arg[0] = receiver;
	  data.result = p2p_latencies[base + receiver];
	  mark_status (&data, "EXISTING");
	  
	  append (&liste,&data,&error);

	  if (data.status != NULL) {
	    free (data.status);
	    data.status = NULL;
	  }
	}
      }
      else { /* receiver/source pair not previously measured */
	data.arg[0] = receiver;
      
	if (CACHE_WARMUP > 0) {
	  /* cache warmups, not measured */
	  if (!am_init(CACHE_WARMUP, FALSE)) {
	    ERROR(NO_MEM,"measure_p2p_latencies cache ");
	    output_error (TRUE); /* ok??????? */
	  }
	
	  do {
	    D(fprintf (stderr, 
		       "server %d: starting test meas.(cache)to %d\n", 
		       _sphinx_myid, receiver);)
	    org_time = (start_time = MPI_Wtime()) - end_time;
	    /* measure */
#ifndef NO_COM
	    MPI_Send (p2p_buf, P2P_MSG_LEN_TEST, MPI_BYTE, receiver, 0, 
		      local_ms.data.p2p_data.communicator);
	    MPI_Recv (p2p_buf, P2P_MSG_LEN_TEST, MPI_BYTE, receiver, 1, 
		      local_ms.data.p2p_data.communicator, &status);
#endif	
	    end_time = MPI_Wtime();
	    tbm_time = end_time - start_time;
	  }while (am_control_end(&local_ms, CACHE_WARMUP, tbm_time, org_time, 
				 receiver, MPI_COMM_NULL, source, TRUE));
	  am_free(FALSE);
	}

	/* and now for real ! */
	if (!am_init(local_ms.max_rep, FALSE)) {
	  ERROR(NO_MEM,"find min/max");
	  output_error (TRUE); /* ok??????? */
	}
	
	do {
	  D(fprintf (stderr, "server %d: starting test meas. (real to %d)\n", 
		     _sphinx_myid, receiver);)
	  org_time = (start_time = MPI_Wtime()) - end_time;
	  /* measure */
#ifndef NO_COM
	  /* Quick and dirty; really should loop in routine_to_measure */
	  for (i = 0; i < local_ms.iters_per_time; i++) {
	    MPI_Send (p2p_buf, P2P_MSG_LEN_TEST, MPI_BYTE, receiver, 0, 
		      local_ms.data.p2p_data.communicator);
	    MPI_Recv (p2p_buf, P2P_MSG_LEN_TEST, MPI_BYTE, receiver, 1, 
		      local_ms.data.p2p_data.communicator, &status);
	  }
#endif
	  end_time = MPI_Wtime();
	  tbm_time = end_time - start_time;
	}while (am_control_end(&local_ms, receiver, tbm_time, org_time, 
			       receiver, MPI_COMM_NULL, source, FALSE));
	
	am_fill_data (&local_ms, receiver, &data, local_ms.iters_per_time);
	am_free(FALSE);
	append(&liste,&data,&error);
	
	if (data.status != NULL) {
	  free (data.status);
	  data.status = NULL;
	}

	/* we could set this to 1.0 for source not task 0 since */
	/* don't plan to use if source not 0 but why not store it... */
	p2p_latencies[source * numprocs + receiver] = data.result;

	if (error != DL_NO_ERROR) {
	  ERROR (NO_MEM,"measure_p2p_latencies");
	  output_error(TRUE);
	}
      }
    }

#ifndef NO_BCAST
    /* Use this broadcast to "synch" up processes; Don't use */
    /* barrier since don't want synching to interfere w/measurements */
    MPI_Bcast (&(local_ms.data.p2p_data.max_node), 1, MPI_INT, source,
	       local_ms.data.p2p_data.communicator);
#endif

    if (_sphinx_myid != 0) {
      /* send the data list to task 0 so it can store & print out results */
      send_data_list (MPI_COMM_WORLD, &liste, 0);
      
      free_data_list (&liste, STATIC);
    }

    D1(fprintf (stderr, "server %d: after Bcast\n", _sphinx_myid);)
  }
  else { /* not source */
    if (p2p_latencies[_sphinx_myid * numprocs + source] == UNMEASURED) {
      /* measure latency between this task and source */
      /* for cache */
      if (CACHE_WARMUP > 0) {
	do {
	  D(fprintf (stderr, "client %d: at recv (cache)\n", _sphinx_myid);)
#ifndef NO_COM
	  MPI_Recv (p2p_buf, P2P_MSG_LEN_TEST, MPI_BYTE, source, 0, 
		    local_ms.data.p2p_data.communicator, &status);
	  MPI_Send (p2p_buf, P2P_MSG_LEN_TEST, MPI_BYTE, source, 1, 
		    local_ms.data.p2p_data.communicator);
#endif	
	}while (am_control_end(&local_ms, 0, 0.0, 0.0, 0, 
			       MPI_COMM_NULL, source, TRUE));
      }
      /* for measurement */
      do {
	D(fprintf (stderr, "client %d: at recv (real)\n", _sphinx_myid);)
#ifndef NO_COM
	for (i = 0; i <  local_ms.iters_per_time; i++) {
	  MPI_Recv (p2p_buf, P2P_MSG_LEN_TEST, MPI_BYTE, source, 0, 
		    local_ms.data.p2p_data.communicator, &status);
	  MPI_Send (p2p_buf, P2P_MSG_LEN_TEST, MPI_BYTE, source, 1, 
		    local_ms.data.p2p_data.communicator);
	}
#endif
      }while (am_control_end(&local_ms, 0, 0.0, 0.0, 0, 
			     MPI_COMM_NULL, source, FALSE));
    }
#ifndef NO_BCAST
      /* Use this broadcast to "synch" up processes; Don't use */
      /* barrier since don't want synching to interfere w/measurements */
    MPI_Bcast (&(local_ms.data.p2p_data.max_node), 1, MPI_INT, source,
	       local_ms.data.p2p_data.communicator);
#endif

    D1(fprintf (stderr, "client %d: after Bcast\n", _sphinx_myid);)

    if (_sphinx_myid == 0) {
      int recvd_size;

      /* recv the data list from source */
      init_list (&liste);

      recv_data_list (MPI_COMM_WORLD, &liste, source);

      if ((recvd_size = number_of_elements(&liste)) == 0) {
	/* use already measured values for all; build list for printing */
	mark_status (&data, "EXISTING");
	data.standard_deviation = 0.0;
	data.count = 0;
	
	for (receiver = 0; receiver < numprocs; receiver++) {
	  if (receiver != source) {
	    data.arg[0] = receiver;
	    data.result = p2p_latencies[base + receiver] = 
	      p2p_latencies[receiver * numprocs + source];

	    if (data.result == UNMEASURED) {
	      ERROR (INTERN, 
		     "Failed to measure data point in measure_p2p_latencies");
	      output_error(TRUE);
	    }

	    append(&liste,&data,&error);
	  }
	}
      }
      else { /* augment list as necessary for printing */
	read_ele (&liste, START, 0, &data, &error);

	recvd_size--;

	/* assume put on in receiver order, which is what we did... */
	for (receiver = 0; receiver < numprocs; receiver++) {
	  if (receiver != source) {
	    if (data.arg[0] == receiver) {
	      p2p_latencies[base + receiver] = data.result;

	      /* need to do this since data is a copy of list element... */
	      if (data.status != NULL) {
		free (data.status);
		data.status = NULL;
	      }

	      if (recvd_size) {
		read_ele (&liste, LAST, 1, &data, &error);
		recvd_size--;
	      }
	      else { /* set data to "high" value... */
		data.arg[0] = numprocs;
	      }
	    }
	    else { /* need to get already measured value... */
	      data_t old_data;
	      
	      if (data.arg[0] < receiver) {
		ERROR(INTERN,"Unexpected receiver in data");
		output_error (TRUE);
	      }		

	      old_data.status = NULL;
	      mark_status (&old_data, "EXISTING");
	      old_data.num_dims = 1;
	      old_data.arg[0] = receiver;
	      old_data.count = 0;
	      old_data.standard_deviation = 0.0;
	      old_data.result = p2p_latencies[base + receiver] = 
		p2p_latencies[receiver * numprocs + source];

	      if (data.arg[0] == numprocs)
		append (&liste, &old_data, &error);
	      else { /* add old_data behind next new measurement */
		add(&liste, LAST, -1, &old_data, &error);

		/* put "last" item back to one that was copied into data... */
		liste.list_last = liste.list_last->next;
	      }

	      free (old_data.status);
	    }
	  }
	}
      }
    }
    else { /* I'm not 0 */
      for (i = 0; i < numprocs; i++)
	/* mark all pairs (source, i) as measured... */
	p2p_latencies[base+i] = 1.0;
    }
  }

  if (_sphinx_myid == 0) {
    /* print out results */
    FILE *output_file;

    if ((output_file = fopen (out_file_name,"a+")) == NULL) {
      ERROR(FILE_OPEN,"append of gap measurement");
      return GENERIC_ERROR;
    }

    fprintf (output_file,"\n#-------------------------------"\
	     "\n#/*@""in measure_p2p_latencies-source=%d.ski*/\n%s", 
	     source, measurement_data_to_string(&local_ms, expl_text, 0));
    write_to_file (&liste, output_file, 1, local_ms.dimensions, FALSE);
    sprintf (_sphinx_msg,
	     "Wrote data of measurement: %s-source=%d to file %s\n",
	     local_name, source, out_file_name);
    write_to_log_file (_sphinx_msg);       
    fclose (output_file);

    free_data_list (&liste, STATIC);
  }

  return SUCCESS;
}

extern int	min_node;
extern int	max_node;

/*
   @FUN:
   @DOES: finds nodes with minimum/maximum latency
   @PARAMETERS: am measurement with the p2p pattern.
   @RETURNS: TRUE in case of success
   @SIDEEFFECTS: modifies min_node, max_node, ms->data.p2p_data.max_node and
   ms->data.p2p_data.min_node; calls measure_p2p_latencies if necessary
   @ASSUMES: _sphinx_myid set
*/
int 
p2p_find_max_min (measurement_t *ms)
{
  int  retval;

  if ((p2p_latencies == NULL) || (p2p_latencies[0] == UNMEASURED)) {
    retval = measure_p2p_latencies (0);
    if (retval) return retval;
  }

  if (_sphinx_myid == 0) {        
    int world_size, i;
    double max_L, min_L;

    MPI_Comm_size (MPI_COMM_WORLD, &world_size);

    if (world_size > 1)
      max_L = min_L = p2p_latencies[1];

    max_node = min_node = 1;

    for (i = 2; i < world_size; i++) {
      if (p2p_latencies[i] < min_L) {
	min_L = p2p_latencies[i];
	min_node = i;
      }
      else if (p2p_latencies[i] > max_L) {
	max_L = p2p_latencies[i];
	max_node = i;
      }
    }
  }

  /* probably should use MPI_COMM_WORLD here... */
#ifndef NO_BCAST
  MPI_Bcast (&max_node, 1, MPI_INT, 0, ms->data.p2p_data.communicator);
  MPI_Bcast (&min_node, 1, MPI_INT, 0, ms->data.p2p_data.communicator);

  ms->data.p2p_data.max_node = max_node;
  ms->data.p2p_data.min_node = min_node;
#endif

  D1(fprintf (stderr, "client %d: after Bcast\n", _sphinx_myid);)
  
  return SUCCESS;
}

/*
   @FUN:
   @DOES: the p2p pattern.
   @PARAMETERS: th actual measurement (which sould be one of the 
   p2p pattern).
   @RETURNES: TRUE in case of success.
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
int 
p2p_pattern (measurement_t *ms, int n)
{
  int 
    _p2p_myid,
    numprocs,
    i,
    arg;

  double 
    start_time,
    end_time = 0,
    org_time,
    tbm_time;

  MPI_Comm_size (ms->data.p2p_data.communicator,&numprocs);
  MPI_Comm_rank (ms->data.p2p_data.communicator,&_p2p_myid);

  overlap_cap = ms->overlap_iters;
  second_overlap_cap = ms->second_overlap_iters;

  if (_p2p_myid == 0)
  {  
    switch (ms->dimensions[n].variation) {
    case LENGTH:
      arg = ms->data.p2p_data.len;
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
      arg = ms->data.p2p_data.iters;
      break;
    case OVERLAP:
      arg = ms->overlap_iters;
      break;
    case SECOND_OVERLAP:
      arg = ms->second_overlap_iters;
      break;
    case NO_VARIATION:
      arg = NO_VARIATION_ARG_VALUE;
      break;
    default:
      ERROR(USER,"invalid variation occured in p2p_pattern");
      return GENERIC_ERROR;
    }

    if (ms->data.p2p_data.which_to_measure == MEASURE_MAX)
    {
      /* measurements for max_node */
      D(fprintf (stderr, "server %d: starting max meas.\n", _p2p_myid);)

      if (CACHE_WARMUP > 0)
      {
	/* cache warmups, not measured */
	am_init(CACHE_WARMUP, ms->pattern_in_omp_parallel);
	do
	{
	  D(fprintf (stderr, "server %d: sending to proc. %d for cache.\n", 
		     _p2p_myid,ms->data.p2p_data.max_node);)
	    
	  org_time = (start_time = MPI_Wtime()) - end_time;
	  /* measure */
	  ms->data.p2p_data.server_op (ms->data.p2p_data.len, 
				       ms->data.p2p_data.max_node, 
				       ms->data.p2p_data.communicator);
	  
	  end_time = MPI_Wtime();
	  tbm_time = end_time - start_time;
	}while (am_control_end(ms, CACHE_WARMUP, tbm_time, org_time,
			       ms->data.p2p_data.max_node, 
			       MPI_COMM_NULL, 0, TRUE));
	am_free(ms->pattern_in_omp_parallel);
      }
      /* and now for real ! */
      am_init(ms->max_rep, ms->pattern_in_omp_parallel);
      do
      {
	D(fprintf (stderr, "server %d: sending to proc. %d for real.\n", 
		   _p2p_myid,ms->data.p2p_data.max_node);)

	org_time = (start_time = MPI_Wtime()) - end_time;
	/* measure */
	/* Quick and dirty change; really should loop in routine_to_measure */
        for (i = 0; i < ms->data.p2p_data.iters; i++)
	  ms->data.p2p_data.server_op (ms->data.p2p_data.len, 
				       ms->data.p2p_data.max_node, 
				       ms->data.p2p_data.communicator);
	
	end_time = MPI_Wtime();
	tbm_time = end_time - start_time;
      }while (am_control_end(ms, arg, tbm_time, org_time,
			     ms->data.p2p_data.max_node, 
			     MPI_COMM_NULL, 0, FALSE));
      
      am_fill_data (ms, ms->data.p2p_data.len, 
		    ms->data.p2p_data.result, ms->data.p2p_data.iters);
      am_free(ms->pattern_in_omp_parallel);
    }
    else  /* measure min node */
    {
      /* measurements for min_node */
      D(fprintf (stderr, "server %d: starting min measurement\n", _p2p_myid);)
      if (CACHE_WARMUP > 0)
      {
	/* cache warmups, not measured */
	am_init(CACHE_WARMUP, ms->pattern_in_omp_parallel);
	do
	{
	  org_time = (start_time = MPI_Wtime()) - end_time;
	  /* measure */
	  ms->data.p2p_data.server_op (ms->data.p2p_data.len, 
				       ms->data.p2p_data.min_node, 
				       ms->data.p2p_data.communicator);
	  
	  end_time = MPI_Wtime();
	  tbm_time = end_time - start_time;
	}while (am_control_end(ms, CACHE_WARMUP, tbm_time, org_time,
			       ms->data.p2p_data.min_node, 
			       MPI_COMM_NULL, 0, TRUE));
	am_free(ms->pattern_in_omp_parallel);
      }
      /* and now for real ! */
      am_init(ms->max_rep, ms->pattern_in_omp_parallel);
      do
      {
	org_time = (start_time = MPI_Wtime()) - end_time;
	/* measure */
	/* BRONIS */
	/* Quick and dirty change; really should do loop in routine_to_measure */
        for (i = 0; i < ms->data.p2p_data.iters; i++)
        /* END BRONIS */
	  ms->data.p2p_data.server_op (ms->data.p2p_data.len, 
				       ms->data.p2p_data.min_node, 
				       ms->data.p2p_data.communicator);
	
	end_time = MPI_Wtime();
	tbm_time = end_time - start_time;
      }while (am_control_end(ms, arg, tbm_time, org_time,
			     ms->data.p2p_data.min_node, 
			     MPI_COMM_NULL, 0, FALSE));
      
      am_fill_data (ms, ms->data.p2p_data.len, 
		    ms->data.p2p_data.result, ms->data.p2p_data.iters);
      am_free(ms->pattern_in_omp_parallel);   
    }
  }
  else /* so I am not process 0 */
  {
    D(fprintf (stderr, "client %d:which_to_measure %d\n"\
	       "max_node %d, min_node %d\n"\
	       "cond: %d\n", _p2p_myid,
	       ms->data.p2p_data.which_to_measure,
	       ms->data.p2p_data.max_node,
	       ms->data.p2p_data.min_node,
	       ((ms->data.p2p_data.which_to_measure == MEASURE_MAX &&
		_p2p_myid == ms->data.p2p_data.max_node) 
	       || (ms->data.p2p_data.which_to_measure == MEASURE_MIN &&
		   _p2p_myid == ms->data.p2p_data.min_node)));)

    if ((ms->data.p2p_data.which_to_measure == MEASURE_MAX &&
	 _p2p_myid == ms->data.p2p_data.max_node) 
       || (ms->data.p2p_data.which_to_measure == MEASURE_MIN &&
	   _p2p_myid == ms->data.p2p_data.min_node))
    {
      if (CACHE_WARMUP > 0)
      {
	/* for cache */
	do
	{
	  D(fprintf (stderr, "client %d: receiving from server for cache.\n", 
		     _p2p_myid);)
	    
	  ms->data.p2p_data.client_op (ms->data.p2p_data.len, 0, 
					 ms->data.p2p_data.communicator);
	}while (am_control_end(ms, 0, 0.0, 0.0, 0, MPI_COMM_NULL, 0, TRUE));
      }
      /* for real */
      do
      {
	D(fprintf (stderr, "client %d: receiving from server for real"\
		   "with len %d.\n", _p2p_myid,ms->data.p2p_data.len );)
	  
	/* BRONIS */
	/* Quick and dirty change; really should do loop in routine_to_measure */
        for (i = 0; i < ms->data.p2p_data.iters; i++)
        /* END BRONIS */
	  ms->data.p2p_data.client_op (ms->data.p2p_data.len, 0, 
				       ms->data.p2p_data.communicator);
      }while (am_control_end(ms, 0, 0.0, 0.0, 0, MPI_COMM_NULL, 0, FALSE));
    } /* if involved */
  }   /* if proc 0 */
  return 0;
}

