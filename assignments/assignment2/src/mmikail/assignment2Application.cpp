/* 

   assignment2Application.cpp - application file for a program named assignment2
   =============================================================================

   This program is for Assignment No. 2, Course 04-630 Data Structures and Algorithms for Engineers. 

   Assigning Unique Identification Numbers to Locations in Ant Paths.

   The functionality of the program is defined as follows.
   
   Read location data and time from an input file, process it, and assign unique id for each unique location.
   The output file will contain a block of unique ids with corresponding time, x and y-coordinates.

   A function is used to prepend the text and write the message to the output file.

   Input data with the total number of test cases is provided in an input file named input.txt.
   It is followed by n sets of locations. Each location was composed of the time, the x coordinate and the y coordinate of the location. 
   All three are real numbers. The last location in each set is signified by a time value less than zero, e.g. -1.0. 
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"


   Input
   -----

   - A block of numbers representing the time, x and y coordinates of the Ant's movement.


   Output
   ------

   - A block of numbers representing the unique id, t and unique x and y coordinates.
 

   Sample Input
   ------------
   
	5
	0.000 0.000 0.000
	0.100 0.050 0.000
	0.200 0.100 0.000
	0.300 0.190 0.000
	0.400 0.300 0.000
	0.500 0.400 0.000
	0.600 0.500 0.000
	0.700 0.600 0.000
	0.800 0.700 0.000
	0.900 0.800 0.000
	1.000 0.900 0.000
	1.100 0.000 1.000
	1.200 0.000 1.010
	1.300 0.000 1.020
	1.400 0.000 2.000
	1.500 0.000 2.000
	1.600 0.000 4.000
	1.700 0.000 4.090
	1.800 0.000 5.000
	1.900 0.000 4.000
	2.000 0.000 2.000
	-1.00 0.000 0.000

   Sample Output
   -------------
	mmikail
	  1  0.000    0    0
	  2  1.100    0    1
	  3  1.400    0    2
	  4  1.600    0    4
	  5  1.800    0    5
	--------------

   Solution Strategy
   -----------------

   The data was read in and stored in variables. An array of struct was defined which was used to store the data read in from the 
   file after processing each location.
   A unique id was assigned by checking that no two lines have the same x and y values that is after the x and y values have been converted
   to int. For every x and y values, check that they are not already in the array of structs, if they are, just return the id and 
   if they are not add that record to the data structure and give it a unique id.

   Decalre an array of struct to store each location, id and time data after processing.
   Instantiate x and y with an invalid value since those values will never be supplied as part of the input data
   read_in(x,y,t)
   check if (x and y already exists in the data structure)
		return the id;
	else
		return a unique id and add the x, y, t and id to the data structure. Increment the id

   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

   - 



   File organization
   -----------------

    assignment1Interface.h          interface file:      
									contains the declarations required to use the functions that implement the solution to this problem
									typically, these will include the definitions of the abstract data types used in the implementation

   assignment1Implementation.cpp	implementation file: 
									contains the definitions of the functions that implement the algorithms used in the implementation
 
   assignment1Application.cpp		application file:    
									contains the code that instantiates the abstract data types and calls the associated functions
									in order to effect the required functionality for this application


   Author
   ------

   Mubarak Mikail, Carnegie Mellon University Africa
   04/02/2019


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.
   - Added store_location() to return a unique id for each location the ants passed through.	Mubarak Mikail	21/01/2019.
   - Added reset_id() to reset the id to 1 at the end of every test case before processing another test case.	Mubarak Mikail 29/01/2019

*/
 
#include "assignment2Interface.h"
 
int main() {
	int number_of_test_cases;
	int i, j, id;
	float t, x, y;
	int debug = TRUE;

   FILE *fp_in, *fp_out;

	struct location_type location[MAX_NUMBER_OF_POINTS];

	for (j=0; j<MAX_NUMBER_OF_POINTS; j++) {
		location[j].t = 0.0;
		location[j].x = -451;
		location[j].y = 451;
	}
	
	/**
	Check if the input and output data file exists, so that it can fail gracefully without crashing the program.
	**/
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
			id = store_location(location, t, (int)x, (int)y);
			printf("%3d ", id);
			in_sort(location, id + 1);
			/* write the output data to the output file */
			printf("%6.3f %4d %4d\n", t, (int)x, (int)y);
			fprintf(fp_out, "%6.3f %4d %4d\n", location[id].t,
								location[id].x, location[id].y);

			fscanf(fp_in, "%f %f %f", &t, &x, &y); //note the &
		}
		fprintf(fp_out, "--------------\n");
		printf("--------------\n");

		fscanf(fp_in, "%f %f %f", &t, &x, &y); //note the &
	}
   fclose(fp_in);
   fclose(fp_out);

   prompt_and_exit(0);
}
