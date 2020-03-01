/************************************************************************/
/*                                                                      */
/* Application file for queue implementation of a LIST ADT        */
/*                                                                      */
/* The list element type is a structure comprising an integer & string  */
/* The list itself is implemented as a singly linked list of elements   */
/* The ADT list operations are implemented as a series of functions:    */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon, Mubarak Mikail                                                       */
/*                                                                      */
/************************************************************************/

#include "queue.h"

/*** main application routine ***/

int main() {

   WINDOW_TYPE w;
   ELEMENT_TYPE e;
   QUEUE_TYPE queue;

   initialize_queue(&queue); 

   empty(&queue);
   print(&queue);
   
   assign_element_values(&e, 1, "String A");
   w = first(&queue);
   insert(e, w, &queue);
   print(&queue);
   
   assign_element_values(&e, 2, "String B");
   insert(e, w, &queue);
   print(&queue);

   assign_element_values(&e, 3, "String C");
   insert(e, last(&queue), &queue);
   print(&queue);

   assign_element_values(&e, 4, "String D");
   w = next(last(&queue), &queue);
   insert(e, w, &queue);
   print(&queue);

   w = previous(w, &queue);
   delete_element(w, &queue);
   print(&queue);

   // keep the terminal open until the user hits return
   printf("Press <return> to finish"); 
   getchar();
}
