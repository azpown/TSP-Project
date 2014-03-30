#include <ArbrePlanaireInt.h>
#include <ArbrePlanaireGenerique.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  ArbrePlanaireInt arbre= creerArbrePlanaireInt();
  printf("%d\n",arbre);
  Noeud n_1=ajouterNoeudInt(arbre,NULL,1);
  printf("%d\n",n_1);
  Noeud n_2=ajouterNoeudInt(arbre,n_1,2);
  printf("%d\n",n_2);
  Noeud n_3=ajouterNoeudInt(arbre,n_2,3);
  Noeud n_4=ajouterNoeudInt(arbre,n_2,3);
  affichagePrefixeInt(arbre);
  //freeArbrePlanaireInt(arbre);
}
