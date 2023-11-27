// Faça uma função que transforme uma pilha em fila onde o topo da pilha é o fim da fila. 

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
int desempilha(Pilha *p) {
    int v;
    No *aux = p->topo;
    v = p->topo->info;
    p->topo = aux->prox;
    free(aux);
    return v;
}
void imprimePilha(Pilha *p) {
    No *aux;
    for(aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->info);
    }
}
int topoPilha(Pilha* p) {
    if(p == NULL) {
        printf("A pilha é vazia\n");
        return 0;
    }
    int v = p->topo->info;
    return v;
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
Fila* pilhaParaFila(Fila* f, Pilha* p) {
    No *aux;
    Pilha *p2 = inicializa();
    aux = p->topo;
    if(aux == NULL) {
        printf("A pilha é vazia!\n");
        return f;
    }
    while(aux != NULL) {
        aux = aux->prox;
        p2 = empilha(p2, desempilha(p));
    }
    aux = p2->topo;
    while(aux != NULL) {
        aux = aux->prox;
        insereFila(f, desempilha(p2));
    }
    return f;
}
int main() {
    Fila *f;
    Pilha *p;
    f = criaFila();
    p = inicializa();
    p = empilha(p, 1);
    p = empilha(p, 2);
    p = empilha(p, 3);
    f = pilhaParaFila(f, p);
    imprimeFila(f);
    return 0;
}