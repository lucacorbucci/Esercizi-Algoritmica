#include <stdio.h>

#define MAX 1001

/*Funzione che confronta lessicograficamente s1 e s2.
Se s1<s2 allora restituisco <0, se s1==s2 allora 0 altrimenti
un numero maggiore di 0 se s1>s2.
*/
int mystrcmp(char *s1, char *s2){
  int temp=0;
  while(*s1 || *s2){
    if (*s1<*s2){
      temp--;
      *s1++;
      *s2++;
    }
    else if (*s1>*s2){
      temp++;
      *s1++;
      *s2++;
    }
    else {
      *s1++;
      *s2++;
    }
  }
return temp;
}

int main(){
  char s1[MAX], s2[MAX];
  scanf("%s%s",s1,s2);
  int d=mystrcmp(s1,s2);
  if (d>0){
    printf("+1\n");
  }
  else if (d<0){
    printf("-1\n");
  }
  else printf("0\n");

return 0;
}
