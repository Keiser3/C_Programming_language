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
entier *suppfin(entier *liste){
    entier *p = liste->suivant;
     while(p->suivant!=NULL){
        p = p->suivant;
      }
      p->precedant->suivant = NULL;
      free(p);
}
entier *AjoutPos(entier *liste, int pos){
    int i=0;
    entier *e, *p;
    if(pos==1)
       return Ajoutdebut(liste);
    p=liste->suivant;
    while(p!=NULL){
        i++;
        if(pos-1 == i) break;
        
        p=p->suivant;
    }
    if(p==NULL){
        puts("sir tqwd liste khawya\n");
        return liste;
    }
    e=(entier*) malloc(sizeof(entier));
    printf("saisir l' entier\n");
    scanf("%d",&e->x);
    e->suivant = p->suivant;
    e->precedant=p;
    if(p->suivant!=NULL){
        p->suivant->precedant = e;
        p->suivant = e;
    }
    return liste;
}
entier *suppPos(entier *liste, int pos){
    int i=0;
    entier *t, *p;
    if(pos==1)
       return suppdebut(liste);
    p=liste->suivant;
    while(p!=NULL){
        i++;
        if(pos-1 == i) break;
        p=p->suivant;
    }
    if(p==NULL){
        puts("sir tqwd liste khawya\n");
        return liste;
    }
    t = p->suivant;
    p->suivant = t->suivant;

    if(t->suivant!=NULL){
        t->suivant->precedant = p;
    }
    free(t);
    return liste;
}
entier *AjoutPosImp(entier *liste){
    
    int n=0;
    entier *e, *p;
    p=liste->suivant;
    while(p!=NULL){
        if((p->x)%2!=0) n++;
        if(n==2) break;
        
        p=p->suivant;
    }
    if(p==NULL){
        printf("ok\n");
        return liste;
    }
    e=(entier*) malloc(sizeof(entier));
    printf("saisir l' entier\n");
    scanf("%d",&e->x);
    e->suivant = p->suivant;
    e->precedant=p;
    if(p->suivant!=NULL){
        p->suivant->precedant = e;
        p->suivant = e;
    }
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
    
    AjoutPosImp(liste);
    Afficher(liste);
}