/* 

   assignment2Interface.h - interface file for a program named assignment2
   =======================================================================

   This program is for Assignment No. 2, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - assignment2Application.cpp - for details of the functionality of this program

      
   File organization
   -----------------

   assignment2Interface.h           interface file:      
									contains the declarations required to use the functions that implement the solution to this problem
									typically, these will include the definitions of the abstract data types used in the implementation

   assignment2Implementation.cpp	implementation file: 
									contains the definitions of the functions that implement the algorithms used in the implementation
 
   assignment2Application.cpp		application file:    
									contains the code that instantiates the abstract data types and calls the associated functions
									in order to effect the required functionality for this application
                                                    
   Author
   ------

   Mubarak Mikail, Carnegie Mellon University Africa
   04/02/2019


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.
   - Added store_location() to return a unique id for each location the ants passed through.	Mubarak Mikail	21/01/2019.
   - Added reset_id() to reset the id to 0 at the end of every test case before processing another test case.	Mubarak Mikail 29/01/2019
   - Added swap() to swap an array element with another array element.	Mubarak Mikail 07/02/2019
   - Added swapStruct() to an array of struct element with another one.	Mubarak Mikail 07/02/2019
   - Added in_sort() to implement insertion sort for performing multi-key sorting. Mubarak Mikail 07/02/2019

*/
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_NUMBER_OF_POINTS 27000

/* function prototypes go here */
struct location_type {
		float t;
		int x;
		int y;
};
void prompt_and_exit(int status);
int store_location(struct location_type location[], float t, int x, int y); // NB x and y are integer values
void swap(int a, int b);
void swap2(location_type arr[], int i, int j);
void swapStruct(struct location_type location[], int i , int j);
void in_sort(struct location_type location[], int n, char key);
int reset_id();