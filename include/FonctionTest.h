#ifndef _TEST
#define _TEST

#include <stdbool.h>

/**
 * \file FonctionTest.h
 * \author Delmas Rémi
 * \brief Module contenant les fonctions de test pur les executables des tests
*/

/**
 * \brief retourne la validité du parcours entré en paramètre.
 * \param tabCycle un tableau d'entiers représentant un parcours de villes.
*/
bool estCycleValide(int* tabCycle,int taille);


bool estDimensionValide(double dim,double meilleureDistance,int nbVille);


void afficheCycle(int* tabCycle,int taille,double valeur);

#endif
