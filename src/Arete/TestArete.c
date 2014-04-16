/**
 * \file TestArete.c
 * \brief Programme de tests.
 */


#include <stdlib.h>
#include <stdio.h>
#include <Arete.h>




/**
 * \brief Fonction permettant d'effectuer des tests pour vérifier les fonctions du fichier Arete.c.
 */
int main()
{
  Arete testArete=creerArete(5.0,0,10);
  Arete testAreteBis=creerArete(5.0,0,3);
  afficheArete(testArete);
  afficheArete(testAreteBis);
  /* attendu : 0 */
  printf("5.0 == 5.0 -> %d\n",comparaisonAreteCle(testArete,5.0));
  setCle(50,testArete);
  /* attendu : 1 */
  printf("50 == 25 -> %d\n",comparaisonAreteCle(testArete,25.0));
  /* attendu : -1 */ 
  printf("50 == 100 -> %d\n",comparaisonAreteCle(testArete,100.0));
  freeArete(testArete);/* libère la mémoire de testArete. */
  freeArete(testAreteBis);/* libère la mémoire de testAreteBis. */
  return EXIT_SUCCESS;
}
  
