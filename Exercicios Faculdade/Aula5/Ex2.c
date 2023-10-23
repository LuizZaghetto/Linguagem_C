// Ler um vetor de inteiros 10 posições e imprima o valor e a posição do
// maior e menor elementos lidos.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define tam 10

int main() {

    setlocale(LC_ALL,"portuguese");

    int i, maior = -999999, menor = 999999;
    int v[tam];

    for(i = 0; i < tam; i++) {

        printf("Digite o valor %d\n ", i);
        scanf("%d", &v[i]);

        if(v[i] > maior) {
            maior = v[i];
        }
        if(v[i] < menor) {
            menor = v[i];
        }

    }

    printf("O maior valor do seu vetor é %d e o menor é %d", maior, menor);


    return 0;
}