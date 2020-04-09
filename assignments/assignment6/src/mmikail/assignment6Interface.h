/* 

   assignment6Interface.h - interface file for a program named assignment6
   =======================================================================

   This program is for Assignment No. 6, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - assignment6Application.cpp - for details of the functionality of this program

      
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

   - Added build_graph() to build weighted graph of roads between two cities.	Mubarak Mikail 03/04/2020
   - Added delete_edge() to delete an edge in a graph. Mubarak Mikail 08/04/2020
   - Added in_sort() to sort the edges of the graph by their weight.	Mubarak Mikail 08/04/2020
   - Added swapStruct() to swap structs.	Mubarak Mikail 08/04/2020
   - Added write_output_to_file() to write the computed outputs to file.	Mubarak Mikail 09/04/2020

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
struct edge_type {
	int v;	
	int y;
	int w;
};

void prompt_and_exit(int status);
void build_graph(graph *g, bool directed, int n, int r, FILE *fp_in, struct edge_type edges[]);
void delete_edge(graph *g, int v, int u, int w);
void in_sort(struct edge_type edges[], int n);
void swapStruct(struct edge_type edges[], int i , int j);
void write_output_to_file(FILE *fp_out, graph *g, int start, int dest, int num_of_tourists, int min_capacity);