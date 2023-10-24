


#include "./necessaire.h"

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


FILE * manokatraFichier(FILE * file , char * chemin_fichier , char * mode);
char * manamboatraChaine(char * chaine , int nbCar);
StructLine creeStructLine();
StructLine * creeTabStructLine(StructLine * pStruct , int nbLine);
void destroyStructLine(StructLine * ligne);
User creeUser();
int manisaLineFichier(FILE * pFile);
User * creeTabUser(User * pUser , int nbUser);
void makaLoginUid(User * pUser , int isaUser , FILE * file);
int manisaVarlogSession(FILE * fvarlog);
char * manala_farany(char * chaine , int taille);
void GetInfo(StructLine * tabLine ,FILE * file , User * tabUser , int isaPasswd);
char * mamerinaDaty(char* date);

/*-----------------------------------------------------------------------*/


int main(){
	
	printf("Content-Type:text/html\n\n");
	printf("<head>");
	printf("<title>recherche par login</title>");
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
	printf("background-color: rgb(73 , 73 , 129);");
	printf("margin: auto;");
	printf("text-align: center;");
	printf("}");
	printf("td{");
	printf("border: 1px solid black");
	printf("}");
	printf("</style>");
	printf("</head>");
	
	FILE * varlog = NULL,* passwd = NULL , * f_olona_connecter = NULL;
	char * chaine = NULL,*tmp = NULL;
	User * tabUser = NULL;
	StructLine * tabLine = NULL;
	int isa=0,isaPasswd=0;
	int boolean = 0;
	
	char * chaineARechercher = NULL;
	chaineARechercher = malloc(sizeof(char)*255);
	char * environnementVar = malloc(sizeof(char)*255);
	char * misylogin = malloc(sizeof(char)*255);
	char * chaine_recue = malloc(sizeof(char)*255);
	char * phrase_file = malloc(sizeof(char)*255);
	chaine_recue = getenv("QUERY_STRING");
// debut%3D1%7Elog%3Dnom%3Dsanda%26pass%3D123%7Echaine=sanda
	char * nom = malloc(sizeof(char)*255);
	char * pass = malloc(sizeof(char)*255);
	char * find = malloc(sizeof(char)*255);
	int deb = 1;
//debut=1~log=nom=sanda&pass=123~chaine=gdm

	if(strstr(chaine_recue ,"%3D")!=NULL){
		sscanf(chaine_recue , "debut\%3D%d\%7Elog\%3Dnom\%3D%[^%]\%26pass\%3D%[^%]\%7Echaine=%s",&deb , nom, pass,find );
		sprintf(chaine_recue,"debut=%d~log=nom=%s&pass=%s~chaine=%s",deb , nom, pass,find);
	}
	int debut = 0;
	chaine = manamboatraChaine(chaine , TAILLE_TEXT);
	tmp = manamboatraChaine(tmp , TAILLE_TEXT);
	
	varlog = manokatraFichier(varlog , "/var/log/auth.log" , "r");
	passwd = manokatraFichier(passwd , "/etc/passwd" , "r");
	f_olona_connecter = manokatraFichier(f_olona_connecter , "../DONNEE/olona_connecter" , "r");	

	isa = manisaLineFichier(passwd);
	isaPasswd = isa;
	tabUser = creeTabUser(tabUser , isa);
	rewind(passwd);
	
	makaLoginUid(tabUser , isa , passwd);

	isa = manisaVarlogSession(varlog);
	tabLine = creeTabStructLine(tabLine , isa);
	rewind(varlog);
	
	GetInfo(tabLine , varlog , tabUser , isaPasswd);
	printf("<body>");

//log=nom=sanda&pass=123~chaine=sanda

	sscanf(chaine_recue , "debut=%d~log=%[^~]~%s",&debut,misylogin , environnementVar);
	printf("<p>%d et %d</p>",debut,isa);
//	printf("<p>%s et %s</p>",environnementVar , misylogin);	
	
	boolean = manamarina_identite(misylogin,phrase_file , f_olona_connecter);
	
	if(boolean == 0){
		printf("<meta http-equiv=\"refresh\" content=\"0.2;url=http://www.sandaniaina.com/cgi/fiche_inscription.cgi\"/>");
		//printf("<p>Tsy afaka manohy</p>");
	}
	sscanf(environnementVar , "chaine=%s",chaineARechercher);

	int isaOlona = 0 , l=0;
	for(l=0; l<isa;l++){
		if(!strcmp((*(tabLine+l)).loginDeConnection , chaineARechercher)){
		//	printf("<p>%s %s</p>",(*(tabLine+l)).loginDeConnection,chaineARechercher);
			isaOlona++;
		}
	}

//	printf("<p>%d</p>",isaOlona);
	int boole = 0;
	int j = debut + 10;

 	printf("<div>");
	printf("<table>");
	printf("<thead>");
			printf("<tr>");
			printf("<th>DATE</th>");
			printf("<th>TYPE DE SESSION</th>");
			printf("<th>LOGIN</th>");
			printf("</tr>");
	printf("</thead>");
 

	 for(int a=debut ,i=0;a<j;i++){
	 	if(a>isaOlona){
			break;
		}
		if(!strcmp((*(tabLine+i)).loginDeConnection , chaineARechercher)){
  			(*(tabLine+i)).temps = mamerinaDaty((*(tabLine+i)).temps);
			printf("<tr>");
				printf("<td>%d %s</td>\n",a,(*(tabLine+i)).temps);
				printf("<td>%s</td>\n",(*(tabLine+i)).fermeture_ouverture);
				printf("<td>%s</td>\n", (*(tabLine+i)).loginDeConnection);

			printf("</tr>");
		//	printf("<p>mitovy</p>");
			boole = 1;
			a++;
		} 
	}
	printf("</table>");
	printf("</div>"); 
	if(boole==0){
		printf("<p>On ne peut trouvez de login approprier</p>");
	}
	else{
		printf("<div>");
		for(int a=debut; a<j;a++){
			if(a>isaOlona){
				break;
			}
			if(a==j-1){
				printf("<a href=\"http://www.sandaniaina.com/cgi/rechercheVarlog.cgi?debut=%d~log=%s~%s\">%d</a>",j , misylogin , environnementVar , a);
			}

			else if(a==isa){
				printf("<a href=\"http://www.sandaniaina.com/cgi/rechercheVarlog.cgi?debut=1~log=%s~%s\">%d</a>",misylogin , environnementVar , a);
			}
			else if(a==1){
				printf("<a href=\"http://www.sandaniaina.com/cgi/rechercheVarlog.cgi?debut=%d~log=%s~%s\">%d&nbsp&nbsp&nbsp&nbsp&nbsp</a>",isa,misylogin , environnementVar , a);
			}
			else if(a==debut){
				printf("<a href=\"http://www.sandaniaina.com/cgi/rechercheVarlog.cgi?debut=%d~log=%s~%s\">%d&nbsp&nbsp&nbsp&nbsp&nbsp</a>",debut-10 , misylogin , environnementVar , a);
			}
			else{
				printf("<a href=\"#\">%d&nbsp&nbsp&nbsp&nbsp&nbsp</a>",a);
			}
			
		} 
	}
	printf("</body>");
	fclose(varlog);
	fclose(passwd);
	fclose(f_olona_connecter);
	
	free(chaine);
	free(tabUser);
	free(tabLine);
	free(phrase_file);
	free(misylogin);
	free(environnementVar);
	
	return 0;
}


/*-----------------------------------------------------------------------*/

void GetInfo(StructLine * tabLine ,FILE * file , User * tabUser , int isaPasswd){
	int isa=0;
	char * text = malloc(sizeof(char)*255);
	char * temp = malloc(sizeof(char)*255);
	for(isa = 0 ;fgets(text ,TAILLE_TEXT, file) != NULL;){
		if((strstr(text , "session closed")) || (strstr(text , "session opened") != NULL) || (strstr(text , "Accepted")) || (strstr(text, "Failed")) || (strstr(text , "logout")) ){
	
			
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

		//	printf("-->%s %s %s\n", (*(tabLine+isa)).temps ,(*(tabLine+isa)).fermeture_ouverture,(*(tabLine+isa)).loginDeConnection);
			isa++;
		}
	}
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


