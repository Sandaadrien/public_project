#include <stdio.h>
#include <math.h>

#define eps 0.000001

double fonction(double x);

int main() {
	
	double a=1,b=4,m;
	
	while(fabs(a-b)>eps){
		m = fabs((a+b))/2;
		if((fonction(m)*fonction(a))<=0){
			b = m;
		}
		else if((fonction(m)*fonction(b))<=0){
			a = m;
		}
	}
	printf("%f\n",m);
	
	return 0;
}

double fonction(double x){
	return sin(x);
}
