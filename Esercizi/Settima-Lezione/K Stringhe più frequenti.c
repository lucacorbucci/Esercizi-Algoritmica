#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct _cnt{
  char * str;
  int cnt;
}conta;

//Compare per le stringhe
int compare(const void *a, const void *b){
  char *a1=*((char **)a);
  char *b1=*((char **)b);
  return strcasecmp(a1,b1);
}

//Compare per le struct
int comparestruct (void const *a, void const *b){
  conta a1=*(conta *)a;
  conta b1=*(conta *)b;
  return ((a1.cnt)-(b1.cnt));
}

/*
Funzione che prende le prime k stringhe che compaiono maggiormente
nell'array di stringhe che passo
*/
char ** kpre(char **strr, int dim, int k){
  /*
  Alloco una struct di spazio dim per contenere al massimo tutti gli elementi
  dell'array che passo con il rispettivo numero di volte che compaiono nell'array
  Poi alloco un array di k posizioni per il risultato.
  */
  conta *p;
  p=(conta*) malloc(sizeof(conta)*dim);
  int i=0, tr=0;;
  char **arr;
  arr=(char **)malloc(sizeof(char*)*k);

  p[0].str=strr[0];
  p[0].cnt=1;

  for(i=1;i<dim;i++){
    if (strcasecmp(strr[i],strr[i-1])!=0){
      tr++;
      p[tr].str=strr[i];
      p[tr].cnt=1;
    }
    else {
      p[tr].cnt++;
    }
  }

  //Ordinamento della struct
  qsort(p,tr+1,sizeof(conta),comparestruct);

  /*
  Sposto nell'array risultato i k elementi che compaiono maggiormente
  */
  i=0;
  for(i=0;i<k;i++){
    arr[i]=(char*)malloc(sizeof(char)*MAX);
    arr[i]=(p[tr].str);
    tr--;
  }

  free(p);

return arr;
for(i=0;i<k;i++){
  free(arr[i]);
}
free(arr);

}

int main(){
  int dimstr=0, k=0,i=0;
  char **str, **final;

  //Prendo la dimensione del mio array di stringhe e la K
  scanf("%d",&dimstr);
  scanf("%d",&k);

  //Alloco i vari array che mi servono, final serve per il risultato
  //str serve per mettere le stringhe
  final=(char **)malloc(sizeof(char *)*k);
  str=(char **)malloc(sizeof(char *)*dimstr);;
  for(i=0;i<dimstr;i++){
    str[i]=(char *)malloc(sizeof(char)*MAX);
    scanf("%s",str[i]);
  }

  //Chiamo qsort per ordinare le stringhe dell'array str
  qsort(str ,dimstr,sizeof(char *), compare);

  //Chiamo la funzione kpre e il risultato finisce in final
  //poi ordino pure final
  final=kpre(str,dimstr,k);
  qsort(final,k,sizeof(char *), compare);

  //Stampo l'array soluzione
  for(i=0;i<k;i++){
    printf("%s\n",final[i]);
  }

  //Libero la memoria

  for(i=0;i<k;i++){
    free(final[i]);
  }
  free(final);
  for(i=0;i<dimstr;i++){
    free(str[i]);
  }
  free(str);



  return 0;
}
