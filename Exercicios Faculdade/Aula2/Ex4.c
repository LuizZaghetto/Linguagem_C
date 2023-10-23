// Faça um algoritmo que leia os valores A, B, C e imprima na tela se a soma de A + B é menor que C. 

#include <stdlib.h>
#include <stdio.h>

int main() {

    float A, B, C, soma;

    printf("Qual é o valor de A? ");
    scanf("%f", &A);

    printf("Qual é o valor de B? ");
    scanf("%f", &B);

    printf("Qual é o valor de C? ");
    scanf("%f", &C);

    soma = A + B;

    if(soma < C) {
        printf("A soma de %.2f e %.2f é menor que %.2f", A, B, C);
    }
    else if(soma == C) {
        printf("A soma de %.2f e %.2f é igual a %.2f", A, B, C);
    }
    else {
        printf("A soma de %.2f e %.2f é maior que %.2f", A, B, C);
    }
}