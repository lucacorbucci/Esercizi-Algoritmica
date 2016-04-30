#include <stdio.h>
#include <stdlib.h>

typedef struct _lista{
  int key;
  struct _lista * next;
} lista;

void inserisci(lista * lis, int dim){
  int i=0;
  for(i=0;i<dim;i++){
    scanf("%d",&(lis->key));
    lis->next=(lista *)malloc(sizeof(lista)*dim);
    lis=lis->next;
  }
  lis->next=NULL;
}

void stampa(lista * lis){
  while(lis->next!=NULL){
    printf("%d\n",lis->key);
    lis=lis->next;
  }
}

int main(){
  int dim=0;
  lista * lis;
  scanf("%d",&dim);
  lis=(lista *)malloc(sizeof(lista)*dim);
  inserisci(lis, dim);
  stampa(lis);
}
