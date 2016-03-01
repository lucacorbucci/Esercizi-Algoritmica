#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1001

/*
La funzione restituisce un puntatore alla nuova stringa che ottengo
concatenando le stringhe s1 e s2.
*/
char * my_strcat1(char *s1,char *s2){
  int dim=strlen(s1)+strlen(s2);
  char * conca=malloc(sizeof(char)*dim);
  int i=0;
  while(*s1){
    conca[i]=*s1;
    *s1++;
    i++;
  }
  while(*s2){
    conca[i]=*s2++;
    i++;
  }
  conca[i]='\0';

return conca;
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
  char * con=malloc(sizeof(char)*(strlen(s1)+strlen(s2)));
  con=my_strcat1(s1,s2);
  stampa(con);
free(con);
return 0;
}
