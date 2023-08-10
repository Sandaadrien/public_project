#include <stdio.h>

struct temps{
	unsigned heures;
	unsigned minutes;
	unsigned secondes;
};

long structSeconde(struct temps t);

int main() {
	
	struct temps t1={1,2,3};
	struct temps t2={1,2,3};
	
	long diffSec = structSeconde(t1) - structSeconde(t2);
	
	if(diffSec<0)
		diffSec *= -1;
		
	printf("La différence de temps entre");
	printf("%u:%u:%u et %u:%u:%u est :\n-->%ld\n",t1.heures,t1.minutes,t1.secondes,t2.heures,t2.minutes,t2.secondes,diffSec);
	
	return 0;
}

long structSeconde(struct temps t){
	long sec = t.secondes;
	sec += t.minutes*60;
	sec += t.heures*3600;
	return sec;
}
