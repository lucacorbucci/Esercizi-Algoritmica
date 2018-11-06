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


//Compare per le struct
int comparestruct (void const *a, void const *b){
  punto *a1=*(punto **)a;
  punto *b1=*(punto **)b;
  return ((a1->c)-(b1->c));
}


/*
Funzione che confronta ogni punto e vede se questo appartiene al rettangolo o no
*/
void check(punto **point, rettangolo **rett, int n, int m){
  int i=0, conta=0,k=0, temp=-1;
  for(i=0;i<m;i++){
    conta=0;
    temp=-1;
    
    for(k=0;k<n;k++){
      if(point[k]->x >= rett[i]->x
        && point[k]->x <= rett[i]->t
        && point[k]->y >= rett[i]->y
        && point[k]->y <= rett[i]->z
        && temp!=point[k]->c){

        temp=point[k]->c;
        conta++;
      }
    }
    printf("%d\n",conta);
  }
}



int main(){
  int n=0,m=0,i=0;
  int a=0,b=0,c=0;
  punto ** point;
  rettangolo ** rett;

  /*
  Prendo n e m e poi alloco il punto e il rettangolo necessario.
  */
  scanf("%d",&n);
  scanf("%d",&m);
  point=(punto **)malloc(sizeof(punto *)*n);
  rett=(rettangolo **)malloc(sizeof(rettangolo *)*m);

  for(i=0;i<n;i++){
    point[i]=(punto *)malloc(sizeof(punto));
    scanf("%d %d %d",&point[i]->x, &point[i]->y, &point[i]->c);
  }

  for(i=0;i<m;i++){
    rett[i]=(rettangolo *)malloc(sizeof(rettangolo));
    scanf("%d %d %d %d", &rett[i]->x,&rett[i]->y,&rett[i]->t, &rett[i]->z);
  }

  //Ordinamento della struct con i punti
  qsort(point,n,sizeof(punto *),comparestruct);


  check(point, rett, n, m);

  //Free sulla memoria
  for(i=0;i<n;i++){
    free(point[i]);
  }
  for(i=0;i<m;i++){
    free(rett[i]);
  }
  free(point);
  free(rett);


return 0;
}
