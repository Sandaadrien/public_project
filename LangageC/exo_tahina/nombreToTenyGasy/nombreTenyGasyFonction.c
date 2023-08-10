#include "nombre_teny_gasy.h"


char* manonona(int* nombre,int isa,int nb){
	
	char* phrase = malloc(sizeof(char)*100);
	int tmp;
	
	for(int i=0;i<isa;i++){

		if(i==0){
			if(isa==1 && *(nombre+i)==0)
				strcpy(phrase,"ahotra");
				
			else if(isa>1 && *(nombre+i)==0)
				continue;
			
			else {
			tmp = *(nombre + i);
			strcpy(phrase,tsotra(tmp));
			}
		}
		
// mananika ny folo
		if(i==1){
			if(*(nombre+i)==0)
				continue;
			else{

				if((nb%(int)pow(10,isa-(isa-1)))==0){
					tmp = *(nombre + i);
					strcpy(phrase,folo(tmp));
				}
				else if((nb%(int)pow(10,isa-(isa-1)))!=0){
					tmp = *(nombre + i);
					strcat(strcat(phrase," amby "),folo(tmp));
				}
			}
				
		}
// mananika ny zato
		if(i==2){
			
			if(*(nombre+i)==0)
				continue;
			else{
				if((nb%(int)pow(10,isa-(isa-2)))==0){
					tmp = *(nombre + i);
					strcpy(phrase,zato(tmp));
				}
				/// rehefa 1??
				else if((nb%(int)pow(10,isa-(isa-2)))!=0 && *(nombre+i)==1){
					tmp = *(nombre + i);
					strcat(strcat(phrase," amin'ny "),zato(tmp));
				}
				/// rehefa ??? !=0
				else if((nb%(int)pow(10,isa-(isa-2)))!=0 && *(nombre+i)!=1){
					tmp = *(nombre + i);
					strcat(strcat(phrase," sy "),zato(tmp));
				}
			}	
		}
// mananika ny arivo
		if(i==3){

			if(*(nombre+i)==0)
				continue;
			else{
			///	?000
				if((nb%(int)pow(10,isa-(isa-3)))==0){
					tmp = *(nombre + i);
					strcpy(phrase,arivo(tmp));
				}
				/// rehefa #??? où #!=0
				else if((nb%(int)pow(10,isa-(isa-2)))!=0){
					tmp = *(nombre + i);
					strcat(strcat(phrase," sy "),arivo(tmp));
				}
			}
		}
// mananika ny alina
		if(i==4){
			
			if(*(nombre+i)==0)
				continue;
			else{
				/// rehefa   ?0 000
				if((nb%(int)pow(10,isa-(isa-4)))==0){
					tmp = *(nombre+i);
					strcpy(phrase,strcat(tsotra(tmp)," alina "));
				}
				/// rehefa ?? ????
				else if((nb%(int)pow(10,isa-(isa-4)))!=0){
					tmp = *(nombre+i);
					strcat(phrase," sy ");
					strcat(phrase,strcat(tsotra(tmp)," alina "));
					
				}
				
				
			}
		}
		
// mananika ny hetsy
		if(i==5){
			
			if(*(nombre+i)==0)
				continue;
			else{
				/// rehefa   ?00 000
				if((nb%(int)pow(10,isa-(isa-5)))==0){
					tmp = *(nombre+i);
					strcpy(phrase,strcat(tsotra(tmp)," hetsy "));
				}
				/// rehefa ?? ????
				else if((nb%(int)pow(10,isa-(isa-5)))!=0){
					tmp = *(nombre+i);
					strcat(phrase," sy ");
					strcat(phrase,strcat(tsotra(tmp)," hetsy "));
					
				}
				
				
			}
		}

	}		
	
	return phrase;
}

int manisa(int nombre){
	int i,j;
	if (nombre==0)
		j = 1;
	else{
		for(i=1,j=0;(nombre/i)!=0;i*=10)
			j++;
	}		
	return j;
}

int * manasaraka(int nombre){
	int* nbMisaraka = malloc(sizeof(int)*manisa(nombre));
	
	for(int i=0;nombre!=0;i++){
		*(nbMisaraka+i) = nombre%10;
		nombre = nombre/10;
	}
	
	return nbMisaraka;
}

char* tsotra(int nombre){
	char** mot = malloc(sizeof(char*)*10);
	for(int i=0;i<10;i++)
		*(mot + i) = malloc(sizeof(char)*20);
	strcpy(*mot,"ahotra");
	strcpy(*(mot+1),"iray");
	strcpy(*(mot+2),"roa");
	strcpy(*(mot+3),"telo");
	strcpy(*(mot+4),"efatra");
	strcpy(*(mot+5),"dimy");
	strcpy(*(mot+6),"enina");
	strcpy(*(mot+7),"fito");
	strcpy(*(mot+8),"valo");
	strcpy(*(mot+9),"sivy");
	
	
	return *(mot+nombre);
}
char* folo(int nombre){
	char** mot = malloc(sizeof(char*)*10);
	for(int i=0;i<10;i++)
		*(mot + i) = malloc(sizeof(char)*20);
	strcpy(*mot," ");
	strcpy(*(mot+1),"folo");
	strcpy(*(mot+2),"roapolo");
	strcpy(*(mot+3),"telopolo");
	strcpy(*(mot+4),"efapolo");
	strcpy(*(mot+5),"dimapolo");
	strcpy(*(mot+6),"enim-polo");
	strcpy(*(mot+7),"fitopolo");
	strcpy(*(mot+8),"valopolo");
	strcpy(*(mot+9),"sivifolo");
	
	
	return *(mot+nombre);
}
char* zato(int nombre){
	char** mot = malloc(sizeof(char*)*10);
	for(int i=0;i<10;i++)
		*(mot + i) = malloc(sizeof(char)*20);
	strcpy(*mot," ");
	strcpy(*(mot+1),"zato");
	strcpy(*(mot+2),"roanjato");
	strcpy(*(mot+3),"telonjato");
	strcpy(*(mot+4),"efajato");
	strcpy(*(mot+5),"dimanjato");
	strcpy(*(mot+6),"eninjato");
	strcpy(*(mot+7),"fitonjato");
	strcpy(*(mot+8),"valonjato");
	strcpy(*(mot+9),"sivinjato");
	
	
	return *(mot+nombre);
}
char* arivo(int nombre){
	char** mot = malloc(sizeof(char*)*10);
	for(int i=0;i<10;i++)
		*(mot + i) = malloc(sizeof(char)*20);
	strcpy(*mot," ");
	strcpy(*(mot+1),"arivo");
	strcpy(*(mot+2),"roa arivo");
	strcpy(*(mot+3),"telo arivo");
	strcpy(*(mot+4),"efatra arivo");
	strcpy(*(mot+5),"dimy arivo");
	strcpy(*(mot+6),"enina arivo");
	strcpy(*(mot+7),"fito arivo");
	strcpy(*(mot+8),"valo arivo");
	strcpy(*(mot+9),"sivy arivo");
	
	
	return *(mot+nombre);
}
