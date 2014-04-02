#include <stdio.h>
#include <Arete.h>
#include <TasArete.h>
  
static bool test1()
{
  /* Test le module de création,taille, free */
  TasMinArete testTas = creerTasMinArete(5);
  AreteHandle tab[5];
  Arete tab_a[5];
  tab[0]=ajouterAreteHandle(testTas,tab_a[0] = creerArete(10,2,5));
  affichageTasArete(testTas);
  tab[1]=ajouterAreteHandle(testTas,tab_a[1] = creerArete(2,2,7));
  affichageTasArete(testTas);
  tab[2]=ajouterAreteHandle(testTas,tab_a[2] = creerArete(4,2,4));
  affichageTasArete(testTas);
  tab[3]=ajouterAreteHandle(testTas,tab_a[3] = creerArete(89,2,1));
  affichageTasArete(testTas);
  tab[4]=ajouterAreteHandle(testTas,tab_a[4] = creerArete(7,2,9));
  affichageTasArete(testTas);
  
  printf("\n------ TEST EXTRACTION ------\n\n");
  printf("Arete extraite :\t");
  afficheArete(extraireAreteMin(testTas));
  affichageTasArete(testTas);
  printf("Arete extraite :\t");
  afficheArete(extraireAreteMin(testTas));
  affichageTasArete(testTas);

  printf("\n------ TEST MODIFKEYS ------\n\n");
  
  diminuerCleArete(testTas,tab[1],1);
  affichageTasArete(testTas);
  
  diminuerCleArete(testTas,tab[2],2);
  affichageTasArete(testTas);


  for(int i=0;i<5;i++)
  {
    freeAreteHandle(tab[i]);
    freeArete(tab_a[i]);
  }
  freeTasArete(testTas);
  
  printf("Ce programme marche niquel, faut automatiser tout ça maintenant :)\n");
  return true;
  
}
  
int main()
{
  test1();
}
