/*
$Log: col_test1.h,v $
Revision 1.4  2000/12/14 00:26:52  bronis
Added improved scan test and scalable tests for fan out collectives

Revision 1.3  2000/01/10 21:50:23  bronis
Added full blown aux tests implementation

Revision 1.2  1999/09/29 00:23:47  bronis
removed most restrictions on ACKER variation

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: col_test1.h,v 1.4 2000/12/14 00:26:52 bronis Exp $ */

void col_init_dummy                (measurement_t *ms);
void col_init_over_nodes_dummy     (measurement_t *ms);
void col_init_Bcast                (measurement_t *ms);
void col_init_Barrier              (measurement_t *ms);
void col_init_Reduce               (measurement_t *ms);
void col_init_Alltoall             (measurement_t *ms);
void col_init_Scan                 (measurement_t *ms);
void col_init_Comm_dup             (measurement_t *ms);
void col_init_Comm_split           (measurement_t *ms);
void col_init_memcpy               (measurement_t *ms);

void col_init_Barrier_barrier      (measurement_t *ms);
void col_init_Reduce_scale         (measurement_t *ms);
void col_init_Reduce_upper_bound   (measurement_t *ms);
void col_init_Scan_send_latency    (measurement_t *ms);
void col_init_Scan_with_Acker      (measurement_t *ms);
void col_init_Gather_scale         (measurement_t *ms);
void col_init_Gather               (measurement_t *ms);
void col_init_Gather_upper_bound   (measurement_t *ms);
void col_init_Scatter_scale        (measurement_t *ms);
void col_init_Scatter              (measurement_t *ms);
void col_init_Scatter_with_ACKer   (measurement_t *ms);
void col_init_Allgather            (measurement_t *ms);
void col_init_Allgather_barrier    (measurement_t *ms);
void col_init_Allreduce            (measurement_t *ms);
void col_init_Allreduce_barrier    (measurement_t *ms);
void col_init_Gatherv_scale        (measurement_t *ms);
void col_init_Gatherv              (measurement_t *ms);
void col_init_Gatherv_upper_bound  (measurement_t *ms);
void col_init_Scatterv_scale       (measurement_t *ms);
void col_init_Scatterv             (measurement_t *ms);
void col_init_Scatterv_with_ACKer  (measurement_t *ms);
void col_init_Allgatherv           (measurement_t *ms);
void col_init_Allgatherv_barrier   (measurement_t *ms);
void col_init_Alltoallv            (measurement_t *ms);
void col_init_Alltoallv_barrier    (measurement_t *ms);
void col_init_Reduce_scatter       (measurement_t *ms);
void col_init_Red_scatter_barrier  (measurement_t *ms);
void col_init_Bcast_barrier        (measurement_t *ms);
void col_init_Bcast_send_latency   (measurement_t *ms);
void col_init_Bcast_round          (measurement_t *ms);
void col_init_Bcast_with_acks      (measurement_t *ms);
void col_init_Bcast_with_ACKer     (measurement_t *ms);
void col_init_Alltoall_barrier     (measurement_t *ms);




