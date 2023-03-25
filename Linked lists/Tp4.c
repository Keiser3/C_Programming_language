#include<stdio.h>
#include<stdlib.h>

typedef struct entier {
    int x;
    struct entier* next;
}entier;


entier *ajoutdebut(entier *liste){
    entier *e= (entier*) malloc(sizeof(entier));
    scanf("%d",&e->x);
    e->next = liste->next;
    liste->next = e;
     return liste;
}
entier *suppdebut(entier *liste){
    entier *e = liste ->next;
    liste->next = e->next;
     free(e);
    return liste;
}

void afficher(entier *liste){
    entier *p= liste->next;
    printf("Affichage:\n");
     while(p!=liste){
        printf("%d",p->x);
        printf("\n");
        p=p->next;

     }
}


entier *ajoutFin(entier *liste){
     entier *e= (entier*) malloc (sizeof(entier));
      entier *p= liste->next;
      scanf("%d",&e->x);

       while(p->next!=liste){
        p = p->next;
      }
      p->next = e;
      e->next = liste;
      return liste; 
}
entier *suppFin(entier *liste){
    entier *t = (entier*) malloc(sizeof(entier));
    entier *p = (entier*) malloc(sizeof(entier));
    t = liste->next;
     if (liste->next==liste){
        return liste;
     }
     while(t->next != liste){
        t=t->next;
     }
     p = liste->next;
     while(p->next != liste){
        p=p->next;
     }
     free(t);
     p->next = liste;
     return liste;


    
}
entier suppPosition

void main(){
    entier *liste= (entier*) malloc(sizeof(entier));
    liste-> next = liste;
    
    
    ajoutdebut(liste);
    ajoutdebut(liste);
    
    afficher(liste);
    suppdebut(liste);
    afficher (liste);
    ajoutFin(liste);
    afficher (liste);
    free(liste);

}