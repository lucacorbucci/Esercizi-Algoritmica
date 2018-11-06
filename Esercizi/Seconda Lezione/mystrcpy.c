#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

/*
Funzione che copia la stringa src in dest restituendo un
puntatore a dest
*/
char * mystrcpy(char *dest, char *src){

  while(*src){
    *dest=*src;
    *dest++;
    *src++;
  }
  *dest='\0';
}

int dimensione(char *s){
  int dim=0;
  while(*s){
    dim++;
    *s++;
  }
return dim;
}

void stampa(char *s2){
  while(*s2){
    printf("%c",*s2++);
}
  printf("\n");
}

int main(){
  char s1[MAX];

  int dim=0;

  scanf("%s",s1);
  dim=dimensione(s1)+1;
  char *s2=(char *) malloc(sizeof(char)*dim);
  mystrcpy(s2,s1);
  stampa(s2);

  free(s2);


return 0;
}
