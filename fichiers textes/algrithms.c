/*ternary operators*/
//syntax:
// (testcondition) ? expression 1 : expression 2 ;
// example:

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
void main()
{
    int n;

    printf("appliquant Age: ");
    scanf("%d",&n);
    printf("\n");
    (n>=18) ? printf("Adult person") : printf("Minor person");
}

//ctype functions:
tolower();
toupper();
isalpha();
isdigit();
