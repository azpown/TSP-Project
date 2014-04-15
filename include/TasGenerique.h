#ifndef _TASMIN
#define _TASMIN

#include <stdbool.h>

/**
 * \file TasGenerique.h
 * \author Delmas Rémi
 * \brief Module de manipulation de la matrice de distance.
*/

typedef struct TasMinGen *TasMinGen;
typedef struct elemHandle *ElemHandle;
typedef int (*ptr_compar)(void*,void*);
typedef void (*ptr_affichage)(void*);
typedef void (*ptr_maj)(void* element,void* nouvelle_cle);

/**
 *\b Retourne le nombre d'élément contenu dans le tas min
*/
int getTailleTas(TasMinGen tas);

/**
 *\b Affecte un indice a un element du tas.
 *\param indice entier a affecté a l'ElemHandle correspondant a sa position dans la structure interne du tas
 *\param element cible de la modification d'indice.
 *\pre l'indice doit etre supérieur ou égal a 0.
*/
void setIndice(int indice,ElemHandle element);

/**
 *\b Retourne l'indice de l'ElemHandle passé en paramètre.
*/
int getIndice(ElemHandle element);

/**
 *\b Retourne l'élément contenu dans la structure ElemHandle passé en paramètre.
 *\pre element objet du tas dont on veut l'element.
*/
void* getElem(ElemHandle e);

void setElem(void * obj,ElemHandle element);

ElemHandle creerElemHandle(void *element,int indice);
void freeElemHandle(ElemHandle elem);
TasMinGen creerTasMinGen(int taille,ptr_compar cmp,ptr_compar cmpCle,ptr_affichage affichage,ptr_maj majCle);
void freeTasGen(TasMinGen tas);

bool estvide(TasMinGen tas);
ElemHandle ajouterSommet(TasMinGen tas, void* element);
void entasserTas(TasMinGen tas,int indice);
void* extraireMin(TasMinGen tas);
void diminuerCle(TasMinGen tas, ElemHandle element, void* cle);

void affichageTas(TasMinGen tas);
ElemHandle sommet(TasMinGen tas, int indice);

/* A voir si ce qui suit est utile, mais je pense pas */
int pere(int indice);
int filsGauche(int indice);
int filsDroit(int indice);
		  
#endif
