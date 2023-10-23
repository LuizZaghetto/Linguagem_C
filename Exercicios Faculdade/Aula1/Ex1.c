// Elabore um programa em C que receba um número inteiro e positivo e exiba o dobro do mesmo.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    short unsigned int numero;
    
    printf("Qual seu número? ");
    scanf("%d", &numero);

    int numerodobro = numero * 2;

    printf("Seu número é %d e o dobro dele é %d\n", numero, numerodobro);


}