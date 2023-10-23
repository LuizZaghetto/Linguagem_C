// Escreva uma função em C que resulte quantas vezes um dado
// número inteiro ocorre em um vetor de números inteiros
// fornecido (a quantidade de elementos do vetor também será
// fornecida).

#include <stdlib.h>
#include <stdio.h>
#define tam 5

int contaNumVetor(int vetor[], int num, int tamanho) {
    int contador = 0, i;
    for(i = 0; i < tamanho; i++) {
        if(num == vetor[i]) {
            contador++;
        }
    }
    return contador;
}
int main() {
    int v[tam] = {1, 1, 3, 4, 5};
    int vezes, num = 1;
    vezes = contaNumVetor(v, num, tam);
    printf("O número de vezes que o número %d aparece no array é %d", num, vezes);
}