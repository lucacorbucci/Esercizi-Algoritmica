/*
Creazione e stampa di una tabella hash. Viene anche liberata la memoria.
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct _elem{
  int key;
  struct _elem* next;
}item;

typedef item* lista;
typedef lista * table;

int hash(int n, int p,int a, int b, int x){
	return (((a*x+b) % p) % (2*n));
}


void inserisci(lista *t,int val){
  lista corr=*t;
  lista new=malloc(sizeof(item));
  new->key=val;
  new->next=NULL;
  if(*t==NULL){
    *t=new;
  }
  else{
    while(corr->next!=NULL){
      corr=corr->next;
    }
    corr->next=new;
  }
}

void stampa(lista l){
  if (l==NULL){
    printf("NULL");
  }

  else {
    lista corr=l;
    while(corr!=NULL){
      printf("%d ",corr->key);
      corr=corr->next;
    }
  }
}

void fre(lista t){

  while(t!=NULL){
    free(t);
    t=t->next;
  }
}

int main(){
  int dim=0,a=0,b=0,tdim=0,val=0,i=0,p=999149;
  scanf("%d",&dim);
  tdim=2*dim;
  scanf("%d%d",&a,&b);
  table t=(lista*)malloc(sizeof(lista)*tdim);
  for(i=0;i<tdim;i++){
    t[i]=NULL;
  }
  for(i=0;i<dim;i++){
    scanf("%d",&val);
    inserisci(&t[hash(dim,p,a,b,val)],val);
  }
  for(i=0;i<tdim;i++){
    stampa(t[i]);
    printf("\n");
  }
  for(i=0;i<tdim;i++){
    fre(t[i]);
  }
  free(t);


return 0;

/*
5
2
4
3
12
97
18
98*/
}
