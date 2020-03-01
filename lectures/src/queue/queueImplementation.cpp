/************************************************************************/
/*                                                                      */
/* Implementation file for queue implementation of a queue ADT     */
/*                                                                      */
/* The queue element type is a structure comprising an integer & string  */
/* The queue itself is implemented as a singly linked queue of elements   */
/* The ADT queue operations are implemented as a series of functions:    */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon, Mubarak Mikail                                                    */
/*                                                                      */
/************************************************************************/

#include "queue.h"
 

/*** initialize the queue pointer to make sure all subsequent checks on its value are valid ***/

void initialize_queue(QUEUE_TYPE *queue) {
  *queue = NULL;
}


/*** position following last element in a queue ***/

WINDOW_TYPE end(QUEUE_TYPE *queue) {

   WINDOW_TYPE q;
   
   q = *queue;

   if (q == NULL) {
      error("non-existent queue");
   }
   else {
      while (q->next != NULL) {
         q = q->next;
      }
   }
   return(q);
}


/*** empty a queue ***/

WINDOW_TYPE empty(QUEUE_TYPE *queue) {

   WINDOW_TYPE p, q;
   
   if (*queue != NULL) {

      /* queue exists: delete all nodes including the header */

      q = *queue;

      while (q->next != NULL) {
         p = q;
         q = q->next;
         free(p);
      }
   }
 
   /* now,  create a new empty one with a header node */
      
   if ((q = (NODE_TYPE) malloc(sizeof(NODE))) == NULL) 
      error("function empty: unable to allocate memory");
   else {
      q->next = NULL;
      *queue = q;
   }
   return(end(queue));
}


/*** test to see if a queue is empty  ***/

int is_empty(QUEUE_TYPE *queue) {

   WINDOW_TYPE q;
   
   q = *queue;

   if (q == NULL) {
      error("non-existent queue");
   }
   else {
      if (q->next == NULL) 
         return(TRUE);
      else
         return(FALSE);
   }
}


/*** position at first element in a queue ***/

WINDOW_TYPE first(QUEUE_TYPE *queue) {

   if (is_empty(queue) == FALSE)
      return(*queue);
   else
      return(end(queue));
}


/*** position at last element in a queue ***/

WINDOW_TYPE last(QUEUE_TYPE *queue) {

   WINDOW_TYPE p, q;
   
   if (*queue == NULL) {
      error("last: non-existent queue");
   }
   else {

      /* queue exists: find last node */

      if (is_empty(queue)) {
         p = end(queue);
      }
      else {
         p = *queue;
         q = p->next;

         while (q->next != NULL) {
            p = q;
            q = q->next; 
         }
      }
      return(p);
   }
 }


/*** position at next element in a queue ***/

WINDOW_TYPE next (WINDOW_TYPE w, QUEUE_TYPE *queue) {

   if (w == last(queue)) {
      return(end(queue));
   }
   else if (w == end(queue)) {
      error("can't find next after end of queue");
   }
   else {
      return(w->next);
   }
}


/*** position at previous element in a queue ***/

WINDOW_TYPE previous(WINDOW_TYPE w, QUEUE_TYPE *queue) {

   WINDOW_TYPE p;

   if (w != first(queue)) {

      p = first(queue);
      while (p->next != w) {
         p = p->next;
         if (p == NULL) break;  /* trap this to ensure we don't dereference */
                                /* a null pointer in the while condition    */
      }

      if (p != NULL)
        return(p);
      else {
        error("can't find previous to a non-existent node ");
        return (w);
      }
   }
   else {
      error("can't find previous before first element in queue");
      return(w);
   }
}


/*** insert an element in a queue ***/

QUEUE_TYPE *insert(ELEMENT_TYPE e,  WINDOW_TYPE w, QUEUE_TYPE *queue ) {

   WINDOW_TYPE temp;

   if (*queue == NULL) {
      error("cannot insert in a non-existent queue");
   }
   else {

      /* insert it after w */

      temp = w->next;
      if ((w->next = (NODE_TYPE) malloc(sizeof(NODE))) == NULL) 
         error("function insert: unable to allocate memory");
      else {
         w->next->element = e;
         w->next->next = temp;
      }
      return(queue);
   }
}


/*** delete an element in a queue ***/

QUEUE_TYPE *delete_element (WINDOW_TYPE w, QUEUE_TYPE *queue) {

   WINDOW_TYPE p;

   if (*queue == NULL) {
      error("cannot delete from a non-existent queue");
   }
   else {

      p = w->next; /* node to be deleted */

      w->next = w->next->next; /* rearrage the links */

      free(p); /* delete the node */

      return(queue);
   }
}


/*** retrieve an element in a queue ***/

ELEMENT_TYPE retrieve(WINDOW_TYPE w, QUEUE_TYPE *queue) {

   if (*queue == NULL) {
      error("cannot retrieve from a non-existent queue");
   }
   else {
      return(w->next->element);
   }
}


/*** print all elements in a queue ***/

int print(QUEUE_TYPE *queue) {

   WINDOW_TYPE w;
   ELEMENT_TYPE e;

   printf("Contents of queue: \n");

   w = first(queue);

   while (w != end(queue)) {

      e = retrieve(w, queue);
      
      printf("%d %s\n", e.number, e.string);

      w = next(w, queue);
   }

   printf("--- \n");

   return(0);
}


/*** error handler: print message passed as argument and take appropriate action ***/

void error(char *s) {
   printf("Error: %s\n",s);
   exit(0);
}

/*** assign values to an element ***/

int assign_element_values(ELEMENT_TYPE *e, int number, char s[]) {

   e->string = (char *) malloc(sizeof(char) * (strlen(s)+1));

   if (e->string==NULL) printf("Failed to allocate memory \n"); 

   strcpy(e->string, s);

   e->number = number;
   
   return(0);
}

QUEUE_TYPE enqueue(ELEMENT_TYPE e, WINDOW_TYPE w, QUEUE_TYPE l) {
	return *insert(e, w, &l);

}

ELEMENT_TYPE dequeue(QUEUE_TYPE l) {
	ELEMENT_TYPE e, d;
	e = retrieve(first(&l), &l);
	d = e;
	delete(&d);
	return e;
}

ELEMENT_TYPE head(QUEUE_TYPE q) {
	ELEMENT_TYPE e;
	e = retrieve(first(&q), &q);
	return e;
}