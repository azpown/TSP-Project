#include <ArbrePlanaireInt.h>
#include <ArbrePlanaireGen.h>
#include <stdlib.h>
#include <stdio.h>

struct arbrePlanaireInt
{
  ArbrePlanaireGen arbre;
};

struct noeudInt
{
  Noeud noeud;
};

/*------ Déclaration fonctions statiques ------*/
static void affichePtrInt(int* elem)

/*------ Allocation ------*/

NoeudInt creerNoeudInt(int elem,NoeudInt parent,NoeudInt aine,NoeudInt cadet)
{
  NoeudInt this=malloc(sizeof(struct noeudInt));
  this->noeud= creerNoeud((void *) &elem,parent,aine,cadet);
  return this;
}

void freeNoeudInt(NoeudInt this)
{
  freeNoeud(this->noeud);
  free(this);
}

ArbrePlanaireInt creerArbrePlanaireInt()
{
  ArbrePlanaireInt this=malloc(sizeof(struct arbrePlanaireInt));
  this->arbre= creerArbrePlanaireGen(afficheInt);
  return this;
}

void freeArbrePlanaireInt(ArbrePlanaireInt this)
{
  freeArbrePlanaireGen(this->arbre);
  free(this);
}

int getInt(NoeudInt this)
{
  return (int) *(getElem(this->noeud));
}

/* Une copie necessaire, surrement optimisable || pas de deleg pour cette fonction*/
int* parcourPrefixeInt(int taille,ArbrePlanaireInt this)
{
  void** tmp=parcourPrefixe(taille,this->arbre);
  int* tmp_int=calloc(taille,sizeof(int));
  for(int i=0;i<taille;i++)
    tmp_int=(int) *(tmp[i]);
  freeParcourPrefixe(tmp);
  return tmp_int;
}

void affichagePrefixeInt(ArbrePlanaireGen this)
{
  affichagePrefixe(this->arbre);
}

NoeudInt ajouterNoeudInt(ArbrePlanaireInt this,NoeudInt pere,int elem)
{
  ajouterFils(this->arbre,pere->noeud,&elem)
}

bool estUneFeuille(NoeudInt this)
{
  return estFeuille(this->noeud);
}

void supprimerNoeud(ArbrePlanaireInt a,NoeudInt this)
{
  supprimerNoeud(a->arbre,this->noeud);
}
  
void afficheInt(void* elem)
{
  affichePtrInt( (int*) elem);
}

static void affichePtrInt(int* elem)
{
  printf("%d -> ",*(elem));
}

  
