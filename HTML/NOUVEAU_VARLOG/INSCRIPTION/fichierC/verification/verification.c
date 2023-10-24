
#include "../../fichierH/verification/verification.h"

void verification(FILE * file , char * phrase_recue ){
    char * phrase_file = malloc(sizeof(char)*255);
    char * login_file = malloc(sizeof(char)*100);
    char * pass_file = malloc(sizeof(char)*255);

    char * login_recue = malloc(sizeof(char)*100);
    char * pass_recue = malloc(sizeof(char)*255);

    sscanf(phrase_recue , "nom=%[^&]&pass=%s",login_recue, pass_recue );

    int boll=0;
    while(fgets(phrase_file,255 , file)!= NULL){
        sscanf(phrase_file , "nom=%[^&]&pass=%s",login_file, pass_file );
        if((strcmp(login_file ,login_recue)==0) && (strcmp(pass_file , pass_recue)==0)){
            boll = 1;
            break;
        }
        else if((strcmp(login_file , login_recue)==0) || (strcmp(pass_file , pass_recue)==0)){
            boll = 2;
        }
    }
    printf("<div id=\"animation\">&nbsp</div>");
    if(boll==1){
        printf("<p class=\"Reussi\">Sceance de login reussie</p>");
        printf("<p>redirectionement en cours</p>");
        FILE * f_user_connecter = fopen("../DONNEE/olona_connecter", "a+");
        fprintf(f_user_connecter , "%s\n" ,phrase_recue);
        fclose(f_user_connecter);
        printf("<meta http-equiv=\"refresh\" content=\"5;url=http://www.sandaniaina.com/cgi/main.cgi?%s\"",phrase_recue);
    }
    else if(boll == 2){
        printf("<p class=\"Erreur\">Login ou mot de passe incorrecte</p>");
        printf("<meta http-equiv=\"refresh\" content=\"5;url=http://www.sandaniaina.com/cgi/fiche_inscription.cgi?erreur_login=2\"");
    }
    else{
        printf("<p class=\"Erreur\">Login Non Reconnue</p>");
        printf("<p>Vous n'etes pas dans nos registre</p>");
        printf("<meta http-equiv=\"refresh\" content=\"5;url=http://www.sandaniaina.com/cgi/fiche_inscription.cgi?erreur_login=3\"");
    }
    free(phrase_file);
    free(login_file);
    free(pass_file);
    free(login_recue);
    free(pass_recue);

}
void function_css(){
    printf("<style>");
    printf("body{background-color: black;font-size: 40px;color: white;text-align:center;padding-top:5%%;}");

    printf(".Erreur{");
    printf("font-size: 200px;font-weight: 50px");
    printf("}");

    printf(".Reussi{color: green;font-size: 80px;font-weight: 1000;transition: 2s ease;");

    printf("}");

    printf("#animation{position: absolute; width: 400px; height: 400px; z-index: 12;background-color: transparent;");
    printf("border: 10px solid transparent;");
    printf("border-top: 10px solid white;");
    printf("border-left: 10px solid white;");
    printf("border-radius: 50%%;");
    printf("margin: 10%% 38%%;animation: spin 2s linear infinite;");
    printf("}");
    printf("@keyframes spin{");
    printf("0%%{transform: rotate(0deg)}");
    printf("100%%{transform: rotate(360deg)}");

    printf("</style>");
}
  
