/*
$Log: autodist.h,v $
Revision 1.7  2000/01/10 21:50:23  bronis
Added full blown aux tests implementation

Revision 1.6  1999/09/29 00:23:47  bronis
removed most restrictions on ACKER variation

Revision 1.5  1999/09/20 19:00:37  srtaylor
Merged measure and measure_suite

Revision 1.4  1999/09/16 16:17:50  bronis
incremental multi dim changes

Revision 1.3  1999/09/15 15:50:57  srtaylor
Structure modifications - Does not currently compile

Revision 1.2  1999/09/14 16:38:50  srtaylor
First cut at multiple dimensions

Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: autodist.h,v 1.7 2000/01/10 21:50:23 bronis Exp $ */

int measure (measurement_t *ms, int n);
int do_aux_tests (measurement_t *ms, int the_arg, int n, int nop);
int use_aux_tests (measurement_t *ms, int the_arg, int n);
int need_to_do_aux_tests (measurement_t *ms, int the_arg, int n);

