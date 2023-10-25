#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double fonction(double x);
void fonction_css();
int main() {

	printf("Content-Type: text/html\n\n");
	char * mot = getenv("QUERY_STRING");

	printf("<html>");
	double a=0 , b=5 ,c,integrale=0, intervalle_kely;
    sscanf(mot , "a=%lf&b=%lf",&a,&b);
	//printf("<p>%f et %f</p>",a,b);
	c = a;
	if(a>b){
		printf("<h2>Erreur de saisie des bornes , <br> elles doivent être: borne1 < borne2</h2>");
	}
	printf("<head>");
	printf("<meta charset=\"utf-8\" />");
	fonction_css();
	printf("<title>Calcule d'intervalle en trapèze</title>");
	printf("</head>");
	printf("<body>");	
	intervalle_kely = (b-a)/10000;
	printf("<table>");
	for(int i=1;a<(b-intervalle_kely);i++){
		integrale += (((fonction(a)+fonction(a+intervalle_kely))*intervalle_kely)/2);
		a += intervalle_kely;
		printf("<tr><td>integrale num° %d</td><td class=\"nombre\">%f</td></tr>",i, integrale);
	}

	printf("<tr><td class=\"farany\" id=\"fin\">%f</td></tr>",integrale);

	printf("</table>");
	
	printf("<div class=\"mitsingevana\">");
	printf("<h2>La fonction x² ,avec la methode des trapeze</h2>");
	printf("<p> de %f à %f</p>", c,b);
	printf("<p class=\"farany\"> integrale calculer %f</p>",integrale);	
	printf("<a href=\"#fin\">Voir la fin de la page</a>");
	printf("<h2>Changer la valeur de l'intervalle ?</h2>");
	printf("<form>"
			"<input type=\"number\" placeholder=\"Borne 1\" required=\"\" name=\"a\">"
			"<input type=\"number\" placeholder=\"Borne 2\" required=\"\" name=\"b\">"
			"<input type=\"submit\" value=\"calculer\">"
			"</form>"
	);
	printf("</div>");

	printf("</body>");
	printf("</html>");
	return 0;
}


double fonction(double x){
	return x*x;
}

void fonction_css(){
	printf("<style>");
	printf("body{"
			"background-color: #F5F7F8;"
			"}"
	);
	printf(".mitsingevana{"
				"position: fixed;"
				"top: 10%%;"
				"left: 10%%;"
				"background-color: #45474B;"
				"width: 20%%;"
				"height: 500px;"
				"text-align: center;"
				"border-radius: 10px;"
				"color: #F5F7F8;"
			"}"
	);
	printf("a{text-decoration: none;color: #F4CE14;}");
	printf(".mitsingevana>p{"
				"width: 80%%;"
				"height: 50px;"
				"margin: 7px auto;"
				"padding-top: 5%%;"
			"}"
	);
	printf("input{outline: none;height: 50px;width: 30%%;font-size: 20px;font-weight: 800;text-align: center;}");

	printf("input[type=\"submit\"]{"
			"background-color: #495E57;"
			"color: #F5F7F8;"
			"}"
	);
	printf("table{"
			"padding: 10px;"
			"font-size: 17px;"
			"margin: 0 40%%;"
			"border: 1px solid black;"
			"background-color: #495E57;"
			"color: #F5F7F8;"
			"}"
	);
	printf("tr{margin: 0;padding: 0px}");
	printf("td{padding: 10px;border: 1px solid black;margin:0;}");
	printf(".farany{"
			"background-color: #F4CE14;"
			"color: #495E57;"
		"}"		
	);
	printf(".nombre{"
			"font-weight: 700;color:#F5F7F8 ;"
		"}"		
	);
	printf("</style>");
}
