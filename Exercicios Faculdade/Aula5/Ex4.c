// Elabore um programa que recebe 20 valores e os armazene em um
// vetor. O programa deve ainda ter um outro vetor de 10 posições que
// recebe a soma de dois valores do primeiro vetor.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define tam 20

int main() {

    setlocale(LC_ALL,"portuguese");

    int vprin[tam], vsoma[tam/2], i, j, z = 0, y = 1;

    printf("Digite os valores do vetor\n");

    for(i = 0; i < tam; i++) {
        printf("Digite o valor %d\n", i);
        scanf("%d", &vprin[i]);
    }
    for(i = 0; i < tam / 2; i++) {
        vsoma[i] = vprin[j] + vprin[j + 1];
        j = j + 2;
    }
    printf("A partir de agora os valores são as somas\n");
    for(i = 0; i < tam / 2; i++) {
        printf("A soma de %d e %d é igual a %d\n",vprin[z], vprin[y], vsoma[i]);
        z = z + 2;
        y = y + 2;
    }

    return 0;
}