/*
$Log: sphinx_call.h,v $
Revision 1.14  2000/08/25 23:17:17  bronis
Added OpenMP tests

Revision 1.13  2000/02/17 14:18:58  bronis
added first real non-blocking tests

Revision 1.12  2000/01/18 18:42:11  bronis
Added MPI_Comm_free calls

Revision 1.11  2000/01/10 21:50:24  bronis
Added full blown aux tests implementation

Revision 1.10  1999/09/29 16:10:41  bronis
First cut at ROOT variation

Revision 1.9  1999/09/29 00:23:48  bronis
removed most restrictions on ACKER variation

Revision 1.8  1999/09/23 17:08:44  bronis
cleaned up multi dim stuff

Revision 1.7  1999/09/21 15:59:51  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.6  1999/09/20 19:00:39  srtaylor
Merged measure and measure_suite

Revision 1.5  1999/09/17 23:03:01  bronis
Split BINDING variation

Revision 1.4  1999/09/16 23:26:02  bronis
fixed fill_dummy_values calls

Revision 1.3  1999/09/15 15:50:57  srtaylor
Structure modifications - Does not currently compile

Revision 1.2  1999/09/14 16:38:51  srtaylor
First cut at multiple dimensions

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: sphinx_call.h,v 1.14 2000/08/25 23:17:17 bronis Exp $ */

int call_variation_prologue(measurement_t *ms, int the_arg, int n, int dp_num);
int call_length_prologue (measurement_t *ms, int length, int n);
int call_nodes_prologue (measurement_t *ms, int nodes, int n);
int call_create_communicator (measurement_t *ms, int nodes, int n);
int call_destroy_communicator (measurement_t *ms, int nodes, int n);
int call_chunks_prologue (measurement_t *ms, int chunks, int n);
int call_p2p_prologue (measurement_t *ms, int n);
int call_mw_prologue (measurement_t *ms, int n);
int call_col_prologue (measurement_t *ms, int n);
int call_simple_prologue (measurement_t *ms, int n);
int call_multitiming_prologue (measurement_t *ms, int n);
int call_master_binding_prologue (measurement_t *ms, int master_cpu,int n);
int call_slave_binding_prologue (measurement_t *ms, int slave_cpu,int n);
int call_ACKer_prologue (measurement_t *ms, int ACKer, int n);
int call_root_prologue (measurement_t *ms, int root, int n);
int call_iters_prologue (measurement_t *ms, int iters, int n);
int call_overlap_prologue (measurement_t *ms, int cap, int n);
int call_second_overlap_prologue (measurement_t *ms, int cap, int n);
int call_threads_prologue (measurement_t *ms, int num_threads, int n);
int call_work_amount_prologue (measurement_t *ms, int work_amt, int n);
int call_work_function_prologue (measurement_t *ms, int work_f, int n);
int call_overlap_function_prologue (measurement_t *ms, int work_f, int n);
int call_sched_cap_prologue (measurement_t *ms, int cap, int n);
int call_sched_chunks_prologue (measurement_t *ms, int chunks, int n);
int call_schedule_prologue (measurement_t *ms, int sched, int n);









