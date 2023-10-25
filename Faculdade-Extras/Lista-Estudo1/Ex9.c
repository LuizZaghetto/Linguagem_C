/*
Faça um programa para ler o nome e a média de 5 alunos. Ao final exiba o nome do aluno que possui a
maior média. Use uma estrutura para representar os dados do aluno.
*/

#include <stdio.h>
#define tam 5

typedef struct Aluno {
    char nome[100];
    float media;
} aluno;

aluno listinha[tam];

void preencheStruct() {
    int i;
    for (i = 0; i < tam; i++) {
        printf("Digite o nome do aluno %d: \n", i + 1);
        scanf(" %99[^\n]", listinha[i].nome);
        printf("Digite a média do aluno %d: \n", i + 1);
        scanf("%f", &listinha[i].media);
    }
}

int identificaMaiorMedia() {
    float maiorMedia = listinha[0].media;
    int i, indiceMaiorMedia = 0;
    
    for (i = 1; i < tam; i++) {
        if (listinha[i].media > maiorMedia) {
            maiorMedia = listinha[i].media;
            indiceMaiorMedia = i;
        }
    }
    
    return indiceMaiorMedia;
}

int main() {
    preencheStruct();
    int indiceMedia = identificaMaiorMedia();
    printf("O aluno com a maior média é: %s\n", listinha[indiceMedia].nome);

    return 0;
}
