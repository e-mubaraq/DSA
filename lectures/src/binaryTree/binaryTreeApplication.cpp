/************************************************************************/
/*                                                                      */
/* Application file for a BINARY_TREE ADT                               */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/* 5/3/2017 Added function to initialize the tree                       */
/*                                                                      */
/************************************************************************/

#include "binaryTree.h"
 
/*** main driver routine ***/

int main() {

   ELEMENT_TYPE e;
   BINARY_TREE_TYPE tree;
   
   initialize(&tree);

   print(tree);

   assign_element_values(&e, 3, "...");
   insert(e, &tree);
   print(tree);
   
   assign_element_values(&e, 1, "+++");
   insert(e, &tree);
   print(tree);
   
   assign_element_values(&e, 5, "---");
   insert(e, &tree);
   print(tree);

   assign_element_values(&e, 2, ";;;");
   insert(e, &tree);
   print(tree);

   assign_element_values(&e, 4, "***");
   insert(e, &tree);
   print(tree);

   assign_element_values(&e, 6, "000");
   insert(e, &tree);
   print(tree);

   assign_element_values(&e, 3, "...");
   delete_element(e, &tree);
   print(tree);

   // keep the terminal open until the user hits return
   printf("Press <return> to finish"); 
   getchar();
}
