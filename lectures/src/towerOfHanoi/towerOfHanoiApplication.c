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

main (int argc, char **argv)
{

   int n;

   printf("Welcome to the Tower of Hanoi: please enter the number of disks in your tower>> ");

   scanf("%d", &n);
   if ((n < 1) || (n > 64)) {
      printf("Sorry: can't shift %d disks; the number must be between 1 and 64 ... try again \n",n);
   }
   else {
      printf("To move the %d disks from Tower A to Tower B, do the following\n\n",n);
      towerofhanoi(n, 'A', 'B', 'C');
   }
   
   printf("\npress any key to continue ... ");
   getch();

}

