/**
 * \file NearestNeighbour.c
 * \brief Fichier source qui contient les fonctions mettant en place l'heuristique de NearestNeighbour.
 * Programme créant l'heuristique de NearestNeighbour.
 *
 */

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


/**
 * \brief Fonction permettant de générer un nombre aléatoire entre les entiers a et b.
 */

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


/**
 * \brief Fonction permettant d'initialiser un tableau de booléens à True.
 */

static void initialiseTrueN(bool* tab,int taille)
{
  for(int i=0;i<taille;i++)
    *(tab+i)=true;
}


/**
 * \brief Fonction permettant de retourner le voisin ayant la distance la plus proche de celui où l'on est.
 * \param sommet Entier correspondant au numéro du sommet actuel dans le graphe.
 * \param tabDispo Tableau de booléan servant à savoir la liste des villes qui n'ont pas été visitées.
 * \param graph Représente la matrice TSP.
 * \param acc Tableau de double contenant les distance des villes.
 */

int plusProcheVoisin(int sommet,bool* tabDispo,Graphe graph,double* acc)
/* Le type sommet sera sûrement implémenté plus tard, pour une question de lisibilité.*/
{
  /* effet de bord sur acc passé en paramètre. */
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



/**
 * \brief Fonction permettant de retourner un tableau de voisins ayant la distance la plus proche avec la ville précédente.
 * \param distanceAcc Tableau de booléens contenant les distances entre les villes.
 * \param departChemin Entier correspondant à la ville de départ.
 * \param graph Représente la matrice TSP.
 */

int* HeuristiquePlusProcheVoisin(Graphe graph,int departChemin,double* distanceAcc)
{
  *(distanceAcc)=0;
  int taille=get_taille(graph);
  /* Allocation du tableau de retour (taille + ville depart). */
  int* tab=malloc((taille+1)*sizeof(int));

  bool* tabAParcourir= malloc(taille*sizeof(bool));
  initialiseTrueN(tabAParcourir,taille);
  /* On crée un tableau de bool,pour savoir quels sont les sommets déjà dans le chemin.*/

  int alloue= 1; //Nombre de ville deja visitées
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
  free(tabAParcourir);
  /* Il faut relier le chemin a la ville de départ maintenant.*/
  *(distanceAcc)+=distance_ville(graph,dernierVisite,departChemin);
  /* distanceAcc contient la distance du chemin a la fin du parcours. */
  tab[alloue]=departChemin;
  return tab;
}

      

  

	  
      
      
      
      
  
  



