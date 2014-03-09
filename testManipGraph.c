#include "manipGraph.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

//On fera un module contenant les fonctions standart de manipulation de matrice.
void afficherMatrice(double** mat,int taille)
{
  printf("\nAffichage matrice rentrée:\n");
  for(int i=0;i<taille;i++)
  {
    for(int j=0;j<taille;j++)
      printf("%.2lf ",mat[i][j]);
    printf("\n");
  }
}

double** InitMat10(int taille,double (*matrice)[10])
{
  double** mat=malloc(taille*sizeof(double *));
  for(int i=0;i<taille;i++){
    mat[i]=malloc(taille*sizeof(double));
    for(int j=0;j<taille;j++)
      mat[i][j]=matrice[i][j];
  }
  return mat;
}

 

int main()
{
  double mat[10][10]={{0,9,4,11,10,8,8,13,10,16}, 
			  {9,0,7,2,7,9,13,10,15,11}, 
			  {4,7,0,7,6,4,6,9,8,12}, 
			  {11,2,7,0,5,7,11,8,13,9}, 
			  {10,7,6,5,0,2,6,3,8,6}, 
			  {8,9,4,7,2,0,4,5,6,8}, 
			  {8,13,6,11,6,4,0,5,2,8}, 
			  {13,10,9,8,3,5,5,0,5,3}, 
			  {10,15,8,13,8,6,2,5,0,6}, 
			  {16,11,12,9,6,8,8,3,6,0}};
  double** matrice=InitMat10(10,mat);
  afficherMatrice(matrice,10);
  Graphe g = creeGraph(10,matrice);
  afficherGraphe(g);
  printf("\n\n--- Plus Proche Voisin ---\n");
  for(int i=0;i<5;i++)
  {
    printf("\nRun %d:\n",i);
    HeuristiquePlusProcheVoisin(g);
  }
  free(g);
}
  
				
