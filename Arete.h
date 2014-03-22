#infdef ARETE
#define ARETE

typedef struct Arete *Arete;

Arete creerArete(double cle,int depart,int arrive);
void freeArete(Arete a);
void afficheArete(Arete a);
double getCle(Arete a);
int getDepart(Arete a);
int getArrive(Arete a);
void setCle(double value,Arete a);
void setDepart(int depart,Arete a);
void setArrive(int arrive,Arete a);

#endif
