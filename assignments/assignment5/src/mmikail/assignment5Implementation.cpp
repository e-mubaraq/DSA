/* 

   assignment5Implementation.cpp - implementation file for a program named assignment5
   ===================================================================================

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

   - Added removePunct() to remove non-alpha numeric characters from a word.	Mubarak Mikail 04/03/2020
   - Added check() to check if an elemebt is in the tree. Mubarak Mikail 07/03/2020
   - Added getTreeHeight() to compute the height of a tree.	Mubarak Mikail 08/03/2020
   - Added max() to get the higher of two integers. Mubarak Mikail 08/03/2020
   - Added getTotal_number_of_probes() to get the total number of probes in a tree.	Mubarak Mikail 08/03/2020
   - Added getAvg_number_of_probes() to compute the average number of probes for a tree.	Mubarak Mikail 10/03/2020
   - Added inorder_write() to write the statistics computed to the output file. Mubarak Mikail 10/03/2020
   - Added size() to compute the size of a tree. Mubarak Mikail 10/03/2020

*/

#include "assignment5Interface.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}


int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void initialize_2D_array(FILE *fp_in, int arr[][MAX_M], int n, int m) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			fscanf(fp_in, "%d", &arr[i][j]);
			//printf("%d ", arr[j][k]);
		}
		//printf("\n");
	}
}

void write_char_to_file(FILE *fp_out, int arr[][MAX_M], int n, int m) {
	 int j, k;
	 for (j = 0; j < n; j++) {
		   for (k = 0; k < m; k++) {
			   if (arr[j][k] == 0)
				   fprintf(fp_out, "  ");
			   else if (arr[j][k] == 1)
				   fprintf(fp_out, "# ");
			   else if (arr[j][k] == 2)
				   fprintf(fp_out, "@ ");
			   else if (arr[j][k] == 3)
				   fprintf(fp_out, "$ ");
		   }
		   fprintf(fp_out, "\n");
	   }

}

int getVertex_from_cellCoordinates(int x, int y, int column_size) {
	int vertex = 0;
	vertex = (column_size * x) + y + 1;

	return vertex;
}
void construct_graph_vertex(int n, int m) {
	int i, j, v;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			v = getVertex_from_cellCoordinates(i, j, m);
			printf("%d ", v);
		}
		printf("\n");
	}
}

void construct_graph(graph *g, bool directed, FILE *fp_in, int arr[][MAX_M], int n, int m) {
	int i,j, x, y;

	initialize_graph(g, directed);
	initialize_2D_array(fp_in, arr, n, m);
	g->nvertices = n * m;

	if (g->nvertices != 0) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (arr[i][j] == arr[i][j+1]) {
					x = getVertex_from_cellCoordinates(i, j, m);
					y = getVertex_from_cellCoordinates(i, j+1, m);
					insert_edge(g, x, y, directed, 0);
				}
			}
		}
		for (j = 0; j < m; j++) {
			for (i = 0; i < n - 1; i++) {
				if (arr[i][j] == arr[i+1][j]) {
					x = getVertex_from_cellCoordinates(i, j, m);
					y = getVertex_from_cellCoordinates(i+1, j, m);
					insert_edge(g, x, y, directed, 0);
				}
			}
		}

	}

}

