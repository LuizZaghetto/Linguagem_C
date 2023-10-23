// Faça um algoritmo que leia dois valores inteiros A e B se os valores forem iguais deverá somar os dois,
// caso contrário multiplique A por B. Ao final de qualquer um dos cálculos deve-se atribuir o resultado para
// uma variável C e mostrar seu conteúdo na tela. 

#include <stdlib.h>
#include <stdio.h>

int main() {

    int num1, num2, total, caso;

    printf("Digite o número 1 ");
    scanf("%d", &num1);

    printf("Digite o número 2 ");
    scanf("%d", &num2);

    if(num1 == num2) {
        total = num1 + num2;
        caso = 1;
    }
    else {
        total = num1 * num2;
        caso = 2;
    }
    if(caso == 1) {
        printf("Já que os números %d e %d são iguais, eles foram somados, tendo como resultado final %d", num1, num2, total);
    }
    if(caso == 2) {
        printf("Já que os números %d e %d são diferentes, eles foram multiplicados, tendo como resultado final %d", num1, num2, total);
    }


    return 0;

}