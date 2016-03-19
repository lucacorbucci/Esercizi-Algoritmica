#include <stdio.h>
#include <stdlib.h>

int intersezione(int a[], int dim1, int b[], int dim2){
int num=0,i=0,j=0;
  while(i<dim1 && j<dim2){
    if (a[i]<b[j])
      i++;
    else if (a[i]>b[j])
      j++;
    else if (a[i]==b[j]) {
      num++;
      i++;
      j++;
    }
  }
return num;
}
int main(){
    int dim1=0, dim2=0,i=0;
    scanf("%d",&dim1);
    int *a=malloc(sizeof(int)*dim1);
    for(i=0;i<dim1;i++){
      scanf("%d",&a[i]);
    }
    scanf("%d",&dim2);
    int *b=malloc(sizeof(int)*dim2);
    for(i=0;i<dim2;i++){
      scanf("%d",&b[i]);
    }
    printf("%d\n",intersezione(a,dim1,b,dim2));

free(a);
free(b);
return 0;
}
