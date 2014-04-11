/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to 1 if the target assembler supports .symver directive. */
#undef HAVE_AS_SYMVER_DIRECTIVE

/* Define to 1 if the target supports __attribute__((alias(...))). */
#undef HAVE_ATTRIBUTE_ALIAS

/* Define to 1 if the target supports __attribute__((dllexport)). */
#undef HAVE_ATTRIBUTE_DLLEXPORT

/* Define to 1 if the target supports __attribute__((visibility(...))). */
#undef HAVE_ATTRIBUTE_VISIBILITY

/* Define if the POSIX Semaphores do not work on your system. */
#undef HAVE_BROKEN_POSIX_SEMAPHORES

/* Define to 1 if the target assembler supports thread-local storage. */
#undef HAVE_CC_TLS

/* Define to 1 if you have the `clock_gettime' function. */
#undef HAVE_CLOCK_GETTIME

/* Define to 1 if you have the <dlfcn.h> header file. */
#undef HAVE_DLFCN_H

/* Define to 1 if you have the `getloadavg' function. */
#undef HAVE_GETLOADAVG

/* Define to 1 if you have the <inttypes.h> header file. */
#undef HAVE_INTTYPES_H

/* Define to 1 if you have the <memory.h> header file. */
#undef HAVE_MEMORY_H

/* Define if pthread_{,attr_}{g,s}etaffinity_np is supported. */
#undef HAVE_PTHREAD_AFFINITY_NP

/* Define to 1 if you have the <semaphore.h> header file. */
#undef HAVE_SEMAPHORE_H

/* Define to 1 if you have the <stdint.h> header file. */
#undef HAVE_STDINT_H

/* Define to 1 if you have the <stdlib.h> header file. */
#undef HAVE_STDLIB_H

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H

/* Define to 1 if you have the `strtoull' function. */
#undef HAVE_STRTOULL

/* Define to 1 if the target supports __sync_*_compare_and_swap */
#undef HAVE_SYNC_BUILTINS

/* Define to 1 if you have the <sys/loadavg.h> header file. */
#undef HAVE_SYS_LOADAVG_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#undef HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/time.h> header file. */
#undef HAVE_SYS_TIME_H

/* Define to 1 if you have the <sys/types.h> header file. */
#undef HAVE_SYS_TYPES_H

/* Define to 1 if the target supports thread-local storage. */
#undef HAVE_TLS

/* Define to 1 if you have the <unistd.h> header file. */
#undef HAVE_UNISTD_H

/* Define to 1 if GNU symbol versioning is used for libgomp. */
#undef LIBGOMP_GNU_SYMBOL_VERSIONING

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#undef LT_OBJDIR

/* Name of package */
#undef PACKAGE

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#undef PACKAGE_NAME

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the home page for this package. */
#undef PACKAGE_URL

/* Define to the version of this package. */
#undef PACKAGE_VERSION

/* The size of `char', as computed by sizeof. */
#undef SIZEOF_CHAR

/* The size of `int', as computed by sizeof. */
#undef SIZEOF_INT

/* The size of `long', as computed by sizeof. */
#undef SIZEOF_LONG

/* The size of `short', as computed by sizeof. */
#undef SIZEOF_SHORT

/* The size of `void *', as computed by sizeof. */
#undef SIZEOF_VOID_P

/* Define to 1 if you have the ANSI C header files. */
#undef STDC_HEADERS

/* Define if you can safely include both <string.h> and <strings.h>. */
#undef STRING_WITH_STRINGS

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#undef TIME_WITH_SYS_TIME

/* Version number of package */
#undef VERSION


#define OMP_LOCK_25_ALIGN 0
#define OMP_LOCK_25_KIND 8
#define OMP_LOCK_25_SIZE 8
#define OMP_LOCK_ALIGN 0
#define OMP_LOCK_KIND 8
#define OMP_LOCK_SIZE 8
#define OMP_NEST_LOCK_25_ALIGN 0
#define OMP_NEST_LOCK_25_KIND 16
#define OMP_NEST_LOCK_25_SIZE 16
#define OMP_NEST_LOCK_ALIGN 0
#define OMP_NEST_LOCK_KIND 16
#define OMP_NEST_LOCK_SIZE 16

/* If we're not using GNU C, elide __attribute__ */
#ifndef __GNUCS__
  #define  __attribute__(x)  /*NOTHING*/
  #define  __builtin_expect(x, y)       x
  #define  __alignof(x)                 0
  #define  __sync_synchronize()         asm(" nop")
  #define  strncasecmp(s1, s2, n)       strncmp(s1, s2, n)
#endif

#include <xdc/std.h>

typedef Bool bool;