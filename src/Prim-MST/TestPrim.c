#include <stdlib.h>
#include <stdio.h>
#include <Input.h>
#include <Prim.h>

int main (int argc,char* argv[])
{
  Input in=open_TSP_file(argv[1]);
  Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
  double acc=0;
  Prim(g,0,&acc);
    
  free_input(in);
  return EXIT_SUCCESS;
}
