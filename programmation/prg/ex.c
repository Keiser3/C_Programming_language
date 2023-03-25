#include<stdio.h>
#include<stdlib.h>
 int somme(int a,int b)
 {
    return a+b;
 }
 int produit(int a,int b)
 {
    return a*b;
 }
 float division(int a,int b)
 {  
    return (float)a/b;
 }
 

 void main()
 {
    int a,b;
    int chx;
    printf("fournir respectivement les deux entiers a et b\n");
    scanf("%d%d",&a,&b);
    printf("que voulez vous faire?\n");
     printf("1: somme\n");
     printf("2: produit\n");
     printf("3: division\n");
    printf("votre choix:");
    scanf("%d",&chx);
    switch (chx)
    {
    case 1: printf("%d + %d = %d",a,b,somme(a,b)); break;
    case 2: printf("%d * %d = %d",a,b,produit(a,b)); break;
    case 3: if (b==0)
            {
                printf("ERROR\n");break;
            }
            else 
             printf("%d / %d = %.2f\n",a,b,division(a,b));break;
    default:
        break;
    }


 }