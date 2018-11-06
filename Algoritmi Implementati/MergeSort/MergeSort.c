#include <stdio.h>
#include <stdlib.h>
#include "Mergesort.h"

void merge(int a[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int left[n1+1];
    int right[n2+1];
    int i = 0, j = 0, k = 0;


    for(i=0; i<n1; i++){
        left[i] = a[p+i];
    }

    for(j=0; j<n2; j++){
        right[j] = a[q+j+1];
    }
    left[i] = 999999;
    right[j] = 999999;
    
    i = 0;
    j = 0;
    for(k=p; k<r; k++){
        if(left[i]<=right[j]){
            a[k]=left[i];
            i+=1;
        }
        else{
            a[k]=right[j];
            j+=1;
        }
    } 
}

void mergeSort(int a[], int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);
    }
}