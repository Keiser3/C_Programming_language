#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_CHAR 300
void main()
{
    char c[MAX_CHAR];
    FILE *f,*f1;
    FILE  *maj,*min,*dig,*sym;
    int i,cpt=0,cptv=0,cptc=0;
    char k,s;

    printf("saisir la chaine de caract%cre\n",138);
    gets(c);
    fflush(stdin);
    f=fopen("string.txt","at+");
    if (f!=NULL)
    {
        for (i=0;c[i]!='\0';i++)
       {
            putc(c[i],f);
       }
       fprintf(f,"\n");
       fclose(f);
    }
    else printf("ERREUR D'OUVERTURE DU FICHIER!");
   /* f=fopen("string.txt","rt");
    if (f!=NULL)
    {
        
         k=getc(f);
         while (k!=EOF)
         {
            printf("%c",k);
            k=getc(f);
         }
         
      
         fclose(f);    
    } else printf("ERREUR!");
    f1=fopen("copy_string.txt","wt");
    if (f1!=NULL)
    {   f=fopen("string.txt","rt");
        if (f!=NULL)
        {
          k=getc(f);
          putc(k,f1);
          while (k!=EOF)
         {
            k=getc(f);
            putc(k,f1);
         }
         fclose(f);
        } else printf("ERREUR DU FICHIER (F)!");
      fclose(f1);    
    } else printf("ERREUR DU FICHIER (F1)!");
    
    f=fopen("string.txt","rt");
    if (f!=NULL)
    {
        k=getc(f);
        while(k!=EOF)
        {
           if (k=='a' || k=='A')
           {
              cpt++;
           }
           k=getc(f);
        }
    fclose(f);
    } else printf("ERREUR!");
    printf("\n");
    printf("Le nombre d'occurence du caract%cre 'a' est : %d \n",138,cpt);
    f=fopen("string.txt","at");
    if (f!=NULL)
    {
      fprintf(f,"nombre d'occurence du caract%cre 'a' : %d\n",138,cpt); 
      fclose(f);   
    } else printf("ERROR!");
    
    f=fopen("string.txt","r+");
    if (f!=NULL)
    {
        k=getc(f);
        while(k!=EOF)
        {
           if (k=='a' || k=='A' || k=='e' || k=='E' || k=='i' || k== 'I' || k== 'o' || k=='O' || k=='u' || k=='U' || k=='y' || k=='Y')
           {
              cptv++;
           }
           k=getc(f);

        }
        fprintf(f,"le nombre de voyelle: %d \n",cptv);
        fclose(f);
    }
     printf("saisir le caract%cre \n",138);
     scanf("%c",&s);
    f=fopen("string.txt","r+");
    if (f!=NULL)
    {
        k=getc(f);
        while(k!=EOF)
        {
           if (k==s || k== s-32)
           {
              cptc++;
           }
           k=getc(f);

        }
        fprintf(f,"le nombre d'occurence du caract%cre '%c': %d \n",138,s,cptc);
        fclose(f);
    }
    */
   f=fopen("string.txt","rt");
	if (f!=NULL)
	{
		maj=fopen("Maj.txt","at");
		min=fopen("Min.txt","at");
		dig=fopen("Digit.txt","at");
		sym=fopen("Symbol.txt","at");
        s=getc(f);
	while(s!=EOF){
        
			if(isalpha(s)){
			  if(isupper(s))
			  {
				putc(s,maj);
			  }
			  else if (islower(s))
			  {
				putc(s,min);
			  }
			 }
			else if(isdigit(s))
			{
				putc(s,dig);
			}
			else
			   {putc(s,sym);}

      s=getc(f);
		}			
		fclose(f);
		fclose(maj);
		fclose(min);
		fclose(dig);
		fclose(sym);
		
	}else printf("erreur du fichier F");
	
}
   

