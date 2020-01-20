/* 

   towerofhanoi 
   ============

   Solve the Tower of Hanoi problem by recursion.
   
   The program prompts the user to enter the number of disks in the tower.  
   This must be in the range 1-64.

   This program prints a sequence of move instructions identifying the disks to be moved.

   There is a flag print_calls in the hanoi() recursive function. If the program is compiled with this flag TRUE
   then the program also prints the calls to the hanoi() function.  
   The indentation of the printed call is proportional to the level of recursion.
   This emulates a structured walkthrough of the program.


   Author
   ------

   David Vernon, Carnegie Mellon University Africa
   28/01/2019


   Audit Trail
   -----------
    
*/

#include "towerOfHanoi.h"

void towerofhanoi(int n, char a, char b, char c) {
   
   int print_calls = TRUE; // FALSE;
   int i;
   static int depth_of_recursion = 0;

   depth_of_recursion++;

   if (print_calls==TRUE) {
      for (i=1; i<depth_of_recursion; i++) {
		 printf("   ");
	 }
	 printf("towerofhanoi(%d, %c, %c, %c);\n",n, a,b,c);
   }


   if (n > 0) {

      towerofhanoi(n-1, a, c, b);

	  /* indent the instruction to match the depth of recursion if printing the calls to the function */

	  if (print_calls==TRUE) {
		 for (i=1; i<=depth_of_recursion; i++) {
			 printf("   ");
		 }
	  }

      printf("Move disk of diameter %2d from %c to %c\n", n, a, b);

      towerofhanoi(n-1, c, b, a);

   }

   depth_of_recursion--;
}
