/**
 * \file Arete.c
 * \brief Fichier source qui contient les fonctions générant des arêtes.
 */



#include <stdlib.h>
#include <stdio.h>
#include <Arete.h>

/**
 * \struct Arete
 * \brief Arête entre la ville depart et la ville arrive.
 */

struct Arete
{
  double cle;
  int depart;
  int arrive;
};


/**
 * \brief Fonction créant une arête entre la ville de départ et la ville d'arrivée associée à une clé.
 * \param depart Entier correspondant à la ville de départ.
 * \param arrive Entier correspondant à la ville d'arrivée.
 */


Arete creerArete(double cle,int depart,int arrive)
{
  Arete a=malloc(sizeof(struct Arete));
  a->cle=cle;
  a->depart=depart;
  a->arrive=arrive;
  return a;
}


/**
 * \brief Fonction comparant deux arêtes en vérifiant si elles ont la même clé.
 */

int comparaisonArete(Arete a,Arete b)
{
  /* On compare uniquement la clé */
  double cmp=a->cle - b->cle;
  if(cmp<0)
    return -1;
  if(cmp>0)
    return 1;
  return 0;
}


/**
 * \brief Fonction comparant une arête et une clé.
 */

int comparaisonAreteCle(Arete a,double cle)
{
  double cmp=a->cle - cle;
  if(cmp<0)
    return -1;
  if(cmp>0)
    return 1;
  return 0;
}  

/**
 * \brief Fonction libérant l'arête passée en paramètre.
 */

void freeArete(Arete a){free(a);}


/**
 * \brief Fonction affichant l'arête passée en paramètre.
 */

void afficheArete(Arete a)
{
  printf("Depart: %d\tArrive: %d\tCle: %.1lf\n",a->depart,a->arrive,a->cle);
}


/**
 * \brief Fonction retournant la clé de l'arête passée en paramètre.
 */


double getCle(Arete a){return a->cle;}


/**
 * \brief Fonction retournant la ville de départ de l'arête passée en paramètre.
 */


int getDepart(Arete a){return a->depart;}


/**
 * \brief Fonction retournant la ville d'arrivée de l'arête passée en paramètre.
 */


int getArrive(Arete a){return a->arrive;}


/**
 * \brief Fonction donnant une clé à l'arête passée en paramètre.
 */


void setCle(double value,Arete a)
{
  a->cle=value;
}


/**
 * \brief Fonction donnant une ville de départ à l'arête passée en paramètre.
 */


void setDepart(int depart,Arete a){a->depart=depart;}


/**
 * \brief Fonction donnant une ville d'arrivée à l'arête passée en paramètre.
 */


void setArrive(int arrive,Arete a){a->arrive=arrive;}

