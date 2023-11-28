// Elabore uma função que inverta uma fila.

#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int info;
    struct no *prox;
} No;
typedef struct fila {
    No *inicio;
    No *fim;
} Fila;

Fila* inicializa() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}
Fila* insereFila(Fila *f, int v) {
    No *novo = (No *) malloc(sizeof(No));
    novo->info = v;
    novo->prox = NULL;
    if(f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    return f;
}
int removeFila(Fila *f) {
    int v;
    No *aux = f->inicio;
    v = f->inicio->info;
    f->inicio = aux->prox;
    free(aux);
    return v;
}
void imprimeFila(Fila *f) {
    No *aux;
    for(aux = f->inicio; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->info);
    }
}
Fila* inverteFilaR(Fila* f) {
    if(f->inicio == NULL) {
        return f;
    }
    int v = removeFila(f);
    f = inverteFilaR(f);
    f = insereFila(f, v);
    return f;
}
int main() {
    Fila *f = inicializa();
    f = insereFila(f, 1);
    f = insereFila(f, 2);
    f = insereFila(f, 3);
    f = insereFila(f, 4);
    f = insereFila(f, 5);
    f = insereFila(f, 6);
    f = insereFila(f, 7);
    f = insereFila(f, 8);
    f = insereFila(f, 9);
    f = insereFila(f, 10);
    f = inverteFilaR(f);
    imprimeFila(f);
    return 0;
}