#include<stdio.h>
#include<stdlib.h>


typedef struct patient{
	int NumSs;
    char nom[30];
    char prenom[30];
    float age;
	struct patient *next;
}patient;
typedef struct Stack{
	struct patient *first;
}Stack;

void Push(Stack * P){
	patient *e=(patient*)malloc(sizeof(patient));
	printf("Print an integer:\n");
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
	e->next=P->first;
	P->first=e;	
}