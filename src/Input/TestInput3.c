/**
 * \file TestInput3.c
 * \brief Programme de tests.
 */



#include <stdlib.h>
#include <stdio.h>
#include <Graphe.h>
#include <Input.h>



/**
 * \brief Fonction de tests.
 * Test effectué sur noDim.tsp.
 */


int main()
{
  Input in=open_TSP_file("../../../tsp_files/noDim.tsp");
  Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
  free_input(in);
  free_graphe(g);
  return EXIT_SUCCESS;
}
