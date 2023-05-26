#include<stdio.h>
#include<stdlib.h>
 typedef struct patient{
	int NumSs;
    char nom[30];
    char prenom[30];
    float age;
    char raison;
	struct patient *next,*prev;
}patient;
typedef struct Queue{
	struct patient *first;
}Queue;
typedef struct Stack{
	struct integer *first;
}Stack;

void unshift(Queue * F){
	patient *e=(patient*)malloc(sizeof(patient)), *p;
	printf("Details du patient:\n");
    printf("Num%cro de s%ccurit%c sociale./",138,138,138);
    scanf("%d",&e->NumSs);
    printf("\n");
    printf("Le nom./");
    scanf("%s",e->nom);
    printf("\n");
    printf("Le prenom./");
    scanf("%s",e->prenom);
    printf("\n");
    printf("Age./");
    scanf("%f",&e->age);
    printf("\n");
    do
    {
        printf("Raison de la visite./");
        scanf("%c",&e->raison);
    } while (e->raison != 'c' && e->raison != 'r' && e->raison != 'd');
    
	if(F->first==NULL){
		e->next=F->first;
		F->first=e;
	}else{
		p=F->first;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=e;
		e->next=NULL;
	}		
}
void shift(Queue *P){
	patient *e=P->first;
	if(e==NULL) printf("Empty Queue!\n");
	else{
		P->first=e->next;
		printf("le patient Supprim%c est : %s %s\n",138,e->prenom, e->nom);
		free(e);	
	}	
}
void AfficherQueue(Queue* P){
	patient *e=P->first;
    int i=1;
	while(e!=NULL){
        printf("Patient %d",i);
		printf("Num%cro de s%ccurit%c sociale : %d\n",138,138,138,e->NumSs);
        printf("Nom                           : %s\n",e->nom);
        printf("Prenom                        : %s\n",e->prenom);
        printf("Age                           : %.2f\n",e->age);
        if (e->raison == 'c')
        {
          printf("Raison de la visite           : consultation\n");
        }
        else if (e->raison == 'r'){
          printf("Raison de la visite           : remise des analyses\n");
        }
        else if (e->raison == 'd'){
          printf("Raison de la visite           : dossiers de prise en charge\n");
        }
		e=e->next;
        i++;
	}
}
void nbPatientR(Queue* P, char c){
    patient *e = P->first;
    int cpt=0;
    while (e!=NULL)
    {
        if(e->raison == c){
            cpt++;
        }
    }
    if (e->raison == 'c')
    {
        printf("nombre de patients present pour consultation : %d\n",cpt);    
    }
    else if (e->raison == 'r'){

        printf("nombre de patients present pour remise des analyses : %d\n",cpt);
    }
    else 
      printf("nombre de patients present pour dossiers de prise en charge : %d\n",cpt);
}
void PourcentagePaR(Queue* P, char c){
    patient *e = P->first;
    int cptP=0;
    int cptT=0;
    float prc;
    while (e!=NULL)
    {
        if(e->raison == c){
            cptP++;
        }
        cptT++;
    }
    prc = (cptP*100)/cptT;
    if (e->raison == 'c')
    {
        printf("nombre de patients present pour consultation : %.2f%c\n",prc,37);    
    }
    else if (e->raison == 'r'){

        printf("nombre de patients present pour remise des analyses : %.2f%c\n",prc,37);
    }
    else 
      printf("nombre de patients present pour dossiers de prise en charge : %.2f%c\n",prc,37);
}
void PushToStack(Stack* S, Queue* Q){
	patient *e= Q->first;
    
    while(e != NULL){
		e->prev = e;
		e = e->next;
	}
    
    
	
}
