#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

/*
  Funzione che, data una stringa, un array di stringhe distinte
  e ordinate lessicograficamente e la sua lunghezza, cerchi la stringa nell’array
  utilizzando la ricerca binaria. La funzione restituisce la posizione della
  stringa se essa `e presente, il valore -1 altrimenti.
*/
int ricerca(char *a[], char *s, int sx, int dx){
  int cx=(sx+dx)/2;
  //Caso in cui sx va oltre dx
  if (sx>dx){
    return -1;
  }

  //caso in cui sx è uguale a dx
  if (sx==dx){
    if ((strcmp(a[sx],s)==0)){
      return cx;
    }
    else return -1;
  }

  //caso in cui sx è minore di dx
  else if (sx<dx){
    if ((strcmp(a[cx],s)==0)){
      return cx;
    }
    if ((strcmp(a[cx],s)<0)){
      ricerca(a,s,cx+1,dx);
  }
    else ricerca(a,s,sx,cx-1);
}

}



int main(){
  int dim=0, i=0;
  char **a;
  int temp=1;
  char *s;


  scanf("%d",&dim);
  a=(char**)malloc(sizeof(char*)*dim);
  for(i=0;i<dim;i++){
    a[i]= malloc(sizeof(char)*MAX);
    scanf("%s",a[i]);
  }

  while(temp==1){
    scanf("%d",&temp);
    if (temp==1){
      s=malloc(sizeof(char)*MAX);
      scanf("%s",s);
      printf("%d\n",ricerca(a,s,0, dim-1));
      free(s);
    }
  }
  for(i=0;i<dim;i++){
    free(a[i]);
  }
  free(a);

return 0;
}
