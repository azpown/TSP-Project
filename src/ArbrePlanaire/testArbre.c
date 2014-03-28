#include <ArbrePlanaireInt.h>
#include <ArbrePlanaireGen.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  ArbrePlanaireInt arbre= creerArbrePlanaireInt();
  NoeudInt n_1=ajouterNoeudInt(arbre,NULL,1);
  NoeudInt n_2=ajouterNoeudInt(arbre,n_1,2);
  NoeudInt n_3=ajouterNoeudInt(arbre,n_2,3);
  NoeudInt n_4=ajouterNoeudInt(arbre,n_2,3);
  affichagePrefixeInt(arbre);
  freeArbrePlanaireInt(arbre);
}
