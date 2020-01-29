/* 

   assignment1Implementation.cpp - implementation file for a program named assignment1
   ===================================================================================

   This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - assignment1Application.cpp - for details of the functionality of this program


   File organization
   -----------------

    assignment1Interface.h          interface file:      
									contains the declarations required to use the functions that implement the solution to this problem
									typically, these will include the definitions of the abstract data types used in the implementation

   assignment1Implementation.cpp	implementation file: 
									contains the definitions of the functions that implement the algorithms used in the implementation
 
   assignment1Application.cpp		application file:    
									contains the code that instantiates the abstract data types and calls the associated functions
									in order to effect the required functionality for this application


   Author
   ------

   Mubarak Mikail, Carnegie Mellon University Africa
   05/01/2019


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

 
#include "assignment1Interface.h"

static int id = 1;
void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {
 
   fprintf(fp,"The message is: %s\n", message);
}

int store_location(struct location_type location[], float t, int x, int y){
	int i;
	
	/* Check if the location already exists in the structure */
	for (i = 0; i < id; i++) {
		if ((x == location[i].x ) && (y == location[i].y)){
			return location[i].id_number;
		}		
	}

	location[i].t = t;
	location[i].x = x;
	location[i].y = y;
	location[i].id_number = id;
	id++;

	return(location[i].id_number); // eventually, return a unique location id. number
};

int reset_id(){
	id = 1;
	return id;
}
