/* 

  Implementation file

  Find the highest highest scoring Scrabble word from a set of seven Scrabble letters
  -----------------------------------------------------------------------------------

  Course 04-630 Data Structures and Algorithms for Engineers, Assignment 7

  This problem reduces to finding the optimal permutation of all subsets of the seven letters.


  David Vernon
  19 March 2019
*/
 
#include "scrabble.h"

/* original backtracking code ... needs to be adapted for the assignment */

void backtrack(int a[], int k, int input) {

   int c[MAXCANDIDATES];     /* candidates for next position  */
   int ncandidates;          /* next position candidate count */
   int i;                    /* counter                       */

   if (is_a_solution(a,k,input)) {
      process_solution(a,k,input);
   } 
   else {
      k = k+1;
      construct_candidates_permutation(a,k,input,c,&ncandidates); 
	  // construct_candidates_subset(a,k,input,c,&ncandidates); 
      for (i=0; i<ncandidates; i++) {
         a[k] = c[i];
         //make_move(a,k,input);
         backtrack(a,k,input);
         //unmake_move(a,k,input);
      }
   }
}



bool is_a_solution(int a[], int k, int n) {
   return (k == n);
}
 

void process_solution(int a[], int k, int input) {

   int i;                       /* counter */
   bool print_permuations;      /* flag ... set to true if you want the permutations listed to the terminal */

   print_permuations = false;

   if (print_permuations) {
	  for (i=1; i<=k; i++) {
         printf(" %d",a[i]);
      }
      printf("\n");
   }
}
 


void construct_candidates_subset(int a[], int k, int n, int c[], int *ncandidates) {
   c[0] = TRUE;
   c[1] = FALSE;
   *ncandidates = 2;
}


void construct_candidates_permutation(int a[], int k, int n, int c[], int *ncandidates) {

   int i;                       /* counter */
   bool in_perm[NMAX];          /* who is in the permutation? */
   for (i=1; i<NMAX; i++) {     /* NB: NMAX must be the number of elements in the permutation + 1 to allow for counting from 1, rather than 0 */
	   in_perm[i] = FALSE;
   }

   /* original Skiena code is incorrect ... a[i(==0)] is not a valid element of the permutation since we start storing them at a[1]

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