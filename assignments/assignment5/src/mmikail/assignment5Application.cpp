/* 

   assignment5Application.cpp - application file for a program named assignment5
   =============================================================================

   This program is for Assignment No. 5, Course 04-630 Data Structures and Algorithms for Engineers. 

   Robot Path Planning using Breadth-First Search in Undirected Unweighted Graphs.

   The functionality of the program is defined as follows.

   Read in the the words file which is the dictionary that contains all words and then read in the first testfile from the input file. 

   The Binary Search Tree(BST) ADT was  used in implementing this solution since, it has do with constructing 2 trees of words in the word file 
   and test file, by implementing the BST functions of getTreeHeight and size, we were able to compute the getTreeHeight and size of the BST respectively.

   The BST ADT insert function was used to keep track of the frequency of occurence of a word in a particular file when building the tree for that file.
   I implemented a inorder_write function which I used to write the words, their frequency and level to the output file. I was able to keep track of the
   level of each word in the tree uing this function. This function does an inorder traversal of the tree.

   The maximum number of probes was computed with the getHeight() function. It is a recursive function which basically
   returns 1 + the maximum of the heights of the left and right trees (1+ max(getTreeHeight(tree->left), getTreeHeight(tree->right))); 
   when the tree is not null, it the tree is null it return zero that is the tree is empty.

   The average number of probes was calculated using a function . 
   The final sum is the total maximum of probes in a tree, the average is gotten by dividing the total by the height of the tree.

   The output file will contain a set of data computed from the input text files we were given.

   Input data with the words file and textfiles that will be used for testing is provided in an input file named input.txt.
   The first line is the relative path of the words.txt file. It is followed by the location of the textfiles to be tested with, one line per textfiles.

   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"


   Input
   -----

   -  Dictionary file with words to build a dictionary and text files that contains sentences or words to be checked from the dictionary.

   Output
   ------

   - Statistics computed from the input textfiles.
 
   Sample Input
   ------------
   
	../data/words.txt
	../data/textfile1.txt
	../data/textfile2.txt

   Sample Output
   -------------
	mmikail
	../data/textfile1.txt
	My heart is in the work
	My heart is in the WIRK
	Maximum number of probes: 4
	Average number of probes: 2.5
	heart 2 (1)
	in 2 (3)
	is 2 (2)
	my 2 (0)
	the 2 (1)
	work 1 (2)
	--------------------
	../data/textfile2.txt
	heart in is My the work
	Maximum number of probes: 6
	Average number of probes: 3.5
	heart		1 (0)
	in			1 (1)
	is			1 (2)
	my			1 (3)
	the			1 (4)
	work		1 (5)
	--------------------

   Solution Strategy
   -----------------

   The input parameters were read in and stored in variables. 
   The maximum number of probes was computed with a getHeight() function. It is a recursive function which basically
   returns 1 + the maximum of the heights of the left and right trees that is (1+ max(getTreeHeight(tree->left), getTreeHeight(tree->right))); 
   when the tree is not null, if the tree is null it return zero that is the tree is empty.

   The average number of probes was calculated using a function getAvg_number_of_probes() which gets the total number of probes from 
   a getTotal_number_of_probes() function and divides it by the size of the tree using the size() function.
   
   The total number of probes was computed using a recursive funtion that takes the tree and an integer level as an argument, this function
   returns  level + 1 + getTotal_number_of_probes(tree ->left, level + 1) + getTotal_number_of_probes(tree ->right, level + 1) when the tree
   is not null, it return 0 when tree is empty(null). This is based on the algorithm that keys on the zeroth level have a probes of 1, 
   first level keys have 2, level 2 keys have a probe of 3. We take a sum of all the probes of keys in the tree.

   The size of the tree is basically the number of elements in the tree, this was computed with a recursive function that returns
   the sum of 1, size of left tree and size of the right tree as in (1+ size(tree->left) + size(tree->right)) when the tree is not null,
   if the tree is null it return zero that is the tree is empty.

   Declare necessary variables to store the input and output parameters.
   declare 2 trees, one for the dictionary and one for the texts.
   read_in(filenames).
   for each filename:
	   if it is the words file, 
			initialize and construct the dictionary
	   else it is a test file (files to check)
			Construct a proper word from each of the words in the file and check if it is in the dictionary.
			if it is in the dictionary
				Insert it into the text_tree
				write the original word to the output file
				write the word, its frequency of occurence and level to the output file
			else
				convert the word to capital letter and write it to the output file.
			write the statistics(Maximum and avergae number of probes) to the output file.


	write the output to the file

   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:
   1. Test with normal words.
   2. Test with repeated words in one file.
   3. Test with words that have multiple non-alphanumeric characters.
   4. Test with words that have hyphen.
   5. Test with words that have apostrophe and a character after it.
   - 

   The order of complexity
   -----------------------.
   The algorithm for this solution was implemented in 4 main steps: read, read, check and write the data.
   The check was done by searching the dictionary binary tree, searching a binary tree has a O(n) of O(logn)
   There is an outer read(loop) which houses another read this gives Big O of O(n^2). Read and write have a big O of O(n).
   Inserting into the binary tree has a complexity of O(logn).
   One of the writing was done by performing an inorder traversal of the binary tree (text_tree), this also has O(logn).
   Hence the Big O of the whole algorithm is going to be O(n^2).


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

   - Added removePunct() to remove non-alpha numeric characters from a word. Mubarak Mikail 04/03/2020
   - Added check() to check if an elemebt is in the tree. Mubarak Mikail 07/03/2020
   - Added getTreeHeight() to compute the height of a tree.	Mubarak Mikail 08/03/2020
   - Added max() to get the higher of two integers. Mubarak Mikail 08/03/2020
   - Added getTotal_number_of_probes() to get the total number of probes in a tree.	Mubarak Mikail 08/03/2020
   - Added getAvg_number_of_probes() to compute the average number of probes for a tree. Mubarak Mikail 10/03/2020
   - Added inorder_write() to write the statistics computed to the output file. Mubarak Mikail 10/03/2020
   - Added size() to compute the size of a tree. Mubarak Mikail 10/03/2020

*/
 
#include "assignment5Interface.h"

int main() {

   bool debug            = false; // print diagnostic information?
   bool input_dictionary = true;  // we begin by reading the dictionary
   int end_of_file, end_of_file2;
   int height, frequency = 1;
   double avg_num_of_probes = 0.0;
   char filename[MAX_STRING_LENGTH];
   char word[MAX_STRING_LENGTH];
   char original_word[MAX_STRING_LENGTH];
   unsigned int i;
   char ch;

   FILE *fp_in;
   FILE *fp_out;
   FILE *fp_in2;


   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
      prompt_and_exit(1);
   }

   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
      prompt_and_exit(1);
   }

   fprintf(fp_out,"mmikail\n");

   /* read the filenames from the input file */

   end_of_file = fscanf(fp_in, "%s", filename);  // read a filename
  
   while (end_of_file != EOF) {

      if (!input_dictionary) {
		  fprintf(fp_out,"%s\n",filename);
	  }

      /* open the target file: dictionary or text */

      if ((fp_in2 = fopen(filename,"r")) == 0) {  
	      printf("Error can't open text file %s\n",filename);
         prompt_and_exit(1);
      }

      end_of_file2 = fscanf(fp_in2, "%s", original_word);  // read a word from the file

	  /* check the whitespace character after the word to see if it is a newline */
      ch = getc(fp_in2);
	  if (ch == '\n') {
	     strcat(original_word,"\n"); // add a newline character so that subsequent text in on the next line
	  }
	  else {
		 strcat(original_word," ");  // add the whitespace
      }

	  
      while (end_of_file2 != EOF) {
             
		 strcpy(word,original_word); // make a copy of the word so that we can process it
		                             // but keep the original so that we can write it to the output file 

         /* convert to lower case */
		 
         for (i=0; i<strlen(word); i++) {
            word[i] = tolower(word[i]);
         }
		 


         fprintf (fp_out,"--------------------\n");
	  }

      fclose(fp_in2);

      end_of_file = fscanf(fp_in, "%s", filename); // read the next filename

	  input_dictionary = false; // the first file is the dictionary file; we've read it so now we reset this flag
   };


   fclose(fp_in);
   fclose(fp_out);
}