#include <stdio.h>
#define MAX 1001

/*Funzione che restituisce il numero dei caratteri
della stringa s*/
int my_strlen(char *s){
int len=0;
  while(*s!='\0'){
    len++;
    *s++;
  }
return len;
}

int main(){
char s[MAX];
  scanf("%s",s);
  printf("%d\n",my_strlen(s));

return 0;
}
