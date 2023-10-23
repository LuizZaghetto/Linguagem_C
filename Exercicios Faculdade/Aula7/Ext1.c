// Escreva uma função em C que resulte a soma dos elementos de
// um vetor de números inteiros dado (a quantidade de
// elementos do vetor também será fornecida). 

#include <stdlib.h>
#include <stdio.h>
#define tam 5

int soma(int v[], int N) {
    int i, soma;
    for(i = 0; i < N; i++) {
        soma = soma + v[i];
    }
    return soma;
}
int main() {
    int vetor[tam] = {1, 2, 3, 4, 5};
    int somatotal = soma(vetor, tam);
    printf("A soma de todos os valores do vetor é %d", somatotal);
}