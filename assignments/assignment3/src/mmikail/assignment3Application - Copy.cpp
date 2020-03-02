/* 

   assignment3Application.cpp - application file for a program named assignment3
   =============================================================================

   This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 

   Simulation of Queueing Behaviour at Traffic Lights.

   The functionality of the program is defined as follows.

   Read in the sets of seven simulation parameters: arrival rate, departure rate, running time, time increment, red light duration, amber light
   duration and green light duration from the input file. Ensure they are or converted to the correct units to be used for the simulation.

   Because this problem is a probabilistic problem, we modelled it using Poisson distribution by writing a function that uses the arrival_rate 
   of a car to simulate the number of cars that arrive at every interval of our simulation. 

   The Queue ADT was also used in implementing this solution since, it has do with cars arriving and leaving a traffic light, by implementing 
   the queue functions of enqueue and dequeue, we were able to add and remove a car from the back and the front of the queue respectively.

   The output file will contain a set of statistical data computed from the input parameters we were given.

   Input data with the total number of test cases is provided in an input file named input.txt.
   The first line is the number of testcases or simulation scenarios. It is followed by N sets of seven key-value pairs, each pair specifying the 
   input parameter and its value. The key-value pairs can appear in any order. There will be only one key-value pair for each parameter.

   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"


   Input
   -----

   -  N sets of seven key-value pairs, each pair specifying the input parameter and its value. .

   Output
   ------

   - Statistics computed from the input parameeters.
 
   Sample Input
   ------------
   
	2
	Arrival 10
	Departure 5
	Runtime 5
	Increment 10
	Green 10
	Amber 1
	Red 30
	Runtime 5
	Arrival 20
	Departure 2
	Increment 100
	Red 15
	Green 5
	Amber 1

   Sample Output
   -------------
	mmikail
	Arrival rate:   10 cars per min
	Departure rate: 5 s per car
	Runtime:		5 min
	Time increment: 10 ms
	Light sequence: Green 10 s; Amber 1 s; Red 30 s
	Average length: 17 cars
	Median length:  15 cars
	Maximum length: 41 cars
	Average wait:   115 s
	Maximum wait:   299 s

	Arrival rate:   20 cars per min
	Departure rate: 2 s per car
	Runtime:		5 min
	Time increment: 100 ms
	Light sequence: Green 5 s; Amber 1 s; Red 15 s
	Average length: 20 cars
	Median length:  16 cars
	Maximum length: 109 cars
	Average wait:   113 s
	Maximum wait:   299 s
	--------------

   Solution Strategy
   -----------------

   The input parameters were read in and stored in variables. The parameters were converted to the right units required for simulation.
   A function was implemented to saple a Poisson distribution, which was then used in our main program to simulate the number of cars
   that arrived at any interval during the runtime(in ms) given in the input file.
   A queue data structure with its enqueue and dequeue functions was implented to store the arrival time of cars and the number of cars that arrived.
   Cars were added to the queue based on the count of cars returned by the samplePoisson() function, the total numbers of cars that arrived
   was tracked. 
   
   Certain conditions were also checked by using a depature timer to see if a car can leave and then call the dequeue() function to remove a car from the queue. 
   The waiting time of the car that was dequeued was noted which is the difference between the current simulation time and the arrival time
   of the car as gotten from the queue element. The total of the waiting time was also kept track of. Everytime a car is dequeued or enqueued, a
   counter (queue_length) was decremented or incremented so as to be able to keep track of the queue length during any simulation period.
   
   The queue length for each interval is stored in an array, so that I can be able to find the median queue length that will be 
   written to the output file. In getting the maximum queue legth, the current queue length is compared with the maximum queue length, if it is greater,
   it is used to replace the maximum queue length. The current queue length is added to a running total of the queue length, this will be used to
   compute the average queue length for that simulation.

   A light timer was also kept to check the times when the light is supposed to change colors and effect the change. Initial state of the light is red.
   The timer is reset to zero after every change of state. 

   Aftert the simualtion, the queue was checked to see if there are no cars waiting(that is still in the queue). If the queue is not empty, all the cars 
   left on the queue are dequeued while keeping track of their waiting time and adding it to the running total.


   Decalre variables to store the input parameters.
   read_in(all input parameters) for each testcase/simulation
   Loop through the simulation period:
		call the samplePoisson() function
		Loop through the returned value(count) of the samplePoisson() function
			enqueue(e, list)
			increment the queue length
		increment the total_number_of_cars by count
		Check if the depature_timer is greater than the depature_time per car and the light is green:
			dequeue(list)
			decrement the queue length
			compute the waiting time of each of the car dequeued (wait_time = current time - arrival time stored in the queue)
			add this waiting time to the running total of waiting time.
			check if the current wait time is greater than the maximum wait time, replace it.
			reset the depature_timer to zero
		store the current queue length in an array and increment the number of queue length by 1
		check if the current queue length is greater than the maximum queue length, replace it.
		increment the total queue length by queue length
		check the light state and light timer to be able to change the state of the light
		if light is green and the light timer > than green duration:
			set light to amber and reset light timer
		if light is amber and the light timer > than amber duration:
			set light to red and reset light timer
		if light is red and the light timer > than red duration:
			set light to amber and reset light timer and depature timer
	check if there are cars left on the queue:
		dequeue them and compute waiting time
		add this waiting time to the running total of waiting time.
	Compute the required statistics to be written to the output file.
		avg_wait_time = total_wait_time / total_number_of_cars;
		avg_queue_length = total_queue_length / num_of_queue_length;

		sort the array of queue length in order to find the median queue length which is the middle element in the array
		if ((num_of_queue_length % 2) != 0)
		median_queue_length = qu_lengths[(num_of_queue_length / 2) + 1];
		else 
		median_queue_length = (qu_lengths[num_of_queue_length / 2] + qu_lengths[(num_of_queue_length / 2) + 1]) / 2;

	write the output to the file
   Repeat the process from read_in() for another test case until there is no more test case to test with in the input file.

   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:
   1. Test with different values of the input parameters.
   2. Test with input parameters such that the order of the parameters of the file is different from the previous.
   3. Test with a red_time_duration of 0 and a high green_time_duration
   4. Test with a green_time_duration of 0
   5. Test with a low green_time_duration and a high red_time_duration
   6. Test with a runtime of 0
   - 

   The order of complexity
   -----------------------
   An insertion sort was used to sort our queue outside the main simualation loop. Insertion sort has a worst case Big O of O(n^2). 
   The sort function was called three times.
   The algorithm for this solution was implemented in 4 main steps: read, simulate, sort and write the data.
   Read and write have a big O of O(n) but the simulation has a Big O of O(n^3). The simulation loop had an internal loop which 
   was used to add cars to the queue by using the queue function(enqeue). The enqueue function which also based on the LinkedList ADT
   implementation has a big O of O(n). Hence the Big O of the whole algorithm is going to be O(n^3).


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


int main() {
	int arrival_rate_input   = 0;  // cars per minute
	int departure_time_input = 0;  // second per car
	int runtime_input        = 0;  // minutes
	int red_duration_input   = 0;  // seconds
	int green_duration_input = 0;  // seconds
	int amber_duration_input = 0;  // seconds
	long int increment       = 0;  // the period of each simulation interval in milliseconds


	double arrival_rate      = 0;  // cars per millisecond
	long int departure_time  = 0;  // milliseconds per car
	long int runtime         = 0;  // milliseconds
	long int red_duration    = 0;  // millisecond
	long int green_duration  = 0;  // milliseconds
	long int amber_duration  = 0;  // milliseconds
	long int wait_time		 = 0;
	long int total_wait_time = 0;
	long int arrival_time	 = 0;
	int max_wait_time		 = 0;	// Maximum wait
	int avg_wait_time		 = 0;	// Average wait
	int queue_length		 = 0;
	int total_queue_length	 = 0;
	int max_queue_length	 = 0;	// Maximum queue length
	int avg_queue_length	 = 0;	// Average queue length
	int median_queue_length	 = 0;
	int num_of_queue_length	 = 0;


	int count;			// the number of cars that arrive in any given
						// simulation interval (i.e time increment)
	int total_number_of_cars = 0; //total numbers of car that have arrived so far during the simulation
	double lambda;		// the mean number of cars that arrive in any one
	int number_of_test_cases;
	int i, j, k, m, value;
	long int n;
	int debug = TRUE;
	int qu_lengths[60000];

	long int depature_timer, light_timer;
	char* colour;

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

	ELEMENT_TYPE e, deq_element;
	LIST_TYPE list;

	initialize_list(&list);
	empty(&list);

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
	//fgets(input_string, STRING_LENGTH, fp_in); // read a line from the input file
		
	for(i = 1; i <= number_of_test_cases; i++)
	{
		
		for (k = 1; k <= 7; k++)
		{
			fgets(input_string, STRING_LENGTH, fp_in); // read a line from the input file
			/* extract the key */
			sscanf(input_string, " %s %d", key, &value); // extracts the key and the value from the string
	
			/* convert the key to lower case to be safe */
			for (j=0; j < (int) strlen(key); j++)
				key[j] = tolower(key[j]);
	
			for (j=0; j < NUMBER_OF_KEYS; j++) {
				if (strcmp(key,keylist[0]) == 0)
				/* use j to select the variable to which value should be assigned */
					arrival_rate_input = value;
				else if (strcmp(key,keylist[1]) == 0)
					departure_time_input = value;
				else if (strcmp(key,keylist[2]) == 0)
					runtime_input = value;
				else if (strcmp(key,keylist[3]) == 0)
					increment = value;
				else if (strcmp(key,keylist[4]) == 0)
					red_duration_input = value;
				else if (strcmp(key,keylist[5]) == 0)
					amber_duration_input = value;
				else if (strcmp(key,keylist[6]) == 0)
					green_duration_input = value;
			}

		}
		/* arrival_rate_input is in cars per minute so convert to cars per millisecond */
		arrival_rate = ((float)arrival_rate_input) / (60 * 1000);
		/* depature_time_input is in seconds per car, so convert to millisecond per car */
		departure_time = departure_time_input * 1000;
		/* Convert all the light durations from seconds to millisecond*/
		red_duration = red_duration_input * 1000;
		amber_duration = amber_duration_input * 1000;
		green_duration = green_duration_input * 1000;
		
		runtime = runtime_input * 60000; //runtime_input is in minute so convert to millisecond
		
		depature_timer = 0;
		light_timer = 0;
		colour = "Red";

		for (n = 0; n < runtime; n += increment) {
			/* the Poisson distribution mean, lambda, is the arrival rate of cars during */
			/* the simulation interval, i.e. arrival rate per millisecond multiplied by */
			/* the number of milliseconds in each simulation interval */
			lambda = arrival_rate * increment;
			/* Compute the number of cars that have arrived in the current simulation interval */
			count = samplePoisson(lambda);
			light_timer += increment;

			for (m = 0; m < count; m++) {	//Loop to enqueue cars that arrived during this simulation interval
				assign_element_values(&e, n, 1);
				enqueue(e, list);
				queue_length++;
			}		
			total_number_of_cars += count;

			depature_timer += increment;
			if (depature_timer > departure_time && strcmp(colour, "Green") == 0 && !is_empty(&list)) {
				deq_element = dequeue(list);
				
				wait_time = n - deq_element.arrival_time;	// n is the current simulation time
				total_wait_time += wait_time;
				if (wait_time > max_wait_time)
					max_wait_time = wait_time;
				depature_timer = 0;
				queue_length--;
			}

			qu_lengths[num_of_queue_length] = queue_length;
			num_of_queue_length++;
			
			if (queue_length > max_queue_length)
				max_queue_length = queue_length;
			total_queue_length += queue_length;		

			if (strcmp(colour, "Green") == 0 && light_timer > green_duration){
				colour = "Amber";
				light_timer = 0;
			}
			else if (strcmp(colour, "Amber") == 0 && light_timer > amber_duration){
				colour = "Red";
				light_timer = 0;
			}
			else if (strcmp(colour, "Red") == 0 && light_timer > red_duration){
				colour = "Green";
				light_timer = 0;
				depature_timer = 0;
			}
		}
		while(!is_empty(&list)){
			deq_element = dequeue(list);
				
			wait_time = n - deq_element.arrival_time;
			total_wait_time += wait_time;
			if (wait_time > max_wait_time)
				max_wait_time = wait_time;
		}
		
		avg_wait_time = total_wait_time / total_number_of_cars;
		avg_queue_length = total_queue_length / num_of_queue_length;

		insertion_sort(qu_lengths, num_of_queue_length);
		if ((num_of_queue_length % 2) != 0)
			median_queue_length = qu_lengths[(num_of_queue_length / 2) + 1];
		else 
			median_queue_length = (qu_lengths[num_of_queue_length / 2] + qu_lengths[(num_of_queue_length / 2) + 1]) / 2;

		fprintf(fp_out, "Arrival rate:   %d cars per min\n", arrival_rate_input);
		fprintf(fp_out, "Departure rate: %d s per car\n", departure_time_input);
		fprintf(fp_out, "Runtime:		%d min\n", runtime_input);
		fprintf(fp_out, "Time increment: %d ms\n", increment);
		fprintf(fp_out, "Light sequence: Green %d s; Amber %d s; Red %d s\n", green_duration_input, amber_duration_input, red_duration_input);
		fprintf(fp_out, "Average length: %d cars\n", avg_queue_length);
		fprintf(fp_out, "Median length:  %d cars\n", median_queue_length);
		fprintf(fp_out, "Maximum length: %d cars\n", max_queue_length);
		fprintf(fp_out, "Average wait:   %d s\n", avg_wait_time / 1000);
		fprintf(fp_out, "Maximum wait:   %d s\n", max_wait_time / 1000);
		fprintf(fp_out, "\n");

	}

   fclose(fp_in);
   fclose(fp_out);

}
