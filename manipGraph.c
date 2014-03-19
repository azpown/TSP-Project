#include "manipGraph.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <assert.h>

/* Il faudra faire un module dédié a la partie ALGO */

struct graphe 
{
  int taille;
  double** matrice;
};

Graphe creeGraph(int len,double** mat)
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

void freeGraph(Graphe graph)
{
  for(int i=0;i<graph->taille;i++)
    free(graph->matrice[i]);
  free(graph->matrice);
  free(graph);
}

int rand_a_b(int a,int b)
{
  srand(time(NULL)); /* Initialisation de rand */
  return rand()%(b-a) +a; /* Tire un nombre dans l'intervalle [a,b[ */
}

double distanceSommetFullMatrice(Graphe graph,int s1,int s2)
{ 
  return graph->matrice[s1][s2];
}

void initialise_true_n(bool* tab,int taille)
{
  for(int i=0;i<taille;i++)
    *(tab+i)=true;
}

void afficherGraphe(Graphe g)
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

int plusProcheVoisin(int sommet,bool* tab_dispo,Graphe graph,double* acc)
/* Le type sommet sera surrement implémenté plus tard, pour une question de lisibilité */
{
  int taille=graph->taille;
  int min=-1;
  double distance=-1;
  double tmp=-1;
  for(int i=0;i<taille;i++)
  {
    if(tab_dispo[i]==true)
    {
      tmp=distanceSommetFullMatrice(graph,sommet,i);
      if(tmp<distance || distance == -1)
      {
	distance=tmp;
	min=i;
      }
    }
  }
  *acc +=distance;
  return min;
}

double* HeuristiquePlusProcheVoisin(Graphe graph)
{
  double distanceAcc=0;
  int taille=graph->taille;
  double* tab=malloc(taille+1*sizeof(double));
  bool* tab_a_parcourir= malloc(taille*sizeof(bool));
  initialise_true_n(tab_a_parcourir,taille);
  // On crée un tableau de bool,pour savoir quels sont les sommets déjà dans le chemin
  int alloue= 1; //Nombre de ville deja visitée
  int dernierVisite=rand_a_b(0,taille);
  int depart=dernierVisite; 
  tab[alloue-1]=dernierVisite;
  tab_a_parcourir[dernierVisite]=false;
  while (alloue < taille)
  {
    dernierVisite=plusProcheVoisin(dernierVisite,tab_a_parcourir,graph,&distanceAcc);
    alloue++;
    tab_a_parcourir[dernierVisite]=false;
    tab[alloue-1]=dernierVisite;
  }
  distanceAcc+=distanceSommetFullMatrice(graph,dernierVisite,depart);
  tab[alloue]=depart;
  return tab;
}

      
	  
	   
  
  

	  
      
      
      
      
  
  



