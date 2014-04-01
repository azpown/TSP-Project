#ifndef _TASMIN
#define _TASMIN

#include <stdbool.h>

typedef struct TasMinGen *TasMinGen;
typedef struct elemHandle *ElemHandle;
typedef int (*ptr_compar)(void*,void*);
typedef void (*ptr_affichage)(void*);
typedef void (*ptr_affectation)(void* element,void* nouvelle_cle);

void setAffichage(TasMinGen tas,ptr_affichage fonction);
void setComparaison(TasMinGen tas,ptr_compar fonction);
void setTailleTas(TasMinGen tas,int taille);
int getTailleTas(TasMinGen tas);

void affecteIndice(ElemHandle element,int indice);

ElemHandle creerElemHandle(void *element,int indice);
void freeElemHandle(ElemHandle elem);
TasMinGen creerTasMinGen(int taille,ptr_compar cmp,ptr_affichage affichage);
bool estvide(TasMinGen tas);
void affichageTas(TasMinGen tas);
void freeTasGen(TasMinGen tas);
ElemHandle ajouterSommet(TasMinGen tas, void* element);
void entasserTas(TasMinGen tas,int indice);
void* extraireMin(TasMinGen tas);
void diminuerCle(TasMinGen tas, ElemHandle element, void* cle);

void* getElem(ElemHandle e);
ElemHandle sommet(TasMinGen tas, int indice);

/* A voir si ce qui suit est utile, mais je pense pas */
int pere(int indice);
int indice(ElemHandle e);
int filsGauche(int indice);
int filsDroit(int indice);
		  
#endif
