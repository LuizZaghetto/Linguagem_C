// Elabore um programa que leia um numero inteiro e construa os seguintes procedimentos:
// • int soma_digit(int a) – este procedimento irá somar os dígitos desse número inteiro.
// • void Maior_Digit(int N, int *M) – este procedimento irá determinar o maior dígito desse número inteiro.

#include <stdio.h>
#include <stdlib.h>

int soma_digit(int a) {
    int soma = 0, somaatual = 0, copia = a;
    while(copia >= 1) {
        somaatual = copia % 10;
        copia = copia / 10;
        soma = soma + somaatual;
    }
    return soma;
}
void Maior_Digit(int N, int *M) {
    int soma = 0, somaatual = 0, copia = N; 
    *M = -1;
    while(copia >= 1) {
    somaatual = copia % 10;
    copia = copia / 10;
    soma = soma + somaatual;
        if(somaatual > *M) {
            *M = somaatual;
        }
    }
}
int main() {
    int num = 358;
    int sum = soma_digit(num);
    int maiorD;
    Maior_Digit(num, &maiorD);
    printf("%d %d", sum, maiorD);
    return 0;
}