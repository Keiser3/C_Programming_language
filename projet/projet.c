#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

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
  } client;

typedef struct
  {
    int matricule; // rand
    char type;
    float pr_location;
    char marque[20];
    date dmc; // date mise en circulation

  } voiture;

typedef struct
  {
    int cin_client;
    int matricule_l; // matricule de la voiture loue
    date date_l;
    float duree_l;
  } location;
void init_tableau();
void insertion();
void insert_client(int p, int x, client *c, int ch)
{
    srand(time(NULL));
    int i;
    
     if (ch==1)
     {
        for (i = x - 1; i > p; i--)
       {
          *(c + (i + 1)) = *(c + i);
       }

      printf("NOM./");
      gets( (c+p)->nom );
    
      printf("PRENOM./");
      gets((c+p)->prenom);

      printf("NUMERO DE PERMIS./");
      scanf("%d",&(c+p)->num_permis);
     }
     
    
    
    
}
void init_tableau(int x, int y, int z, client *c, voiture *v, location *l)
{
    c = (client *)malloc(x * sizeof(client));
    v = (voiture *)malloc(y * sizeof(voiture));
    l = (location *)malloc(z * sizeof(location));
}


void menu()
{
    printf("**************** AGENCE DE LOCATION DES VOITURES *******************\n");
    printf(" 1.initialisation des tableaux \n");
    printf(" 2.ajout d'un nouveau client:\n");
    printf("\t a. A une position donnee?\n");
    printf("\t b. vers la fin?\n");
    printf(" 3.ajout d'une nouvelle voiture:\n");
    printf("\t a. A une position donnee?\n");
    printf("\t b.vers la fin?\n");
    printf(" 4. ajout d'une nouvelle location:\n");
    printf("\t a. A une position donnee?\n");
    printf("\t b.vers la fin?\n");
    printf("5. Affichage de la liste des voitures:\n");
    printf("\t a. Toutes les voitures?\n ");
    printf("\t b. Par marque?\n");
    printf("\t c. Par ville\n");
    printf("6. Affichage de la liste des clients:\n");
    printf("\t a. Tous les clients?\n ");
    printf("\t b. Par CIN?\n");
    printf("\t 3. Par ville\n");
    printf("6. Affichage de la liste des locations:\n");
    printf("\t a. Par client(nom)?\n ");
    printf("\t b. Par voiture (matricule)?\n");
    printf("\t c. Par duree\n");
    printf("\t d. Par date de location\n");
    printf("8. Affichage de la liste des clients dont le nom par une lettre donnee\n");
    printf("9. Suppression d'un client par CIN \n");
    printf("10. Supprimer une voiture par son numero d'immatriculation\n");
    printf("11. Supprimer tous les contacts d'une ville donnee \n");
    printf("12. Compter le nombre de contacts d'une ville donnee \n");
    printf("13. Le chiffre realise par une voiture donnee \n");
    printf("14. Afficher les informations de la voiture ayant realise le chiffre le plus eleve \n");
    printf("15. Creer un nouveau tableau representant les locations d'un client donne \n");
    printf("16. Creer un nouveau tableau des locations d'une voiture donnee \n");
    printf("17. Exporter les locations d'un client vers un fichier texte \n");
    printf("\t a. Fonction d'affichage de ce fichier\n");
    printf("18. Exporter les voitures ayant un prix de location donne vers un fichier binaire \n");
    printf("\t a. Fonction d'affichage de ce fichier\n");
    printf("19. Quitter \n");
}
void main()
{
    int ch, chx, i;
    int pos = 0;

    client *c;
    int cl, nbc;
    voiture *v;
    int vo, nbv;
    location *l;
    int lo, nbl;

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
        init_tableau(nbc, nbv, nbl, c, v, l);
        menu();
        main();
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
            
        }
        else if (ch == 2)
        {   
            
            pos=nbc-1;
        }
        insert_client(pos,nbc, c,ch);


    default:
        break;
    }
}


