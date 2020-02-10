/* 

   assignment2Implementation.cpp - implementation file for a program named assignment2
   ===================================================================================

   This program is for Assignment No. 2, Course 04-630 Data Structures and Algorithms for Engineers. 

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
   04/02/2019


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.
   - Added store_location() to return a unique id for each location the ants passed through.	Mubarak Mikail	21/01/2019.
   - Added reset_id() to reset the id to 1 at the end of every test case before processing another test case.	Mubarak Mikail 29/01/2019

*/

 
#include "assignment2Interface.h"

static int i = 0;		// id was declared static so that we can keep track of the changes to the variable.
void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {
	
   fprintf(fp,"The message is: %s\n", message);
}

int store_location(struct location_type location[], float t, int x, int y){

	int id = 0;
	/* Every location entry that doesn't exist already is added to the data structure*/
	location[i].t = t;
	location[i].x = x;
	location[i].y = y;
	
	id = i;
	i++;

	return (id);
};

void swap(location_type arr[], int i, int j){
	location_type temp;

	temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;

}
void swapStruct(struct location_type location[], int i , int j){
	struct location_type temp;

	temp = location[j];
	location[j] = location[i];
	location[i] = temp;
}

//void in_sort(struct location_type location[], int n){
//	int i, j;
//	for(i = 0; i < n-1; i++){
//		j = i;
//		while((j >= 0) && (location[j].x > location[j + 1].x)){
//			swapStruct(location, j, j+1);
//			j--;
//		}
//	}
//
//}

void in_sort(struct location_type location[], int n, int key){
	int i, j;
	for(i = 0; i < n-1; i++){
		j = i;

		if(key == 1)
		{

			while((j >= 0) && (location[j].t > location[j + 1].t)){
				swapStruct(location, j, j+1);
				j--;
			}
		}
		
		else if(key == 2)
		{

			while((j >= 0) && (location[j].x > location[j + 1].x)){
				swapStruct(location, j, j+1);
				j--;
			}
		}

		else if(key == 3)
		{

			while((j >= 0) && (location[j].y > location[j + 1].y)){
				swapStruct(location, j, j+1);
				j--;
			}
		}

	}

}

int reset_id(){
	i = 0;
	return i;
}
