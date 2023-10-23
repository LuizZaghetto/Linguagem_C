// Faça programas para calcular a soma da seguinte sequência: 4 + 7 +
// 10 + (3n+1). Por exemplo se for digitado o valor 3 para n, o valor da
// soma a ser impresso será 31.

#include <stdlib.h>
#include <stdio.h>

int main() {

    int expressao, num;

    printf("Qual seu número? ");
    scanf("%d", &num);

    expressao = 4 + 7 + 10 + (3*num + 1);

    printf("O valor do cálculo foi %d", expressao);

    return 0;
}