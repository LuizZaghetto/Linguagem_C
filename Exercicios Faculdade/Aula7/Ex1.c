// Construa um programa que seja constituído das seguintes funções:
// • Ler um vetor de inteiros de 20 posíções
// • Função que retorna a quantidade de números pares e a
// quantidade de múltiplos de 5.
// • Função que retorna a média do vetor e quantos valores são maiores que essa média.

#include <stdlib.h>
#include <stdio.h>
#define tam 20

void lerVetor(int v[]) {
    int i;
    for(i = 0; i < tam; i++) {
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", &v[i]);
    }
}
void paresMult5(int v[], int *pares, int *mult5) {
    int i;
    for(i = 0; i < tam; i++) {
        if(v[i] % 2 == 0) {
            *pares = *pares + 1;
        }
        if(v[i] % 5 == 0) {
            *mult5 = *mult5 + 1;
        }
    }
}
void mediaMaior(int v[], float *media, int *maior) {
    int i;
    for(i = 0; i < tam; i++) {
        *media = *media + v[i];
    }
    *media = *media / tam;
    for(i = 0; i < tam; i++) {
        if(v[i] > *media) {
            *maior = *maior + 1;
        }
    }
}
int main() {
    int vetor[tam];
    int pares = 0, mult5 = 0, maior = 0;
    float media = 0;
    lerVetor(vetor);
    paresMult5(vetor, &pares, &mult5);
    mediaMaior(vetor, &media, &maior);
    printf("A quantidade de números pares é %d\n", pares);
    printf("A quantidade de números múltiplos de 5 é %d\n", mult5);
    printf("A média dos valores do vetor é %.2f\n", media);
    printf("A quantidade de valores maiores que a média é %d\n", maior);
}