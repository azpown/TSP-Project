/**
 * \file Prim.c
 * \brief Fichier source qui contient les fonctions implémentant l'algorithme de Prim.
 */


#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdio.h> 
#include <ArbrePlanaireInt.h> 
#include <Arete.h>
#include <TasArete.h>
#include <Graphe.h>
#include <Prim.h>



/**
 * \brief Algorithme de Prim servant à créer un arbre de poids minimum.
 * \param g Graphe représentant la matrice.
 * \param depart Entier représentant la ville de départ du graphe g.
 * \param acc Tableau de booléens contenant la distance des villes.
 */



/* Effet de bord de acc <- contient la taille du cycle */
int* Prim(Graphe g,int depart,double* acc)
{
  /*------ Allocation de la mémoire necessaire et Init.------*/
  const int taille=get_taille(g);
  assert(depart<taille);
  /* On crée les tableaux des références pour modification dans la routine et free */
  TasMinArete tas = creerTasMinArete(taille);
  AreteHandle* tabH=malloc(taille*sizeof(AreteHandle));
  Arete* tabA =malloc(taille*sizeof(Arete));
  
  /* Contruction du tas min -> Initialisation avec les distances par rapport a départ. */
  for(int i=0;i<taille;i++)
    if(i!=depart)
      tabH[i]=ajouterAreteHandle(tas,tabA[i]= creerArete(distance_ville(g,depart,i),depart,i));
  
  ArbrePlanaireInt arbre=creerArbrePlanaireInt();
  /* Ce tableau sert pour libérer la mémoire et pour tester l'éligibilité d'une ville dans la routine*/
  Noeud* tabN=calloc(taille+1,sizeof(Noeud)); 
  /* Creation de la racine de l'arbre : depart */
  tabN[depart]=ajouterNoeudInt(arbre,NULL,depart); 

  /* Routine de traitement */
  Arete min;
  int ville;
  while(!estVide(tas))
  {
    /* On extrait le minimum du tas */
    min=extraireAreteMin(tas);
    ville=getArrive(min);
    /* On ajoute l'entier correspondant au sommet dans l'arbre planaire
     * son père est le départ de l'arête */
    tabN[ville]=ajouterNoeudInt(arbre,tabN[getDepart(min)],ville);

    for(int i=0;i<taille;i++)
    {
      if(i!=depart && !tabN[getArrive(getArete(tabH[i]))] && (distance_ville(g,ville,getArrive(getArete(tabH[i]))) < getCle(getArete(tabH[i]))))
      {
	/* !tab_dispo car le tableau est initialisé a false 
	 * Si la ville n'a pas été ajoutée et que la distance par rapport à ville
	 * est plus petite que la précédente, on actualise. */

	setDepart(ville,getArete(tabH[i]));
	/* On diminue la clef, le tas se reorganise en conséquence. */
	diminuerCleArete(tas,tabH[i],distance_ville(g,ville,getArrive(getArete(tabH[i]))));
      }
    }
  }

  *acc=0;

  /* Création du tableau pour le retour */
  int *tab=malloc((taille+1) *sizeof(int));
  /* On remplie le tableau avec les valeurs correspondantes dans l'arbre 
  * avec un parcours prefixe de ce dernier */
  tableauArbreInt(arbre,tab,taille+1);
  tab[taille]=depart;
  for(int i=0;i<taille;i++)
  {
    *acc+=distance_ville(g,tab[i],tab[i+1]);
    if(i!=depart)
    {
      freeAreteHandle(tabH[i]);
      freeArete(tabA[i]);
    }
    freeInt(tabN[i]);
  }
  freeArbrePlanaireInt(arbre);
  freeTasArete(tas);
  free(tabN);
  free(tabH);
  free(tabA);
  return tab;
}
