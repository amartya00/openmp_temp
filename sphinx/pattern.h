/*
$Log: pattern.h,v $
Revision 1.8  2000/08/25 23:17:16  bronis
Added OpenMP tests

Revision 1.7  1999/10/01 21:36:52  bronis
Added debugged Root variation

Revision 1.6  1999/09/29 00:23:48  bronis
removed most restrictions on ACKER variation

Revision 1.5  1999/09/23 17:08:44  bronis
cleaned up multi dim stuff

Revision 1.4  1999/09/21 15:59:50  bronis
Added make unmeasured; fixed call_*_prologue bug

Revision 1.3  1999/09/16 23:26:02  bronis
fixed fill_dummy_values calls

Revision 1.2  1999/09/14 16:38:51  srtaylor
First cut at multiple dimensions

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

int measure_gaps (measurement_t *ms);
int col_pattern (measurement_t *ms, int n);

int mw_pattern (measurement_t *ms, int n);

int measure_p2p_latencies (int source);
int p2p_find_max_min (measurement_t *ms);
int p2p_pattern (measurement_t *ms, int n);

int simple_pattern (measurement_t *ms, int n);
int thread_chain_pattern (measurement_t *ms, int n);
int multitiming_pattern (measurement_t *ms, int n);

