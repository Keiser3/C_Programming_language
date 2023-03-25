#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char nom[10];
    int matricule;
    float moy;
} etudiant;
void main()
{
    etudiant e;
    int i;
    int n;
    FILE *f,*v,*nv;
    f=fopen("classe1.txt","at");
if(f)
{   
    printf("donner le nombre des etudiant\n");
     scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("matricule,nom ,  moy\n");
        scanf("%d%s%f",&e.matricule,e.nom,&e.moy);
        fprintf(f," %d \t %s \t %.2f\n",e.matricule,e.nom,e.moy);
    }
    fclose(f);
}else printf("error!");
f=fopen("classe1.txt","rt");
if(f){
    nv=fopen("N_valide.txt","wt");
    printf("non valide: \n");
    while(fscanf(f,"%d%s%f",&e.matricule,e.nom,&e.moy)==3)
    {  
       if(e.moy<10)
       {
         fprintf(nv," %d \t %s \t %.2f\n",e.matricule,e.nom,e.moy);
         printf("%d\t %s\t %.2f\n",e.matricule, e.nom, e.moy);
         
        }
     }

    fclose(nv);
    rewind(f);
    v=fopen("valide.txt","wt");
    
    printf("valide: \n");
    while(fscanf(f,"%d%s%f",&e.matricule,e.nom,&e.moy)==3)
      { 
         if(e.moy>=10)
       {
         printf("%d\t %s\t %.2f\n",e.matricule, e.nom, e.moy);
         fprintf(v," %d \t %s \t %.2f\n",e.matricule,e.nom,e.moy);
        }

      }
    fclose(v);
    fclose(f);
    
    
 }else printf("error 2 !");
}
