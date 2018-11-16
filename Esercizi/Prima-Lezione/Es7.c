#include <stdio.h>
#include <stdlib.h>

/*
Implementare una funzione tswap(int *x, int *y, int *z) che riceva in input tre variabili e ne scambi i valori in modo che
• x prenda il valore di z; 
• y prenda il valore di x; 
• z prenda il valore di y.
Leggere da input un array di 3 interi e invocare la funzione passando gli indirizzi delle 3 celle in ordine.
Scrivere poi un programma che legga da input il valore di tre variabili intere a, b e c e utilizzi la funzione tswap per scambiare i loro valori.
Le tre righe dell’input contengono il valore di a, b e c .
Le tre righe dell’output contengono il valore di a, b e c dopo lo scambio.
*/

void tswap(int *x, int *y, int *z){
    int tmp1 = *x;
    int tmp2 = *y;
    *x = *z;
    *y = tmp1;
    *z = tmp2;    
}

int main(){

    int dim = 3, i = 0;

    int *a = malloc(sizeof(int)*dim);

    for(i=0;i<dim;i++){
        scanf("%d", &a[i]);
    }

    tswap(&a[0], &a[1], &a[2]);

    for (i = 0; i < dim; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}