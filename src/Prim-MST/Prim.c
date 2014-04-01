#include <stdlib.h>
#include <ArbrePlanaireInt.h>
#include <TasArete.h>
#include <Graphe.h>

/* Effet de bord de acc <- contient la taille du cycle */
int* Prim(Graphe g, int depart,int* acc)
{
  int taille=get_taille(g);
  /* On crée les tableaux des références pour modification dans la routine et free */
  Arete* ref_arete=malloc(taille-1*sizeof(Arete));
  Noeud* ref_noeud=malloc(taille*sizeof(Noeud));

  /* tab_dispo initialiser a false */
  bool* tab_dispo=calloc(taille,sizeof(bool*));

  TasMinArete tas=creerTasMinArete(taille);
  ArbrePlanaireInt arbre=creerArbrePlanaireInt();

  /* --Phase d'initialisation-- */
  
  /* Creation de la racine de l'arbre : depart */
  ref_noeud[0]=ajouterNoeudInt(this,NULL,depart);
  tab_dispo[0]=!tab_dispo[0];
  
  /* Contruction du tas min -> Initialisation avec les distances par rapport a départ. */
  for(int i=0;i<taille;i++)
    if(i!=depart)
      ajouterArete(tas,ref_arete[i]=creerArete(distance_ville(depart,i),depart,i));
  
  /* Routine de traitement */
  int cpt=1;
  Arete min;
  while(!estVide(tas))
  {
    min=extraireAreteMin(tas);
    int ville=getArrive(min);

    tab_dispo[ville]=true;

    for(int i=0;i<taille;i++)
      /* !tab_dispo car le tableau est initialisé a false 
       * Si la ville n'a pas été ajoutée et que la distance par rapport a ville
       * est plus petite que la précédente, on actualise. */
      if(!tab_dispo[i] && (distance_vile(g,ville,i) < getCle(ref_arete[i]))   
      {
	setDepart(ville,ref_arete[i]);
	setCle(getCle(ref_arete[i]))
    
  
  
}

