#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"

int partition(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    int j = 0;
    for(j = p; j < r; j++){
        if(a[j] <= x){
            i+=1;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    int tmp = a[i+1];
    a[i+1] = a[r];
    a[r] = tmp;
    return i+1;
}

void quicksort(int a[], int p, int r){
    if(p<r){
        int q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}