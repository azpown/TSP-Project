/**
 * \file FonctionTest.c
 * \brief Programme de tests.
 *
 * Programme de test qui vérifie les solutions des algorithmes.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



/**
 *\brief Fonction vérifiant si la solution est un cycle ayant qu'une seule fois chaque ville (sauf la première et la dernière).
 *\param tabCyble Tableau contenant des entiers correspondants aux villes.
 *\param taille Entier correspondant à la taille du tableau tabCycle.
 */

bool estCycleValide(int* tabCycle,int taille)
{
  bool* estPresentUneSeuleFois=calloc(taille,sizeof(bool));
  for(int i=0;i<taille;i++)
  {
    /* On verifie que chaque ville est presente seule fois*/
    if(tabCycle[i]>=0 && tabCycle[i]<taille && !estPresentUneSeuleFois[tabCycle[i]])
      estPresentUneSeuleFois[tabCycle[i]]=true;
    else
      free(estPresentUneSeuleFois);
      return false;
  }
  free(estPresentUneSeuleFois);
  /* On verifie qu'il s'agit bien d'un cycle */
  return tabCycle[0]==tabCycle[taille];
}


/**
 *\brief Fonction vérifiant si la solution a une meilleur dimension.
 *\param dim Double contenant la valeur de la distance la plus petite possible.
 *\param meilleureDistance Double contenant une distance.
 */

bool estDimensionValide(double dim,double meilleureDistance,int nbVille)
{
  /* On verifie que la distance est compris entre la meilleure distance et la plus petite possible */
  return dim <= meilleureDistance && dim>0;
}


/**
 *\brief Fonction qui affiche le tableau(cycle) en paramètre avec sa valeur.
 */

void afficheCycle(int* tabCycle,int taille,double valeur)
{
  printf("Chemin : "); 
  for(int i=0;i<taille;i++)
  {
    printf("%d -> ",tabCycle[i]);
  }
  printf("%d\n",tabCycle[taille]);
  printf("Taille chemin : %.1lf\n",valeur);
}
