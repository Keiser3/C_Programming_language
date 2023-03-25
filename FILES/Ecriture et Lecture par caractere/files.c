#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 void main()
 {
    FILE *f;
    char nom[20];
     int i;
    f=fopen("file.txt","at");
    if(f!=NULL)
    {
        printf("Votre nom./");
        scanf("%s",nom);
        fflush(stdin);
      for (i=0;nom[i]!='\0';i++)
      {
            putc(nom[i],f);
      }
        fclose(f);    
    }
    else printf("Error!");
    f=fopen("file.txt","rt");
    if(f!=NULL)
    {
        for (i=0;nom[i]!='\0';i++)
      {   
         nom[i]=getc(f);
         while (nom[i]!=EOF)
         {
            printf("%c",nom[i]);
            nom[i]=getc(f);
         }
         
      }
         fclose(f);    
       
    } else printf("error!");
   
 }