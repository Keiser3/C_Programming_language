#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 void main()
 {
    int n,m;
    int *t, *s,*r;
    int cpt;
    int tm,x;
    int i,j;
    srand(time(NULL));
    //TABLEAU T
    printf("saisir le nombre n des entiers du tableau t\n");
    scanf("%d",&n);
    t=(int*) malloc (n*sizeof(int));
    for(i=0;i<n;i++)
{
    if(i==0)
      {
        *(t+i)=rand()%20+1;
      }
     else{
           do{
               x=rand()%20+1;
               tm=0;
                 for(j=0;j<i;j++)
                 {
                    if(x==*(t+j))
                       tm++;
                 }
            }while(tm!=0);
             *(t+i)=x;

         } 
}
   printf("Le tableau T:\n");
     for(i=0;i<n;i++)
     {
      printf("T[%d]: %d \t",i,*(t+i));
     }
     printf("\n");
     //TABLEAU S
    do
    {
      printf("donner le nombre m des entiers du tableau s (M<20)\n");
      scanf("%d",&m);
    } while (m>=20);
     s=(int*) malloc (m*sizeof(int));
     
  for(i=0;i<m;i++)
{
    if(i==0)
      {
        *(s+i)=rand()%20+1;
      }
     else{
           do{
               x=rand()%20+1;
               tm=0;
                 for(j=0;j<i;j++)
                 {
                    if(x==*(s+j))
                       tm++;
                 }
            }while(tm!=0);
             *(s+i)=x;

         } 
}
   printf("Le tableau S:\n");
     for(i=0;i<m;i++)
     {
      printf("S[%d]: %d \t",i,*(s+i));
     }
     printf("\n");
     // INTERSECTION
      for (i=0;i<n;i++)
      {
        for(j=0;j<m;j++)
         {
            if (*(t+i)==*(s+j))
            {
              cpt++;
            }
         }
     }
      r=(int*) malloc (cpt*sizeof(int));
      cpt=0;
      for (i=0;i<n;i++)
      {
        for(j=0;j<m;j++)
         {
            if (*(t+i)==*(s+j))
            {
              *(r+cpt)=*(t+i);
              cpt++;
            }
         }
     }
   printf("L'intersection des deux tableaux:\n");
   for(i=0;i<cpt;i++)
     {
      printf("R[%d]: %d \t",i,*(r+i));
     }
     printf("\n");
 }