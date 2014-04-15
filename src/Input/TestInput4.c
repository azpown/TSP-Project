/**
 * \file TestInput4.c
 * \brief Programme de tests.
 */




#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <Graphe.h>
#include <Input.h>


/**
 * \brief Fonction de tests.
 * Test effectué sur notSymmetrical.tsp.
 */

int main()
{
  Input in=open_TSP_file("../../../tsp_files/notSymmetrical.tsp");
  free_input(in);
  return EXIT_SUCCESS;
}
