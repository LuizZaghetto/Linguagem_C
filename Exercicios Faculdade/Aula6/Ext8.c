// Faça um programa que lê um número não determinado de valores
// inteiros e positivos, e para cada valor lido:
// a) a. calcula e escreve o seu fatorial;
// b) b. calcula e escreve os seus divisores;

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void Ler_num(long *xcerto) {
    long x;
    printf("Digite seu número \n");
    scanf("%ld", &x);
    *xcerto = labs(x);
}
long Fatorial(long N) {
    long i, resultado = 1; 
    
    for(i = 1; i <= N; i++) { 
        resultado *= i;
    }
    
    return resultado;
}
void divisores(long N) {
    long i;
    printf("Seus Divisores são: \n");
    for(i = 1; i < N; i++) {
        if(N % i == 0){
            printf("%ld\n", i);
        }
    }
}
int main() {
    long num;
    Ler_num(&num);
    long resultado = Fatorial(num);
    printf("Seu fatorial é %ld\n", resultado);
    divisores(num);
}