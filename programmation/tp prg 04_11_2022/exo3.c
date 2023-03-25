#include <stdio.h>    
     
int main()    
{  int t[50],i,n;
   int x;
   int pos;
    printf("saisir le nbr des entiers\n ");
    scanf("%d",&n);
     
//remplissage
    printf("donner la valeur 1 \n");
    scanf("%d", &t[0]);
    for(i=1;i<n;i++)
    { 
          do{
             printf("donner la valeur %d\n",i+1);
             scanf("%d",(t+i));
           } while (*(t+i)<*(t+i-1));   
    }
 //affichage
    for(i=0;i<n;i++)
    {
        printf(" t[%d]= %d \t",i+1,*(t+i));
    }
//insertion
    printf("\n");
    printf("donner la valeur que vous vouler inserer\n");
    scanf("%d",&x);

 for(i=0;i<n;i++)
     {
      if(*(t+i)>=x)
       {
        pos=i;break;
       } 
     }
  

    
  for(i=n;i>=pos;i--)
    {
       *(t+i)=*(t+i-1);
    }
     *(t+pos)=x;
     n++;
//affichage
  for(i=0;i<n;i++)
    {
        printf(" t[%d]= %d \t",i+1,*(t+i));
    }
}   
    