#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <NearestNeighbour.h>
#include <Prim.h>
#include <BruteForceOpti.h>
#include <FonctionTest.h>
#include <Input.h>

#define PTF_NAME printf("\n\t\t======- TSPsolv -======\n\n")
#define DEFAULT_ALG HeuristiquePlusProcheVoisin
#define DEFAULT_CODE "-n"
#define DEFAULT_START 0
#define DEFAULT_BOOL true
#define NB_ALGO 3
	
static void Usage();

/* Le pointeur de fonction de cette struture pourra prendre deux type de signature :
 * si estAvecDepart == true -> HeuristiqueAvecDepart;
 * sinon HeuristiqueSansDepart;*/
typedef struct symbAlgo
{
  bool estAvecDepart;
  char* code_algo;
  HeuristiqueAvecDepart algo_d;
  HeuristiqueSansDepart algo_nd;
}symbAlgo;

symbAlgo tabSelection[NB_ALGO] = {{false,"-b",NULL,BruteForceOpti},
				  {true,"-n",HeuristiquePlusProcheVoisin,NULL},
				  {true,"-m",Prim,NULL}};


static void Usage()
{
  printf("<Usage>: ./TSPsolv <Nom_du_fichier_tsp> -<Algorithme> -d=<Départ>\n\n");
  printf("Algorithmes :\n"); 
  printf("\t-b\tBrute Force, recherche du chemin optimal de façon exaustive (déconseiller sur des instances de plus de 18 villes)\n\n");
  printf("\t-m\t2-Approximation, contruction de l'arbre de poid couvrant minimal via l'algorithme de prim (tas min) et d'un parcour préfixe de ce dernier\n\n");
  printf("\t-n\tHeuristique Plus Proche Voisin, calcul d'un chemin par selection successive du plus proche voisin.\n\n");
  printf("\nDepart : entier, paramètre non pris en compte pour Brute Force.\n");
}

int main(int argc,char** argv)
{
  if(argc < 2 || !(strcmp(argv[1],"-h")) || !(strcmp(argv[1],"--help")))
  {
    PTF_NAME;
    Usage();
    exit(EXIT_FAILURE);
  }

  /* mieux vaut mettre DEFAULT_ALG a la place de null, mais le compilo' n'est pas content :p */
  symbAlgo selection = {DEFAULT_BOOL,DEFAULT_CODE,DEFAULT_ALG,NULL};
  
  char* nom_file;
  int depart = DEFAULT_START;
  bool flag_selection_code = false; 
  bool  flag_selection_depart = false;
  bool  flag_file = false;
  for(int i=1;i<5 && i<argc;i++)
  {
    for(int j=0;j<NB_ALGO;j++)
    {
      if(!(flag_file) && argv[i][0] != '-')
      {
	nom_file= argv[i];
	flag_file=true;
	break;
      }
      if(!(flag_selection_code) && !(strcmp(argv[i],tabSelection[j].code_algo)))
      {
	selection.estAvecDepart=tabSelection[j].estAvecDepart;
	if(selection.estAvecDepart)
	  selection.algo_d=tabSelection[j].algo_d;
	else
	  selection.algo_nd=tabSelection[j].algo_nd;	
	flag_selection_code=true;
	break;
      }
      if(!(flag_selection_depart) && (!strncmp("-d=",argv[i],3)) && (strlen(argv[i])>3))
      {
	depart=atoi(argv[i]+3);
	flag_selection_depart=true;
	break;
      }
    }
  }
  Graphe g = getGraphe(nom_file);
  if(get_taille(g)<depart || depart<=0)
  {
    Usage();
    printf("\n-ERREUR- : Dimension non valide (valide entre 0 et dimension matrice-1).\n");
    exit(EXIT_FAILURE);
  }    
  double acc = 0;
  int* resultat;   
  if(selection.estAvecDepart)
  {
    resultat = selection.algo_d(g,depart,&acc);
  }
  else
  {
    resultat = selection.algo_nd(g,&acc);
  }
  PTF_NAME;
  afficheCycle(resultat,get_taille(g),acc);
  printf("\n\t\t===========OK==========\n");
  freeHeuristique(g,resultat);
  return EXIT_SUCCESS;
}

  
	
    
	
      
    
	
      
      
      
    
    
  
