/* 

   exampleApplication.cpp - application file for a program named example
   =====================================================================

   This program is for Assignment No. 0, Course 04-630 Data Structures and Algorithms for Engineers. 

   The functionality of the program is defined as follows.
   
   Read a single-line message from an input file, write it to the terminal, and also write a version of it to an output file.
   The message to be written to file should be prepended with the following text:

   "The message is: "

   A function is used to prepend the text and write the message to the output file.

   Input data with a test case message is provided in an input file named input.txt.  
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"

   There are a maximum of eighty of characters in the message.  If message has more than eighty characters, only the first eighty are read.


   Input
   -----

   - A single line of text no longer than 80 characters.


   Output
   ------

   - A single line of text, beginning "The message is: "
 

   Sample Input
   ------------
   
   Hello World!


   Sample Output
   -------------

   The message is: Hello World!


   Solution Strategy
   -----------------

   This is just an example program so there is no real computational problem to solve.  In other cases, you would describe here
   the principle computational theories used in solving the problem, along with the main data structures and algorithms used.


   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

   - message with no character
   - message with number of characters in the range 1-80
   - message with more than eighty characters



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
 
#include "example.h"
/* A program to prompt the user three times and reads three numbers. */
/* It compare these three numbers and tell the user whether          */
/*                                                                   */
/* - all three numbers are the same                                  */
/* - all three numbers are different                                 */
/* - just two numbers are the same                                   */
/*   in this case, it also tells the user which two numbers they are */
/*                                                                   */
/* The program continues to ask the user for input until he enters   */
/* three zeros.                                                      */   

#include <stdio.h> 
#include <conio.h>

#define TRUE  1
#define FALSE 0

void main() {
   int n1, n2, n3;

   /* give the numbers initial values */

   n1 = 1; 
   n2 = 1; 
   n3 = 1;

   /* while the three numbers are not all zero */

   while ((n1 != 0) && (n2 != 0) && (n3 != 0)) {
 
      printf("Please enter the first number  >>");
      scanf("%d",&n1);
  
      printf("Please enter the second number >>");
      scanf("%d",&n2);

      printf("Please enter the third number  >>");
      scanf("%d",&n3);

      
      /* check to see if they are all the same */

      if ((n1 == n2) && (n2 == n3) && (n1 == n3)) {
         printf(" The three numbers are all the same. \n"); 
      } 
      else {
         if ((n1 != n2) && (n2 != n3) && (n1 != n3)) {
	          printf("The three numbers are all the different.\n");
	       }
         else {
     
            /* two are the same -  which are they? */

            if (n1 == n2) {
	            printf("The first and second numbers are the same: %d\n",
               n1, n2);
	         }
	         else {
	            if (n2 == n3) {
	               printf("The second and third numbers are the same: %d\n",
                  n2, n3);
	            }

	            else {  /* no need to check if the first and third    */
		               /* are the same ... it's the only possibility */
        	    printf("The first and third numbers are the same:%d\n",
                   n1, n2);                                                         
	            }
	         }
	      }
       }
    }
  
   printf("\nPress any key to continue\n");
   _getch();
}  
