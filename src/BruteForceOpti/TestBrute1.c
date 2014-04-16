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
 * \brief Fonction permettant d'utiliser l'heuristique BruteForceOpti avec n'importe quelle matrice Tsp.
 * \param argv[] Tableau de char* contenant le chemin du fichier tsp à parser.
 */
int main (int argc,char* argv[])
{
  if(argc =! 2)
  {
    printf("Usage : ./<NomExec> <CheminTspFile> \n");
    return EXIT_FAILURE;
  }
  testBaseHeuristiqueSD(argv[1], BruteForceOpti);
  return EXIT_SUCCESS;
}
