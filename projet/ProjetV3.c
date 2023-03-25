#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include<windows.h>
//declaration des structures
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
void main();
void menu(void);
void init_voiture(voiture*,int);
void init_client(client*,int);
void init_location( client *, voiture *, location *,int , int , int );
void add_voiture( voiture *,int,int);
void add_client(client *,int,int);
void add_location( client *, voiture *, location *,int , int , int ,int);
void aff_cin(client *,int);
void aff_matricule(voiture *,int);
void aff_voiture(voiture *,int,int);
void aff_client(client *,int,int);
void aff_location(client *,voiture *,location *,int,int,int,int);
void supp_client(client *,int);
void supp_voiture(voiture *,int);
void supp_contact(client *,int);
int cpt_contact(client *,int);
void chiff_aff(voiture *,int );
void pgrand_chiffre(voiture *,int );
void init_tab_cin(client *,location *,location *,int,int,int);
void init_tab_mat(voiture *,location *,location *,int,int,int);
void main()
{
    int ch, chx, i;
    int n;
    int pos = 0;
    int  nbc;
    int  nbv;
    int nbl2;
    int  nbl;
    int nbl3;
    voiture vo, *v;
    client cl, *c;
    location lo, *l;
     location lo2,*l2;
     location lo3,*l3;
    c=&cl;
    v=&vo;
    l=&lo;
    l2=&lo2;
    l3=&lo3;


    menu();
    printf("votre choix./ ");
    scanf("%d", &chx);
    switch (chx)
    {
    case 1:
        printf("Nombre de client./ ");
        scanf("%d", &nbc);
        printf("\n");

        printf("Nombre de voiture./ ");
        scanf("%d", &nbv);
        printf("\n");

        printf("Nombre de location./ ");
        scanf("%d", &nbl);
        printf("\n");
        init_voiture(v,nbv);
        init_client(c,nbc);
        init_location(c,v,l,nbc,nbv,nbl);

        break;
    case 2:
        nbc++;
        c=(client *)realloc(c,nbc*sizeof(client));
        printf("\t 1. A une position donnee?\n");
        printf("\t 2. vers la fin?\n");
        printf("./");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("La position./");
            scanf("%d", &pos);
            add_client(c,nbc,pos);
            menu();
            main();

        }
        else if (ch == 2)
        {
            pos=nbc;
            add_client(c,nbc,pos);
            menu();
            main();
        }
    case 3:
        nbv++;
        v=(voiture *)realloc(v,nbv*sizeof(voiture));
        printf("\t 1. A une position donnee?\n");
        printf("\t 2. vers la fin?\n");
        printf("./");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("La position./");
            scanf("%d", &pos);
            add_voiture(v,nbv,pos);
            menu();
            main();



        }
        else if (ch == 2)
        {
            pos=nbv;
            add_voiture(v,nbv,pos);
            menu();
            main();
        }
    case 4:
        nbl++;
        l=(location *)realloc(l,nbl*sizeof(location));
        printf("\t 1. A une position donnee?\n");
        printf("\t 2. vers la fin?\n");
        printf("./");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("La position./");
            scanf("%d", &pos);
            add_location(c,v,l,nbc,nbv,nbl,pos);
            getch();
            menu();
            main();

        }
        else if (ch == 2)
        {
            pos=nbl;
            add_location(c,v,l,nbc,nbv,nbl,pos);
            getch();
            menu();
            main();
        }
      case 5:
          printf("1. Toutes les voitures?\n ");
          printf("2. Par marque?\n");
          printf("3. Par type\n");
          printf("votre choix./");
          scanf("%d",&ch);
          aff_voiture(v,nbv,ch);
           getch();
            menu();
            main();
      case 6:
         printf("\t a. Tous les clients?\n ");
         printf("\t b. Par CIN?\n");
         printf("\t c. Par ville\n");
          printf("votre choix./");
          scanf("%d",&ch);
          aff_client(c,nbc,ch);
           getch();
            menu();
            main();
      case 7:
        printf("\t a. Par client(nom)?\n ");
        printf("\t b. Par voiture (matricule)?\n");
        printf("\t c. Par duree\n");
        printf("\t d. Par date de location\n");
        printf("votre choix./");
        scanf("%d",&ch);
        aff_location(c,v,l,nbc,nbv,nbl,ch);
         getch();
            menu();
            main();
      case 8:
        aff_location(c,v,l,nbc,nbv,nbl,4);
         getch();
            menu();
            main();
      case 9:
        supp_client(c,nbc);
         getch();
            menu();
            main();
      case 10:
        supp_voiture(v,nbv);
         getch();
            menu();
            main();
      case 11:
        supp_contact(c,nbc);
         getch();
            menu();
            main();
      case 12:
       n= cpt_contact(c,nbc);
       printf("nombre de contact: %d \n",n);
         getch();
            menu();
            main();
      case 13:
       chiff_aff(v,nbv);
         getch();
         menu();
         main();
      case 14:
       pgrand_chiffre(v,nbv);
       getch();
       menu();
       main();
      case 15:
       init_tab_cin(c,l,l2,nbc,nbl,nbl2);
       getch();
       menu();
       main();
      case 16:
       init_tab_mat(v,l,l3,nbv,nbl,nbl3);
       getch();
       menu();
       main();
    default:
        break;
    }
}
void menu()
{

	printf("        ____   ____    ___  ___  ___   ___     __   ___         ___   ___  ___   ___   ___   ___   ___       \n");
	printf("       |____| |   ___ |___  | | |     |___    |  | |___   |    |   | |    |___|   |     |   |   |  | |         \n");
	printf("       |    | |____|  |___  | | |___  |___    |__/ |___   |___ |___| |___ |   |   |    _|_  |___|  | |        \n\n\n\n\n");

	printf(" _______________________________________________Menu______________________________________________________ \n ");
	printf("|                                                                                                        |\n ");
    printf("|1.initialisation des tableaux                                                                           |\n ");
    printf("|2.ajout d'un nouveau client:                                                                            |\n ");
    printf("|a. A une position donnee?                                                                               |\n ");
    printf("|b. vers la fin?                                                                                         |\n ");
    printf("|3.ajout d'une nouvelle voiture:                                                                         |\n ");
    printf("|a. A une position donnee?                                                                               |\n ");
    printf("|b.vers la fin?                                                                                          |\n ");
    printf("|4. ajout d'une nouvelle location:                                                                       |\n ");
    printf("|a. A une position donnee?                                                                               |\n ");
    printf("|b.vers la fin?                                                                                          |\n ");
    printf("|5. Affichage de la liste des voitures:                                                                  |\n ");
    printf("|a. Toutes les voitures?                                                                                 |\n ");
    printf("|b. Par marque?                                                                                          |\n ");
    printf("|c. Par ville                                                                                            |\n ");
    printf("|5. Affichage de la liste des clients:                                                                   |\n ");
    printf("|a. Tous les clients?                                                                                    |\n ");
    printf("|b. Par CIN?                                                                                             |\n ");
    printf("|3. Par ville                                                                                            |\n ");
    printf("|5. Affichage de la liste des locations:                                                                 |\n ");
    printf("|a. Par client(nom)?                                                                                     |\n ");
    printf("|b. Par voiture (matricule)?                                                                             |\n ");
    printf("|c. Par duree                                                                                            |\n ");
    printf("|d. Par date de location                                                                                 |\n ");
    printf("|8. Affichage de la liste des clients dont le nom par une lettre donnee                                  |\n ");
    printf("|9. Suppression d'un client par CIN                                                                      |\n ");
    printf("|10. Supprimer une voiture par son numero d'immatriculation                                              |\n ");
    printf("|11. Supprimer tous les contacts d'une ville donnee                                                      |\n ");
    printf("|12. Compter le nombre de contacts d'une ville donnee                                                    |\n ");
    printf("|13. Le chiffre realise par une voiture donnee                                                           |\n ");
    printf("|14. Afficher les informations de la voiture ayant realise le chiffre le plus eleve                      |\n ");
    printf("|15. Creer un nouveau tableau representant les locations d'un client donne                               |\n ");
    printf("|16. Creer un nouveau tableau des locations d'une voiture donnee                                         |\n ");
    printf("|17. Exporter les locations d'un client vers un fichier texte                                            |\n ");
    printf("|a. Fonction d'affichage de ce fichier                                                                   |\n ");
    printf("|18. Exporter les voitures ayant un prix de location donne vers un fichier binaire                       |\n ");
    printf("|a. Fonction d'affichage de ce fichier                                                                   |\n ");
    printf("|19. Quitter                                                                                             |\n ");
	printf("|________________________________________________________________________________________________________| \n  ");





}
void init_voiture(voiture *v,int y)
{   int i,j,tm,t;
   srand(time(NULL));
    v = (voiture *)malloc(y * sizeof(voiture));
    for ( i = 0; i < y; i++)
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

    }
}
void init_client(client *c,int x)
{   int i;
    srand(time(NULL));
    c = (client *)malloc(x * sizeof(client));

    for ( i = 0; i < x; i++)
    {   (c+i)->cin=rand();
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
    }
}
void init_location( client *c, voiture *v, location *l,int x , int y, int z)
{
    int i,j,k;
    int n;
    int cin,mat;
    aff_cin(c,x);
    aff_matricule(v,y);
    for(i=0;i<z;i++)
    { printf("*******LOCATION %d",i+1);
      printf("\n");
       printf("CIN du client./");
       scanf("%d",&cin);
       for(j=0;j<x;j++)
        {
         if(cin == (c+j)->cin)
         {
           (l+i)->cin_client = cin;

            break;
         }
        }
         if(j==x)
         {
            printf("ERREUR: client introuvable!\n");
            printf("ressayer?(1/0)./");
            scanf("%d",&n);
             if(n==1)
              {
                 init_location(c,v,l,x,y,z);
              }
             else
                menu();
                main();
         }
       printf("Matricule de la voiture./");
       scanf("%d",&mat);
       for(k=0;k<y;k++)
        {
         if(mat == (v+k)->matricule)
         {
           (l+i)->matricule_l = mat ;
            (v+k)->cpt_l++;
            break;
         }
        }
         if(k==y)
         {
            printf("ERREUR: voiture introuvable!\n");
            printf("ressayer?(1/0)./");
            scanf("%d",&n);
             if(n==1)
              {
                 init_location(c,v,l,x,y,z);
              }
             else
                menu();
                main();
         }
       printf("Date de location:\n");
       printf("jours./");
        scanf("%d",&(l+i)->date_l.jour);
       printf("\t mois./");
        scanf("%d",&(l+i)->date_l.mois);
       printf("\t annee./");
        scanf("%d",&(l+i)->date_l.annee);
       printf("\n");
       printf("Duree de location (en jours)./");
        scanf("%d",&(l+i)->duree_l);

     }
  menu();
  main();

}
void aff_cin(client *c,int x)
{
  int i;
   printf("LISTES DES CIN\n");
   for ( i = 0; i < x; i++)
   {
    printf("#client %d:\n",i+1);
    printf("\t CIN: %d \n",(c+i)->cin);
   }

}
void aff_matricule(voiture *v,int y)
{
   int i;
   printf("LISTES DES MATRICULES\n");
   for ( i = 0; i < y; i++)
   { printf("#voiture %d:\n",i+1);
     printf("\t MATRICULE %d \n",(v+i)->matricule);
   }
}
void add_voiture(voiture *v,int y,int p)
{ voiture t;
   int i;
   srand(time(NULL));
    t.matricule=rand();
    scanf("%c",&t.type);
    fflush(stdin);
    t.loc=0;
    printf("prix de location./ ");
    scanf("%f",&t.pr_location);
    printf("\n");
    printf("Marque./");
    gets(t.marque);
    fflush(stdin);
    printf("date mise en service :\n");
    printf("jours./");
    scanf("%d",&t.dmc.jour);
    printf("\t");
    printf("mois./");
    scanf("%d",&t.dmc.mois);
    printf("\t");
    printf("annee./");
    scanf("%d",&t.dmc.annee);
    printf("\n");

  for(i=y;i>=p;i--)
  {
    *(v+i)=*(v+i-1);
  }
    *(v+p)=t;



 menu();
 main();

}
void add_client(client *c,int x,int p)
{  client t;
    int i;
    srand(time(NULL));
     t.cin=rand();
     printf("Nom./");
        scanf("%s",t.nom);
       printf("\n");
       fflush(stdin);
       printf("prenom./");
        scanf("%s",t.prenom);
       printf("\n");
       printf("Date de naissance:\n");
       printf("jours./");
        scanf("%d",&t.ddn.jour);
       printf("\t mois./");
        scanf("%d",&t.ddn.mois);
       printf("\t\t annee./");
        scanf("%d",&t.ddn.annee);
        printf("\n");
       printf("ville./");
        scanf("%s",t.ville);
        fflush(stdin);
       printf("\n");
       printf("Numero de permis./");
        scanf("%d",&t.num_permis);



  for(i=x;i>=p;i--)
  {


   *(c+i)=*(c+i-1);
  }
   *(c+p)= t;

  menu();
  main();
 }
void add_location(client *c, voiture *v, location *l, int x, int y, int z, int p)
{
   location t;
   int cin,mat;
   int i,j,n;

   aff_cin(c,x);
   aff_matricule(v,y);
   printf("cin du client./");
   scanf("%d",&cin);
       for(j=0;j<x;j++)
        {
         if(cin == (c+j)->cin)
         {
           t.cin_client = cin; break;
         }
        }
         if(j==x)
         {
            printf("ERREUR: client introuvable!\n");
            printf("ressayer?(1/0)./");
            scanf("%d",&n);
             if(n==1)
              {
                 add_location(c,v,l,x,y,z,p);
              }
             else
                menu();
                main();
         }
        printf("\n");
       printf("matricule de la voiture./");
       scanf("%d",&mat);
          for(j=0;j<y;j++)
        {
         if(mat == (v+j)->matricule)
         {
           t.matricule_l = mat ; break;
         }
        }
         if(j==y)
         {
            printf("ERREUR: voiture introuvable!\n");
            printf("ressayer?(1/0)./");
            scanf("%d",&n);
             if(n==1)
              {
                 add_location(c,v,l,x,y,z,p);
              }
             else
                menu();
                main();
         }
           printf("Date de location:\n");
       printf("jours./");
        scanf("%d",&t.date_l.jour);
       printf("\t mois./");
        scanf("%d",&t.date_l.mois);
       printf("\t annee./");
        scanf("%d",&t.date_l.annee);
       printf("\n");
       printf("Duree de location (en jours)./");
        scanf("%d",&t.duree_l);

    for(i=z;i>=p;i--)
  {


   *(l+i)=*(l+i-1);
  }
   *(l+p) = t;

  menu();
  main();

}
void aff_voiture(voiture *v,int y, int ch)
{ int i;
  char marque[20];
  char type;
  if(ch==1)
  {
    for (i=0;i<y;i++)
    {
      printf("########## voiture %d\n",i+1);
        printf("\t matricule:%d \n",(v+i)->matricule);
        printf("\t type: %c \n",(v+i)->type);
        printf("\t prix de location: %.2f \n",(v+i)->pr_location);
        printf("\t Marque: %s \n",(v+i)->marque);
        printf("\t date mise en service: %d/%d/%d\n",(v+i)->dmc.jour,(v+i)->dmc.mois,(v+i)->dmc.annee);
        printf("\n");
    }
  }
  else if (ch==2)
       {
         printf("la marque ./");
         scanf("%s",marque);
         for(i=0;i<y;i++)
           {
              if (marque==(v+i)->marque)
              {
                printf("\t matricule:%d \n",(v+i)->matricule);
                printf("\t type: %c \n",(v+i)->type);
                printf("\t prix de location: %.2f \n",(v+i)->pr_location);
                printf("\t Marque: %s \n",(v+i)->marque);
                printf("\t date mise en service: %d/%d/%d\n",(v+i)->dmc.jour,(v+i)->dmc.mois,(v+i)->dmc.annee);
                printf("\n");
              }
           }
      }
        else {
          printf("Le type./ ");
          scanf("%c",&type);
           for(i=0;i<y;i++)
           {
              if (type==(v+i)->type)
              {
                printf("\t matricule:%d \n",(v+i)->matricule);
                printf("\t type: %c \n",(v+i)->type);
                printf("\t prix de location: %.2f \n",(v+i)->pr_location);
                printf("\t Marque: %s \n",(v+i)->marque);
                printf("\t date mise en service: %d/%d/%d\n",(v+i)->dmc.jour,(v+i)->dmc.mois,(v+i)->dmc.annee);
                printf("\n");
              }
           }
        }
}
void aff_client(client *c,int x,int ch)
{
   int i,j;
   int cin;
   char s;
   char ville[20];
   if (ch==1)
   {
      for(i=0;i<x;i++)
       {
        printf("####### client %d \n",i+1);
         printf("\t Cin: %d \n",(c+i)->cin);
         printf("\t Nom: %s \n",(c+i)->nom);
         printf("\t Prenom: %s \n",(c+i)->prenom);
         printf("\t Ville: %s \n",(c+i)->ville);
         printf("\t numero de permis: %d \n",(c+i)->num_permis);
         printf("\t date de naissance: %d/%d/%d\n",(c+i)->ddn.jour,(c+i)->ddn.mois,(c+i)->ddn.annee);
         printf("\n");
       }
   }
   else if(ch==2)
        {
          printf("Cin ./");
          scanf("%d",&cin);
         for(i=0;i<x;i++)
         {
          if(cin==(c+i)->cin)
          {
            printf("\t Nom: %s \n",(c+i)->nom);
             printf("\t Cin: %d \n",(c+i)->cin);
             printf("\t Prenom: %s \n",(c+i)->prenom);
             printf("\t Ville: %s \n",(c+i)->ville);
             printf("\t numero de permis: %d \n",(c+i)->num_permis);
             printf("\t date de naissance: %d/%d/%d\n",(c+i)->ddn.jour,(c+i)->ddn.mois,(c+i)->ddn.annee);
             printf("\n");
          }
         }
        }
        else if(ch==3)
        {
          printf("ville./");
          scanf("%s",ville);
           for(i=0;i<x;i++)
          {
          if(ville==(c+i)->ville)
           {
             printf("\t Nom: %s \n",(c+i)->nom);
             printf("\t Cin: %d \n",(c+i)->cin);
             printf("\t Prenom: %s \n",(c+i)->prenom);
             printf("\t Ville: %s \n",(c+i)->ville);
             printf("\t numero de permis: %d \n",(c+i)->num_permis);
             printf("\t date de naissance: %d/%d/%d\n",(c+i)->ddn.jour,(c+i)->ddn.mois,(c+i)->ddn.annee);
             printf("\n");
           }
        }
        }
        else {
          printf("la lettre./");
          scanf("%c",&s);
          for(i=0;i<x;i++)
           {
             for(j=0;j<20;j++)
             {
               if((c+i)->nom[j]==s)
               {
                 printf("\t Nom: %s \n",(c+i)->nom);
                 printf("\t Cin: %d \n",(c+i)->cin);
                 printf("\t Prenom: %s \n",(c+i)->prenom);
                 printf("\t Ville: %s \n",(c+i)->ville);
                 printf("\t numero de permis: %d \n",(c+i)->num_permis);
                 printf("\t date de naissance: %d/%d/%d\n",(c+i)->ddn.jour,(c+i)->ddn.mois,(c+i)->ddn.annee);
                 printf("\n");
                 i++;
               }
             }
           }
        }
}
void aff_location(client *c,voiture *v,location *l,int x,int y,int z,int ch)
{  int i,j;
   date da;
   char nom[20];
   int d;
   int cin;
   int mat;
   switch (ch)
   {
   case 1:
       printf("nom du client./");
       scanf("%s",nom);
        for(i=0;i<x;i++)
         {
           if (nom== (c+i)->nom)
            {
               cin = (c+i)->cin;
                for(j=0;j<z;j++)
                {
                  if(cin== (l+j)->cin_client)
                  {
                    printf("cin client: %d\n",(l+j)->cin_client);
                    printf("matricule voiture: %d\n",(l+j)->matricule_l);
                    printf("Date de location: %d/%d/%d \n",(l+j)->date_l.jour,(l+j)->date_l.mois,(l+j)->date_l.annee);
                    printf("duree de location: %.2f",(l+j)->duree_l);
                  }
                }
            }
         }
        getch();
       menu();
       main();

    case 2:
       aff_matricule(v,y);
       printf("\n");
       printf("matricule de la voiture./");
        scanf("%d",&mat);
       for(i=0;i<z;i++)
       {
        if(mat==(l+i)->matricule_l)
          {
              printf("cin client: %d\n",(l+j)->cin_client);
              printf("matricule voiture: %d\n",(l+j)->matricule_l);
              printf("Date de location: %d/%d/%d \n",(l+j)->date_l.jour,(l+j)->date_l.mois,(l+j)->date_l.annee);
              printf("duree de location: %.2f",(l+j)->duree_l);
          }
       }
       getch();
       menu();
       main();
    case 3:
       printf("La duree./");
       scanf("%d",&d);
       for(i=0;i<z;i++)
       {
        if(d==(l+i)->duree_l)
          {
              printf("cin client: %d\n",(l+j)->cin_client);
              printf("matricule voiture: %d\n",(l+j)->matricule_l);
              printf("Date de location: %d/%d/%d \n",(l+j)->date_l.jour,(l+j)->date_l.mois,(l+j)->date_l.annee);
              printf("duree de location: %.2f",(l+j)->duree_l);
              printf("\n");
          }
       }
       getch();
       menu();
       main();
    case 4:
        printf("date:\n");
        printf("\t jour:");
         scanf("%d",&da.jour);
        printf("\n");

        printf("\t mois:");
         scanf("%d",&da.mois);
        printf("\n");

        printf("\t annee:");
         scanf("%d",&da.annee);
        printf("\n");
     for(i=0;i<z;i++)
       {
        if(da.jour == (l+i)->date_l.jour && da.mois== (l+i)->date_l.mois && da.annee==(l+i)->date_l.annee)
          {
              printf("cin client: %d\n",(l+j)->cin_client);
              printf("matricule voiture: %d\n",(l+j)->matricule_l);
              printf("Date de location: %d/%d/%d \n",(l+j)->date_l.jour,(l+j)->date_l.mois,(l+j)->date_l.annee);
              printf("duree de location: %.2f",(l+j)->duree_l);
              printf("\n");
          }
       }
       getch();
       menu();
       main();

   default:
    break;
   }
}
void supp_client(client *c,int x)
{  int pos;
   int i,cin;
   aff_cin(c,x);
   printf("cin./");
   scanf("%d",&cin);
   for(i=0;i<x;i++)
   {
    if ((c+i)->cin==cin)
     {
       pos=i;
       break;
     }
   }
         for (i=pos-1;i<=x;i++)
       {
         *(c+i)=*(c+i+1);
       }
      x--;
    c=(client *)realloc(c,x*sizeof(client));
}
void supp_voiture(voiture *v,int y)
{
   int pos;
   int i,mat;
   aff_matricule(v,y);
   printf("matricule./");
   scanf("%d",&mat);
   for(i=0;i<y;i++)
   {
    if ((v+i)->matricule==mat)
     {
       pos=i;
       break;
     }
   }
         for (i=pos-1;i<=y;i++)
       {
         *(v+i)=*(v+i+1);
       }
      y--;
    v=(voiture *)realloc(v,y*sizeof(voiture));
}
void supp_contact(client *c, int x)
{
   int k,i,j,pos,cpt=0;
   char ville[20];
   printf("la ville./");
   scanf("%s",ville);
   fflush(stdin);
   for ( i = 0; i < x; i++)
   {
     for(j=0;j<x;j++)
     {
       if(ville==(c+i)->ville)
        {
           pos=i;
           cpt++;
           break;
        }
     }
       for (k=pos-1;k<=x;k++)
      {
         *(c+i)=*(c+i+1);
      }

   }
   x-=cpt;
   c=(client *) realloc(c,x*sizeof(client*));
}
int cpt_contact(client *c, int x)
{
 int i,cpt=0;
 char ville[20];
 printf("ville./");
 scanf("%s",ville);
   for ( i = 0; i < x; i++)
   {
      if (ville==(c+i)->ville)
      {
        cpt++;
      }

   }
   return cpt;
}
void chiff_aff(voiture *v,int y)
{
  int i;
  float f;
  int mat;
  printf("matricule de la voiture ./");
  scanf("%d",&mat);
  for ( i = 0; i < y; i++)
  {
    if ((v+i)->matricule==mat)
    {
       (v+i)->chiffre=(v+i)->pr_location * (v+i)->cpt_l;
    }
  }

}
void pgrand_chiffre(voiture *v,int y)
{ int i;
  int mat;


  for(i=0;i<y;i++)
  {
    if((v+i)->chiffre<(v+i+1)->chiffre)
    {
       mat=(v+i)->matricule;
    }
  }
  for(i=0;i<y;i++)
  {
    if((v+i)->matricule==mat)
    {
        printf("\t matricule:%d \n",(v+i)->matricule);
        printf("\t type: %c \n",(v+i)->type);
        printf("\t prix de location: %.2f \n",(v+i)->pr_location);
        printf("\t Marque: %s \n",(v+i)->marque);
        printf("\t date mise en service: %d/%d/%d\n",(v+i)->dmc.jour,(v+i)->dmc.mois,(v+i)->dmc.annee);
        printf("\n");
    }
  }
}
void init_tab_cin(client *c,location *l,location *l2,int x,int y,int z)
{
  int i,j=0,cin;
  int cpt;
  aff_cin(c,x);
  printf("cin du client ./");
  scanf("%d",&cin);
  for ( i = 0; i < y; i++)
  {
    if((l+i)->cin_client==cin)
    {
      cpt++;
    }
  }
  l2=(location *) malloc(cpt*sizeof(location));
  for ( i = 0; i < x; i++)
  {
    if((l+i)->cin_client==cin)
    {
      *(l2+j)=*(l+i);
       j++;
    }
  }
  for(j=0;j<cpt;i++)
  {
    printf("########### Location %d \n",i+1);
    printf("cin : %d\n",(l2+j)->cin_client);
    printf("matricule : %d \n",(l2+j)->matricule_l);
    printf("date de location : %d/%d/%d \n",(l2+j)->date_l.jour,(l2+j)->date_l.mois,(l2+j)->date_l.annee);
    printf("duree de location : %f \n",(l2+j)->duree_l);
  }
}
void init_tab_mat(voiture *v,location *l,location *l3,int x,int y,int z)
{
  int i,j;
  int cpt,mat;
  aff_matricule(v,x);
   printf("matricule de la voiture ./");
   scanf("%d",&mat);
   for(i=0;i<y;i++)
   {
     if((l+i)->matricule_l == mat)
     {
      cpt++;
     }
   }
  l3=(location *) malloc(cpt*sizeof(location));
    for ( i = 0; i < x; i++)
  {
    if((l+i)->matricule_l == mat)
    {
       *(l3+j)=*(l+i);
       j++;
    }
  }
   for(j=0;j<cpt;i++)
  {
    printf("########### Location %d \n",i+1);
    printf("cin : %d\n",(l3+j)->cin_client);
    printf("matricule : %d \n",(l3+j)->matricule_l);
    printf("date de location : %d/%d/%d \n",(l3+j)->date_l.jour,(l3+j)->date_l.mois,(l3+j)->date_l.annee);
    printf("duree de location : %f \n",(l3+j)->duree_l);
  }
}
