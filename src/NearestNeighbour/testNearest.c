#include "NearestNeighbour.h"
#include "Graphe.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include "Input.h"

void
afficher(double* t, int taille){
  for (int i=0; i<taille;i++)
    printf("%d ",t[i]);
}

int
main(){
  Input matrice=open_TSP_file("bays29.tsp");
  Graphe g=cree_graphe(get_dimension(matrice),get_edge_weight_matrix(matrice));
  afficher_graphe(g);
  printf("\n \n");
  afficher(HeuristiquePlusProcheVoisin(g),get_taille(g));
  return EXIT_SUCCESS;
}
