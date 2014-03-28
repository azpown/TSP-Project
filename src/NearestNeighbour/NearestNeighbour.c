<<<<<<< HEAD
#include <NearestNeighbour.h>
#include <Graphe.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <assert.h>

/*------ Déclaration fonction statique ------ */
static int rand_a_b(int a,int b);
static void initialise_true_n(bool* tab,int taille);

static int rand_a_b(int a,int b)
{
  srand(time(NULL)); /* Initialisation de rand */
  return rand()%(b-a) +a; /* Tire un nombre dans l'intervalle [a,b[ */
}

static void initialise_true_n(bool* tab,int taille)
{
  for(int i=0;i<taille;i++)
    *(tab+i)=true;
}

int plusProcheVoisin(int sommet,bool* tab_dispo,Graphe graph,double* acc)
/* Le type sommet sera surrement implémenté plus tard, pour une question de lisibilité.*/
{
  /* effet de bord sur acc passé en parametre. */
  int taille=get_taille(graph);
  int min=-1;
  double distance=-1;
  double tmp=-1;
  for(int i=0;i<taille;i++)
  {
    if(tab_dispo[i]==true)
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

double* HeuristiquePlusProcheVoisin(Graphe graph)
{
  double distanceAcc=0;
  int taille=get_taille(graph);
  /* Allocation du tableau de retour (taille + ville depart). */
  double* tab=malloc(taille+1*sizeof(double));

  bool* tab_a_parcourir= malloc(taille*sizeof(bool));
  initialise_true_n(tab_a_parcourir,taille);
  /* On crée un tableau de bool,pour savoir quels sont les sommets déjà dans le chemin.*/

  int alloue= 1; //Nombre de ville deja visitée

  /* On tire une ville aléatoirement, je mettrai sans doute un paramètre ville depart plus tard.*/
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
  /* Il faut relier le chemin a la ville de départ maintenant.*/
  distanceAcc+=distance_ville(graph,dernierVisite,depart);
  /* On pourra eventuellement mettre un parametre distance qui sera un double*
   * ou on mettra la distance du chemin via effet de bord.*/  
  tab[alloue]=depart;
  return tab;
}

      
	  
	   
  
  

	  
      
      
      
      
  
  



