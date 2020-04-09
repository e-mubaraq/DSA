/* 

   assignment6Application.cpp - application file for a program named assignment6
   =============================================================================

   This program is for Assignment No. 6, Course 04-630 Data Structures and Algorithms for Engineers. 

   Travel Planner Minimizing the number of scheduled buses needed to take tourists to their destination.

   The functionality of the program is defined as follows.

   Read in the input data from the input file.

	This problem was solved with a graph by implenting a graph and some graph functions.
	After reading in the map from the input file,a  function was used to build a graph and array of edges.
	The build_graph function uses the insert_edge() function to insert edges between 2 cities as given in the input file 
	and also build an array of edges.

	The array of edges was sorted by weight so that we can easily have access to the edge with the lowest weight when we start deleting edges.

	After constructing the graph, the find_path_graph function was used to find a path between the start and destination city such that
	while there is stil path, the edhe or road with the lowest capacity is deleted. This is done until there is no path and then the last
	deleted edge is inserted back into the graph so that we now have a path that maximizes the minimum capacity of the paths in the graph
	between those two cities.

	After the path is found, some computations will be done to get the minimum number of trips required to take those tourists 
	between the start and destination with the number of tourists per trip.

   The output file will contain certain statistics computed from finding the best route for transporting passengers between 2 cities.

   Input data with the test cases that will be used for testing is provided in an input file named input.txt.
   The first line of each scenario contains N & R representing the number of cities and the number of road segments, respectively. 
   The next R lines specify the roads between cities C1 and C2 with their maximum passenger capacity. 
   The (R + 1)th line will contain three integers (S, D, and T) representing, respectively, the starting city,
   the destination city, and the number of tourists to be guided.
   Each scenario has its first line giving the dimension n rows and m columns of the map.
   The input will end with zero values for N and R.

   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"


   Input
   -----

   - The input file contains data showing roads between two cities and the number of passengers the bus could take on a trip at once.

   Output
   ------

   - Minimum number of trips, number of tourists per trip and route.
 
   Sample Input
   ------------
   
	7 10
	1 2 30
	1 3 15
	1 4 10
	2 4 25
	2 5 60
	3 4 40
	3 6 20
	4 7 35
	5 7 20
	6 7 30
	1 7 99
	6 6
	1 2 30
	1 3 15
	2 4 20
	3 5 11
	4 6 10
	5 6 20
	1 6 49
	0 0

   Sample Output
   -------------
	mmikail
	Scenario 1
	Minimum Number of Trips = 5: 24 24 24 24 3
	Route = 1 2 4 7

	Scenario 2
	Minimum Number of Trips = 5: 10 10 10 10 9
	Route = 1 3 5 6               

   Solution Strategy
   -----------------

   The input data were read in accordingly stored in variables and a graph was built from them.
   A function was created to build the graph for each scenario. This function also builds an array of edges.
   Another function in_sort was used to sort the array of edges. A delete_edge() function was implemented to delete an edge frm the graph.
   
   After building the graph check that while there is still a path between the start and end cities, keep deleting the edge with minimum 
   capacity from the graph. When there is no path, insert the last deleted edge back into the graph and then find path again. This path is 
   our bottlneck shortest path that is the path that maximizes the minimum path between the two cities.

   Another function was implemented to write the output data to file.

	This function checks if there is a path and prints out the output statistics in the output file. If there is no path, it prints out
	a message saying there is no path between the two cities. It also prints out the cities numbers.

   Pseudocode
   ----------
   Declare necessary variables.
   Declare the graph and an array of eedges that will be used for processing.
   read_in(number of cities and roads)
   for each scenario that while n!=0 and r!=0:
	   write to file the scenario number
	   read_in(start and destination city with the number of tourists).
	   Build the graph from the input data.
	   Populate the array of edges and sort it by weight.
	   find a path between the start and destination cities from the graph.
	   if a path exists:	
			delete the edge with the minimum capacity
		repeat this check and delete until there is no path.

		insert the last deleted edge back into the graph
		find path again
		if a path exists:
			write to file the minimum number of trips, number of tourists per trip and route.
		else:
			write to file a message that says there is no path between the two cities.

	write to file a new line at the end of every scenario

   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:
   1. Test with a smaller dimension map.
   2. Test with a map that has a larger dimension.
   3. Test with a map that has no path between the initial and final position of the robot.
   4. Test with a map where the start and end position of the robot are adjacent to each other.
   5. Test with a medium dimension map.


   File organization
   -----------------

   assignment6Interface.h           interface file:      
									contains the declarations required to use the functions that implement the solution to this problem
									typically, these will include the definitions of the abstract data types used in the implementation
										
   assignment6Implementation.cpp	implementation file: 
									contains the definitions of the functions that implement the algorithms used in the implementation
 
   assignment6Application.cpp		application file:    
									contains the code that instantiates the abstract data types and calls the associated functions
									in order to effect the required functionality for this application


   Author
   ------

   Mubarak Mikail, Carnegie Mellon University Africa
   01/04/2020


   Audit Trail
   -----------

   - Added build_graph() to build weighted graoh of roads between two cities.	Mubarak Mikail 03/04/2020
   - Added delete_edge() to delete an edge in a graph. Mubarak Mikail 08/04/2020
   - Added in_sort() to sort the edges of the graph by their weight.	Mubarak Mikail 08/04/2020
   - Added swapStruct() to swap structs.	Mubarak Mikail 08/04/2020
   - Added write_output_to_file() to write the computed outputs to file.	Mubarak Mikail 09/04/2020

*/
 
#include "assignment6Interface.h"

int main() {

   bool debug    = false; // print diagnostic information?
   graph g;
   bool directed = false;
   int number_of_scenarios;
   int i, j, n, r;
   int start, dest, num_of_tourists;
   int min_capacity;
   
   FILE *fp_in;
   FILE *fp_out;

   struct edge_type edges [MAX_N];

   for (i = 0; i < MAX_N; i++) {
	   edges[i].v = 0;
	   edges[i].y = 0;
	   edges[i].w = 0;
   }

   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
      prompt_and_exit(1);
   }

   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
      prompt_and_exit(1);
   }

   fprintf(fp_out,"mmikail\n");

   number_of_scenarios = 1;
   fscanf(fp_in, "%d %d", &n, &r);

   while(n != 0 && r !=0) {
	   fprintf(fp_out, "Scenario %d\n", number_of_scenarios);
	   build_graph(&g, directed, n, r, fp_in, edges);
	   fscanf(fp_in, "%d %d %d", &start, &dest, &num_of_tourists);

	   j = 0;
	   while (find_path(&g, start, dest)) {
			delete_edge(&g, edges[j].v, edges[j].y, edges[j].w);
			j++;
	   }

	   if (j > 0) {
		   min_capacity = edges[j-1].w;
		   insert_edge(&g, edges[j-1].v, edges[j-1].y, directed, edges[j-1].w);
	   }

	   write_output_to_file(fp_out, &g, start, dest, num_of_tourists, min_capacity);

	   number_of_scenarios++;
	   fprintf(fp_out, "\n");
	   fscanf(fp_in, "%d %d", &n, &r);
   }

   fclose(fp_in);
   fclose(fp_out);

   //prompt_and_exit(1);
}