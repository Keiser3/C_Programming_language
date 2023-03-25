#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 void main()
 {
  int i=0;
  int cpt=1;
  int cpt_e=0;
  int cpt_E=0;
  int cpt_spc=0;
  int l=0;
  char c[100];
  printf("saisir la phrase\n");
  gets(c);
  
  while (c[i]!='\0')
  {
     if (c[i]==' ' || c[i]=='\n' || c[i]=='\t')
      {
          cpt++;
      }
      i++;
  }
  printf("%d\n",cpt);
   l=strlen(c);
   printf("le nombre de caractere est:%d \n",l);
 i=0;
  while(c[i]!='\0')
  {
      if (c[i]>='a' && c[i]<='z')
        c[i]-=32;
      else if (c[i]>='A' && c[i]<='Z')
       { c[i]+=32;
       }
        
    i++;
  }
  puts(c);
  
 i=0;

  while(c[i]!='\0')
  {
      if (c[i]=='E')
        cpt_E++;
      else if (c[i]=='e')
        cpt_e++;
       else if(c[i]==' ' || c[i]=='\n' || c[i]=='\t')
        cpt_spc++;
        i++;
  }
  printf("le nombre des 'E':%d\n",cpt_E);
  printf("le nombre des 'e':%d\n ",cpt_e);
  printf("le nombre des espaces: %d\n",cpt_spc);

 }
