#include <stdio.h>
#include <math.h>
#define pi 3.141592

int main () {
	
	FILE* file;
	
	file = fopen("trigo.csv" , "w");
	
	fprintf(file , "%s ; %s ; %s ; %s ; %s" , "angle" ,"sinus" , "cosinus" , "tan" , "artan\n");
	double angle;
	
	for(int i=0;i<=360;i++){
		angle = i * pi / 180;
		fprintf(file , "%d ; %f ; %f ; %f ; %f ; %s" , i, sin(angle) , cos(angle) , tan(angle) , atan(angle) , "\n"); 
	}
	
	fclose(file);
	
	printf("Vos résultats sont stockés dans trigo.csv");
	
	return 0;
}
