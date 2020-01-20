/************************************************************************/
/*                                                                      */
/* Application file for linked-list implementation of a LIST ADT        */
/*                                                                      */
/* The list element type is a structure comprising an integer & string  */
/* The list itself is implemented as a singly linked list of elements   */
/* The ADT list operations are implemented as a series of functions:    */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/*                                                                      */
/************************************************************************/

#include "linkedList.h"

/*** main application routine ***/

int main() {

   WINDOW_TYPE w;
   ELEMENT_TYPE e;
   LIST_TYPE list;

   initialize_list(&list); 

   empty(&list);
   print(&list);
   
   assign_element_values(&e, 1, "String A");
   w = first(&list);
   insert(e, w, &list);
   print(&list);
   
   assign_element_values(&e, 2, "String B");
   insert(e, w, &list);
   print(&list);

   assign_element_values(&e, 3, "String C");
   insert(e, last(&list), &list);
   print(&list);

   assign_element_values(&e, 4, "String D");
   w = next(last(&list), &list);
   insert(e, w, &list);
   print(&list);

   w = previous(w, &list);
   delete_element(w, &list);
   print(&list);

   // keep the terminal open until the user hits return
   printf("Press <return> to finish"); 
   getchar();
}
