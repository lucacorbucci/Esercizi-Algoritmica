#include <stdio.h>
#include <stdlib.h>

/*Funzione che prende due array in input e restituisce in output
l'unione ordinata dei due array. L'intersezione degli array è vuota*/
int* fusione(int a[], int dim1, int b[], int dim2){
  int n=dim1+dim2;
  int *res=malloc(sizeof(int)*(n));
  int i=0,j=0,ind=0;

  while(i<dim1 && j<dim2){
    if (a[i]<b[j]){
      res[ind]=a[i];
      i++;
    }
    else {
      res[ind]=b[j];
      j++;
    }
    ind++;
  }

if (i<dim1){
  while(i<dim1){
    res[ind]=a[i];
    i++;
    ind++;
  }
}
else{
  while(j<dim2){
    res[ind]=b[j];
    j++;
    ind++;
  }
}



return res;
}


int main(){
  int dim1=0, dim2=0,i=0;

  scanf("%d",&dim1);
  int *a=malloc(sizeof(int)*dim1);
  for (i=0;i<dim1;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&dim2);
  int *b=malloc(sizeof(int)*dim2);
  for(i=0;i<dim2;i++){
    scanf("%d",&b[i]);
  }

  int *result=malloc(sizeof(int)*(dim1+dim2));
  result= fusione(a,dim1,b, dim2);
  for(i=0;i<(dim1+dim2);i++){
    printf("%d\n",result[i]);
  }

  free(a);
  free(b);
  free(result);
return 0;
}
