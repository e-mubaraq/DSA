/* 

   exampleImplementation.cpp - implementation file for a program named example
   ============================================================================

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

 
 
#include "example.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {
   fprintf(fp,"The message is: %s\n", message);
}

void swap(int a, int b){
	int temp;

	temp = b;
	b = a;
	a = temp;
}

void swap2(int arr[], int i, int j){
	int temp;

	temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}

int bubble_sort(int *a, int size) { // int a[]
	int i,j, temp;
	for (i=0; i < size-1; i++) { // why?
		for (j=i; j >= 0; j--) { // Because initially j=i
			if (a[j] > a[j+1]) { // and we access element j+1
			/* swap */
			temp = a[j+1];
			a[j+1] = a[j];
			a[j] = temp;
			//swap2(a, j, j+1);
			}
		}
	}

	return (0);
}

int bubble_sort_eff(int *a, int size) { // int a[]
	int i,j;
	
	for (i = 0; i < size-1; i++) {
		j = i;
		while ((a[j] > a[j+1]) &&  (j >= 0)){
			/* swap */
			swap2(a, j, j+1);
			j--;
		}
	}

   return (0);
}

int insertion_sort(int a[], int size) { // int a[]
	int i,j;
	
	for (i = 1; i < size; i++) {
		j = i;
		while ((a[j] < a[j-1]) &&  (j > 0)){
			/* swap */
			swap2(a, j-1, j);
			j--;
		}
	}

   return (0);
}

void printArray(int *arr, int size){
		for (int i = 0; i < size; i++){
		printf("%3d  ", arr[i]);
	}
}