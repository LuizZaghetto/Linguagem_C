// Leia um número inteiro e imprima a soma do sucessor de seu triplo com o antecessor de seu dobro.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {

    int numero, numerotriplo, numerodobro, numerofinal;
    printf("Digite um número ");
    scanf("%d", &numero);

    numerotriplo = (numero * 3) + 1;
    numerodobro = (numero * 2) - 1;

    numerofinal = numerotriplo + numerodobro; 

    printf("O resultado foi de %d", numerofinal);



}