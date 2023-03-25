#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t[30][30];

    int i ,j,n;
    do
    {
        printf("donner le nbre de lignes: \n");
       scanf("%d", &n);
    } while (n>30);
    
    
    
    for (i=0;i<n;i++) {
        for (j=0;j<n-1-i;++j)
            printf("\t");

        for(j=0;j<=i;++j) {
            if (j==0||j==i)
                *(*(t+i)+j)=1;
            else
                *(*(t+i)+j) = *(*(t+i-1)+j-1)+*(*(t+i-1)+j) ;  
            printf("%d\t",*(*(t+i)+j));
        }
        printf("\n");
    }
    return 0;
}

