#include <stdio.h>
#include <stdlib.h>

typedef struct _point{
  int x;
  int y;
  int c;
} punto;

typedef struct _rettangolo{
  int x;
  int y;
  int t;
  int z;
} rettangolo;

void check(punto **point, rettangolo **rett, int n, int m){
  int i=0, conta=0,k=0;
  for(i=0;i<m;i++){
    conta=0;
    for(k=0;k<n;k++){
      if(point[k]->x >= rett[i]->x
        && point[k]->x <= rett[i]->t
        && point[k]->y >= rett[i]->y
        && point[k]->y <= rett[i]->z)

        conta++;
    }
    printf("%d\n",conta);
  }
}



int main(){
  int n=0,m=0,i=0;
  int a=0,b=0,c=0;
  punto ** point;
  rettangolo ** rett;

  scanf("%d",&n);
  scanf("%d",&m);
  point=(punto **)malloc(sizeof(punto *)*n);
  rett=(rettangolo **)malloc(sizeof(rettangolo *)*m);

  for(i=0;i<n;i++){
    point[i]=(punto *)malloc(sizeof(punto));
    scanf("%d %d %d",&a, &b, &c);
    if(a>0 && b>0){
    point[i]->x=a;
    point[i]->y=b;
    point[i]->c=c;
  }
}

  for(i=0;i<m;i++){
    rett[i]=(rettangolo *)malloc(sizeof(rettangolo));
    scanf("%d %d %d %d", &rett[i]->x,&rett[i]->y,&rett[i]->t, &rett[i]->z);
  }

  check(point, rett, n, m);


  //Stampa di prova di tutti gli elementi presenti nelle due strutture.

  for(i=0;i<n;i++){
    printf("%d %d %d\n",point[i]->x, point[i]->y, point[i]->c);
  }
  for(i=0;i<m;i++){
    printf("%d %d %d %d\n", rett[i]->x,rett[i]->y,rett[i]->t, rett[i]->z);
  }



return 0;
}
