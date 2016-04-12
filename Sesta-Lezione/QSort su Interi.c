#include <stdio.h>
#include <stdlib.h>

/*
Funzione che utilizzi la funzione qsort e ordini un vettore di
interi (in input), in modo da ottenere il seguente effetto. L’array ordinato
deve contenere prima tutti i numeri pari e, a seguire, i numeri dispari. Si
assuma che il numero 0 sia pari. I numeri pari devono essere ordinati in
modo crescente fra di loro. I numeri dispari devono essere ordinati in modo
decrescente fra di loro.
*/
int compare(const void *a, const void *b){
  int *a1=(int *) a;
  int *b1=(int *) b;
  if ((*a1)%2==0 && (*b1)%2==0){
    return (*a1-*b1);
}
  else if ((*a1)%2!=0 && (*b1)%2!=0){
    return (*b1-*a1);
  }
  else if((*a1)%2!=0 && (*b1)%2==0){
    return 1;
  }
  else if ((*a1)%2==0 && (*b1)%2!=0){
    return -1;
  }
}

void stampa(int *a, int dim){
  int i=0;
  for(i=0;i<dim;i++){
    printf("%d\n",a[i]);
  }
}

int main(){
  int dim=0,i=0;
  int *a;
  scanf("%d",&dim);
  a=malloc(sizeof(int)*dim);
  for (i=0;i<dim;i++){
    scanf("%d",&a[i]);
  }
  qsort(a, dim, sizeof(int), compare);
  stampa(a, dim);
  free(a);

  return 0;
}
