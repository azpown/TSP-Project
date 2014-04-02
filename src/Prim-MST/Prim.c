#include <stdlib.h>
#include <assert.h>
#include <stdio.h> 
#include <ArbrePlanaireInt.h>
#include <TasArete.h>
#include <Graphe.h>
#include <Prim.h>

/* Effet de bord de acc <- contient la taille du cycle */
void Prim(Graphe g,int depart,double* acc)
{
  /*------ Allocation de la mémoire necessaire------*/
  *acc=0;
  const int taille=get_taille(g);
  assert(depart<taille);
  /* On crée les tableaux des références pour modification dans la routine et free */
  AreteHandle* ref_areteH=malloc(taille-1*sizeof(AreteHandle));
  /* Ce tableau sert pour libérer la mémoire et pour tester l'éligibilité d'une ville dans la routine*/
  Noeud* ref_noeud=calloc(taille,sizeof(Noeud));

  TasMinArete tas=creerTasMinArete(taille);
  ArbrePlanaireInt arbre=creerArbrePlanaireInt();

  /*------Phase d'initialisation------*/

  /* Creation de la racine de l'arbre : depart */
  ref_noeud[0]=ajouterNoeudInt(arbre,NULL,depart);
  
  /* Contruction du tas min -> Initialisation avec les distances par rapport a départ. */
  for(int i=0;i<taille;i++)
    if(i!=depart)
    {
      ref_areteH[i]=ajouterAreteHandle(tas,creerArete(distance_ville(g,depart,i),depart,i));
      affichageTasArete(tas);
    }

  /* Routine de traitement */
  Arete min;
  int ville;
  while(!estVide(tas))
  {
    /* On extrait le minimum du tas */
    min=extraireAreteMin(tas);
    ville=getArrive(min);
    
    /* On ajoute l'entier correspondant au sommet dans l'arbre planaire
     * son pere est le depart de l'arete */
    ref_noeud[ville]=ajouterNoeudInt(arbre,ref_noeud[getDepart(min)],ville);
    
    for(int i=0;i<taille;i++)
    {
      /* !tab_dispo car le tableau est initialisé a false 
       * Si la ville n'a pas été ajoutée et que la distance par rapport a ville
       * est plus petite que la précédente, on actualise. */
      if(!ref_noeud[i] && (distance_ville(g,ville,i) < getCle(getArete(ref_areteH[i]))))   
      {
	setDepart(ville,getArete(ref_areteH[i]));
	/* On diminue la clef, le tas se reorganise en conséquence. */
	diminuerCleArete(tas,ref_areteH[i],distance_ville(g,ville,i));
      }
    }
  }
  affichagePrefixeInt(arbre);
}
