#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

int comparestring(const void * a, const void *b){
  char **a1=(char **)a;
  char **b1=(char **)b;
  return (-1*(strcmp (*a1,*b1)));
}

int main(){
int dim=0, i=0;
char **str;
scanf("%d",&dim);
str=malloc(dim*sizeof(char*));
for(i=0;i<dim;i++){
  str[i]=malloc(sizeof(char)*MAX);
  scanf("%s",str[i]);
}

qsort(str, dim, sizeof(char *), comparestring);

for(i=0;i<dim;i++){
  printf("%s\n",str[i]);
}

for(i=0;i<dim;i++){
  free(str[i]);
}
free(str);
return 0;
}
