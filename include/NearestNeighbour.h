#ifndef NEAREST_NEIGHBOUR
#define NEAREST_NEIGHBOUR

#include <stdbool.h>
#include "Graphe.h"

int plusProcheVoisin(int sommet,bool* tab_dispo,Graphe graph,double* acc);
/**
 * \b Retourne un tableau désignant le chemin le plus court optenu par
 * l'algorithme du plus proche voisin.
 * \param graphe structure graphe(matrice2D double + taille matrice) contenant la matrice de
 * l'instance TSP associée et sa dimension.
 * \param distanceAcc /!\ la valeur pointée avant appel de HeuristiquePlusProcheVoisin est écrassée, 
 * on affecte la distance du chemin via effet de bord au double pointé.
 * \param depart entier en 0 et nombre_de_ville désignant la ville de depart du cycle.
 * \post le tableau doit etre free après traitement par le client.
 */
int* HeuristiquePlusProcheVoisin(Graphe graph,double* distanceAcc,int departChemin);

#endif
