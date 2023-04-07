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
    liste->suivant = e->suivant;
    if (e->suivant!=NULL)
    {
        liste->suivant->precedant = e;
    }
     free(e);
    return liste;
}

void main(){
    entier *liste = (entier*) malloc(sizeof(entier));
    liste->suivant = NULL;
    liste->precedant = NULL;
    Ajoutdebut(liste);
    Ajoutdebut(liste);
    Afficher(liste);
    suppdebut(liste);
    Afficher(liste);
    
}