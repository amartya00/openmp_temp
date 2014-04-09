/*
$Log: pqtypes.h,v $
Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

/* $Id: pqtypes.h,v 1.1.1.1 1999/05/11 16:50:02 srtaylor Exp $ */

#ifndef PQTYPES
#define PQTYPES
typedef double PqKey;
typedef list_item_t *PqData;
#define PQINFINITY      (0x7fffffff)
#define PQMINUSINFINITY (-PQINFINITY)
#define PQKEY MPI_INT
#endif
#ifndef PQ
#define PQ
/* sequential priority queue 
 * implemented using a D-Heap
 * Priority queue entries consist of a user defined arthmetic type 
 * PqKey which is linearly ordered by >
 * and a user defined type 
 * PqData
 * which must be a scalar or a struct without internal pointers
 */
typedef struct {
  PqKey  key;
  PqData data;
} PqItem;

/* ----------------- begin private --------------------------------- */

typedef struct {
   int length;
   int maxLength;
   PqItem item[1]; /* >^ actual length will be maxLength */
} Pq;

#if 0
static PqItem pqDummyItem;
#endif
/* ------------------ end private ---------------------------------- */

/* iniatlize a sequential Priority queue which is able to
 * accept up to maxLength items
 */
Pq *pqInit(int maxLength);

/* find minimum item */
#define pqMax(this) (this->item[0])
#define pqMaxKey(this)  (pqMax(this).key)
#define pqMaxData(this) (pqMax(this).data)

/* delete minimum item */
void pqDeleteMax(Pq *this);

/* insert item */
void pqInsert(Pq *this, PqItem item);
#define pqInsert2(this, k, d)                   \
(  pqDummyItem.key  = (k),                      \
   pqDummyItem.data = (d),                      \
   pqInsert((this), pqDummyItem)                \
)

/* how many items are in this Pq? */ 
#define pqLength(this) ((this)->length)
#define pqMaxLength(this) ((this)->maxlength)

void pqClose(Pq *this);

#endif
