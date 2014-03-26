#ifndef INPUT
#define INPUT

typedef struct input *Input;

void print_input_data(Input input);
Input open_TSP_file(char* nom_file);
void free_input(Input input);
char* get_nom_file(Input input);
char* get_nom(Input input);
char* get_type(Input input);
char* get_commentaire(Input input);
int   get_dimension(Input input);
char* get_edge_weight_type(Input input);
char* get_edge_weight_format(Input input);
char* get_display_data_type(Input input);
double** get_edge_weight_matrix(Input input);
double** get_display_data(Input input);

#endif 
