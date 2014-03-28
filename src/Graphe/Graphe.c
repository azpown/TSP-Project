#include <Graphe.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct graphe 
{
  int taille;
  double** matrice;
};

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

void free_graphe(Graphe graphe)
{
  for(int i=0;i<graphe->taille;i++)
    free(graphe->matrice[i]);
  free(graphe->matrice);
  free(graphe);
}

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

double distance_ville(Graphe graphe,int s1,int s2)
{ 
  return graphe->matrice[s1][s2];
}

int get_taille(Graphe graphe)
{
  return graphe->taille;
}
