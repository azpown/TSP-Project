#include "TasGenerique.h"
#include "Arete.h"
#include <stdlib.h>
#include <stdio.h>

struct TasArete
{
  TasMinGen tas;
};

TasMinArete creerTasMinArete(int taille,ptr_compar cmp,ptr_affichage affichage)
{
  TasMinArete tas=malloc(sizeof(struct TasArete));
  tas->tas= creerTasMinGen(taille,cmp,affichage);
  return tas;
}

void freeTasArete(TasMinArete tas)
{
  for(int i=0;i<taille;i++)
    freeArete(sommet(tas->tas,i));
  freeTasGen(tas->tas);
  free(tas);
}

bool estVide(TasMinArete tas)
{
  return estvide(tas->tas);
}

void ajouterArete(TasMinArete tas, Arete a)
{
  ajouterSommet(tas->tas,(void*) a);
}

void entasserTasArete(TasMinArete tas, int indice)
{
  entasserTas(tas->tas,indice);
}

Arete extraireAreteMin(TasMinArete tas)
{
  return (Arete) extraireMin(tas->tas);
}

void affichageTasArete(TasMinArete tas)
{
  affichageTas(tas->tas);
}


