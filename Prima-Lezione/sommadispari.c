#include <stdio.h>

int somma(int a){

  if (a==1)
    return 1;
  else
    return (a*2)-1+somma(a-1);
  }

int main(){
  int n=0;
  scanf("%d",&n);
  printf("%d\n",somma(n));

return 0;
}
