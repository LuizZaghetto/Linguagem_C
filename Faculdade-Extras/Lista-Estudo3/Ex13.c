// Utilizando uma pilha resolver o exercício a seguir: Dada uma sequência contendo N (N >0) números
// reais, imprimi-la na ordem inversa.

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
void imprimeInverso(Pilha *p) {
    Pilha *aux = inicializa();
    while(p->topo != NULL) {
        aux = empilha(aux, p->topo->info);
        p = desempilha(p);
    }
    imprime(aux);
}
void imprimeInversoR(Pilha *p) {
    if(p->topo == NULL) {
        return;
    }
    int aux = p->topo->info;
    p = desempilha(p);
    imprimeInverso(p);
    printf("%d\n", aux);
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
    imprimeInverso(p);
    return 0;
}