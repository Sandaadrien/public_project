#include "fonction.h"


int main () {
	
	printf("Ce programme affiche le résultat de la fonction f(x) = x/2\n");
	printf("\nPour l'interval [0;20]\n");
	FILE *file;
	
	file = fopen("fonction.csv" , "w");
	
	fprintf(file , "%s ; %s\n","x" , "f(x) = x/2");
	for(int i = 0;i<=20;i++){
		fprintf(file , "%d ; %.2f ;%s" , i , fonction(i),"\n");
	}
	
	printf("\n\n-->Les résultats sont stockés dans fonction.csv\n");
	
	return 0;
}

