/* 

   assignment5Application.cpp - application file for a program named assignment5
   =============================================================================

   This program is for Assignment No. 5, Course 04-630 Data Structures and Algorithms for Engineers. 

   Robot Path Planning using Breadth-First Search in Undirected Unweighted Graphs.

   The functionality of the program is defined as follows.

   Read in the map whcih contains the two-dimensional array of numbers, each number representing the occupancy of a cell in the grid.
   The cells could have numbers 0,1,2,and 3.
		0 indicates that the cell is empty and the robot can occupy that cell when navigating to its goal.
		1 indicates that there is an obstacle in that cell and the robot cannot move into that cell when navigating to its goal.
		2 indicates the initial position of the robot.
		3 indicates the goal position of the robot.

	This problem was solved with a graph by implenting a graph and some graph functions.
	After reading in the map from the input file, I used a function to initialize a 2-d array thus using another function to construct a graph 
	from this 2-d array. The construct_graph function uses the insert_edge() function to insert edges between 2 similar cells in the map that 
	is a cell with a value of 0 can be connected to another cell with value 0 horizontally and vertically but not diagonally.

	After constructing the graph, the find_path_graph function was used to find a path between the start and end point of the robot,
	this path is marked and printed on another map in the output file.

   The output file will contain a map showing the robot path with an asterisk.

   Input data with the maps that will be used for testing is provided in an input file named input.txt.
   The first line is the number of scenarios/test cases we want to use to test. The remaining lines specify these scenarios.
   Each scenario has its first line giving the dimension n rows and m columns of the map.
   There then follow n lines, each line comprising m numbers. Each number is either a 0 designating an unoccupied cell, 1, a cell occupied 
   by an obstacle, 2, the start cell where the robot is located initially, and 3, the destination cell.

   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"


   Input
   -----

   - The input file contains maps which comprises a two-dimensional array of numbers, each number representing the occupancy of a cell in the grid.

   Output
   ------

   - Map showing the path from the robot's initial position to its end position with asterisks (*). The start position is marked by @,
   end position by $, obstacles by # and the remaining non-obsatacle cells by a space.
 
   Sample Input
   ------------
   
	2
	4 4
	2 0 0 0
	0 1 1 0
	0 0 0 0
	0 0 0 3
	10 10
	0 0 0 0 0 0 0 0 0 0
	0 2 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0
	0 0 0 1 1 1 1 1 1 0
	0 0 0 1 1 1 1 0 0 0
	0 0 0 1 1 1 1 0 0 0
	0 0 0 0 0 1 1 0 0 0
	0 1 1 1 0 0 0 0 0 0
	0 1 1 1 0 0 0 0 3 0
	0 0 0 0 0 0 0 0 0 0

   Sample Output
   -------------
	mmikail
	Scenario 1
	@       
	* # #   
	*       
	* * * $ 

	Scenario 2
                    
	@                 
	*                 
	*   # # # # # #   
	*   # # # #       
	*   # # # #       
	* * * * # #       
	# # # *           
	# # # * * * * $   
                  

   Solution Strategy
   -----------------

   The number of scenarios was read in and stored in a variable.
   A function was created to initialize a 2-d array for each scenario. Another function construct_graph was used to construct a graph from ths 2-d array.
   The construct_graph() function initializes a graph and then uses a function which implements a mapping function that maps coordinates to vertex.
   After constructing a graph of vertices, I used the insert_edge() function of graph to connect similar vertices. Thus, unoccupied cells can only be 
   connected to unoccupied cells and obstacle cells can only be connected to obstacle cells. While constructing the graph, I also ensured to insert edges
   between the initial position(2) and unoccupied cells(0). I did the same for the final position. This is important when I want to find the path between the start 
   and end position of the robot.
   I then used a find_path_graph() function to search for path between the initial and final position of the robot.
   The find_path_function is a rcursive function which does a breadth first search on the graph. If a path is found on the graph, the function marks that point
   in the map with a number (4) such that at the end of the path finding, the path has been marked with the number 4. Two funtion were implented to map
   a vertex back to its x and y coordinates respectively. This function was used to get the coordinates(indices) to be marked on the map.

   Another function was implemented to write the output map to file, this function was used to map the numbers showing the cell occupancy to certain characters.
	- An empty cell(0) is depicted by a space '  ' character
	- An obstacle(1) is depicted by '# ' character
	- The start position(2) of the robot is depicted by a '@ ' character
	- The destination position(3) of the robot is depicted by a '$ ' character
	- The path cells(4) are depicted by a '* ' character

	This function checks if there is a path and prints out the map showing the path in the output file. If there is no path, it prints out the map without the path
	and prints a message saying there is no path between the initial and final position of the robot. It also prints out the coordiantes of the two positions.

   Pseudocode
   ----------
   Declare necessary variables.
   Declare the graph and 2-d array that will be used for processing.
   read_in(number of scenarios from input file).
   for each scenario:
	   read_in(dimensions n,m of the input map  from the input file).
	   initialize a 2-d array and a graph
	   construct a graph from the map
	   get the start and end position of the robot in the map using the getVertex_from_coordinates() function
	   find a path between the start and end position(vertices) of the robot
	   if a path exists:	
			get the x and y coordinates of each of those vertices along the path
			mark those coordinates in the map
			write to file a map showing that path with the vertices represented as *
	   else
			write to file the map showing the characters 
			write to file a message that says there is no path between the initial and final position of the robot with their coordinates.

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

   assignment5Interface.h           interface file:      
									contains the declarations required to use the functions that implement the solution to this problem
									typically, these will include the definitions of the abstract data types used in the implementation
										
   assignment5Implementation.cpp	implementation file: 
									contains the definitions of the functions that implement the algorithms used in the implementation
 
   assignment5Application.cpp		application file:    
									contains the code that instantiates the abstract data types and calls the associated functions
									in order to effect the required functionality for this application


   Author
   ------

   Mubarak Mikail, Carnegie Mellon University Africa
   18/03/2020


   Audit Trail
   -----------

   - Added initialize_2D_array() to initialize a 2-d array.	Mubarak Mikail 20/03/2020
   - Added write_char_to_file() to print the chracter version of the map to screen. Mubarak Mikail 20/03/2020
   - Added getVertex_from_cellCoordinates() to compute the vertex number from its cell coordinates by using a mapping function.	Mubarak Mikail 23/03/2020
   - Added construct_graph_vertex() to construct a graph of vertex from a map of coordinates.	Mubarak Mikail 23/03/2020
   - Added construct_graph() to construct the graph.	Mubarak Mikail 25/03/2020
   - Added search_for_path() to find the path between the start and end points of the robot.	Mubarak Mikail 25/03/2020
   - Added getX_from_vertex() to compute the x coordinate from the vertex. Mubarak Mikail 25/03/2020
   - Added getY_from_vertex() to compute the y coordinate from the vertex. Mubarak Mikail 25/03/2020

*/
 
#include "assignment5Interface.h"

int main() {

   bool debug    = false; // print diagnostic information?
   graph g;
   bool directed = false;
   int i, number_of_scenarios;
   int n, m; // n refers to rows amd mt to columns
   
   int arr[MAX_N][MAX_M];
   FILE *fp_in;
   FILE *fp_out;


   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
      prompt_and_exit(1);
   }

   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
      prompt_and_exit(1);
   }

   fprintf(fp_out,"mmikail\n");
   /* read the number of scenarios from a file */
   fscanf(fp_in, "%d", &number_of_scenarios);

   for (i = 1; i <= number_of_scenarios; i++) {
	   fprintf(fp_out, "Scenario %d\n", i);
	   fscanf(fp_in, "%d %d", &n, &m);

	   construct_graph(&g, directed, fp_in, arr, n, m);
	   construct_graph_vertex(n, m);
	   write_char_to_file(fp_out, arr, n, m, &g);


	   fprintf(fp_out, "\n");
   }

   fclose(fp_in);
   fclose(fp_out);
}