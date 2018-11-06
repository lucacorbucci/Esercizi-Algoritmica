#include <stdio.h>
#include <stdlib.h>
#include "InsertionSort.h"

void InsertionSort(int a[], int size){
    int j = 0;
    int i = 0;
    int key = 0;

    for(j=1; j<size; j++){
        key = a[j];
        i = j-1;
        while(i>=0 && a[i]>key){
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
    }
}