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

/**
 * \brief affiche OK si le test d'un heuristique qui prend une ville de départ en paramètre renvoie une solution valide, ECHEC sinon.
 * \param nomFichier chaîne de caractères représentant le nom d'un fichier TSP contenant un graphe.
*/
void testBaseHeuristiqueAD(char* nomFichier,int depart,HeuristiqueAvecDepart H);

/**
 * \brief affiche OK si le test d'un heuristique qui ne prend pas de ville de départ en paramètre renvoie une solution valide, ECHEC sinon.
 * \param nomFichier chaîne de caractères représentant le nom d'un fichier TSP contenant un graphe.
*/
void testBaseHeuristiqueSD(char* nomFichier,HeuristiqueSansDepart H);

/**
 * \brief Renvoie la validité de la dimension du parcours, si le parcours fait une distance inférieure au plus court chemin il est invalidé. 
*/
bool estDimensionValide(double dim,double meilleureDistance);
void afficheCycle(int* tabCycle,int taille,double valeur);
/**
 * \brief retourne la validité du parcours entré en paramètre.
 * \param tabCycle un tableau d'entiers représentant un parcours de villes.
*/
bool estCycleValide(int* tabCycle,int taille);

/**
 * \brief Libère la mémoire allouée au Graphe g et celle allouée au tableau contenant le parcours obtenu suite à l'execution d'un heuristique.
 * \ Cette fonction est appelé uniquement après l'execution d'un test.
*/
void freeHeuristique(Graphe g,int* tabCycle);

/**
 * \brief Retourne le Graphe contenu dans un fichier TSP.
 * \param nomFichier chaîne de caractères représentant le nom d'un fichier TSP contenant un graphe.
*/
Graphe getGraphe(char* nomFichier);

#endif
