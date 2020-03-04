/* 

   assignment4Implementation.cpp - implementation file for a program named assignment4
   ===================================================================================

   This program is for Assignment No. 4, Course 04-630 Data Structures and Algorithms for Engineers. 

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

   - Added swap() to swap an array element with another array element.	Mubarak Mikail 29/02/2019
   - Added insertion_sort() to implement insertion sort for sorting the queue lengths. Mubarak Mikail 29/02/2019

*/

#include "assignment4Interface.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}



int insertion_sort(int a[], int size) { // int a[]
	int i,j;
	
	for (i = 1; i < size; i++) {
		j = i;
		while ((a[j] < a[j-1]) &&  (j > 0)){
			/* swap */
			swap(a, j-1, j);
			j--;
		}
	}

   return (0);
}

void swap(int arr[], int i, int j) {
	int temp;

	temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}
