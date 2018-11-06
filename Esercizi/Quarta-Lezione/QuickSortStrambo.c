#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  Scambio due elementi
*/
void scambia(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

/*
  Divisione dell'array in due parti, nella prima vanno gli elementi pari
  nella seconda gli elementi dispari
*/
int dividi(int a[], int sx,int dx){
  int i=sx-1, j=sx;
  for(j=sx;j<dx;j++){
    if (a[j]%2==0){
      i++;
      scambia(&a[i],&a[j]);
    }
  }
  scambia(&a[i+1],&a[dx]);
  if (a[i+1]%2==0)
    return i+1;
  else return i;
}


/*
  Procedura partition
  */
int distribuzione(int a[], int sx, int px, int dx) {

  int i=sx-1, j=sx;
  for(j=sx;j<dx;j++){
    if (a[j]<=a[dx]){
      i++;
      scambia(&a[i],&a[j]);
    }

    }
  scambia(&a[i+1],&a[dx]);
  return i+1;
}

/*
  Ordinamento dell'array tramite QuickSort
*/
void quicksort( int a[], int sx, int dx ) {

  int perno, pivot;
  if( sx < dx ) {
    /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
int i=0;
    pivot = rand()%(dx-sx+1)+sx;
    scambia(&a[pivot],&a[dx]);


    perno = distribuzione(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot]
					        da quelli maggiori o uguali */
    /* Ordina ricorsivamente le due metà*/
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);

  }

}

/*
------------------------------------------------------------------------------------------
*/

int main(){
  int dim=0,i=0;
  int *a;

  //prendo da tastiera la dimensione dell'array
  scanf("%d",&dim);
  //alloco l'array a tenendo conto di dim
  a=(int*)malloc(sizeof(int)*dim);
  for(i=0;i<dim;i++)
    scanf("%d",&a[i] );

  //Divisione array in parte pari e dispari e ordinamento
  srand(time(NULL));
  int px=dividi(a,0,dim-1);
  quicksort(a,0,px);
  quicksort(a,px+1,dim-1);

  //stampa dell'array
  for(i=0;i<dim;i++){
    printf("%d ",a[i]);
  }

  //free della memoria
  free(a);

  return 0;
}
