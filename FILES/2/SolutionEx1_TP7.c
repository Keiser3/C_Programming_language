#include<stdio.h>
#include<conio.h>
#include<ctype.h>

void EcrireFicherT(char *nf, char *Texte){
	FILE *f;
	int i=0;
	f=fopen(nf,"wt");
	if(f){
		while(*(Texte+i)!='\0'){
			putc(*(Texte+i),f);
			i++;
		}			
		fclose(f);
	}else puts("Erreur fichier1!");
}
void AfficherFichierT(FILE *f){
	char c;
	while((c=getc(f))!=EOF){
		printf("%c",c);
	}
}
void CopieFicherT(char *nf, char *nfc){
	FILE *f, *fc;
	char c;
	f=fopen(nf,"rt");
	fc=fopen(nfc,"wt");
	if(f&&fc){
		while((c=getc(f))!=EOF){
			putc(c,fc);
		}			
		fclose(f);
		fclose(fc);
	}else puts("Erreur fichier1!");
}
int NbrCharFicherT(char *nf, char car){
	FILE *f;
	char c;
	int i=0;
	f=fopen(nf,"rt");
	if(f){
		while((c=getc(f))!=EOF){
			if(tolower(c)==tolower(car))
				i++;
		}			
		fclose(f);
	}else puts("Erreur fichier1!");
	return i;
}
int NbrVoyFicherT(char *nf){
	FILE *f;
	char c;
	int i=0;
	f=fopen(nf,"rt");
	if(f){
		while((c=getc(f))!=EOF){
			if(isalpha(c)){
				c=tolower(c);
				if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
					i++;
			}
		}			
		fclose(f);
	}else puts("Erreur fichier1!");
	return i;
}
int NbrConFicherT(char *nf){
	FILE *f;
	char c;
	int i=0;
	f=fopen(nf,"rt");
	if(f){
		while((c=getc(f))!=EOF){
			if(isalpha(c)){
				c=tolower(c);
				if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!='y')
					i++;
			}
		}			
		fclose(f);
	}else puts("Erreur fichier1!");
	return i;
void rangement (char *chaine)
{
	FILE *maj,*min,*dig,*sym;
	char c;
	f=fopen("NomF.txt","rt");
	if (f!=NULL)
	{
		maj=fopen("Maj.txt","r+");
		min=fopen("Min.txt","r+");
		dig=fopen("Digit.txt","r+");
		sym=fopen("Symbol.txt","r+");
	while((c=getc(f))!=EOF){
			if(isalpha(c)){
			  if(isupper(c))
			  {
				putc(c,maj);
			  }
			  else if (islower(c))
			  {
				putc(c,min);
			  }
			 }
			else if(isdigit(c))
			{
				putc(c,dig);
			}
			else
			   putc(c,sym);
		}			
		fclose(f);
		fclose(maj);
		fclose(min);
		fclose(dig);
		fclose(sym);
		
	
	
}else printf("erreur du fichier F");

void main(){
	FILE *f;
	char NomF[30], NomFc[30], Chaine[100];
	printf("Donner le nom du fichier (nom+ .txt):\n");
	fflush(stdin); gets(NomF);
	printf("Donner le texte a ecrire dans ce fichier:\n");
	fflush(stdin); gets(Chaine);
	EcrireFicherT(NomF,Chaine);
	f=fopen(NomF,"rt");
	if(f){
		AfficherFichierT(f);		
		fclose(f);
	}else puts("Erreur Fichier2 !");
	printf("Donner le nom du fichier copie (nom+ .txt):\n");
	fflush(stdin); gets(NomFc);
	CopieFicherT(NomF, NomFc);
	printf("Le nombre de a dans le fichier est :%d \n",NbrCharFicherT(NomF,'a'));
	printf("Le nombre de Voyelles dans le fichier est :%d \n",NbrVoyFicherT(NomF));
	printf("Le nombre de Consonnes dans le fichier est :%d \n",NbrConFicherT(NomF));

}
