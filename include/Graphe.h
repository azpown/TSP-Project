/**
 * \file Graphe.h
 * \author Delmas Rémi
 * \brief Module de manipulation de la matrice de distance.
*/

#ifndef GRAPHE
#define GRAPHE

typedef struct graphe * Graphe;


/**
 * \brief Fonction de création d'une instance de Graphe.
 * \param len Dimension de la matrice de distance, strictement positive.
 * \param mat Matrice 2D contenant les distances entre chaque villes.
 * \post L'instance doit etre free avec free_graphe
*/
Graphe cree_graphe(int len,double** mat);

/**
 *\brief Fonction de destruction d'une instance Graphe.
*/
void free_graphe(Graphe graphe);

/**
 * \brief Affiche une contenu instance de type Graphe sous la forme :
 * Affichage de la structure graphe:
 * Taille : <len>
 * Matrice :
 * <numVille>- <distance00>- <distance01>- ...
 * (deux décimale affichées uniquement.)
 * \param input Instance de type Graphe à afficher.
*/
void afficher_graphe(Graphe g);

/**
 * \brief Retourne la distance entre deux villes d'indice s1 et s2 dans graphe.
 * L'ordre n'a pas d'importance. 
*/
double distance_ville(Graphe graphe,int s1,int s2);

/**
 * \brief Retourne le nombre de ville dans l'instance graphe.
*/
int get_taille(Graphe graphe);

double get_double(Graphe g,int i,int j);

#endif
