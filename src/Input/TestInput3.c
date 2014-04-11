#include <stdlib.h>
#include <stdio.h>
#include <Graphe.h>
#include <Input.h>

int main()
{
  Input in=open_TSP_file("../../tsp_files/noDim.tsp");
  Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
}
