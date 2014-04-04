#include "BruteForce.h"
#include "Graphe.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>

/*------ Déclaration fonction statique ------ */
static void initialise_true_n(bool* tab,int taille);


static void initialise_true_n(bool* tab,int taille) // Initialise un tableau de booléens à true
{
  for(int i=0;i<taille;i++)
    *(tab+i)=true;
}


int sommet_suivant(bool* tab_dispo, Graphe graph, int ville_depart) // Retourne le prochain sommet qui n'a pas encore été visité
{
  int taille=get_taille(graph);
  for (int i=0; i<taille; i++)
  {
    if (tab_dispo[i] && i!=ville_depart)
    {
      tab_dispo[i]=false; // marque dans le tableau que le sommet renvoyé va être visité
      return i;
    }
  }
  return ville_depart;
}

bool* creer_tab_dispo(Graphe graph, int departChemin)// creer un tableau contenant les disponnibilités des sommets
{
  int taille=get_taille(graph);
  bool* tab_dispo= malloc(taille*sizeof(bool));
  initialise_true_n(tab_dispo, taille);
  tab_dispo[departChemin]=false;// on retire la disponnibilitée du sommet de départ
  return tab_dispo;
}




int* BruteForce(Graphe graph,int departChemin, double distanceAcc)// retourne le chemin le plus court parmis tous les chemins possibles
{
  int taille = get_taille(graph);
  bool* tab_dispo = creer_tab_dispo(graph, departChemin);//creer le tableau de disponnibilités
  int* chemin_le_plus_court=malloc(taille+1*sizeof(int));//tableau contenant le trajet le plus court au final
  int* retourEnArriere = malloc(taille*sizeof(int));//sauvegarde les sommets par lesquels on est passé pour pouvoir y revenir 
  int* dernier_Visite = malloc(taille*sizeof(int));// sauvegarde les derniers sommets visités que l'on va modifier au cours de l'algo
  chemin_le_plus_court[0]=departChemin;//innitialise le sommet de départ dans le tableau de retour
  double distance = 0;
  int dernierVisite = departChemin;
  int aRetirer = 0;//compteur du nombre de sommet à retirer au tableau retourEnArriere
  int nbAjouts_Dernier_Visite=0;//compteur du nombre de sommet à retirer au tableau dernier_Visite
  int cptSommetsChemin = 1;
  while (!aucun_dispo(graph, tab_dispo))// arrete le while si tous les sommets sont indisponibles
  {
    for(int i=0;i<taille;i++)
    {
      if(distance<distanceAcc)//si le chemin est plus long ou aussi long que celui de distance distanceAcc on passe au else qui effectue le retour en arrière
      {
	distance += distance_ville(graph, dernierVisite, sommet_suivant(tab_dispo, graph, departChemin));
	dernierVisite = sommet_suivant(tab_dispo, graph,dernierVisite);
	dernier_Visite[nbAjouts_Dernier_Visite] = dernierVisite;
	nbAjouts_Dernier_Visite ++;
	tab_dispo[dernierVisite]=false;
	retourEnArriere[aRetirer] = dernierVisite;
	aRetirer ++;
	chemin_le_plus_court[cptSommetsChemin]=dernierVisite;
	cptSommetsChemin++;
      }
      else
      {
	for (int j = aRetirer; j>0 ; j--)
	{
	  if (retourEnArriere[aRetirer]==departChemin)
	  {
	    if (retourEnArriere[aRetirer-1]==dernierVisite)
	      aRetirer--;
	    tab_dispo[retourEnArriere[aRetirer-1]]=true;
	    distance -= distance_ville(graph, retourEnArriere[aRetirer-1], retourEnArriere[aRetirer]);
	    aRetirer -=2;
	   }
	  if (retourEnArriere[aRetirer]==dernierVisite)
	      aRetirer--;
	  else
	  {
	    distance -= distance_ville(graph, retourEnArriere[aRetirer-1], retourEnArriere[aRetirer]);
	    tab_dispo[retourEnArriere[aRetirer]]=true;
	    aRetirer --;
	  }
	  cptSommetsChemin--;
	  nbAjouts_Dernier_Visite--;
	}
      }
    }
    if(distance<distanceAcc){// effectue un nouveau test en cas d'arrivée à la fin de la boucle for et que la distance de parcours soit supérieure ou égale à distanceAcc suite au dernier ajout
      //   for(int i=1;i<taille;i++)
      //	for(int j=0;j<taille;j++)
      //  chemin_le_plus_court[i]=dernier_Visite[j];
      chemin_le_plus_court[cptSommetsChemin]=dernierVisite;
      distanceAcc=distance;
      distance = 0;
    }
  } 
  if(distance<distanceAcc){// effectue un nouveau test en cas d'arrivée à la fin de la boucle for et que la distance de parcours soit supérieure ou égale à distanceAcc suite au dernier ajout
    for(int i=1;i<taille;i++)
      for(int j=0;j<taille;j++)
	chemin_le_plus_court[i]=dernier_Visite[j];
  }
  chemin_le_plus_court[taille+1]=departChemin;
  return chemin_le_plus_court;
}


double premierChemin(Graphe graph,int departChemin) //renvoie la distance parcourue pars le parcours le plus simple (departChemin -> 0 -> 1 > 2 ...)
{
  double distanceAcc = 0;
  int taille = get_taille(graph);
  int* tab=malloc(taille*sizeof(int));
  for (int i=0; i<taille; i++)
    tab[i] = i;
  int dernierVisite = departChemin;
  for (int j=0; j<taille; j++)
    if(j != departChemin)
    {
      distanceAcc += distance_ville(graph, dernierVisite, j);
      dernierVisite = j;
    }
  distanceAcc += distance_ville(graph, dernierVisite, departChemin);
  return distanceAcc;
}

bool aucun_dispo(Graphe graph, bool* tab_dispo) // renvoie true si tous les sommets ont été parcourus en un seul trajet
{
  for (int i=0; i<get_taille(graph); i++)
    if (tab_dispo[i])
      return false;
  return true;
}



int* HeuristiqueBruteForce (Graphe graph,int departChemin){
  return BruteForce(graph, departChemin, premierChemin(graph, departChemin));
}

