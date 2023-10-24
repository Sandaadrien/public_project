
#include <stdio.h>
#include <stdlib.h>
void fichier_css();
void miantso_switch(int number_erreur);
int main() {
    
    char * erreur_login = getenv("QUERY_STRING");
    int number_erreur = 0;
    printf("Content-Type: text/html\n\n");
    printf("<html>");
    printf("<head>");
    printf("<meta charset=\"utf-8\" />");
    printf("<title>FICHE D'INSCRIPTION</title>");
    fichier_css();
    printf("</head>");

    printf("<body>");
    sscanf(erreur_login , "erreur_login=%d",&number_erreur);
    printf("<div class=\"logo\"><img src=\"../INSCRIPTION/images/ubuntu.svg \" alt=\"logo ubuntu\" /></div>");
    printf("<div class=\"main\">");

        printf("<input type=\"checkbox\" id=\"check\" aria-hidden=\"true\">");

        printf("<form class=\"sign-up\" action=\"http://www.sandaniaina.com/cgi/inscription.cgi\" method=\"get\">");
        printf("<label for=\"check\" aria-hidden=\"true\">SIGN UP</label>");
        printf("<input type=\"text\" name=\"nom\" placeholder=\"entrez votre login\" required=\"\"/>");
        printf("<input type=\"password\" name=\"pass\" placeholder=\"entrez votre mot de passe\" required=\"\" />");
        printf("<input type=\"submit\" value=\"s'inscrire\" />");
        miantso_switch(number_erreur);
        printf("</form>");
            

        printf("<form class=\"sign-in\" action=\"http://www.sandaniaina.com/cgi/verification.cgi\" method=\"get\">");
        printf("<label for=\"check\" class=\"label-in\" aria-hidden=\"true\">SIGN IN</label>");
        printf("<input type=\"text\" name=\"nom\" placeholder=\"entez votre login\" required=\"\"/>");
        printf("<input type=\"password\" name=\"pass\" placeholder=\"entrez votre mot de passe\" required=\"\"/>");
        printf("<input type=\"submit\" value=\"se connecter\" />");
        miantso_switch(number_erreur);
        printf("</form>");

    printf("</div>");

    printf("</body>");
    
    printf("</html>");
    return 0;
}
void miantso_switch(int number_erreur){
        switch(number_erreur){
        case 1:
            printf("<p>Votre login est déja existant</p>");
            break;
        case 2:
            printf("<p>Votre login ou votre mot de passe est incorrecte</p>");
            break;
        case 3:
            printf("<p>Veuillez vous inscrire s'il vous plait</p>");
            break;
 	case 4:
	    printf("<p>Connecter vous maintenant mon amie</p>");
 	default:
            break;
    }
    
}
void fichier_css(){
printf("<style>");
    printf("body{background-color: #192655; width: 100%%; height: 100vh;overflow:hidden;}");
    printf(".main{");
        printf("max-width: 400px;height: 600px;box-shadow: 12px 12px 12px black;");
        printf("background-color:  #E1AA74;border-radius: 10px;border: none;");
        printf("margin: 10%% auto;overflow: hidden;");
    printf("}");

    printf("input[type=\"checkbox\"]{display: none;}");

    printf("form{");
        printf("display: flex;");
        printf("flex-direction: column;align-items: center;");
        printf("text-align: center;");
    printf("}");
    printf("label{");
    printf("font-size: 30px;font-weight: 1000;");
    printf("padding: 10%%;transition: 2s ease-in-out; ");
    printf("}");
    printf(".label-in{font-size: 20px; margin-bottom: 20px;color: white;}");
    printf("form > input{");
        printf("width: 80%%;");
        printf("padding: 15px 40px;margin: 10px;");
        printf("outline:none;background-color: #F3F0CA;");
        printf("border-radius: 10px;border: none;");
        printf("font-size: 15px;");
    printf("}");

    printf("input[type=\"submit\"]{");
    printf("margin-top: 20px;font-weight: bolder;font-size: 18px;");
    printf("}");
    printf(".sign-up>input[type=\"submit\"]{background-color: #3876BF;color: #F3F0CA;}");
    printf(".sign-in>input[type=\"submit\"]{background-color:#E1AA74}");
    printf(".sign-up{");
    printf("height: 80%%;background-color:  #E1AA74;justify-content: center;align-items: center;");
    printf("}");

    printf(".sign-in{");
    printf("background-color: #3876BF;height: 87%%;border-radius: 130px 90px 0 0;transition: 2s ease-in-out;");
    printf("}");

    printf("#check:checked ~ .sign-in{");
    printf("transform: translateY(-400px);transition: 2s ease-in-out;border-radius: 70px 150px 0 0;");
    printf("}");
    printf("#check:checked ~ .sign-up>label{transition: 2s ease-in-out;transform: translateY(-95px);font-size: 25px}");
    printf("#check:checked ~ .sign-in>.label-in{font-size: 30px;transition: 2s ease-in-out;}");

    printf("img{position: absolute;z-index: -1;width: 50%%;}");
printf("</style>");
}
