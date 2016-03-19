#include <stdio.h>

void minmax(int a[], int dim, int *min, int *max){
  int i=0;
  *min=0;
  *max=0;
  for (i=1;i<dim;i++){
    if (a[i]<a[*(min)]){
      *min=i;
    }
    if (a[i]>a[(*max)]){
      *max=i;
    }
  }
}

int main(){
  int a[10], dim=10,i=0;
  int min, max;
  for (i=0;i<dim;i++){
    scanf("%d",&a[i]);
  }
  minmax(a, dim, &min, &max);
  printf("%d\n%d\n%d\n%d\n",min,a[(min)],max, a[(max)]);

return 0;
}
