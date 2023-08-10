#include <stdio.h>
#include <stdlib.h>
struct temps{
	unsigned heures;
	unsigned minutes;
	unsigned secondes;
};


int main () {

	struct temps t1;
	struct temps *t = &t1;
	
	(*t).heures = 10;
	t->minutes = 30;
	(*t).secondes = 40;
	printf("Le contenu de la structure pointer par t :\n");
	printf("%u , %u , %u\n",(*t).heures,(*t).minutes,(*t).secondes);
	printf("Le contenu de la structure t1 :\n");
	printf("%u , %u , %u\n",t1.heures,t1.minutes,t1.secondes);
	return 0;
}
