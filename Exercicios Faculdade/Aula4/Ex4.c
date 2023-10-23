// Faça um programa que leia um número positivo e imprima os seus
// divisores.

#include <stdlib.h>
#include <stdio.h>

int main() {

    int num, i = 1;

    do{
    printf("Qual o seu número? Ele deve ser positivo ");
    scanf("%d", &num);

    if(num <= 0){
        printf("Entrada inválida, por favor insira outro número\n");
    }
    else {
        break;
    }
    }while(1);
    
    printf("Seus divisores são esses:\n");
    
    for(i; i <= num; i++) {
        
     
        
        if(num % i == 0){
            printf("%d\n", i);
        } 
    }
    return 0;
}

