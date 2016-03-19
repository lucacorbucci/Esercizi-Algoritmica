#include <stdio.h>
#define MAX 380

void scambia(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int main(){
int a[MAX], n=0,i=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&(a[i]));
  }
  int dim=n;
  for(i=0;i<dim;i++){
    dim--;
    scambia(&a[i],&a[dim]);

  }
  for(i=0;i<n;i++){
    printf("%d\n",a[i]);
  }
}
