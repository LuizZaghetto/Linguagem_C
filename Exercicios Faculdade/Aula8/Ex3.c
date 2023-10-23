// Escrever a função recursiva float pot(float x, int n), que retorna x elevado a n.

#include <stdlib.h>
#include <stdio.h>

float potencia(float x, int n) {
    while(n != 1) {
    return x * potencia(x, n - 1);
    }
}
int main() {
    int potencia2 = potencia(2, 1);
    printf("%d", potencia2);
}