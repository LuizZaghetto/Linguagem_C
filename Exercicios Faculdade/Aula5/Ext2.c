// Fazer um programa que faz a leitura de um vetor X com N inteiros,
// com tamanho máximo igual a 20 e N deverá ser lido. Multiplica
// cada elemento do vetor por um valor K (K também deverá ser lido).
// Imprimir o vetor lido, o valor da variável K e o vetor multiplicado por K. 

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {

    int N, i;
    double K;

    printf("Digite o valor de N, que é o tamanho do vetor, o máximo é 20\n");
    scanf("%d", &N);

    if(N < 1 || N > 20) {
        printf("Digite um valor válido para N");
        return 1;
    }
    printf("Digite o valor de K, que vai multiplicar cada um dos valores do vetor individualmente\n");
    scanf("%lf", &K);

    double V[N], novoV[N];

    printf("Agora serão registrados os %d valores do vetor\n", N);
    for(i = 0; i < N; i++) {
        printf("Digite o valor %d\n", i);
        scanf("%lf", &V[i]);
    }

    // Copiando o vetor V para novoV
    for(i = 0; i < N; i++) {
        novoV[i] = V[i];
    }
    // Multiplicando os valores por K
    for(i = 0; i < N; i++) {
        novoV[i] = novoV[i] * K;
    }

    printf("O vetor antes de ser multiplicado:\n");
    for(i = 0; i < N; i++) {
        printf("%2.lf\n", V[i]);
    }
    printf("O vetor depois de ser multiplicado:\n");
        for(i = 0; i < N; i++) {
            printf("%2.lf\n", novoV[i]);
        }
    printf("O multiplicador K é igual a %lf", K);

    return 0;
}