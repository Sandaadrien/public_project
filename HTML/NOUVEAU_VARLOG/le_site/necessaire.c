
#include "./necessaire.h"

char * mamerinaDaty(char* date){
	
    int * tabDate = malloc(sizeof(int)*3);
	char * date2 = malloc(sizeof(char)*255);
	char * tmpDate = malloc(sizeof(char)*255);

	strcpy(tmpDate , date);

	sscanf(strtok(date , "-") , "%d" , (tabDate));
	sscanf(strtok(NULL , "-") , "%d" , (tabDate+1));
	sscanf(strtok(NULL , "T") , "%d" , (tabDate+2));

//	*(tabDate+2) = 8;
//	*(tabDate) = 2022;
//	*(tabDate+1) = 6;
	unsigned njours = (*(tabDate) -1) * 365;
	if(*tabDate > 1582){
		njours += ((*tabDate-1) / 4);
		njours -= ((*tabDate-1) / 100);
		njours += 2;
	}
	else{
		njours +=((*tabDate-1)/4);
	}
	njours += (*(tabDate+1) -1 ) * 31;
	switch(*(tabDate+1)){
		
		case 12:
			--njours;
		case 11:
		case 10:
			--njours;
		case 9:
		case 8:
		case 7:
			--njours;
		case 6:
		case 5:
			--njours;
		case 4:
		case 3:
			if(*tabDate> 1582){
				if(*tabDate%4 == 0 && (*tabDate%100 != 0 || *tabDate%400 == 0))
					njours -=2;
				else
					njours -=3;
			}
			else {
				if(*tabDate%4 == 0)
					njours -= 2;
				else
					njours -= 3;
			}
			break;
		
	}

	njours += (*(tabDate+2) -1);
//	printf("%d\n",njours%7);
	char tabMois[12][50] = {"janoary" ,"febroary", "martsa" , "aprily", "may","jona","jolay","Aogositra","septembra","oktobra","novambra","desambra"};
	switch(njours%7){
		case 6 :{
			sprintf(date2 , "%s %d %s %d\n","Alarobia" ,*(tabDate+2),tabMois[*(tabDate+1) -1], *(tabDate));
			break;
		}
		case 5 :{
			sprintf(date2 , "%s %d %s %d\n","Talata" ,*(tabDate+2),tabMois[*(tabDate+1) -1] , *(tabDate));
			break;
		}
		case 4 :{
			sprintf(date2 , "%s %d %s %d\n","Alatsinainy",*(tabDate+2) ,tabMois[*(tabDate+1) -1] , *(tabDate));
			break;
		}
		case 3 :{
			sprintf(date2 , "%s %d %s %d\n","Alahady",*(tabDate+2) ,tabMois[*(tabDate+1) -1], *(tabDate));
			break;
		}
		case 2:{
			sprintf(date2 , "%s %d %s %d\n","Sabotsy" ,*(tabDate+2),tabMois[*(tabDate+1) -1] , *(tabDate));
			break;
		}
		case 1:{
			sprintf(date2 , "%s %d %s %d\n","Zoma" ,*(tabDate+2),tabMois[*(tabDate+1) -1], *(tabDate));
			break;
		}
		case 0:{
			sprintf(date2 , "%s %d %s %d\n","Alakamisy" ,*(tabDate+2),tabMois[*(tabDate+1) -1], *(tabDate));
			break;
		}
	}
	char * heure = malloc(sizeof(char)*255);
	char * tmp = malloc(sizeof(char)*255);
	
	tmpDate = strchr(tmpDate , 'T');
	sscanf(tmpDate , "T%[^.].%s",heure, tmp);
	sprintf(date2 , "%s @ %s\n",date2 , heure);

	return date2;
}


int manamarina_identite(char * phrase_recue, char * phrase_file, FILE * f_olona_connecter){

    int boolean = 0;
	while(fgets(phrase_file, 255 , f_olona_connecter) != NULL ){
		
		phrase_file = manala_anti_shash(phrase_file);
		
		if(!strcmp(phrase_file, phrase_recue)){
			boolean = 1;
		}
		
	}
    return boolean;
}

char * manala_anti_shash(char * mot){

    char * mot_retour = malloc(sizeof(char)*255);
    for(int i=0; *(mot+i) != '\n'; i++){
        *(mot_retour+i) = *(mot+i);
    }
    strcpy(mot , mot_retour);
    return mot;
}

char * manamboatraChaine(char * pChaine , int nbCar){
	pChaine = malloc(sizeof(char)*nbCar);
	
	if(pChaine == NULL){
		printf("Tsy mety amboarina ny chaine de caractère\n");
		exit(EXIT_FAILURE);
	}
	return pChaine;
}

FILE * manokatraFichier(FILE * file , char * chemin_fichier , char * mode){
	file = fopen( chemin_fichier, mode);
	if(file == NULL){
		printf("Tsy nisokatra ny fichier\n");
		exit(EXIT_FAILURE);
	}
	return file;
}

void fonction_css(){
	printf("<style>");
	printf(".conteneur1-image{"
			"border-radius: 50%%;"
			"position: absolute;width: 40%%;right: 10%%;top: 10%%;height: 90%%;"
 			"overflow: hidden;"
			"}"

	);
	printf(".conteneur2-image{"
			"display:flex;"
			"animation: conteneur2-image 25s infinite ease-in-out;"
			"}"
	);
	printf(".logo{width: 80%%;margin: 10%%;}");
	printf("@keyframes conteneur2-image{"
			"0%%, 20%%{transform: translateX(0);}"
			"25%%, 45%%{transform: translateX(-100%%);}"
			"50%%, 70%%{transform: translateX(-200%%);}"
			"75%%, 95%%{transform: translateX(-300%%);}"
			"100%%{transform: translateX(-400%%);}"
			"}"
	);
	printf(".navbar{"
				"background-color: transparent;"
				"display: flex; flex-direction: column;justify-content: space-between; align-items: center;"
				"height: 10%%;"
			"}"
	);
	
	printf(".debut{"
			"width: 500px;height: 100%%;"
			"display: flex; justify-content: center;align-items: center;"
			"}"
	);
	printf(".debut>ul{height: 100%%;}");
	printf(".debut>ul>li{margin-right: 60px; height: 100%%;font-size: 20px;position: relative}");
	printf("a{display: flex;align-items: center;text-decoration: none; color: black;height: 100%%;}");
	
	printf(".debut>ul>li a:after{"
			"position: absolute;left:0;bottom: -1px;"
			"content: \"\";"
			"width: 0; background-color: black; height:4px;"
			"transition: 0.5s ease-in-out;"
			"}"
	);
	printf(".debut>ul>li a:hover:after{"
			"width: 100%%;"
			"}"
	);
	
	printf(".lien{"
			"list-style-type: none;"
			"display: flex;"
			"justify-content:space-between;"
			"width: 80%%;"
			"text-align: center;"
			"margin: auto 10%%;"
			"}"
	);


	printf(".ul-interne{"
			"display: flex;"
			"list-style-type: none;"
			"justify-content: space-around;"
			"}"
	);

	printf(".farany{padding-top: 15px;}");
	printf("input[type=\"submit\"]{width: 200px;height: 40px;font-size: 16px;}");
	printf("input[type=\"text\"]{"
			"height: 40px;"
			"width: 400px;"
			"padding: 10px 30px;"
			"font-size: 15px;"
			"font-weight: 600;"
			"}"
	);

	printf("hr{width: 90%%;}");

	printf(".deconnection{"
			"width: 40px;"
			"}"
	);
	printf(".div-connection{position: absolute; width: 400px; height : 100px;bottom: 2%%;left: 2%%;}");
	printf(".div-connection::after{"
			"position: absolute;"
			"content: \"\";"
			"background-color: red;"
			"transform: rotate(44deg);"
			"bottom:80px;left: 3.5%%;width: 50px; height: 50px; "
			"z-index: 4;"
			"display: none;"
			"}"
	);
	
	printf(".div-connection::before{"
			"position: absolute;"
			"content: \"\";"
			"background-color: red;"
			"transform: rotate(44deg);"
			"bottom:80px;left: 3.5%%;width: 50px; height: 50px; "
			"display: none;"
			"z-index: 4;"
			"}"
	);

	printf(".connection{"
			"width: 70px;height:70px;"
			"background-color: yellow;"
			"bottom: 3%%;"
			"left: 3%%;"
			"border-radius: 50%%;"
			"position: absolute;"
			"box-shadow: 0 0 10px black;"
			"}"
	);
	printf(".div-log{"
			"position: absolute;"
			"width: 300px;height: 100px;"
			"font-size: 20px;"
			"text-align: center;"
			"padding: 30px 10px;"
			"background-color: red;"
			"border-radius: 10px;"
			"bottom:100px;left: -10px;"
			"box-shadow: 0 0 5px black;"
			"display: none;"
			"}"
	);
	
	printf("div.div-connection:hover .div-log{"
			"cursor: pointer;"
			"display: flex;"
			"}"
	);
	printf("div.div-connection:hover::after ,div.div-connection:hover::before {display: flex;}");


	printf(".deconnection{margin: 20px 10px 0 10px;}");


	printf("</style>");
}
