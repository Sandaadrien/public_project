
#include "fichierH/verification/verification.h"


int main() {
    char * phrase_recue = getenv("QUERY_STRING");

    FILE * fichier = NULL;
    fichier = fopen("../DONNEE/login" , "r");
    printf("Context-Type: text/html\n\n");

    printf("<html>");
    
    printf("<head>");
    printf("<title>Verification d'information</title>");
    function_css();
    printf("</head>");
    
    printf("<body>");
    if(fichier == NULL){
        printf("<p>Tsy nisokatra ny fichier</p>");
    }
    else{
        verification(fichier , phrase_recue);
    }
    printf("</body>");
    
    printf("</html>");
    fclose(fichier);
    return 0;
}
