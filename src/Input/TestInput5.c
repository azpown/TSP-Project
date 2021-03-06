/**
 * \file TestInput5.c
 * \brief Programme de tests.
 */



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <Graphe.h>
#include <Input.h>



/**
 * \brief Fonction de tests.
 * Test effectué sur exemple14.tsp.
 */

int main()
{
  Input in=open_TSP_file("../../../tsp_files/exemple14.tsp");
  Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
  print_input_data(in);
  free_input(in);
  free_graphe(g);
  return EXIT_SUCCESS;
}
