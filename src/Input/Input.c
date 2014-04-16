/**
 * \file main.c
 * \brief Fichier source qui contient les fonctions permettant de passer un fichier Tsp en un Input.
 * Ce programme fait le parsing.
 */



/* La fonction getline est dans une extension GNU, d'où la ligne suivante.*/
#define _GNU_SOURCE
#include <Input.h>
#include <malloc.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>



/**
 * \brief Déclaration des fonctions statiques.
 * Les fonctions statiques ne sont pas nécessaire dans le .h car seul ce fichier les utilisera.
 */



/* Déclaration des fonctions statiques */


/**
 * \brief Fonction qui test si la dimension de la matrice est symétrique.
 */

static bool est_symetrique(double** mat,int dim);

/**
 * \brief Fonction qui alloue de la mémoire et initialise à 0 les champs de la structure .
 */

static Input alloc_init_input(char * nom);

/**
 * \brief Fonction qui libère la mémoire de la structure.
 * \param line_ptr est un pointeur sur une ligne.
 * \param input instance de type Input à afficher.
 */

static void free_erreur(FILE* file, char* line_ptr,Input input);

/**
 * \brief Fonction qui affiche les erreurs.
 * Affiche si c'est une erreur de lecture ou d'entrée.
 */

static void affiche_erreur();


/**
 * \brief Fonction qui vérifie le champ entré.
 * Retourne si le champ passé en paramètre est celle attendu ou non.
 */

static bool verif_champ_entree(char* ligne_ptr, const char* champ_attendu, const char* pattern);

/**
 * \brief Fonction vérifie si tout est correct.
 * \param line_ptr est un pointeur sur une ligne.
 * \param input instance de type Input à afficher.
 */

static bool est_valide(bool flag,FILE* imput_file,char* ligne_ptr,const char* pattern,bool erreur_possible,const char* chaine_attendu,const char* message_erreur,Input input);

/**
 * \brief Fonction qui alloue de la mémoire.
 * Alloue de la mémoire de la taille du champ taille-pattern.
 */

char* alloc_chaine(ssize_t taille_ligne,int taille_pattern,char* ligne_lue);

/**
 * \brief Fonction qui parse les champs.
 * \param input instance de type Input à afficher.
 */

static void parsing_champs(FILE* file,Input input);


/**
 * \brief Fonction qui alloue de la mémoire.
 * \param input instance de type Input à afficher.
 * Alloue de la mémoire à display_data du input.
 */

static void affectation_display_data(int indice,double x,double y,Input input);


/**
 * \brief Fonction qui parse le display.
 * \param line_ptr est un pointeur sur une ligne(lu avec getline ).
 * \param input instance de type Input à afficher.
 */



static void parsing_display(FILE* file,char* ligne_ptr,size_t taille_alloc,Input input);



/**
 * \brief Fonction qui parse la matrice.
 * \param line_ptr est un pointeur sur une ligne(lu avec getline ).
 * \param input instance de type Input à afficher.
 */


static void parsing_matrice(FILE* nom_file,char* ligne_ptr,size_t taille_alloc,Input input);




/**
 * \struct input
 * \brief structure contenant tous les éléments nécessaires au parsing.
 */

/* Structure contenant les différents champs a la fin du parsing */
struct input
{
  char*       nom_file; /* comes from argv : should not be freed */
  char*       nom;
  char*       type;
  char*       commentaire;
  int         dimension;
  char*       edge_weight_type;
  char*       edge_weight_format;
  char*       display_data_type;
  double**    edge_weight_matrix;
  double**    display_data;
};



/*------ ACCESSEUR ------*/

/**
 * \brief Fonction retournant le nom du fichier.
 */

char* get_nom_file(Input input){return input->nom_file;}

/**
 * \brief Fonction retournant le nom.
 */

char* get_nom(Input input){return input->nom;}

/**
 * \brief Fonction retournant le type.
 */

char* get_type(Input input){return input->type;}

/**
 * \brief Fonction retournant le commentaire.
 */

char* get_commentaire(Input input){return input->commentaire;}

/**
 * \brief Fonction retournant la dimension.
 */

int   get_dimension(Input input){return input->dimension;}

/**
 * \brief Fonction retournant la taille du type.
 */

char* get_edge_weight_type(Input input){return input->edge_weight_type;}

/**
 * \brief Fonction retournant la taille du format.
 */

char* get_edge_weight_format(Input input){return input->edge_weight_format;}

/**
 *\brief Retourne le champs display_data_type (ex: TWOD_DISPLAY) du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
*/

char* get_display_data_type(Input input){return input->display_data_type;}

/**
 * \brief Fonction retournant la taille de la matrice.
 */

double** get_edge_weight_matrix(Input input){return input->edge_weight_matrix;}

/**
 *\brief Retourne la matrice d'affichage du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
*/

double** get_display_data(Input input){return input->display_data;}



/**
 * \brief Fonction affichant les données du Input passé en paramètre.
 */

void print_input_data(Input input)
{
    printf("-- Données d'entrées --\n");
    printf("nom_file : %s\n", input->nom_file);
    printf("nom : %s\n", input->nom);
    printf("type : %s\n", input->type);
    printf("commentaire : %s\n", input->commentaire);
    printf("dimension : %d\n", input->dimension);
    printf("edge_weight_type : %s\n", input->edge_weight_type);
    printf("edge_weight_format : %s\n", input->edge_weight_format);
    printf("display_data_type : %s\n", input->display_data_type);
    printf("edge_weight_matrix :\n");
    if(input->edge_weight_matrix)
    {
      for(int i = 0 ; i<input->dimension ; i++)
      {
	if(input->edge_weight_matrix[i])
	{
	  for(int j = 0 ; j<input->dimension ; j++)
	      printf("%.1lf\t", input->edge_weight_matrix[i][j]);
	  printf("\n");
	}
      }
    }
    else
      printf("Matrice vide.\n"); // Si matrice vide
    printf("display_data :\n");
    if(input->display_data != NULL)
    {
      for(int i = 0 ; i<input->dimension ; i++)
	if(input->display_data[i]!=NULL)
	  printf("%d ->\t%.1lf\t%.1lf\n", i+1, input->display_data[i][0], input->display_data[i][1]);
    }
    else
      printf("Matrice vide.\n"); // Si matrice vide
    printf("\n");
}



/**
 * \brief Fonction transformant la chaine de caractères passée en paramètre en Input.
 * Cette fonction passe le fichier Tsp en un Input.
 */

Input open_TSP_file(char* nom_file)
{    
    FILE* file = NULL;
    file = fopen(nom_file,"r");
    /*On ouvre le fichier a parser en lecture seule */
    if(file == NULL)
    {
        perror("Probleme d'ouverture du fichier "); 
	/* Affiche le message d'erreur lié a un problème d'ouverture en plus du message */
        exit(EXIT_FAILURE);
    }
    Input input=alloc_init_input(nom_file); 

    parsing_champs(file,input);
    /* Sorti dans parsing_champs si erreur */
    fclose(file);
    return input;
}

/*------ ALLOCATION/LIBERATION MEMOIRE ------*/
static Input alloc_init_input(char * nom)
{
  /* On alloue et on initialise a 0 les champs de la structure */
  Input myStruct=calloc(1,sizeof(struct input));
  myStruct->nom_file=nom; /* Viens de argv -> pas de free*/
  return myStruct;
}

char* alloc_chaine(ssize_t taille_ligne,int taille_pattern,char* ligne_lue)
{
  /* On alloue la taille du champ (taille-pattern) */
  int taille_alloc=taille_ligne-taille_pattern;
  if(taille_alloc==0)
    return NULL;
  char* alloc = malloc(sizeof(char) * taille_alloc);
  /* on effectue la copie dans alloc */
  strncpy(alloc,ligne_lue+taille_pattern,taille_alloc);
  /* On supprime le retour chariot */
  *(alloc+taille_alloc-1)='\0'; 
  return alloc;
}
 
/* nom_file vient de la console, et taille n'est pas allouer dynamiquement 
 * on libère un à un les champs*/
void free_input(Input input)
{
  if(input->nom)
    free(input->nom);
  if(input->commentaire)
    free(input->commentaire);
  free(input->type);
  free(input->edge_weight_type);
  free(input->edge_weight_format);
  free(input->display_data_type);
  for(int i=0 ; i<input->dimension ; i++)
  {
    if(input->edge_weight_matrix)
      free(input->edge_weight_matrix[i]);
    if(input->display_data)
      free(input->display_data[i]);
  }
  free(input->edge_weight_matrix);
  free(input->display_data);
  free(input);
}

static void free_erreur(FILE* file, char* line_ptr,Input input)
{
  /* Libère la mémoire utilisé par le buffer si une erreur survient, 
   * ferme le flux, et libère la mémoire de la structure, si des champs ne sont
   * pas initialiser, on fait free(NULL) ce qui est une expression valide.*/

  free_input(input);
  free(line_ptr);
  fclose(file);
  exit(EXIT_FAILURE);
}

/*------ AFFICHE ERROR ------*/ 
static void affiche_erreur(){
  /* errno == -1 ou 0, erreur appels système ou erreur fonction bibliotheque */
  if(!errno || errno==-1) 
    perror("Erreur du la lecture du fichier.\nConsultez l'entrée errno du manuel pour plus d'information\nErreur");
  else
    error(0,0,"Erreur de lecture de l'entrée.");
}

static bool verif_champ_entree(char* ligne_ptr, const char* champ_attendu, const char* pattern){
    char* champ = NULL;
    sscanf(ligne_ptr, pattern, &champ);
    /* Si ligne_ptr pointe sur "TYPE: TSP_OUPAS", alors champs pointe sur TSP_OUPAS */
    if(!strcmp(champ,champ_attendu)) /*strcmp=0 si les chaines sont équivalentes, 0=false*/
      {
	free(champ);
        return true;
      }
    free(champ);
    return false;
}

/* Amélioration envisageable : passer un tableau de couple(chaine_attendu,fonction de modification du comportement du programme),
 * afin gérer plusieurs formats.*/

static bool est_valide(bool flag,FILE* imput_file,char* ligne_ptr,const char* pattern,bool erreur_possible,const char* chaine_attendu,const char* message_erreur,Input input)
{
  /* On ignore le "%XX" systématiquement passé avec pattern */
  int taille = strlen(pattern)-3;
  if(flag && !strncmp(ligne_ptr,pattern,taille)) /*voir commentaire fonction verif_champ_entree*/
  {
    /* Dans le cas où un pattern à été localiser, si le champ suivant est incorrect
     * On va donner une erreur et quitter le programme */
    if(erreur_possible)
    {
      if(!verif_champ_entree(ligne_ptr,chaine_attendu,pattern))
      {
	error(0,0,message_erreur);
	/* free_erreur libère propremment la mémoire avant de lancer un exit(FAILURE), 
	 * tous les OS ne faisant par forcement bien leur travail  ...*/
	free_erreur(imput_file,ligne_ptr,input);
      }
    }
    return true;
  }
  return false;
}

static void parsing_champs(FILE* file,Input input)
{     
  ssize_t taille_ligne;
  bool bool_section; // Permet d'éco. un strcmp.
  char* ligne_ptr = NULL;
  size_t taille_alloc = 0; /* correspond a un entier signé.*/

  while((taille_ligne=getline(&ligne_ptr,&taille_alloc,file)) != EOF)/* EOF généralement égal a -1*/
  {
    /* On verifie sur chaque ligne si des paramètres valides sont insérer
     * si true, on parse.
     * On utilise la fonction est_valide surtout pour des raisons de lisibilité,
     * Une fonction vraiment générique étant difficilement réalisable. */


    /*------- NAME -------*/
    if(est_valide(!input->nom,file,ligne_ptr,"NAME: %42",false,NULL,NULL,input))
    {
      /* On pourrait allouer directement la mémoire avec sscanf, mais le code est peu-etre
       * plus lisible en passant par alloc_chaine*/
      input->nom=alloc_chaine(taille_ligne,6,ligne_ptr);
      continue;
      /* Une ligne ne peut etre associé a au plus un champs, pas la peine d'évaluer d'autres expressions.*/
    }
        
    /*------ TYPE -------*/
    if(est_valide(!input->type,file,ligne_ptr,"TYPE: %ms",true,"TSP","TYPE non géré.",input))
    {
      /*Si une erreur est survenue, est_valide a lancé un exit.*/
      input->type=alloc_chaine(taille_ligne,6,ligne_ptr);
      continue;
    }

    /*------ COMMENT ------*/
    if(est_valide(!input->commentaire,file,ligne_ptr,"COMMENT: %42",false,NULL,NULL,input))
    {
      input->commentaire=alloc_chaine(taille_ligne,9,ligne_ptr);
      continue;
    }
	  
    /*------ DIMENSION ------ AMELIORATION POSSIBLE EN MODIFIANT est_valide.*/
    if(est_valide(!input->dimension,file,ligne_ptr,"DIMENSION: %42",false,NULL,NULL,input))
    {
      sscanf(ligne_ptr,"DIMENSION: %d",&input->dimension);
      if(input->dimension<=0)
      {
	error(0,0,"Dimension incorrecte");
	free_erreur(file,ligne_ptr,input);
      }
      continue;
    }

    /*------ EDGE WEIGHT TYPE ------*/
    if(est_valide(!input->edge_weight_type,file,ligne_ptr,"EDGE_WEIGHT_TYPE: %ms",true,"EXPLICIT","EDGE_WEIGHT_TYPE non géré.",input))
    {
      input->edge_weight_type=alloc_chaine(taille_ligne,18,ligne_ptr);
      continue;
    }

    /*------ EDGE WEIGHT FORMAT ------*/
    if(est_valide(!input->edge_weight_format,file,ligne_ptr,"EDGE_WEIGHT_FORMAT: %ms",true,"FULL_MATRIX","EDGE_WEIGHT_FORMAT non géré.",input))
    {
      input->edge_weight_format=alloc_chaine(taille_ligne,20,ligne_ptr);
      continue;
    }

    /*------ DISPLAY_DATA_TYPE ------*/
    if(est_valide(!input->display_data_type,file,ligne_ptr,"DISPLAY_DATA_TYPE: %ms",true,"TWOD_DISPLAY","DISPLAY_DATA_TYPE non géré.",input))
    {
      input->display_data_type=alloc_chaine(taille_ligne,19,ligne_ptr);
      continue;
    }

    /*------ PARTIE SECTION ------*/
    bool_section = !strncmp("EDGE_WEIGHT_SECTION",ligne_ptr,19);
    if( bool_section || !strncmp("DISPLAY_DATA_SECTION",ligne_ptr,20) )
    {
      /* Pour parser les différents champs de données, il faut que certains champs soient présents 
       * sinon, on affiche un message d'erreur */
      if(bool_section && input->dimension && input->edge_weight_type && !input->edge_weight_matrix && input->edge_weight_format)
      {
	parsing_matrice(file,ligne_ptr,taille_alloc,input);
	continue;
      }
      
      else if(input->display_data_type && input->dimension)
      {
	parsing_display(file,ligne_ptr,taille_alloc,input);
	continue;
      }
      error(0,0,"Champs manquant avant section_part, ou section_part redondante.");
      free_erreur(file,ligne_ptr,input);
    }

    /*------ EOF OPTIONNEL ------*/
    if(!strncmp("EOF",ligne_ptr,3))
       break;
    
    /*------ ERREUR ------ */
    printf("Erreur avec : %s",*ligne_ptr);
    error(0,0,"Champs redondant,inconnu ou dimension incorrecte.");
    free_erreur(file,ligne_ptr,input);
  }
  /* On est sorti du while car on a fini de lire, ou a la rencontre d'un "EOF"
   * Si le champ edge_weight_matrix a été rencontré, alors le parsing est réussi.*/
  if(!input->edge_weight_matrix)
  {
    affiche_erreur();
    free_erreur(file,ligne_ptr,input);
  }
  free(ligne_ptr);
  /* Parsing reussi.*/
}


static void affectation_display_data(int indice,double x,double y,Input input)
{
  input->display_data[indice]=malloc(2*sizeof(double)); 
  input->display_data[indice][0]=x;
  input->display_data[indice][1]=y;
}

static void parsing_display(FILE* file,char* ligne_ptr,size_t taille_alloc,Input input)
{
  int taille_ligne,nombre_affectation;
  int taille= input->dimension;
  double position_x;
  double position_y;
  int numero_ville;

  /* On initialise la matrice display_data a NULL pour les tests d'affectation.*/
  input->display_data= calloc(taille,sizeof(double*));
  for(int i=0;i<taille;i++)
  {
    if((taille_ligne=getline(&ligne_ptr,&taille_alloc,file)) != EOF)
    {
      nombre_affectation=sscanf(ligne_ptr,"%d %lf %lf",&numero_ville,&position_x,&position_y);
      
      /* Si il y a moins de 3 affectations, erreur de lecture*/
      if(nombre_affectation<3)
      {
	error(0,0,"Format de la display_section incorrect.");
	free_erreur(file,ligne_ptr,input);
      }
      
      if(numero_ville<1 || numero_ville > taille || input->display_data[numero_ville-1])
      /* input.display_data[numero_ville-1] : On verifie qu'il n'y a pas deja eu d'affectation.*/
      {
	error(0,0,"Erreur display_section : ville avec le meme numéro ou numéro incorrect.");
	free_erreur(file,ligne_ptr,input);
      }

      /* L'affectation realisé via sscanf est donc valide. */
      affectation_display_data(numero_ville-1,position_x,position_y,input);
    }
    else
    {
      affiche_erreur();
      free_erreur(file,ligne_ptr,input);
    }
  }
}

static void parsing_matrice(FILE* file,char* ligne_ptr,size_t taille_alloc,Input input)
{
  char* ptr_debut_double;
  char* ptr_fin_double;
  ssize_t taille_ligne;
  int taille=input->dimension;
  
  input->edge_weight_matrix = calloc(taille, sizeof(double*));

  for(int i=0;i<taille;i++)
  { 
    if(taille_ligne=getline(&ligne_ptr,&taille_alloc,file) != EOF)
    {
      input->edge_weight_matrix[i] = calloc(taille, sizeof(double));
      ptr_debut_double=ptr_fin_double=ligne_ptr;
      for(int j=0;j<taille;j++)
      {
	input->edge_weight_matrix[i][j]=strtod(ptr_debut_double,&ptr_fin_double);
	if(ptr_debut_double==ptr_fin_double || input->edge_weight_matrix[i][j]<0)
	{
	  error(0,0,"Erreur matrice: distance ou format incorrect.");
	  free_erreur(file,ligne_ptr,input);
	}
	/* On passe a la valeur suivante,en décalant le pointeur de debut. */
	ptr_debut_double=ptr_fin_double;
      }
    }
    else
    {
      affiche_erreur();
      free_erreur(file,ligne_ptr,input);
    }
  }
  if(!est_symetrique(input->edge_weight_matrix,taille))
  {
    error(0,0,"Erreur matrice: Matrice non symétrique.");
    free_erreur(file,ligne_ptr,input);
  }
}

static bool est_symetrique(double** mat,int dim)
{
  /* On parcoure la matrice sous la diagonale */
  for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
      /* si a_ij != a_ji , la matrice n'est pas valide. */
      if(mat[i][j]!=mat[j][i])
	 return false;
  return true;
}
	 


	  
  
	
	
	
	

  
