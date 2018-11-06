/*
  Esame del 13/06/2014
  Trovate altezza e profondità di ogni nodo e poi confrontarli
  se sono uguali si stampa il nodo.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int key;
  struct _node* sx;
  struct _node* dx;
} nodo;

typedef nodo * albero;

void inserisci(albero *a, int val){
  albero new=(albero)malloc(sizeof(nodo));
  new->key=val;
  new->sx=NULL;
  new->dx=NULL;
  if(*a==NULL)
    *a=new;
  else{
    albero prec=NULL;
    albero corr=*a;
    while(corr!=NULL){
      prec=corr;
      if(val > corr->key)
        corr=corr->dx;
      else
        corr=corr->sx;
    }
    if(val > prec->key)
      prec->dx=new;
    else
      prec->sx=new;
  }
}

void stampa(albero a){
  if(a==NULL)
    return;
  else{
    printf("%d",a->key);
    stampa(a->sx);
    stampa(a->dx);
  }
}

int altezza(albero a,int prof){
  int altdx=0,altsx=0,alt=0;
  if(a->sx==NULL && a->dx==NULL){
    alt=0;

    if(alt==prof)
      printf("%d\n",a->key);
    return alt;

  }
  else if(a->dx==NULL){

    altsx=altezza(a->sx,prof+1);


    alt=altsx+1;
    if(alt==prof)
      printf("%d\n",a->key);
    return alt;
  }
  else if(a->sx==NULL){

    altdx=altezza(a->dx,prof+1);

    alt=altdx+1;
    if(alt==prof)
      printf("%d\n",a->key);
    return alt;
  }


  else {

    altsx=altezza(a->sx,prof+1);
    altdx=altezza(a->dx,prof+1);

    if(altsx < altdx)
      alt=altsx+1;
    else
      alt=altdx+1;

    if(alt==prof)
      printf("%d\n",a->key);

    return alt;
  }
}

int main(){
  int i=0,val=0,n=0;
  albero a=NULL;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&val);
    inserisci(&a,val);
  }
  int k=0;
  altezza(a,k);


  return 0;
}
