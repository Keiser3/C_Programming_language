#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main(){
float *t, r;
int k;
int j;
int pos;
int cpt=0;
int n,i,p;
float moy;
float min,max;
float somme;
printf("Donner le nbre de reels a manipuler:\n");
scanf("%d",&n);
//Allocation dynamique de la memoire
t=(float*)malloc(n*sizeof(float));
if(t==NULL) puts("Probleme d'allocation!!!");
else{
    for(i=0;i<n;i++)
    {
       printf("Donner le reel : %d\n",i+1);
       scanf("%f",(t+i));
    }
    for(i=0;i<n;i++)
    {
      printf("%.2f\t",*(t+i));
    }
//Ajout d'une case dans le tableau: realloc
  t=(float*)realloc(t,(n+1)*sizeof(float));
  if(t==NULL) puts("Erreur reallocation!!!");
   else
   {
      n++;
      printf("Donner un reel et une position:\n");
      scanf("%f%d",&r,&p);
     for(i=n;i>=p;i--)
      {
      *(t+i)=*(t+i-1);
      }
     *(t+p-1)=r;
     for(i=0;i<n;i++)
     {
       printf("%.2f\t",*(t+i));
      }
    }
    //la somme du tableau
    for (i=0;i<n;i++)
    {
      somme+=*(t+i);
    }
    printf("la somme du tableau est: somme=%.2f\n",somme);
    //la moyenne 
    moy=somme/n;
    printf("la moyenne est %.2f\n",moy);
    // min et max 
    max=min=*t;
    for(i=1;i<=n;i++)
    {
        if (*(t+i)> max)
          max= *(t+i);
        else if (*(t+i)<min);
          min= *(t+i);
    }
    printf("le max= %f\n",max);
    printf("le min= %f\n",min);
  //suppression d'une valeur
  printf("\n");
  printf("saisir la position de la valeur que vous voulez supprimer\n");
  scanf("%d",&pos);
     // decalage du tableau
      for (i=pos-1;i<=n;i++)
      {
         *(t+i)=*(t+i+1);
      }
     // suppression de memoire
      t=(float*) realloc (t,(n-1)*sizeof(float));
      n--;
    // affichage apres suppression
     
     for(i=0;i<n;i++)
      {
        printf("%.2f\t",*(t+i));
      }
      printf("\n");
//suppression des double
  for ( i = 0; i < n-1; i ++)  
    {  
        for ( j=i+1;j<n;j++)  
        {  
            
            while ( *(t+i) == *(t+j))  
            {  
                for ( k=j;k<n-1;k++)  
                {  
                    *(t+k)=*(t+k+1);  
                }   
                n--;           
            }  
        }  
    }  
    t=(float*) realloc (t,(n)*sizeof(float));
    printf("Apres suppression des doubles\n");
     for(i=0;i<n;i++)
     {
      printf("%.2f\t",*(t+i));
     }

 //Liberation de memoire allouee par malloc
    free(t);
}
}
