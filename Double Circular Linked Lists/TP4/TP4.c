#include<stdio.h>
#include<stdlib.h>
#define BUFF 30
typedef struct patient{
    char nom[BUFF];
    char prenom[BUFF];
    int rdv;
    struct patient *next, *prev;
} patient;
patient *Saisie(void){
  patient *temp = (patient*) malloc(sizeof(patient));
  printf("Le Nom./");
  scanf("%s",temp->nom);
  fflush(stdin);
  printf("Le Prenom./");
  scanf("%s",temp->prenom);
  fflush(stdin);
  do
  {
    scanf("%d",temp->rdv);
  } while (temp->rdv>1 || temp->rdv<0);
  return temp;
}

patient *AjoutPatientT(patient *root, patient *Aj){
    
    patient *temp = Aj;
    temp->next = root->next;
    temp->prev = root;
    root->next->prev = temp; 
    root->next = temp;
    return root;
}
patient *AjoutPatientQ(patient *root, patient *Aj){
    patient *temp = Aj;
    temp->prev = root->prev;
    temp->next = root;
    root->prev->next = temp; 
    root->prev = temp;
    return root;
}
patient *AjoutPatientPos(patient *root, patient *Aj, int pos){
    patient *temp = Aj;
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
void *SuppressionPatientT(patient **root){
     patient *temp = *root;
     temp = temp->next;
     temp->prev = *root;
}
void *SuppressionPatientQ(patient **root){
    patient *temp = *root;
    temp = temp->prev->prev;
    temp->next = *root;
}


void main(){
    patient *sAttente = (patient*) malloc(sizeof(patient));
    patient *Aj = (patient*) malloc(sizeof(patient));
    sAttente->next = sAttente;
    sAttente->prev = sAttente;
    Aj = Saisie();

}
