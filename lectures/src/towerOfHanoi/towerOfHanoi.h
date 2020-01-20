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

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0

void towerofhanoi(int n, char a, char b, char c);
 