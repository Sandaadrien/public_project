#include <stdio.h>
#include <stdlib.h>

double fonction(double x);
void fonction_css();

int main() {

	printf("Content-Type: text/html\n\n");
	char * mot = getenv("QUERY_STRING");

	printf("<html>");

	printf("<head>");
	printf("<meta charset=\"utf-8\"/>");
	printf("<title>Calcule integrale en simpson</title>");
	fonction_css();
	printf("</head>");
	double a=0 , b=5 , integrale=0 , intervalle_kely;
    
	sscanf(mot , "a=%lf&b=%lf",&a,&b);

	if(a>b){
		printf("<h2>Erreur de saisie des bornes , <br> elles doivent être: borne1 < borne2</h2>");
	}

	else{

	int n = 10000;
	intervalle_kely = (b-a)/n;

	integrale = fonction(a) + fonction(b);
	double x;

	printf("<body>");
	for(int i=1;i<n;i++){
		x = a+ (i*intervalle_kely);	
		if(i%2 !=0){
			integrale += 4 * fonction(x);
		}
		else{
			integrale += 2 * fonction(x);		
		}
	}
	integrale *= intervalle_kely / 3;
	printf("<div class=\"main\">");
	printf("<h2>La fonction x*x en simpson</h2>");

	printf("<p>Avec les bornes <br />%lf et %lf</p>",a ,b);
	printf("<p class=\"valiny\">%f</p>",integrale);
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
	return x*x;
}

void fonction_css(){

	printf("<style>");
	printf("body{background-color: #192655;}");
	printf(".main{"
			"background-color: #E1AA74;"
			"width: 500px;"
			"height: 400px;"
			"margin: 10px auto;"
			"text-align: center;"
			"border-radius: 10px;"
			"display: flex; flex-direction: column;justify-content: space-around; align-items: center;"
			"}"
	);
	printf(".valiny{"
			"background-color: #3876BF;"
			"width: 80%%;"
			"height: 50px;"
			"margin: 7px auto;"
			"padding-top: 5%%;"

			"}"
	);
	printf("input{outline: none;height: 50px;width: 30%%;font-size: 20px;font-weight: 800;text-align: center;}");

	printf("</style>");

}