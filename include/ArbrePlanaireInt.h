#ifndef _ARBREPLANAIREINT
#define _ARBREPLANAIREINT

/**
 * \file ArbrePlanaireInt.h
 * \author Delmas Rémi
 * \brief Module pour la création et les opérations utilisables sur les arbres planaires qui contiennent des int
*/

#include <ArbrePlanaireGenerique.h>

typedef struct arbrePlanaireInt *ArbrePlanaireInt;


/**
 * \brief Crée un arbrePlanaireInt vide.
*/
ArbrePlanaireInt creerArbrePlanaireInt();

/**
 * \brief Libère l'espace mémoire alloué à un arbrePlanaireInt.
 * \pre Avant d'appeler cette fonction, il faut avoir libéré les valeurs contenues dans l'arbre.
*/
void freeArbrePlanaireInt(ArbrePlanaireInt this);

/**
 * \brief renvoie la valeur entière stockée dans le noeud entré en paramètre.
*/
int getInt(Noeud this);

/**
 * \brief remplit le tableau tab avec les valeurs contenues dans l'arbrePlanaireInt en parcours préfixe.
 * \param tab un tableau qui doit être déjà instancié.
*/
void tableauArbreInt(ArbrePlanaireInt this,int* tab,int taille);

/**
 * \brief Affiche le parcours préfixe récursif de l'arbre.
*/
void affichagePrefixeInt(ArbrePlanaireInt this);

/**
 * \brief Ajoute un noeud pere contenant l'entier elem à un arbrePlanaireInt.
*/
Noeud ajouterNoeudInt(ArbrePlanaireInt this,Noeud pere,int elem);

/**
 * \brief Retourne vrai si le noeud entré en paramètre est une feuille.
*/
bool estUneFeuille(Noeud this);

/**
 * \brief Supprime un noeud d'un arbrePlanaireInt après avoir libéré la mémoire allouée à l'entier contenu dans le noeud.
 * \post le noeud supprimé est remplacé par son frere s'il était le premier fils de son père, sinon le frère de son frère devient le frère du sommet à détruire.
*/
void supprimerNoeudInt(ArbrePlanaireInt a,Noeud this);

/**
 * \brief Affiche l'entier contenu dans un noeud.
*/
void afficheInt(void* elem);

/**
 * \brief Libère l'espace mémoire alloué à l'entier stocké dans un noeud.
*/
void freeInt(Noeud this);

#endif
