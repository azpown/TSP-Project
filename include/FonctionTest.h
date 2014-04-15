#ifndef _TEST
#define _TEST

/**
 * \file FonctionTest.h
 * \author Delmas Rémi
 * \brief Module contenant les fonctions de test pur les executables des tests
*/

#include <stdbool.h>
#include <Graphe.h>

typedef int* (*HeuristiqueAvecDepart)(Graphe g,int depart,double* acc);
typedef int* (*HeuristiqueSansDepart)(Graphe g,double* acc);

void testBaseHeuristiqueAD(char* nomFichier,int depart,HeuristiqueAvecDepart H);
void testBaseHeuristiqueSD(char* nomFichier,HeuristiqueSansDepart H);
bool estDimensionValide(double dim,double meilleureDistance);
void afficheCycle(int* tabCycle,int taille,double valeur);
/**
 * \brief retourne la validité du parcours entré en paramètre.
 * \param tabCycle un tableau d'entiers représentant un parcours de villes.
*/
bool estCycleValide(int* tabCycle,int taille);
void freeHeurisque(Graphe g,int* tabCycle);
Graphe getGraphe(char* nomFichier);

#endif
