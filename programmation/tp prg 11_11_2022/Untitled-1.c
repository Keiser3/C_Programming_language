#include<stdio.h>
#include<stdlib.h>
 void main()
 {
    float *t;
    int n,i;
    printf("donner le nombre des reels\n");
    scanf("%d",&n);
    t=(float*) malloc (n*sizeof(float));
    for (i=0;i<n;i++)
    {
        printf("saisir la valeur %d du tableau T\n",i+1);
        scanf("%f",(t+i));
        t=(float*) realloc (t,(n-1)*sizeof(float));
    }
    t=(int*) realloc (t,(n+1)*sizeof(int))
 }