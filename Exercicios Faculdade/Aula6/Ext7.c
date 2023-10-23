// Construa um programa em C que leia um número inteiro não
// negativo e determine a soma dos seus divisores. A soma dever ser
// efetuada através de uma função somadiv e o resultado impresso no
// programa principal. O protótipo da função é: void somadiv(int x, int
// *y);

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void somadiv() {
    int num, i;
    printf("Digite seu número: \n");
    scanf("%d", &num);
    if(num == 0) {
        printf("Seu número não tem divisores naturais");
    }
    else if(num == 1) {
        printf("Seu único divisor é ele mesmo, %d", num);
    }else {
        printf("Seus divisores são: \n");
        int numcerto = abs(num);
        for(i = 1; i < numcerto; i++) {
            if(numcerto % i == 0){
                printf("%d\n", i);
            }
        }
    }
}
int main() {
    somadiv();
}