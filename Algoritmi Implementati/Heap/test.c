#include <stdio.h>
#include <stdlib.h>
#include "HeapLib.h"



int main(){
    int i=0, j=9;
    int * array = malloc(sizeof(int)*10);
    array[0]=0;
    
    for(i=1;i<11;i++){
        array[i] = j;
        j--;
    }

    /*
        Test della procedura MaxHeapify sull'array in cui destra
        e sinistra sono ordinate ma il nodo root è 0 quindi va spostato.
    */
    MaxHeapify(array,10,0);
    printf("MaxHeapify\n");
    for(i=0;i<10;i++){
        printf("%d\n",array[i]);
    }

    for(i=0;i<10;i++){
        array[i] = i;
    }

    printf("HeapSort\n");

    HeapSort(array, 10);
    for(i=0;i<10;i++){
        printf("%d\n",array[i]);
    }
}