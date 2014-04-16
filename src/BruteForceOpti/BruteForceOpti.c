/**
 * \file BruteForceOpti.c
 * \brief Fichier source qui contient les fonctions mettant en place un heuristique de Bruteforce optimisé.
 */




#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <Graphe.h>
#include <NearestNeighbour.h>
#include <Input.h>
#include <BruteForceOpti.h>



/**
 * \brief Déclaration des fonctions statiques.
 * Les fonctions statiques ne sont pas nécessaires dans le .h car seul ce fichier les utilisera.
 */


/*------ Declaration des fonctions statiques ------*/
static void copieTableauInt(int* tabSrc,int* tabDst,int taille);
static void afficherTab(int* tab, int taille);
static void BruteForceOptiRecursif(Graphe g,
				   int indicePrecedent,
				   int profondeur,
				   double distanceChemin,
				   int* tabChemin,
				   bool* tabEstValide,
				   double* meilleureDistance,
				   int* meilleurChemin);





/*------ Implémentation des fonctions du module ------*/




/**
 * \brief Fonction appliquant le brute force optimisé.
 * Cette fonction appelle la fonction BruteForceOptimise.qui va chercher tous les chemins possibles en 
 * ne testant que les chemins ayant la distance parcourue la plus courte et ne poursuit pas un 
 * chemin si sa distance est supérieure ou égale à la distance passée en paramètre. 
 */


int* BruteForceOpti(Graphe g,double* acc)
{
  double meilleureDistance=0;
  int taille=get_taille(g);
  /* On initialise le meilleur chemin et la meilleure distance comme celle de NearestNeigbour */
  int* meilleurChemin=HeuristiquePlusProcheVoisin(g,0,&meilleureDistance);

  /* Création d'un tableau de chemin*/
  int* tabChemin=calloc(taille+1,sizeof(int));

  /* Initialiser a false */
  bool* tabEstVisite=calloc(taille,sizeof(bool));

  int profondeur=0;
  /* On choisit arbitrairement 0 comme indice de départ */
  BruteForceOptiRecursif(g,0,0,0,tabChemin,tabEstVisite,&meilleureDistance,meilleurChemin);
  free(tabEstVisite); 
  free(tabChemin); 

  /* On affecte via effet de bord la meilleure distance a acc */
  *acc=meilleureDistance;

  return meilleurChemin;
}




/**
 * \brief Fonction appliquant le brute force mais de manière optimisée.
 * \param g Graphique correspondant à la matrice Tsp.
 * \param distanceChemin Double contenant la distance du chemin.
 * \param tabEstVisite Tableau de booléens servant à savoir si le sommet a été visité ou non.
 * \param meilleurChemin Tableau d'entiers contenant l'ordre des villes pour lequel on a la distance la plus petite.
 * Cette fonction recherche tous les chemins possibles en ne testant que les chemins ayant la distance parcourue 
 * la plus courte et ne poursuit pas un chemin si sa distance est supérieure ou égale à la distance passée en paramètre. 
 */



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
    /* Remet l'indice précédent comme disponible pour le retour d'appel 
     * Si l'on est rentré, on a donc un chemin qui sera forcément plus long que
     * le meilleurChemin car la distance entre deux ville est strictement positive */
    tabEstVisite[indicePrecedent]=false;
    return;
  }

  /* Cas où il faut refermer le chemin pour faire le cycle attendu */
  if(profondeur == taille)
  {
    distanceChemin+=distance_ville(g,indicePrecedent,tabChemin[0]);
    if (distanceChemin < *(meilleureDistance))
    {
      *(meilleureDistance)=distanceChemin;
      /* Pas besoin de copier jusqu'à l'indice taille sachant que cette valeur est déja 0 */
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
  


/**
 * \brief Fonction affichant le tableau passé en paramètre de longueur taille.
 */


static void afficherTab(int* tab, int taille)
{
  for(int i=0;i<taille;i++)
      printf("%d : %d\n",i,tab[i]);
  printf("\n");
}


/**
 * \brief Fonction copiant le tableau d'entiers tabSrc dans le tableau d'entiers tabDst d'une longueur taille..
 */



static void copieTableauInt(int* tabSrc,int* tabDst,int taille)
{
  for(int i=0;i<taille;i++)
    tabDst[i]=tabSrc[i];
}

  
