/* 

   assignment5Interface.h - interface file for a program named assignment5
   =======================================================================

   This program is for Assignment No. 5, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - assignment5Application.cpp - for details of the functionality of this program

      
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
   - Added max() to get the higher of two integers. Mubarak Mikail 08/03/2020
   - Added construct_graph_vertex() to construct a graph of vertex from a map of coordinates.	Mubarak Mikail 23/03/2020
   - Added construct_graph() to construct the graph.	Mubarak Mikail 25/03/2020
   - Added getAvg_number_of_probes() to compute the average number of probes for a treee.	Mubarak Mikail 10/03/2020
   - Added inorder_write() to write the statistics computed to the output file. 	Mubarak Mikail 10/03/2020
   - Added size() to compute the size of a tree. Mubarak Mikail 10/03/2020

*/
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "graph.h"

#define TRUE 1
#define FALSE 0
#define MAX_STRING_LENGTH 200
#define MAX_N 100
#define MAX_M 100


/* function prototypes go here */


void prompt_and_exit(int status);
int max(int a, int b);
void initialize_2D_array(FILE *fp_in, int arr[][MAX_M], int n, int m);
void write_char_to_file(FILE *fp_out, int arr[][MAX_M], int n, int m);
int getVertex_from_cellCoordinates(int x, int y, int column_size);
void construct_graph_vertex(int n, int m);
void construct_graph(graph *g, bool directed, FILE *fp_in, int arr[][MAX_M], int n, int m);
