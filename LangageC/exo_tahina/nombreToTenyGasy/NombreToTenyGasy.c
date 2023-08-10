#include "nombre_teny_gasy.h"

int main () {
	int nombre = 0;
	printf("enter your number : ");
	scanf("%d",&nombre
	);
	int tmp = nombre;/// pour conserver la valeur du nombre any amin'ny lavitrisa
	int* nbMisaraka;
	nbMisaraka = manasaraka(nombre);
	char* gasy = malloc(sizeof(char)*100);
	gasy = manonona(nbMisaraka,manisa(nombre),nombre);
	//printf("%s\n",gasy);
	if(manisa(nombre)>6){
	/// manaboatra ny tapitrisa
		nombre = nombre/pow(10,6);
		nombre = nombre%(int)pow(10,3);// le nombre 3 manaraka ihany no atao  ao amin'ny fonction manonona
		nbMisaraka = manasaraka(nombre);
		gasy = strcat(gasy,strcat(manonona(nbMisaraka,manisa(nombre),nombre)," tapitrisa "));
	}
	
	if (manisa(tmp)>9){	
		/// manamboatra ny lavitrisa
		tmp = tmp/pow(10,9);
		nbMisaraka = manasaraka(tmp);
		strcat(gasy," sy ");
		gasy = strcat(gasy,strcat(manonona(nbMisaraka,manisa(tmp),tmp)," lavitrisa "));
	}
	printf("\n%s\n",gasy);
	return 0;
}
