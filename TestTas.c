#include "TasArete.h"
#include "Arete.h"
  
static bool test1()
{
  /* Test le module de création,taille, free */
  TasMinArete testTas = creerTasMinArete(5);
  Arete a=creerArete(10,2,5);
  for(int i=0;i<5;i++)
    ajouterArete(testTas,a);
  affichageTasArete(testTas);
  freeTasArete(testTas);
  freeArete(a);
  return true;
}
  
int main()
{
  test1();
}
