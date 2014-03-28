#include <TasGenerique.h>
#include <TasArete.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*------ Déclaration des fonctions statiques ------*/
static void setAffichageTasMin(void* elem);
static int setComparaisonTasMin(void* a,void *b);

struct TasArete
{
  TasMinGen tas;
};

TasMinArete creerTasMinArete(int taille)
{
  TasMinArete tasMin=malloc(sizeof(struct TasArete));
  tasMin->tas= creerTasMinGen(taille,setComparaisonTasMin,setAffichageTasMin);
  return tasMin;
}

void freeTasArete(TasMinArete tasMin)
{
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

static void setAffichageTasMin(void* elem)
{
  afficheArete( (Arete) elem);
}

static int setComparaisonTasMin(void* a,void *b)
{
  return comparaisonArete( (Arete) a, (Arete) b);
}


