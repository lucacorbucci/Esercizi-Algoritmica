#include <stdio.h>
#include <stdlib.h>

void scambia(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

/*Ordinamento di array con il selectionsort*/
void selectionsort(int a[], int n){
  int i=0, j=0, min=0;
  for (j=0; j<n-1;j++){
    min=j;
    for(i=j+1;i<n;i++){
      if (a[i]<a[min])
        min=i;
    }
    scambia(&a[min],&a[j]);
  }
}

int main(){
  int dim=0,i=0;
  scanf("%d",&dim);
  int *a=(int *)malloc(sizeof(int)*dim);
  for(i=0;i<dim;i++)
    scanf("%d",&a[i]);
  selectionsort(a, dim);
  for(i=0;i<dim;i++)
    printf("%d\n",a[i]);
  free(a);
}
