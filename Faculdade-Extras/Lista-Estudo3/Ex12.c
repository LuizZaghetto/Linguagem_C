// . Construa uma função que retorne a média dos elementos de uma pilha.

#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no *prox;
}No;

typedef struct pilha{
    No *topo;
}Pilha;

Pilha* inicializa() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
Pilha* empilha(Pilha *p, int v) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = v;
    novo->prox = p->topo;
    p->topo = novo;
    return p;
}
Pilha* desempilha(Pilha *p) {
    No *aux = p->topo;
    p->topo = aux->prox;
    free(aux);
    return p;
}
void imprime(Pilha *p) {
    No *aux;
    for(aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->info);
    }
}
int media(Pilha *p) {
    No *aux;
    int soma = 0, contagem = 0;
    for(aux = p->topo; aux != NULL; aux = aux->prox) {
        soma = soma + aux->info;
        contagem++;
    }
    int media = (soma / contagem);
    return media;
}
int main() {
    Pilha *p;
    p = inicializa();
    p = empilha(p, 1);
    p = empilha(p, 2);
    p = empilha(p, 3);
    p = empilha(p, 4);
    p = empilha(p, 5);
    p = empilha(p, 180);
    p = empilha(p, 7);
    printf("Média: %d\n", media(p));
    return 0;
}