#include <stdio.h>

void scambia(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int main(){
  int a=0,b=0;
  scanf("%d%d",&a,&b);
  scambia(&a,&b);
  printf("%d%d\n",a,b);


return 0;
}
