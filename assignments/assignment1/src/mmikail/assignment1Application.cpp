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
 
#include "assignment1Interface.h"
 
int main() {
	int number_of_test_cases;
	int i, j, id;
	float t, x, y;
	int debug = TRUE;

   FILE *fp_in, *fp_out;

	struct location_type location[MAX_NUMBER_OF_POINTS];
	struct location_type temp;


	for (j=0; j<MAX_NUMBER_OF_POINTS; j++) {
		location[j].t = 0.0;
		location[j].x = 0;
		location[j].y = 0;
		location[j].id_number = 0;
	}
	/* this is how you swap elements 0 and 1 in an array of structures */

   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
     prompt_and_exit(1);
   }

   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
     prompt_and_exit(1);
   }

   fprintf(fp_out, "mmikail\n");
   	/* read the number of test cases from a file */
	fscanf(fp_in, "%d", &number_of_test_cases); //note the &

	/* read the location data from a file */
	fscanf(fp_in, "%f %f %f", &t, &x, &y);
	
	for(i = 1; i <= number_of_test_cases; i++)
	{
		while(t >= 0.00)
		{
			// I need to populate the location matrix with the x, y and t values
			id = store_location(location, t, (int)x, (int)y);
			printf("%3d %6.3f %4d %4d\n", id, t, (int)x, (int)y);

			/* write the input data to the output file */
			fprintf(fp_out, "%3d %6.3f %4d %4d\n", id, t, (int)x, (int)y);
			fscanf(fp_in, "%f %f %f", &t, &x, &y); //note the &
		}
		fprintf(fp_out, "--------------\n");

		fscanf(fp_in, "%f %f %f", &t, &x, &y); //note the &
	}

   fclose(fp_in);
   fclose(fp_out);

   prompt_and_exit(0);
}
