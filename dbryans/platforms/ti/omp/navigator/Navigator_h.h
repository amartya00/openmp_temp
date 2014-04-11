/*
 * Navigator.h
 *
 *  Created on: Jun 8, 2011
 *      Author: Wajdi Darmoul
 */

#ifndef Navigator_h_H_
#define Navigator_h_H_
/* FuncPtr */
typedef void (*Nav_Ptr)(UArg, UArg);

typedef void (*Thread_Ptr)(void *xdata);

void init_Navigator();
void sysExit ();
Ptr queue_pop_elem(Uint32 Hnd);
void queue_push_elem(Uint32 Hnd,Uint32 elem);
void Close_Queue(Uint32 Hnd);
Uint32 Create_Queue(void);
Ptr queue_pop_elem_wait(Uint32 Hnd);
Uint32 Queue_get_num_elem(Uint32 Hnd);
void queue_push_elem(Uint32 Hnd,Uint32 elem); 
void Barrier_wait(volatile Uint32 total,volatile Uint32 Hnd);
void Queue_wait_for_release(volatile Uint32 Hnd);
void Queue_release_threads(volatile Uint32 total,volatile Uint32 Hnd);
#endif /* Navigator_h_H_ */

