#include <stdlib.h>
#include <stdio.h>

long calculaFatorial(long num) {
    long fat = 1, i;
    if(num == 0 ||num == 1 ) {
        fat = 1;
    }
    else {
        for(i = 1; i <= num; i++) {
            fat = fat * i;
        }
    }
    printf("O fatorial de %ld é %ld\n", num, fat);
    return fat;
}
long imprimeDivisores(long num) {
    if (num <= 0) {
        printf("O número %ld não possui divisores naturais.\n", num);
        return;
    }

    printf("Os divisores naturais de %ld são: \n", num);

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main() {
    long fatorial, num;
    printf("Digite seu número ");
    scanf("%ld", &num);
    fatorial = calculaFatorial(num);
    imprimeDivisores(num);
}
