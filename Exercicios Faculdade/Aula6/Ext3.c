// Elabore um programa que contenha uma função que
// dado um numero inteiro natural ela retorne a o seu
// fatorial.

#include <stdlib.h>
#include <stdio.h>

int calculaFatorial(int num) {
    int fat = 1, i;
    if(num == 0 ||num == 1 ) {
        fat = 1;
    }
    else {
        for(i = 1; i <= num; i++) {
            fat = fat * i;
        }
    }
    return fat;
}
int main() {
    int fatorial, num;
    printf("Digite seu número ");
    scanf("%d", &num);
    fatorial = calculaFatorial(num);
    printf("O fatorial de seu número é %d", fatorial);
}