#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
  time_t seconds=time(NULL);
  struct tm* current_time=localtime(&seconds);
  int currYear = current_time->tm_year + 1900 ; 
  printf("%d",currYear);
}