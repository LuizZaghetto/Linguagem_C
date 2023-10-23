// 1. Sejam a e b inteiros e não negativos, elabore um
// algoritmo iterativo para calcular a*b usando somente a operação de adição.
// 2. Refaça o algoritmo anterior na forma recursiva.
// 3. Faça uma função recursiva que permita somar os elementos de um vetor de inteiros.

#include <stdio.h>
#include <stdlib.h>
#define tam 10

int calculaIterativo(int a, int b) {
    int i;
    int aoriginal = a;
    if(a < 0 || b < 0 ) {
        printf("Algum dos dois números é negativo, coloque os dois números como positivos");
        return 0;
    }
    for(i = 1; i < b; i++) {
        a = a + aoriginal;
    }
    return a;
}
int calcularRecursivo(int a, int b) {
    if(a < 0 || b < 0 ) {
    printf("Algum dos dois números é negativo, coloque os dois números como positivos");
    return 0;
    }
    if(b == 0) {
        return 0;
    }
    return a + calcularRecursivo(a, b - 1);
}
int calculaSomaVetor(int v[tam], int tamanho) {
    if(tamanho == 0) {
        return 0;
    }
    return v[0] + calculaSomaVetor(v + 1, tamanho - 1);
}
int main() {
    int num = calculaIterativo(4, 5);
    printf("%d\n", num);
    int num2 = calcularRecursivo(5, 5);
    printf("%d\n", num2);
    int array[tam] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int somavetor = calculaSomaVetor(array, tam);
    printf("%d\n", somavetor);


    return 0;
}