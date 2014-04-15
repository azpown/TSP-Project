/**
 * \file TestPrim2.c
 * \brief Programme de tests de l'algorithme Prim.
 */

#include <stdlib.h>
#include <stdio.h>
#include <Input.h>
#include <Prim.h>
#include <FonctionTest.h>
#include <Graphe.h>

/**
 * \brief Fonction de test de l'algorithme Prim sur un fichier TSP, vérifiant qu'il s'agit bien d'une 2 approximation. La valeur passée en 3ème parametre doit etre valide, sous peine d'avoir un test sans intêret.
 */
int main (int argc,char* argv[])
{
  if(argc =! 3)
  {
    printf("Usage : ./<NomExec> <CheminTspFile> <DistancePlusCourtChemin>\n");
    return EXIT_FAILURE;
  }    
  Graphe g= getGraphe(argv[1]);
  double acc=0;
  double min = (double) atoi(argv[2]);
  /* On verifie qu'il s'agit d'une 2 approximation et que la distance est valide */
  for(int i=0;i<get_taille(g);i++)
  {
    acc=0;
    int* resultat=Prim(g,i,&acc);
    printf("Depart : %d - Résultat : %.2lf\n",i,acc);
    if(!(acc<=2*min && acc+1 >= min))
    {
	printf("ECHEC\n");
	return EXIT_FAILURE;
    }
    free(resultat);
  }
  free_graphe(g);
  printf("OK\n");
  return EXIT_SUCCESS;
}
