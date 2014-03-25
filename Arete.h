#ifndef ARETE
#define ARETE

typedef struct Arete *Arete;

Arete creerArete(double cle,int depart,int arrive);
int comparaisonArete(void* a,void* b);
void freeArete(Arete a);
void afficheArete(void* a);
double getCle(Arete a);
int getDepart(Arete a);
int getArrive(Arete a);
void setCle(double value,Arete a);
void setDepart(int depart,Arete a);
void setArrive(int arrive,Arete a);

#endif
