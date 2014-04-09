
int get_which_work (measurement_t *ms);
int get_work_param (measurement_t *ms);
int get_thread_count (measurement_t *ms);
int get_sched_cap (measurement_t *ms);
int get_schedule_chunks (measurement_t *ms);
int get_loop_schedule (measurement_t *ms);

int set_up_omp_parameters (measurement_t *ms);

int simple_work (int work_size);
int bors_work (int work_size);
int spin_timed_work (int work_size);
int sleep_timed_work (int work_size);


#ifdef _HAVE_OMP_

void simple_init_omp_parallel_ref (measurement_t *ms);
void simple_init_omp_parallel (measurement_t *ms);
void simple_init_omp_parallel_for_ref (measurement_t *ms);
void simple_init_omp_parallel_for (measurement_t *ms);
void simple_init_omp_parallel_for_chunks (measurement_t * ms);
void thread_chain_init_omp_ordered_ref (measurement_t * ms);
void thread_chain_init_omp_ordered_only (measurement_t * ms);
void thread_chain_init_omp_ordered (measurement_t * ms);
void thread_chain_init_omp_single_ref (measurement_t * ms);
void thread_chain_init_omp_single (measurement_t * ms);
void thread_chain_init_omp_barrier (measurement_t * ms);
void simple_init_omp_reduction_ref (measurement_t *ms);
void simple_init_omp_reduction (measurement_t *ms);
void simple_init_omp_atomic_ref (measurement_t *ms);
void thread_chain_init_omp_atomic (measurement_t * ms);
void col_init_mixed_omp_mpi_barrier (measurement_t * ms);
void col_init_mixed_omp_mpi_barrier_only (measurement_t * ms);
void col_init_mixed_omp_mpi_allreduce (measurement_t * ms);
void col_init_mixed_omp_mpi_allreduce_only (measurement_t * ms);
void col_init_mixed_omp_mpi_allreduce_barrier_only (measurement_t * ms);
void p2p_init_omp_overlap (measurement_t *ms);
void p2p_init_Isend_Recv_omp_overlap (measurement_t *ms);
void p2p_init_Isend_Recv_both_omp_overlaps (measurement_t *ms);
void p2p_init_Irecv_Send_omp_overlap (measurement_t *ms);

#endif /* _HAVE_OMP_ */
