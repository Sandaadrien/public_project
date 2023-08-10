#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
	printf("Ce programme demande l'ajout d'un nouvel utilisateur : \n");
	FILE * file;
	file = fopen("fichier.txt" , "a");
	printf("Entrer votre nom  : ");
	char * nom = malloc(256 * sizeof(char));
	scanf("%s",nom);
	fputs("Nom : ", file);
	fputs(strcat(nom,"\n"), file);
	
	printf("Entrer votre prenom  : ");
	scanf("%s",nom);
	fputs("Prénom: ", file);
	fputs(strcat(nom ,"\n"), file);

	printf("Entrer votre adresse  : ");
	scanf("%s",nom);
	fputs("Adresse : ", file);
	fputs(strcat(nom , "\n"), file);
	
	printf("Vos données sont dans fichier.txt");
	
	fclose(file);
	
	return 0;
}
