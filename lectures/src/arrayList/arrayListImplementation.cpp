/************************************************************************/
/*                                                                      */
/* Implementation file for array implementation of a LIST ADT           */
/*                                                                      */
/* The list element type is a structure comprising an integer & string  */
/* The maximum size of the list is given by the constant MAX_LIST_SIZE  */
/* The list itself is implemented as a structure comprising an array    */
/* of elements and also  an integer containing the size of the list.    */
/* The ADT list operations are implemented as a series of functions     */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/*                                                                      */
/************************************************************************/

#include "arrayList.h"

/*** position following last element in a list ***/

WINDOW_TYPE end(LIST_TYPE *list) {
   return(list->last+1);
}


/*** empty a list ***/

WINDOW_TYPE empty(LIST_TYPE *list) {

   list->last = -1;  

   return(end(list));
}


/*** test to see if a list is empty  ***/

int is_empty(LIST_TYPE *list) {

   if (list->last == -1)
      return(TRUE);
   else
      return(FALSE);
}



/*** position at first element in a list ***/


WINDOW_TYPE first(LIST_TYPE *list) {

   if (is_empty(list) == FALSE)
      return(0);
   else
      return(end(list));
}


/*** position at next element in a list ***/

WINDOW_TYPE next (WINDOW_TYPE w, LIST_TYPE *list) {

   if (w == last(list)) {
      return(end(list));
   }
   else if (w == end(list)) {
      error("can't find next after end of list");
   }
   else {
      return(w+1);
   }
}


/*** position at previous element in a list ***/

WINDOW_TYPE previous(WINDOW_TYPE w, LIST_TYPE *list) {

   if (w != first(list)) {
      return(w-1);
   }
   else {
      error("can't find previous before first element in list");
      return(w);
   }
}


/*** position at last element in a list ***/

WINDOW_TYPE last(LIST_TYPE *list) {

   return(list->last);
}


/*** insert an element in a list ***/

LIST_TYPE *insert(ELEMENT_TYPE e,  WINDOW_TYPE w, LIST_TYPE *list ) {

   int i;

   if (list->last >= MAX_LIST_SIZE-1) {
   
      error("can't insert - list is full");

   } 
   else if ((w > list->last + 1) || (w < 0)) {

      error("position does not exist");
   }
   else {

      /* insert it ... shift all after w to the right */

      for (i = list->last; i >= w; i--) {
         list->a[i+1] = list->a[i];
      }
      
      list->a[w] = e;
      list->last = list->last + 1;

      return(list);
   }
}


/*** delete an element in a list ***/

LIST_TYPE *delete_element (WINDOW_TYPE w, LIST_TYPE *list) {

   int i;

   if ((w < 0) || (w > list->last)) {
   
      /* list is empty */

      error("Position does not exist");

   } 
   else {

      /* delete it ... shift all after w to the left */

      list->last = list->last - 1;

      for (i = w; i <= list->last; i++) {
         list->a[i] = list->a[i+1];
      }
      
      return(list);
   }
}


/*** retrieve an element in a list ***/

ELEMENT_TYPE retrieve(WINDOW_TYPE w, LIST_TYPE *list) {

   if ((w < 0) || (w > list->last)) {
   
      /* list is empty */

      error("Position does not exist");

   } 
   else {
      
      return(list->a[w]);
   }
}


/*** print all elements in a list ***/

int print(LIST_TYPE *list) {

   WINDOW_TYPE w;
   ELEMENT_TYPE e;

   printf("Contents of list: \n");

   w = first(list);

   while (w != end(list)) {

      e = retrieve(w, list);
      
      printf("%d %s\n", e.number, e.string);

      w = next(w, list);
   }

   printf("--- \n");

   return(0);
}


/*** error handler: print message passed as argument and take appropriate action ***/

int error(char *s) {

   printf("Error: %s\n",s);

   exit(0);
}

/*** assign values to an element ***/

int assign_element_values(ELEMENT_TYPE *e, int number, char s[]) {

    e->string = (char *) malloc(sizeof(char) * (strlen(s)+1));

	if (e->string==NULL) printf("Debug failed to allocate memory \n"); 

	strcpy(e->string, s);

    e->number = number;

    return(0);
}
