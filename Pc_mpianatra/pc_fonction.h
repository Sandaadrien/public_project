#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pc {
	char mac[256];
	char label[256];
	char marque[256];
}Pc;
char ** mitri(char ** tab, int dim , char ** compl , char ** compl2);
