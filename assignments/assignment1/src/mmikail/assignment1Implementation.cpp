/* 

   exampleImplementation.cpp - implementation file for a program named example
   ============================================================================

   This program is for Assignment No. 0, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - exampleApplication.cpp - for details of the functionality of this program


   File organization
   -----------------

   example.h                  interface file:      
                              contains the declarations required to use the functions that implement the solution to this problem
                              typically, these will include the definitions of the abstract data types used in the implementation

   exampleImplementation.cpp  implementation file: 
                              contains the definitions of the functions that implement the algorithms used in the implementation
 
   exampleApplication.cpp     application file:    
                              contains the code that instantiates the abstract data types and calls the associated functions
                              in order to effect the required functionality for this application


   Author
   ------

   David Vernon, Carnegie Mellon University Africa
   05/01/2019


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

 
 
#include "assignment1Interface.h"


void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {
 
   fprintf(fp,"The message is: %s\n", message);
}

int store_location(struct location_type location[], float t, int x, int y){
	int i, id = 1;
	/* this is how you access fields in an array of structures */
	for (i=0; i<MAX_NUMBER_OF_POINTS; i++) {
		if ((location[i].x == x) && (location[i].y == y)){
			return id;
		}
		else{
			return id += 1;
		}
	}

	//return(id); // eventually, return a unique location id. number
};