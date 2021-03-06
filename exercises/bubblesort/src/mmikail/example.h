/* 

   example.h - interface file for a program named example
   ======================================================

   This program is for Assignment No. 0, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - exampleApplication.cpp - for details of the functionality of this program

      
   File organization
   -----------------

   example.h                  interface file:      
                              contains the declarations required to use the functions that implement the solution to this problem
                              typically, these will include the definitions of the abstract data types used in the implementation

   exampleImplementation.cpp  implementation file: 
                              contains the definitions of the functions that implement the algorithms used in the implementation
 
   exampleApplication.cpp     application file:    
                              contains the code that instantiates the abstract data types and calls the associated functions
                              in order to effect the required functionality for this application
                                                    
   Author
   ------

   David Vernon, Carnegie Mellon University Africa
   05/01/2019


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_MESSAGE_LENGTH 81
#define SIZE 5

/* function prototypes go here */

void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);
int bubble_sort(int *a, int size);
int bubble_sort_eff(int *a, int size);
void swap(int a, int b);
void swap2(int arr[], int i, int j);
int insertion_sort(int a[], int size);
void printArray(int *a, int size);