/* 

   assignment4Interface.h - interface file for a program named assignment4
   =======================================================================

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
   - Added getTotal_number_of_probes() to get the total number of probes in a tree.	Mubarak Mikail 08/03/2020
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
#include "binaryTree.h"

#define TRUE 1
#define FALSE 0
#define MAX_STRING_LENGTH 80


/* function prototypes go here */


void prompt_and_exit(int status);
void removePunt(char word[]);
bool check(ELEMENT_TYPE e, BINARY_TREE_TYPE tree);
int getTreeHeight(BINARY_TREE_TYPE tree);
int max(int a, int b);
double getAvg_number_of_probes(BINARY_TREE_TYPE tree);
int inorder_write(BINARY_TREE_TYPE tree, FILE *fp_out, int level);
int size(BINARY_TREE_TYPE tree);
int getTotal_number_of_probes(BINARY_TREE_TYPE tree, int level);
