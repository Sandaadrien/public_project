
#include <stdio.h>
#include <math.h>

#define eps 0.0000001

double fonction(double x);
double mitadyX2(double a , double b);

int main() {

	double a=3.00 , b=4.00 ,x;

	while(fabs(a-b)>=eps){
		
		printf("%f et %f\n ",a,b);
		x = mitadyX2(a,b);
		if((fonction(x)*fonction(b))<=0){
			a = x;
		}
		else if((fonction(x)*fonction(b))){
			b = x;
		}

	}

	printf("%f\n",x);

	return 0;
}

double fonction(double x){
	return sin(x);
}

double mitadyX2(double a , double b){

	double num = fonction(b)*(b-a);
	double deno = fonction(a) - fonction(b);
	
	return ( b + (num / deno));
}
