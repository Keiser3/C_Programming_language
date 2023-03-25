#include<stdio.h>
#include<stdlib.h>
int main()
{    
    float t[50];
    int i,n;
    int p;
    int pos;
    float x;
    float val;
    do{
    printf("donner le nbr des reel\n");
    scanf("%d",&n);
    } while(n<0 || n>50);
    for(i=0;i<n;i++)
    {
        printf("donner la valeur %d\n",i+1);
        scanf("%f",(t+i));
    }
    //affichage
    for(i=0;i<n;i++)
    {
        printf(" t[%d]= %.2f \t",i+1,*(t+i));
    }
    printf("\n");
    //lecture de position et valeur
    printf("donner la position p \n");
    scanf("%d",&p);
    printf("donner la valeur que vous souhaitez inserer\n");
    scanf("%f",&x);
    //insertion
      
   for(i = n-1; i > p; i--) {
      *(t+(i+1)) = *(t+i);
   }
    *(t+(p-1)) = x ;
     n++;
    
   for(i=0;i<n;i++)
    {
        printf(" t[%d]= %.2f \t",i+1,*(t+i));

    }
    printf("\n");
    //lecture
     printf("donner la valeur val\n");
     scanf("%f",&val);
    //insertion en ordre croissant
     for(i=0;i<n;i++)
    {
   	
     if(val<*(t+i))
     {
       pos = i;
       break;
     }
     else
      {
     	pos=i+1;
      }
	 }
   
   for(i=n+1;i>=pos;i--)
     {
        *(t+i)=*(t+i-1);
     }
      *(t+pos)=val;
    for(i=0;i<n;i++)
    {
        printf(" t[%d]= %.2f \t",i+1,*(t+i));
    }  



    return 0;
}