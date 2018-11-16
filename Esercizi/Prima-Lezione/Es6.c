#include <stdio.h>
#include <stdlib.h>

/*
Implementare la funzione swap(int *a, int *b) che scambi il contenuto delle due variabili.
Scrivere poi un programma che legga da input il valore di due varia- bili intere a e b e utilizzi la funzione swap per scambiare i loro valori. Il programma deve quindi stampare il valore di a e b dopo questa operazione. Le due righe dell’input contengono il valore di a e b.
Le due righe dell’output contengono il valore di a e b dopo lo scambio.
*/

void swap(int * a, int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a = 0, b = 0; 
    scanf("%d", &a);
    scanf("%d", &b);

    swap(&a, &b);
    printf("%d\n%d\n", a, b);
    return 0;
}