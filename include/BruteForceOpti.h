#ifndef _BRUTEFORCEOPTI
#define _BRUTEFORCEOPTI

/**
 * \file BruteForceOpti.h
 * \author Delmas Rémi
 * \brief Module pour Branch and Bound
*/

#include <Graphe.h>

/**
 * \brief retourne un parcours de villes après avoir executé l'algorithme Branch and Bound sur un graphe.
 * \param g graphe récupéré à partir d'un .tsp
 * \pre L'accumulateur entré en paramètre doit être initialisé à 0.
*/
int* BruteForceOpti(Graphe g,double* acc);

#endif
