// Fazer um programa em C para ler um vetor de inteiros positivos
// de 15 posições. Imprimir a quantidade de números pares e a
// quantidade de múltiplos de 5.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL,"portuguese");
    int N, i, par = 0, multi5 = 0;

    printf("Diga o valor de N, que é equivalente o tamanho do vetor\n ");
    scanf("%d", &N);

    if(N < 1 || N > 15) {
        printf("Digite um valor válido");
        return 1;
    }
    int v[N];

    for(i = 0; i < N; i++) {
        printf("Digite o valor %d\n", i);
        scanf("%d", &v[i]);

        if(v[i] % 2 == 0) {
            par = par + 1;
        }
        if(v[i] % 5 == 0) {
            multi5 = multi5 + 1;
        }
    }

    printf("Seu vetor tem um total de %d números pares e %d números múltiplos de 5", par, multi5);

    return 0;


}