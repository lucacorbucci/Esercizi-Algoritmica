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
  int dim1=0,dim2=0;
  scanf("%d",&dim1);
  char *s1=malloc(sizeof(char)*dim1);
  scanf("%s",s1);
  scanf("%d",&dim2);
  char *s2=malloc(sizeof(char)*dim2);
  scanf("%s",s2);

  char * con=malloc(sizeof(char)*(dim1+dim2));
  con=my_strcat1(s1,s2);
  stampa(con);
free(con);
free(s1);
free(s2);
return 0;
}
