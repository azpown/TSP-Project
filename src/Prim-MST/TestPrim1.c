#include <stdlib.h>
#include <stdio.h>
#include <Input.h>
#include <Prim.h>
#include <FonctionTest.h>

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


