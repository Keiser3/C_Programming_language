#include<stdio.h>
#include<stdlib.h>

typedef struct patient {
    int x;
    struct patient *next;
}patient;

typedef struct{
  struct patient *first;
} file;

typedef struct integer{
    int x;
    struct integer *next;

}integer;
typedef struct {
   struct integer *first;
}pile;
void enfiler(file *f){
    patient *e=(patient *)malloc(sizeof(patient)), *p;
    e->x = 5;
    if(f->first == NULL){
        e->next = f->first;
        f->first = e;
    } else{
        p=f->first;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next = e;
        e->next = NULL;
    }
}
void defiler(file *f){
    patient *p = f->first;
    if(p==NULL) printf("la file est vide!\n");
    else{
        f->first = p->next;
        printf("element defile: %d",p->x);
        free(p);
    }

}

void empiler(pile *p){
    integer *e = malloc(sizeof(integer));
    e->next = p->first;
    p->first = e;
}
void depiler(pile *p){
    integer *e = p->first;
    if(e==NULL) printf("pile vide!\n");
    else{
        p->first = e->next;
        printf("element depiler:%d",e->x);
        free(e);
    }
}

void main(){
    patient *p;
    file *f = (file*) malloc(sizeof(file));
    f->first = NULL;
}