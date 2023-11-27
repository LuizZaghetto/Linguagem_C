// . Escreva uma função que dado duas pilhas, passadas por parâmetro ele retorne que tem mais elementos.
// Os valores de retorno serão:
// • 0 se as duas pilhas ;verem a mesma quan;dade de elementos.
// • 1 se a pilha 1 ;ver mais elementos.
// • 2 se a pilha 2 ;ver mais elementos.

#include <stdio.h>
#include <stdlib.h>

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
int comparaPilha(Pilha *p1, Pilha *p2) {
    No *aux;
    int conta1 = 0, conta2 = 0;

    for(aux = p1->topo; aux != NULL; aux = aux->prox) {
        conta1++;
    }
    for(aux = p2->topo; aux != NULL; aux = aux->prox) {
        conta2++;
    }
    
    if(conta1 == conta2) {
        return 0;
    }
    if(conta1 > conta2) {
        return 1;
    }
    if(conta1 < conta2) {
        return 2;
    }
}
int main() {
    Pilha *p1, *p2;
    p1 = inicializa();
    p2 = inicializa();
    p1 = empilha(p1, 1);
    p1 = empilha(p1, 2);
    p1 = empilha(p1, 3);
    p2 = empilha(p2, 1);
    p2 = empilha(p2, 2);
    p2 = empilha(p2, 3);
    printf("%d\n", comparaPilha(p1, p2));
    return 0;
}