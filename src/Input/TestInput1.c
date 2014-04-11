#include <stdlib.h>
#include <stdio.h>
#include <Graphe.h>
#include <Input.h>

int main (int argc,char* argv[])
{
  Input in=open_TSP_file(argv[1]);
  Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
  print_input_data(in);
    
  free_input(in);
  free_graphe(g);
  return EXIT_SUCCESS;
}