/* 

   assignment3Application.cpp - application file for a program named assignment3
   =============================================================================

   This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 

   Multi-key Sorting.

   The functionality of the program is defined as follows.
   
   Read location data and time from an input file, store each entry in an array of struct that haas been defined, and sort each row entry
   by sorting all x coordinates in ascending order. If locations have the same x coordinate, the location should be listed so that 
   y coordinates are in ascending order. If locations have the same x and y coordinates, the locations should be listed so that the 
   time t is in ascending. It is a multi-key sorting problem with x,y and t.
   The output file will contain a block of sorted time, x and y-coordinates.

   A function is used to store each entry of t, x and y read in for each testcase.
   Another function is used to sort the entries in each testcase such that it doesn't sort all entries in the output file all at once.
   This was done with a function that resets the seed of the array of struct everytime the sorting of one testcase data is concluded.

   Input data with the total number of test cases is provided in an input file named input.txt.
   It is followed by n sets of locations. Each location was composed of the time, the x coordinate and the y coordinate of the location. 
   All three are real numbers. The last location in each set is signified by a time value less than zero, e.g. -1.0. that is the row 
   before the row with a negatove time.
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"


   Input
   -----

   - A block of numbers representing the time, x and y coordinates of the Ant's movement.


   Output
   ------

   - A block of numbers showing the sorted real time t and x , y integer coordinates.
 

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
	0.000 0 0
	0.100 0 0
	0.200 0 0
	0.300 0 0
	0.400 0 0
	0.500 0 0
	0.600 0 0
	0.700 0 0
	--------------

   Solution Strategy
   -----------------

   The data was read in and stored in variables. An array of struct was defined which was used to store the data read in from the 
   file after processing each location. Every t and its corresponding integer values of x and y were stored in an array of struct
   and then sorted. An insertion sort was used in this implementation, it was implemented in a way that it could be called multiple
   times in the main program thus performing a multi-key sort. A function was also used to reset the seed of the array of struct 
   everytime the sorting of one testcase data is done. This was added to avoid sorting over different testcases.

   Decalre an array of struct to store each location, id and time data after processing.
   Instantiate x and y with an invalid value since those values will never be supplied as part of the input data
   read_in(x,y,t) for each testcase
   store t, (int)x, (int)y into the array of struct
   After all the data for one test case has been stored
	sort with t
	sort with y
	sort with x
	write thw output to thw file
   Repeat the process from red_in() for another test case until there is no more test case to test with in the input file.

   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:
   1. Test with different values of x, y and t.
   2. Test with the same integer value of x but different values of y and t.
   3. Test with the same integer value of x and y but different values of t.
   4. Test witch mixed values of x and y such that the test case contained both negative and positive numbers.
   5. Test with values that appear multiple time in diffferent test cases.
   - 

   The order of complexity
   -----------------------
   An inserion sort was utilized for this algorithm. Insertion sort has a worst case Big O of O(n^2). The sort function was called three times.
   The algorithm for this solution was implemented in 4 main steps: read, store, sort and write the data.
   Each of this four steps except the sort has a big O of O(n). Hence the Big O of the whole algorithm is going to be O(n^2).


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
   - Added int samplePoisson() to implement a Poisson distribution.	Mubarak Mikail 16/02/2019

*/
 
#include "assignment3Interface.h"
 
int main() {
	int arrival_rate_input, runtime, depature;		// the arrival rate in cars per minute
	int red, amber, green;
	double arrival_rate;	// the arrival rate in cars per millisecond
	long int increment;		// the period of each simulation interval in milliseconds
	int count;			// the number of cars that arrive in any given
						// simulation interval (i.e time increment)
	double lambda;		// the mean number of cars that arrive in any one
	int number_of_test_cases;
	int i, j, k, n, value;
	int debug = TRUE;

    FILE *fp_in, *fp_out;

    typedef char keyword[KEY_LENGTH];
	char input_string[STRING_LENGTH]; // a line read from the input file
	keyword key; // the key string when reading parameters

	keyword keylist[NUMBER_OF_KEYS] = {
			"arrival",
			"departure",
			"runtime",
			"increment",
			"red",
			"amber",
			"green"
	};

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
	fgets(input_string, STRING_LENGTH, fp_in); // read a line from the input file
		
	for(i = 1; i <= number_of_test_cases; i++)
	{
		for (k = 1; k <= 7; k++)
		{
			fgets(input_string, STRING_LENGTH, fp_in); // read a line from the input file

			/* extract the key */
			sscanf(input_string, " %s %d", key, &value); // extracts the key and the value from the string
	
			//printf("key-value: %s %d\n", key, value); // write it out to the terminal to check
	
			/* convert the key to lower case to be safe */
			for (j=0; j < (int) strlen(key); j++)
				key[j] = tolower(key[j]);
	
			for (j=0; j < NUMBER_OF_KEYS; j++) {
				if (strcmp(key,keylist[0]) == 0)
				/* use j to select the variable to which value should be assigned */
					arrival_rate_input = value;
				else if (strcmp(key,keylist[1]) == 0)
					depature = value;
				else if (strcmp(key,keylist[2]) == 0)
					runtime = value;
				else if (strcmp(key,keylist[3]) == 0)
					increment = value;
				else if (strcmp(key,keylist[4]) == 0)
					red = value;
				else if (strcmp(key,keylist[5]) == 0)
					amber = value;
				else if (strcmp(key,keylist[6]) == 0)
					green = value;
			

				//switch(j)
				//{
				//case 0 : arrival_rate_input = value;
				//	break;
				//case 1 : depature = value;
				//	break;
				//case 2 : runtime = value;
				//	break;
				//case 3 : increment = value;
				//	break;
				//}
			}

			printf("%s %d\n", key, value);
		}
		for (n = 0; n <= runtime * 60000; n += increment){
			/* example usage of samplePoisson */
			/* arrival_rate_input is in cars per minute so convert to cars per millisecond */
			arrival_rate = ((float) arrival_rate_input) / (60 * 1000);

			/* the Poisson distribution mean, lambda, is the arrival rate of cars during */
			/* the simulation interval, i.e. arrival rate per millisecond multiplied by */
			/* the number of milliseconds in each simulation interval */
			lambda = arrival_rate * increment;

			/* Compute the number of cars that have arrived in the current simulation interval */
			count = samplePoisson(lambda);
		}




		printf("Number of cars: %d\n", count);
		//fprintf(fp_out, "Number of cars: %d\n", count);
		fprintf(fp_out, "Arrival rate:   %d cars per min\n", arrival_rate_input);
		fprintf(fp_out, "Departure rate: %d s per car\n", depature);
		fprintf(fp_out, "Runtime:		%d min\n", runtime);
		fprintf(fp_out, "Time increment: %d ms\n", increment);
		fprintf(fp_out, "Light sequence: Green %d s; Amber %d s; Red %d s\n", green, amber, red);
		fprintf(fp_out, "Average length: %d cars\n", count);
		fprintf(fp_out, "Median length:  %d cars\n", count);
		fprintf(fp_out, "Maximum length: %d cars\n", count);
		fprintf(fp_out, "Average wait:   %d s\n", count);
		fprintf(fp_out, "Maximum wait:   %d s\n", count);
		fprintf(fp_out, "\n");
		printf("-----------------\n");

	}

   fclose(fp_in);
   fclose(fp_out);

    prompt_and_exit(0);
}
