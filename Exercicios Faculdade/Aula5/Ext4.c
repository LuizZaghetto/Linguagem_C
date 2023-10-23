// Fazer um programa que faz a leitura de um vetor X, com N
// inteiros, com tamanho máximo igual a 20 e N deverá ser lido.
// Gera um segundo vetor com os valores de vetor lido em ordem
// inversa. Imprimir o vetor lido e vetor com a ordem inversa.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL,"portuguese");
    int N, i, y = 0;

    printf("Diga o valor de N, que é equivalente o tamanho do vetor\n ");
    scanf("%d", &N);

    if(N < 1 || N > 20) {
        printf("Digite um valor válido");
        return 1;
    }

    double v[N], vinv[N];

    for(i = 0, y = N - 1; i < N; i++, y--) {
        printf("Digite o valor %d\n ", i);
        scanf("%lf", &v[i]);
        vinv[y] = v[i];
    }

    printf("O vetor invertido é igual a:\n");
    for(i = 0; i < N; i++) {
        printf("%2.lf", vinv[i]);
    }



        return 0;
}