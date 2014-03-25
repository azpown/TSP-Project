#include <stdlib.h>
#include <stdio.h>
#include "Arete.h"

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

int comparaisonArete(void* a,void* b)
{
  /* On compare uniquement la clé */
  a= (Arete) a;
  b= (Arete) b;
  double cmp=a->cle - b->cle;
  if(cmp<0)
    return -1;
  if(cmp>0)
    return 1;
  return 0;
}

void freeArete(Arete a){free(a);}

void afficheArete(void* a)
{
  a = (Arete) a;
  printf("Depart: %d\tArrive: %d\tCle: %.1lf\n",a->depart,a->arrive,a->cle);
}

double getCle(Arete a){return a->cle;}
int getDepart(Arete a){return a->depart;}
int getArrive(Arete a){return a->arrive;}

void setCle(double value,Arete a){a->cle=value;}
void setDepart(int depart,Arete a){a->depart=depart;}
void setArrive(int arrive,Arete a){a->arrive=arrive;}
