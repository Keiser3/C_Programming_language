#include<stdio.h>
#include<stdlib.h>
#define CHUNK 4
void main()
{
  char *str, c;
  char *cypher;
  int i = 0, j = 1;

  str = (char*)malloc(sizeof(char));

  printf("Enter String : ");

  while (c != '\n') {
    // read the input from keyboard standard input
    c = getc(stdin);

    // re-allocate (resize) memory for character read to be stored
    str = (char*)realloc(str, j * sizeof(char));

    // store read character by making pointer point to c
    str[i] = c;
    cypher=(char*) malloc(sizeof(str));
    i++;
    j++;

  }

  str[i] = '\0'; // at the end append null character to mark end of string
    i=0;
    while(str[i]!='\n')
    {
        cypher[i]=str[i]*12/10;
        i++;
    }


  printf("\nThe entered string is : %s", str);
  printf("\nThe cyphered string is : %s", cypher);
  // important step the pointer declared must be made free
  free(str);
  free(cypher); 
}