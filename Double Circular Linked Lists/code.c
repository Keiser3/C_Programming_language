#include<stdio.h>
#include<stdlib.h>
typedef struct entier{
    int x;
    struct entier *next,*prev;
} entier;

entier *AjoutDebut(entier *root){
    entier *temp = (entier*) malloc(sizeof(entier));
    int x;
    temp = root;
    printf("L'entier./");
    scanf("%d",&x);
    temp->x = x;
    temp->next = root->next;
    temp->prev = root;
    root->next->prev = temp; 
    root->next = temp;
    return root;
}
entier *AjoutFin(entier *root){
    entier *temp = (entier*) malloc(sizeof(entier));
    temp = root;
    int x;
    printf("L'entier./");
    scanf("%d",&temp->x);
    temp->prev = root->prev;
    temp->next = root;
    root->prev->next = temp; 
    root->prev = temp;
    return root;
}

void AffichageNrml(entier *root){
    printf("test1\n");
    entier *curr = (entier*) malloc(sizeof(entier));
    printf("test2\n");
    int i= 1;
    curr = root;
    printf("test3\n");
    while(curr->next != root ){
        printf("test4\n");
        printf("Entier %d: %d \n",i,curr->x);
        curr = curr->next;
        i++;
    }
}
void AffichageInvrs(entier *root){
    entier *curr = (entier*) malloc(sizeof(entier));
    int i= 1;
    curr = root->next;
    while(curr->prev != root){
        printf("Entier %d: %d \n",i,curr->x);
        curr = curr->prev;
        i++;
    }
}
void main(){
  entier *root = (entier*) malloc(sizeof(entier));
  root->next = root;
  root->prev = root;

  AjoutDebut(root);
  AjoutDebut(root);
  AjoutFin(root);
  AffichageNrml(root);
  AffichageInvrs(root);
  
}

