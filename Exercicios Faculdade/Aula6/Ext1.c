// Elabore um programa que possua uma função que recebe um valor
// inteiro e verifica se o valor é par. A função deve retornar 1 se o
// número for par e 0 se for ímpar e o resultado deverá ser impresso no
// programa principal.

#include <stdlib.h>
#include <stdio.h>

int verificanum() {
    int num, retorno;
    printf("Digite um numero: ");
    scanf("%d", &num);

    if(num % 2 == 0) {
        retorno = 1;
    }
    else {
        retorno = 0;
    }
    return retorno;
}

int main() {
    int valor;
    valor = verificanum();
    if(valor == 1) {
        printf("O numero é par.\n");
    }
    else {
        printf("O numero é impar.\n");
    }
}