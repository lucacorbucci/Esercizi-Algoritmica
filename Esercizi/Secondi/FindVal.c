#include <stdio.h>

/*Funzione che dato un array A e la sua linghezza len
cerca il valore val all'interno di A e restituisce un puntatore
alla cella che lo contiene on NULL se non è presente.
*/
int* findval (int a[], int len, int val){
  int i=0;
  int *p=NULL;
  while(i<len && p==NULL){
    if (a[i]==val)
    p=&a[i];
    else i++;
  }
  return p;
}

/*
Array A di 10 interi e un valore val.
Se val è presente allora stampo trovato else non trovato
*/
int main(){
  int a[10],i=0,n=0;
  for(i=0;i<10;i++)
    scanf("%d",&a[i]);
  scanf("%d",&n);

  if (findval(a,10,n)!=NULL)
    printf("trovato\n");
  else
    printf("non trovato\n");
}
