/*
  Inserimento di interi in un albero binario di ricerca
  e stampa con le varie visite.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int key;
  struct _node *sx;
  struct _node *dx;
} nodo;

/*
  Inserimento di elementi nell'albero binario di ricerca
*/
void inserisci(nodo **t,int val){
  nodo* new=(nodo*)malloc(sizeof(nodo));
  if(new==NULL)
    exit(-1);
  new->key=val;
  new->sx=new->dx=NULL;

  if(*t==NULL){
    *t=new;
  }
  else{
    nodo* prec=NULL;
    nodo* corr=*t;
    while(corr!=NULL){
      prec=corr;
      if(val>(corr->key))
        corr=corr->dx;
      else corr=corr->sx;
    }
    if(val>(prec->key))
      prec->dx=new;
    else prec->sx=new;
  }
}

void visitaanticipata(nodo *t){
  nodo *corr=t;
  if (t==NULL)
    return;
  else{
    printf("%d\n",corr->key);
    visitaanticipata(corr->sx);
    visitaanticipata(corr->dx);
  }
}

void visitasimmetrica(nodo *t){
  nodo *corr=t;
  if (t==NULL)
    return;
  else{
    visitasimmetrica(corr->sx);
    printf("%d\n",corr->key);
    visitasimmetrica(corr->dx);
  }
}

void visitaposticipata(nodo *t){
  nodo *corr=t;
  if (t==NULL)
    return;
  else{
    visitaposticipata(corr->sx);
    visitaposticipata(corr->dx);
    printf("%d\n",corr->key);
  }
}

/*
  Funzione che libera la memoria allocata per l'albero.
*/
void memf(nodo *t){
  if(t==NULL){
    return;
  }
  else{
    memf(t->dx);
    memf(t->sx);
    free(t);
  }
}


int main(){
  int dim=0,i=0,val=0;
  nodo *t=NULL;
  scanf("%d",&dim);

  /*
  Creazione dell'albero
  */
  for(i=0;i<dim;i++){
    scanf("%d",&val);
    inserisci(&t,val);
  }

  /*
  Stampa dell'albero in vari modi
  */
  printf("---Anticipata---\n");
  visitaanticipata(t);
  printf("---Simmetrica---\n");
  visitasimmetrica(t);
  printf("---Posticipata---\n");
  visitaposticipata(t);

  /*
  Libero la memoria
  */
  memf(t);

return 0;
}
