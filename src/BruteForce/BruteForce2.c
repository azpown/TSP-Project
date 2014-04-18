#include "BruteForce.h"
#include "Graphe.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "ArbrePlanaireInt.h"
#include "ArbrePlanaireGenerique.h"


void BruteForce2 (Graphe graph, int nbVilles, int* parcours,bool* libre, double distanceParcours,int* parcoursFinal);

bool* creer_tab_dispo(int nombreSommets);

int sommet_suivant(bool* tab_dispo, Graphe graph);

static void initialise_true_n(bool* tab,int taille);


static void initialise_true_n(bool* tab,int taille) // Initialise un tableau de booléens à true
{
  for(int i=0;i<taille;i++)
    tab[i]=true;
}




int sommet_suivant(bool* tab_dispo, Graphe graph) // Retourne le prochain sommet qui n'a pas encore été visité
{
  int taille=get_taille(graph);
  for (int i=0; i<taille; i++)
  {
    if (tab_dispo[i])
    {
      tab_dispo[i]=false; // marque dans le tableau que le sommet renvoyé va être visité
      return i;
    }
  }
  return EXIT_SUCCESS;
}



//rajouter un paramètre qui est le nombre d'éléments du tableau 
bool* creer_tab_dispo(int nombreSommets)// creer un tableau contenant les disponnibilités des sommets
{
  bool* tab_dispo= malloc(nombreSommets*sizeof(bool));
  initialise_true_n(tab_dispo, nombreSommets);
  tab_dispo[0]=false;// on retire la disponnibilitée du sommet de départ
  return tab_dispo;
}





double parcoursSimple(Graphe graph){
  double distance = 0;
  int taille = get_taille(graph);
  for (int j=1; j<taille; j++)
      distance += distance_ville(graph, j-1, j);
  distance += distance_ville(graph, 0, taille-1);
  return distance;
}




double calculDistanceParcours(Graphe graph,int taille, int* parcours){
  double distance = 0;
  for(int i=1 ; i<=taille; i++)
  {
    if (parcours[i])
      distance += distance_ville(graph, parcours[i], parcours[i-1]);
  }
  distance += distance_ville(graph,parcours[taille-1],parcours[0]);
  return distance;
}

/* Cette fonction contient une erreur, à un moment on essaie d'accéder à une des cases d'un tableau pour lequel la mémoire allouée a 
   déjà  été libérée */
void BruteForce2 (Graphe graph, int nbVilles, int* parcours,bool* libre, double distanceParcours,int *parcoursFinal)
{
  int taille=get_taille(graph);

  int i=nbVilles;
  while(i<taille)
  {
    bool* tabDispo = creer_tab_dispo(nbVilles);
    for (int j=1; j<nbVilles; j++)
      tabDispo[j]=libre[j];
    int* nouveauChemin = malloc(taille+1*sizeof(int));
    for (int k=0; k<taille; k++)
      nouveauChemin[k]= parcours[k];
    if (calculDistanceParcours(graph,nbVilles, nouveauChemin)<distanceParcours && nbVilles==taille-1)
    {
      distanceParcours=calculDistanceParcours(graph,nbVilles, nouveauChemin);
      for(int l=0; l<=taille; l++)
	parcoursFinal[l]=nouveauChemin[l];
    }
    nouveauChemin[nbVilles] = sommet_suivant(tabDispo,graph);
    nbVilles ++;
    BruteForce2(graph,nbVilles,nouveauChemin,tabDispo,distanceParcours,parcoursFinal); 
    free(tabDispo);
    free(nouveauChemin);
  }
  if (calculDistanceParcours(graph, taille+1, parcoursFinal)<distanceParcours)
    free(parcours);  
}

int* algorithmeBruteForce2 (Graphe graph){
  int taille=get_taille(graph);
  bool* libre = creer_tab_dispo(1);
  int* parcours = malloc(taille+1*sizeof(int));
  parcours[0]=0;
  double distance=parcoursSimple(graph);
  int* parcoursFinal = malloc(taille+1*sizeof(int));/*tableau contenant le trajet le plus court au final*/
  BruteForce2(graph, 1, parcours, libre, distance,parcoursFinal);
  return parcoursFinal;
}
