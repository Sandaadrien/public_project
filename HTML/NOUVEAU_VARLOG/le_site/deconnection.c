
#include "./necessaire.h"


void mamindra_donner(FILE * f_olona_connecter, FILE * f_temp, FILE * f_a_copier , char * line_fichier ,char * phrase_recue );

int main(){
    
    char * phrase_recue = getenv("QUERY_STRING");

    printf("Content-Type: text/html\n\n");
    
    printf("<html>");
    printf("<head>");
    printf("<title>Deconnection</title>");
    printf("</head>");
    printf("<body>");
    
    printf("<h2>En cours de deconnection</h2>");
    FILE * f_olona_connecter = NULL;
    f_olona_connecter = fopen("../DONNEE/olona_connecter" , "r+");
    char * line_fichier = malloc(sizeof(char)*255);
    
    FILE * f_temp = fopen("../DONNEE/tmp" , "w");
    FILE * f_a_copier = fopen("../DONNEE/a_copier" , "w");

    mamindra_donner(f_olona_connecter,f_temp,f_a_copier ,line_fichier ,phrase_recue );

    remove("../DONNEE/olona_connecter");
    rename("../DONNEE/a_copier","../DONNEE/olona_connecter");

    printf("<meta http-equiv=\"refresh\" content=\"5;url=http://www.sandaniaina.com/cgi/fiche_inscription.cgi\"");

    printf("</body>");
    printf("</html>");
    

    free(line_fichier);
    fclose(f_olona_connecter);
    fclose(f_temp);
    fclose(f_a_copier);

    return 0;
}

void mamindra_donner(FILE * f_olona_connecter, FILE * f_temp, FILE * f_a_copier , char * line_fichier ,char * phrase_recue ){
    while(!feof(f_olona_connecter)){
        fgets(line_fichier , 255 , f_olona_connecter);
        line_fichier = manala_anti_shash(line_fichier);

         if((strcmp(line_fichier , phrase_recue))==0)
            fprintf(f_temp,"%s\n",line_fichier);
        
        else
            fprintf(f_a_copier, "%s\n" , line_fichier);
        
    }

}