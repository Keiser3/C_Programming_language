#include<stdio.h>
#include<stdlib.h>

void permute(int *,int *);
void main()
{
    int a,b;
    printf("saisir les valeur de a et b");
    scanf("%d%d",&a,&b);
    printf(" avant permutation: \n");
    printf(" a= %d \t",a);
    printf("b= %d \n",b);
    permute(&a,&b);
    printf(" apres permutation: \n");
    printf(" a= %d \t",a);
    printf("b= %d ",b);
    

}

void permute( int *x,int *y)
{
    int c;
    c= *x;
    *x= *y;
    *y=c;
    
}
