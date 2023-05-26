#include<stdio.h>
#include<stdlib.h>
 typedef struct {
    int j,m,a;
 } date;
 typedef struct Wagon{
    char code[10];
    int NbPlace;
    int classe;
    struct Wagon *next;
 }Wagon;

 Wagon *saisie(){
    Wagon *temp = (Wagon*) malloc(sizeof(struct Wagon));
    printf("Code./");
    scanf("%s",temp->code);
    fflush(stdin);
    printf("\n");
    printf("Nombre de place./");
    scanf("%d",&temp->NbPlace);
    printf("\n");
    do
    {
        printf("Classe (1 / 2)");
        scanf("%d",&temp->classe);
    } while (temp->classe != 1 && temp->classe != 2);    
    temp->next = NULL;
  }
  
Wagon *ajoutdebut(Wagon *liste){
     Wagon *e= saisie();
     e->next = liste->next;
     liste->next = e;
     return liste;
}
Wagon *ajoutFin(Wagon *liste){
     Wagon *e= saisie();
      Wagon *p= liste->next;
       while(p->next!=liste){
        p = p->next;
      }
      p->next = e;
      e->next = liste;
      return liste; 
}

void Affichage(Wagon *root){
    Wagon *temp = root;
    int i=0;
    while(temp->next != NULL ){
        printf("Wagon %d:\n",i+1);
        printf("Code             :%s\n",temp->code);
        printf("Nombre de Place  :%d\n",temp->NbPlace);
        printf("Classe           :%d\n",temp->classe);
        i++;
        temp = temp->next;
    }
}
Wagon *FIFO(Wagon *root, Wagon *fRoot){
    
}
void main(){
    Wagon *root = (Wagon*) malloc(sizeof(struct Wagon));
    Wagon *fRoot = (Wagon*) malloc(sizeof(struct Wagon));
    Wagon *lRoot = (Wagon*) malloc(sizeof(struct Wagon));
    for ( int i = 0; i < 3; i++)
    {
        ajoutdebut(root);
    }

    Affichage(root);
    
}