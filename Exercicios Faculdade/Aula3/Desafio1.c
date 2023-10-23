// Elabore um programa que determine se um número
// inteiro positivo é primo.


#include <stdlib.h>
#include <stdio.h>

int main() {

    int num, contagem = 1, lista;

    printf("Qual número você deseja verificar? ");
    scanf("%d", &num);

    do {

        if(num % 2 == 0) {
            lista++;
        }

        contagem++;


    }while(contagem <= num);

    if (lista > 2) {
        printf("Seu número não é primo");
    }
    else {
        printf("Seu número é primo");
    }



}