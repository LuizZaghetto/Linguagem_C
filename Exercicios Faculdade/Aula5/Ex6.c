// Elabore um programa que crie um vetor de 10 posições onde o
// conteúdo desse vetor seja o dobro do valor da sua posição.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define tam 10

int main() {

    int i, v[tam] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(i = 0; i < tam; i++) {
        v[i] = v[i] * 2;
        printf("%d\n", v[i]);
    }

    return 0;
}