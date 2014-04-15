/**
 * \file TestPrim2.c
 * \brief Programme de tests de l'algorithme Prim.
 */




#include <stdlib.h>
#include <stdio.h>
#include <Input.h>
#include <Prim.h>
#include <FonctionTest.h>

/**
 * \brief Fonction de test de l'algorithme Prim sur le fichier Tsp exemple10.tsp.
 */



int main ()
{
  Input in=open_TSP_file("../../../tsp_files/exemple10.tsp");
  Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
  double acc=0;
  int* resultat=Prim(g,0,&acc);
  afficheCycle(resultat,get_dimension(in),acc);
  free(resultat);
  free_input(in);
  free_graphe(g);
  return EXIT_SUCCESS;
}
