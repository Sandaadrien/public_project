#include "mpianatra_fonction.h"



int main() {

	FILE * file;
	
	file = fopen("mpianatra.csv","w");
	int i=1,mode=0;
	Mpianatra mpianatra[46];
	
	printf(" ---------------------------------------\n");
	printf("| Entrer le mode d'entrer des données : |\n");
	printf("| [0] -> Avec un fichier                |\n");
	printf("| [1] -> Entrer par le clavier          |\n");
	printf(" ---------------------------------------\n===>");
	scanf("%d",&mode);
	if(mode == 1){	
		fprintf(file,"%s ; %s ; %s; %s ; %s ; %s; %s","nom","prenom","parcours","grade","niveau","numéro d'inscription","\n");
		for(;i<=46;i++){
			printf("Entrer le nom de l'étudiant : ");
			scanf("%[^\n]",mpianatra[i].nom);
			
			printf("Entrer le prénom de l'étudiant : ");
			scanf("%[^\n]",mpianatra[i].prenom);
			
			printf("Entrer le parcours de l'étudiant : ");
			scanf("%[^\n]",mpianatra[i].parcours);
			
			printf("Entrer le grade de l'étudiant : ");
			scanf("%[^\n]",mpianatra[i].grade);
			
			printf("Entrer le niveau de l'étudiant : ");
			scanf("%[^\n]",mpianatra[i].niveau);
			
			printf("Entrer le numéro d'inscription de l'étudiant : ");
			scanf("%[^\n]",mpianatra[i].numInscription);
			
			fprintf(file, 
			"%s ; %s ; %s ; %s ; %s ; %s ; %s",
			mpianatra[i].nom,mpianatra[i].prenom,mpianatra[i].parcours, mpianatra[i].grade, mpianatra[i].niveau, mpianatra[i].numInscription,"\n");
		}
	}
	else{
		FILE * file2;
		file2 = fopen("mpianatraOriginal.csv","r");
		for(;!feof(file2);i++){
			fscanf(file2, "%[^;] ; %[^;] ; %[^;]; %[^;] ; %[^;] ; %[^\n]",mpianatra[i].nom,mpianatra[i].prenom,mpianatra[i].parcours, mpianatra[i].grade, mpianatra[i].niveau, mpianatra[i].numInscription);
			fprintf(file, 
			"%s ; %s ; %s ; %s ; %s ; %s",
			mpianatra[i].nom,mpianatra[i].prenom,mpianatra[i].parcours, mpianatra[i].grade, mpianatra[i].niveau, mpianatra[i].numInscription);
			
		}
/*---------------------------------------------------------------------*/
		i-=2;
		int j;
/*---------------------------------------------------------------------*/	
		char ** nom = malloc(i*sizeof(char*));
		for(j=0;j<i;j++)
			*(nom+j) = malloc(256*sizeof(char));

		char ** tmp = malloc(i*sizeof(char*));
		for(j=0;j<i;j++)
			*(tmp+j) = malloc(256*sizeof(char));
/*---------------------------------------------------------------------*/			
		rewind(file2);
		for(j=0;j<i;j++)
			fscanf(file2 , "%[^;];%[^\n]",*(nom+j),*(tmp+j));
		
		fclose(file2);
		file2 = fopen("mpianatra.csv","w");
		mitri(nom , i , tmp);
		for(int j=0; j <(i-2) ; j++){
			fprintf(file , "%s ; %s ",*(nom+j),*(tmp+j));
		
		}
		
		fclose(file2);
	}
	
	printf("Vos résultats sont stockés dans le fichier.csv\n");
	
	fclose(file);
	return 0;
}

