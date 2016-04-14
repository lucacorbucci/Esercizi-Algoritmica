#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct _stringhe{
  char *s;
  int dim;
} string;

int compare (const void *a, const void *b){
  string *a1=(string *) a;
  string *b1=(string *) b;
  if (a1->dim==b1->dim){
    return strcmp((a1->s), (b1->s));
  }
  else return ((a1->dim)-(b1->dim));
}

int main(){
  int dim=0,i=0;
  string *p;
  scanf("%d",&dim);
  p=malloc(sizeof(string)*dim);
  for(i=0;i<dim;i++){
    (p[i].s)=malloc(sizeof(char)*MAX);
    scanf("%s",(p[i].s));
    p[i].dim=strlen(p[i].s);
  }

  qsort(p,dim, sizeof(string),compare);

  for(i=0;i<dim;i++){
    printf("%s\n",p[i].s);
  }
  for(i=0;i<dim;i++){
    free(p[i].s);
  }
  free(p);
return 0;
}
