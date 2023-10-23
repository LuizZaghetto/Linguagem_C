// Elabore um programa em C que possua uma função recursiva que calcule a soma dos elementos reais de um vetor de 
// no máximo 10 posições.O resultado deve ser impresso no programa principal.

#include <stdio.h>
#include <stdlib.h>
#define tam 10

float calculaSomaVetor(float v[],int tamanho) {
    if(tamanho == 0) {
        return 0;
    }
    return v[0] + calculaSomaVetor(v + 1, tamanho - 1); 
} 

int main() {

    float array[10] = {1.5, 2, 5.9, 6, 7, 8, 9, 10.5, 39, 47.5};
    float somavetor = calculaSomaVetor(array, tam);
    printf("%.4f", somavetor);
}