// Crie um algoritmo que receba do usuário um número qualquer e verifique se esse é múltiplo de 5.

#include <stdlib.h>
#include <stdio.h>

int main() {

    int num;

    printf("Qual o número? ");
    scanf("%d", &num);

    if(num % 5 == 0) {
        printf("%d é múltiplo de 5", num);
    }
    else {
        printf("%d não é múltiplo de 5", num);
    }





}