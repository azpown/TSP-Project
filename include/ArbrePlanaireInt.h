#ifndef _ARBREPLANAIREINT
#define _ARBREPLANAIREINT

#include <ArbrePlanaireGenerique.h>

typedef struct arbrePlanaireInt *ArbrePlanaireInt;

ArbrePlanaireInt creerArbrePlanaireInt();
void freeArbrePlanaireInt(ArbrePlanaireInt this);
int getInt(Noeud this);
void tableauArbreInt(ArbrePlanaireInt this,int* tab,int indice);
void affichagePrefixeInt(ArbrePlanaireInt this);
Noeud ajouterNoeudInt(ArbrePlanaireInt this,Noeud pere,int elem);
bool estUneFeuille(Noeud this);
void supprimerNoeudInt(ArbrePlanaireInt a,Noeud this);
void afficheInt(void* elem);
void freeInt(Noeud this);

#endif
