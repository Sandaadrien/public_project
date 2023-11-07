


#include <stdio.h>
#include <stdlib.h>

int main() {

    char * phrase_recue = getenv("QUERY_STRING");
    char * nom_virt_host = malloc(sizeof(char)*255);
    char * commande = malloc(sizeof(char)*255);

    printf("Content-Type: text/html\n\n");

    printf("<html>");
    printf("<head>");
    printf("</head>");
    printf("<body>");

    sscanf(phrase_recue , "site=%s", nom_virt_host);

    sprintf(commande , "cd /etc/apache2/sites-enabled && rm -rf %s", nom_virt_host);

    system(commande);

    printf("<p>Desactivation fait</p>");
    printf("<meta http-equiv=\"refresh\" content=\"0.5;url=http://www.adrien.com/prog/main.cgi/\"");

    printf("</body>");
    printf("</html>");

    free(nom_virt_host);
    nom_virt_host = NULL;

    return 0;
}