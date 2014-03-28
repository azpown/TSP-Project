#ifndef NEAREST_NEIGHBOUR
#define NEAREST_NEIGHBOUR

#include <stdbool.h>
#include "Graphe.h"

int plusProcheVoisin(int sommet,bool* tab_dispo,Graphe graph,double* acc);
int* HeuristiquePlusProcheVoisin(Graphe graph,double* distanceAcc,int departChemin);

#endif
