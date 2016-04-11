#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 101

  void scambia(char **a, char **b){
    char *temp=*a;
    *a=*b;
    *b=temp;
  }

/*
  !!!!!!!!!!!! D A  F A R E !!!!!!!!!!!!
  sx e dx sono le posizioni del primo e dell'ultimo elemento dell'array mentre
  px è la posizione dell'elemento perno.
  La funzione deve restituire la posizione del perno dopo che gli elementi sono
  stati partizionati.
*/
int distribuzione(char *a[], int sx, int px, int dx) {
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

void quicksort( char *a[], int sx, int dx ) {

  int perno, pivot;
  if( sx < dx ) {
    // DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi.
    pivot = rand()%(dx-sx+1)+sx;
    scambia(&a[pivot],&a[dx]);
    perno = distribuzione(a, sx, pivot, dx); // separa gli elementi minori di a[pivot]
					     // da quelli maggiori o uguali
    // Ordina ricorsivamente le due metà
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);

  }

}


int main() {

  int i, dim=0;
  char **a;

  scanf("%d", &dim);
  if(dim <= 0) return 1;

  a = (char **) malloc(dim * sizeof(char*));
  if(a == NULL) return 1;

  for( i = 0; i < dim; i++ ) {
    a[i]=malloc(sizeof(char)*MAX);
    scanf("%s", a[i]);
  }


  srand(time(NULL));
  quicksort(a, 0, dim-1);

  // Stampa l'array ordinato
  for( i = 0; i < dim; i++ )
    printf("%s\n", a[i]);

  for(i=0;i<dim;i++){
    free(a[i]);

  }
  free(a);
  return 0;
}
