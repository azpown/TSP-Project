#ifndef INPUT
#define INPUT

/**
 * \file Input.h
 * \author Delmas Rémi
 * \brief Module pour le parsing de fichier TSP
*/

typedef struct input *Input;

/**
 * \brief Affiche une instance de type Input.
 * \param input instance de type Input à afficher.
*/
void print_input_data(Input input);

/**
 *\brief Fonction de parsing d'un fichier TSP.
 *\param nom_file chemin du fichier .tsp à parser.
 *\pre Présentement, il n'y a que les instances de type FULL_MATRIX qui sont gérées
 * un message d'erreur est affiché et la mémoire est libéré en cas de format incorrect.
 * La matrice de donnée doit etre symétrique et contenir des valeurs strictement  positives
 *\post l'instance Input doit etre free via free_input.
*/
Input open_TSP_file(char* nom_file);

/**
 *\brief Fonction de destruction d'une instance Input.
*/
void free_input(Input input);

/**
 *\brief Retourne le nom du fichier .tsp qui a servi à générer l'instance d'Input passée en paramètre.
*/
char* get_nom_file(Input input);

/**
 *\brief Retourne le champs nom du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
 *\pre si ce champs est vide ou non présent, la valeur renvoyée est "NoName".
*/
char* get_nom(Input input);

/**
 *\brief Retourne le champs type (ex: TSP) du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
*/
char* get_type(Input input);

/**
 *\b Retourne le champs commentaire du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
 *\pre si ce champs est vide ou non présent, la valeur renvoyée est "NoComm".
*/
char* get_commentaire(Input input);

/**
 *\brief Retourne la dimension (Pas de borne sup) de la matrice du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
 *\pre la dimension doit etre strictement supérieure a 0.
*/
int   get_dimension(Input input);

/**
 *\brief Retourne le champs edge_weight_type (ex: EXPLICIT) du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
*/
char* get_edge_weight_type(Input input);

/**
 *\b Retourne le champs edge_weight_format (ex: FULL_MATRIX) du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
*/
char* get_edge_weight_format(Input input);

/**
 *\brief Retourne le champs display_data_type (ex: TWOD_DISPLAY) du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
*/
char* get_display_data_type(Input input);

/**
 *\brief Retourne la matrice de travail du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
 *\pre les valeurs contenues dans la matrice doivent être strictements supérieures a 0.
*/
double** get_edge_weight_matrix(Input input);

/**
 *\brief Retourne la matrice d'affichage du fichier .tsp qui a servi à générer l'instance d'Input en paramètre.
*/
double** get_display_data(Input input);

#endif 
