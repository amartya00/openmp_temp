/*
$Log: sphinx_threads.h,v $
Revision 1.4  2000/11/15 00:00:39  bronis
made changes to improve scalability

Revision 1.3  2000/09/15 00:05:00  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.2  2000/08/25 23:17:19  bronis
Added OpenMP tests

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* Macros used for binding threads to processors and */
/* retrieving other relevant system info for threads benchmarks... */

/* Coded by John May; file created by Bronis de Supinski... */


/* Note about BIND: althouth I've tried to hide the differences
 * between the interfaces, BIND will work differently on different
 * systems.  In particular, the inheritance of bindings will differ.
 * To guarantee that threads land on the same or different CPUs,
 * it's necessary to bind each thread explicitly, as we do here.
 * Even then, I don't know how this will work for more than two
 * threads.
 */

/* Skampi mods rely on this exact value for UNBIND */
#define UNBIND (-1)

#if defined(SUN)
#include <sys/types.h>
#include <sys/processor.h>
#include <sys/procset.h>
#include <unistd.h>
#include <thread.h>
#define ONLINE _SC_NPROCESSORS_ONLN
#define CONFIGURED _SC_NPROCESSORS_CONF
#define GETMAXPROCS(a) (sysconf(a))

/* Sun processors are not numbered consecutively.  We have to look
 * up how many there are and then fill in an array to match a
 * sequence of integers to the actual processor numbers.
 * The function is designed to build the array and return an element
 * so it can be used in a conditional expression to check whether
 * the array is initialized yet.
 */
#define MAXPNUM 999999	/* An arbitrary limit to bound the search */
processorid_t * sunprocnums;
processorid_t initsunprocnums( int procindex );
			
#define BIND(processor) (processor_bind(P_LWPID, P_MYID, \
	((processor==UNBIND) ? PBIND_NONE : \
	((sunprocnums) ? sunprocnums[processor] : initsunprocnums(processor))),\
	NULL))

int getsuncpu( void );
#define GETCPU() (getsuncpu())
/* end SUN */

#elif defined(DEC)
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/resource.h>
#include <unistd.h>
#define ONLINE _SC_NPROCESSORS_ONLN
#define CONFIGURED _SC_NPROCESSORS_CONF
#define GETMAXPROCS(a) (sysconf(a))
#define BIND(processor) \
	(bind_to_cpu(getpid(), ((processor==UNBIND)?0:(1<<processor)), \
	BIND_NO_INHERIT))
long cpu_num;
#define GETCPU() (getsysinfo(GSI_CURRENT_CPU, (caddr_t) &cpu_num, sizeof(long), 0L, 0L, 0L), cpu_num)
/* end DEC */

#elif defined(IBM)
#include <sys/processor.h>
#include <unistd.h>
#define ONLINE _SC_NPROCESSORS_ONLN
#define CONFIGURED _SC_NPROCESSORS_CONF
#define GETMAXPROCS(a) (sysconf(a))
#define BIND(processor) (bindprocessor(BINDTHREAD,thread_self(), \
	((processor==UNBIND)?PROCESSOR_CLASS_ANY:processor)))
#define GETCPU() (mycpu())
/* end IBM */

#elif defined(SGI)
#include <sys/types.h>
#include <sys/sysmp.h>
#include <unistd.h>
#define ONLINE _SC_NPROC_ONLN
#define CONFIGURED _SC_NPROC_CONF
#define GETMAXPROCS(a) (sysconf(a))
/* Assuming that sysmp will ignore the processor arg when RUNANYWHERE is used */
#define BIND(processor) \
	( sysmp(((processor==UNBIND)?MP_RUNANYWHERE:MP_MUSTRUN), processor) )
#define GETCPU() (sysmp(MP_GETMUSTRUN))
/* end SGI */

#elif defined(LINUX)
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/resource.h>
#include <unistd.h>
#define ONLINE _SC_NPROCESSORS_ONLN
#define CONFIGURED _SC_NPROCESSORS_CONF
#define GETMAXPROCS(a) (sysconf(a))
/* Don't know the bind call if it exists; for now use this... */
#define BIND(processor) 0
long cpu_num;
#define GETCPU() (getsysinfo(GSI_CURRENT_CPU, &cpu_num, 0L, 0L, 0L), cpu_num)
/* end LINUX */

#endif

