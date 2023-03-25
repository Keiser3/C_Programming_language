#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
    float re;
    float im;
} complex;
 void main()
 {  
    int p;
   int n,i;
   float *t;
   float sre,sim;
   complex c1,*c2;
   complex n1,*n2;
   n2=&n1; 
   c2=&c1;
   printf("saisir le nbre des complex:\n");
   scanf("%d",&n);
   c2=(complex*)malloc(n*sizeof(complex));
   
    for (i=0;i<n;i++)
    {
       printf("saisir la partie reel du complex %d\n",i+1);
       scanf("%f",&(c2+i)->re);
       printf("saisir la partie imaginaire du complex %d\n",i+1);
       scanf("%f",&(c2+i)->im);    
    }
    for (i=0;i<n;i++)
    {
        printf("c%d=%.2f+i*%.2f \n",i+1,(c2+i)->re,(c2+i)->im);
    }
    for (i=0;i<n;i++)
    {
        sre+=(c2+i)->re;
        sim+=(c2+i)->im;
    }
    printf("la somme des complex cs=%.2f+i*%.2f ",sre,sim);
   //calcul de la norme
   t=(float*)malloc(n*sizeof(float));
    for (i=0;i<n;i++)
    {
        *(t+i)= sqrt(pow((c2+i)->re,2)+pow((c2+i)->re,2));
    }
     for (i=0;i<n;i++)
    {
         printf("|c%d|= %.2f \n",i+1,*(t+i));
    }
    printf("saisir la position\n");
    scanf("%d",&p);
     printf("saisir la partie reel et la partie imaginaire\n");
     scanf("%f%f",&n2->re,&n2->im);
     n++;
     c2=(complex*) realloc(c2,n*sizeof(complex));
    
         for (i = n - 1; i > p; i--)
       {
         *(c2 + (i + 1)) = *(c2 + i);
      }
        *(c2+p-1)=*(n2);

     for (i=0;i<n;i++)
    {
        printf("c%d=%.2f+i*%.2f \n",i+1,(c2+i)->re,(c2+i)->im);
    }
      printf("saisir la position de l'element que vous voulez supprimer\n");
      scanf("%d",&p);
         for (i = n - 1; i > p; i--)
       {
         *(c2 + (i + 1)) = *(c2 + i);
      }

    for (i=0;i<n;i++)
    {
      printf("complex %d : %f+%fi",i,(c2+i)->re,(c2+i)->im);
    }
  }
  