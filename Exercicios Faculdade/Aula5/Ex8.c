// Dado dois vetores, A (5 elementos) e B (8 elementos), faça um
// programa em C que imprima todos os elementos comuns aos dois
// vetores.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    int vA[5], vB[8], vC[8], i, j, pos = 0;

    printf("Leitura do vetor A:\n");
    for (i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &vA[i]);
    }
    printf("Leitura do vetor B:\n");
    for (i = 0; i < 8; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &vB[i]);
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 8; j++) {
            if (vA[i] == vB[j]) {
                vC[pos] = vA[i];
                pos++;
            }
        }
    }

    printf("Elementos comuns aos vetores A e B:\n");
    for (i = 0; i < pos; i++) {
        printf("%d\n", vC[i]);
    }

    return 0;
}