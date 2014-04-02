#ifndef _TASMIN
#define _TASMIN

#include <stdbool.h>

typedef struct TasMinGen *TasMinGen;
typedef struct elemHandle *ElemHandle;
typedef int (*ptr_compar)(void*,void*);
typedef void (*ptr_affichage)(void*);
typedef void (*ptr_maj)(void* element,void* nouvelle_cle);

int getTailleTas(TasMinGen tas);

void setIndice(int indice,ElemHandle element);
int getIndice(ElemHandle element);
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
