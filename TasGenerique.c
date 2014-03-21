#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "creationTasMin.h"

/* La fonction ptr_compar(a,b) renvoie -1,0,1 respectivement pour :
 * - a<b
 * - a==b
 * - a>b */
typedef int (*ptr_compar)(void*,void*)

/* Refonte du module TasGen, les compléxités de vos algorithmes étaient bien souvent supérieures
 * aux valeurs attendues.*/

struct TasMinGen
{ 
  void* sommets;
  int taille;
  int taille_tas;
  ptr_compar comparaison;
};


TasGen creerTasMinGen(int taille,ptr_compar cmp)
{
  TasGen tas=malloc(sizeof(struct TasMinGen));	  //initialise un TasMin
  tas->taille_tas=taille_tas;	                  //initialise le nombre maximum d'éléments du tas
  tas->taille=0;
  tas->sommets=calloc(taille,sizeof(void*));
  tas->comparaison=cmp;
  return tas;
}

bool estvide(TasMinGen tas)
{
  /* null=0=false */
  if (tas->sommets[0])
    return true;
  return false;
}

void freeTasGen(TasMinGen tas)
{
  free(tas->sommets);
  free(tas);
}

static void percolate_haut(TasMinGen tas,int indice)
{
  void* sommet=sommet(tas,indice);
  void* pere=sommet(tas,pere(indice));
  /* Si le père est plus grand que le fils, on swap */
  if(indice>0 && tas->comparaison(sommet,pere) < 0)
  {
    /* swap sommet/pere sommet */
    echanger(sommet,pere(indice));
    percolate_haut(tas,pere(indice));
  }
}

void ajouterSommet(TasMinGen tas, void* elem)
{
  if(tas->taille < tas->taille_tas)
  {
    /* On ajoute l'elem en tant que feuille */
    tas->sommets[tas->taille];
    /* On le fait ensuite remonter jusqu'a qu'il soit a une position valide du tas */
    percolate_haut(tas,tas->taille);
    tas->taille++;
  }
  else
  {
    /* Nous n'implementons pas une fonction de rallongement car la taille du tas
     * dans nos algorithmes sera majorée par le nombre de ville.*/
    printf("Tas déjà plein\n");
  }
}

void entasserTas(TasMinGen tas,int indice)
{
  int taille=tas->taille;
  void* gauche=filsGauche(indice);
  void* droit=filsDroit(indice);
  int min=indice;
  /* Si gauche existe et sommet(gauche)<sommet(indice) */
  if(gauche<taille && tas->comparaison(sommet(tas,min),sommet(tas,gauche)) >0)
    min=gauche;
  /* si droit existe et sommet(droit)<min(sommet(indice), sommet(gauche)) */
  if(droit<taille && tas->comparaison(sommet(tas,min),sommet(tas,droit)) >0)
    min=droit;
  /* Si le sommet[indice] est plus petit qu'un de ces fils, on le swap
   * avec le plus petit des deux. */
  if(min != indice)
  {
    echanger(min,indice);
    entasserTas(tas,min);
  }
}

void* extraireMin(TasMinGen tas)
{
  assert(tas->taille>0);
  void* min=sommet(tas,0);
  tas->taille--;
  tas->sommets[0]=sommet(tas,tas->taille);
  /* On réorganise le tas en O(ln_2(nb_sommet)) vu que le tas est un arbre quasi
   * parfait (donc etage(0)-> 2**0 sommet ... etage i -> 2**i sommet) */
  entasserTas(tas,0);
  return min;
}

/*------- Fonction d'accès, pour plus de lisibilité ------*/
void* sommet(TasMinGen tas, int indice){return tas->sommets[indice];}
int pere(TasMinGen tas,int indice){return indice/2;}
int filsGauche(TasMinGen tas, int indice){return 2*indice+1];}
int filsDroit(TasMinGen tas, int indice){return 2*indice+2];}
		  
void echanger(int i,int j)
{
  void* tmp=t[i];
  t[i]=t[j];
  t[j]=tmp;
}

void reorganiserTasMin(ville v,ptr_compar){
  int taille=v->taille_max;
  for(int i=0;i<taille;i++){
    for(int j=i;j<taille;j++){
      if(ptr_compar(v->sommets[i],filsGauche(v,j))) // si le sommet père est supérieur à son fils
	echanger(v->sommets[i],filsGauche(v,j));// gauche alors on les échange
      if(ptr_compar(v->sommets[i],filsDroit(v,j))) // si le sommet père est superieur à son fils
	echanger(v->sommets[i],filsGauche(v,j));// droit alors on les échange
  }
}



