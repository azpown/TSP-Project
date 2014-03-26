#ifndef GRAPHE
#define GRAPHE

typedef struct graphe * Graphe;

Graphe cree_graphe(int len,double** mat);
void free_graphe(Graphe graphe);
void afficher_graphe(Graphe g);
double distance_ville(Graphe graphe,int s1,int s2);
int get_taille(Graphe graphe);

#endif
