#include <stdio.h>
#include <stdlib.h>

/*
Scrivere un programma che legga da tastiera una sequenza di numeri interi 
terminata da 0 e ne stampi la somma.
L’input una sequenza di numeri interi terminata da 0, un intero per riga.
Il programma stampa in output la somma degli interi.
*/

int main(){

    int tmp = -1, sum = 0;

    while(tmp != 0){
        scanf("%d", &tmp);
        sum+=tmp;
    }

    printf("%d\n", sum);

    return 0;
}