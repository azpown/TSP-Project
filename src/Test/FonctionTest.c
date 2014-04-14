#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

bool estDimensionValide(double dim,double meilleureDistance,int nbVille)
{
  /* On verifie que la distance est compris etre la meilleure distance et la plus petite possible */
  return dim <= meilleureDistance && dim>0;
}

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
