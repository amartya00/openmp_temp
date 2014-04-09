/*
$Log: sphinx_error.c,v $
Revision 1.4  2000/09/15 00:05:00  bronis
Added assure makefiles and removed problems revealed by assure

Revision 1.3  1999/09/16 23:26:02  bronis
fixed fill_dummy_values calls

Revision 1.2  1999/09/16 16:17:50  bronis
incremental multi dim changes

Revision 1.1.1.1  1999/05/11 16:50:03  srtaylor
CVS repository setup for sphinx

*/

#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include "sphinx_error.h"

int sphinx_error=NO_ERROR;

char *error_text[] =
{
  "no error",
  "user",
  "not enough free memory",
  "error opening file",
  "error reading file",
  "error writing file",
  "internal error"
};


char *message = "";
char *user_message = "";
char pos_message[0x100];
char eht[0x200];

/*
   @FUN:
   @DOES: prints error message (in sphinx_error) to stderr and (only if 
   really_end == TRUE) aborts the running programm.
   @PARAMETERS:
   @RETURNES:
   @SIDEEFFECTS: none.
   @ASSUMES: nothing.
*/
void 
output_error (int really_end)
{
  if (really_end)
  {
    fprintf (stderr,"FATAL ERROR: %s: %s: %s\n", 
	     error_text[sphinx_error], message, user_message);
    fprintf (stderr,"Occured at %s\n", pos_message);

#ifndef NO_MPI
    MPI_Abort (MPI_COMM_WORLD,sphinx_error);
#endif
    exit (sphinx_error);       /* also closes files */
  }

  /* Not exiting; print semantically correct message... */
  fprintf (stderr,"NON-FATAL ERROR: %s: %s: %s\n", 
	     error_text[sphinx_error], message, user_message);
  fprintf (stderr,"Occured at %s\n", pos_message);
}

