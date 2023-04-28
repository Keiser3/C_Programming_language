#include<stdio.h>
#include<stdlib.h>
typedef struct integer{
	int x;
	struct integer *next;
}integer;
typedef struct Queue{
	struct integer *first;
}Queue;

void EnQueuer(Queue * F){
	integer *e=(integer*)malloc(sizeof(integer)), *p;
	printf("Donner un integer:\n");
	scanf("%d",&e->x);
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
//Suppression
void DeQueuer(Queue *P){
	integer *e=P->first;
	if(e==NULL) printf("Empty Queue!\n");
	else{
		P->first=e->next;
		printf("integer Supprime est : %d\n",e->x);
		free(e);	
	}	
}
//Recuperation de l'integer deQueue
integer* DeQueuerEnt(Queue *P){
	integer *e=P->first;
	if(e==NULL) {printf("Empty Queue! \n"); return NULL;}
	else{
		P->first=e->next;
		//printf("integer Recupere est : %d\n",e->x);
		return e;
	}
}

void AfficherQueue(Queue* P){
	integer *e=P->first;
	while(e!=NULL){
		printf("%d\n", e->x);
		e=e->next;
	}
}


main(){
	int i,n=4;
	integer *Dep;
	Queue *MaQueue=(Queue*)malloc(sizeof(Queue));
	MaQueue->first=NULL;
	for(i=1;i<=n;i++)
		EnQueuer(MaQueue);
	
	AfficherQueue(MaQueue);
	DeQueuer(MaQueue);
	AfficherQueue(MaQueue);
	Dep=DeQueuerEnt(MaQueue);
	if(Dep==NULL) puts("\nQueue vide!");
	else printf("\n La valeur recuperee est :%d\n",Dep->x);
	free(Dep);
	AfficherQueue(MaQueue);
}
