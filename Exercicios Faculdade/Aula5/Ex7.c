// Elabore um programa que leia dois vetores de 10 posições e calcule
//outro vetor contendo, nas posições pares os valores do primeiro e nas
//posições impares os valores do segundo.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define tam 10

int main() {

    setlocale(LC_ALL, "portuguese");

    int v1[tam], v2[tam], v3[tam * 2], i, p = 0, m = 0;

    printf("Leitura do primeiro vetor:\n");
    for(i = 0; i < tam; i++) {
        printf("Digite o valor %d\n", i);
        scanf("%d", &v1[i]);
    }
    printf("Leitura do segundo vetor:\n");
    for(i = 0; i < tam; i++) {
        printf("Digite o valor %d\n", i);
        scanf("%d", &v2[i]);
    } 
    for(i = 0; i < tam * 2; i++) {
        if(i == 0 || i % 2 == 0) {
            v3[i] = v1[p];
            p++;
        }
        else {
            v3[i] = v2[m];
            m ++;
        }
    }
    for(i = 0; i < tam * 2; i++) {
        printf("%d\n", v3[i]);
    }

    return 0;
}