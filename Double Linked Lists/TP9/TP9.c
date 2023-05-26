#include<stdio.h>
#include<stdlib.h>

typedef struct chaine {
    char S[100];
    struct chaine *next,*prev;
} chaine;
typedef struct Queue{
	struct chaine *first;
}Queue;
typedef struct Stack{
    struct chaine *first;
}Stack;
char* saisie(){
    char *str;
    scanf("%[^\n]s",str);

    return str;
}
chaine *AjoutchaineT(chaine *root){
    
    chaine *temp = (chaine*) malloc(sizeof(struct chaine));
    *temp->S = saisie();
    temp->next = root->next;
    temp->prev = root;
    root->next->prev = temp; 
    root->next = temp;
    return root;
}
chaine *AjoutchaineQ(chaine *root){
    chaine *temp = saisie();
    temp->prev = root->prev;
    temp->next = root;
    root->prev->next = temp; 
    root->prev = temp;
    return root;
}
chaine *AjoutchainePos(chaine *root, int pos){
    chaine *temp = saisie();
    while (--pos)
    {
        temp = temp->next;
    }
    temp->prev = root->prev;
    temp->next = root;
    root->prev->next = temp; 
    root->prev = temp;
    
     return root;
}
void affichage(chaine *root){
    chaine *temp = root->next;
    
}
void *SuppressionChaineT(chaine **root){
     chaine *temp = *root;
     temp = temp->next;
     temp->prev = *root;
}
void *SuppressionchaineQ(chaine **root){
    chaine *temp = *root;
    temp = temp->prev->prev;
    temp->next = *root;
}

void main(){
    chaine *root = (chaine*) malloc(sizeof(struct chaine));
    
    

}