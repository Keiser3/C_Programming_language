#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
typedef struct
  {
    int jour;
    int mois;
    int annee;
  } date;
typedef struct
  {
    int cin; // rand
    char nom[20];
    char prenom[20];
    char ville[20];
    int num_permis;
    date ddn;
  } client;
typedef struct
  {
    int matricule; // rand
    char type;
    int loc ;
    float pr_location;
    char marque[20];
    int cpt_l;
    float chiffre;
    date dmc; // date mise en circulation
  } voiture;
typedef struct
  {
    int cin_client;
    int matricule_l; // matricule de la voiture loue
    date date_l;
    float duree_l;
  } location;
void aff_cin(client *c,int x)
{
  int i;
   printf("LISTES DES CIN\n");
   for ( i = 0; i < x; i++)
   {
    printf("#client %d:\n",i+1);
    printf("nom: %s \n",(c+i)->nom);
    printf("\t CIN: %d \n",(c+i)->cin);
   }
  
}
void init_tableau( client *c, voiture *v, location *l,int nbc,int nbv,int nbl)
{   int i,j,k;
    
    for ( i = 0 ; i < nbc; i++)
    {  (c+i)->cin=rand();
       printf("--------->client %d:\n",i+1);
       printf("Nom./");
        scanf("%s",(c+i)->nom);
       printf("\n");
       fflush(stdin);
       printf("prenom./");
        scanf("%s",(c+i)->prenom);
       printf("\n");
       printf("Date de naissance:\n");
       printf("jours./");
        scanf("%d",&(c+i)->ddn.jour);
       printf("\t mois./");
        scanf("%d",&(c+i)->ddn.mois);
       printf("\t\t annee./");
        scanf("%d",&(c+i)->ddn.annee);
        printf("\n");
       printf("ville./");
        scanf("%s",(c+i)->ville);
       printf("\n");
       printf("Numero de permis./");
        scanf("%d",&(c+i)->num_permis);
       printf("\n");
    } 
    for ( i = 0; i < nbv; i++)
    {  (v+i)->matricule = rand() ;
       (v+i)->loc=0;
       printf("--------->voiture %d:\n",i+1);
       printf("Type./");
       fflush(stdin);
        scanf("%c",&(v+i)->type);      
       printf("\n");
       printf("Marque./");
       fflush(stdin);
        scanf("%s",(v+i)->marque);
       printf("\n");
       printf("Date mise en service:\n");
       fflush(stdin);
       printf("jours./");
        scanf("%d",&(v+i)->dmc.jour);
       printf("\t mois./");
        scanf("%d",&(v+i)->dmc.mois);
       printf("\t\t annee./");
        scanf("%d",&(v+i)->dmc.annee);
        printf("\n");
    }
    for ( i = 0; i < nbv; i++)
    {  
        printf("%d\n%d\n%c\n%s\n %d/%d/%d \n",(v+i)->matricule,(v+i)->loc,(v+i)->type,(v+i)->marque,(v+i)->dmc.jour,(v+i)->dmc.mois,(v+i)->dmc.annee);
    }
}
void main()
{
    client cl,*c;
    voiture vo,*v;
    location lo,*l;
    int nbc,nbv,nbl,chx;
    c=&cl;
    v=&vo;
    l=&lo;
    do{
        printf("votre choiX./");
        scanf("%d",&chx);
     }while(chx<1 || chx>19);
    switch (chx)
  {
   case 1:
    srand(time(NULL));
    printf("Nombre de client./");
    scanf("%d",&nbc);
    printf("\n");
    printf("Nombre de voiture./");
    scanf("%d",&nbv);
    printf("\n");
    printf("Nombre de location./");
    scanf("%d",&nbl);
    printf("\n");
    
     c=(client *) malloc(nbc*sizeof(client));
     v=(voiture *) malloc(nbv*sizeof(voiture));
     l=(location *) malloc(nbl*sizeof(location));
     init_tableau(c,v,l,nbc,nbv,nbl);break;
   case 2:
     nbc++;
     c=(client *)realloc(c,nbc*sizeof(client));
           
    
    default:
        break;
  }


}