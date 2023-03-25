#include<stdio.h>
#include<stdlib.h>
 void main()
 {
    int t[20],i,n;
    float moy=0;
    float moy_n=0;
    float moy_p=0;
    int cpt=0;
    int cpt_i=0;
    int min,max;
    int x,e=0;
    float moy_pair, moy_impair;
    do{
        printf("donner le nbr d'entiers a saisir:\n");
        scanf("%d",&n);
    } while (n<0 || n>20);
    //lecture
    for(i=0;i<n;i++)
    {
        printf("saisir l'entier %d du tableau \n",i+1);
        scanf("%d",(t+i));
    }
    //afichage
    for (i=0;i<n;i++)
    {
        printf("t[%d]:%d\t",i+1, *(t+i));
    }
    printf("\n");
    //calcul de la moyenne
    for(i=0;i<n;i++)
    {
        moy+=*(t+i);
    }
    moy/=n;
    printf("la moyenne du tableau = %f",moy);
    //moy element negatif
    for(i=0;i<n;i++)
    {
        if ( *(t+i)<0 )
         {
            moy_n+=*(t+i);
            cpt++;
         }
    }
    printf("\n");
    moy_n/=cpt;
    printf("la moyenne des elements negatif est: %.2f\n",moy_n);
    cpt=0;
    //moy element positifs
    for (i=0;i<n;i++)
    {
        if(*(t+i)>0)
        {
           moy_p+=*(t+i);
           cpt++;
        }
    }
    printf("\n");
    moy_p/=cpt;
    printf("la moyenne des elements positif est: %.2f\n",moy_p);
    cpt=0;
    //min et max
    max=min=*t;
    for(i=1;i<n;i++)
    {
        if (*(t+i)> max)
          max= *(t+i);
        else if (*(t+i)<min);
          min= *(t+i);
    }
    printf("le max= %d\n",max);
    printf("le min= %d\n",min);
    //nbr des 0
    for(i=0;i<n;i++)
    {
        if( *(t+i)==0)
          cpt++;
    }
    printf("le nbr des 0= %d\n",cpt);
    cpt=0;
    //existence de l'entier x
     printf("fournir l'entier que vous souhaiter chercher\n");
     scanf("%d",&x);

     for(i=0;i<n;i++)
     {
       if(*(t+i)== x)
       {
         e=1;
       }
     }
     if (e==1)
        printf("l'entier %d est trouve!\n",x);
      else 
        printf("l'entier %d n'est pas trouve!\n",x);
   //moyenne des impair
     for(i=0;i<n;i++)
     {
        if (*(t+i)%2==0)
         {
            cpt++;
            moy_pair+=*(t+i);
         }
        else 
           cpt_i++;
           moy_impair+=*(t+i);
     }
     if(cpt!=0)
     {
        moy_pair/=cpt;
     }
     if(cpt_i!=0)
     {
        moy_impair/=cpt_i;
     }
     printf("la moyenne des pair est: %.2f\n", moy_pair);
     printf("la moyenne des impairs est: %.2f\n",moy_impair);

     
      

   
     


    
    
 }