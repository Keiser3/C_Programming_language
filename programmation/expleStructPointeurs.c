#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//1. Ajoutant les champs note et matricule pour chaque Etudiant?
typedef struct{
	char nom[30];
	int age;
	float note;
	int matricule;	
}Etudiant;
main(){
	Etudiant e1, *e2, *Et;
	int i, n, pa, pn=0, cpt=0;
	float mn=0, ma=0;

	//pointeur sur une structure : e2
	//*e2.nom devient e2->nom
	e2=&e1;
	printf("Donner votre nom , age , note et matricule:\n");
	scanf("%s%d%f%d",e2->nom, &e2->age, &e2->note, &e2->matricule);
	printf("Vous etes : %s age de : %d ans ,vous avez eu : %.2f. Ton matricule est : %d\n",e2->nom, e2->age, e2->note, e2->matricule);
	//Tableau de structures : Et
	printf("Donner le nbre d'etudiants a saisir:\n");
	scanf("%d",&n);
	Et=(Etudiant*)malloc(n*sizeof(Etudiant));
	if(Et){
		//Remplissage du tableau : Formalisme Pointeur
		//*(Et+i).nom devient (Et+i)->nom
		for(i=0;i<n;i++){
			printf("Donner le nom ,l'age ,la note ,le matricule %d :\n",i+1);
			//(Et+i)->nom=(char*)malloc(20*sizeof(char));
			scanf("%s%d%f%d",(Et+i)->nom, &(Et+i)->age, &(Et+i)->note, &(Et+i)->matricule);
			ma = ma + (Et+i)->age;
			mn = mn + (Et+i)->note;
			pa = (Et)->age;
			if((Et+i)->age>pa)      pa = i;
		}
		ma = ma / n;
	    mn = mn / n;
	    /*for(i=0;i<n;i++){
	    	if((Et+i)->note>mn)   cpt++;
		}*/
		for(i=0;i<n;i++){
			printf("Etudiant ::: %d\n",i+1);
			printf("Nom: %s\tAge: %d\tNote: %.2f\tMatricule: %d\n",(Et+i)->nom, (Et+i)->age, (Et+i)->note, (Et+i)->matricule);
		}
		printf("La moyenne des ages des etudiants est : %.2f\n", ma);	
		printf("La moyenne de la classe est : %.2f\n", mn);
		printf("Le grand age est : %d\n", (Et+pa)->age);
		printf("Les informations de l'eleve le plus age est : Nom: %s\tAge: %d\tNote: %.2f\tMatricule: %d", (Et+pa)->nom, (Et+pa)->age, (Et+pa)->note, (Et+pa)->matricule);
		printf("Le nombre des eleves qui ont eu au dessus de la moyenne de la classe est : %d", cpt);
		free(Et);
	}else puts("Erreur d'allocation!!!");
	getch();
}
//Compl�ter l'exemple en:
	//1. Ajoutant les champs note et matricule pour chaque Etudiant?
	//2. Calculant la moyenne :
			//a. d'age des Etudiants?
			//b. de la classe repr�sent�e par ce tableau d'Etudiants?
	//3. Affichant les informations de l'Etudiant le plus ag�?
	//4. Calculant le nbre d'Etudiants ayant une moyenne au dessus 
	// de la moyenne de la classe?
