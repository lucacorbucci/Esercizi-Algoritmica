#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

/*
Data un array conta il numero degli elementi che stanno
nell'array e che sono compresi tra 0 e 9.
Le frequenze stanno in un array di contatori inizializzati a 0
*/

//Inizializza l'array dei contatori a 0
void reset(int a[],int len){
  a=calloc(len,sizeof(int));
}

//Incrementa il contatore array[val]
//se val è tra  e len -1
void add(int array[], int len, int val){
  int i=0;
  int *b=malloc(10*sizeof(int));
  reset(b,10);

  for (i=0;i<len;i++){
    if (array[i]>=0 && array[i]<=9){
      b[array[i]]++;
    }
  }

  for (i=0;i<10;i++){

    array[i]=b[i];
  }
  free(b);
}

/*Input: sequenza di interi terminata da -1
Output: frequenza interi tra 0 e 10
*/

int main(){
  int a[MAX], i=0,dim=0;
  while(i!=-1){
    scanf("%d",&i);
    if (i!=-1){
      a[dim]=i;
      dim++;
    }
  }

  add(a,dim,0);

  for (i=0;i<10;i++){
    printf("%d\n",a[i]);
  }
return 0;
}
