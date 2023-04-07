#include<stdio.h>
#include<stdlib.h>

typedef struct entier{
    int x;
    struct entier *suivant, *precedant;
} entier;
entier *Ajoutdebut(entier *liste){
    entier *e = (entier*) malloc(sizeof(entier));
    printf("saisir l'entier\n");
    scanf("%d",&e->x);
    e->suivant = liste->suivant;
    e->precedant = liste; 
    if (liste->suivant!=NULL)
    {
        liste->suivant->precedant = e;
    }
    liste->suivant = e;
    return liste;
    
}

void Afficher(entier *liste){
    entier *curr = liste->suivant;
    printf("Affichage:-----------------------------------------\n");
    while(curr!=NULL){
        printf("%d\n",curr->x);
        curr=curr->suivant; 
    }
}
entier *suppdebut(entier *liste){
    entier *e = liste ->suivant;
    if(e==NULL) return liste;
    liste->suivant=e->suivant;
    if (e->suivant!=NULL)
    {
        e->suivant->precedant = liste;
    }
     free(e);
    return liste;
}
entier *ajoutFin(entier *liste){
     entier *e , *p;
     if(liste->suivant == NULL){
        return Ajoutdebut(liste);
     }
     e = (entier*) malloc(sizeof(entier));
        printf("saisir l'entier: \n");
        scanf("%d",&e->x);
        p= liste->suivant;

       while(p->suivant!=NULL){
        p = p->suivant;
      }
      e->suivant = NULL;
      p->suivant = e;
      e-> precedant = p;
      return liste; 
}
void main(){
    entier *liste = (entier*) malloc(sizeof(entier));
    liste->suivant = NULL;
    liste->precedant = NULL;
    Ajoutdebut(liste);
    Ajoutdebut(liste);
    Ajoutdebut(liste);
    Ajoutdebut(liste);
    Afficher(liste);
    suppdebut(liste);
    Afficher(liste);
    suppdebut(liste);
    Afficher(liste);
    ajoutFin(liste);
    Afficher(liste);
    
}