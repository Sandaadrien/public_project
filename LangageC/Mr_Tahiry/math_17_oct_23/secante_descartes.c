
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define eps 0.0000001

double fonction(double x);
double mitadyX2(double a , double b);
void fonction_css();

int main() {

	printf("Content-Type: text/html\n\n");
	char * mot = getenv("QUERY_STRING");

	printf("<html>");

	printf("<head>");
	printf("<title>Methodes de descartes</title>");
	printf("<meta charset=\"utf-8\" >");
	fonction_css();
	printf("</head>");

	printf("<body>");
	double a=3.00 , b=4.00 ,x;

	sscanf(mot , "a=%lf&b=%lf",&a,&b);

	if(a>b){
		printf("<h2>Erreur de saisie des bornes , <br> elles doivent être: borne1 < borne2</h2>");
	}
	else if((fonction(a)*fonction(b))>0){
		printf("<h2>Pas de solutions pour que sin(x) = 0 , <br />sur %lf et %lf</h2>",a,b);
	}
	else{

	printf("<div class=\"main\">");
	printf("<h1>METHODE DES SECANTES</h1>");
	printf("<h2>La fonction sin(x)=0<br>sur [%f a %f]</h2>",a,b);

	printf("<table>");

	printf("<tr>");
	printf("<td>Borne a</td>");
	printf("<td>Borne b</td>");
	printf("<td>La solution</td>");
	printf("<tr>");
	printf("<a href=\"#fin\">Allez a la fin de la page</a>");

	while(fabs(a-b)>=eps){
		
		x = mitadyX2(a,b);
	
		printf("<tr>");
		printf("<td>%f</td><td>%f</td><td class=\"farany\">%f</td>\n ",a,b ,x);
		printf("</tr>");

		if((fonction(x)*fonction(b))<=0){
			a = x;
		}
		else if((fonction(x)*fonction(b))){
			b = x;
		}

	}

	printf("<tr><td></td><td></td><td class=\"end\" id=\"fin\">%f</td></tr>",x);

	printf("</table>");
	printf("<form>"
			"<input type=\"number\" placeholder=\"Borne 1\" required=\"\" name=\"a\">"
			"<input type=\"number\" placeholder=\"Borne 2\" required=\"\" name=\"b\">"
			"<input type=\"submit\" value=\"calculer\">"
			"</form>"
	);
	printf("</div>");
	}
	printf("</body>");
	printf("</html>");

	return 0;
}

double fonction(double x){
	return sin(x);
}

double mitadyX2(double a , double b){

	double num = fonction(b)*(b-a);
	double deno = fonction(a) - fonction(b);
	
	return ( b + (num / deno));
}
void fonction_css(){
	printf("<style>");
	printf("body{background-color: #192655;}");

	printf(".main{"
			"background-color: #E1AA74;"
			"width: 500px;"
			"margin: 10px auto;"
			"text-align: center;"
			"border-radius: 10px;"
			"display: flex; flex-direction: column;justify-content: space-around; align-items: center;"
			"}"
	);
	printf("table{"
			"padding: 30px;"
			"font-size: 17px;"
			"margin: 20px 40%%;"
			"border: 1px solid black;"
			"background-color: #495E57;"
			"color: #F5F7F8;"
			"}"
	);
	printf("tr{margin: 0;padding: 0px}");
	printf("td{padding: 10px;margin:0;}");
	printf("input{outline: none;height: 50px;width: 30%%;font-size: 20px;font-weight: 800;text-align: center;}");
	printf(".farany{"
			"background-color: #F4CE14;"
			"color: #495E57;"
		"}"		
	);
	printf(".end{"
			"background-color: green;"
			"color: white;"
		"}"		
	);
	printf("</style>");
}