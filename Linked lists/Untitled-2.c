#include<stdio.h>
#include<stdlib.h>
 void main(){
    FILE *f;
    f= fopen("kiwi2.txt","wt+");
    if(f) 
     { fprintf(f,"lkiwi is gay");}
   fclose(f);
 }