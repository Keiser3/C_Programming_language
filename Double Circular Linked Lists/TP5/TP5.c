#include<stdio.h>
#include<stdlib.h>
#define BUFFER 30
typedef struct voiture{
    int mat;
    int AmC;
    char marque[BUFFER];
    int pF;
    float PrixLoc;
    struct voiture *next, *prev;
} voiture;

voiture *Saisie(void){
    voiture *temp = (voiture*) malloc(sizeof(voiture));
    printf("La Matricule                ./");
    scanf("%d",&temp->mat);
    printf("\n");
    printf("Annee de mise en circulation./");
    scanf("%d",&temp->AmC);
    printf("\n");
    printf("Marque                      ./");
    scanf("%s",temp->marque);
    fflush(stdin);
    printf("\n");
    printf("Puissance fiscale           ./");
    scanf("%d",&temp->pF);
    printf("\n");
    printf("prix de location            ./");
    scanf("%f",&temp->PrixLoc);

    return temp;
}
 void Affichage(voiture *root){
     voiture *curr = root->next;
     while (curr != root)
     {      
            printf("La Matricule                :%d\n", curr->mat);
            printf("Annee de mise en circulation:%d\n",curr->AmC);
            printf("Marque                      :%s\n",curr->marque);
            printf("Puissance fiscale           :%d\n",curr->pF);
            printf("prix de location            :%.3f\n",curr->PrixLoc);
            printf("***************************************************");
            curr = curr->next;
     }
 }
 voiture *AjoutTete(voiture *root){
    voiture *temp = Saisie();
    temp->prev = root->prev;
    temp->next = root;
    root->prev->next = temp; 
    root->prev = temp;
    return root;
    
 }


void main(){
   voiture *root = (voiture*) malloc(sizeof(voiture));
   root->next = Saisie();
   root->prev = root->next;
   Affichage(root);
   AjoutTete(root);
   Affichage(root);
   

}