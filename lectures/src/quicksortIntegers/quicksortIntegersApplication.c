/************************************************************************/
/*                                                                      */
/* Application file for QuickSort of an array of integers               */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/* 29/1/2019                                                            */
/*                                                                      */
/************************************************************************/

#include "quicksortIntegers.h"

main() {

   int i, num, n;
   char fname[50];
   FILE *i_fpn, *o_fpn, *i_fps, *o_fps;
   int number[ARRAY_SIZE];
   int debug = TRUE;

   /* open input file */

   if ((i_fpn = fopen("../data/quicksortIntegersInput.txt", "r")) == NULL) {
      printf("Fatal error: cannot open input file\n");
   }
   else {
 
      /* read input file into an array */

      i = 0;
      while ((fscanf(i_fpn, "%d", &num) != EOF) && (i<ARRAY_SIZE)) {
         number[i] = num;
         i++;
      }
      n = i;


      if (debug) {
         printf("Unsorted ");
         print_list_int(number,0,n-1);
         printf("\n");
      }

      /* insert sentinel */
      number[n] = 99999;

      quicksort(number, 0, n);

      if (debug) {
         printf("Sorted ");
         print_list_int(number,0,n-1);
         printf("\n");
      }


      /* write out sorted list */

      if ((o_fpn = fopen("../data/quicksortIntegersOutput.txt", "w")) == NULL) {
         printf("Fatal error: cannot open output file\n");
      }
      else {
         for (i=0; i<n; i++) {
            fprintf(o_fpn, "%d ", number[i]);
         }

         fclose(i_fpn);
         fclose(o_fpn);

      }
   }

   printf("\npress any key to continue ... ");
   getch();
}
