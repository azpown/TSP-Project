#ifndef _TAS_ARETE
#define _TAS_ARETE

#include <stdbool.h>
#include "Arete.h"

typedef struct TasArete *TasMinArete;
typedef struct AreteHandle *AreteHandle;

TasMinArete creerTasMinArete(int taille);
void freeTasArete(TasMinArete tasMin);
void freeAreteHandle(AreteHandle a);
bool estVide(TasMinArete tasMin);
AreteHandle ajouterAreteHandle(TasMinArete tasMin, Arete a);
void entasserTasArete(TasMinArete tasMin, int indice);
Arete extraireAreteMin(TasMinArete tasMin);
void affichageTasArete(TasMinArete tasMin);
int indiceTas(AreteHandle areteH);
Arete getArete(AreteHandle areteH);

#endif
