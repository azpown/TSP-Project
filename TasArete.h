#ifndef _TAS_ARETE
#define _TAS_ARETE

#include <stdbool.h>

typedef struct TasArete *TasMinArete;

TasMinArete creerTasMinArete(int taille,ptr_compar cmp,ptr_affichage affichage);
void freeTasArete(TasMinArete tasMin);
bool estVide(TasMinArete tasMin);
void ajouterArete(TasMinArete tasMin, Arete a);
void entasserTasArete(TasMinArete tasMin, int indice);
Arete extraireAreteMin(TasMinArete tasMin);
void affichageTasArete(TasMinArete tasMin);

#endif
