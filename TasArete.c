#include "TasGenerique.h"
#include "Arete.h"
#include "TasArete.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct TasArete
{
  TasMinGen tas;
};

TasMinArete creerTasMinArete(int taille,ptr_compar cmp,ptr_affichage affichage)
{
  TasMinArete tasMin=malloc(sizeof(struct TasArete));
  tasMin->tas= creerTasMinGen(taille,cmp,affichage);
  return tasMin;
}

void freeTasArete(TasMinArete tasMin)
{
  for(int i=0; i< getTailleTas(tasMin->tas) ;i++)
    freeArete(sommet(tasMin->tas,i));
  freeTasGen(tasMin->tas);
  free(tasMin);
}

bool estVide(TasMinArete tasMin)
{
  return estvide(tasMin->tas);
}

void ajouterArete(TasMinArete tasMin, Arete a)
{
  ajouterSommet(tasMin->tas,(void*) a);
}

void entasserTasArete(TasMinArete tasMin, int indice)
{
  entasserTas(tasMin->tas,indice);
}

Arete extraireAreteMin(TasMinArete tasMin)
{
  return (Arete) extraireMin(tasMin->tas);
}

void affichageTasArete(TasMinArete tasMin)
{
  affichageTas(tasMin->tas);
}


