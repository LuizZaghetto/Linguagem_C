// Elabore uma função que retorne o maior elemento de uma pilha.

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
int maior(Pilha *p) {
    No *aux;
    aux = p->topo;
    int maior = p->topo->info;
    while(aux != NULL) {
        if(maior < aux->info) {
            maior = aux->info;
        }
        aux = aux->prox;
    }
    return maior;
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
    p = empilha(p, 8);
    p = empilha(p, 9);
    p = empilha(p, 10);
    imprime(p);
    printf("Maior: %d\n", maior(p));
}
