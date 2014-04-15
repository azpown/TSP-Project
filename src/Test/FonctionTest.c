#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <FonctionTest.h>
#include <Graphe.h>
#include <Input.h>

/* Ces deux fonctions ne sont pas si facilement factorisable, les heurisques
 * pouvant avoir des signatures différentes.
 * On va néanmois appliquer cette fonction a chaque heuristique, il est donc
 * utile de créé ces fonctions de factorisation des modules de tests.*/
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
  freeHeurisque(g,resultat);
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
  freeHeurisque(g,resultat);
}

bool estCycleValide(int* tabCycle,int taille)
{
  bool* estPresentUneSeuleFois=calloc(taille,sizeof(bool));
  for(int i=0;i<taille;i++)
  {
    /* On verifie que chaque ville est presente seule fois*/
    if(tabCycle[i]>=0 && tabCycle[i]<taille && !estPresentUneSeuleFois[tabCycle[i]])
      estPresentUneSeuleFois[tabCycle[i]]=true;
    else
    {
      free(estPresentUneSeuleFois);
      return false;
    }
  }
  free(estPresentUneSeuleFois);
  /* On verifie qu'il s'agit bien d'un cycle */
  return tabCycle[0]==tabCycle[taille];     
}

bool estDimensionValide(double dim,double meilleureDistance)
{
  /* On verifie que la distance est compris etre la meilleure distance et la plus petite possible */
  return dim >= meilleureDistance && dim>0;
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

Graphe getGraphe(char* nomFichier)
{
    Input in=open_TSP_file(nomFichier);
    Graphe g=cree_graphe(get_dimension(in),get_edge_weight_matrix(in));
    free_input(in);
    return g;
}

void freeHeurisque(Graphe g,int* tabCycle)
{
  free_graphe(g);
  free(tabCycle);
}
