/*
$Log: yieldtest.c,v $
Revision 1.6  2000/11/15 00:00:39  bronis
made changes to improve scalability

Revision 1.5  2000/09/15 00:05:01  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.4  2000/08/25 23:17:19  bronis
Added OpenMP tests

Revision 1.3  2000/03/16 15:48:42  bronis
fixed mpguidec warnings

Revision 1.2  1999/07/09 22:11:45  srtaylor
Remove debug output

Revision 1.1.1.1  1999/05/11 16:50:03  srtaylor
CVS repository setup for sphinx

*/

#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sphinx_threads.h"



#define TODOUBLE( ts ) ((double)(ts.tv_sec + 1e-9 * ts.tv_nsec))
#define DIFFTIMES(t1,t2) (TODOUBLE(t1) - TODOUBLE(t2))

#define WHICH_CPU       1
#define NUM_THREADS	2
#define NUM_TIMES	100


struct thread_data
{
   int	              thread_id;
   int                my_turn_num[NUM_TIMES];
};

pthread_t           threads[NUM_THREADS - 1];
struct thread_data  thread_data_array[NUM_THREADS];
int                 cur_t = 0;
pthread_cond_t      condition[NUM_THREADS - 1];
pthread_mutex_t     mutex[NUM_THREADS - 1];
pthread_attr_t      attr;
int                 ready[NUM_THREADS-1];

void *Get_times(void *threadarg)
{
   int                 taskid, i, child, rc;
   struct thread_data  *my_data;

   my_data = (struct thread_data *) threadarg;
   taskid = my_data->thread_id;

   printf ("Thread %d starting\n", taskid);

   rc = BIND (WHICH_CPU);

   if (rc) {
     printf( "Client error from BIND is %d, errno is %d\n",
	     rc, errno );
     perror( "client" );
   }

   printf ("Thread %d running on CPU %d\n", taskid, GETCPU());

   if ((child = taskid - 1) >= 0) {
     pthread_mutex_init( &mutex[child], NULL );
     pthread_cond_init( &condition[child], NULL );

     pthread_mutex_lock( &mutex[child] );

     ready[child] = 0;

     thread_data_array[child].thread_id = child;
     printf("Creating thread %d\n", child);
     rc = pthread_create(&threads[child], &attr, Get_times, 
			              (void *) &thread_data_array[child]);
     if (rc) {
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
     }

     /* Wait until my turn to start */
     while( !ready[child] ) {
       pthread_cond_wait( &condition[child], &mutex[child] );
     }
   }

   /* It's my turn to start; we assume all of this is fast enough */
   /* that fact all threads are bound to same CPU guarantees atomicity... */

   if (taskid < NUM_THREADS - 1) {
     /* first signal parent that I'm up and starting... */
     pthread_mutex_lock( &mutex[taskid] );
     pthread_cond_signal( &condition[taskid] );
     ready[taskid] = 1;

     /* give up lock so parent can receive signal... */
     pthread_mutex_unlock( &mutex[taskid] );
   }

   /* start yielding and recording... */
   for (i = 0; i < NUM_TIMES; i++) {
     /* Give up the CPU... */
#ifdef SUN
     thr_yield();
#else
     sched_yield();
#endif

     /* Record that I'm running "again" */
     my_data->my_turn_num[i] = cur_t++;
   }

   printf ("Thread %d running on CPU %d\n", taskid, GETCPU());

   /* We're done; let's clean up... */
   if (taskid == 0)
     pthread_exit(NULL);

   pthread_mutex_unlock( &mutex[child] );
    
   pthread_mutex_destroy( &mutex[child] );
   pthread_cond_destroy( &condition[child] );
      
   if (taskid == NUM_THREADS - 1)
     return NULL;

   pthread_exit(NULL);

   /* required for SGI */
   return (NULL);
}

int main()
{
   int                 t, i;
   int                 this_turn, last_turn;
   int                 turn_error = 0;
   struct thread_data  *cur_data;

   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
   /*   pthread_attr_setschedpolicy(&attr, SCHED_RR); */
   /*   pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM); */

   thread_data_array[NUM_THREADS - 1].thread_id = NUM_THREADS - 1;
   printf("Starting thread %d\n", NUM_THREADS - 1);

   /* really should be able to use initial thread, but... */
   Get_times ((void *) &thread_data_array[NUM_THREADS - 1]);

   /* this is unlikely to be necessary, but just to be sure, */
   /* ensure all threads are done (except maybe for some cleanup)... */
   while (cur_t < NUM_THREADS * NUM_TIMES) /* NULL */;

   /* Free attribute and wait for the other threads */
   pthread_attr_destroy(&attr);

   printf("Checking results\n");

   /* expected result is each thread's turns are separated by NUM_THREAD */
   /* turns; also expect first turn to be equal to taskid... */
   for (t = 0; t < NUM_THREADS; t++) {
     cur_data = &thread_data_array[t];

     last_turn = cur_data->my_turn_num[0];

     if (last_turn != t) {
       printf ("START UP ERROR: thread %d; first turn: %d\n", t, last_turn);
     }
     
     for (i = 1; i < NUM_TIMES; i++) {
       this_turn = cur_data->my_turn_num[i];

       if (this_turn != last_turn + NUM_THREADS) {
         printf ("TURN ERROR: thread: %d; time: %d; turn: %d; last turn: %d\n",
		 t, i, this_turn, last_turn);
	 turn_error = 1;
       }

       last_turn = this_turn;
     }
   }

   if (!turn_error) {
     printf ("Processor yielded as expected\n");
   }

   return turn_error;
}
