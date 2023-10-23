// Faça um Programa que peça um valor e mostre na tela se o valor é positivo, negativo ou nulo. 

#include <stdlib.h>
#include <stdio.h>

int main() {

    float num;

    printf("Digite seu número ");
    scanf("%f", &num);

    if(num >= 1) {
        printf("O número é positivo");
    }
    else if(num <= -1) {
        printf("O número é negativo");
    }
    else {
        printf("O valor é nulo");
    }









}