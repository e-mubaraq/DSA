/************************************************************************/
/*                                                                      */
/* Interface file for QuickSort of an array of strings                  */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/* 29/1/2019                                                            */
/*                                                                      */
/************************************************************************/

#include "quicksortStrings.h"

/*** simple quick sort ***/

int quicksort(char * a[], int l, int r) {

   int        print_calls = TRUE; // FALSE;
   static int depth_of_recursion = 0;
   int        i, j, pivot;
   int        temp;
   int        debug = FALSE;

   depth_of_recursion++;

   if (print_calls==TRUE) {
      for (i=1; i<depth_of_recursion; i++) {
		 printf("   ");
	 }
	 printf("quicksort(%d, %d);\n", l, r);
   }

   /* assume a[r] contains a string > any element,   */
   /* i.e., it is a sentinel.                        */

   if (debug) printf("l, r = %d %d\n", l, r);
   if (debug) print_list_string(a, l, r);

   if (r > l) {
      i = l; j = r; 

      pivot = a[l];

      do {

         while (strcmp(a[i],pivot) <= 0)
            i = i+1;

         while ((j>l) && (strcmp(a[j],pivot) >= 0))
            j = j-1;
              
         if (i < j) 
            exchange_string(a,i,j);  /* between partitions */

      } while (i <= j);    

      exchange_string(a,l,j);        /* reposition pivot   */

      quicksort(a, l, j);

      quicksort(a, i, r); /* includes sentinel */

   }

   if (debug) print_list_string(a, l, r);
   
   depth_of_recursion--;
}


/*** exchange two strings ***/

int exchange_string(char * a[], int i, int j) {

   char * temp;

   temp = a[j];
   a[j] = a[i];
   a[i] = temp;

}

/*** print a list ***/


int print_list_string(char * a[], int l, int r) {

   int i;

   printf("List:\n");
   for (i=l; i<=r; i++) {
      printf("%s \n", a[i]);
   } 
   printf("\n");
}

