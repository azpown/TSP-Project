#ifndef _BRUTEFORCE
#define _BRUTEFORCE

#include "Graphe.h"
#include <stdbool.h>


int sommet_suivant(bool* tab_dispo, Graphe graph);
bool* creer_tab_dispo(int nombreSommets);
double calculDistanceParcours(Graphe graph, int* parcours);
int* BruteForce2 (Graphe graph, int nbVilles, int* parcours,bool* libre, double distanceParcours);
int* euristiqueBruteForce2 (Graphe graph);

#endif
