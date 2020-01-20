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

main() {

   int i, num, n;
   char fname[50];
   FILE *i_fps, *o_fps;
   char *strings[ARRAY_SIZE];
   int debug = TRUE;
   char buffer[120]; /* maximum buffer size set to 120 */

   /* open input file */

   if ((i_fps = fopen("../data/quicksortStringsInput.txt", "r")) == NULL) {
      printf("Fatal error: cannot open input file\n");
   }
   else {
 
      /* read input file into an array */

      i = 0;
      while ((fgets(buffer, 120, i_fps) != NULL) && (i<ARRAY_SIZE)) {
         
         /* fgets also reads the new line so we remove it by overwriting it */
         /* with a '\0'                                                     */

         buffer[ strlen(buffer) - 1 ] = '\0';

         /* allocate space of the string in the array */
         /* and copy it                               */

         if ((strings[i] = (char *) malloc(strlen(buffer) + 1)) == NULL) {
            printf("error ... unable to allocate space for strings \n");
            exit(0);
         } 

         strcpy(strings[i], buffer);                               
        
         if (FALSE) printf("%s - %s\n", buffer, strings[i]);

         i++;
      }
      n = i;


      if (debug) {
         printf("Unsorted ");
         print_list_string(strings,0,n-1);
         printf("\n");
      }

      /* insert sentinel */

      strings[n] = "zzzzzzzzzzzzzz";

      quicksort(strings, 0, n);

      if (debug) {
         printf("Sorted ");
         print_list_string(strings,0,n-1);
         printf("\n");
      }


      /* write out sorted list */

      if ((o_fps = fopen("../data/quicksortStringsOutput.txt", "w")) == NULL) {
         printf("Fatal error: cannot open output file\n");
      }
      else {
         for (i=0; i<n; i++) {
            fprintf(o_fps, "%s\n", strings[i]);
         }

         fclose(i_fps);
         fclose(o_fps);

      }
   }

   printf("\npress any key to continue ... ");
   getch();
}
