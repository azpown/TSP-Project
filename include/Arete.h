#ifndef ARETE
#define ARETE

/**
 * \file Arete.h
 * \author Delmas Rémi
 * \brief Module pour la création d'arêtes et les opérations dessus.
*/

typedef struct Arete *Arete;

/**
 * \brief Crée une arête.
 * \param Un double, et deux int représentant une ville de départ et une ville d'arrivée.
*/
Arete creerArete(double cle,int depart,int arrive);

/**
 * \brief Retourne -1 si la clé de l'arête à est infèrieure celle de l'arête b, 1 si elle lui est supérieure ou 0 si elles sont égales.
*/
int comparaisonArete(Arete a,Arete b);

/**
 * \brief Retourne -1 si la clé de l'arête à est supérieure à la clé entrée en paramètre, 1 si elle lui est supérieure ou 0 si elles sont égales.
*/
int comparaisonAreteCle(Arete a,double cle);

/**
 * \brief Libère l'espace mémoire alloué à l'arête entrée en paramètre.
*/
void freeArete(Arete a);

/**
 * \brief Affiche les valeurs des données membres d'une arête sous la forme (Depart: villeDépart     Arrive: villeArrivée     Cle: valeurClé.
*/
void afficheArete(Arete a);

/**
 * \brief Retourne la clé de l'arête entrée en paramètre.
*/
double getCle(Arete a);

/**
 * \brief Retourne le départ(une ville) de l'arête entrée en paramètre.
*/
int getDepart(Arete a);

/**
 * \brief Retourne l'arrivée(une ville) de l'arête entrée en paramètre.
*/
int getArrive(Arete a);

/**
 * \brief Donne une valeur (double) à une clé. 
*/
void setCle(double value,Arete a);

/**
 * \brief Modifie la ville de départ de l'arête entrée en paramètre.
*/
void setDepart(int depart,Arete a);

/**
 * \brief Modifie la ville d'arrivée de l'arête entrée en paramètre.
*/
void setArrive(int arrive,Arete a);

#endif
