#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 10000 // Tableau de taille 1000

int* conversionTSP(char* fichier)
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
 
    fichier = fopen(fichier, "r");
 
    if (fichier != NULL)
    {
      while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
      {
	
        printf("%s", chaine); // On affiche la chaîne
 
        fclose(fichier);
    }
 
    return 0;
}
