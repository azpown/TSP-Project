#include <malloc.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Nous déclarons et on initialise cette structure, qui sera accessible de l'extérieur à travers des 
 *accesseurs, nous garantissant une pseudo-encapsulation. */ 
static struct{
  char*       nom_file; /* comes from argv : should not be freed */
  char*       nom;
  char*       type;
  char*       commentaire;
  int         dimension;
  char*       edge_weight_type;
  char*       display_data_type;
  double**    edge_weight_matrix;
  double**    display_data;
}input;

void print_input_data(){
    printf("-- Données d'entrées --\n");
    printf("nom_file : %s\n", input.nom_file);
    printf("nom : %s\n", input.nom);
    printf("commentaire : %s\n", input.commentaire);
    printf("dimension : %d\n", input.dimension);
    printf("edge_weight_type: %s\n", imput.edge_weight_type);
    printf("display_data_type: %s\n", imput.display_data_type);
    printf("edge weight matrix :\n");
    if(input.edge_weight_matrix != NULL)
      {
        for(int i = 0 ; i<input.dimension ; i++)
	  {
            for(int j = 0 ; j<input.dimension ; j++)
                printf("%lf\t", input.edge_weight_matrix[i][j]);
            printf("\n");
	  }
      }
    else
      printf("NULL\n"); // Si matrice vide
    printf("display data :\n");
    if(input.display_data != NULL)
      {
        for(int i = 0 ; i<input.dimension ; i++)
            printf("%d -> %lf\t%lf\n", i+1, input.display_data[i][0], input.display_data[i][1]);
      }
    else
      printf("NULL\n"); // Si matrice vide
}

void open_TSP_file(char* nom_file)
{
    
    FILE* nom_file = NULL;
    nom_file = fopen(nom_file,"r");
    /*On ouvre le fichier a parser en lecture seule */
    if(nom_file == NULL)
    {
        perror("Probleme d'ouverture du fichier "); 
	/* Affiche le message d'erreur lié a un problème d'ouverture en plus du message */
        exit(EXIT_FAILURE);
    }
    input.nom_file = nom_file;
    
    char ** line_ptr = NULL;
    int* taille_ligne = NULL;
    int* line_str_s = NULL;

    parsing_champs(nom_file,ligne_ptr, line_str_s);
    parsing_matrice(input_file, line, line_str, line_str_s);
    
    free(ligne_ptr);
    fclose(input_file);
}

/* nom_file vient de la console, et taille n'est pas allouer dynamiquement */
void free_input(void)
{
  free(input.nom);
  free(input.commentaire);
  for(int i=0 ; i<input.dimension ; i++)
  {
    if(input.edge_weight_matrix != NULL)
      free(input.edge_weight_matrix[i]);
    if(input.display_data != NULL)
      free(input.display_data[i]);
  }
  free(input.edge_weight_matrix);
  free(input.display_data);
}

static void free_erreur(FILE* input_file, char* line_ptr)
{
  /* Libère la mémoire utilisé par le buffer si une erreur survient, 
   * ferme le flux, et libère la mémoire de la structure, si des champs ne sont
   * pas initialiser, on fait free(NULL) ce qui est une expression valide.*/
  free_input_data();
  free(line_ptr);
  fclose(input_file);
  exit(EXIT_FAILURE);
}

static void affiche_erreur(){
  /* errno == -1 ou 0, erreur appels système ou erreur fonction bibliotheque */
  if(errno || errno==-1) 
    perror("Erreur du la lecture du fichier./nConsultez l'entrée errno du manuel pour plus d'information\nErreur");
  else
    error(0,0,"Erreur de lecture de l'entrée.");
}

static bool verif_champ_entree(char* ligne_ptr, const char* champ_attendu, const char* pattern){
    char* champ = NULL;
    sscanf(line_ptr, pattern, &champ);
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

static bool est_valide(bool est_chaine,bool flag,FILE* imput_file,char* ligne_ptr,const char* pattern,bool erreur_possible,const char* chaine_attendu,const char* message_erreur)
{
  /* On ignore le "%ms" systématiquement passer avec pattern */
  int taille = strlen(pattern)-3;
  if(flag && !strncmp(ligne_ptr,pattern,taille)) /*voir commentaire fonction verif_champ_entree*/
  {
    /* Dans le cas où un pattern à été localiser, si le champ suivant est incorrect
     * On va donner une erreur et quitter le programme */
    if(erreur_possible)
    {
      if(est_chaine)
      {
	if(!verif_champ_entree(ligne_ptr,chaine_attendu,pattern))
	  {
	    error(0,0,message_erreur);
	    /* free_erreur libère propremment la mémoire avant lancer un exit(FAILURE), 
	     * tous les OS ne faisant par forcement bien leur travail  ...*/
	    free_erreur(imput_file,ligne_ptr);
	  }
      }
      return true;
    }
    return true;
  }

static char* alloc_chaine(int taille_ligne,int taille_pattern,char* ligne_lue)
{
  /* getline renvoie la longueur de la ligne sans '/0' ,d'où le +1*/
  char* alloc = malloc(sizeof(char)*(taille_ligne+1-taille_pattern));
  strcpy(alloc,ligne_lue+taille_pattern);
  return alloc;
}

void parsing_champs(FILE* nom_file,char* line_ptr, int *taille_alloc)
{   
  /* On utilise des flags afin d'éviter des tests inutiles. */
  bool edge_weight_format_flag = false;
  bool display_data_type_flag = false;
    
  int taille_ligne = 0;
  while((taille_ligne = getline(line_ptr, taille_alloc, nom_file)) != EOF)/* EOF généralement égal a -1*/
    {
      /* On verifie sur chaque ligne si des paramètres valides sont insérer
       * si true, on parse.
       * On utilise la fonction est_valide surtout pour des raisons de lisibilité,
       * Une fonction vraiment générique étant difficilement réalisable. */

      /*------- NAME -------*/
      if(est_valide(imput.nom==NULL,nom_file,*ligne_ptr,"NAME: %42",false,NULL,NULL))
      {
	/* On pourrait allouer directement la mémoire avec sscanf, mais le code est peu-etre
	 * plus lisible en passant par alloc_chaine*/
	imput.nom=alloc_chaine(taille_ligne,6,*ligne_ptr);
	if(!strcmp('',imput.nom))
	  input.nom=alloc_chaine(6,0,"NoName");
	continue;
	/* Une ligne ne peut etre associé a au plus un champs, pas la peine d'évaluer d'autres expressions.*/
      }
        
      /*------ TYPE -------*/
      if(est_valide(input.type==NULL,nom_file,*ligne_ptr,"TYPE: %ms",true,"TSP","TYPE non géré."))
      {
	/*Si une erreur est survenue, est_valide a lancé un exit.*/
	imput.type=alloc_chaine(taille_ligne,6,*ligne_ptr);
	continue;
      }

      /*------ COMMENT ------*/
      if(est_valide(input.commentaire==NULL,nom_file,*ligne_ptr,"COMMENT: %42",false,NULL,NULL))
      {
	imput.commentaire=alloc_chaine(taille_ligne,9,*ligne_ptr);
	if(!strcmp('',imput.commentaire))
	  input.commentaire=alloc_chaine(6,0,"NoComm");
	continue;
      }
	  
        
      /*------ DIMENSION ------ AMELIORATION POSSIBLE EN MODIFIANT est_valide.*/
      if(est_valide(imput.dimension==0,nom_file,*ligne_ptr,"DIMENSION: %42",false,NULL,NULL))
      {
	sscanf(*line_str,"DIMENSION: %d",&input.dimension);
	if(input.dimension<=0)
	{
	  error(0,0,"Dimension incorrecte");
	  free_erreur(nom_file,*ligne_ptr);
	}
	continue;
      }

      /*------ EDGE WEIGHT TYPE ------*/
      if(est_valide(imput.edge_weight_type==NULL,nom_file,*ligne_ptr,"EDGE_WEIGHT_TYPE: %ms",true,"EXPLICIT","EDGE_WEIGHT_TYPE non géré."))
      {
	imput.edge_weight_type=alloc_chaine(taille_ligne,18,*ligne_ptr);
	continue;
      }

      /*------ EDGE WEIGHT FORMAT ------*/
      if(est_valide(imput.edge_weight_format==NULL,nom_file,*ligne_ptr,"EDGE_WEIGHT_FORMAT: %ms",true,"FULL_MATRIX","EDGE_WEIGHT_FORMAT non géré."))
      {
	imput.edge_weight_type=alloc_chaine(taille_ligne,18,*ligne_ptr);
	continue;
      }

      /*------ DISPLAY_DATA_TYPE ------*/
      if(est_valide(input.display_data_type==NULL,nom_file,*ligne_ptr,"DISPLAY_DATA_TYPE: %ms",true,"TWOD_DISPLAY","DISPLAY_DATA_TYPE non géré."))
      {
	imput.edge_weight_type=alloc_chaine(taille_ligne,20,*ligne_ptr);
	continue;
      }

      /*------EDGE------*/
