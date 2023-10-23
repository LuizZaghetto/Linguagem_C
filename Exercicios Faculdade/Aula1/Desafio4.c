// Para vários tributos, a base de cálculo é o salário mínimo. 
// Fazer um programa que leia o valor do salário mínimo e o valor do salário de uma pessoa. 
// Calcular e imprimir quantos salários mínimos ela ganha.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {

    float salariominatual, salariocliente, multiplicador;

    printf("Digite seu sálario atual ");
    scanf("%f", &salariocliente);

    salariominatual = 1.320;
    multiplicador = salariocliente / salariominatual;

    printf("Tendo em mente que o salário minímo atual é de %f, seu salário equivale a %f vezes desse mesmo", salariominatual, multiplicador);









}