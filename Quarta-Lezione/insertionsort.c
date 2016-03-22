#include <stdio.h>
#include <stdlib.h>

void insertionsort(int a[], int dim){
  int i=0,key=0,j=0;
  for(i=1;i<dim;i++){
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=key;
  }
}

int main(){
  int dim=0,i=0;
  scanf("%d",&dim);
  int *a=(int *)malloc(sizeof(int)*dim);
  for (i=0;i<dim;i++)
    scanf("%d",&a[i]);
  insertionsort(a,dim);
  for (i=0;i<dim;i++){
    printf("%d\n",a[i]);
  }
  free(a);
return 0;
}
