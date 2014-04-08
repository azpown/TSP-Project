#include <ArbrePlanaireGenerique.h>
#include <ArbrePlanaireInt.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  ArbrePlanaireInt this= creerArbrePlanaireInt();
  Noeud tab[4];
  printf("ajout racine : 1\n");
  tab[0]=ajouterNoeudInt(this,NULL,1);
  printf("ajout : 2 -> pere(1)\n");
  tab[1]=ajouterNoeudInt(this,tab[0],2);
  printf("ajout : 3 -> pere(1)\n");
  tab[2]=ajouterNoeudInt(this,tab[1],3);
  printf("ajout : 4 -> pere(1)\n");
  tab[3]=ajouterNoeudInt(this,tab[1],4);
  printf("Affichage avant suppression : ");
  affichagePrefixeInt(this);
  printf("Affichage apres suppression de 4: ");
  supprimerNoeudInt(this,tab[3]);
  affichagePrefixeInt(this);
  for(int i=0;i<3;i++)
    freeInt(tab[i]);
  freeArbrePlanaireInt(this);
}
