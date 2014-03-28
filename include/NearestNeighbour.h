#ifndef NEAREST_NEIGHBOUR
#define NEAREST_NEIGHBOUR

#include <stdbool.h>
#include "Graphe.h"

int plusProcheVoisin(int sommet,bool* tab_dispo,Graphe graph,double* acc);
double* HeuristiquePlusProcheVoisin(Graphe graph);

#endif
