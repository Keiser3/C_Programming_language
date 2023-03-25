#include<stdio.h>
 void main()
 {
    int t[50],n;
    int s[50],m;
    int r[50];
    int f[50],l;
    int i,j;
    int k;
    int cpt=0;
    int timp[50];
    //lecture de n 
    printf("saisir la taille du tableau T\n");
    scanf("%d",&n);
    //remplissage du tableau t
    for(i=0;i<n;i++)
    {
        printf("donner la valeur %d\n",i+1);
        scanf("%d",(t+i));
    }
    //lecture de m 
    printf("saisir la taille du tableau S\n");
    scanf("%d",&m);
    //remplissage du tableau s
    for(i=0;i<m;i++)
    {
        printf("donner la valeur %d\n",i+1);
        scanf("%d",(s+i));
    }
    //affichage de t
    printf("tableau T:\n");
    for(i=0;i<n;i++)
    {
        printf(" T[%d]= %d \t",i+1,*(t+i));
    }
    printf("\n");
    //affichage de s
    printf("tableau S:\n");
    for(i=0;i<n;i++)
    {
        printf(" S[%d]= %d \t",i+1,*(s+i));
    }
    printf("\n");
    //intersection
    for (i=0;i<n;i++){
        for(j=0;j<m;j++)
         {
            if (*(t+i)==*(s+j))
            {
              *(r+cpt)=*(t+i);
              cpt++;
            }
         }
    }

    //affichage de R
    printf("tableau R:\n");
    for(i=0;i<cpt;i++)
    {
        printf(" R[%d]= %d \t",i+1, *(r+i));
    }
    //elimination des repetition
     for ( i = 0; i < cpt; i ++)  
    {  
        for ( j = i + 1; j < cpt; j++)  
        {    
            if ( *(r+i) == *(r+j))  
            {  
                for ( k = j; k < cpt - 1; k++)  
                {  
                    *(r+k) = *(r+k+1);  
                }  
                cpt--;   
                j--;      
            }  
        }  
    }  
    //affichage de R apres elimination
    printf("\n");
    printf("tableau R apres eliminiation des repetition:\n");
    for(i=0;i<cpt;i++)
    {
        printf(" R[%d]= %d \t",i+1, *(r+i));
    }
    //fusion des deux tableaux
    l=m+n;
    j=0;
    for (i=0;i<n;i++)
    {
       *(f+i)=*(t+i);
    }
    for(i;i<l;i++)
    {
        *(f+i)=*(s+j);
        j++;
    }
    //affichage de F
    printf("\n");
    printf("tableau F:\n");
    for(i=0;i<l;i++)
    {
        printf(" F[%d]= %d \t",i+1, *(f+i));
    }
    //regrouper les impairs
    cpt=0;
    for(i=0;i<l;i++)
    {
        if (*(f+i)%2 != 0)
        {
            *(timp+cpt) = *(f+i);
             cpt++;
        }
    }
    //affichage de timp
    printf("\n");
    printf("tableau timp:\n");
    for(i=0;i<cpt;i++)
    {
        printf(" F[%d]= %d \t",i+1, *(timp+i));
    }
    
 }