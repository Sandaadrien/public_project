#include "pc_fonction.h"
int main() {
	
	FILE * file;
	FILE * file2;
	file = fopen("pc.csv","w");
	file2 = fopen("pcOriginal.csv","r");
	int i;
	Pc *pc= malloc(sizeof(Pc)*46);
	char * tmp = malloc(sizeof(char)*256);
	char ** label = malloc(sizeof(char*)*46);
	char ** mac = malloc(sizeof(char*)*46);
	char ** marque = malloc(sizeof(char*)*46);
	int j;
	for(j=0;j<46;j++)
		*(label+j) = malloc(sizeof(char)*256);
	for(j=0;j<46;j++)
		*(mac+j) = malloc(sizeof(char)*256);
	for(j=0;j<46;j++)
		*(marque+j) = malloc(sizeof(char)*256);
	fscanf(file2, "%s",tmp);
	for(i=1;!feof(file2);i++){
		fscanf(file2, "%[^;];%[^\n;];%[^\n;]",pc[i].mac,pc[i].label,pc[i].marque);
		fprintf(file , "%s ; %s ; %s\n",pc[i].mac,pc[i].label,pc[i].marque);
	
		strcpy(*(label+i) ,pc[i].label );
		strcpy(*(mac+i) , pc[i].mac);
		strcpy(*(marque+i), pc[i].marque);
	}
	
	mitri(label , 46 , mac, marque);
	
	
	fprintf(file , "%s\n",tmp);

	for(int i=0;i<46;i++)
		fprintf(file , "%s ; %s ; %s\n",*(mac+i),*(label+i),*(marque+i));
	

	fclose(file);
	
	printf("Vos donnez sont enregistrer dans pc.csv\n-->Les tries sont en bas des informations\n");
	
	return 0;
}
