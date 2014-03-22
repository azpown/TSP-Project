#include <stdlib.h>
#include <stdio.h>

struct Arete
{
  double cle;
  int depart;
  int arrive;
};

Arete creerArete(double cle,int depart,int arrive)
{
  Arete a=malloc(sizeof(struct Arete));
  a->cle=cle;
  a->depart=depart;
  a->arrive=arrive;
  return a;
}

void freeArete(Arete a){free(a);}

void afficheArete(Arete a)
{
  printf("Depart: %d\tArrive: %d\tCle: %.1lf\n",a->depart,a->fin,a->cle);
}

double getCle(Arete a){return a->cle;}
int getDepart(Arete a){return a->depart;}
int getArrive(Arete a){return a->arrive;}

void setCle(double value,Arete a){a->cle=value;}
void setDepart(int depart,Arete a){a->depart=depart;}
void setArrive(int arrive,Arete a){a->arrive=arrive;}
