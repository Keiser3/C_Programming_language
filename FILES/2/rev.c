#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char nom[30];
    char prenom[30];
    float note;
} etudiant;
void Ecrirefichier( char *nf)
{   int n,i;
    etudiant etud;
    FILE *f;
    f=fopen(nf,"at");
    if(f){
        printf("le nombre des etudiant?");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            printf("nom, prenom, note");
            scanf("%s",etud.nom);
            fflush(stdin);
            scanf("%s",etud.prenom);
            fflush(stdin);
            scanf("%f",&etud.note);
            fprintf(f,"%s\t %s\t %.2f\n",etud.nom,etud.prenom,etud.note);
        }
     fclose(f);
    }
}
void LireFichier(char *nf)
{
  
    etudiant e;
    FILE *f;
    f=fopen(nf,"rt");
    if(f)
    {
    while(fscanf(f,"%s%s%f",e.nom,e.prenom,&e.note)==3)
    {
        printf("%s\t %s\t %.2f\n",e.nom,e.prenom,e.note);
    }
    fclose(f);
    } else puts("erreur");
}
void main()
{
    
    int chx;
    char nomF[30];
    printf("1/ ecrire fichier\n 2/ lire fichier\n");
    scanf("%d",&chx);
    while(chx!=0)
    {
    printf("1/ ecrire fichier\n 2/ lire fichier\n");
    scanf("%d",&chx);
    if (chx==1)
    {  printf("le nom du fichier?\n");
       scanf("%s",nomF);
       Ecrirefichier(nomF);
    }
    else if (chx==2)
    {
        LireFichier(nomF);
    }
    else if(chx==3)
     {
        Ecrirefichier(nomF);
     }
    }
     
}
