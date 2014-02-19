#ifndef _MANIP 
#define _MANIP 

typedef struct graphe *graphe;

int distanceSommetFullMatrice (int* graphe,int s1,int s2);
int rand_a_b(int a,int b);
int distanceSommetFullMatrice(graphe graph,int s1,int s2);
void initialise_1_n(int* tab,int taille);
int plusProcheVoisin(int sommet,int* tab_dispo,int taille);
void HeuristiquePlusProcheVoisin(graphe graph);

#endif
