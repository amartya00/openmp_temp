/*
$Log: pqtypes.c,v $
Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
CVS repository setup for sphinx

*/

#include "sphinx.h"
#include "sphinx_any.h"
#include "pqtypes.h"

/* internal shorthands */
#define Length    (this->length)
#define MaxLength (this->maxLength)
#define Item(i)   (this->item[i])
#define Key(i)    (Item(i).key)
#define Parent(i) ((i-1) / 2)
#define Left(i)   ((i) * 2 + 1)
#define Right(i)  ((i) * 2 + 2)

#if 0
/********************* Debugging *************************************/
void pqPrint(Pq *this)
{  int i; 
   Pq temp[1000];
 
   memcpy(temp, this, pqLength(this) * sizeof(PqItem) + sizeof(Pq));
   while (pqLength(temp) != 0) {
      printf("%d ", pqMaxKey(temp));
      pqDeleteMax(temp);
   }
  
   printf("(");
   for (i = 0;  i < pqLength(this);  i++) {
      printf("%d ", Key(i));
   }
   printf(")");
}
/*********************************************************************/
#endif

/* iniatlize a sequential Priority queue which is able to
 * accept up to maxLength items
 */
Pq *pqInit(int maxLength)
{  
   /* BRONIS */
   /* Commented out the " - 1" */
   /* Array runs from 0 to maxLength - 1! need maxLength items! Duh! */
   /* Of course, they think that they already have one in Pq */
   /* But it breaks for some cases at maxLength... */
   /* Right way to do this is: Pq->PqItem a pointer that holds the */
   /* the malloc'ed storage. Argument in favor of this grungy way */
   /* involves possible cache effects that should be minimal... */
   Pq *this = malloc(sizeof(Pq) + (maxLength/* - 1*/) * sizeof(PqItem));
   /* Getting it the right way would require:
   Pq *this = (Pq *) malloc(sizeof(Pq));
   NAssert(this != 0);
   
   this->item = (PqItem *) malloc (maxLength * sizeof(PqItem));
   NAssert(this->item != 0);
   */
   /* END BRONIS */

   NAssert(this != 0);
   Length    = 0;
   MaxLength = maxLength;
   return(this);
}


void pqClose(Pq *this)
{  
  /* BRONIS */
  /* If we get it the right way, we would have to free it the right way... 
  free (this->item);
  */
  /* END BRONIS */
  
  free (this);
}


/* aux. function from CorEtAl149 */
static void heapify(Pq *this, int i)
{  int l, r, largest;
   PqItem temp;

   l = Left(i);
   r = Right(i);
   largest = (l < Length && Key(l) > Key(i      )) ? l : i;
   largest = (r < Length && Key(r) > Key(largest)) ? r : largest;
   if (largest != i) {
      temp = Item(largest); Item(largest) = Item(i); Item(i) = temp;
      heapify(this, largest);
   }
}


/* delete maximum item */
void pqDeleteMax(Pq *this) 
{  NAssert2(Length > 0);
   Length--;
   Item(0) = Item(Length);
   heapify(this, 0);
}


/* insert item */
void pqInsert(Pq *this, PqItem item){
   int   i;
   PqKey key = item.key;

   NAssert2(Length < MaxLength);
   NDebug3(pqPrint(this));
   NDebug3(printf("-ins>"));

   /* BRONIS */
   /* I just can't leave this in this form:
   Length++;
   i = Length - 1;
   */
   i = Length++;
   /* END BRONIS */
   
   while (i > 0 && Key(Parent(i)) < key) {
      Item(i) = Item(Parent(i));
      i = Parent(i);
   }
   Item(i) = item;
   NDebug3(pqPrint(this));
   NDebug3(printf("\n"));
}
