#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int info;
    struct no *prox;
} Lista;

Lista* inicializa() {
    return NULL;
}

Lista* cria() {
    Lista *novo;
    novo = (Lista*)malloc(sizeof(Lista));
    return novo;
}
Lista* insereOrdenando(Lista* listinha, int valor) {
    Lista *aux, *ant = NULL;
    aux = listinha;

    Lista *novo = cria();
    novo->info = valor;

    if (aux == NULL || aux->info > valor) {
        novo->prox = aux;
        return novo;
    }

    while (aux != NULL && aux->info < valor) {
        ant = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    ant->prox = novo;
    return listinha;
}

void imprimeLista(Lista* listinha) {
    Lista *aux;
    aux = listinha;
    while(aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

int main() {
    Lista *p;
    p = inicializa();
    p = insereOrdenando(p, 10);
    p = insereOrdenando(p, 8);
    p = insereOrdenando(p, 15);
    p = insereOrdenando(p, 1);
    imprimeLista(p);
}