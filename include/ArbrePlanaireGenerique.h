#ifndef _ARBREPLANAIREGEN
#define _ARBREPLANAIREGEN

#include <stdbool.h>

typedef void (*ptr_affichage)(void*);
typedef struct noeud *Noeud;
typedef struct arbrePlanaireGen *ArbrePlanaireGen;

Noeud creerNoeud(void* element,Noeud parent,Noeud aine,Noeud cadet);
void freeNoeud(Noeud this);
ArbrePlanaireGen creerArbrePlanaireGen(ptr_affichage f);
void freeArbrePlanaireGen(ArbrePlanaireGen this);
void* getElem(Noeud this);
Noeud getPremierFils(Noeud this);
Noeud getPere(Noeud this);
Noeud getFrere(Noeud this);
Noeud getRacine(ArbreBinaireGen this);
void** parcourPrefixe(int taille,ArbrePlanaireGen this);
void freeParcourPrefixe(void** this)
void affichagePrefixe(ArbrePlanaireGen this);
void parcourPrefixe(void** this);
void ajouterFils(ArbrePlanaireGen a,Noeud pere,void* elem);
bool estFeuille(Noeud this);
void supprimerNoeud(ArbrePlanaireGen a,Noeud this);


#endif