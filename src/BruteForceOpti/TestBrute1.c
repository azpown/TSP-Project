/**
 * \file TestBrut.c
 * \brief Programme de test.
 */




#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <Graphe.h>
#include <NearestNeighbour.h>
#include <Input.h>
#include <BruteForceOpti.h>
#include <FonctionTest.h>




/**
 * \brief Fonction permettant de tester des fonctions implémenté dans le fichier BruteForceOpti.c.
 */


int main()
{
  Input in=open_TSP_file("../../../tsp_files/exemple10.tsp");
  Graphe g= cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
  double acc=0;
  int* BF = BruteForceOpti(g,&acc);
  afficheCycle(BF,get_dimension(in),acc);
  free_input(in);
  free_graphe(g);
  free(BF);
}
