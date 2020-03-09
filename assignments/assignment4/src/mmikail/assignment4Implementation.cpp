/* 

   assignment4Implementation.cpp - implementation file for a program named assignment4
   ===================================================================================

   This program is for Assignment No. 4, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - assignment4Application.cpp - for details of the functionality of this program


   File organization
   -----------------

   assignment4Interface.h           interface file:      
									contains the declarations required to use the functions that implement the solution to this problem
									typically, these will include the definitions of the abstract data types used in the implementation

   assignment4Implementation.cpp	implementation file: 
									contains the definitions of the functions that implement the algorithms used in the implementation
 
   assignment4Application.cpp		application file:    
									contains the code that instantiates the abstract data types and calls the associated functions
									in order to effect the required functionality for this application


   Author
   ------

   Mubarak Mikail, Carnegie Mellon University Africa
   03/03/2020


   Audit Trail
   -----------

   - Added swap() to swap an array element with another array element.	Mubarak Mikail 29/02/2020
   - Added insertion_sort() to implement insertion sort for sorting the queue lengths. Mubarak Mikail 29/02/2020

*/

#include "assignment4Interface.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}


int insertion_sort(int a[], int size) { // int a[]
	int i,j;
	
	for (i = 1; i < size; i++) {
		j = i;
		while ((a[j] < a[j-1]) &&  (j > 0)){
			/* swap */
			swap(a, j-1, j);
			j--;
		}
	}

   return (0);
}

void swap(int arr[], int i, int j) {
	int temp;

	temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}

void removePunt(char word[]) {
	unsigned int i, j;
	for (i=0; i<strlen(word); i++) {
		if (word[i] == '\'')
			word[i+1] = ' ';
		if (!isalnum(word[i]) && (word[i] != '-') && (word[i] != ' ') && (word[i] != '\n')) {
			for (j=i; j<strlen(word); j++) // copy the rest of the word overwriting the non-alphanumeric
				word[j] = word[j+1];
		}

	}
}

bool isCorrect(ELEMENT_TYPE e, BINARY_TREE_TYPE *tree) {
	//check if the element is in the dictionary
	if (strcmp(e.string, (*tree)->element.string) == 0) {
		return true;

	}
	else
		return false;
	//return 0;
}

int height(BINARY_TREE_TYPE tree) {
	if (tree != NULL) {
      return (1+ max(height(tree->left), height(tree->right)));  
    }
	return 0;
}

int avg_number_of_probes(BINARY_TREE_TYPE tree) {
	int num;

	return num;
}

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int inorder_write(BINARY_TREE_TYPE tree, FILE *fp_out) {

   if (tree != NULL) {
	   inorder_write(tree->left, fp_out);

	  fprintf(fp_out, "%s %d \n", tree->element.string, tree->element.frequency);

	  inorder_write(tree->right, fp_out);
   }
   return(0);
}
