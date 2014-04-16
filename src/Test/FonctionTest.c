/**
 * \file FonctionTest.c
 * \brief Programme de tests.
 *
 * Programme de test qui vérifie les solutions des algorithmes.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <FonctionTest.h>
#include <Graphe.h>
#include <Input.h>

/* Ces deux fonctions ne sont pas si facilement factorisable, les heuristiques
 * pouvant avoir des signatures différentes.
 * On va néanmoins appliquer cette fonction a chaque heuristique, il est donc
 * utile de créer ces fonctions de factorisation des modules de tests.*/
void testBaseHeuristiqueAD(char* nomFichier,int depart,HeuristiqueAvecDepart H)
{
  Graphe g= getGraphe(nomFichier);
  double acc=0;
  int* resultat=H(g,depart,&acc);
  afficheCycle(resultat,get_taille(g),acc);
  if(estCycleValide(resultat,get_taille(g)))
    printf("OK\n");
  else
    printf("ECHEC");
  freeHeuristique(g,resultat);
}

void testBaseHeuristiqueSD(char* nomFichier,HeuristiqueSansDepart H)
{
  Graphe g= getGraphe(nomFichier);
  double acc=0;
  int* resultat=H(g,&acc);
  afficheCycle(resultat,get_taille(g),acc);
  if(estCycleValide(resultat,get_taille(g)))
    printf("OK\n");
  else
    printf("ECHEC");
  freeHeuristique(g,resultat);
}



/**
 *\brief Fonction vérifiant si la solution est un cycle n'ayant qu'une seule fois chaque ville (sauf la première et la dernière qui doivent être identique).
 *\param tabCyble Tableau contenant des entiers correspondant aux villes.
 *\param taille Entier correspondant à la taille du tableau tabCycle.
 */

bool estCycleValide(int* tabCycle,int taille)
{
  bool* estPresentUneSeuleFois=calloc(taille,sizeof(bool));
  for(int i=0;i<taille;i++)
  {
    /* On vérifie que chaque ville n'est présente qu'une seule fois*/
    if(tabCycle[i]>=0 && tabCycle[i]<taille && !estPresentUneSeuleFois[tabCycle[i]])
      estPresentUneSeuleFois[tabCycle[i]]=true;
    else
    {
      free(estPresentUneSeuleFois);
      return false;
    }
  }
  free(estPresentUneSeuleFois);
  /* On vérifie qu'il s'agit bien d'un cycle */
  return tabCycle[0]==tabCycle[taille];     
}

/**
 *\brief Fonction vérifiant si la solution renvoie un résultat possible.
 *\param dim Double contenant une distance.
 *\param meilleureDistance Double contenant la distance du chemin min. d'un graphe.
 */
bool estDimensionValide(double dim,double meilleureDistance)
{
  /* On vérifie que la distance est supérieure ou égale à la meilleure distance */
  return dim >= meilleureDistance;
}


/**
 *\brief Fonction qui affiche le tableau(cycle) en paramètre avec sa valeur.
 */

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

Graphe getGraphe(char* nomFichier)
{
    Input in=open_TSP_file(nomFichier);
    Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
    free_input(in);
    return g;
}

void freeHeuristique(Graphe g,int* tabCycle)
{
  free_graphe(g);
  free(tabCycle);
}
