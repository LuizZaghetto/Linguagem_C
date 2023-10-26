/*
Elabore uma função recursiva que determina o elemento máximo de um vetor
*/

#include <stdlib.h>
#include <stdio.h>
#define tam 10

int maiorElementoArray(int listinha[]) {
    int i = 0, maior = listinha[0];

    if(i == tam - 1) {
        return maior;
    }
    maiorElementoArray(listinha[i+1]);
    if(listinha[i] > maior) {
        maior = listinha[i];
    }
}
int main() {
    int array[tam] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int maiorElemento = maiorElementoArray(array);
    printf("%d", maiorElemento);
}