// Faça um programa que realize a leitura dos seguintes dados relativos a um conjunto de alunos:
// • RA - inteiro
// • Código da Disciplina - inteiro de 4 dígitos
// • Nota1 e Nota 2 – valores reais que podem ser armazenados na forma de um vetor de 2 posições.
// Considere uma turma de até 10 alunos. Após ler todos os dados
// digitados, e depois de armazená-los em um vetor de estrutura,
// exibir na tela a listagem final dos alunos com as suas respectivas
// medias finais (use uma média ponderada: Nota1 com peso=1.0 e
// Nota2 com peso=2.0).

#include <stdlib.h>
#include <stdio.h>
#define tam 2

struct Aluno {
    int ra;
    int codigodisciplina;
    float notas[2];
};
struct Aluno alunos[tam];

void leAluno(struct Aluno alunos[]) {
    for(int i = 0; i < tam; i++) {
        printf("Digite o RA do aluno: \n");
        scanf("%d", &alunos[i].ra);
        printf("Digite o código da disciplina: \n");
        scanf("%d", &alunos[i].codigodisciplina);
        printf("Digite a primeira nota: \n");
        scanf("%f", &alunos[i].notas[0]);
        printf("Digite a segunda nota: \n");
        scanf("%f", &alunos[i].notas[1]);
    }
}

void imprimeMedia(struct Aluno alunos[]) {
    for(int i = 0; i < tam; i++) {
        printf("O aluno de RA %d tem media %.2f\n", alunos[i].ra, (alunos[i].notas[0] + (alunos[i].notas[1]*2)) / 3);
    }
}
int main() {
    leAluno(alunos);
    imprimeMedia(alunos);
}