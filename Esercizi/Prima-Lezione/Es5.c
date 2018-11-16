#include <stdio.h>
#include <stdlib.h>

/*
Scrivere una funzione ricorsiva f che, dato un intero N , restituisca la somma dei primi N interi dispari. Scrivere un programma che prenda in input un intero x e stampi il valore di f(x).
L’unica riga dell’input contiene il valore x.
L’unica riga dell’output contiene la somma dei primi x numeri dispari.
*/

int sommaDispari(int N, int index, int sum){
    if(N==0){
        return sum;
    }
    
    if(index == 0){
        index += 1;
    }
    else{
        index += 2;
    }
    sum+=index;
    return sommaDispari(N-1, index, sum);
}

int main(){

    int N = 0, sum = 0;
    scanf("%d",&N);

    printf("%d", sommaDispari(N, 0, sum));

    return 0;
}