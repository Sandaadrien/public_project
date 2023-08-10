#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int charToDouble(char* car);
char** devirguler(char* car);

int main () {
	srand(time(NULL));
	FILE * file;
	FILE * f_exel;
	file = fopen("/etc/passwd" , "r");
	f_exel = fopen("user.csv" , "w");
	
	char *string= malloc(256 * sizeof(char));
	char ** retour= malloc(7 * sizeof(char*));
	int uid;
	for(int i=0;i<7 ; i++){
	 *(retour+i) = malloc(256 * sizeof(char));
	}
	fprintf(f_exel , "%s;%s;%s;%s;%s","login","adresse_mail","mot-de-passe","répertoire","shell\n");
	while(!feof(file)){

		if(uid < 6000 && uid >= 1000){
			fprintf(f_exel , "%s ;" , *(retour));
			fprintf(f_exel , "%s ; %d ; %s ; %s ; %s",strcat(*(retour) , "@gmail.com"), rand() % 100 , *(retour+5) , *(retour+6) ,"\n");	
		}
	//sanda:x:1000:1000:sanda,,,:/home/sanda:/bin/bash
		fgets(string , 256 , file);
		retour = devirguler(string);

		uid = charToDouble(*(retour+2));
		for(int i=0;i<20000;i++){}
	}

	fclose(f_exel);
	fclose(file);
	
	printf("Vos donner sont enregistrer dans user.csv");
	
	return 0;
}

char** devirguler(char* car){
	
	char** tab2Char=NULL;
	int i,j,n;
	
	tab2Char = malloc(7*sizeof(char*));
	for(int i=0;i< 7 ; i++)
		*(tab2Char+i) = malloc(256 * sizeof(char));
	
	for(i=0,j=0,n=0;*(car+i);i++){
		if(*(car+i)== ':'){
			j++;
			n = 0;
			continue;
		}
	
		*(*(tab2Char+j)+n) = *(car+i);
		/// Tsy azo apiakarina eny amin'ny boucle !! :
		n++;
	}
	
	return tab2Char;
}
int charToDouble(char* car){
	
	int nombre=0;
	int isa,mem;
	isa = strlen(car);
	mem = isa;
	for(int i=0;i<mem;i++,isa--){
		nombre += (*(car+i)-48)*pow(10,isa-1);
	}
	return nombre;
}
