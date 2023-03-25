#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 void main()
 {
    FILE *f;
    char chaine[20];
     int i;
    f=fopen("file.txt","at");
    if(f!=NULL)
    {
        printf("la chaine./");
        scanf("%s",chaine);
        fflush(stdin);
      for (i=0;chaine[i]!='\0';i++)
      {
            putc(chaine[i],f);
      }
        fclose(f);    
    }
    else printf("Error!");
    f=fopen("file.txt","rt");
    if(f!=NULL)
    {
        for (i=0;chaine[i]!='\0';i++)
      {   
         chaine[i]=getc(f);
         while (chaine[i]!=EOF)
         {
            printf("%c",chaine[i]);
            chaine[i]=getc(f);
         }
         
      }
         fclose(f);    
       
    } else printf("error!");
   
 }