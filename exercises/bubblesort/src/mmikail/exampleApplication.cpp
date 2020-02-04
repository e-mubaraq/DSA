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
int main() {
   int debug = TRUE;
   char message[MAX_MESSAGE_LENGTH];

   FILE *fp_in, *fp_out;

   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
     prompt_and_exit(1);
   }

   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
     prompt_and_exit(1);
   }

   /* read the message from the input file */

   fgets(message, MAX_MESSAGE_LENGTH, fp_in);
 
   if (debug) printf ("%s\n",message);

   print_message_to_file(fp_out, message);

   fclose(fp_in);
   fclose(fp_out);

   prompt_and_exit(0);
}
#endif

#include <stdio.h>
#include <conio.h>



int bubble_sort(int *a, int size) { // int a[]
	int i,j, temp;
	for (i=0; i < size-1; i++) { // why?
		for (j=i; j >= 0; j--) { // Because initially j=i
			if (a[j] > a[j+1]) { // and we access element j+1
			/* swap */
			temp = a[j+1];
			a[j+1] = a[j];
			a[j] = temp;
			}
		}
	}

	printf("\nPress any key to continue\n");
   _getch();
   return 0;
}

int main(){
	int arr[SIZE];
	int i;

	arr[0] = 10;
	arr[1] = 9;
	arr[2] = 11;
	arr[3] = 8;
	arr[4] = 4;
	//for (i = 0; i < SIZE; i++){

	//}

	bubble_sort(arr, SIZE);
	printf("Sorted array: \n");
	for (i = 0; i < SIZE; i++){
		printf("%3d, ", arr[i]);
		printf("Sorted array: \n");
	}

	return (0);
}

//int bubble_sort(int *a, int size) { // int a[]
//	int i,j, temp;
//	for (j=1; j < size-1; j++) { // why?
//		while (a[j] > a[j-1]){
//			/* swap */
//			temp = a[j+1];
//			a[j+1] = a[j];
//			a[j] = temp;
//			}
//		}
//	}
//
//	printf("\nPress any key to continue\n");
//   _getch();
//   return 0;
//}

