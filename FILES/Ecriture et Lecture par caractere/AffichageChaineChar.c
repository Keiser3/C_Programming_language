#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCHAR 200
// mode ecriture: w, wt, a, at;
// mode lecture: r, rt;
 void main()
 {
    FILE *f;
    char chaine[MAXCHAR];
    char c;
     int i;
    f=fopen("FileExemple.txt","at");
    if(f!=NULL)
    {
        printf("la chaine./");
        gets(chaine);
        fflush(stdin);
      for (i=0;chaine[i]!='\0';i++)
      {
            putc(chaine[i],f);
      }
      
        fclose(f);    
    }
    else printf("Error!");
    f=fopen("FileExemple.txt","rt");
    if(f!=NULL)
    {
    
         c=getc(f);
         while (c!=EOF)
         {
            printf("%c",c);
            c=getc(f);
         }
         
      
         fclose(f);    
       
    } else printf("error!");
   
 }