#ifndef _MANIP 
#define _MANIP 

#include <stdbool.h>

typedef struct graphe * Graphe;

double distanceSommetFullMatrice (Graphe Graphe,int s1,int s2);
int rand_a_b(int a,int b);
void initialise_true_n(bool* tab,int taille);
int plusProcheVoisin(int sommet,bool* tab_dispo,Graphe graph,double* acc);
void HeuristiquePlusProcheVoisin(Graphe graph);
Graphe creeGraph(int len,double** mat);
Graphe creeGraph(int len,double** mat);
void afficherGraphe(Graphe g);


#endif
