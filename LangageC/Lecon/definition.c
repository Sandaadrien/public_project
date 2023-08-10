#include <stdio.h>
#include <string.h>
struct temps{
	char nom[50];
	unsigned heure;
	unsigned minutes;
	unsigned long secondes;
};

int main () {
/*	
	// initialisation général
	
	struct temps tmp = {"t2", 1, 2,3};
	printf("Initialisation :\n");
	printf("%s : %u , %u , %lu",tmp.nom,tmp.heure,tmp.minutes,tmp.secondes);

*/	
	
	//initialisation selective : 
	struct temps tmp = {.nom="t3",.heure=3,.minutes=2,.secondes=1};
	printf("%s : %u , %u , %lu",tmp.nom,tmp.heure,tmp.minutes,tmp.secondes);
	
	strcpy(tmp.nom,"t1");
	tmp.heure = 10;
	tmp.minutes = 20;
	tmp.secondes = 20;
	
	printf("\nAffectation :\n");
	printf("%s : " ,tmp.nom);
	printf("%u , %u , %lu", tmp.heure , tmp.minutes , tmp.secondes);
	return 0;
}
