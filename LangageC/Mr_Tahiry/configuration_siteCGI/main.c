#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>


void fonction_css();

char ** tab_pers(FILE * f , char ** tab_pers , int nb_case , char * nom_fichier , char * mode_ouverture);
void ecrire_virt_host(char * chemin_fichier , char * fichier_stock );
int compte_ligne_fichier(FILE * f , char * nom_fichier , char * mode_ouverture);

int main() {

    printf("Content-Type: text/html\n\n");

    printf("<html>");
    printf("<head>");
	printf("<title>accesslog</title>");
	fonction_css();
    printf("</head>");
    printf("<body>");
	char * phrase_recue = getenv("QUERY_STRING");
	
	FILE * f_liste_available = NULL , * f_liste_enable = NULL;
	char ** tab_virt_host_avai = NULL , ** tab_virt_host_en = NULL ;
	char * copy = malloc(sizeof(char)*1000);
	int nb_site_available = 0 , nb_site_enable = 0;
	
	ecrire_virt_host("/etc/apache2/sites-available/" , "liste_site_available");
	ecrire_virt_host("/etc/apache2/sites-enabled/" , "liste_site_enabled");
	
	nb_site_available = compte_ligne_fichier( f_liste_available, "liste_site_available","r");
	nb_site_enable = compte_ligne_fichier( f_liste_enable , "liste_site_enabled", "r");
	
	tab_virt_host_avai = tab_pers(f_liste_available ,tab_virt_host_avai, nb_site_available , "liste_site_available" , "r");
	tab_virt_host_en  = tab_pers(f_liste_enable , tab_virt_host_en , nb_site_enable , "liste_site_enabled" , "r");
	
	int * tab_frq = malloc(sizeof(int)*nb_site_available);

	for(int i=0;i<nb_site_available;i++){
		*(tab_frq + i) = 0;
 		for(int j=0;j<nb_site_enable;j++){
			if(strcmp(*(tab_virt_host_avai+i),*(tab_virt_host_en + j)) == 0){
				*(tab_frq+i) = 1;
				break;
			}
		}
	}

	printf("<div class=\"tous\" >");
	printf("<h2>Liste de tout les sites</h2>");
	for(int i=0;i<nb_site_available;i++){
		printf("<p>%s</p>",*(tab_virt_host_avai+i));
	}
	printf("</div>");
	printf("<div class=\"actives\" />");
	printf("<h2>Liste des sites actives</h2>");
	for(int i=0;i<nb_site_enable;i++){
		printf("<p>%s <a href=\"http://www.adrien.com/prog/desactiver.cgi?site=%s\">Voulez vous desactiver ?</a></p>",*(tab_virt_host_en+i),*(tab_virt_host_en+i));
	}
	printf("</div>");
	printf("<a href=\"#creer\" class=\"viens\">Revenir en haut</a>");
	printf("<div class=\"desactives\">");
	printf("<h2>Les sites desactivees</h2>");
	for(int i=0;i<nb_site_available;i++){
 		if(*(tab_frq+i) == 0){
			printf("<p>%s<a href=\"http://www.adrien.com/prog/activation.cgi?site=%s\">Voulez vous activer ?</a></p>",*(tab_virt_host_avai + i),*(tab_virt_host_avai + i));		
		} 
	}
	printf("</div>");
	if(phrase_recue != NULL){
		char * serverName = malloc(sizeof(char)*255);
		char * serverAdmin = malloc(sizeof(char)*255);
		char * documentRoot = malloc(sizeof(char)*255);
		char * virtualHost = malloc(sizeof(char)*255);
		char * ip = malloc(sizeof(char)*255);
		char * commande = malloc(sizeof(char)*255);

		gchar * url_traiter = g_uri_unescape_string(phrase_recue , NULL);
		sscanf(url_traiter ,"virtualHost=%[^&]&serverName=%[^&]&serverAdmin=%[^&]&documentRoot=%[^&]&ip=%s",virtualHost,serverName,serverAdmin,documentRoot,ip);
		sprintf(commande , "/etc/apache2/sites-available/%s.conf" , virtualHost);

		FILE * tmp = fopen(commande , "w");

		fprintf(tmp , "<VirtualHost %s:80>\n"
							"ServerName %s\n"
							"ServerAdmin %s\n"
							"DocumentRoot %s\n"
							"ErrorLog ${APACHE_LOG_DIR}/error.log\n"
							"CustomLog ${APACHE_LOG_DIR}/access.log combined\n"
						"</VirtualHost>\n"
						,ip,serverName,serverAdmin,documentRoot
		
		);
		FILE * hosts = fopen("/etc/hosts" , "a+");
		strcpy(copy , serverName);
		if(strstr(copy , "www.") != NULL){
		//	printf("<h1>%s %s %s %s et %s</h1>",virtualHost,documentRoot,serverAdmin,ip , serverName);
			fprintf(hosts ,"%s %s\n",ip , serverName);
		}


		free(serverName);
		free(serverAdmin);
		free(documentRoot);
		free(virtualHost);
		free(ip);
		fclose(tmp);
		fclose(hosts);
	}
	printf("<div class=\"creer\" id=\"creer\">");
	printf("<h2>Creer un virtual host</h2>");
	printf("<form action=\"http://www.adrien.com/prog/test.cgi\" method=\"get\">");
	printf("<label>Nom du virtual Host</label>");
	printf("<input type=\"text\" placeholder=\"Nom du virtual Host\" required=\"\" name=\"virtualHost\" />");
	printf("<label>Server Name</label>");
	printf("<input type=\"text\" placeholder=\"Server Name\" required=\"\" name=\"serverName\"/>");
	printf("<label>Server Admin</label>");
	printf("<input type=\"text\" placeholder=\"Server Admin\" required=\"\" name=\"serverAdmin\"/>");
	printf("<label>Document Root</label>");
	printf("<input type=\"text\" placeholder=\"Document Root\" required=\"\" name=\"documentRoot\"/>");
	printf("<label>Addresse IP</label>");
	printf("<input type=\"text\" placeholder=\"Addresse IP\" required=\"\" name=\"ip\"/>");
	printf("<input type=\"submit\" value=\"Creer\"/>");
	printf("</form>");
	
	printf("</div>");
	char * ip = malloc(sizeof(char)*255);
	char * date = malloc(sizeof(char)*255);
	char*  protocole = malloc(sizeof(char)*255);
	int nb1 , nb2;
	char* lien = malloc(sizeof(char)*255);
	char *nav = malloc(sizeof(char)*255);
	char *heure = malloc(sizeof(char)*255);

	FILE * access_log = fopen("/var/log/apache2/access.log" , "r");
	printf("<table>");
	printf("<thead>");
	printf("<tr>");
	printf("<th>IP</th>");
	printf("<th>Date</th>");
	printf("<th>Hours</th>");
	printf("<th>Protocole</th>");
	printf("<th>code</th>");
	printf("<th>erreur</th>");
	printf("<th>lien</th>");
	printf("<th>navigateur web</th>");
	printf("<th>systeme</th>");
	printf("</tr>");

	printf("</thead>");

	while(fgets(copy , 1000 , access_log) != NULL){
		sscanf(copy , "%[^ ] - - [%[^]]] \"%[^\"]\" %d %d \"%[^\"]\" \"%[^\"]\"", 
			ip , date , protocole , &nb1, &nb2, lien , nav
		);
		strtok(date , ":");
		strtok(heure = (date + strlen(date) + 1) , " ");
		g_uri_unescape_string(protocole , NULL);
		g_uri_unescape_string(lien , NULL);
//	Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Safari/537.36
		char moz[255];
		char distro[255];

		strcpy(copy , nav);
		sscanf(copy , "%s (%[^)]) %[^\n]",moz,distro,nav);
		printf("<tr>"
				"<td>%s</td>"
				"<td>%s</td>"
				"<td>%s</td>"
				"<td>%s</td>"
				"<td>%d</td>"
				"<td>%d</td>"
				"<td>%s</td>"
				"<td>%s</td>"
				"<td>%s</td>"
				"</tr>"
		, ip, date, heure, protocole , nb1 , nb2 , lien ,nav, distro);
	}
	printf("</table>");	

    printf("</body>");
    printf("</html>");

	free(copy);
	free(ip);
	free(date);
	free(protocole);
	free(lien);
	free(nav);
	free(heure);
	fclose(access_log);
	return 0;
}

char ** tab_pers(FILE * f , char ** tab_pers , int nb_case , char * nom_fichier , char * mode_ouverture){
	tab_pers = malloc(sizeof(char*)*nb_case);
	
	for(int i=0;i<nb_case;i++){
		*(tab_pers+i) = malloc(sizeof(char)*255);
	}
	f = fopen(nom_fichier , mode_ouverture);
	
	for(int i=0;fgets(*(tab_pers+i),255 , f) != NULL;i++){}
	
	fclose(f);
	return tab_pers;
}

int compte_ligne_fichier(FILE * f , char * nom_fichier , char * mode_ouverture){
	int nb_ligne = 0;
	char * phrase = malloc(sizeof(char)*255);
	f = fopen(nom_fichier , mode_ouverture);
	while(fgets(phrase , 255 , f) != NULL){
		nb_ligne ++;
	}
	free(phrase);
	fclose(f);
	return nb_ligne;
}

void ecrire_virt_host(char * chemin_fichier , char * fichier_stock ){
	char * commande = NULL;
	commande = malloc(sizeof(char)*255);
	if(commande == NULL){
		printf("Erreur lors de l'allocation de commande");
		exit(EXIT_FAILURE);
	}
	sprintf(commande , "ls %s > %s" , chemin_fichier , fichier_stock);
	
	system(commande);
	
	free(commande);
}


void fonction_css(){

	printf("<style>");
	printf("body{background-color: #27005D;color: #E4F1FF;}");
	printf(".desactives{"
			"background-color :#9400FF;"
			"position: fixed;"
			"right: 0;"
			"width: 30%%;"
			"bottom: 30px;"
			"text-align: center;"
			"border-radius: 10px;"
			"box-shadow: 2px 2px 10px #AED2FF;"
			"color: black;"
			"}"
	);

 	printf(".actives{"
			"background-color :#9400FF ;"
			"position: fixed;"
			"right: 30px;"
			"width: 30%%;"
			"top: 30px;"
			"text-align: center;"
			"border-radius: 10px;"
			"box-shadow: 2px 2px 10px #AED2FF;"
			"color: black;"
			"}"
	);
	printf(".tous{"
			"width: 40%%;"
			"margin: 30px;"
			"background-color:#9400FF;"
			"box-shadow: 2px 2px 10px #AED2FF;"
			"text-align: center;"
			"padding: 10px;"
			"color: black;"
			"}"
	);
	printf(".creer{"
			"background-color:#9400FF;"
			"display: flex;"
			"flex-direction: column;"
			"align-items: center;"
			"margin: 5%%;"
			"width: 500px;"
			"color: black;"
			"padding: 30px;"
			"border-radius: 10px;"
			"}"
	);
	printf("form{"
			"background-color:#9400FF;"
			"display: flex;"
			"flex-direction: column;"
			"align-items: center;"
			"width: 100%%;"
			"}"
	);
	printf("table{"			
			"background-color:#9400FF;"
			"width: 50%%;"
			"font-size: 14px;"
			"color:black;"
			"}"
	);
	printf("input{height: 50px;width: 80%%;border-radius: 10px;font-size: 20px;font-weight: 700;margin: 10px;padding-left: 20px;outline: none;}");
	printf(".viens{position: fixed;bottom: 10px;left: 10px;color: white;}");
	printf("</style>");
}