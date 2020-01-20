/************************************************************************/
/*                                                                      */
/* Interface file for array implementation of a LIST ADT                */
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

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100
#define FALSE 0
#define TRUE  1

typedef  struct {
            int number;
            char *string;
         } ELEMENT_TYPE;

typedef  struct {
            int last;
            ELEMENT_TYPE a[MAX_LIST_SIZE];
         } LIST_TYPE;

typedef  int WINDOW_TYPE;

/*** function prototypes ***/

/*** position following last element in a list ***/

WINDOW_TYPE end(LIST_TYPE *list);

/*** empty a list ***/

WINDOW_TYPE empty(LIST_TYPE *list);

/*** test to see if a list is empty  ***/

int is_empty(LIST_TYPE *list);

/*** position at first element in a list ***/

WINDOW_TYPE first(LIST_TYPE *list);

/*** position at next element in a list ***/

WINDOW_TYPE next (WINDOW_TYPE w, LIST_TYPE *list);

/*** position at previous element in a list ***/

WINDOW_TYPE previous(WINDOW_TYPE w, LIST_TYPE *list);

/*** position at last element in a list ***/

WINDOW_TYPE last(LIST_TYPE *list);

/*** insert an element in a list ***/

LIST_TYPE *insert(ELEMENT_TYPE e,  WINDOW_TYPE w, LIST_TYPE *list );

/*** delete an element in a list ***/

LIST_TYPE *delete_element (WINDOW_TYPE w, LIST_TYPE *list);

/*** retrieve an element in a list ***/

ELEMENT_TYPE retrieve(WINDOW_TYPE w, LIST_TYPE *list);

/*** print all elements in a list ***/

int print(LIST_TYPE *list);


/*** error handler: print message passed as argument and take appropriate action ***/

int error(char *s);

/*** assign values to an element ***/

int assign_element_values(ELEMENT_TYPE *e, int number, char s[]);
 