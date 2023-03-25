#include<stdio.h>
#include<stdlib.h>
typedef struct complex{
    float pr,pi;
    struct  complex *suivant;
} complex;
complex* Ajoutdebut(complex *liste) 
{
    complex *c;
    //allocation
    c=(complex*) malloc(sizeof(complex));
    //Lecture des donnees
    printf("donner la partie reel, et la partie imaginaire:\n");
    scanf("%f %f",&c->pr,&c->pi);
    //chainage
    c->suivant=liste;
    liste=c;
    return liste;
}
void AfficherListe(complex* liste){
    complex *c;
    int i=0;
    c=liste;
    while(c!=NULL){
        printf("complex %d: %.2f+%.2fi \n",++i,c->pr,c->pi);
        c=c->suivant;
    }
}
complex *AjoutFin(complex *liste){
	complex *t=liste;
	complex *c=(complex*)malloc(sizeof(complex));
	printf("Donner la partie r%celle et la partie imaginaire:\n",138);
	scanf("%f%f",&c->pr,&c->pi);
	if(liste==NULL){
		c->suivant=liste;
		liste=c;
	}else{
		while(t->suivant!=NULL){
			t=t->suivant;
		}
		t->suivant=c;
		c->suivant=NULL;
	}
	return liste;
}
 void main(){
  
  

 }
 /* ajout a la fin:
    complex *t= liste;
    while(t->suivant!NULL){
        t=t->suivant;
    }
    c->suivant = NULL;
    t-> suivant = c;
 */