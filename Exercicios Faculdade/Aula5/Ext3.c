// Fazer um programa que faz a leitura de um vetor X com N reais ,
//com tamanho máximo igual a 20 e N deverá ser lido. Calcula o
// somatório de todos os elementos do vetor. Imprimir o vetor lido
// e o valor do somatório.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL,"portuguese");
    int N, i;

    printf("Diga o valor de N, que é equivalente o tamanho do vetor\n ");
    scanf("%d", &N);

    if(N < 1 || N > 20) {
        printf("Digite um valor válido");
        return 1;
    }

    double v[N], soma;

    printf("Agora será feito o registro dos números\n ");
    for(i = 0; i < N; i++) {
        printf("Digite o valor %d\n ", i);
        scanf("%lf", &v[i]);
    }
    for(i = 0; i < N; i++) {
        soma = soma + v[i];
    }
    printf("A soma total é de %2.lf", soma);




    return 0;
}