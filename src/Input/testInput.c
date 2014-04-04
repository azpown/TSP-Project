#include <stdlib.h>
#include <stdio.h>
#include <Graphe.h>
#include <Input.h>

int main ()
{
  Input in=open_TSP_file("bays29.tsp");
  Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
  double acc=0;
  print_input_data(in);
    
  free_input(in);
  free_graphe(g);
  return EXIT_SUCCESS;
}
