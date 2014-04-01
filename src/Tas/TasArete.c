#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <TasGenerique.h>
#include <TasArete.h>

/*------ Déclaration des fonctions statiques ------*/
static void setAffichageTasMin(void* elem);
static int setComparaisonTasMin(void* a,void *b);

struct TasArete
{
  TasMinGen tas;
};

/* cette structure est fortement dépendante du tas qui ce charge automatiquement 
 * de la libération de mémoire interne, il faut que le client libere imméditement
 * la mémoire alloué apres extraction. */
struct AreteHandle
{
  ElemHandle arete;
};

/*------ Allocation ------*/

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

void freeAreteHandle(AreteHandle a)
{
  freeArete(getElem(a->arete));
  free(a);
}

/*------ Primitives tas ------*/

bool estVide(TasMinArete tasMin)
{
  return estvide(tasMin->tas);
}

AreteHandle ajouterAreteHandle(TasMinArete tasMin, Arete a)
{
  AreteHandle areteH=malloc(sizeof(struct AreteHandle));
  areteH->arete=ajouterSommet(tasMin->tas,(void*) a);
  return areteH;
}

int indiceTas(AreteHandle areteH)
{
  return indice(areteH->arete);
}

Arete extraireAreteMin(TasMinArete tasMin)
{
  return (Arete) extraireMin(tasMin->tas);
}

Arete getArete(AreteHandle areteH)
{
  return (Arete) getElem(areteH->arete);
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

void diminuerCleArete(TasMinArete tas_a, AreteHandle areteH, Arete newArete)
{
  diminuerCle(tas_a->tas,areteH->arete, (void*) newArete);
}

	      
