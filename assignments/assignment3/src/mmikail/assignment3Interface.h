/* 

   assignment3Interface.h - interface file for a program named assignment3
   =======================================================================

   This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - assignment3Application.cpp - for details of the functionality of this program

      
   File organization
   -----------------

   assignment3Interface.h           interface file:      
									contains the declarations required to use the functions that implement the solution to this problem
									typically, these will include the definitions of the abstract data types used in the implementation

   assignment3Implementation.cpp	implementation file: 
									contains the definitions of the functions that implement the algorithms used in the implementation
 
   assignment3Application.cpp		application file:    
									contains the code that instantiates the abstract data types and calls the associated functions
									in order to effect the required functionality for this application
                                                    
   Author
   ------

   Mubarak Mikail, Carnegie Mellon University Africa
   15/02/2019


   Audit Trail
   -----------

   - Added int samplePoisson() to implement a Poisson distribution.	Mubarak Mikail 16/02/2019
   - Added LIST_TYPE *enqueue() to enqueue a queue. Mubarak Mikail 21/02/2019
   - Added ELEMENT_TYPE dequeue() to dequeue a  queue. Mubarak Mikail 21/02/2019
   - Added swap() to swap an array element with another array element.	Mubarak Mikail 29/02/2019
   - Added insertion_sort() to implement insertion sort for sorting the queue lengths. Mubarak Mikail 29/02/2019

*/
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "linkedList.h"

#define TRUE 1
#define FALSE 0
#define KEY_LENGTH 20
#define STRING_LENGTH 80
#define NUMBER_OF_KEYS 7

/* function prototypes go here */

void prompt_and_exit(int status);
int samplePoisson(double lambda);
LIST_TYPE *enqueue(ELEMENT_TYPE e, LIST_TYPE l);
ELEMENT_TYPE dequeue(LIST_TYPE l);
int insertion_sort(int a[], int size);
void swap(int arr[], int i, int j);