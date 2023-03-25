#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char nom[30];
    char prenom[30];
    float age;
    float note;
} etudiant;

void main()
{
    etudiant etud;
    FILE *f;
    int i;
    f=fopen("revisionFILES.txt","at");
    if(f){
        for(i=0;i<5;i++){
        printf("nom, prenom, age, note\n");
        scanf("%s%s%f%f");
        fflush(stdin);
        fprintf(f,"%s%s%f%f",etud.nom,etud.prenom,etud.age,etud.note);
        }
    fclose(f);
    } else printf("ERREUR DU FICHIER!\n");
    
}