#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001


void occorrenza(int *a,int *b,unsigned char *s1, unsigned char *s2,int n1, int n2){
  int i=0;
  for(i=0;i<n1;i++){
    a[s1[i]]++;
  }
  for(i=0;i<n2;i++){
    b[s2[i]]++;
  }
}
/*
La funziona anagramma restituisce 1 se le stringhe sono
una l'anagramma dell'altra. 0 altrimenti.
*/
int anagramma(unsigned char *s1, unsigned char *s2){
  int *a=calloc(256, sizeof(int));
  int *b=calloc(256,sizeof(int));
  int n1=strlen(s1);
  int n2=strlen(s2);
  int equals=1,j=0,i=0;
  occorrenza(a,b,s1,s2,n1,n2);
  while(equals!=0 && i<256){
    if (a[i]!=b[j])
      equals=0;
    else{
      j++;
      i++;
    }
  }
  free(a);
  free(b);
  return equals;
}



int main(){
  unsigned char s1[MAX],s2[MAX];
  scanf("%s%s",s1,s2);
  unsigned char *ss1=malloc(sizeof(char)*strlen(s1));
  unsigned char *ss2=malloc(sizeof(char)*strlen(s2));

  int i=0;
  for (i=0;i<strlen(s1);i++){
    ss1[i]=s1[i];
  }
  for (i=0;i<strlen(s2);i++){
    ss2[i]=s2[i];
  }

  printf("%d\n",anagramma(ss1,ss2));
  free(ss1);
  free(ss2);
}
