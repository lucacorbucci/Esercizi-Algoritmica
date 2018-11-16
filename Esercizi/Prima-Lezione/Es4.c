#include <stdio.h>
#include <stdlib.h>

/*
Scrivere un programma che legga da input gli N interi di un array A. Il pro- gramma deve invertire A in loco (cio`e senza utilizzare un array di appoggio), ossia scambiare il contenuto della prima e dell’ultima cella, della seconda e della penultima, ecc.
Si assuma che N ≤ 10000.
La prima riga dell’input `e il valore N. Seguono N interi, uno per riga.
Il programma stampa in output gli elementi dell’array invertito, uno per riga.
*/

int main(){
    int dim = 0, FIndex = 0, LIndex = 0, i = 0, tmp = 0;        

    scanf("%d", &dim);
    int a[dim];
    

    LIndex = dim-1;

    for(i=0; i<dim; i++){
        a[i] = 0;
        scanf("%d", &a[i]);
    }


    for (FIndex = 0; FIndex < dim / 2; FIndex++){
        tmp = a[FIndex];
        a[FIndex] = a[LIndex];
        a[LIndex] = tmp;
        LIndex--;
    }

    for (i = 0; i < dim; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}