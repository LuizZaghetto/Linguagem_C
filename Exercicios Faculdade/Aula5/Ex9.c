// Crie um programa que armazene 10 números digitados pelo usuário
// em dois vetores: um somente para números pares, e outro somente
// para números ímpares.

#include <stdio.h>
#include <locale.h>
#define TAM 10

int main() {
    setlocale(LC_ALL, "portuguese");

    int vA[TAM], vB[TAM], num, vAindex = 0, vBindex = 0;

    printf("Leitura do vetor (Não são permitidos valores 0):\n");

    for (int i = 0; i < TAM; i++) {
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", &num);

        if (num == 0) {
            printf("O valor é inválido. Digite outro valor diferente de zero.\n");
            i--;
            continue;
        }

        if (num % 2 == 0) {
            vA[vAindex] = num;
            vAindex++;
        } else {
            vB[vBindex] = num;
            vBindex++;
        }
    }

    printf("\nValores pares:\n");
    for (int i = 0; i < vAindex; i++) {
        printf("%d\n", vA[i]);
    }

    printf("\nValores ímpares:\n");
    for (int i = 0; i < vBindex; i++) {
        printf("%d\n", vB[i]);
    }

    return 0;
}
