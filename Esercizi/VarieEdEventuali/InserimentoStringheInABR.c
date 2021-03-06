/*
  Inserimento di una stringa in un albero binario di ricerca
  e stampa con le varie visite.
  L'ordinamento dell'ABR viene eseguito tenendo conto della stringa
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct _node{
  char *str;
  struct _node *sx;
  struct _node *dx;
} nodo;

/*
  Inserimento di elementi nell'albero binario di ricerca
*/
void inserisci(nodo **t,char *s){
  nodo* new=(nodo*)malloc(sizeof(nodo));
  if(new==NULL)
    exit(-1);
  new->str=s;
  new->sx=new->dx=NULL;

  if(*t==NULL){
    *t=new;
  }
  else{
    nodo* prec=NULL;
    nodo* corr=*t;
    while(corr!=NULL){
      prec=corr;
      if(strcmp(s,(corr->str))>0)
        corr=corr->dx;
      else corr=corr->sx;
    }
    if(strcmp(s,(prec->str))>0)
      prec->dx=new;
    else prec->sx=new;
  }
}

void visitaanticipata(nodo *t){
  nodo *corr=t;
  if (t==NULL)
    return;
  else{
    printf("%s\n", corr->str);
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
    printf("%s\n",corr->str);
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
    printf("%s\n",corr->str);
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
    free(t->str);
    free(t);
  }
}


int main(){
  int dim=0,i=0;
  char *s=NULL;
  nodo *t=NULL;
  scanf("%d",&dim);

  /*
  Creazione dell'albero
  */
  for(i=0;i<dim;i++){
    s=(char*)malloc(sizeof(char)*MAX);
    scanf("%s",s);
    inserisci(&t,s);
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
