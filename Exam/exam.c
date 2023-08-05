#include<stdio.h>
#include<stdlib.h>

typedef struct character{
    char c;
    struct character *next;
}character;

typedef struct Stack{
	struct character *first;
}Stack;

void Push(Stack * P){
	character *e=(character*)malloc(sizeof(character));
	printf("type a character:\n");
	scanf("%c",&e->c);
    fflush(stdin);
	e->next=P->first;
	P->first=e;	
}
//Suppression
void Pop(Stack *P){
	character *e=P->first;
	if(e==NULL) printf("Stack Underflow!\n");
	else{
		P->first=e->next;
		printf("Deleted character is : %d\n",e->c);
		free(e);	
	}	
}
void PrintStack(Stack* P){
	character *e=P->first;
	while(e!=NULL){
		printf("%c\n", e->c);
		e=e->next;
	}
}
int IsEmpty(Stack *P){
    character *e = P->first;
    if(e==NULL){
        return 1;
    }
    else return 0;
}
int nbOccur(Stack *P, char c){
    character *e=P->first;
    int cpt=0;
	while(e!=NULL){
		if(e->c == c){
            cpt++;
        }
		e=e->next;
	}
    return cpt;
}
void changeChar(Stack *P, char c, char c1){
    character *e= P->first;
    
	while(e!=NULL){
		if(e->c == c){
            e->c = c1;
        }
		e=e->next;
	}
}
void PushChar(Stack * P,char c){
	character *e=(character*)malloc(sizeof(character));
	e->c = c;
    fflush(stdin);
	e->next=P->first;
	P->first=e;	
}
int PopChar(Stack *P){
	character *e=P->first;
    int pCpt=0;
	if(e==NULL) 
    {
        printf("#ERROR: No matching '(' found ");
        exit(0);
    }
	else{
		P->first=e->next;
		
		free(e);	
	}
  
}
void ParenthesisCheck(Stack *P,char *str){
    int i = sizeof(str);
    for ( i = 0; str[i]!='\0' ; i++)
    {
        if(str[i]=='('){
            PushChar(P,str[i]);
        }
        if(str[i]==')'){
            PopChar(P);
        }
    }
}


 void main(){
    int i,n=4,e;
    int ErrCode=0;
	character *Dep;
	Stack *stack=(Stack*)malloc(sizeof(Stack));
    Stack *stack2=(Stack*)malloc(sizeof(Stack));
    stack2->first =NULL;
    stack->first=NULL;
/*	for(i=1;i<=n;i++)
		Push(stack);
	
	PrintStack(stack);
    if (IsEmpty(stack)==1){
        printf("The Stack is Empty!\n");
    }
    else 
      printf("The Stack is Full!");
    */
    char str[100];
    printf("$Type the string>>>");
    scanf("%s",str);
    printf("_______________________________________________________\n");
    ParenthesisCheck(stack2,str);
    
    PrintStack(stack2);
        if(IsEmpty(stack2)==1){
         printf("#NO ERROR: All parenthesis are valid\n");
    } else 
      printf("#ERROR: Expected ')'\n");
 }