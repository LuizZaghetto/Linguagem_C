// Elabore um programa que leia três números reais e imprima o maior e
// o menor número lido . O programa deverá ser constituído de duas funções:
// • Uma função para ler os números reais
// • Uma função para determinar quem é o maior e quem é o menor.
// Esta função terá como parâmetro os 3 valores a serem analisados
// e retornará para o principal quem é o maior quem é o menor.

#include <stdlib.h>
#include <stdio.h>
#define tam 3


void leNum(float vetor[]) {
    int i;
    for(i = 0; i < tam; i++) {
        printf("Digite o número da posição %d \n", i);
        scanf("%f", &vetor[i]);
    }
}
void determinaNum(float vetor[], float *maior, float *menor) {
    int i;
    *maior = vetor[0];
    *menor = vetor[0];
    for(i = 0; i < tam; i++) {
        if(vetor[i] < *menor) {
            *menor = vetor[i];
        }if(vetor[i] > *maior) {
            *maior = vetor[i];
        }
    }   
}
int main() {
    float vetor2[tam], maiornum, menornum;
    leNum(vetor2);
    determinaNum(vetor2, &maiornum, &menornum);
    printf("O maior número é %.2f e o menor é %.2f\n", maiornum, menornum);
}