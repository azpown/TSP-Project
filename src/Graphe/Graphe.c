/**
 * \file Graphe.c
 * \brief Fichier source qui contient les fonctions mettant en place un graphe correspondant à une matrice.
 */



#include <Graphe.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>



/**
 * \struct graphe
 * \brief Crée un graphe ayant pour longueur taille et en paramètre des doubles contenus dans une matrice.
 */


struct graphe 
{
  int taille;
  double** matrice;
};


/**
 * \struct graphe
 * \brief Crée un graphe ayant pour longueur len et contient des doubles contenus dans une matrice.
 * \param mat Tableau de tableau (tableau "2D") contenant des doubles.
 */

Graphe cree_graphe(int len,double** mat)
{
  Graphe g=malloc(sizeof(struct graphe));
  assert(len>0);
  g->taille=len;
  g->matrice=malloc(len*sizeof(double *));
  for(int i=0;i<len;i++)
  {
    g->matrice[i]=malloc(len*sizeof(double));
    for(int j=0;j<len;j++)
      g->matrice[i][j]=mat[i][j];
  }
  return g;
}


/**
 * \brief Fonction permettant la suppression d'un graphe.
 */

void free_graphe(Graphe graphe)
{
  for(int i=0;i<graphe->taille;i++)
    free(graphe->matrice[i]);
  free(graphe->matrice);
  free(graphe);
}


/**
 * \brief Fonction permettant d'afficher le graphe passé en paramètre.
 */

void afficher_graphe(Graphe g)
{
  printf("\nAffichage de la structure graphe:\nTaille : %d\nMatrice :\n ",g->taille);
  for(int i=0;i< g->taille;i++)
  {
    printf("%d- ",i);
    for(int j=0;j< g->taille;j++)
      printf("%.2lf ",g->matrice[i][j]);
    printf("\n");
  }
}


/**
 * \brief Fonction retournant le double se situant à la position[i][j] .
 */


double get_double(Graphe g,int i,int j)
{
  return g->matrice[i][j];
}


/**
 * \brief Fonction retournant la distance se situant à la position[s1][s2].
 */

double distance_ville(Graphe graphe,int s1,int s2)
{ 
  return graphe->matrice[s1][s2];
}


/**
 * \brief Fonction retournant la taille du graphe passé en paramètre.
 */

int get_taille(Graphe graphe)
{
  return graphe->taille;
}
