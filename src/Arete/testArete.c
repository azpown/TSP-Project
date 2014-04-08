#include <stdlib.h>
#include <stdio.h>
#include <Arete.h>

int main()
{
  Arete testArete=creerArete(5.0,0,10);
  Arete testAreteBis=creerArete(5.0,0,3);
  afficheArete(testArete);
  afficheArete(testAreteBis);
  /* attendu : 0 */
  printf("%d\n",comparaisonAreteCle(testArete,5.0));
  setCle(50,testArete);
  /* attendu : 1 */
  printf("%d\n",comparaisonAreteCle(testArete,25.0));
  freeArete(testArete);
  //freeArete(testAreteBis);
  return EXIT_SUCCESS;
}
  
