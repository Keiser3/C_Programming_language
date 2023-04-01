#include<stdio.h>
#include<stdlib.h>

typedef struct polynome{
    int coeff;
    int exp;
    struct polynome* next;
} polynome;
polynome* saisie(){
   polynome* temp = (polynome*) malloc(sizeof(polynome));
   printf("sasir le coeffecient et l'exposant: \n");
   scanf("%d%d",&temp->coeff,&temp->exp);
   temp->next = NULL;
   return temp;
}

polynome* ajout(polynome* liste){
     polynome *curr= saisie();
     
     curr->next = liste->next;
     liste->next = curr;
     return liste;
}

void afficher(polynome *liste){
    polynome *curr= liste->next;
    printf("Affichage:\n");
     while(curr->next!=liste){
        
        printf(" %dX^%d +",curr->coeff,curr->exp);
        

        curr=curr->next;

     }
}
int plcmp(polynome *liste1, polynome *liste2){
    polynome *curr1= liste1->next;
    polynome *curr2= liste2->next;
     while(curr1!=liste1 && curr2!=liste2){
        
        if(curr1->coeff == curr2->coeff && curr1->exp == curr2->exp)  
        {
            curr1=curr1->next;
            curr2=curr2->next;
        }
        else
           return 0;
     }
     return 1;
}
void suppPl(polynome* liste){
    liste->next = NULL;
}

int appart(polynome* liste)
{
    polynome* monome = (polynome*) malloc(sizeof(polynome));
    polynome* curr = liste->next;
    printf("Saisir le coeffecient et l'exposant: \n ");
    scanf("%d%d",&monome->coeff,&monome->exp);
    monome->next = NULL;
    while(curr!=liste){
         
         if(curr->coeff == monome->coeff && curr->exp == monome->exp)
         {
            return 1;
         }
         curr = curr->next; 
    }

    return 0;
}
int modifier(polynome *liste,int exp, int coeff){
    polynome* curr = liste->next;
    
    while(curr->next!=liste){
         
         if(curr->coeff == coeff && curr->exp == exp)
         {
            curr->coeff=coeff;
            curr->exp= exp;
            return 1;
            
         }
         curr = curr->next;
    }
    return 0;

}
//derivee : X^n' == n X ^ n-1
polynome* derivee(polynome *liste){
    polynome *dr =  (polynome*) malloc(sizeof(polynome));
    polynome* curr = liste->next;
    while(curr->next!=liste){
      curr->coeff = curr->exp;
      curr->exp = (curr->exp) - 1;

    }
    return dr;
}
void main(){
    polynome* one = (polynome*) malloc(sizeof(polynome));
    polynome* two = (polynome*) malloc(sizeof(polynome));
    polynome* three = (polynome*) malloc(sizeof(polynome));
    int n;
    printf("saisir le nombre des Monomes du polynomes 1\n");
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        one = ajout(one);
     }
     
     printf("saisir le nombre des Monomes du polynomes 2\n");
     scanf("%d",&n);
     for(int i = 0;i<n;i++)
     {two = ajout(two);}
     
     printf("saisir le nombre des Monomes du polynomes 3\n");
     scanf("%d",&n);
     for(int i = 0;i<n;i++)
     {three = ajout(three);}
     
     
     
     afficher(one);
     afficher(two);
     afficher(three);

    free(one);
    free(two);
    free(three);
}


