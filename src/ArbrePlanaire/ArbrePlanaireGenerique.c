/**
 * \file ArbrePlanaireGenerique.c
 * \brief Fichier source qui contient les fonctions mettant en place un Arbre planaire générique.
 */


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ArbrePlanaireGenerique.h>

/* structure représentant un noeud d'arbre, le premier fils est pointé,
 *les autres sont accessibles via les frères du premier fils de manière successive. */
struct noeud
{
  void* elem;
  Noeud pere;
  Noeud premierFils;
  Noeud frere;
};
 
struct arbrePlanaireGen
{
  Noeud racine;
  ptr_affichage affiche;
};

/*------ Declaration des fonctions statiques ------*/

/**
 * \brief Fonction qui marque les sommets visités.
 * Met le sommet this dans le tableau tab à l'indice indice.
 */

static void visite(int* indice,void** tab,Noeud this);

/**
 * \brief Fonction qui parcours un arbre.
 * Parcours l'arbre de manière préfixe.
 */

static void visiterPrefixe(int* indice,void** tab,Noeud this);

/**
 * \brief Fonction qui libère la mémoire alouée au noeud.
 * Détruit le noeud this en libérant sa mémoire.
 */

static void detruireArbo(Noeud this);

/**
 * \brief Fonction qui affiche le parcours préfixe..
 */

static void affichagePrefixeRecursif(Noeud this,ptr_affichage f);

/*------ Allocation ------*/
Noeud creerNoeud(void* element,Noeud parent,Noeud aine,Noeud cadet)
{
  Noeud this=malloc(sizeof(struct noeud));
  assert(this!=NULL);
  this->elem=element;
  this->pere=parent;
  this->premierFils=aine;
  this->frere=cadet;
  return this;
}

void freeNoeud(Noeud this)
{
  free(this);
}

ArbrePlanaireGen creerArbrePlanaireGen(ptr_affichage f)
{
  /* retourne un arbre planaire vide, le premier appel de ajouter fils se fait avec pere==NULL */
  ArbrePlanaireGen this=malloc(sizeof(struct arbrePlanaireGen));
  this->racine=NULL;
  this->affiche=f;
  return this;
}

static void detruireArbo(Noeud this)
{
  if(!this)
    return;
  detruireArbo(getPremierFils(this));
  detruireArbo(getFrere(this));
  /* Ici, le sommet est donc une feuille sans frère */
  freeNoeud(this);
}

void freeArbrePlanaireGen(ArbrePlanaireGen this)
{
  detruireArbo(getRacine(this));
  free(this);
}
    

/*------ Accesseurs ------*/
void* getElement(Noeud this){return this->elem;}

Noeud getPremierFils(Noeud this){return this->premierFils;}
Noeud getPere(Noeud this){return this->pere;}
Noeud getFrere(Noeud this){return this->frere;}
Noeud getRacine(ArbrePlanaireGen this){return this->racine;}

/*------ Parcour ------ */
/* Dans notre utilisation de l'arbre pour l'algorithme de prim, la taille de l'arbre
 * est majorée par la dimension de la matrice, pas la peine d'implementer un module
 * de file ou de tableau extensible. */

/* effet de bord sur indice afin de placer l'élément à la bonne position dans le tableau*/
static void visiterPrefixe(int* indice,void** tab,Noeud this)
{
  visite(indice,tab,this);
  if(!estFeuille(this))
    visiterPrefixe(indice,tab,getPremierFils(this));
  if(getFrere(this))
    visiterPrefixe(indice,tab,getFrere(this));
}
  
static void visite(int* indice,void** tab,Noeud this)
{
  tab[*indice]=getElement(this);
  *indice++;
}


/*------ Fonction affichage arbre planaire ------*/

void affichagePrefixe(ArbrePlanaireGen this)
{
  affichagePrefixeRecursif(getRacine(this),this->affiche);
  printf("\n");
}

/* moins d'accès à la structure en passant f en paramètre, mais plus de place sur la pile */
static void affichagePrefixeRecursif(Noeud this,ptr_affichage f)
{
  f(this->elem);
  if(!estFeuille(this))
    affichagePrefixeRecursif(getPremierFils(this),f);
  if(getFrere(this))
    affichagePrefixeRecursif(getFrere(this),f);
}
  
/*------ Primitive d'arbre planaire ------*/

/* Fonction en O(nb_fils(this)) */
Noeud ajouterFils(ArbrePlanaireGen a,Noeud pere,void* elem)
{
  Noeud this= creerNoeud(elem,pere,NULL,NULL);
  if(!pere)
  {
    a->racine=this;
    return this;
  }
  Noeud tmp= getPremierFils(pere);
  /* Traitement différent dans le cas où this a déjà des fils ou non */
  if(tmp)
  {
    /* On entre ici si getPremierFils désigne un sommet -> deja un fils */
    while(getFrere(tmp))
      /* Tant qu'il y a un frère, on itère. */
      tmp=getFrere(tmp);
    /* Il faut ajouter le noeud créé comme frère du dernier fils du sommet passé en paramètre */
    tmp->frere=this;
  }
  else
    /* Le sommet ajouté est le seul fils du sommet passé en paramètre -> c'est son premierFils */
    pere->premierFils= this;
  return this;
}

bool estFeuille(Noeud this){return getPremierFils(this)==NULL;}

/* S'applique sur une feuille */
void supprimerNoeud(ArbrePlanaireGen a,Noeud this)
{
  assert(this && estFeuille(this));
  if(!getPere(this))
  {
    freeNoeud(this);
    a->racine=NULL;
    return;
  }
  Noeud tmp= getPremierFils(getPere(this));
  if(tmp==this)
    /* Si le sommet à enlever de l'arbre est le premier fils du père, alors son frère devient
     * premier fils du père. */
    getPere(this)->premierFils=getFrere(this);
  else
  {
    while(getFrere(tmp)!=this)
      tmp=getFrere(tmp);
    /* Si le sommet n'est pas le premier fils, alors le frère de son frère precedent devient 
     * le frère du sommet a détruire. */
    tmp->frere=getFrere(this);
  }
  /* Module générique, donc l'utilisateur doit free l'elem de this. */
  freeNoeud(this);
}

  

  
    
  
