#ifndef _ARBREPLANAIREGEN
#define _ARBREPLANAIREGEN

/**
 * \file ArbrePlanaireGenerique.h
 * \author Delmas Rémi
 * \brief Module pour la création et les opérations utilisables sur les arbres planaires génériques
*/

#include <stdbool.h>

typedef void (*ptr_affichage)(void*);
typedef struct noeud *Noeud;
typedef struct arbrePlanaireGen *ArbrePlanaireGen;


/**
 * \brief Crée un noeud.
 * \param Un pointeur générique et trois noeuds pour déterminer la place du noeud crée par rapport à ceux déjà existant.
*/
Noeud creerNoeud(void* element,Noeud parent,Noeud aine,Noeud cadet);


/**
 * \brief Libère l'espace mémoire alloué à un noeud.
 * \pre L'utilisateur doit avoir effacé le contenu du noeud.
*/
void freeNoeud(Noeud this);


/**
 * \brief Crée un arbre planaire générique vide.
 * \param Prend un ptr_affichage qui est un pointeur générique en paramètre.
*/
ArbrePlanaireGen creerArbrePlanaireGen(ptr_affichage f);

/**
 * \brief Libère l'espace mémoire alloué à un arbre planaire générique après avoir détruit l'arbre récursivement.
 * \pre L'utilisateur doit avoir effacé le contenu de l'arbre.
*/
void freeArbrePlanaireGen(ArbrePlanaireGen this);

/**
 * \brief Retourne l'élément stocké dans un noeud.
*/
void* getElement(Noeud this);

/**
 * \brief Retourne le premier fils d'un noeud.
*/
Noeud getPremierFils(Noeud this);

/**
 * \brief Retourne le père d'un noeud.
*/
Noeud getPere(Noeud this);

/**
 * \brief Retourne le frère d'un noeud.
*/
Noeud getFrere(Noeud this);

/**
 * \brief Retourne la racine d'un arbre planaire générique.
*/
Noeud getRacine(ArbrePlanaireGen this);

/**
 * \brief Affiche le parcours préfixe récursif de l'arbre.
*/
void affichagePrefixe(ArbrePlanaireGen this);


/**
 * \brief Ajoute un fils à un noeud en lui donnant l'élément elem.
 * \pre Il faut mettre le père à NULL pour l'ajout en tant que racine.
*/
Noeud ajouterFils(ArbrePlanaireGen a,Noeud pere,void* elem);

/**
 * \brief Retourne faux si le noeud entré en paramètre à un fils, vrai s'il n'en a pas.
*/
bool estFeuille(Noeud this);

/**
 * \brief Supprime un noeud d'un arbre planaire après avoir libéré l'espace mémoire à l'entier contenu dans le noeud.
 * \post le noeud supprimé est remplacé par son frere s'il était le premier fils de son père, sinon le frère de son frère devient le frère du sommet à détruire.
*/
void supprimerNoeud(ArbrePlanaireGen a,Noeud this);


#endif
