#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

typedef struct _nomi{
  char * str;
  char * an;
} nomi;

int comparestruct (void const *a, void const *b){
  nomi a1=*(nomi *)a;
  nomi b1=*(nomi *)b;
  if (strcasecmp(a1.an,b1.an)==0){
    return strcasecmp(a1.str,b1.str);
  }
  else return strcasecmp(a1.an,b1.an);
}

int ordina(const void *a, const void *b){
  char *a1=(char *)a;
  char *b1=(char *) b;
  return strcasecmp(a1,b1);
}

void anagramma(nomi *elenco, int dim){

  qsort(elenco,dim, sizeof(nomi),comparestruct);
  int i=0;

  printf("%s ",elenco[0].str);
  for(i=1;i<dim;i++){
    if(strcmp(elenco[i].an,elenco[i-1].an)==0){
      printf("%s ",elenco[i].str);
    }
    else
    {
      printf("\n");
      printf("%s ",elenco[i].str);
    }
  }
  printf("\n");

}


int main(){
  int dim=0,i=0;
  nomi * elenco;
  scanf("%d",&dim);

  elenco=(nomi *)malloc(sizeof(nomi)*dim);
  for(i=0;i<dim;i++){
    elenco[i].str=malloc(sizeof(char)*MAX);
    elenco[i].an=malloc(sizeof(char)*MAX);
    scanf("%s",elenco[i].str);
    strcpy(elenco[i].an,elenco[i].str);
    qsort(elenco[i].an,strlen(elenco[i].an),sizeof(char),ordina);
  }

  anagramma(elenco, dim);

  for(i=0;i<dim;i++){
    free(elenco[i].str);
    free(elenco[i].an);
  }
  free(elenco);


return 0;
}
