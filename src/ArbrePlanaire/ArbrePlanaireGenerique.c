#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ArbrePlanaireGenerique.h>

/* structure représentant un noeud d'arbre, le premier fils est pointé,
 *les autres sont accessible via accès au frere successif. */
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
static void visite(int* indice,void** tab,Noeud this);
static void visiterPrefixe(int* indice,void** tab,Noeud this);
static void detruireArbo(Noeud this);
static void affichagePrefixeRecursif(Noeud this,ptr_affichage f);

/*------ Allocation ------*/
Noeud creerNoeud(void* element,Noeud parent,Noeud aine,Noeud cadet)
{
  Noeud this=malloc(sizeof(struct noeud));
  assert(this!=NULL);
  this->elem=element;
  printf("elem : %d\n",*(int *)this->elem);
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
  /* retourne un arbre planaire vide, le premier appel de ajouter fils ce fait avec pere==NULL */
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
  /* Ici, la sommet est donc une feuille sans frere */
  freeNoeud(this);
}

void freeArbrePlanaireGen(ArbrePlanaireGen this)
{
  detruireArbo(getRacine(this));
  free(this);
}
    

/*------ Accesseurs ------*/
void* getElem(Noeud this)
{
  return this->elem;
}

Noeud getPremierFils(Noeud this){return this->premierFils;}
Noeud getPere(Noeud this){return this->pere;}
Noeud getFrere(Noeud this){return this->frere;}
Noeud getRacine(ArbrePlanaireGen this){return this->racine;}

/*------ Parcour ------ */
/* Dans notre utilisation de l'arbre pour l'algorithme de prim, la taille de l'arbre
 * est majorée par la dimension de la matrice, pas la peine d'implementé un module
 * de file ou de tableau extensible. */
void** parcourPrefixe(int taille,ArbrePlanaireGen this)
{
  assert(taille>0);
  void** parcour=calloc(taille,sizeof(void*));
  Noeud tmp=this->racine;
  int indice=0;
  visiterPrefixe(&indice,parcour,tmp);
  /* On verifie que la taille du parcour correspond au nombre de sommet de l'arbre */
  assert(taille==indice+1);
  return parcour;
}

void freeParcourPrefixe(void** this){free(this);}

/* effet de bord sur indice afin de placer l'element a la bonne position dans le tableau*/
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
  tab[*indice]=getElem(this);
  *indice++;
}


/*------ Fonction affichage arbre planaire ------*/

void affichagePrefixe(ArbrePlanaireGen this)
{
  affichagePrefixeRecursif(getRacine(this),this->affiche);
}

/* moins d'acces a la structure en passant f en parametre, mais plus de place sur la pile */
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
  printf("Adresse de la cellule : %p\n",this);
  if(!pere)
  {
    printf("Pas de pere\n\n");
    a->racine=this;
    return this;
  }
  Noeud tmp= getPremierFils(pere);
  printf("PremierFils du pere : %p\n",tmp);
  /* Traitement different dans le cas ou this a deja des fils ou non */
  if(tmp)
  {
    /* On entre ici si getPremierFils designe un sommet -> deja un fils */
    while(getFrere(tmp))
      /* Tant qu'il y a un frere, on itere. */
      tmp=getFrere(tmp);
    /* Il faut ajouter le noeud crée comme frere du dernier fils du sommet passé en parametre */
    tmp->frere=this;
    printf("FRERE DE LA CELLULE : Pere : %p , Frere : %p , PremierFils : %p\n\n",tmp->pere,tmp->frere,tmp->premierFils);
  }
  else
    /* Le sommet ajouter est le seul fils du sommet passé en parametre -> c'est son premierFils */
    pere->premierFils= this;
  printf("Pere : %p , Frere : %p , PremierFils : %p\n\n",this->pere,this->frere,this->premierFils);
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
    /* Si le sommet a enlever de l'arbre est le premier fils du pere, alors son frere devient
     * premier fils du pere. */
    getPere(this)->premierFils=getFrere(this);
  else
  {
    while(getFrere(tmp)!=this)
      tmp=getFrere(tmp);
    /* Si le sommet n'est pas le premier fils, alors le frere de son frere precedant deviens 
     * le frere du sommet a détruire. */
    tmp->frere=getFrere(this);
  }
  /* Module générique, donc l'utilisateur doit free l'elem de this. */
  freeNoeud(this);
}

  

  
    
  
