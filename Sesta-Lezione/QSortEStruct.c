#include <stdio.h>
#include <stdlib.h>


typedef struct _point{
  int x;
  int y;
} point;

int compare (void const *a, void const *b){
  point *a1=(point *)a;
  point *b1=(point *)b;
  if ((a1->x)==(b1->x)){
    return ((b1->y)-(a1->y));
  }
  else
    return ((a1->x)-(b1->x));
}


int main(){
  point *p;
  int dim=0,i=0;
  scanf("%d",&dim);
  p=malloc(sizeof(point)*dim);
  for (i=0;i<dim;i++){
    scanf("%d",&(p[i].x));
    scanf("%d",&(p[i].y));
  }

  qsort(p, dim, sizeof(point), compare);

  for (i=0;i<dim;i++){
    printf("%d ",p[i].x);
    printf("%d\n",p[i].y);
  }
  free(p);
return 0;
}
