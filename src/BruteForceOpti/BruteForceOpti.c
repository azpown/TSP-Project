#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <Graphe.h>
#include <NearestNeighbour.h>
#include <Input.h>
#include <BruteForceOpti.h>

/*------ Declaration des fonctions statiques ------*/
static void afficherTab(int* tab, int taille);
static void copieTableauInt(int* tabSrc,int* tabDst,int taille);
static void swap(int i,int j,int* tab);
static void BruteForceOptiRecursif(Graphe g,
				   int indicePrecedent,
				   int profondeur,
				   double distanceChemin,
				   int* tabChemin,
				   bool* tabEstValide,
				   double* meilleureDistance,
				   int* meilleurChemin);


/*------ Implémentation des fonctions du module ------*/

int* BruteForceOpti(Graphe g,double* acc)
{
  double meilleureDistance=0;
  int taille=get_taille(g);
  /* On initialise le meilleur chemin et la meilleur distance comme celle de NearestNeigbourg */
  int* meilleurChemin=HeuristiquePlusProcheVoisin(g,&meilleureDistance,0);

  /* Création d'un tableau de chemin*/
  int* tabChemin=calloc(taille+1,sizeof(int));

  /* Initialiser a false */
  bool* tabEstVisite=calloc(taille,sizeof(bool));

  int profondeur=0;
  /* On choisit arbitrairement 0 comme indice de départ */
  BruteForceOptiRecursif(g,0,0,0,tabChemin,tabEstVisite,&meilleureDistance,meilleurChemin);
  free(tabEstVisite); 
  free(tabChemin); 

  printf("meilleureDistance : %.1lf\n",meilleureDistance);
  *acc=meilleureDistance;

  int* tabReturn = malloc(taille+1 * sizeof(int));
  copieTableauInt(meilleurChemin,tabReturn,taille+1);
  //free(meilleurChemin);
  return tabReturn;
}

static void BruteForceOptiRecursif(Graphe g,
				   int indicePrecedent,
				   int profondeur,
				   double distanceChemin,
				   int* tabChemin,
				   bool* tabEstVisite,
				   double* meilleureDistance,
				   int* meilleurChemin)
{
  int taille=get_taille(g);
  tabChemin[profondeur]=indicePrecedent;
  tabEstVisite[indicePrecedent]=true;
  profondeur++;
  
  /* printf("Valeur en cour : %.1lf - Profondeur : %d\n",distanceChemin,profondeur); */
  if(distanceChemin >= *(meilleureDistance))
  {
    /* Remet l'indice precedent comme disponible pour le retour d'appel 
     * Si l'on est rentré, on a donc un chemin qui sera forcement plus long que
     * le meilleurChemin car la distance entre deux ville est strictement positive */
    tabEstVisite[indicePrecedent]=false;
    return;
  }

  /* Cas où il faut refermé le chemin pour faire le cycle attendu */
  if(profondeur == taille)
  {
    distanceChemin+=distance_ville(g,indicePrecedent,tabChemin[0]);
    if (distanceChemin < *(meilleureDistance))
    {
      *(meilleureDistance)=distanceChemin;
      /* Pas besoin de copié jusqu'a l'indice taille sachant que cette valeur est déja 0 */
      copieTableauInt(tabChemin,meilleurChemin,taille);
    }
  }
    
  for(int i=1;i<taille;i++)
  {
    if(!tabEstVisite[i])
      BruteForceOptiRecursif(g,
			     i,
			     profondeur,
			     distanceChemin+distance_ville(g,indicePrecedent,i),
			     tabChemin,
			     tabEstVisite,
			     meilleureDistance,
			     meilleurChemin);
  }
  tabEstVisite[indicePrecedent]=false;
  return;
}
  

static void copieTableauInt(int* tabSrc,int* tabDst,int taille)
{
  for(int i=0;i<taille;i++)
    tabDst[i]=tabSrc[i];
}

static void afficherTab(int* tab, int taille)
{
  for(int i=0;i<taille;i++)
      printf("%d : %d\n",i,tab[i]);
  printf("\n");
}

