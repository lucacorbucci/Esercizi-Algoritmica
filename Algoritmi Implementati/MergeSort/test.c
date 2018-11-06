#include <stdio.h>
#include <stdlib.h>
#include "Mergesort.h"

int main(){
    int i = 0;
    int a[] = {6,9,1,2,4,10,3,7,8,5};

    mergeSort(a, 0, 9);

    for(i=0;i<10;i++){
        printf("%d\n", a[i]);
    }

    return 0;
}