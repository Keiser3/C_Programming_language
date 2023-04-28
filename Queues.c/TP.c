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

