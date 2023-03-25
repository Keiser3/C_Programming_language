#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct{
	int matr;
	char nom[30];
	float note;	
}Etud;

void AfficherFichBin(char *nf){
	FILE *f;
	Etud e;
	int i=0;
	f=fopen(nf,"rb"); //w	wb	a	ab
	if(f){
		printf("Contenu du Fichier:\n");
		while(fread(&e,sizeof(Etud),1,f)==1){
			i++;
			printf("Etudiant %d : %d\t%s\t%.2f\n",i,e.matr,e.nom,e.note);
		}
		fclose(f);
	}else puts("Erreur d'ouverture du fichier binaire!!!");
}
void transfertBIN(char *nf)
{
	FILE *f;
	FILE *rdb,*reub;
	Etud e;

	f=fopen(nf,"rb");
	rdb=fopen("redoublant.bin","wb");
	reub= fopen("reussie.bin","wb");
	if (f)
	{   
	   while(fread(&e,sizeof(Etud),1,f))
	   {
            if(e.note>=10)
			{
               fwrite(&e,sizeof(Etud),1,reub);
			}
			else {
				fwrite(&e,sizeof(Etud),1,rdb);
			}
	   }
	  fclose(f);
	}else puts("error!");
	fclose(rdb);
	fclose(reub);
}
void transfertTEXT()
{
	
	FILE *rdb,*reub;
	FILE *rdt, *reut;
	Etud e;

	
	rdb=fopen("redoublant.bin","rb");
	reub= fopen("reussie.bin","rb");
	rdt= fopen("redoublant.txt","at");
	reut= fopen ("reussie.txt","at");
	if (rdb )
	{   
	   while(fread(&e,sizeof(Etud),1,rdb))
	   {
            fprintf(rdt,"%d \t %s \t %.2f\n",e.matr,e.nom, e.note);
	   }
	   while(fread(&e,sizeof(Etud),1,reub))
	   {
            fprintf(reut,"%d \t %s \t %.2f\n",e.matr,e.nom, e.note);
	   }

	  fclose(rdb);
	  fclose(reub);
	}else puts("error!");
	fclose(rdt);
	fclose(reut);
}
void main(){
	FILE *f;
	Etud e;
	int i, n;	
	//Inserer N etudiants dans un fichier binaire!
	f=fopen("Groupe5.bin","ab"); //w	wb	a	ab
	if(f){
		printf("Donner le nbre d'etud N:\n");
		scanf("%d",&n);
		for(i=0;i<n;i++){
			printf("Donner le matr, nom et note: %d\n",i+1);
			scanf("%d%s%f",&e.matr,e.nom,&e.note);
			fwrite(&e,sizeof(Etud),1,f);
		}
		fclose(f);
	}else puts("Erreur d'ouverture du fichier binaire!!!");
	AfficherFichBin("Groupe5.bin");
	transfertBIN("Groupe5.bin");
	transfertTEXT();
}
