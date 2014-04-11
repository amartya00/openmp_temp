module Navigator{

typedef void (*Nav_Ptr)(UArg, UArg);

void init_Navigator();

Ptr queue_pop_elem(UInt32 Hnd);

Ptr queue_pop_elem_wait(UInt32 Hnd);

UInt32 Queue_get_num_elem(UInt32 Hnd);

void queue_push_elem(UInt32 Hnd,UInt32 elem); 


void Barrier_wait(volatile UInt32 total,volatile UInt32 Hnd);
void Queue_Barrier_wait(UInt32 *bar);

void wait_for_release(UInt32 *bar);

void wait_threads_release(UInt32 *bar);

void Close_Queue(UInt32 Hnd);

void sysExit ();

UInt32 Create_Queue();

}