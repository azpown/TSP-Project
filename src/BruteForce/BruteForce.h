#ifndef _BRUTEFORCE
#define _BRUTEFORCE

#include "Graphe.h"
#include <stdbool.h>


int sommet_suivant(bool* tab_dispo, Graphe graph, int ville_depart);
bool* creer_tab_dispo(Graphe graph, int departChemin);
int* BruteForce(Graphe graph,int departChemin, double distanceAcc);
double premierChemin(Graphe graph,int departChemin);
bool aucun_dispo(Graphe graph, bool* tab_dispo);
int* HeuristiqueBruteForce (Graphe graph,int departChemin);

#endif
