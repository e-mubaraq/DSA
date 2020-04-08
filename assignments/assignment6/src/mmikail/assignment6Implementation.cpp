/* 

   assignment6Implementation.cpp - implementation file for a program named assignment6
   ===================================================================================

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
   01/04/2020+


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

#include "assignment6Interface.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}


void build_graph(graph *g, bool directed, int n, int r, FILE *fp_in) {
	int j, s_city, d_city, passengers;

	initialize_graph(g, directed);
	g->nvertices = n;

	if (g->nvertices != 0) {
		for (j = 0; j < r; j++) {
		   fscanf(fp_in, "%d %d %d", &s_city, &d_city, &passengers);
		   insert_edge(g, s_city, d_city, directed, passengers);
	   }
	}
}

/* delete an edge in a graph */
void delete_edge(graph *g, int v, int u, int w) {

	int x, capac;
	edgenode *p;
	edgenode *temp;
	p = g->edges[v];
	temp = p;

	if(p->y == u && p->weight == w) {
		g->edges[v] = p->next;
		free(p);
		g->nedges --;
	}
	else {
		while (p != NULL) {
			x = p->y;
			capac = p->weight;
			if (x == u && capac == w) {
				temp->next = p->next;
				free (p);
				g->nedges --;
			}
			else {
				temp = p;
				p = p->next;
			}
		}
	}
	print_graph(g);
}