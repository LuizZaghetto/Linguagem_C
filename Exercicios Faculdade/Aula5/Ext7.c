// Ler um vetor A com 10 elementos inteiros correspondentes as
// idades de um grupo de pessoas. Escreva um programa que
//determine e escreva a idade média dos elementos lidos e
// quantos elementos são menores que a média.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL,"portuguese");
    int N, i, somai, mediai, guris;

    printf("Diga o valor de N, que é equivalente o tamanho do vetor\n ");
    scanf("%d", &N);

    if(N < 1 || N > 10) {
        printf("Digite um valor válido");
        return 1;
    }

    int v[N];

    for(i = 0; i < N; i++) {
        printf("Digite o valor %d\n", i);
        scanf("%d", &v[i]);
        somai = somai + v[i];

    }


    mediai = somai / N;
    printf("%d", somai);

    for(i = 0; i < N; i++) {
        if(v[i] < mediai) {
            guris = guris + 1;
        }
    }
    printf("A soma total de idade é %d, a média é %d e a quantidade de pessoas com idade abaixo da média é de %d", somai,mediai, guris);
    return 0;

}
