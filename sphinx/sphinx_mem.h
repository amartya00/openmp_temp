/*
$Log: sphinx_mem.h,v $
Revision 1.2  1999/09/20 19:00:40  srtaylor
Merged measure and measure_suite

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: sphinx_mem.h,v 1.2 1999/09/20 19:00:40 srtaylor Exp $ */
/* SKaMPI Special Karlsruher MPI-Benchmark
   -memory management-
   -header-

   R. Reussner, 07.02.1997

   last change:       
     . 03.03.98 changed all variables concerning the buffer length from int to long int. 
       (due to problems on the alpha architecture) RR

*/


int allocate_mem (int memsize);
void free_mem (void);

long int mem_init_one_buffer (int nor, int nom, int nop, measurement_t *ms);
long int mem_init_two_buffers (int nor, int nom, int nop, measurement_t *ms);
long int mem_init_two_buffers_attach (int nor, int nom, int nop, measurement_t *ms);
long int mem_init_two_buffers_attach_p2p (int nor, int nom, int nop, measurement_t *ms);
long int mem_init_two_buffers_attach_mw (int nor, int nom, int nop, measurement_t *ms);
long int mem_init_two_buffers_alltoall (int nor, int nom, int nop, measurement_t *ms);

void mem_release (measurement_t *ms);
void mem_release_detach (measurement_t *ms);

long int mem_init_mw_Waitsome (int nor, int nom, int nop, measurement_t *ms);
long int mem_init_mw_Waitany (int nor, int nom, int nop, measurement_t *ms);







