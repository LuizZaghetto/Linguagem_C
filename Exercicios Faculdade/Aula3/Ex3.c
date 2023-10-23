// Construa um programa que imprima todos os divisores de um número
// inteiro fornecido pelo usuário.

#include <stdlib.h>
#include <stdio.h>


int main() {

    int numeroguri, i;

    printf("Qual o número ");
    scanf("%d", &numeroguri);

    for(i = 1; i <= numeroguri; i++) {

        if(numeroguri % i == 0) {

            printf("%d\n", i);
        }
    }


}