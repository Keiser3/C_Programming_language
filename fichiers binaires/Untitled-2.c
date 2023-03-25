#include<stdio.h>
#include<stdlib.h>
 typedef struct{
    int numero;
    char auteur[30];
    char editeur[30];
    char titre[100];
    int stock;
    float prix;
 }Typelivre;
 void ajoutLivre(char *nf)
 {
    FILE *f,*f2;
    Typelivre e;
    int chx;
    printf("voulez vous ajouter un livre \n");
    scanf("%d",&chx);
 if(chx==1){
    f=fopen(nf,"at+");
    f2=fopen("librairie.txt","at+");
    if(f){
        printf("donner le numero, auteur, editeur, titre, stock, prix \n");
        scanf("%d",&e.numero);
        scanf("%s",e.auteur);
        fflush(stdin);
        scanf("%s",e.editeur);
        fflush(stdin);
        scanf("%s",e.titre);
        fflush(stdin);
        scanf("%d%f",&e.stock,&e.prix);
        fwrite(&e,sizeof(Typelivre),1,f);
        fprintf(f2,"livre:\n numero:%d\n auteur: %s\n editeur:%s\n titre:%s\n stock: %d\n prix:%.2f\n",e.numero, e.auteur, e.editeur, e.titre, e.stock, e.prix);
       } 
   fclose(f);
   fclose(f2);
 }
 

 }
 void affichageLivre(char *nf)
 { 
    FILE *f;
    Typelivre e;
    int i=0;
    f=fopen("librairie.bin","rb");
    if(f)
    {
      printf("contenu du fichier:\n");
      while (fread(&e,sizeof(Typelivre),1,f)==1)
      {
         i++;
         printf("LIVRE %d: \n numero:%d\n auteur: %s\n editeur:%s\n titre:%s\n stock: %d\n prix:%.2f\n",e.numero, e.auteur, e.editeur, e.titre, e.stock, e.prix);
      }
      fclose(f);
    } else printf("erreur aff!");
    
 }

  void main()
 {
        ajoutLivre("librairie.bin");
        affichageLivre("librairie.bin");
    

 }
