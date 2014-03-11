#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "creationTasMin.h"



struct ville{	//crée une structure ville qui contient une taille maximale et un tableau de pointeurs génériques qui contiendra les distances avec les autres villes. 
  long taille_max;
  void ** sommets;
};

ville creerVille(long taille){
   ville v;	    //initialise un Tas min v
   v->taille_max=taille;	    //initialise le nombre maximum d'éléments du tas
   v->sommets=(void **)calloc(taille,sizeof(void *)); //initialise les distances à 0
   return v;
}

bool estvide(ville v){
  if (!v->sommets[0])
    return false;
  return true;
}

void detruireVille(ville v){
   for(int i=0;i< v->taille_max;++i){		//on parcours les cases de la table de distance
      if (v->sommets[i])				//on teste si la case contient quelque chose
       free(v->sommets[i]);			//on libère les cases pleines
   }
   free(v->sommets);
}

void ajouterSommet(ville v, void* t){
  int i=0;
  while (v->sommets[i])
    i++;
  v->sommets[i]=t;
}

int tailleTableau(ville v){
  int taille=0;
  for (int i=0; v->sommets[i]; i++)
    taille++;
  return taille;
}

void supprimerSommet(ville v){
  for (int i=0;i<(tailleTableau(v))-1; i++)
    v->sommets[i]=v->sommets[i+1];
  free(v->sommets[tailleTableau(v)]);
}

void* filsGauche(ville v, int pere){
  return v->sommets[2*pere+1];
}

void* filsDroit(ville v, int pere){
  return v->sommets[2*pere+2];
}

void echanger(void* i,void* j){
  void* echange=i;
  i=j;
  j=echange;
}






void reorganiserTasMin(ville v,){
  int taille=v->taille_max;
  for(int i=0;i<taille;i++){
    for(int j=i;j<taille;j++){
      if(comparer(v->sommets[i],filsGauche(v,j))) // si le sommet père est supérieur à son fils
	echanger(v->sommets[i],filsGauche(v,j));// gauche alors on les échange
      if(comparer(v->sommets[i],filsDroit(v,j))) // si le sommet père est superieur à son fils
	echanger(v->sommets[i],filsGauche(v,j));// droit alors on les échange
  }
}



