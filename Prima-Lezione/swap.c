#include <stdio.h>

void scambia(int *a, int *b,int *c){
  int temp=*a;
  *a=*c;
  *c=*b;
  *b=temp;

}

int main(){
  int a=0,b=0,c=0;
  scanf("%d%d%d",&a,&b,&c);
  scambia(&a,&b,&c);
  printf("%d\n%d\n%d",a,b,c);

return 0;
}
