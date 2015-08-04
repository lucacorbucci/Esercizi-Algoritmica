#include <stdio.h>
#include <stdlib.h>

int scambia(int *a,int *b){
int temp=0;
	temp=*a;
	*a=*b;
	*b=temp;
}
	

int stampa(int a[],int n){
int i=0;
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}

int ordina01(int a[],int n){
int i=0,j=-1;
	for(i=0;i<n;i++){
		if (a[i]==0){
			j++;
			scambia(&a[i],&a[j]);
		}
	}
}

int main(){
int i=0,n=0;
int *a;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	ordina01(a,n);
	stampa(a,n);

return 0;
}
