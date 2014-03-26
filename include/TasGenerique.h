#ifndef _TASMIN
#define _TASMIN

#include <stdbool.h>

typedef struct TasMinGen *TasMinGen;
typedef int (*ptr_compar)(void*,void*);
typedef void (*ptr_affichage)(void*);

void setAffichage(TasMinGen tas,ptr_affichage fonction);
void setTableau(TasMinGen tas,void** tab,int taille);
void setComparaison(TasMinGen tas,ptr_compar fonction);
void setTailleTas(TasMinGen tas,int taille);
int getTailleTas(TasMinGen tas);


TasMinGen creerTasMinGen(int taille,ptr_compar cmp,ptr_affichage affichage);
bool estvide(TasMinGen tas);
void affichageTas(TasMinGen tas);
void freeTasGen(TasMinGen tas);
void ajouterSommet(TasMinGen tas, void* elem);
void entasserTas(TasMinGen tas,int indice);
void* extraireMin(TasMinGen tas);

/* A voir si ce qui suit est utile, mais je pense pas */

void* sommet(TasMinGen tas, int indice);
int pere(int indice);
int filsGauche(int indice);
int filsDroit(int indice);
		  
#endif
