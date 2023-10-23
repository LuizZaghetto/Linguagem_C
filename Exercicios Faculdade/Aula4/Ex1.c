// Faça um algoritmo em C que leia um número N, some todos os
// números inteiros de 1 a N e mostre o resultado obtido.

#include <stdlib.h>
#include <stdio.h>

int main() {


    int num, true = 1, i = 1, soma = 0;

    do {
    printf("Digite seu número, sendo ele obrigatoriamente inteiro ");
    scanf("%d", &num);

    if(num < 0) {
        printf("O número deve ser inteiro");
    }
    else {
        true = 0;
    }

    }while(true == 1);

    while(i <= num) {
        soma = soma + i;
        i++;
    }

    printf("Sua soma total é de %d", soma);

}