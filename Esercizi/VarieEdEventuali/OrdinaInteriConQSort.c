#include <stdio.h>
#include <stdlib.h>



int compare(const void *a, const void *b){
  int *a1=(int *) a;
  int *b1=(int *) b;

    return (*a1-*b1);

}

void stampa(int *a, int dim){
  int i=0;
  for(i=0;i<dim;i++){
    printf("%d\n",a[i]);
  }
}

int main(){
  int dim=0,i=0;
  int *a;
  scanf("%d",&dim);
  a=malloc(sizeof(int)*dim);
  for (i=0;i<dim;i++){
    scanf("%d",&a[i]);
  }
  qsort(a, dim, sizeof(int), compare);
  stampa(a, dim);
  free(a);

  return 0;
}
