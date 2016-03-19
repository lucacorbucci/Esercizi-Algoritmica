#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

char * mystrcpy(char *dest, char *src){

  while(*src){
    *dest=*src;
    *dest++;
    *src++;
  }

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

/*
Funzione che data una stringa str e un intero k restituisce
la stringa ottenuta concatenando k volte la stringa str
*/
char* product(char * str, int k){
  int dim=dimensione(str);
  char *s=malloc(sizeof(char)*dim*k);
  int i=0;

  for(i=0;i<k;i++){
    mystrcpy((s+i*dim),str);

  }


return s;
}



int main(){
  char s1[MAX];
  int k=0;
  scanf("%s%d",s1,&k);
  char *de=product(s1,k);
  stampa(de);

free(de);
return 0;
}
