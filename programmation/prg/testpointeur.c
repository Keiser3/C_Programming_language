#include<stdio.h>
#include<conio.h>
void main()
 {
    float note1,note2,note3,moy;
    float *x, *y, *z, *m;
    x=&note1;
    y=&note2;
    z=&note3;
    //lecture et affichage classique
    printf("saisir les 3 notes\n");
    scanf("%f%f%f",&note1,&note2,&note3);
    moy=(note1+note2+note3)/3;
    printf("la moyenne= %.2f\n",moy);
    //utilisation des pointeur
    printf("saisir les 3 notes\n");
    scanf("%f%f%f",x,y,z);
    m=&moy;
    *m=(*x+*y+*z)/3;
    printf("la moyenne est %.2f\n",*m);
    // affichage des adresse
    printf("&note1=%X \t &note2=%X \t &note3=%X \n",&note1,&note2,&note3);
    printf("&note1=%X \t &note2=%X \t &note3=%X \n",x,y,z);
 }