#ifndef _BRUTEFORCE
#define _BRUTEFORCE

#include "Graphe.h"
#include <stdbool.h>

/**
 * \b retourne la distance parcourue lors d'un parcours.
*/
double calculDistanceParcours(Graphe graph,int taille, int* parcours);


/**
 * \b effectue l'algorithme force brute sur le graphe rentré en paramètre et renvoie le parcours optimal.
*/
int* algorithmeBruteForce2 (Graphe graph);

/**
 *\b retourne la distance parcourue lors du parcours [0,1,2,3, ... ,0]
*/
double parcoursSimple(Graphe graph);

#endif
