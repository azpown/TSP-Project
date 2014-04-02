#ifndef _TAS_ARETE
#define _TAS_ARETE

#include <stdbool.h>
#include "Arete.h"

typedef struct TasArete *TasMinArete;
typedef struct AreteHandle *AreteHandle;

TasMinArete creerTasMinArete(int taille);
void freeTasArete(TasMinArete tasMin);
void freeAreteHandle(AreteHandle a);
AreteHandle ajouterAreteHandle(TasMinArete tasMin, Arete a);

bool estVide(TasMinArete tasMin);
void entasserTasArete(TasMinArete tasMin, int indice);
Arete extraireAreteMin(TasMinArete tasMin);
void affichageTasArete(TasMinArete tasMin);

int indiceAreteHandle(AreteHandle areteH);
Arete getArete(AreteHandle areteH);

void diminuerCleArete(TasMinArete tas_a, AreteHandle areteH,double newCle);


#endif
