#include<stdio.h>
#include<stdlib.h>
 typedef struct patient{
	int NumSs;
    char nom[30];
    char prenom[30];
    float age;
	struct patient *next;
}patient;
typedef struct Queue{
	struct patient *first;
}Queue;

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
		e=e->next;
        i++;
	}
}
int Empty(Queue *P){
	patient *e=P->first;
	if(e==NULL) return 1;
    else
      return 0;
}
int Full(Queue *P){
    patient *e = (patient*) malloc(sizeof(struct patient));
    if (e!= NULL)
        return 0;
    else 
        return 1;
}


float MoyenneAge(Queue* P){
	patient *e=P->first;
    int i=0;
    float moyenne;
	while(e!=NULL){
        moyenne += e->age;
		e=e->next;
        i++;
	}
    return moyenne/i;
}
int NbNomA(Queue* P){
    patient *e=P->first;
    int i=0;
    while(e!=NULL){
        if (e->nom[0] == 'a' || e->nom[0] == 'A' ){
            i++;
        }

		e=e->next;
	}
    return i;
}
void menu(){
    printf("*******************Cabinet Medecin************************\n");
    printf("1: Ajouter un patient\n");
    printf("2: supprimer un patient\n");
    printf("3: Afficher les patients\n");
    printf("4: tester si la file est vide\n");
    printf("5: tester si la file est pleine\n");
    printf("6: calculer la moyenne d'age\n");
    printf("7: le nombre des patients ayant un nom commencant par 'A'\n");
    printf("votre choix ./");
}


void main(){
  
    int i,n=2;
	patient *Dep;
	Queue *MaQueue=(Queue*)malloc(sizeof(Queue));
	MaQueue->first=NULL;
	for(i=1;i<=n;i++)
		unshift(MaQueue);
    
    AfficherQueue(MaQueue);
    shift(MaQueue);
    
    int chx;
    while (1)
    {
         menu();
         scanf("%d",&chx);
         switch (chx)
         {
         case 1:
            unshift(MaQueue); break;
         case 2:
            shift(MaQueue); break;
         case 3:
            AfficherQueue(MaQueue); break;
         case 4:
             Empty(MaQueue); break; 
         case 5:
             Full(MaQueue); break;
         case 6:
             printf("La moyenne d' Age: %.2f",MoyenneAge(MaQueue));
         case 7:
             printf(" le nombre des patients ayant un nom commencant par 'A': %d",NbNomA(MaQueue));
         default:
            break;
         }
        
    }
    
}