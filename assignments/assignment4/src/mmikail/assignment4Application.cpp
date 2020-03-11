/* 

   assignment4Application.cpp - application file for a program named assignment4
   =============================================================================

   This program is for Assignment No. 4, Course 04-630 Data Structures and Algorithms for Engineers. 

   Text Analysis using Binary Search Trees.

   The functionality of the program is defined as follows.

   Read in the the words file which is the dictionary that contains all words and then read in the first testfile from the input file. 

   The Binary Search Tree(BST) ADT was  used in implementing this solution since, it has do with constructing 2 trees of words in the word file 
   and test file, by implementing the BST functions of height and size, we were able to compute the height and size of the BST respectively.

   The output file will contain a set of data computed from the input text files we were given.

   Input data with the words file and textfiles that will be used for testing is provided in an input file named input.txt.
   The first line is the relative path of the words.txt file. It is followed by the location of the textfiles to be tested with, one line per textfiles.

   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"


   Input
   -----

   -  Dictionary file and text files that contains sentences or words to be checked from the dictionary.

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
	heart 1 (0)
	in 1 (1)
	is 1 (2)
	my 1 (3)
	the 1 (4)
	work 1 (5)
	--------------------

   Solution Strategy
   -----------------

   The input parameters were read in and stored in variables. The parameters were converted to the right units required for simulation.
   A function was implemented to saple a Poisson distribution, which was then used in our main program to simulate the number of cars
   that arrived at any interval during the runtime(in ms) given in the input file.
   A queue data structure with its enqueue and dequeue functions was implented to store the arrival time of cars and the number of cars that arrived.
   Cars were added to the queue based on the count of cars returned by the samplePoisson() function, the total numbers of cars that arrived
   was tracked. 
   
   Decalre variables to store the input parameters.
   read_in(all input parameters) for each testcase/simulation





	write the output to the file
   Repeat the process from read_in() for another test case until there is no more test case to test with in the input file.

   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:
   1. Test with different values of the input parameters.
   2. Test with input parameters such that the order of the parameters of the file is different from the previous.
   3. Test with a red_time_duration of 0 and a high green_time_duration
   4. Test with a green_time_duration of 0
   5. Test with a low green_time_duration and a high red_time_duration
   6. Test wih arrival rate of 0
   - 

   The order of complexity
   -----------------------
   An insertion sort was used to sort our queue outside the main simualation loop. Insertion sort has a worst case Big O of O(n^2). 
   The sort function was called three times.
   The algorithm for this solution was implemented in 4 main steps: read, simulate, sort and write the data.
   Read and write have a big O of O(n) but the simulation has a Big O of O(n^3). The simulation loop had an internal loop which 
   was used to add cars to the queue by using the queue function(enqeue). The enqueue function which also based on the LinkedList ADT
   implementation has a big O of O(n). Hence the Big O of the whole algorithm is going to be O(n^3).


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

   - Added swap() to swap an array element with another array element.	Mubarak Mikail 29/02/2019
   - Added insertion_sort() to implement insertion sort for sorting the queue lengths. Mubarak Mikail 29/02/2019

*/
 
#include "assignment4Interface.h"

int main() {

   bool debug            = false; // print diagnostic information?
   bool input_dictionary = true;  // we begin by reading the dictionary
   int end_of_file, end_of_file2;
   int frequency = 1;
   int max_num_of_probes = 0;
   double avg_num_of_probes = 0.0;
   char filename[MAX_STRING_LENGTH];
   char word[MAX_STRING_LENGTH];
   char original_word[MAX_STRING_LENGTH];
   unsigned int i;
   char ch;

   ELEMENT_TYPE e;
   BINARY_TREE_TYPE dictionary_tree;
   BINARY_TREE_TYPE text_tree;

   FILE *fp_in;
   FILE *fp_out;
   FILE *fp_in2;

   initialize(&dictionary_tree);
	initialize2(&text_tree);
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
		 
		 removePunt(word);
		 
         if (strlen(word) > 0) {

			if (input_dictionary) {
				
				/*** building the dictionary ***/
				assign_element_values(&e, frequency, word);
				insert(e, &dictionary_tree);
			}
			else {

			   /*** analyzing text ***/
				assign_element_values(&e, frequency, word);

				 if (check(e, dictionary_tree)) {
					 insert(e, &text_tree);
					 fprintf(fp_out, "%s", original_word);
				 }
				 else
				 {
					 for (i=0; i<strlen(original_word); i++)
						 original_word[i] = toupper(original_word[i]);
					 fprintf(fp_out, "%s", original_word);
				 }
				 
			}
         }
  
         end_of_file2 = fscanf(fp_in2, "%s", original_word);
		      
	     /* check the whitespace character to see if it is a newline */
         ch = getc(fp_in2);
	     if (ch == '\n') {
	        strcat(original_word,"\n");  // add the newline
	     }
		 else {

			 strcat(original_word," ");  // add the whitespace
		 }
      }

	  if (!input_dictionary) {
		 fprintf(fp_out, "\nMaximum number of probes: %d\n", height(text_tree));
         fprintf(fp_out, "Average number of probes: %3.1f\n", avg_num_of_probes);
		 inorder_write(text_tree, fp_out);
         fprintf (fp_out,"--------------------\n");
	  }

      fclose(fp_in2);

      end_of_file = fscanf(fp_in, "%s", filename); // read the next filename
	  initialize2(&text_tree);
	  input_dictionary = false; // the first file is the dictionary file; we've read it so now we reset this flag
   };


   fclose(fp_in);
   fclose(fp_out);

   prompt_and_exit(1);
}