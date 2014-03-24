#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "TasGenerique.h"

/* La fonction ptr_compar(a,b) renvoie -1,0,1 respectivement pour :
 * - a<b
 * - a==b
 * - a>b */

/* Refonte du module TasGen, les complexités de vos algorithmes étaient bien souvent enormes par rapport
 * aux valeurs attendues.*/

struct TasMinGen
{ 
  void* sommets;
  int taille;
  int taille_tas;
  ptr_compar comparaison;
  ptr_affichage affichage;
};

/*------ DECLARATION FONCTION STATIQUE ------*/
static void percolate_haut(TasMinGen tas,int indice);
static void echanger(void* t,int i,int j);
static void trierTableauTas(TasMinGen tas);

/*------ ACCESSEUR/MUTATEUR ------*/
void setAffichage(TasMinGen tas,ptr_affichage fonction){tas->affichage=fonction;}
void setComparaison(TasMinGen tas,ptr_compar fonction){tas->comparaison=fonction;}
void setTailleTas(TasMinGen tas,int taille){tas->taille_tas=taille;}
int getTailleTas(TasMinGen tas){return tas->taille;}

void setTableau(TasMinGen tas,void** tab,int taille)
{
  assert(taille<=tas->taille_tas);
  for(int i=0;i<taille;i++)
    /* Attention a free avant */
    tas->sommets[i]=tab[i];
  /* On a fait une copie des références, on reorganise le tas
   * afin qu'il represente un tas valide. */
  tas->taille=taille;
  trierTableauTas(tas);
}

/* On ne laisse pas la possibilité au client d'instancier un tas sans fonction de comparaison ni
 * d'affichage (moins de traintement d'erreurs, et pas d'utilité dans le cadre de ce projet */

/* On affiche le tas tel qu'il est dans la mémoire <-> tableau 1D
 *c'est au module utilisant le délégué de faire un affichage perso.  */
void affichageTas(TasMinGen tas)
{
  printf("\tCONTENU DU TAS MIN\n");
  for(int i=0; i< tas->taille;i++)
    tas->affichage(sommet(tas,i));
}

TasMinGen creerTasMinGen(int taille,ptr_compar cmp,ptr_affichage affichage)
{
  TasMinGen tas=malloc(sizeof(struct TasMinGen));	  //initialise un TasMin
  tas->taille_tas=taille;	                  //initialise le nombre maximum d'éléments du tas
  tas->taille=0;
  tas->sommets=calloc(taille,sizeof(void*));
  tas->comparaison=cmp;
  tas->affichage=affichage;
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
  void* cellule=sommet(tas,indice);
  void* pere=sommet(tas,pere(indice));
  /* Si le père est plus grand que le fils, on swap */
  if(indice>0 && tas->comparaison(cellule,pere) < 0)
  {
    /* swap sommet/pere sommet */
    echanger(tas->sommets,cellule,pere(indice));
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
    echanger(tas->sommets,min,indice);
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
		  
static void echanger(void* t,int i,int j)
{
  void* tmp=t[i];
  t[i]=t[j];
  t[j]=tmp;
}

/* On reorganise le tas, sous arbre après sous arbre, sachant qu'on commence
 * à l'indice taille/2 car tout les sommets avec des indices supérieur
 * sont des feuilles (arbre q-parfait. */
static void trierTableauTas(TasMinGen tas)
{
  for(int i=tas->taille;i<=0;i--)
    entasserTas(tas,i);
}  




