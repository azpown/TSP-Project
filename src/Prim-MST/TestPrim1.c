/**
 * \file TestPrim1.c
 * \brief Programme de tests de l'algorithme Prim.
 */

#include <stdlib.h>
#include <stdio.h>
#include <Input.h>
#include <Prim.h>
#include <FonctionTest.h>
#include <Graphe.h>

/**
 * \brief Fonction de tests de l'algorithme Prim.
 * \param argv[] Chaine de caractères qui contient le fichier TSP a utilisé et la ville de départ pour l'algorithme de Prim.
 */
int main (int argc,char* argv[])
{
  if(argc != 3)
  {
    printf("Usage : ./<NomExec> <CheminTspFile> <VilleDepart>\n");
    return EXIT_FAILURE;
  }    
  testBaseHeuristiqueAD(argv[1],atoi(argv[2]),Prim);
  return EXIT_SUCCESS;
}


