#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct{
    int j;
    int m;
    int a;
} date;

typedef struct Avion{
    char Mat[20];
    int MaxPl;
    char Etat[12];
    date dms;
    int nbVol;
    struct Avion *next;
}Avion;
Avion *Saisie(){
    int j=0;
    
   Avion *temp = (Avion*) malloc(sizeof(Avion));
   printf("Matricule./ ");
   scanf("%s",temp->Mat);
   fflush(stdin);
   printf("\n");
   printf("Nombre maximum de place./ ");
   scanf("%d",&temp->MaxPl);
   printf("\n");    
  do
   {
      printf("Etat (Decolle, Atterit, Maintenance)");
      scanf("%s",temp->Etat);
      fflush(stdin);
    
   } while (strcmp(temp->Etat,"decolle")!=0&& strcmp(temp->Etat,"atterit")!=0&& strcmp(temp->Etat,"maintenance")!=0);
   printf("Date mise en service:\n");
   printf("jour./");
   scanf("%d",&temp->dms.j);
   printf("\t");
   printf("mois./");
   scanf("%d",&temp->dms.m);
   printf("\t");
   printf("ann%ce./",138);
   scanf("%d",&temp->dms.a);
   printf("\n");
   printf("Nombre de vols./");
   scanf("%d",&temp->nbVol);
   temp->next = NULL;
   
   return temp;
}
void Affichage(Avion *root){
    int i= 1;
    Avion* curr = root;
    while (curr!=NULL)
    {
        printf("Avion %d",i);
        printf("\n");
        printf("Matricule:                 %s\n",curr->Mat);
        printf("Nombre maximum de place:   %d",curr->MaxPl);
        printf("\n");
        printf("Etat:                      %s",curr->Etat);
        printf("\n");
        printf("Date mise en service:      %d/%d/%d \n",curr->dms.j,curr->dms.m,curr->dms.a);
        printf("Nombre De vol:             %d \n",curr->nbVol);
        printf("\n \n");
        i++;
        curr= curr->next;
    }
}
int Size ( Avion *root)
{
  int size = 0;

  while (root != NULL)
    {
      root = root->next;
      size++;
    }
  return size;
}
void AjoutFin(Avion **root){
    int size = Size(*root);
    struct Avion *temp = (struct Avion *) malloc (sizeof (struct Avion));
    temp = Saisie();
     struct Avion *curr = *root;
      while (--size)
	  { 
        curr = curr->next;
      }
      temp->next = NULL;
      curr->next = temp;
}
void ajoutDebut(Avion **root) {
  struct Avion *temp = (struct Avion *) malloc (sizeof (struct Avion));
   temp = Saisie();
   temp->next = *root;
   *root = temp;    
}
void AjoutPos(struct Avion **root,int pos)
{
  int size = Size (*root);

  struct Avion *temp = (struct Avion *) malloc (sizeof (struct Avion));
   temp = Saisie();
  if (pos < 0 || pos > size)
    printf ("Position n'existe pas\n");
  else if (pos == 0)
    {
      temp->next = *root;
      *root = temp;
    }
  else
    {
      struct Avion *curr = *root;
      while (--pos)
	   {
        curr = curr->next;
       }
     temp->next = curr->next;
     curr->next = temp;
    }
}
void SuppDebut(Avion **root){
    struct Avion *temp = (struct Avion *) malloc (sizeof (struct Avion));
    temp = *root;
    temp = temp->next;
    *root = temp;
}
void SuppFin(Avion **root){
    int size = Size(*root);
    int pos=0;
    struct Avion *curr = (struct Avion *) malloc (sizeof (struct Avion));
    curr = *root;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    curr->next = NULL;
}
void SuppPos(struct Avion **root,int pos)
{
  int size = Size (*root);
  struct Avion *temp = (struct Avion *) malloc (sizeof (struct Avion));
  struct Avion *prev = (struct Avion *) malloc (sizeof (struct Avion));
  if (pos < 0 || pos > size)
    printf ("Position n'existe pas\n");
  else if (pos == 0)
    {
       temp = *root;
       temp = temp->next;
      *root = temp;
    }
  else
    {
      temp = *root;
      while (--pos){
         prev = temp;
	     temp = temp->next;
       }
       prev->next = temp->next;
    }
}
int Exist(Avion *root,char Mat[]){
    Avion *curr = (Avion*) malloc(sizeof(Avion));
    curr = root;
    while(curr->next != NULL){
        if(strcmp(curr->Mat,"atterit")==0 || strcmp(curr->Mat,"maintenance")==0){
            curr->next = NULL;
            Affichage(curr);
            return 1;
        }
        else 
           return -1;
    }
}
int Age(date *dms){
  time_t seconds=time(NULL);
  struct tm* current_time=localtime(&seconds);
  int currYear = current_time->tm_year + 1900 ; 
  
  return currYear - dms->a;
}
int ManTechnique(Avion *root,char MAt[]){
    Avion *curr = (Avion*) malloc(sizeof(Avion));
    curr = root;
    while (curr->next != NULL)
    {
        if (strcmp(curr->Mat,MAt)==0 && strcmp(curr->Etat,"maintenance"))
        {   
            return 1;
        }
        curr = curr->next;
    }
    return 0;
    
}
void SuppAge(Avion **root)
{
  int size = Size (*root);
  struct Avion *temp = ( Avion *) malloc (sizeof ( Avion));
  struct Avion *prev = ( Avion *) malloc (sizeof (Avion));
  int cpt=0;
  char Mat[20];
  
      temp = *root;
      while (temp->next!=NULL){
         *Mat = *temp->Mat;
         if(ManTechnique(temp,Mat)==1 && Age(&temp->dms)>20){
            if(cpt==0){
                temp = temp->next;
                *root = temp;
            }
            else{
                prev = temp->next;
                temp = prev;
            }
         }
         prev=temp;
         temp=temp->next;
         cpt++; 
       }
    }

int NbAtterit(Avion *root){
     struct Avion *temp = (Avion *) malloc (sizeof ( Avion));
     int cpt=0;
     temp = root;
     while(temp->next != NULL){
        if(strcmp(temp->Etat,"atterit")==0){
            cpt++;
        }
     }
    return cpt;
}
int NbDecolle(Avion *root){
     struct Avion *temp = (Avion *) malloc (sizeof ( Avion));
     int cpt=0;
     temp = root;
     while(temp->next != NULL){
        if(strcmp(temp->Etat,"decolle")==0){
            cpt++;
        }
     }
    return cpt;
}
int NbMaintenance(Avion *root){
     struct Avion *temp = (Avion *) malloc (sizeof ( Avion));
     int cpt=0;
     temp = root;
     while(temp->next != NULL){
        if(strcmp(temp->Etat,"maintenance")==0){
            cpt++;
        }
     }
    return cpt;
}
void Pourcentage(Avion *root,char Etat[]){
    if(strcmp(Etat,"maintenance")==0){
        printf("Pourcentage des avions %s : %.2f%c\n",Etat,(NbMaintenance(root)*100)/Size(root),37);
    }
    else if(strcmp(Etat,"atterit")==0){
        printf("Pourcentage des avions %s : %.2f%c\n",Etat,(NbAtterit(root)*100)/Size(root),37);
    }
    else 
      printf("Pourcentage des avions %s : %.2f%c\n",Etat,(NbDecolle(root)*100)/Size(root),37);
}
void MaxVol(Avion *root){
    struct Avion *temp = (Avion *) malloc (sizeof ( Avion));
    int nbMax=0;
    temp = root;
    while (temp->next!=NULL)
    {
        if(Age(&temp->dms)<10){
            if(temp->nbVol>nbMax){
                nbMax = temp->nbVol;
            }
        }
        temp = temp->next;
    }
    temp=root;
    while (temp->next!=NULL)
    {
        if(temp->nbVol == nbMax){
           temp->next = NULL;
           Affichage(temp);
        }
        temp->next = temp;
    }
    
}
void MinVol(Avion *root){
    struct Avion *temp = (Avion *) malloc (sizeof ( Avion));
    int nbMin;
    temp = root;
    nbMin = temp->nbVol;
    while (temp->next!=NULL)
    {
        if(Age(&temp->dms)<10){
            if(temp->nbVol<nbMin){
                nbMin = temp->nbVol;
            }
        }
        temp = temp->next;
    }
    while (temp->next!=NULL)
    {
        if(temp->nbVol == nbMin){
           temp->next = NULL;
           Affichage(temp);
        }
        
    }
    
}

void Menu(){
    printf("Que voulez vous faire: \n");
    printf("1./Ajout Debut \n");
    printf("2./Ajout Fin \n");
    printf("3./Ajout Position \n");
    printf("4./Afficher la liste\n");
    printf("5./Suppression Debut \n");
    printf("6./Suppression Fin \n");
    printf("7./Suppression Position\n");
    printf("8./verifier si un Avion est dans l'A%croport\n ",138);
    printf("9./suppression des avions ag%ce +20ans\n",138);
    printf("10./Nombre totale des avions\n");
    printf("11./Nombre des avions atterit\n");
    printf("12./Nombre des avions decolle\n");
    printf("13./Nombre des avions en maintenance\n");
    printf("14./Afficher pourcentage des avions\n ");
    printf("15./ Avion ayant assur%c le nombre maximale des vols\n",138);
    printf("16./ Avion ayant assur%c le nombre minimale des vols\n ",138);
    printf("99./ Quitter \n");
    printf("votre choix./");
}

void main(){
    Avion *root = (Avion*) malloc(sizeof(Avion));
    int chx,pos;
    char Mat[20];
    char Etat[20];
    printf("Details du premier avion:\n");
    root = Saisie();
    while (1)
    {
        Menu();
        scanf("%d",&chx);
        switch (chx){
            case 1: ajoutDebut(&root);break;
            case 2: AjoutFin(&root);break;
            case 3:{
                printf("La position./");
                scanf("%d",&pos);
                printf("\n");
                AjoutPos(&root,pos);break;
            }
            case 4: Affichage(root);break;
            case 5: SuppDebut(&root);break;
            case 6: SuppFin(&root);break;
            case 7:{
                printf("La position./");
                scanf("%d",&pos);
                printf("\n");
                SuppPos(&root,pos);break;
            }
            case 8:{
                printf("La Matricule./");
                scanf("%s",Mat);
                printf("\n");
                SuppPos(&root,*Mat);break;
            }
            case 9:SuppAge(&root);
            case 10: printf("Le nombre des Avions: %d\n",Size(root)); break;
            case 11: printf("Le nombre des Avions Atterit: %d\n",NbAtterit(root)); break;
            case 12: printf("Le nombre des Avions Decolle: %d\n",NbDecolle(root)); break;
            case 13: printf("Le nombre des Avions en Maintenance: %d\n",NbMaintenance(root)); break;
            case 14:{ 
                printf("L'Etat./");
                scanf("%s",Etat);
                printf("\n");
                Pourcentage(root,Etat);break;
              }
            case 15: MaxVol(root);
            case 16: MinVol(root);
            case 99: exit(0);
            
            
            default: break;
        }
    }
    
 }