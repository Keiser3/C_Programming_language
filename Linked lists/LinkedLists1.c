#include<stdio.h>
#include<stdlib.h>
//Maillon compte
typedef struct compte{
    int num;
    float solde;
    char CIN[10];
    struct compte *suivant;
} compte;
compte* AjoutDebut(compte *liste){
    compte *c=(compte*) malloc(sizeof(compte));;
    //allocation
    
    //Lecture des donnees
    printf("donner le num, solde et CIN:\n");
    scanf("%d%f%s",&c->num,&c->solde,c->CIN);
    //chainage
    c->suivant=liste;
    liste=c;
    return liste;
}

void AfficherListe(compte* liste){
    compte *c;
    int i=0;
    c=liste;
    while(c!=NULL){
        printf("compte %d: Num:%d\t Solde:%.2f \n CIN:%s\n",++i,c->num,c->solde,c->CIN);
        c=c->suivant;
    }
}

float MoyenneSoldes(compte *liste){
    int i=0;
    float s=0;
    compte *c=liste;
    while(c!=NULL){
        i++;
        s+=c->solde;
        c=c->suivant;
    }
    if(i==0) return 0;
    return s/i;
}
void AugmenteSolde(compte *liste)
{
  compte *c;
  c=liste;
  while(c!=NULL)
  {
    c->solde += (c->solde)*0.2;
    c = c->suivant;
  }

    while(c!=NULL)
    {
      liste->solde = c->solde;
      c = c->suivant;
      liste = liste->suivant;
      
    }
}

void main()
{   
    compte *c;
    int chx=0,i;
    int nbr=0;
    while(chx!=9)
    {
    printf("que voulez vous faire?:\n");
    printf("1\ajouter un compte:\n");
    printf("votre choix:");
    scanf("%d",&chx);
    switch(chx){
    case 1:printf("donner le nombre des compte que vous voulez ajouter?\n");
         scanf("%d",&nbr);
         for(i=0;i<nbr;i++)
         {
            c = AjoutDebut(c); 
         }   
         break;
    case 2:   AugmenteSolde(c);break;  
    case 3:   AfficherListe(c); break;  
    
    
      default:break;
   }
   }
}