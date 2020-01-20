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
#ifdef compile 

/* Example 2                                       */
/* This is a C program to ask you to enter two     */
/* numbers; it then compares them and prints a     */
/* message to say whether they are equal or not    */

#include <stdio.h> 
#include <conio.h>

void main() {
 
   int first_number, second_number;

   printf("Type a number and then press Enter >>");
   scanf("%d",&first_number);

  printf("Type another number and then press Enter >>");
  scanf("%d",&second_number);

  if (first_number == second_number) 
     printf("The two numbers %d are identical", first_number);
  else
     printf("The two numbers %d and %d are different",  first_number, second_number);

  printf("\nPress any key to continue\n");
   _getch();
}
#endif

/* Example 2b                                                          */
/* This is a C program to ask you to enter three   */
/* numbers; it then compares them and prints a   */
/* message to say whether they are equal or not  */  

#include <stdio.h>
#include <conio.h>
void main() {

   int first_number, second_number, third_number;

   printf("Please type three numbers .... \n");
   printf("Enter the first number >>");
   scanf("%d",&first_number);

   printf("Enter the second number >>");
   scanf("%d",&second_number);

   printf("Enter the third number >>");
   scanf("%d",&third_number);


   if (first_number == second_number)
      if (second_number == third_number)
         printf("The three numbers %d are identical", 
                 first_number);

   if (first_number != second_number)
      if (second_number != third_number)
         if (first_number != third_number)
            printf("The three numbers %d %d %d are all different", 
                   first_number, second_number, third_number);
 
    printf("\nPress any key to continue\n");
   _getch();
}
