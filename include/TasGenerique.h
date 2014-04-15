#ifndef _TASMIN
#define _TASMIN

#include <stdbool.h>

/**
 * \file TasGenerique.h
 * \author Delmas Rémi
 * \brief Module de manipulation de la matrice de distance.
*/

typedef struct TasMinGen *TasMinGen;
typedef struct elemHandle *ElemHandle;
typedef int (*ptr_compar)(void*,void*);
typedef void (*ptr_affichage)(void*);
typedef void (*ptr_maj)(void* element,void* nouvelle_cle);

/**
 * \b Retourne le nombre d'élément contenu dans le tas min
*/
int getTailleTas(TasMinGen tas);

/**
 * \b Affecte un indice a un element du tas.
 * \param indice entier a affecté a l'ElemHandle correspondant a sa position dans la structure interne du tas
 * \param element cible de la modification d'indice.
 * \pre l'indice doit etre supérieur ou égal a 0.
*/
void setIndice(int indice,ElemHandle element);

/**
 * \b Retourne l'indice de l'ElemHandle passé en paramètre.
*/
int getIndice(ElemHandle element);

/**
 * \b Retourne l'élément contenu dans la structure ElemHandle passé en paramètre.
 * \pre element objet du tas dont on veut l'element.
*/
void* getElem(ElemHandle e);

/**
 * \b Affete un ElemHandle à un pointeur générique.   
*/
void setElem(void * obj,ElemHandle element);

/**
 * \b Crée un ElemHandle et le renvoie.   
*/
ElemHandle creerElemHandle(void *element,int indice);

/**
 * \b Libère la mémoire allouée à un ElemHandle.  
*/
void freeElemHandle(ElemHandle elem);

/**
 * \b Crée un tas min générique vide.
 * \param   
*/
TasMinGen creerTasMinGen(int taille,ptr_compar cmp,ptr_compar cmpCle,ptr_affichage affichage,ptr_maj majCle);

/**
 * \b Libère l'espace mémoire alloué à un tas min générique. 
*/
void freeTasGen(TasMinGen tas);

/**
 * \b Teste si un tas min générique est vide.
*/
bool estvide(TasMinGen tas);

/**
 * \b ajoute un element à un tas min générique en vérifiant qu'il reste min.
 * \pre le tas min générique en parmètre ne doit pas être plein.
*/
ElemHandle ajouterSommet(TasMinGen tas, void* element);

/**
 * \brief Réorganise le tas en tas min à partir du sommet de nom indice entré en paramètre lorsque c'est nécessaire pour
 * \  préserver l'accés aux données.
*/
void entasserTas(TasMinGen tas,int indice);

/**
 * \b Retourne le plus petit élément du tas min générique.
 * \post Supprime l'élément qui est retourné et réorganise le tas en tas min.
*/
void* extraireMin(TasMinGen tas);

/**
 * \brief Cette fonction donne à la clé de elem de element la valeur de cle(entrée en paramètre) dans le cas ou cle est inférieure et
 * \ elle fait en sorte que le tas reste un tas min en échangeant les sommets reliés par l'arete si besoin.
 * \pre la fonction s'arrête si la clé entrée en paramètre n'est pas infèrieure à la clé contenue dans la donnée membre
 * \ elem de element.
 * \post les deux sommets reliés par l'arete contenue dans element sont échangés si c'est nécessaire pour que le tas reste min.
*/
void diminuerCle(TasMinGen tas, ElemHandle element, void* cle);

/**
 * \brief Affiche 'CONTENU DU TAS MIN' puis en dessous, une ligne de la liste des elements contenus dans tas.
*/
void affichageTas(TasMinGen tas);

/**
 * \brief Retourne l'ElemHandle situé à l'indice entré en paramètre de la donnée membre sommets[] de tas.
*/
ElemHandle sommet(TasMinGen tas, int indice);
		  
#endif
