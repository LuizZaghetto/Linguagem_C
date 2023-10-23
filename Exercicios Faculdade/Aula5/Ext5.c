// Ler um vetor de inteiros 10 posições Escrever a seguir o valor
// e a posição do maior e menor elementos lidos.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define tam 10

int main() {

    setlocale(LC_ALL,"portuguese");
    int i, pos1, pos2;

    long v[tam], maior = -99999, menor = 99999;

    printf("Agora será feito a leitura do vetor\n");
    for(i = 0; i < tam; i++) {
        printf("Digite o valor %d\n", i);
        scanf("%d", &v[i]);
        if(v[i] > maior) {
            maior=v[i];
            pos1 = i;
        }
        if(v[i] < menor) {
            menor=v[i];
            pos2 = i;
        }
    }


    printf("O maior valor do vetor é %d e o menor é %d, e suas posições são respectivamente, %d e %d", maior, menor, pos1, pos2);


    return 0;
}