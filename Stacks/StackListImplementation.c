#include<stdio.h>
#include<stdlib.h>
typedef struct integer{
	int x;
	struct integer *next;
}integer;
typedef struct Stack{
	struct integer *first;
}Stack;

void Push(Stack * P){
	integer *e=(integer*)malloc(sizeof(integer));
	printf("Print an integer:\n");
	scanf("%d",&e->x);
	e->next=P->first;
	P->first=e;	
}
//Suppression
void Pop(Stack *P){
	integer *e=P->first;
	if(e==NULL) printf("Stack Underflow!\n");
	else{
		P->first=e->next;
		printf("Deleted integer is : %d\n",e->x);
		free(e);	
	}	
}
//Recuperation de l'integer deStack
integer* PopInt(Stack *P){
	integer *e=P->first;
	if(e==NULL) {printf("Stack Underflow!\n"); return NULL;}
	else{
		P->first=e->next;
		//printf("integer Recupere est : %d\n",e->x);
		return e;
	}
}

void PrintStack(Stack* P){
	integer *e=P->first;
	while(e!=NULL){
		printf("%d\n", e->x);
		e=e->next;
	}
}


void main(){
	int i,n=4;
	integer *Dep;
	Stack *stack=(Stack*)malloc(sizeof(Stack));
	stack->first=NULL;
	
	for(i=1;i<=n;i++)
		Push(stack);
	
	PrintStack(stack);
	Pop(stack);
	PrintStack(stack);
	Dep=PopInt(stack);
	if(Dep==NULL) puts("\nStack Underflow!");
	else printf("\n Parsed Integer:%d\n",Dep->x);
	free(Dep);
	PrintStack(stack);
}
