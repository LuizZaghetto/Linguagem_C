// Escreva um programa que calcule x elevado a n. Assuma que n é um
// valor inteiro.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

    int vezes;
    float numero, calculo;

    printf("Qual o número? ");
    scanf("%f", &numero);

    printf("A qual número você deseja elevar ele? ");
    scanf("%d", &vezes);

    calculo = pow(numero, vezes);

    printf("O seu número ficou igual a %f", calculo);





}