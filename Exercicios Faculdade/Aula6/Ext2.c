// Elabore um programa que contenha duas funções:
// • Uma função que lê um número real
// • E uma função que a partir do número real lido retorna a parte
// fracionária do mesmo.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float lerNum() {
    float num;
    printf("Digite um numero: ");
    scanf("%f", &num);
    return num;
}
float parteFracionaria(float num) {
    float parteFracionaria = fabs(num) - floor(fabs(num));
    return parteFracionaria;
}
int main() {
    float num, numfracio;
    num = lerNum();
    numfracio = parteFracionaria(num);
    printf("A parte fracionaria do numero é: %f\n", numfracio);
}