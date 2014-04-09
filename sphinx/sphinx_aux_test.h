
/* NOTE: simple_inside_dummy is special since it depends on max_iters... */
typedef enum { SIMPLE_DUMMY = 0,
	       MW_DUMMY,
	       P2P_DUMMY,
	       COL_DUMMY,
	       DUMMY_COUNT } dummy_t;


#ifdef _HAVE_OMP_

typedef enum { OMP_PARALLEL_AUX = 0,
	       OMP_PARALLEL_FOR_AUX, 
	       OMP_ORDERED_AUX, 
	       OMP_SINGLE_AUX, /* etc. */ 
	       OMP_REDUCTION_AUX, 
	       OMP_ATOMIC_AUX, 
	       OMP_OVERLAP_AUX, 
	       OMP_AUX_COUNT } omp_aux_t;

#endif /* _HAVE_OMP_ */


void generic_destroy (void *the_ms);


void initialize_simple_aux (measurement_t *ms);
void initialize_mw_aux (measurement_t *ms);
void initialize_p2p_aux (measurement_t *ms);
void initialize_p2p_overlap_aux (measurement_t *ms);
void initialize_p2p_overlap_and_ack_aux (measurement_t *ms);
void initialize_p2p_both_overlaps_aux (measurement_t *ms);
void initialize_col_aux (measurement_t *ms);
void initialize_col_over_nodes_aux (measurement_t *ms);

void initialize_simple_inside_aux (measurement_t *ms);

void initialize_ACKer_aux (measurement_t *ms);


#ifdef _HAVE_OMP_

void initialize_omp_parallel_aux (measurement_t *ms);
void initialize_omp_parallel_for_aux (measurement_t *ms);
void initialize_omp_ordered_aux (measurement_t *ms);
void initialize_omp_single_aux (measurement_t *ms);
void initialize_omp_reduction_aux (measurement_t *ms);
void initialize_omp_atomic_aux (measurement_t *ms);
void initialize_p2p_omp_overlap_aux (measurement_t *ms);
void initialize_p2p_omp_overlap_and_ack_aux (measurement_t *ms);
void initialize_p2p_both_omp_overlaps_aux (measurement_t *ms);

#endif /* _HAVE_OMP_ */


int need_simple_dummy_test (void *ms, int the_arg, int n);
int need_mw_dummy_test (void *ms, int the_arg, int n);
int need_p2p_dummy_test (void *ms, int the_arg, int n);
int need_col_dummy_test (void *ms, int the_arg, int n);
int need_col_over_nodes_dummy_test (void *ms, int the_arg, int n);

int need_simple_inside_dummy_test (void *ms, int the_arg, int n);

int need_ACKer_latencies (void *ms, int the_arg, int n);
int need_p2p_ACK_latency (void *ms, int the_arg, int n);
int need_gaps (void *ms, int the_arg, int n);

int need_p2p_overlap_test (void *ms, int the_arg, int n);
int need_p2p_second_overlap_test (void *ms, int the_arg, int n);


#ifdef _HAVE_OMP_

int need_omp_parallel_ref_test (void *ms, int the_arg, int n);
int need_omp_parallel_for_ref_test (void *ms, int the_arg, int n);
int need_omp_ordered_ref_test (void *ms, int the_arg, int n);
int need_omp_single_ref_test (void *ms, int the_arg, int n);
int need_omp_reduction_ref_test (void *ms, int the_arg, int n);
int need_omp_atomic_ref_test (void *ms, int the_arg, int n);
int need_omp_overlap_ref_test (void *ms, int the_arg, int n);

#endif /* _HAVE_OMP_ */


int simple_dummy_test (void *ms, int the_arg, int n);
int mw_dummy_test (void *ms, int the_arg, int n);
int p2p_dummy_test (void *ms, int the_arg, int n);
int col_dummy_test (void *ms, int the_arg, int n);
int col_over_nodes_dummy_test (void *ms, int the_arg, int n);

int simple_inside_dummy_test (void *ms, int the_arg, int n);

int do_ACKer_latencies (void *ms, int the_arg, int n);
int do_p2p_ACK_latency (void *ms, int the_arg, int n);
int do_gaps (void *ms, int the_arg, int n);

int p2p_overlap_test (void *ms, int the_arg, int n);
int p2p_second_overlap_test (void *ms, int the_arg, int n);


#ifdef _HAVE_OMP_

int omp_parallel_ref_test (void *ms, int the_arg, int n);
int omp_parallel_for_ref_test (void *ms, int the_arg, int n);
int omp_ordered_ref_test (void *ms, int the_arg, int n);
int omp_single_ref_test (void *ms, int the_arg, int n);
int omp_reduction_ref_test (void *ms, int the_arg, int n);
int omp_atomic_ref_test (void *ms, int the_arg, int n);
int omp_overlap_ref_test (void *ms, int the_arg, int n);

#endif /* _HAVE_OMP_ */


int use_simple_dummy_test (void *ms, int the_arg, int n);
int use_mw_dummy_test (void *ms, int the_arg, int n);
int use_p2p_dummy_test (void *ms, int the_arg, int n);
int use_col_dummy_test (void *ms, int the_arg, int n);
int use_col_over_nodes_dummy_test (void *ms, int the_arg, int n);

int use_simple_inside_dummy_test (void *ms, int the_arg, int n);

int use_ACKer_latencies (void *ms, int the_arg, int n);
int use_p2p_ACK_latency (void *ms, int the_arg, int n);
int use_gaps (void *ms, int the_arg, int n);

int use_p2p_overlap_test (void *ms, int the_arg, int n);
int use_p2p_second_overlap_test (void *ms, int the_arg, int n);


#ifdef _HAVE_OMP_

int use_omp_parallel_ref_test (void *ms, int the_arg, int n);
int use_omp_parallel_for_ref_test (void *ms, int the_arg, int n);
int use_omp_ordered_ref_test (void *ms, int the_arg, int n);
int use_omp_single_ref_test (void *ms, int the_arg, int n);
int use_omp_reduction_ref_test (void *ms, int the_arg, int n);
int use_omp_atomic_ref_test (void *ms, int the_arg, int n);
int use_omp_overlap_ref_test (void *ms, int the_arg, int n);

#endif /* _HAVE_OMP_ */


void clean_up_aux_tests (void);












