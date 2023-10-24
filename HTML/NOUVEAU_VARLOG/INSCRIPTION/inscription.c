

#include "fichierH/inscription/inscription.h"

int main() {

	//	declaration
	FILE * fdonnee = NULL;
	
	char * motRecue = getenv("QUERY_STRING");
	char * login = malloc(sizeof(char)*100);
	char * pass = malloc(sizeof(char)*100);
	char * login_fichier = malloc(sizeof(char)*100);
	char * mot_comparer = malloc(sizeof(char)*255);
	char * pass_fichier = malloc(sizeof(char)*100);

	//	programme
	printf("Context-Type: text/html\n\n");
	
	printf("<html>");
	
	printf("<head>");
	printf("<meta charset=\"utf-8\" />");
	printf("<title>inscription</title>");
	function_css();
	printf("</head>");
	
	// body
	
	printf("<body>");
	fdonnee = fopen("../DONNEE/login" , "a+");
	int boole = 1;
	if(fdonnee == NULL){
		printf("<p>Tsy nisokatra ny fichier login</p>");
		exit(1);
	}

	else if(fdonnee != NULL){
		
		inscription(motRecue , mot_comparer , login_fichier , pass_fichier , fdonnee , login , pass , boole);

	}
	printf("</body>");
	printf("</html>");

	// end of programme
	
	fclose(fdonnee);
	free(login);
	free(login_fichier);
	free(pass_fichier);
    	return 0;
}
