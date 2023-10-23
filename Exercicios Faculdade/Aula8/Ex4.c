// Escrever a função recursiva int fib(int n), que retorna o nésimo número da sequência de Fibonacci: 1, 1, 2, 3, 5, 8, 13,
// 21, 34, ...
// Exemplo: N= 6 O sexto termo da sequencia é 8.

#include <stdio.h>
#include <stdlib.h>

int calculaFib(int n) {
    if(n <= 2) {
        return 1;
    }
    return calculaFib(n - 1) + calculaFib(n - 2);
}
int main() {

int soma = calculaFib(6); 
printf("%d", soma);
}