#ifndef _TAS_ARETE
#define _TAS_ARETE

/**
 * \file Graphe.h
 * \author Delmas Rémi
 * \brief Module de manipulation de la matrice de distance.
*/

#include <stdbool.h>
#include "Arete.h"

typedef struct TasArete *TasMinArete;
typedef struct AreteHandle *AreteHandle;

/**
 * \brief Crée un tas min contenant des arêtes.
*/
TasMinArete creerTasMinArete(int taille);

/**
 * \brief Libère l'espace mémoire alloué à un tas min contenant des arêtes
*/
void freeTasArete(TasMinArete tasMin);

/**
 * \brief Libère l'espace mémoire alloué à une areteHandle contenant des elemHandle (une structure contenant un pointeur générique et un int).
*/
void freeAreteHandle(AreteHandle a);

/**
 * \brief Ajoute une areteHandle à un tas min d'arêtes, la fonction l'ajoute d'abord en tant que feuille puis la positionne à un endroit
 * \ qui fait en sorte que le tas reste un tas min.
 * \post Il faut que le tas ne soit pas plein, la fonction le vérifie.
*/
AreteHandle ajouterAreteHandle(TasMinArete tasMin, Arete a);

/**
 * \brief Vérifie si un tas min d'arêtes est vide (le champ taille de la structure est à -1 dans le cas où le tas est vide).
*/
bool estVide(TasMinArete tasMin);

/**
 * \brief Retourne l'arete minimale contenue dans tasMIn.
*/
Arete extraireAreteMin(TasMinArete tasMin);

/**
 * \brief Affiche 'CONTENU DU TAS MIN' puis en dessous, une ligne de la liste des arêtes contenues dans tasMin
*/
void affichageTasArete(TasMinArete tasMin);

/**
 * \brief Retourne l'indice de la donnée membre arete contenue dans l'AreteHandle areteH passée en paramètre.
*/
int indiceAreteHandle(AreteHandle areteH);

/**
 * \brief Retourne la donnée membre arete contenue dans l'AreteHandle areteH passée en paramètre.
*/
Arete getArete(AreteHandle areteH);

/**
 * \brief Cette fonction donne à la clé de l'arete de areteH la valeur de newCle dans le cas ou newCle est inférieure et
 * \ elle fait en sorte que le tas reste un tas min en échangeant les sommets reliés par l'arete si besoin.
 * \pre la fonction s'arrête si la clé entrée en paramètre n'est pas infèrieure à la clé contenue dans la donnée membre
 * \ arete de areteH.
 * \post les deux sommets reliés par l'arete de areteH sont échangés si c'est nécessaire pour que le tas reste min.
*/
void diminuerCleArete(TasMinArete tas_a, AreteHandle areteH,double newCle);


#endif
