// Fazer um programa que faz a leitura de dois vetores X e Y, ambos
// com N reais, com tamanho máximo igual a 20 e N deverá ser lido.
// Efetua a multiplicação de um vetor por outro, gerando um terceiro
// vetor. Imprimir os vetores lidos e o vetor com o produto.

#include <stdlib.h>
#include <stdio.h>

int main() {

    int N;

    printf("Digite o valor de N, equivalente ao tamanho dos vetores (máximo é 20): ");
    scanf("%d", &N);

    if (N < 1 || N > 20) {
        printf("O valor de N é inválido, por favor insira outro.\n");
        return 1;
    }

    double X[N], Y[N], Z[N];

    printf("Digite os %d valores de X:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%lf", &X[i]);
    }

    printf("Digite os %d valores de Y:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%lf", &Y[i]);
    }

    // Multiplicação dos vetores e armazenamento no vetor Z
    for (int i = 0; i < N; i++) {
        Z[i] = X[i] * Y[i];
    }

    printf("Os valores do Vetor X são:\n");
    for (int i = 0; i < N; i++) {
        printf("%lf\n", X[i]);
    }

    printf("Os valores do Vetor Y são:\n");
    for (int i = 0; i < N; i++) {
        printf("%lf\n", Y[i]);
    }

    printf("Os valores multiplicados são, respectivamente:\n");
    for (int i = 0; i < N; i++) {
        printf("%lf\n", Z[i]);
    }

    return 0;
}
