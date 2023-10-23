// Leia dois números inteiros e verifique qual é o menor e o maior. Em
// seguida, imprima todos os números entre ambos.

#include <stdlib.h>
#include <stdio.h>


int main() {


    int numero1, numero2, maior, menor, i;

    printf("Qual o primeiro número? ");
    scanf("%d", &numero1);

    printf("Qual o segundo número? ");
    scanf("%d", &numero2);

    if(numero1 > numero2) {
        printf("O primeiro é o maior e o segundo o menor");
        maior = numero1;
        menor = numero2;
    }
    if(numero1 < numero2) {
        printf("O segundo é o maior e o primeiro o menor");
        maior = numero2;
        menor = numero1;
    }
    for(i = menor; i < maior; i++) {

        printf("%d\n",i);
    }



}