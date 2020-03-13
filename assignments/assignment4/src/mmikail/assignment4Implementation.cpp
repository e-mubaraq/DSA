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

   - Added removePunct() to remove non-alpha numeric characters from a word.	Mubarak Mikail 04/03/2020
   - Added check() to check if an elemebt is in the tree. Mubarak Mikail 07/03/2020
   - Added getTreeHeight() to compute the height of a tree.	Mubarak Mikail 08/03/2020
   - Added max() to get the higher of two integers. Mubarak Mikail 08/03/2020
   - Added getAvg_number_of_probes() to compute the average number of probes for a treee.	Mubarak Mikail 10/03/2020
   - Added inorder_write() to write the statistics computed to the output file. 	Mubarak Mikail 10/03/2020
   - Added size() to compute the size of a tree. Mubarak Mikail 10/03/2020

*/

#include "assignment4Interface.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

void removePunt(char word[]) {
	int i, j = 0;
	char temp[MAX_STRING_LENGTH];
	for (i=0; i<strlen(word); i++) {
		if (isalnum(word[i]) || (word[i] == '-')  ) {
			temp[j] = word[i];
			j++;
		}
		else {
			if (word[i] == '\'') 
				i++;
		}
	}
	temp[j] = '\0';
	strcpy(word, temp);
}


bool check(ELEMENT_TYPE e, BINARY_TREE_TYPE tree) {

	if (tree != NULL) {
		if (strcmp(e.string, tree->element.string) < 0){
			check(e, (tree->left));
		}
		else if (strcmp(e.string, tree->element.string) > 0){
			check(e, (tree->right));
		}
		else{
			return true;
		}
	}  
	else{
		return false;
	}
}

int getTreeHeight(BINARY_TREE_TYPE tree) {
	if (tree != NULL) {
      return (1+ max(getTreeHeight(tree->left), getTreeHeight(tree->right)));  
    }
	return 0;
}

double getAvg_number_of_probes(BINARY_TREE_TYPE tree) {
	int i, height, total_num_of_probes = 0;
	double avg = 0.0;

	height = getTreeHeight(tree);
	for (i= 1; i <= height; i++)
		total_num_of_probes += i;
	avg = ((float)total_num_of_probes / height);

	return avg;
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
	   n = 15 - strlen(tree->element.string);	// n is number os spaces in the output file between the word and frequency
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
