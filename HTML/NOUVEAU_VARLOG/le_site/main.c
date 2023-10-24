#include "./necessaire.h"

void blabla_aloha(char * phrase_recue);

int main() {
	
	char * phrase_recue = getenv("QUERY_STRING");
	char * phrase_file = malloc(sizeof(char)*255);
	char * phrase_var = malloc(sizeof(char)*1000);

	FILE * f_olona_connecter = NULL;
	FILE * f_var_log = NULL;
	
	f_var_log = manokatraFichier(f_var_log , "/var/log/auth.log", "r");
	f_olona_connecter = manokatraFichier(f_olona_connecter , "../DONNEE/olona_connecter" , "r");
	
	int boolean = 0;

	boolean = manamarina_identite(phrase_recue , phrase_file , f_olona_connecter);
	
	blabla_aloha(phrase_recue);

	if(boolean == 0){
		printf("<meta http-equiv=\"refresh\" content=\"0.2;url=http://www.sandaniaina.com/cgi/fiche_inscription.cgi\"/>");
	}

	else if(boolean == 1){
		printf("<h1>Fichiers traitant <br />les informations du fichier<br/> /var/log/auth.log</h1>");
	}


	printf("<div class=\"conteneur1-image\">"
				"<div class=\"conteneur2-image\">"
					"<img class=\"logo\" src=\"../INSCRIPTION/images/centos.svg\"/>"
					"<img class=\"logo\" src=\"../INSCRIPTION/images/debian.svg\"/>"
					"<img class=\"logo\" src=\"../INSCRIPTION/images/ubuntu.svg\"/>"
					"<img class=\"logo\" src=\"../INSCRIPTION/images/redhat.svg\"/>"
					"<img class=\"logo\" src=\"../INSCRIPTION/images/centos.svg\"/>"
				"</div>"
			"</div>"
	);

	printf("<div class=\"div-connection\">"
				"<div class=\"div-log\"><a href=\"http://www.sandaniaina.com/cgi/deconnection.cgi?%s\">Se deconecter <img class=\"deconnection\"src=\"../INSCRIPTION/images/deconnection.svg\" /></a></div>"
				"<a href=\"#\"><img class=\"connection\" src=\"../INSCRIPTION/images/circle-user.svg\" alt=\"parametre de session\" /></a>"
			"</div>",phrase_recue);
	printf("</body>");
	printf("</html>");

	free(phrase_file);
	free(phrase_var);

	fclose(f_olona_connecter);
	fclose(f_var_log);

	return 0;
}

void blabla_aloha(char * phrase_recue){

	printf("Context-Type: text/html\n\n");

	printf("<html>");
	printf("<head>"
			"<title>varlog</title>"
			"<meta charset=\"utf-8\">"
	);
	fonction_css();
	printf("</head>");
	printf("<body>");
	printf("<div class=\"navbar\">"	
			"<ul class=\"lien\">"
				"<li class=\"debut\">"
					"<ul class=\"ul-interne\">"
						"<li><a href=\"http://www.sandaniaina.com/cgi/session.cgi?debut=1~%s\">Les sessions d'utilisateur</a></li>"
					"</ul>"
				"</li>"
//http://www.sandaniaina.com/cgi/rechercheVarlog.cgi?debut=1~log=nom=sanda&pass=123~chaine=gdm
			"<li class=\"farany\">"
				"<form method=\"get\" action=\"http://www.sandaniaina.com/cgi/rechercheVarlog.cgi\">"
					"<input type=\"text\" placeholder=\"login a rechercher\" name=\"debut=1~log=%s~chaine\"/>"
					"<input type=\"submit\" value=\"rechercher\" />"
				"</form>"
			"</li>"
			"</ul>"
			"</div>"
			"<hr />"
	,phrase_recue,phrase_recue);

}
