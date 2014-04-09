/*
$Log: p2p_test1.h,v $
Revision 1.3  2000/02/17 14:18:58  bronis
added first real non-blocking tests

Revision 1.2  1999/09/29 00:23:47  bronis
removed most restrictions on ACKER variation

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: p2p_test1.h,v 1.3 2000/02/17 14:18:58 bronis Exp $ */
/* routines to be measured with the ping-pong-pattern
   
   R. Reussner, 09.12.1996

*/

void p2p_init_dummy                    (measurement_t *ms);
void p2p_init_Send_Recv                (measurement_t *ms);
void p2p_init_Send_Iprobe_Recv         (measurement_t *ms);
void p2p_init_Send_Irecv               (measurement_t *ms);
void p2p_init_Send_Recv_AT             (measurement_t *ms);
void p2p_init_Ssend_Recv               (measurement_t *ms);
void p2p_init_Isend_Recv               (measurement_t *ms);
void p2p_init_Bsend_Recv               (measurement_t *ms);
void p2p_init_Sendrecv                 (measurement_t *ms);
void p2p_init_Sendrecv_replace         (measurement_t *ms);

void p2p_init_overlap                  (measurement_t *ms);
void p2p_init_Isend_Recv_overlap       (measurement_t *ms);
void p2p_init_Isend_Recv_both_overlaps (measurement_t *ms);
void p2p_init_Irecv_Send_overlap       (measurement_t *ms);












