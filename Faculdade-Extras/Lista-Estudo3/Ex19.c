// Elabore um procedimento que conte quantos elementos há numa fila.

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

Fila* criaFila() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}
Fila* insereFila(Fila *f, int v) {
    No *novo = (No *) malloc(sizeof(No));
    novo->info = v;
    novo->prox = NULL;
    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    return f;
}
int removeFila(Fila *f) {
    No *aux;
    int v;
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return 0;
    }
    aux = f->inicio;
    v = aux->info;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(aux);
    return v;
}
void imprimeFila(Fila *f) {
    No *aux;
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    aux = f->inicio;
    while (aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
int contaNumeros(Fila *f) {
    No *aux;
    int cont = 0;
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return 0;
    }
    aux = f->inicio;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}
int main() {
    Fila *f;
    f = criaFila();
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
    imprimeFila(f);
    printf("Quantidade de números: %d\n", contaNumeros(f));
    return 0;
}