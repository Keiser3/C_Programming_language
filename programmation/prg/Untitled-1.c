#include<stdio.h>
void main()
{
    int A,B,C;
    int min,max,inter;
    int *a,*b,*c;
    int *mi,*ma, *in;
    float moy;
    float *m=&moy;
    int i;
    int *j= &i;
    int somme=0;
    int *s=&somme;
    int fact=1;
    int *f=&fact;
    ma= &max;
    mi= &min;
    in= &inter;
    a=&A;
    b=&B;
    c=&C;

    //lecture des var
    printf("saisir les 3 entier\n");
    scanf("%d%d%d",a,b,c);
    //le max
    min=max=*a;
    if (*b>*ma)
        *ma= *b;
    else if (*c>*ma)
         *ma= *c;
    // le min    
    if (*b<*mi)
       *mi= *b;
    else if (*c<*mi)
       *mi= *c;
    //recherche de la valeur inter
    if(*a>=*mi && *a<=*ma)
       *in = *a;
    if(*b>=*mi && *b<=*ma)
       *in = *b;
    if(*c>=*mi && *c<=*ma)
       *in = *c;  
    
    //affichage
    printf("le min= %d \t le max= %d \t la valeur intermediaire= %d \n", *mi, *ma, *in);
    printf("&A= %X \t &B= %X \t &C= %X \t &min= %X \t &max= %X \t &inter= %X\n",a,b,c,mi,ma,in);

    //egalite
    if (*a==*b+*c)
      printf("A=B+C:\t %d=%d+%d\n",*a,*b,*c);
    else if (*b== *a+*c)
         printf("B=A+C:\t %d=%d+%d\n",*b,*a,*c);
         else if (*c== *a+*b)
              printf("C=A+B:\t %d=%d+%d\n",*c,*a,*b);
               else
                printf(" aucune variables n'est egale a la somme des deux autres\n");
    //moyenne
    *m=(float)(*a+*b+*c)/3;
    printf("la moyenne de A,B et C: %.2f\n",*m);
    //1+2+....+(b-1)+b;
    
    
     for(*j=1 ; *j<=*b ; (*j)++ )
     {
       *s =*s + *j;
     }
    printf("1+2+.....+(b-1)+b= %d",*s);
    // factorielle
    for (*j=1; *j<=*b; (*j)++)
    {
        *f= *f * *j;
    }
    
    
     



}