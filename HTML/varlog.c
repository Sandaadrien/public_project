
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    printf("Context-Type: text/html\n\n");

	printf("<html>\n");
		printf("<head>\n");
			printf("<meta charset=\"utf-8\" >\n");
			printf("<title>VARLOG</title>\n");
			printf("<style>");
				printf("body{");
 				printf("background: -moz-linear-gradient(top left , #071952 , white)");
 				printf("}");
				printf("h1{");
				printf("color:black");
				printf("}");
				printf(".deco{");
				printf("background-color: rgba(147, 186, 199, 0.57);");
				printf("width: 500px;");
				printf("height: 300px;");
				printf("border-radius: 0 0 400px 0;");
				printf("border-right: 30px solid rgba(0, 0, 0, 0.40);");
				printf("border-bottom: 10px solid rgba(0, 0, 0, 0.40);");
				printf("text-align: center;");
				printf("padding-top: 50px;");
				printf("margin: 0;");
				printf("display: inline;");
				printf("position: fixed;");
				printf("z-index: 2000;");
				printf("}");
				printf("table{");
				printf("	margin-left: 400px;");
				printf("	border: 2px solid black;");
				printf("	border-spacing: 5px");
				printf("	display:inline;");
				printf("	position: relative;");
				printf("}");
				printf("tr{");
				printf("	border: 2px solid black;");
				printf("}");
				printf("td{");
				printf("	border: 2px solid black;");
				printf("}");
				printf(".midy{");
					printf("background-color: #35A29F;");
				printf("}");
				printf(".mivoha{");
					printf("background-color: #F2F7A1;");
				printf("}");
				printf("td:hover{");
				printf("	background-color: #FFC436;");
				printf("}");
			printf("</style>");
		printf("</head>\n");
		printf("<body>\n");
			printf("<table>\n");
	FILE * f=NULL;
	
	f = fopen("/var/log/auth.log" , "r");
	if(f==NULL){
		printf("Tsy nisokatra");
	}
	char * phrase = malloc(sizeof(char)*600);
	int nbLine = 0;

	while(!feof(f)){
                fgets(phrase , 600 , f);
                nbLine++;
    }

	rewind(f);
	int i;
	for(i=0; i<(nbLine-100); i++ ){
		fgets(phrase , 600 , f);
	}
	char * time = malloc(sizeof(char)*255);
	char * user = malloc(sizeof(char)*255);
	char * mot1 = malloc(sizeof(char)*255);
	char * mot2 = malloc(sizeof(char)*255);
	char * mot3 = malloc(sizeof(char)*255);
	char * mot4 = malloc(sizeof(char)*255);
	char * mot5 = malloc(sizeof(char)*255);
	char * mot6 = malloc(sizeof(char)*255);
	char * mot7 = malloc(sizeof(char)*255);
	char * ordi = malloc(sizeof(char)*255);
	
	printf("<div class=\"deco\">");
	printf("<h1>Les infos du /var/log/auth.log</h1>");
	printf("</div>");
	printf("<thead>");
	printf("<tr>");
	printf("<th>Time</th>");
	printf("<th>User</th>");
	printf("</tr");
	printf("</thead>");
	 for(int j=i; j<nbLine; j++){
		fgets(phrase , 600 , f);
		sscanf(phrase,"%[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] ",time , ordi ,mot1 , mot2 , mot3 , mot4 , mot5,mot6 , mot7);
	//	 printf("%s\n",phrase); 
		if(!strcmp("session",mot3)){
			if(!strcmp("closed",mot4)){
				printf("<tr>\n");
					printf("<td class=\"midy\">%s</td>\n",time);
					printf("<td class=\"midy\">%s</td>\n",mot4);
				/* 	printf("<td>%s</td>\n",mot5);
					printf("<td>%s</td>\n",mot6); */
					printf("<td class=\"midy\">%s</td>\n",mot7);
				printf("</tr>\n");
			}
			else if(!strcmp("opened",mot4)){
				printf("<tr>\n");
					printf("<td class=\"mivoha\">%s</td>\n",time);
					printf("<td class=\"mivoha\">%s</td>\n",mot4);
					/* printf("<td>%s</td>\n",mot5);
					printf("<td>%s</td>\n",mot6); */
					printf("<td class=\"mivoha\">%s</td>\n",mot7);
				printf("</tr>\n");
			}
			else{
				continue;
			}
		}
		
	}
	// printf("%s\n",user);
	//printf("%d",nbLine);	
	 
	printf("</table>\n");


	fclose(f);
	printf("</body>\n");
	printf("</html>\n");
    free(time);
    free(phrase);
    free(user);
	return 0;
}
