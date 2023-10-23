// Escrever um algoritmo que leia uma quantidade desconhecida de
// números e conte quantos deles estão nos seguintes intervalos:
// [0,25], [26,50], [51,75] e [76,100]. A entrada de dados deve
// terminar quando for lido um número negativo.

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {

    int num;
    char continuar;

    do {
        printf("Digite um número: ");
        if (scanf("%d", &num) != 1) {
            printf("Entrada inválida. Encerrando o programa.\n");
            exit(1);
        }

        if (num < 0) {
            printf("Número negativo lido. Encerrando o programa.\n");
            break;
        }

        if (num >= 0 && num <= 25) {
            printf("O número está presente no intervalo de [0, 25]\n");
        } else if (num >= 26 && num <= 50) {
            printf("O número está presente no intervalo de [26, 50]\n");
        } else if (num >= 51 && num <= 75) {
            printf("O número está presente no intervalo de [51, 75]\n");
        } else if (num >= 76 && num <= 100) {
            printf("O número está presente no intervalo de [76, 100]\n");
        } else {
            printf("O número está fora dos intervalos suportados.\n");
        }

        while (1) {
            printf("Deseja digitar outro número? (S/N): ");
            scanf(" %c", &continuar);

            if (continuar == 'S' || continuar == 's') {
                break;
            } else if (continuar == 'N' || continuar == 'n') {
                printf("Encerrando o programa.\n");
                exit(0);
            } else {
                printf("Resposta inválida. Digite 'S' para continuar ou 'N' para encerrar.\n");
            }
        }

    } while (1);

    return 0;
}