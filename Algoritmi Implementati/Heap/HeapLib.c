#include <stdio.h>
#include <stdlib.h>
#include "HeapLib.h"

void MaxHeapify(int a[], int size, int i){
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = -1;
    if(a[left] > a[i] && left < size){
        largest = left;
    }
    else{
        largest = i;
    }
    if(a[right]>a[largest] && right < size){
        largest = right;
    }

    if(i != largest){
        int tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        MaxHeapify(a, size, largest);
    }
    
}

void BuildMaxHeap(int a[], int size){
    int i = 0;
    for(i=size/2; i>=0; i--){
        MaxHeapify(a, size, i);
    }
}

void HeapSort(int a[], int size){
    int i=0;
    BuildMaxHeap(a, size);
    int j=0;
    for(i = size-1; i>=1; i--){
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        size--;

        MaxHeapify(a, size, 0);
    }
}
