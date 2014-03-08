#ifndef _TASMIN
#define _TASMIN

typedef struct voisin *voisin;
typedef struct ville *ville;


ville creerVille(long taille);
bool estvide(ville v);
void detruireVille(ville v);
void ajouterSommet(ville v, void* t);
int tailleTableau(ville v);
void supprimerSommet(ville v);
void* filsGauche(ville v, int pere);
void* filsDroit(ville v, int pere);
void reorganiserTasMin(ville v);
void echanger(void* i,void* j);

#endif
