#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <Graphe.h>
#include <Input.h>

int main()
{
  Input in=open_TSP_file("../../../tsp_files/notSymmetrical.tsp");
  free_input(in);
  return EXIT_SUCCESS;
}
