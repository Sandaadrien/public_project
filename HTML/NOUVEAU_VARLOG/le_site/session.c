

#include "./necessaire.h"

#define TAILLE_TEXT 255


/*-----------------------------------------------------------------------*/


typedef struct StructLine{
	char * temps;
	char * nom_pc;
	char * environnement;
	char * type_session;
	char * mot_cle;
	char * fermeture_ouverture;
	char * tmp1;
	char * tmp2;
	char * loginDeConnection;
	char * tmp3;
	char * loginDuConnectant;
}StructLine;

typedef struct User{
	char * login;
	int uid;
}User;


/*-----------------------------------------------------------------------*/


StructLine creeStructLine();
StructLine * creeTabStructLine(StructLine * pStruct , int nbLine);
void destroyStructLine(StructLine * ligne);
User creeUser();
int manisaLineFichier(FILE * pFile);
User * creeTabUser(User * pUser , int nbUser);
void makaLoginUid(User * pUser , int isaUser , FILE * file);
int manisaVarlogSession(FILE * fvarlog);
char * manala_farany(char * chaine , int taille);
void GetInfo(StructLine * tabLine ,FILE * file , User * tabUser , int isaPasswd , char * phrase_recue , int debut);

/*-----------------------------------------------------------------------*/


int main(){
	printf("Content-Type:text/html\n\n");
	printf("<head>");

	printf("<title>Les sessions dans var Log</title>");
	printf("<style>");
	printf("body{");
	printf("background-color: rgba(73, 73, 129, 0.685);");
	printf("color: white;");
	printf("}");
	printf("div{");
	printf("margin: 100px 25%%;");
	printf("}");
	printf("table{");
	printf("border: 1px solid black;");
	printf("text-align: center;");
	printf("background-color : rgba(0, 0, 0, 0.7);");
	printf("}");
	printf("td{");
	printf("border: 1px solid transparent;");
	printf("}");
	printf("a{");
	printf("text-decoration: none;");
	printf("color: white;");
	printf("}");
	printf("</style>");
	
	printf("</head>");
	char * phrase_recue = manamboatraChaine(phrase_recue, TAILLE_TEXT);
	char * environnementVar = getenv("QUERY_STRING");
	char * phrase_file = manamboatraChaine(phrase_file , TAILLE_TEXT);

	FILE * varlog = NULL,* passwd = NULL , * f_olona_connecter = NULL;
	f_olona_connecter = manokatraFichier(f_olona_connecter , "../DONNEE/olona_connecter" , "r");
	char * chaine = NULL,*tmp = NULL;
	User * tabUser = NULL;
	StructLine * tabLine = NULL;
	int isa=0,isaPasswd=0;
	int boolean = 0;
/* 	char * chaineARechercher = manamboatraChaine(chaine , TAILLE_TEXT);
	strcpy(chaineARechercher , "sanda"); */


	chaine = manamboatraChaine(chaine , TAILLE_TEXT);
	tmp = manamboatraChaine(tmp , TAILLE_TEXT);
	
	varlog = manokatraFichier(varlog , "/var/log/auth.log" , "r");
	passwd = manokatraFichier(passwd , "/etc/passwd" , "r");
	

	isa = manisaLineFichier(passwd);
	isaPasswd = isa;
	tabUser = creeTabUser(tabUser , isa);
	rewind(passwd);
	
	makaLoginUid(tabUser , isa , passwd);

	isa = manisaVarlogSession(varlog);
	tabLine = creeTabStructLine(tabLine , isa);
	rewind(varlog);
	
	printf("<body>");
//debut=0~nom=sanda&pass=123
	int debut = 0;
	sscanf(environnementVar , "debut=%d~%s" ,&debut,phrase_recue );

	//printf("<p>%d et %s</p>",debut, phrase_recue);

	boolean = manamarina_identite(phrase_recue,phrase_file , f_olona_connecter);
 	if(boolean == 0){
		printf("<meta http-equiv=\"refresh\" content=\"0.2;url=http://www.sandaniaina.com/cgi/fiche_inscription.cgi\"/>");
	}
	
	GetInfo(tabLine , varlog , tabUser , isaPasswd , phrase_recue , debut);
/*
	for(int i=0;i<isa;i++){
		if(!strcmp((*(tabLine+i)).loginDeConnection , chaineARechercher)){
			printf("%s\n", (*(tabLine+i)).loginDeConnection);
		}
	}
*/	
	printf("</body>");
	fclose(varlog);
	fclose(passwd);
	
	free(chaine);
	free(tabUser);
	free(tabLine);
	
	return 0;
}
/*-----------------------------------------------------------------------*/
void GetInfo(StructLine * tabLine ,FILE * file , User * tabUser , int isaPasswd , char * phrase_recue , int debut){
	int isa=0;
	char * text = malloc(sizeof(char)*255);
	char * temp = malloc(sizeof(char)*255);
	printf("<div>");
	printf("<table>");
	printf("<thead>");
	printf("<tr>");
	printf("<th>TEMPS</th>");
	printf("<th>MODE DE SESSION</th>");
	printf("<th>LOGIN DE CONNECTION</th>");
	printf("</tr>");
	printf("</thead>");
	int i=0;
	int fin = debut+10;
	
	for(isa = 0 ;fgets(text ,TAILLE_TEXT, file) != NULL;){
		
		if(i+1>fin){
			break;
		}
		
		if((strstr(text , "session closed")) || (strstr(text , "session opened") != NULL) || (strstr(text , "Accepted")) || (strstr(text, "Failed")) || (strstr(text , "logout")) ){
			i++;

			sscanf(text ,"%[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ]", 
			(*(tabLine+isa)).temps, (*(tabLine+isa)).nom_pc, (*(tabLine+isa)).environnement, (*(tabLine+isa)).type_session, (*(tabLine+isa)).mot_cle,
			(*(tabLine+isa)).fermeture_ouverture, (*(tabLine+isa)).tmp1, (*(tabLine+isa)).tmp2, (*(tabLine+isa)).loginDeConnection, (*(tabLine+isa)).tmp3,(*(tabLine+isa)).loginDuConnectant);
			(*(tabLine+isa)).loginDeConnection = manala_farany((*(tabLine+isa)).loginDeConnection , TAILLE_TEXT);
	
			for(int i=0; i<isaPasswd ; i++){
				if(strstr((*(tabUser+i)).login , (*(tabLine+isa)).loginDeConnection) != NULL ){
					strcpy((*(tabLine+isa)).loginDeConnection , (*(tabUser+i)).login);
				}
				else if(strtok((*(tabLine+isa)).loginDeConnection , "user=") !=NULL){
					sscanf((*(tabLine+isa)).loginDeConnection , "%[^(]uid=%d)", temp, &isa);
					strcpy((*(tabLine+isa)).loginDeConnection , temp);
				}
			
			}
			if(i>debut){
				(*(tabLine+isa)).temps = mamerinaDaty((*(tabLine+isa)).temps);
				printf("<tr>");
				printf("<td>%d %s</td>",isa,(*(tabLine+isa)).temps);
				printf("<td>%s</td>",(*(tabLine+isa)).fermeture_ouverture);
				printf("<td><a href=\"http://www.sandaniaina.com/cgi/rechercheVarlog.cgi?debut=1~log=%s~chaine=%s\">%s</a></td>",phrase_recue,(*(tabLine+isa)).loginDeConnection,(*(tabLine+isa)).loginDeConnection);
				printf("</tr>");
			}
			isa++;
			
		}
	}
	printf("</table>");
	printf("</div>");

	rewind(file);
	
	for(isa = 0 ;fgets(text ,TAILLE_TEXT, file) != NULL;){
		if((strstr(text , "session closed")) || (strstr(text , "session opened") != NULL) || (strstr(text , "Accepted")) || (strstr(text, "Failed")) || (strstr(text , "logout")) ){
			isa++;
		}
	}
	printf("<div>");

	for(int i=debut ; i<fin;i++){
		if(i==1){
			printf("<a href=\"http://www.sandaniaina.com/cgi/session.cgi?debut=%d~nom=sanda&pass=123\">%d&nbsp<a>",(isa - (isa-1)%10),i);
		}
		else if(i>isa-1){
			break;
		}
		else if(i==fin-1){
			printf("<a href=\"http://www.sandaniaina.com/cgi/session.cgi?debut=%d~nom=sanda&pass=123\">%d&nbsp<a>",i+1,i);
		}
		else if(i==isa-1){
			printf("<a href=\"http://www.sandaniaina.com/cgi/session.cgi?debut=1~nom=sanda&pass=123\">%d&nbsp<a>",i);
		}
		else if(i==debut){
			printf("<a href=\"http://www.sandaniaina.com/cgi/session.cgi?debut=%d~nom=sanda&pass=123\">%d&nbsp<a>",debut-10,i);
		}
		else{
			printf("<a href=\"#\">%d&nbsp</a>",i);
		}
	}
	printf("</div>");

	free(text);
	free(temp);
}
char * manala_farany(char * chaine , int taille){

	for(int i=0; i<taille; i++){
		if(*(chaine+i) == '\n'){
			*(chaine+i) = '\0';
		}
	}

	return chaine;
}
int manisaVarlogSession(FILE * fvarlog){
	int compt=0;
	char * text=NULL;
	text = manamboatraChaine(text , TAILLE_TEXT);
	
	for(compt=0;fgets(text ,TAILLE_TEXT, fvarlog) != NULL;){
		if((strstr(text , "session closed")) || (strstr(text , "session opened") != NULL) || (strstr(text , "Accepted")) || (strstr(text , "Failed")) || (strstr(text , "logout")) ){
			compt++;
		}
	}
	return compt;
}

void makaLoginUid(User * pUser , int isaUser , FILE * file){
	char * text = NULL;
	char * tmp = malloc(sizeof(char)*255);
	text = manamboatraChaine(text , TAILLE_TEXT);
	for(int i=0; fgets(text , TAILLE_TEXT, file)!=NULL; i++){
		tmp = strtok(text , ":");
		strtok(NULL , ":");
		sscanf(strtok(NULL , ":") , "%d" , &(*(pUser+i)).uid);
		(*(pUser+i)).login  = strdup(tmp);
	//	printf("%s et %d\n",(pUser+i)->login ,(*(pUser+i)).uid);

	}
	free(text);
}


int manisaLineFichier(FILE * pFile){

	int isa=0;
	char * text = NULL;
	text = manamboatraChaine(text , TAILLE_TEXT);
	while(fgets(text , TAILLE_TEXT , pFile) != NULL){
		++isa;
	}

	return isa;
}


User * creeTabUser(User * pUser , int nbUser){
	
	pUser = malloc(sizeof(User)*nbUser);
	for(int i=0 ; i<nbUser ; i++){
		*(pUser + i) = creeUser();
	}

	return pUser;
}


User creeUser() {
	User user;
	user.login = malloc(sizeof(char)*TAILLE_TEXT);
	return user;
}

StructLine * creeTabStructLine(StructLine * pStruct , int nbLine){
	pStruct = malloc(sizeof(StructLine)*nbLine);
	for(int i=0; i<nbLine ; i++){
		*(pStruct+i) = creeStructLine();
	}
	return pStruct;
}

StructLine creeStructLine() {

	StructLine ligne;

	ligne.temps = malloc(sizeof(char)*TAILLE_TEXT);
	ligne.nom_pc = malloc(sizeof(char)*TAILLE_TEXT);
	ligne.environnement = malloc(sizeof(char)*TAILLE_TEXT);
	ligne.type_session = malloc(sizeof(char)*TAILLE_TEXT);
	ligne.mot_cle = malloc(sizeof(char)*TAILLE_TEXT);
	ligne.fermeture_ouverture = malloc(sizeof(char)*TAILLE_TEXT);
	ligne.tmp1 = malloc(sizeof(char)*TAILLE_TEXT);
	ligne.tmp2 = malloc(sizeof(char)*TAILLE_TEXT);
	ligne.loginDeConnection = malloc(sizeof(char)*TAILLE_TEXT);
	ligne.tmp3 = malloc(sizeof(char)*TAILLE_TEXT);
	ligne.loginDuConnectant = malloc(sizeof(char)*TAILLE_TEXT);
	
	return ligne;
}

