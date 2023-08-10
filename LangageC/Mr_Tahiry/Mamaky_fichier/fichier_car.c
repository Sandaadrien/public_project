#include <stdio.h>
#include <stdlib.h>

int main () {
	printf("Ce programme lit un texte à partir d'un fichier(fichierALire)\nCaractère par caractère :\n\n");
	FILE * file;
	char car;

	file = fopen("fichierALire.txt" , "r");

	if(file == NULL){
		printf("Tsy misokatra ny fichier anao\n");
		exit(1);
	}

	while(EOF != car){
		car = fgetc(file);
		printf("%c",car);
	}

	fclose(file);

	return 0;

}
