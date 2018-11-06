#include <stdio.h>
#include <stdlib.h>

int sommamassima(int a[], int dim){
  int i=0, somma=0,max=0;
  for (i=0;i<dim;i++){
    if (somma<0 && a[i]>0)
      somma=a[i];
    else somma+=a[i];

    if (somma>max)
      max=somma;

  }
return max;
}

int main(){
  int dim=0,i=0;
  scanf("%d",&dim);
  int *a=(int *)malloc(sizeof(int)*dim);
  for(i=0;i<dim;i++){
    scanf("%d",&a[i]);
  }
  printf("%d\n",sommamassima(a,dim));
free(a);
return 0;
}
