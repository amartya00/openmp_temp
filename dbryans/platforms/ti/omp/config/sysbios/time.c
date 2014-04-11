/* Copyright (C) 2005, 2009 Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@redhat.com>.

   This file is part of the GNU OpenMP Library (libgomp).

   Libgomp is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

/* This file contains system specific timer routines.  It is expected that
   a system may well want to write special versions of each of these.
  */

#include <ti/omp/libgomp.h>
#include <ti/omp/utils/OpenMP.h>
#include <xdc/runtime/Types.h>

double
omp_get_wtime (void)
{
    return ((double)OpenMP_getTimerCount());
}

double
omp_get_wtick (void)
{
    Types_FreqHz freq;
    double wtick;
    
    OpenMP_getTimerFreq(&freq);
    wtick = (double)(1/((double)freq.lo));
    
    return wtick;
}

ialias (omp_get_wtime)
ialias (omp_get_wtick)
