/************************************************************************/
/*                                                                      */
/* Interface file for queue implementation of a QUEUE ADT          */
/*                                                                      */
/* The queue element type is a structure comprising an integer & string  */
/* The queue itself is implemented as a singly linked queue of elements   */
/* The ADT queue operations are implemented as a series of functions:    */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon, Mubarak Mikail                                                        */
/*                                                                      */
/* 26/02/2018 changed delete() to delete_element() in order to avoid    */
/* conflict with the inbuilt delete function in C++                     */
/************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE  1

typedef  struct {
            int number;
            char *string;
         } ELEMENT_TYPE;

typedef struct node *NODE_TYPE;

typedef struct node {
            ELEMENT_TYPE element;
            NODE_TYPE next;
         } NODE;

typedef NODE_TYPE QUEUE_TYPE;

typedef QUEUE_TYPE WINDOW_TYPE;

/*** function prototypes ***/


/*** initialize the queue pointer to make sure all subsequent checks on its value are valid ***/

void initialize_queue(QUEUE_TYPE *queue);


/*** position following last element in a queue ***/

WINDOW_TYPE end(QUEUE_TYPE *queue);

/*** empty a queue ***/

WINDOW_TYPE empty(QUEUE_TYPE *queue);

/*** test to see if a queue is empty  ***/

int is_empty(QUEUE_TYPE *queue);

/*** position at first element in a queue ***/

WINDOW_TYPE first(QUEUE_TYPE *queue);

/*** position at last element in a queue ***/

WINDOW_TYPE last(QUEUE_TYPE *queue);

/*** position at next element in a queue ***/

WINDOW_TYPE next (WINDOW_TYPE w, QUEUE_TYPE *queue);

/*** position at previous element in a queue ***/

WINDOW_TYPE previous(WINDOW_TYPE w, QUEUE_TYPE *queue);

/*** insert an element in a queue ***/

QUEUE_TYPE *insert(ELEMENT_TYPE e,  WINDOW_TYPE w, QUEUE_TYPE *queue );

/*** delete an element in a queue ***/

QUEUE_TYPE *delete_element (WINDOW_TYPE w, QUEUE_TYPE *queue);

/*** retrieve an element in a queue ***/

ELEMENT_TYPE retrieve(WINDOW_TYPE w, QUEUE_TYPE *queue);

/*** print all elements in a queue ***/

int print(QUEUE_TYPE *queue);

/*** error handler: print message passed as argument and take appropriate action ***/

void error(char *s);

/*** assign values to an element ***/

int assign_element_values (ELEMENT_TYPE *e, int number, char s[]);

/*** Enqueue an element ***/
QUEUE_TYPE enqueue(ELEMENT_TYPE e, WINDOW_TYPE w, QUEUE_TYPE q);

/*** Dequeue an element ***/
ELEMENT_TYPE dequeue(QUEUE_TYPE q);

ELEMENT_TYPE head(QUEUE_TYPE q);
