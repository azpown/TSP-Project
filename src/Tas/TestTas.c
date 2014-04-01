#include <Arete.h>
#include <TasArete.h>
  
static bool test1()
{
  /* Test le module de création,taille, free */
  TasMinArete testTas = creerTasMinArete(5);
  AreteHandle tab[5];
  tab[0]=ajouterAreteHandle(testTas,creerArete(10,2,5));
  tab[1]=ajouterAreteHandle(testTas,creerArete(2,2,7));
  tab[2]=ajouterAreteHandle(testTas,creerArete(4,2,4));
  tab[3]=ajouterAreteHandle(testTas,creerArete(89,2,1));
  tab[4]=ajouterAreteHandle(testTas,creerArete(7,2,9));
  
  affichageTasArete(testTas);
  for(int i=0;i<5;i++)
    freeAreteHandle(tab[i]);
  freeTasArete(testTas);
  
  return true;
  
}
  
int main()
{
  test1();
}
