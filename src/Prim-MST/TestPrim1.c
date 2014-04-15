/**
 * \file TestPrim1.c
 * \brief Programme de tests de l'algorithme Prim.
 */


#include <stdlib.h>
#include <stdio.h>
#include <Input.h>
#include <Prim.h>
#include <FonctionTest.h>



/**
 * \brief Fonction de tests de l'algorithme Prim.
 * \param argv[] Chaine de caractères qui contient la matrice pour laquelle on souhaite effectuer l'algorithme de Prim.
 */



int main (int argc,char* argv[])
{
  if(argc =! 3)
  {
    printf("Usage : ./<NomExec> <CheminTspFile> <VilleDepart>");
    return EXIT_FAILURE;
  }    
  testBaseHeuristiqueAD(argv[1],atoi(argv[2]),Prim);
  return EXIT_SUCCESS;
}


