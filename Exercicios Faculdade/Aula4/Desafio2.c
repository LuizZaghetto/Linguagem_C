// Fazer um programa, usando o comando while, que calcule o valor
// de N! (fatorial de N), sendo que o valor inteiro de N deve ser lido. 

#include <stdlib.h>
#include <stdio.h>

int main() {

    int num, multi = 1, i = 1;
    do{
    printf("Diga seu número ");
    scanf("%d", &num);

    if(num < 0) {
        printf("Digite um valor válido\n");
    }
    else if(num == 0) {
        printf("O resultado de sua fatoração é 1\n");
        exit(1);
    }
    else {
        break;
    }
    }while(1);

    for(i = 1; i <= num; i++) {

        multi *= i;
    }

    printf("O resultado de seu fatorial de %d foi %d",num, multi);

    return 0;
}