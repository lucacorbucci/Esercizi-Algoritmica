#include <stdio.h>
#include <stdlib.h>

/*
Scrivere un programma che legga da tastiera un intero e stabilisca se il numero `e primo.
L’input consiste di una sola riga contente l’intero x.
Il programma stampa in output 1 se x `e primo, 0 altrimenti.
*/

int isPrimo(int value){
    int i = 1;
    if (value == 1){
        return 1;
    }
    else if (value == 0){
        return 0;
    }

    for (i = 2; i < value - 1; i++){
        if (value % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int value = 0;
    scanf("%d", &value);

    printf("%d\n", isPrimo(value));

    return 0;
}