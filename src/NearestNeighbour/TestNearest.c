/**
 * \file TestNearest.c
 * \brief Programme de tests.
 * Programme de test pour l'heuristique NearestNeighbour.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <Input.h>
#include <NearestNeighbour.h>
#include <FonctionTest.h>


/**
 * \brief Fonction permettant d'utiliser l'heuristique NearestNeighbour avec n'importe quelle matrice Tsp.
 * \param argv[] Chaine de caractères qui contient la matrice pour laquelle on souhaite effectuer l'algorithme de Prim.
 */


int main (int argc,char* argv[])
{
  Input in=open_TSP_file(argv[1]);
  Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
  double acc=0;
  int* resultat=HeuristiquePlusProcheVoisin(g,&acc,0);
  afficheCycle(resultat,get_dimension(in),acc);
  free_input(in);
  free_graphe(g);
  free(resultat);
  return EXIT_SUCCESS;
}
