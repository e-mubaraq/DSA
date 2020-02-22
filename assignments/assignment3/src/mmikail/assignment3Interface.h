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

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.


*/
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define KEY_LENGTH 20
#define STRING_LENGTH 80
#define NUMBER_OF_KEYS 7

/* function prototypes go here */

void prompt_and_exit(int status);
int samplePoisson(double lambda);