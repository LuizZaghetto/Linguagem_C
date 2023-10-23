// Faça um Programa que peça dois números e imprima o maior deles. 

#include <stdlib.h>
#include <stdio.h>

int main() {

    float num1, num2;

    printf("Qual o primeiro número? ");
    scanf("%f", &num1);

    printf("Qual o segundo número? ");
    scanf("%f", &num2);

    if(num1 > num2) {
        printf("O número %f é o maior", num1);
    }
    if(num1 == num2) {
        printf("Os números %f e %f são iguais", num1, num2);
    }
    else{
        printf("O número %f é maior", num2);
    }

}