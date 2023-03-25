#include<stdio.h>
 void main()
 {
    int t[50],n,i;
    int p,a;
    int r;
    int j, d;
    
    printf("saisir le nbr des entiers\n ");
    scanf("%d",&n);
    //remplissage
    for(i=0;i<n;i++)
    {
        printf("donner la valeur %d\n",i+1);
        scanf("%d",(t+i));
    }
    //affichage
    for(i=0;i<n;i++)
    {
        printf(" t[%d]= %d \t",i+1,*(t+i));
    }
    
    //lecture de position et valeur
    printf("\n");
    printf("donner la position p \n");
    scanf("%d",&p);
    printf("donner la valeur que vous souhaitez inserer\n");
    scanf("%d",&a);
    //insertion
      
   for(i = n-1; i > p; i--) {
      *(t+(i+1)) = *(t+i);
   }
    *(t+(p-1)) = a ;
     n++;
    
   for(i=0;i<n;i++)
    {
        printf(" t[%d]= %d \t",i+1,*(t+i));

    }
    printf("\n");
    //lecture n de rotation
    printf("saisir le nombre de case de rotation\n");
    scanf("%d",&r);
    //rotation
    for(i = 0; i < r; i++){    
            
           
        d = *(t+n-1);    
        
        for(j = n-1; j > 0; j--){    
                
            *(t+j) = *(t+j-1);    
        }    
         
        *t = d;    
    }    
    //affichage apres rotation
    for(i=0;i<n;i++)
    {
        printf(" t[%d]= %d \t",i+1,*(t+i));
    }
        
    printf("\n");    
 }