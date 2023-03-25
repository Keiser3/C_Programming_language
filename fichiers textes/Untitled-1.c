#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct{
    char platform[20];
    char username[20];
    char password[20];
} compte;
void main()
{   compte *c,co;
    c=&co;
    FILE *f;
    int i,n;                            
    printf("number of accounts./");
    scanf("%d",&n);                                    
    // ecriture: w, wt, a ,at
    //ecriture: wt+ ecrase les donnees != at;
    // putc: write  // getc: lecture   
    //lecture : r, rt;  
    c=(compte *) malloc(n*sizeof(compte)); 

    if (c!=NULL)
    {   
        f=fopen("accounts.txt","at+");
        if (f!=NULL)
        {
          for ( i = 0; i < n; i++)
          {
            printf("Platform Name:\t");
            fflush(stdin);
            fgets((c+i)->platform,20,stdin);
            fflush(stdin);
            printf("\n");
            printf("UserName: \t");
            fgets((c+i)->username,20,stdin);
            fflush(stdin);
            printf("\n");
            printf("Password: \t");
            fgets((c+i)->password,20,stdin);
            fflush(stdin);
            fprintf(f,"ACCOUNT %d/ %s\n +USERNAME ='%s' \n  +PASSWORD ='%s' \n",i+1,(c+i)->platform,(c+i)->username,(c+i)->password);
          }
          fclose(f);
        }
        else printf("File Error!\n");
    }
    else printf("Memory Error!\n");
    free(c);
}