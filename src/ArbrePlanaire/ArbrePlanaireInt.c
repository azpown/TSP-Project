#include <stdlib.h>
#include <stdio.h>
#include <ArbrePlanaireInt.h>

struct arbrePlanaireInt
{
  ArbrePlanaireGen arbre;
};

static int* homogeneise(int n);

/*------ Allocation ------*/

static int* homogeneise(int n)
{
  int* ptr = malloc(sizeof(int));
  *ptr = n;
  return ptr;
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

void freeInt(Noeud this)
{
  free(getElem(this));
}

int getInt(Noeud this)
{
  return *((int *)getElem(this));
}

/* Une copie necessaire, surrement optimisable || pas de deleg pour cette fonction*/
//int* parcourPrefixeInt(int taille,ArbrePlanaireInt this)
//{
//  void** tmp=parcourPrefixe(taille,this->arbre);
//  int* tmp_int=calloc(taille,sizeof(int));
//  int* cast;
//  for(int i=0;i<taille;i++)
//  {
//    cast=(int*) tmp[i];
//    tmp_int[i]=*(cast);
//  } 
//  freeParcourPrefixe(tmp);
//  return tmp_int;
//}

void affichagePrefixeInt(ArbrePlanaireInt this)
{
  affichagePrefixe(this->arbre);
}

/* Cette fonction assure l'homogéneité de la structure deleguée */
Noeud ajouterNoeudInt(ArbrePlanaireInt this,Noeud pere,int elem)
{
  return ajouterFils(this->arbre,pere,(void*) homogeneise(elem));
}

bool estUneFeuille(Noeud this)
{
  return estFeuille(this);
}

void supprimerNoeudInt(ArbrePlanaireInt a,Noeud this)
{
  supprimerNoeud(a->arbre,this);
}
  
void afficheInt(void* elem)
{
  printf("%d -> ",*((int *)elem));
}

  
