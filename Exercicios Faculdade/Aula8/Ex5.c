// Faça uma função recursiva que receba um número inteiro
// positivo par N e imprima todos os números pares de 0 até N
// em ordem crescente. 

#include <stdio.h>
#include <stdlib.h>

void imprimePar(int n) {
    if(n == 0) {
        return;
    }
    else {
        imprimePar(n - 1);
        if(n % 2 == 0) {
            printf("%d\n", n);
        }
    }
}

int main() {
    imprimePar(15);
    return 0;
}