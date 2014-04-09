#ifndef _PRIM
#define _PRIM

#include <Graphe.h>

/**
 * \b Retourne un tableau désignant le chemin le plus court optenu par
 * l'algorithme de Prim (contruction d'un arbre de poid couvrant minimal).
 * \param g graphe (matrice2D double + taille matrice) contenant la matrice de
 * l'instance TSP associée et sa dimension.
 * \param depart entier en 0 et nombre_de_ville désignant la ville de depart du cycle.
 * \param acc /!\ la valeur pointée avant appel de Prim est écrassée, on affecte la distance 
 * du chemin via effet de bord au double pointé.
 * \post le tableau doit etre free après traitement par le client.
 */
int* Prim(Graphe g, int depart,double* acc);


#endif
