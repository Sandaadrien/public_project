#include <stdio.h>
#include <stdlib.h>

int main () {
	printf("Ce programme lit un texte à partir d'un fichier(fichierALire)\nLigne par ligne :\n\n");
	FILE * file;
	file = fopen("fichierALire.txt" , "r");
	if(file == NULL){
		printf("Tsy misokatra ny fichier anao\n");
		exit(1);
	}
	char ligne[256];
	while(!feof(file)){
		printf("%s" , ligne);
		fgets(ligne , 256 , file);
	}
	fclose(file);

	return 0;
}
