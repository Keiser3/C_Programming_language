#include<stdio.h>
#include<stdlib.h>
 void main()
 {
    int t[10][10];
    int i,j;
     i=0;
   for (j=0;j<10;j++)
     {
        t[i][j]=1;
     }
     j=0;
    for(i=0;i<10;i++)
    {
        t[i][j]=1;
        j++;
    }
    for(i=1;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            t[i][j]=t[i][j-1]+t[i-1][j-1];
        }
    }

    for(i=1;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            printf("t[%d][%d]: %d\t",i,j,t[i][j]);
        }
    }
 }