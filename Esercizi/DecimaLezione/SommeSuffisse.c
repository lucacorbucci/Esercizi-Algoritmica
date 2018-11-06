#include <stdio.h>
#include <stdlib.h>

typedef struct _elem{
  int key;
  struct _elem* next;
} lista;

lista* crealista(int val){
  lista *new=(lista*)malloc(sizeof(lista));
  new->key=val;
  new->next=NULL;
  return new;
}

lista* append(lista* l, int val){
  l->next=(lista*)malloc(sizeof(lista));
  l->next->key=val;
  l->next->next=NULL;
  return l->next;
}

void stampa(lista *l){
  if(l==NULL)
    return;
  else{
    printf("%d ",l->key);
    stampa(l->next);
  }
}

int sommasuffissa(lista *l){
  if(l==NULL)
    return 0;

  else{
    if(l->next!=NULL)
      return (l->key)=(l->next->key)+sommasuffissa(l->next);
    else if(l->next==NULL)
      return (l->key)=sommasuffissa(l->next);
  }
}

int main(){
  int dim=0,val=0,i=0;
  scanf("%d",&dim);
  lista *l;
  lista *corr;
  scanf("%d",&val);
  l=crealista(val);
  corr=l;
  for(i=0;i<dim-1;i++){
    scanf("%d",&val);
    corr=append(corr,val);
  }

  stampa(l);
  sommasuffissa(l);
  printf("\n");
  stampa(l);

  while(l!=NULL){
    free(l);
    l=l->next;
  }
return 0;
}
