#include <stdlib.h>
#include <stdio.h>

struct point{
  int x;
  int y;
};

void swap(struct point *p){
  int temp=p->x;
  p->x=p->y;
  p->y=temp;
}

int main(){
  struct point *p;
  p=(struct point *)malloc(sizeof(struct point));
  scanf("%d", &(p->x));
  //p->x=10;
  p->y=15;
  swap(p);
  printf("%d\n%d\n",p->x, p->y);
  printf("It Worked!")
return 0;
}
