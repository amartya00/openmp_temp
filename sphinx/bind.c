/*
$Log: bind.c,v $
Revision 1.3  2000/09/15 00:04:59  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.2  1999/08/10 20:51:04  bronis
Added priority chart

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include <stdio.h>
#include <stdlib.h>

#include "sphinx_threads.h"

#ifdef SUN

processorid_t initsunprocnums( int procindex )
{
	processor_info_t infop;
	int procs = GETMAXPROCS(ONLINE);
	int index;
	processorid_t pnum;

	sunprocnums = (processorid_t *)malloc(procs * sizeof(processorid_t));
	
	for( index = 0, pnum = 0; index < procs; index++ ) {
		int goodid;
		for( goodid = 0; !goodid && pnum < MAXPNUM; pnum++ ) {
			goodid = processor_info( pnum, &infop ) == 0
					&& infop.pi_state == P_ONLINE;
			if( goodid ) sunprocnums[index] = pnum;
		}
		if( pnum >= MAXPNUM ) {
			fprintf( stderr, "Error getting list of Sun CPUs: "
				"no valid ID below %d for proc %d of %d\n",
				MAXPNUM, index, procs - 1 );
			return UNBIND;
		}
/*		printf("sunprocnums[%d] = %d\n", index, sunprocnums[index] ); */
	}

	return sunprocnums[procindex];
}
			

/* Need a reverse-lookup for processor nubmers too.  I could have had
 * another array indexed by the Sun CPU number, but this is potentially
 * sparse, so I'll just search the forward-lookup array.
 */
int getsuncpu( void )
{
	int index, maxprocs = GETMAXPROCS(ONLINE);
	processorid_t cpu_num;
	

	/* Be sure the array has been initialize before we search it! */
	if( !sunprocnums ) initsunprocnums(0);

	processor_bind(P_LWPID, P_MYID, PBIND_QUERY, &cpu_num );
	if( cpu_num < 0 ) return cpu_num;	/* in case it's unbound... */

	for( index = 0; index < maxprocs; index++ ) {
		if( sunprocnums[index] == cpu_num ) break;
	}

	if( index >= maxprocs ) {
		fprintf( stderr,
			"Can't match Sun CPU number %d to sequence #\n",
			cpu_num );
		return UNBIND;
	}

	return index;
}


#endif
