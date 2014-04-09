/*
$Log: automeasure.h,v $
Revision 1.4  2000/08/25 23:17:16  bronis
Added OpenMP tests

Revision 1.3  2000/01/10 21:50:23  bronis
Added full blown aux tests implementation

Revision 1.2  1999/10/01 21:36:52  bronis
Added debugged Root variation

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: automeasure.h,v 1.4 2000/08/25 23:17:16 bronis Exp $ */

int  am_init        (int size, int in_omp_parallel);
int  am_control_end (measurement_t *ms, int arg, double time, double org_time,
		     int partner, MPI_Comm communicator, int server_id,
		     int cold_cache);
void am_fill_data   (measurement_t *ms, int arg,
		     data_t *data, int num_iters_per_time);
void am_free        (int in_omp_parallel);

int  am_gap_init          (int size, int comm_size, int in_omp_parallel);
int  am_gap_control_end   (measurement_t *ms, int arg, double time, 
			   double org_time, MPI_Comm communicator,
			   int cold_cache);
double * am_gap_fill_data (measurement_t *ms, int num_iters_per_time);
void am_gap_free          (int in_omp_parallel);

int  am_multi_init        (int size, int timing_count, int in_omp_parallel);
int  am_multi_control_end (measurement_t *ms, int arg, double *time, 
			   double *org_time, int partner, MPI_Comm comm,
			   int cold_cache);
void am_multi_fill_data   (measurement_t *ms, int arg,
			   data_t *data, int num_iters_per_time);
void am_multi_free        (int in_omp_parallel);

