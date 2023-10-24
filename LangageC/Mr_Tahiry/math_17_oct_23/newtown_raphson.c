
#include <stdio.h>
#include <math.h>

#define eps 0.00001

double fonction(double x);
double derive(double x);
double mitadyX2(double a);

int main() {
	
	double a=2.0 , b= mitadyX2(a);
	int i= 0;
	while(fabs(a-b)>=eps){
		printf("%f et %f\n",a,b);
		a = b;
		b = mitadyX2(a);
		i++;
	}

	printf("%f\n",b);

	return 0;
}
double mitadyX2(double a){
	return (a - (fonction(a)/derive(a)));
}
double derive(double x){
	return cos(x);
}

double fonction(double x){
	return sin(x);
}
