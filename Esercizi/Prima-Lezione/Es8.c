#include <stdio.h>
#include <stdlib.h>

/*
Scrivere una funzione minmax avente i seguenti parametri
• un array di interi;
• la lunghezza dell’array;
• un puntatore a una variabile intera min; • un puntatore a una variabile intera max.
La funzione scandisce l’array e salva in min la posizione in cui si trova l’elemento minimo e in max la posizione in cui si trova l’elemento massimo. Si pu`o assumere che l’array contenga valori distinti.
Scrivere poi un programma che
• legga 10 interi da tastiera;
• invochi minmax sull’array letto;
• produca in output: la posizione dell’elemento minimo, il valore dell’e- lemento minimo, la posizione dell’elemento massimo, il valore dell’ele- mento massimo.
L’input `e formato da dieci righe contenenti gli elementi dell’array.
L’output `e formato da quattro righe contenenti la posizione dell’elemento minimo, il valore dell’elemento minimo, la posizione dell’elemento massimo, il valore dell’elemento massimo.
*/

void minmax(int a[], int dim, int *min, int *max){
    int index = 0;
    for(index=0;index<dim;index++){     
        if(a[index] > a[*max]){
            *max = index;
        }
        if(a[index] < a[*min]){
            *min = index;
        }
    }
}

int main(){
    int dim = 10, i = 0, min = 0, max = 0;
    int a[10];

    for(i=0;i<dim;i++){
        a[i] = 0;
        scanf("%d", &a[i]);
    }

    minmax(a,10,&min, &max);

    printf("%d\n", min);
    printf("%d\n", a[min]);
    printf("%d\n", max);
    printf("%d\n", a[max]);

    return 0;
}