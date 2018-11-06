#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

void scambia(char **a, char **b){

  char *temp=*a;
  *a=*b;
  *b=temp;
}

int partition(char **a, int sx, int dx){
  int i=sx-1, j=sx;
  for(j=sx;j<dx;j++){
    if (strcmp(a[j],a[dx])<0){
      i++;
      scambia(&a[i],&a[j]);
    }

    }
  scambia(&a[i+1],&a[dx]);

  return i+1;
  }

/*
Funzione che,dato un array di stringhe e la sua lunghezza, lo ordini (lessicograficamente)
utilizzando l’algoritmo Quicksort.
*/
void quickkastr(char **a,int sx, int dx){
  if (sx<dx){
    int cx=partition(a, sx, dx);
    quickkastr(a, sx, cx-1);
    quickkastr(a,cx+1,dx);
  }
}

void stampa(char **a, int dim){
  int i=0;
  for (i=0;i<dim;i++){
    printf("%s\n",a[i]);
  }
}


int main(){
  int dim=0,i=0;
  char **str;
  scanf("%d",&dim);
  str=(char**)malloc(sizeof(char*)*(dim));
  for(i=0;i<dim;i++){
    str[i]=(char*)malloc(sizeof(char)*MAX);
    scanf("%s",str[i]);

  }

  quickkastr(str,0, dim-1);
  stampa(str, dim);


  for(i=0;i<dim;i++)
    free(str[i]);

  free(str);
  return 0;
}
