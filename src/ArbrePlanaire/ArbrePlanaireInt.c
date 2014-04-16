/**
 * \file ArbrePlanaireGenerique.c
 * \brief Fichier source qui contient les fonctions mettant en place un arbre planaire d'entier.
 */



#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ArbrePlanaireInt.h>

struct arbrePlanaireInt
{
  ArbrePlanaireGen arbre;
};


/*------ Declaration des fonctions statiques ------*/

/**
 * \brief Fonction qui alloue de la mémoire.
 * alloue de la mémorie d'un taille n.
 */

static int* homogeneise(int n);

/**
 * \brief Fonction qui rempli un tableau.
 * Rempli un tableau à l'aide d'éléments présent dans un arbre
 */

static void remplirTab(Noeud this,int* tab,int* indice,int taille);

/**
 * \brief Fonction qui 
 */

static void ajouter(Noeud this,int* tab,int* indice);


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
  free(getElement(this));
}

int getInt(Noeud this)
{
  return *((int *)getElement(this));
}

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
  freeInt(this);
  supprimerNoeud(a->arbre,this);
}
  
void afficheInt(void* elem)
{
  printf("%d -> ",*((int *)elem));
}

void tableauArbreInt(ArbrePlanaireInt this,int* tab,int taille)
{
  int indice=0;
  remplirTab(getRacine(this->arbre),tab,&indice,taille);
}

static void remplirTab(Noeud this,int* tab,int* indice,int taille)
{
  assert(*indice<taille);
  ajouter(this,tab,indice);
  if(!estFeuille(this))
    remplirTab(getPremierFils(this),tab,indice,taille);
  if(getFrere(this))
    remplirTab(getFrere(this),tab,indice,taille);
}

static void ajouter(Noeud this,int* tab,int* indice)
{
  tab[*indice]=(int) *((int*) getElement(this));
  *(indice)+=1;
}
