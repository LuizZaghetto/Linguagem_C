// Elabore uma função que leia um número inteiro e guarde os seus dígitos numa pilha.

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
Pilha *leNumero() {
    Pilha *p = inicializa();
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    while(n > 0) {
        p = empilha(p, n % 10);
        n /= 10;
    }
    return p;
}
int main() {
    Pilha *p;
    p = leNumero();
    imprime(p);
    return 0;
}