#include "mpianatra_fonction.h"

char ** mitri(char ** tab, int dim , char ** compl){
	char tmp[256];
	for(int i=0;i<dim ; i++){
		for(int j=i ; j<dim ; j++){
			if(strcmp(tab[j] , tab[i]) < 0){
				strcpy(tmp , tab[i]);
				strcpy(tab[i] ,tab[j] );
				strcpy(tab[j] ,tmp );
				
				strcpy(tmp , compl[i]);
				strcpy(compl[i] , compl[j]);
				strcpy(compl[j] , tmp);
				
			}
			
		}
	}
	return tab;
}
