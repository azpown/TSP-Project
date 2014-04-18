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
 * \param argv[] Tableau de char* contenant le chemin du fichier tsp a parser et la ville de départ.
 */
int main (int argc,char* argv[])
{
  if(argc != 3)
  {
    printf("Usage : ./<NomExec> <CheminTspFile> <VilleDepart>\n");
    return EXIT_FAILURE;
  }
  testBaseHeuristiqueAD(argv[1],atoi(argv[2]),HeuristiquePlusProcheVoisin);
  return EXIT_SUCCESS;
}

