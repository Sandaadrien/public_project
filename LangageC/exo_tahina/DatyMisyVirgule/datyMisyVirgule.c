

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char** manasaraka(char* car);
double* chaineToDouble(char* date);
char** creeTabChaine(int dim,int taille);
int testDeVirgule(char* car);
double* charToDoubleMisyVirgule(char** car);
char** devirguler(char* car);
double charToDouble(char* car);
void conversComplet(double jour,double*j,double*h,double*m,double*s);
double jourToSeconde(double jour);
int nombreDeJour(double mois,double annee);
double* reglementation(double* datyDouble);



/*


	mila avadika ho nombre ilay mot(chaineToDouble)
	
		*raisina ilay mot de sarahina isakin'ny /

		* Jerena TSIRAIRAY ireo mots raha misy ',' na '.'
		
			*rehefa misy dia sarahana indray ilay mot, ho lasa mot anakiroa(devirguler)
			*de miantso ny fonction charToDoubleMisyVirgule(manome tableau de nombre: T[0]-alohan'ny virgule,T[1]-arina amizay mamadika le mots anakiroa ho lasa nombre 
			* mila avadika 10⁻zavatra ilay nombre arinan'ny virgule de atambatra ilay mot


			*rehefa Tsy misy de avadiho nombre ilay char* (charToDouble)
	
	jerena tsara ny daty raha manaraka ny fenitra jour <= (28,30,31) volana < 12
	
	ny nombre azo voalohany avadika jour,heure,min,sec(conversComplete)
	ny manarakaS avadika moi,sy annee
*/





int main () {
	int nbJour = 31;
	char* daty = "05,3/10/1981";
	double *datyDouble = malloc(sizeof(double)*3);
	char* phrase=malloc(sizeof(char)*50);
	/// avadika nombre daholo ny char rehetra
	datyDouble = chaineToDouble(daty);
	
	/// mila fantarina na 30 jour ny volana na 31 na 28 na 29
	nbJour = nombreDeJour(*(datyDouble+1),*(datyDouble+2));
	
	datyDouble = reglementation(datyDouble);
	
	int tmp;
	tmp = (int)*(datyDouble+2);
	*(datyDouble+1) += (*(datyDouble+2) - tmp)*12;
	*(datyDouble+2) = tmp;
	
	tmp = (int)*(datyDouble+1);
	*datyDouble += (*(datyDouble+1) - tmp)*nbJour;
	*(datyDouble+1) = tmp;
	
	datyDouble = reglementation(datyDouble);

	double jours,heures,minutes,secondes;

	conversComplet(*datyDouble,&jours,&heures,&minutes,&secondes);

	sprintf(phrase,"%.0f : %.0f : %.0f\t%.0f : %.0f : %.0f",heures,minutes,secondes,jours,*(datyDouble+1),*(datyDouble+2));
	printf("%s",phrase);
	return 0;
}



double* reglementation(double* datyDouble){

	// ampitomboana ny taona rehefa mihoatra ny 12 ny volana
	if(*(datyDouble+1)>12){
		
		while(*(datyDouble+1)>12){
			*(datyDouble+1) -= 12;
			*(datyDouble+2)+=1;
		}
		
	}

	int nbJour;
		/// mila fantarina na 30 jour ny volana na 31 na 28 na 29
	nbJour = nombreDeJour(*(datyDouble+1),*(datyDouble+2));
		// rehefa mihoatra ny nombre de jour tokony ho izy ao anatin'ny volana iray ,dia ampitomboana le volana
	if(*datyDouble>nbJour){
		
		while(*datyDouble>nbJour){
			*(datyDouble) -= nbJour;
			*(datyDouble+1)+=1;
			nbJour = nombreDeJour(*(datyDouble+1),*(datyDouble+2));
		}
		
	}
	// ampitomboana ny taona rehefa mihoatra ny 12 ny volana
	if(*(datyDouble+1)>12){
		
		while(*(datyDouble+1)>12){
			*(datyDouble+1) -= 12;
			*(datyDouble+2)+=1;
		}
		
	}
	
	return datyDouble;
}


int nombreDeJour(double mois,double annee){
	int nombre,mod1,mod2;
	mod1 = (int)annee % 4;
	mod2 = (int)annee % 100;
	
	if(mois == (1 || 3 || 5 || 7 || 8 || 10 || 12))
		nombre = 31;
	
	else if (((mod1&&mod2) != 0) && mois == 2)
		nombre = 28;
	
	else if (((mod1&&mod2) == 0) && mois == 2)
		nombre = 29;

	else
		nombre = 30;
	return nombre;
}


double jourToSeconde(double jour){
	double seconde;
	seconde = jour * 24 * 3600;
	return seconde;
}


void conversComplet(double jour,double*j,double*h,double*m,double*s){
	double sec;
	sec = jourToSeconde(jour);
	int reste;
	
	*j = (int)sec / (24*3600);
/*//	indray indray manome 0 ilay izy dia iny 0 iny atao 1
	if(*j==0)
		*j=1;
*/
	reste = (int)sec % (24*3600);
	*h = reste/ 3600;

	reste = reste % 3600;
	*m = reste / 60;

	*s = reste % 60;

}


double charToDouble(char* car){
	
	double nombre;
	int isa,mem;
	isa = strlen(car);
	mem = isa;
	for(int i=0;i<mem;i++,isa--)
		nombre += (*(car+i)-48)*pow(10,isa-1);
	
	return nombre;
}


char** devirguler(char* car){
	
	char** tab2Char=NULL;
	int i,j,n;
	
	tab2Char = creeTabChaine(2,20);
	
	/// miafecter ny alohan'ny virgule ao anaty mot1 sy ny ariana ao anaty mot2
	for(i=0,j=0,n=0;*(car+i);i++){
		// rehefa tonga eo amin'ilay virgule de mifindra mot
		if(*(car+i)== ',' || *(car+i)== '.' ){
			j = 1;
			n = 0;
			continue;
		}
	
		*(*(tab2Char+j)+n) = *(car+i);
		/// Tsy azo apiakarina eny amin'ny boucle !! :
		n++;
	}
	
	return tab2Char;
}


double* charToDoubleMisyVirgule(char** car){
	int isa,mem;
	double* tabEntier=NULL;
	tabEntier = malloc(sizeof(double)*2);
	
/*
 * 	JEREO TSARA LE FANORATANA CARACTÈRE 
	printf("%c\n",*((*car)+1));
*/
	for(int j=0;j<2;j++){
		isa = strlen(*(car+j));
		mem = isa;
		for(int i=0;i<mem;i++,isa--)
			*(tabEntier+j) += (*((*(car+j))+i)-48)*pow(10,isa-1);
	
	}
		
	return tabEntier; 
}


int testDeVirgule(char* car){
	int bool = 0;
	for(int i=0;*(car+i);i++){
		
		if(*(car+i)==','|| *(car+i)=='.'){
			bool = 1;
			break;
		}
		
	}
	
	return bool;
}


char** creeTabChaine(int dim,int taille){
	
	char** tabDeChaine;
	tabDeChaine= malloc(sizeof(char*)*dim);
	for(int i=0;i<dim;i++){
		*(tabDeChaine+i) = malloc(sizeof(char)*taille);
	}
	
	return tabDeChaine;
}


double* chaineToDouble(char* date){
	
	double* dateDouble;
	int bool=0;
	dateDouble = malloc(sizeof(double)*3); 
	char** dateChar;

	dateChar = creeTabChaine( 3 , 20);
	
	// sarahana isakin'ny / ny mot
	dateChar = manasaraka(date);
	
	for(int j=0;j<3;j++){
		
		/// mila jerena aloha ilay chaine na misy virgule na tsy misy
		bool = testDeVirgule(*(dateChar+j));
		
		if(bool==1){
			char** chaine;
			double* tabDouble = malloc(sizeof(double)*2);
			int isa=0;
			chaine = creeTabChaine(2,20);
			
			// zaraina 2 ilay chaine misy virgule : ny partie misy de ny partie tsy misy
			chaine = devirguler(*(dateChar+j));
			// isaina ilay caractère ao aorianan'ny virgule mba ahafahany mano an'le pow(10,-isa) 
			isa = strlen(*(chaine+1));

			tabDouble = charToDoubleMisyVirgule(chaine);
		
			*(dateDouble+j) = *(tabDouble)+(pow(10,-isa)* *(tabDouble+1));
			
			//printf("%f\n",*(dateDouble+j));
		}
		
		else
			*(dateDouble+j) = charToDouble(*(dateChar+j));
		
	}
	
	return dateDouble;
}


char** manasaraka(char* car){
	
	char** tabFragmenter=NULL;
	int i,j=0,n=0;
	// manamboatra an'ilay tableau de retour
	tabFragmenter = malloc(sizeof(char*)*3);
	for(i=0;i<3;i++){
		*(tabFragmenter+i) = malloc(sizeof(char)*20);
	}
	for(i=0;*(car+i);i++){
		
		if(*(car+i)=='/'){
			j++;
			n=0;
			continue;
		}
		
		*(*(tabFragmenter+j)+n) = *(car+i);
		n++;
		
	}
	return tabFragmenter;
	
}

