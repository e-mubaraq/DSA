/* 

   travellingSalesmanImplementation.cpp - application file for the solution of the travelling salesman problem by exhaustive search using backtracking

   04-630 Data Structures and Algorithms for Engineers Assignment No. 7

   The backtracking code is based on the examples in S. Skiena, The Algorithm Design Manual, 2008.
   David Vernon
   16 April 2018

   Mubarak Mikail
   17 April 2020

   Audit Trail
   -----------
   - Added backtrack_dist() to backtrack the distances.	Mubarak Mikail 20/04/2020
   - Added computeDistance() to calculate distance of a given permutation. Mubarak Mikail 20/04/2020
   - Added process_solution() to process each permutation.	Mubarak Mikail 20/04/2020
   - Added write_output_to_file() to write the computed outputs to file.	Mubarak Mikail 22/04/2020

*/
 
#include "travellingSalesman.h"

/* original backtracking code ... needs to be adapted for the assignment */

int min_distance = INT_MAX;
int min_array[NMAX+1];
void backtrack(int a[], int k, int input) {

   int c[MAXCANDIDATES];     /* candidates for next position  */
   int ncandidates;          /* next position candidate count */
   int i;                    /* counter                       */

   if (is_a_solution(a,k,input)) {
      process_solution(a,k,input);
   } 
   else {
      k = k+1;
      construct_candidates(a,k,input,c,&ncandidates); 
      for (i=0; i<ncandidates; i++) {
         a[k] = c[i];
         //make_move(a,k,input);
         backtrack(a,k,input);
         //unmake_move(a,k,input);
      }
   }
}

void backtrack_dist(int distances[][NUMBER_OF_STOPS], int a[], int k, int input) {

   int c[MAXCANDIDATES];     /* candidates for next position  */
   int ncandidates;          /* next position candidate count */
   int i;                    /* counter                       */

   if (is_a_solution(a,k,input)) {
	   process_solution(a,k,input, distances);
   } 
   else {
      k = k+1;
      construct_candidates(a,k,input,c,&ncandidates); 
      for (i=0; i<ncandidates; i++) {
         a[k] = c[i];
		 backtrack_dist(distances, a, k, input);
      }
   }
}


bool is_a_solution(int a[], int k, int n) {
   return (k == n);
}
 

void process_solution(int a[], int k, int input) {

   int i;                       /* counter */
   bool print_permuations;      /* flag ... set to true if you want the permutations listed to the terminal */

   print_permuations = true;    /* set to true if you want the permutations printed to the terminal; false otherwise */

   if (print_permuations) {
	  for (i=1; i<=k; i++) {
         printf(" %d",a[i]);
      }
      printf("\n");
   }

}

void process_solution(int a[], int k, int input, int distances[][NUMBER_OF_STOPS]) {

   int i, distance;                       /* counter */
   bool print_permuations;      /* flag ... set to true if you want the permutations listed to the terminal */

   print_permuations = true;    /* set to true if you want the permutations printed to the terminal; false otherwise */

   if (print_permuations) {
	  for (i=1; i<=k; i++) {
         printf(" %d",a[i]);
      }
      printf("\n");
   }

   distance = computeDistance(distances, a, k);
   printf("DISTANCE: %3d\n", distance);
   
   if (distance < min_distance) {
	   min_distance = distance;
	   for (i=1; i<=k; i++) {
			min_array[i-1] = a[i];
			//printf(" %d",min_array[i]);
      }
   }
   printf("minimum distance: %3d\n", min_distance);
}
 

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {

   int i;                       /* counter */
   bool in_perm[NMAX];          /* who is in the permutation? */
   for (i=1; i<NMAX; i++) {     /* NB: NMAX must be the number of elements in the permutation + 1 to allow for counting from 1, rather than 0 */
	   in_perm[i] = FALSE;
   }

   /* the original Skiena code is incorrect ... a[i(==0)] is not a valid element of the permutation since we start storing them at a[1]

      for (i=0; i<k; i++) in_perm[ a[i] ] = TRUE;

   */

   for (i=1; i<k; i++) in_perm[ a[i] ] = TRUE; // we are finding candidates for a_k, a_k+1, ... a_n
                                               // when k == 1, all candidates are valid because we haven't selected any yet
                                               // when k == 2, all candidates except a_1 are valid
                                               // when k == n, all candidates except a_1 .. a_n-1 are valid
   *ncandidates = 0;
   for (i=1; i<=n; i++) {
      if (in_perm[i] == FALSE) {
         c[ *ncandidates] = i;
         *ncandidates = *ncandidates + 1;
      }
   }
}
 

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

void remove_new_line(char string[]) {
   int i;

   i=0;
   while(string[i] != '\0' && string[i] != '\n')
      i++;
   string[i] = '\0';
}

int computeDistance(int distances[][NUMBER_OF_STOPS], int a[], int n) {
	int i, totalDist = 0;
	int p, q, r;

	totalDist = totalDist + distances[n][a[1] - 1];
	for (i = 1; i < n; i++) {
		p = a[i] - 1;
		r = i + 1;
		q = a[r] - 1;

		totalDist = totalDist + distances[p][q];
		if (totalDist > min_distance)
			return min_distance;
	}
	p = a[i] - 1;
	totalDist = totalDist + distances[p][n];
	if (totalDist > min_distance)
			return min_distance;

	return totalDist;
}

void write_output_to_file(FILE *fp_out, int k, struct record_type record[]) {
	int i, key;
	fprintf(fp_out, "%d\n",min_distance);
	fprintf(fp_out, "%s\n",record[k].string);
	for (i=0; i<k; i++) {
		key = min_array[i];
		//fprintf(fp_out, "%d ",key);
		fprintf(fp_out, "%s\n",record[key - 1].string);
    } 
	fprintf(fp_out, "%s\n",record[k].string);
}
