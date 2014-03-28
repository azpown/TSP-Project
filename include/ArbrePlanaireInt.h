#ifndef _ARBREPLANAIREINT
#define _ARBREPLANAIREINT

#include <stdbool.h>

typedef struct noeudInt *NoeudInt;
typedef struct arbrePlanaireInt *ArbrePlanaireInt;
NoeudInt creerNoeudInt(int elem,NoeudInt parent,NoeudInt aine,NoeudInt cadet);
void freeNoeudInt(NoeudInt this);
ArbrePlanaireInt creerArbrePlanaireInt();
void freeArbrePlanaireInt(ArbrePlanaireInt this);
int getInt(NoeudInt this);
int* parcourPrefixeInt(int taille,ArbrePlanaireInt this);
void affichagePrefixeInt(ArbrePlanaireGen this);
NoeudInt ajouterNoeudInt(ArbrePlanaireInt this,NoeudInt pere,int elem);
bool estUneFeuille(NoeudInt this);
void supprimerNoeud(ArbrePlanaireInt a,NoeudInt this);
void afficheInt(void* elem);
