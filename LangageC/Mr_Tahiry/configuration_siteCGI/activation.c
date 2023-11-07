

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

    sprintf(commande , "cd /etc/apache2/sites-enabled && a2ensite %s", nom_virt_host);

    printf("<p>%s</p>",nom_virt_host);
    system(commande);
    system("sudo systemctl reload apache2");
    system("service apache2 reload");
 
    printf("<p>Activation fait</p>");
    printf("<meta http-equiv=\"refresh\" content=\"4;url=http://www.adrien.com/prog/main.cgi/\" />");

    printf("</body>");
    printf("</html>");

    free(nom_virt_host);
    nom_virt_host = NULL;

    return 0;
}