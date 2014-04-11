#include <NearestNeighbour.h>
#include <Graphe.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <assert.h>

/*------ Déclaration fonction statique ------ */
static int randAB(int a,int b);
static void initialiseTrueN(bool* tab,int taille);

static int randAB(int a,int b)
{
  static bool first = true;
  if(first)
  {
    /* Initialisation de rand */
    srand(time(NULL)); /* Initialisation de rand */
    first=false;
  }
  return rand()%(b-a) +a; /* Tire un nombre dans l'intervalle [a,b[ */
}

static void initialiseTrueN(bool* tab,int taille)
{
  for(int i=0;i<taille;i++)
    *(tab+i)=true;
}

int plusProcheVoisin(int sommet,bool* tabDispo,Graphe graph,double* acc)
/* Le type sommet sera surrement implémenté plus tard, pour une question de lisibilité.*/
{
  /* effet de bord sur acc passé en parametre. */
  int taille=get_taille(graph);
  int min=-1;
  double distance=-1;
  double tmp=-1;
  for(int i=0;i<taille;i++)
  {
    if(tabDispo[i]==true)
    {
      tmp=distance_ville(graph,sommet,i);
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

int* HeuristiquePlusProcheVoisin(Graphe graph,double* distanceAcc,int departChemin)
{
  *(distanceAcc)=0;
  int taille=get_taille(graph);
  /* Allocation du tableau de retour (taille + ville depart). */
  int* tab=malloc(taille+1*sizeof(double));

  bool* tabAParcourir= malloc(taille*sizeof(bool));
  initialiseTrueN(tabAParcourir,taille);
  /* On crée un tableau de bool,pour savoir quels sont les sommets déjà dans le chemin.*/

  int alloue= 1; //Nombre de ville deja visitée

  /* On tire une ville aléatoirement, je mettrai sans doute un paramètre ville depart plus tard.*/
  int dernierVisite=departChemin;
  tab[alloue-1]=dernierVisite;
  tabAParcourir[dernierVisite]=false;
  while (alloue < taille)
  {
    dernierVisite=plusProcheVoisin(dernierVisite,tabAParcourir,graph,distanceAcc);
    alloue++;
    tabAParcourir[dernierVisite]=false;
    tab[alloue-1]=dernierVisite;
  }
  /* Il faut relier le chemin a la ville de départ maintenant.*/
  *(distanceAcc)+=distance_ville(graph,dernierVisite,departChemin);
  /* distanceAcc contient la distance du chemin a la fin du parcour. */
  tab[alloue]=departChemin;
  return tab;
}

      

  

	  
      
      
      
      
  
  



