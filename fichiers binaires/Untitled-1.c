#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int matr;
    char nom[30];
    float note;
} etud;
void afficherBIN(char *nf){
    FILE *f;
    etud e;
    int i=0;
    f=fopen(nf,"rb"); //w wb a ab
    if (f)
    {
        
        
        while(fread(&e,sizeof(etud),1,f)==1)    
            {i++;
            printf("ETudian %d: %d \t %s \t %.2f",i+1,e.matr,e.nom,e.note);
            }


        fclose(f);
    } else puts("erreur du fichier binaire!");
}
 void main()
 {
    FILE *f;
    etud e;
    int i, n;
    f=fopen("groupe5.bin","ab"); //w wb a ab
    if (f)
    {
        printf("donner le nombre d'etudiant n \n");
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            printf("donner le matricule, nom et note : %d \n",i+1);
            scanf("%d%s%f",&e.matr,e.nom,&e.note);

            fwrite(&e,sizeof(etud),1,f);

        }



        fclose(f);
    } else puts("erreur du fichier binaire!");
    afficherBIN("groupe5.bin");
    //inserer N etudiant dans un fichier binaire!
 }