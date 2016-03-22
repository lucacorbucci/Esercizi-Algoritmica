#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

void insertionsort(char *a[],int dim){
  int i=0,j=0;
  char *key=malloc(sizeof(char)*MAX);
  for(i=1;i<dim;i++){
    key=a[i];
    j=i-1;
    while(j>=0 && strcmp(a[j],key)>0){
      a[j+1]=a[j];
      j--;

    }
    a[j+1]=key;
  }

}

int main(){
  int n=0, i=0;
  scanf("%d",&n);
  char **s;
  s=(char**)malloc(sizeof(char*)*n);
  for(i=0;i<n;i++){
    s[i]=(char*)malloc(sizeof(char)*MAX);
    scanf("%s",s[i]);
  }

  insertionsort(s,n);
  for (i=0;i<n;i++){
    printf("%s\n",s[i]);
  }
  free(s);
return 0;
}
