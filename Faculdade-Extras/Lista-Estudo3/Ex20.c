// Elabore uma função que tenha como parâmetro uma fila. Retire os valores da fila e coloque-os em uma
// pilha. 

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
void imprimePilha(Pilha *p) {
    No *aux;
    for(aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->info);
    }
}
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
Pilha* filaParaPilha(Fila* f, Pilha* p) {
    No *aux;
    aux = f->inicio;
    while(aux != NULL) {
        aux = aux->prox;
        p = empilha(p, removeFila(f));
    }
    return p;
}
int main() {
    Fila *f;
    Pilha *p;
    f = criaFila();
    p = inicializa();
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
    p = filaParaPilha(f, p);
    imprimePilha(p);
}