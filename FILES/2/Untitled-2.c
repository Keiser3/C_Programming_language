#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nom[30];
    char prenom[30];
    float note;
} etudiant;
void main()
{
  etudiant *tptr;
  int n;
  printf("le nombre des etudiant\n");
  scanf("%d",&n);
  tptr=(etudiant *) malloc(n*sizeof(etudiant));
  for (int i=0;i<n; i++)
  {
    printf("nom, prenom, note");
    scanf("%s", *(tptr+i)->nom);
    fflush(stdin);
    scanf("%s", *(tptr+i)->prenom);
    fflush(stdin);
    scanf("%f", (tptr+i)->note);
  }

}