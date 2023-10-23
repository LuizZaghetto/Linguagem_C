// Fazer um programa para ler um número do usuário e determinar se este número é par ou ímpar. 


#include <stdio.h>
#include <stdlib.h>

int main() {

    int numero;

    printf("Qual seu número? ");
    scanf("%d", &numero);

    if(numero % 2 == 0) {
        printf("Seu número é par");
    }
    else {
        printf("Seu número é ímpar");
    }




}