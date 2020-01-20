/* 
 
  Application file 

  Driver to demonstrate some of the functionality of the graph adjacency list implementation.

  David Vernon
  20 March 2017

*/
 
#include "graph.h"
 
int main() {

   bool debug = false;

   graph g;
   bool directed = true;

   read_graph(&g, directed);       // build the graph interactivel
   
   print_graph(&g);                // print the graph to screen
    
   find_path(&g, 1, g.nvertices);  // find the path from vertex 1 to vertex n, where n is the last vertex in the graph
  
   prompt_and_exit(0);
}
