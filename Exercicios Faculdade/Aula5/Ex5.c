// Elabore um programa que leia um vetor de 7 posições e crie um vetor
// inverso ao vetor lido.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define tam 7

int main() {

    setlocale(LC_ALL, "portuguese");

    int i, j;
    int vnorm[tam], vinv[tam];

    printf("Agora será feita a leitura do vetor\n");
    for(i = 0, j = tam - 1; i < tam; i++, j--) {
        printf("Digite o valor %d\n", i);
        scanf("%d", &vnorm[i]);
        vinv[j] = vnorm[i];
    }
    printf("Agora os valores invertidos\n");
    for(i = 0; i < tam; i++) {
        printf("%d\n", vinv[i]);
    }

    return 0;
}