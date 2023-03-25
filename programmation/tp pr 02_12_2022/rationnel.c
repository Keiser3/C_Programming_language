#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int num;
    int den;
} rationnel;
void afficherRationnel(rationnel *, int);
void simplifierRationnel(rationnel *,int);
int ComparerRationnel(rationnel *, int, int);
void SommeRationnel(rationnel *, int, int);
void plusgrandrationnel(rationnel *,int);
void menu(void);

  void main()
  {
    rationnel r1,*r;
    int chx;
    int cmp;
    int pos,pos1;
    r=&r1;
    int n,i;
    printf("saisir le nbre des rationnel\n");
    scanf("%d",&n);
    r= (rationnel*) malloc(n*sizeof(rationnel));
    for(i=0;i<n;i++)
    {
        printf("saisir le numerateur du rationnel %d: \n",i+1);
        scanf("%d",&(r+i)->num);
       printf("saisir le denominateur du rationnel %d: \n",i+1);
        scanf("%d",&(r+i)->den);        
    }
    menu();
    do
    {
     printf("votre choix./");
     scanf("%d",&chx);
    } while (chx<1 || chx>5);
    switch (chx)
    {
    case 1:
      do
       {
         printf("donner la position du rationnel\n");
         scanf("%d",&pos);
       } while (pos>=n);
         afficherRationnel(r,pos);
        break;
    case 2:
      do
       {
         printf("donner la position du rationnel\n");
         scanf("%d",&pos);
       } while (pos>n);
         simplifierRationnel(r,pos - 1);
        break;
    case 3:
      do
       {
         printf("donner la position du rationnel 1\n");
         scanf("%d",&pos);
       } while (pos>n);
      do
       {
         printf("donner la position du rationnel 2\n");
         scanf("%d",&pos1);
       } while (pos1>n);
       cmp=ComparerRationnel(r,pos,pos1);  
       if (cmp == -1)
       {
         printf("%d/%d > %d/%d \n",(r+pos-1)->num,(r+pos-1)->den, (r+pos1-1)->num, (r+pos1-1)->den);break;
       }
       else if (cmp == 0)
        {
             printf("%d/%d = %d/%d \n",(r+pos-1)->num,(r+pos-1)->den, (r+pos1-1)->num, (r+pos1-1)->den);break;
        }
        else 
            printf("%d/%d < %d/%d \n",(r+pos-1)->num,(r+pos-1)->den, (r+pos1-1)->num, (r+pos1-1)->den);break;
    case 4:
      do
       {
         printf("donner la position du rationnel 1\n");
         scanf("%d",&pos);
       } while (pos>n);
      do
       {
         printf("donner la position du rationnel 2\n");
         scanf("%d",&pos1);
       } while (pos1>n);
    SommeRationnel(r,pos,pos1);break;
    case 5:
       plusgrandrationnel(r,n);

    
    default:
        break;
    }
  }
  void afficherRationnel(rationnel *r, int x)
  {
    printf("r= %d/%d ",(r+x-1)->num,(r+x-1)->den);
  }
  void simplifierRationnel(rationnel *r, int x)
  {
    
    int num, den, pgcd, i;
     num = (r+x)->num;
     den = (r+x)->den;
    for(i=1; i <= num && i <= den; ++i)
    {
        if( num%i==0 && den%i == 0)
            pgcd = i;
    }
    printf("PGCD(%d,%d) = %d\n", num, den, pgcd);
     (r+x)->num/=pgcd;
     (r+x)->den/=pgcd;
    printf("Le rationnel simplifie: %d/%d",(r+x)->num,(r+x)->den);
  }
  int ComparerRationnel(rationnel *r, int x, int y)
  {
       int n,m;
       n= (r+x)->num/(r+x)->den;
       m= (r+y)->num/(r+y)->den;
        if (n<m)
           return -1;
        else if (n>m)
            return 2;
              else 
                return 0;
  }
  void SommeRationnel(rationnel *r, int x, int y)
  {
     rationnel s;
     
     s.num= (r+x-1)->num + (r+y-1)->num;
     s.den= (r+x-1)->den + (r+y-1)->den;
     printf("s= %d/%d",s.num,s.den);

  }
  void plusgrandrationnel(rationnel *r,int x)
  {
     int i=0,j,cpt=0;
     float pg;
      pg =(float) (r+i)->num/(r+i)->den;
     for (i=0;i<x;i++)
     {
       for(j=1;j<x;j++)
       {
         if ((r+j)->num/(r+j)->den > pg)
         {
            pg =(float) (r+j)->num/(r+j)->den;
            cpt=j;
         }
         
       }
          
     }
    
    printf("le plus grand rationnel est r= %d/%d ",(r+cpt)->num,(r+cpt)->den);
  }
  void menu()
  {
    printf("1/ afficher le rationnel\n");
    printf("2/ simplifier le rationnel\n");
    printf("3/ comparer deux rationnel\n");
    printf("4/ somme de deux rationnel\n");
    printf("5/ plus grand rationnel\n");
  }