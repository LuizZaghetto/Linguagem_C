// Leia um número inteiro e imprima o seu antecessor e seu sucessor.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    int numero;
    printf("Qual o seu número?");
    scanf("%d", &numero);

    int antecessor = numero - 1;
    int sucessor = numero + 1;

    printf("Seu número é %d, e seu antecessor é %d e seu sucessor é %d\n", numero, antecessor, sucessor);









}