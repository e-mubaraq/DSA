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
   01/04/2020


   Audit Trail
   -----------

   - Added build_graph() to build weighted graph of roads between two cities.	Mubarak Mikail 03/04/2020
   - Added delete_edge() to delete an edge in a graph. Mubarak Mikail 08/04/2020
   - Added in_sort() to sort the edges of the graph by their weight.	Mubarak Mikail 08/04/2020
   - Added swapStruct() to swap structs.	Mubarak Mikail 08/04/2020
   - Added write_output_to_file() to write the computed outputs to file.	Mubarak Mikail 09/04/2020

*/

#include "assignment6Interface.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}


void build_graph(graph *g, bool directed, int n, int r, FILE *fp_in, struct edge_type edges[]) {
	int j, s_city, d_city, passengers;

	initialize_graph(g, directed);
	g->nvertices = n;

	if (g->nvertices != 0) {
		for (j = 0; j < r; j++) {
		   fscanf(fp_in, "%d %d %d", &s_city, &d_city, &passengers);
		   insert_edge(g, s_city, d_city, directed, passengers - 1);
		   	edges[j].v = s_city;
			edges[j].y = d_city;
			edges[j].w = passengers - 1;
			edges[j+r].v = d_city;
			edges[j+r].y = s_city;
			edges[j+r].w = passengers - 1;
	    }
		in_sort(edges, r*2);
	}

	for (j = 0; j < r *2; j++)
		printf("%d %d %d\n", edges[j].v, edges[j].y, edges[j].w);
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
				p = temp;
				g->nedges --;
			}

			else {
				temp = p;
				p = p->next;
			}
		}
	}
}

void in_sort(struct edge_type edges[], int n){
	int i, j;

	for(i = 0; i < n-1; i++) {
		j = i;
		while((j >= 0) && (edges[j].w > edges[j + 1].w)){
			swapStruct(edges, j, j+1);
			j--;
		}
	}
}

void swapStruct(struct edge_type edges[], int i , int j){
	struct edge_type temp;

	temp = edges[j];
	edges[j] = edges[i];
	edges[i] = temp;
}

void write_output_to_file(FILE *fp_out, graph *g, int start, int dest, int num_of_tourists, int min_capacity) {
	int i, count_of_capac, rem;

	if (find_path_graph(g, start, dest)) {
		count_of_capac = num_of_tourists / min_capacity;
		rem = num_of_tourists % min_capacity;

		fprintf(fp_out, "Minimum Number of Trips = %d: ", count_of_capac+1);
		for (i = 0; i < count_of_capac; i++) {
			fprintf(fp_out, "%d ", min_capacity);
		}
		if (rem != 0)
			fprintf(fp_out, " %d\n", rem);
		else
			fprintf(fp_out, "\n");
		find_path(fp_out, g, start, dest);
		   
		fprintf(fp_out, "\n");
	}

	else
		fprintf(fp_out, "There is no route that can take passengers between cities %d and %d\n", start, dest);
}