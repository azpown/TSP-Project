#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <TasGenerique.h>

/* La fonction ptr_compar(a,b) renvoie -1,0,1 respectivement pour :
 * - a<b
 * - a==b
 * - a>b */

/* Refonte du module TasGen, les complexités de vos algorithmes étaient bien souvent enormes par rapport
 * aux valeurs attendues.*/

struct elemHandle
{
  void* elem;
  int handle;
};

struct TasMinGen
{ 
  ElemHandle* sommets;
  int taille;
  int taille_tas;
  ptr_compar comparaison;
  ptr_affichage affichage;
  ptr_affectation affecte;
};

/*------ DECLARATION FONCTION STATIQUE ------*/
static void percolate_haut(TasMinGen tas,int indice);
static void echanger(ElemHandle* t,int i,int j);
static void trierTableauTas(TasMinGen tas);

/*------ ACCESSEUR/MUTATEUR ------*/
void setAffichage(TasMinGen tas,ptr_affichage fonction){tas->affichage=fonction;}
void setComparaison(TasMinGen tas,ptr_compar fonction){tas->comparaison=fonction;}
void setTailleTas(TasMinGen tas,int taille){tas->taille_tas=taille;}
int getTailleTas(TasMinGen tas){return tas->taille;}


/*------ ALLOCATION ------*/

TasMinGen creerTasMinGen(int taille,ptr_compar cmp,ptr_affichage affichage)
{
  TasMinGen tas=malloc(sizeof(struct TasMinGen));	  //initialise un TasMin
  tas->taille_tas=taille;	                  //initialise le nombre maximum d'éléments du tas
  tas->taille=-1; //Indice du dernier element !
  tas->sommets=malloc(taille * sizeof(ElemHandle));
  tas->comparaison=cmp;
  tas->affichage=affichage;
  return tas;
}

ElemHandle creerElemHandle(void *element,int indice)
{
  ElemHandle obj= malloc(sizeof(struct elemHandle));
  obj->handle=indice;
  obj->elem=element;
  return obj;
}

void freeElemHandle(ElemHandle elem){free(elem);}


void freeTasGen(TasMinGen tas)
{
  for(int i=0;i<tas->taille+1;i++)
    freeElemHandle(tas->sommets[i]);
  free(tas->sommets);
  free(tas);
}

/* On ne laisse pas la possibilité au client d'instancier un tas sans fonction de comparaison ni
 * d'affichage (moins de traintement d'erreurs, et pas d'utilité dans le cadre de ce projet */

/* On affiche le tas tel qu'il est dans la mémoire <-> tableau 1D
 *c'est au module utilisant le délégué de faire un affichage perso.  */
void affichageTas(TasMinGen tas)
{
  printf("\tCONTENU DU TAS MIN\n");
  for(int i=0; i< tas->taille+1;i++)
    tas->affichage(sommet(tas,i)->elem);
}

bool estvide(TasMinGen tas)
{
  return tas->taille ==-1;
}

static void percolate_haut(TasMinGen tas,int indice)
{
  ElemHandle cellule=sommet(tas,indice);
  ElemHandle cellulePere=sommet(tas,pere(indice));
  /* Si le père est plus grand que le fils, on swap */
  if(indice>0 && tas->comparaison(cellule->elem,cellulePere->elem) < 0)
  {
    /* swap sommet/pere sommet */
    echanger(tas->sommets,indice,pere(indice));
    percolate_haut(tas,pere(indice));
  }
}

ElemHandle ajouterSommet(TasMinGen tas, void* element)
{
  if(tas->taille < tas->taille_tas)
  {
    tas->taille++;
    /* On ajoute l'elem en tant que feuille */
    ElemHandle tmp = creerElemHandle(element,tas->taille);
    tas->sommets[tas->taille]=tmp;
    /* On le fait ensuite remonter jusqu'a qu'il soit a une position valide du tas */
    percolate_haut(tas,tas->taille);
    return tmp;
  }
  else
  {
    /* Nous n'implementons pas une fonction de rallongement car la taille du tas
     * dans nos algorithmes sera majorée par le nombre de ville.*/
    printf("Tas déjà plein\n");
    return NULL;
  }
}

void entasserTas(TasMinGen tas,int indice)
{
  int taille=tas->taille;
  int gauche=filsGauche(indice);
  int droit=filsDroit(indice);
  int min=indice;
  /* Si gauche existe et sommet(gauche)<sommet(indice) */
  if(gauche<taille && tas->comparaison(sommet(tas,min)->elem ,sommet(tas,gauche)->elem) >0)
    min=gauche;
  /* si droit existe et sommet(droit)<min(sommet(indice), sommet(gauche)) */
  if(droit<taille && tas->comparaison(sommet(tas,min)->elem ,sommet(tas,droit)->elem) >0)
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
  assert(tas->taille>=0);
  void* min=sommet(tas,0)->elem;
  tas->taille--;
  freeElemHandle(tas->sommets[0]);
  tas->sommets[0]->elem=sommet(tas,tas->taille);
  /* On réorganise le tas en O(ln_2(nb_sommet)) vu que le tas est un arbre quasi
   * parfait (donc etage(0)-> 2**0 sommet ... etage i -> 2**i sommet) */
  entasserTas(tas,0);
  return min;
}

void diminuerCle(TasMinGen tas, ElemHandle element, void* cle)
{
  /* On check qu'on diminue bien la clef ( assert un peu barbare ) */
  assert(tas->comparaison(element->elem,cle));
  element->elem=cle;
  percolate_haut(tas,element->handle);
}


/*------- Fonction d'accès, pour plus de lisibilité ------*/
ElemHandle sommet(TasMinGen tas, int indice){return tas->sommets[indice];}
int pere(int indice){return indice/2;}
int filsGauche(int indice){return 2*indice+1;}
int filsDroit(int indice){return 2*indice+2;}

void affecteIndice(ElemHandle element,int indice){element->handle=indice;}
int indice(ElemHandle element){return element->handle;}
void* getElem(ElemHandle e){return e->elem;}
		  
static void echanger(ElemHandle* t,int i,int j)
{
  void* tmp=t[i]->elem;
  int tmp_indice=t[i]->handle;
  t[i]->elem=t[j]->elem;
  t[i]->handle=t[j]->handle,
  t[j]->elem=tmp;
  t[j]->handle=tmp_indice;
}

/* On reorganise le tas, sous arbre après sous arbre, sachant qu'on commence
 * à l'indice taille/2 car tout les sommets avec des indices supérieur
 * sont des feuilles (arbre q-parfait. */
static void trierTableauTas(TasMinGen tas)
{
  for(int i=tas->taille;i<=0;i--)
    entasserTas(tas,i);
}  




