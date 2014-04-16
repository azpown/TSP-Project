/**
 * \file TasArete.c
 * \brief Programme mettant en place un graphe correspondant à une matrice.
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <TasGenerique.h>
#include <TasArete.h>

/*------ Déclaration des fonctions statiques ------*/


/**
 * \brief Fonction qui affiche l'arête elem.
 */

static void setAffichageTasMin(void* elem);

/**
 * \brief Fonction qui compare deux arretes.
 */

static int setComparaisonTasMin(void* a,void *b);

/**
 * \brief Fonction qui affecte une nouvelle clé à l'arête.
 */

static void setMajTasMin(void* old, void* new);

/**
 * \brief Fonction qui compare une arête à la clé et une arête a.
 */

static int setComparaisonCleTasMin(void* a,void* cle);

struct TasArete
{
  TasMinGen tas;
};

/*L'utilisateur doit free la liste des AreteHandle. */
struct AreteHandle
{
  ElemHandle arete;
};

/*------ Allocation ------*/

TasMinArete creerTasMinArete(int taille)
{
  TasMinArete tasMin=malloc(sizeof(struct TasArete));
  tasMin->tas= creerTasMinGen(taille,setComparaisonTasMin,setComparaisonCleTasMin,setAffichageTasMin,setMajTasMin);
  return tasMin;
}

void freeTasArete(TasMinArete tasMin)
{
  freeTasGen(tasMin->tas);
  free(tasMin);
}

void freeAreteHandle(AreteHandle a)
{
  freeElemHandle(a->arete);
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

int indiceAreteHandle(AreteHandle areteH)
{
  return getIndice(areteH->arete);
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

void diminuerCleArete(TasMinArete tas_a, AreteHandle areteH,double newCle)
{
  diminuerCle(tas_a->tas,areteH->arete, (void*) &newCle);
}

static void setAffichageTasMin(void* elem)
{
  afficheArete( (Arete) elem);
}

static int setComparaisonTasMin(void* a,void *b)
{
  return comparaisonArete( (Arete) a, (Arete) b);
}

static void setMajTasMin(void* oldArete, void* newCle)
{
  /* fonction du module arete */
  setCle(*((double*) newCle),(Arete) oldArete);
}

static int setComparaisonCleTasMin(void* a,void* cle)
{
  return comparaisonAreteCle((Arete) a,*((double*) cle));
}
	      
