#infdef _TAS_ARETE
#define _TAS_ARETE

typedef struct TasArete *TasMinArete;

TasMinArete creerTasMinArete(int taille,ptr_compar cmp,ptr_affichage affichage);
void freeTasArete(TasMinArete tas);
bool estVide(TasMinArete tas);
void ajouterArete(TasMinArete tas, Arete a);
void entasserTasArete(TasMinArete tas, int indice);
Arete extraireAreteMin(TasMinArete tas);
void affichageTasArete(TasMinArete tas);

#endif
