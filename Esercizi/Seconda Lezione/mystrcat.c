#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 1001

/*
Funzione che aggiunge la stringa s2 alla fine della stringa s1
sovrascrivendo il terminatore /0. Devo anche controllare
che nella stringa s1 ci sia posto per la stringa s2.
*/
char * my_strcat(char *s1,char *s2){

  while(*s1){
    *s1++;
  }
  while(*s2){
    *s1=*s2++;
    *s1++;
  }
  *s1='\0';
}

/*Stampa una stringa*/
void stampa(char *s){

  while(*s){
    printf("%c",*s++);
  }
  printf("\n");
}

int main(){
  char s1[MAX], s2[MAX];
  scanf("%s%s",s1,s2);
  stampa(s1);

return 0;
}
