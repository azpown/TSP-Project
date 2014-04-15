/**
 * \file TestInput2.c
 * \brief Programme de tests.
 */




#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <Graphe.h>
#include <Input.h>


/**
 * \brief Fonction de tests.
 * Test effectué sur exemple10.tsp.
 */



int main()
{
  Input in=open_TSP_file("../../../tsp_files/exemple10.tsp");
  Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));

  bool taille_attendu = get_taille(g)==10;
  bool double1_attendu = get_double(g,0,0)==0;
  bool double2_attendu = get_double(g,1,2)==7;
  bool double3_attendu = get_double(g,2,1)==7;
  bool double4_attendu = get_double(g,4,6)==6;
  if(taille_attendu && double1_attendu && double2_attendu && double3_attendu && double4_attendu)
    printf("OK");
  else
    printf("ECHEC");
  free_input(in);
  free_graphe(g);
  return EXIT_SUCCESS;
}
  
  
  
  
  
