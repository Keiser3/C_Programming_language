#include<stdio.h>
#include<stdlib.h>
typedef struct integer{
    int x;
    struct integer *next;

}integer;
typedef struct {
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
void main(){

}