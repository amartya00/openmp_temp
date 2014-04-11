/* Copyright (C) 2005, 2008, 2009 Free Software Foundation, Inc.
   Contributed by Jakub Jelinek <jakub@redhat.com>.

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

/* Copyright (C) 2011
   Texas Instruments, Inc.
   Modifications by Shreyas Prasad <shreyasp@ti.com>. 
   
   Changes from original:
   - This is a TI-specific implementation of the gomp lock APIs */ 
   
#include "proc.h"

typedef struct omp_lock_t {
    UInt key;
    Bool entered;
} omp_lock_t;

typedef struct { 
    omp_lock_t lock; 
    int count; 
    void *owner; 
} omp_nest_lock_t;

typedef omp_lock_t omp_lock_25_t;
typedef omp_nest_lock_t omp_nest_lock_25_t;
