#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <Graphe.h>
#include <NearestNeighbour.h>
#include <Input.h>
#include <BruteForceOpti.h>

int main()
{
  Input in=open_TSP_file("../../../tsp_files/exemple10.tsp");
  Graphe g= cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
  double acc=0;
  int* BF = BruteForceOpti(g,&acc);
  free_input(in);
  free_graphe(g);
  //free(BF);
}
