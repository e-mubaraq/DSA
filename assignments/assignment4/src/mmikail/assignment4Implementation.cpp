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
	int i, j = 0;
	char temp[MAX_STRING_LENGTH];
	for (i=0; i<strlen(word); i++) {
		if (isalnum(word[i]) || (word[i] == '-')  ) {
			temp[j] = word[i];
			j++;
		}
		else
			if (word[i] == '\'') 
				i++;

	}
	temp[j] = '\0';
	strcpy(word, temp);
}



bool check(ELEMENT_TYPE e, BINARY_TREE_TYPE tree) {

	if (tree != NULL) {
		if (strcmp(e.string, tree->element.string) < 0){
			//printf("Okay_passed - %s _ %s\n", e.string, tree->element.string);
			check(e, (tree->left));
		}
		else if (strcmp(e.string, tree->element.string) > 0){
			//printf("Okay_passed2 - %s _ %s\n", e.string, tree->element.string);
			check(e, (tree->right));
		}
		else{
			//printf("Found - %s _ %s\n", e.string, tree->element.string);
			return true;
		}
	}  
	else{
		//printf("Nope\n");
		return false;
	}
}

int getTreeHeight(BINARY_TREE_TYPE tree) {
	if (tree != NULL) {
      return (1+ max(getTreeHeight(tree->left), getTreeHeight(tree->right)));  
    }
	return 0;
}

int avg_number_of_probes(BINARY_TREE_TYPE tree) {
	int num = 0;

	return num;
}

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int inorder_write(BINARY_TREE_TYPE tree, FILE *fp_out, int level) {
	int i, n;

   if (tree != NULL) {
	   n = 15 - strlen(tree->element.string);
		inorder_write(tree->left, fp_out, level + 1);

		fprintf(fp_out, "%s", tree->element.string);
		for (i=0; i<n; i++) fprintf(fp_out, " ");

		fprintf(fp_out, "%d (%d)\n", tree->element.frequency, level);

		inorder_write(tree->right, fp_out, level + 1);
   }
   return(0);
}

int size(BINARY_TREE_TYPE tree) {
	if (tree != NULL) {
		return (1+ size(tree->left) + size(tree->right));
	}
	return (0);
}
