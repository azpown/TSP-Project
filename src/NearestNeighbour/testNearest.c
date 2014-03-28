#include <NearestNeighbour.h>
#include <Graphe.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <Input.h>

void
afficher(int* t, int taille){
  for (int i=0; i<taille;i++)
    printf("%d ",t[i]);
}

int
main(){
  Input matrice=open_TSP_file("../../lib/exemple10.tsp");
  Graphe g=cree_graphe(get_dimension(matrice),get_edge_weight_matrix(matrice));
  afficher_graphe(g);
  printf("\n\n");
  double acc=0;
  printf("le chemin en dur en partant de la ville 1 est : 1 3 5 2 0 6 8 7 9 1");
  printf("\n");
  printf("la distance parcourue est de 46");
  
  printf("le chemin en dur en partant de la ville 1 et la distance parcourue est de :");
  printf("\n");
  afficher(HeuristiquePlusProcheVoisin(g,&acc,1),get_taille(g)+1);
  printf("%.1lf\n",acc);
  return EXIT_SUCCESS;
}
