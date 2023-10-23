// Elabore um programa em C que seja constituído de uma função recursiva que dado um número inteiro, forneça a quantidade de dígitos que esse número possui. O resultado deve ser impresso no programa principal.
// Exemplo: 3598 possui 4 dígitos

#include <stdlib.h>
#include <stdio.h>

int retornaQuantidade(int num) {
    if(num == 0) {
        return 0;
    }
    return 1 + retornaQuantidade(num / 10);
}
int main() {
    int digito = retornaQuantidade(4444);
    printf("%d", digito);
}