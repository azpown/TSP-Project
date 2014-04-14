#include <stdlib.h>
#include <stdio.h>
#include <Input.h>
#include <Prim.h>
#include <FonctionTest.h>

int main (int argc,char* argv[])
{
  Input in=open_TSP_file(argv[1]);
  Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
  double acc=0;
  int* resultat=Prim(g,0,&acc);
  
  if(estCycleValide(resultat,get_taille(g)) && acc>0)
    printf("OK");
  else
    printf("ECHEC");
  free(resultat);
  free_input(in);
  free_graphe(g);
  return EXIT_SUCCESS;
}


