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

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.


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