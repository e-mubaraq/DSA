/* 

   assignment3Implementation.cpp - implementation file for a program named assignment3
   ===================================================================================

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

   - Added int samplePoisson() to implement a Poisson distribution.	Mubarak Mikail 16/02/2019
   - Added LIST_TYPE *enqueue() to enqueue a queue. Mubarak Mikail 21/02/2019
   - Added ELEMENT_TYPE dequeue() to dequeue a  queue. Mubarak Mikail 21/02/2019
   - Added swap() to swap an array element with another array element.	Mubarak Mikail 29/02/2019
   - Added insertion_sort() to implement insertion sort for sorting the queue lengths. Mubarak Mikail 29/02/2019

*/

#include "assignment3Interface.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}


int samplePoisson(double lambda) {
	/* Generate a random sample from a Poisson distribution with a given mean, lambda */
	/* Use the function rand to generate a random number */
	static bool first_call = true;
	int count;
	double product;
	double zero_probability;
	/* Seed the random-number generator with current time so */
	/* that the numbers will be different every time we run */
	if (first_call) {
		srand( (unsigned)time( NULL ));
		first_call = false;
	}
	count = 0;
	product = (double) rand() / (double) RAND_MAX;
	zero_probability = exp(-lambda);
	while (product > zero_probability) {
		count++;
		product = product * ((double) rand() / (double) RAND_MAX);
	}
	return(count);
}


LIST_TYPE *enqueue(ELEMENT_TYPE e, LIST_TYPE list) {
	insert(e, end(&list), &list);
	return (&list);
}

ELEMENT_TYPE dequeue(LIST_TYPE l) {
	ELEMENT_TYPE e;
	e = retrieve(first(&l), &l);
	delete_element(first(&l), &l);
	return e;
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
