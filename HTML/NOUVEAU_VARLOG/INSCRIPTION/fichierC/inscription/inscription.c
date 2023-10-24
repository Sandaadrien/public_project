#include "../../fichierH/inscription/inscription.h"


void inscription( char * motRecue , char * mot_comparer , char * login_fichier , char * pass_fichier , FILE * fdonnee , char * login , char * pass , int boole){
                sscanf(motRecue ,"nom=%[^&]&pass=%s" ,login , pass);
                printf("<div id=\"animation\">&nbsp</div>");
                while((fgets(mot_comparer, 100 , fdonnee) != NULL)){
                        sscanf(mot_comparer, "nom=%[^&]&pass=%s", login_fichier, pass_fichier);
                        if(strcmp(login_fichier , login) == 0){
                                printf("<p id=\"erreur\">login %s est déja existant</p>",login);
                                boole = 0;
                                printf("<meta http-equiv=\"refresh\" content=\"5;url=http://www.sandaniaina.com/cgi/fiche_inscription.cgi?erreur_login=1\"");
                                break;
                        }
                }
                if(boole == 1){
                        fprintf(fdonnee , "%s\n",motRecue);
                        printf("<p>INSCRIPTION RÉUSSIE</p>");
                        printf("<p>Redirection en cours</p>");
                        printf("<meta http-equiv=\"refresh\" content=\"5;url=http://www.sandaniaina.com/cgi/fiche_inscription.cgi?erreur_login=4\"");
                }
}

void function_css(){
        printf("<style>");
        printf("body{text-align: center;font-size: 100px;font-weight: 800;color: green;}");

        printf("#erreur{color: red;}");

        printf("#animation{position: absolute; width: 400px; height: 400px; z-index: 12;background-color: transparent;");
    printf("border: 10px solid transparent;");
    printf("border-top: 10px solid black;");
    printf("border-left: 10px solid black;");
    printf("border-radius: 50%%;");
    printf("margin: 10%% 38%%;animation: spin 2s linear infinite;");
    printf("}");
    printf("@keyframes spin{");
    printf("0%%{transform: rotate(0deg)}");
    printf("100%%{transform: rotate(360deg)}");
        printf("</style>");
}


