#include <stdio.h>
#include <stdlib.h>

void scambia(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int partition(int a[], int sx, int dx, int *px){
  int i=sx-1, j=sx, k=dx+1,  pivot=a[dx];

  while(j<k){
    if (a[j]<pivot){
      i++;
      scambia(&a[i],&a[j]);
      j++;
    }
    else if (a[j]>pivot){
      k--;
      scambia(&a[k],&a[j]);
    }
    else if (a[j]==pivot){
      j++;
    }
  }
  *px=k;
  return i+1;
}

void threewayquicksort(int a[], int sx, int dx){
  if (sx<dx){
    int px=0;
    int cx=partition(a, sx, dx, &px);
    threewayquicksort(a,sx,cx-1);
    threewayquicksort(a,px,dx);
  }
}

int main(){
  int dim=0,i=0;
  int *a;

  scanf("%d",&dim);
  a=malloc(sizeof(int)*dim);
  for(i=0;i<dim;i++){
    scanf("%d",&a[i]);
  }

  threewayquicksort(a,0,dim-1);

  for(i=0;i<dim;i++)
    printf("%d ",a[i]);
  free(a);
  return 0;
}
