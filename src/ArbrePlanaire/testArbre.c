#include <ArbrePlanaireGenerique.h>
#include <ArbrePlanaireInt.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  ArbrePlanaireInt this= creerArbrePlanaireInt();
  Noeud tab[4];
  tab[0]=ajouterNoeudInt(this,NULL,1);
  tab[1]=ajouterNoeudInt(this,tab[0],2);
  tab[2]=ajouterNoeudInt(this,tab[1],3);
  tab[3]=ajouterNoeudInt(this,tab[1],4);
  printf("Affichage avant suppression :  ");
  affichagePrefixeInt(this);
  printf("Affichage apres suppression de 4:  ");
  supprimerNoeudInt(this,tab[3]);
  affichagePrefixeInt(this);
  for(int i=0;i<3;i++)
    freeInt(tab[i]);
  freeArbrePlanaireInt(this);
  printf("Ce programme marche niquel, faut automatiser tout ça maintenant :)\n");
}
