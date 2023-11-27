// Fazer uma função que realiza o merge de duas listas ordenadas.

#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* inicializa() {
    return NULL;
}
Lista* cria() {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    return novo;
}
Lista* insere(Lista* l, int v) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = l;
    return novo;
}
Lista* retira(Lista* l, int v) {
    Lista* ant = NULL;
    Lista* aux = l;
    
    while(aux != NULL && aux->info != v) {
        ant = aux;
        aux = aux->prox;
    }
    
    if(aux == NULL) {
        return l;
    }
    
    if(ant == NULL) {
        l = aux->prox;
    } else {
        ant->prox = aux->prox;
    }
    free(aux);
    return l;
}
void imprime(Lista* l) {
    Lista *aux;
    for(aux = l; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->info);
    }
}
Lista* insereOrdenando(Lista* l, int v) {
    Lista *aux = l, *ant = NULL;

    Lista *novo = cria();
    novo->info = v;

    if (aux == NULL || aux->info >= v) {
        novo->prox = aux;
        return novo;
    }

    while (aux != NULL && v > aux->info) {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = novo;
    novo->prox = aux;

    return l;
}
Lista* junta(Lista* l1, Lista* l2) {
    Lista *l3 = inicializa();
    Lista *aux;

    for (aux = l1; aux != NULL; aux = aux->prox) {
        l3 = insereOrdenando(l3, aux->info);
    }
    for (aux = l2; aux != NULL; aux = aux->prox) {
        l3 = insereOrdenando(l3, aux->info);
    }
    return l3;
}

int main() {
    Lista *l1 = inicializa();
    Lista *l2 = inicializa();
    Lista *l3 = inicializa();
    l1 = insereOrdenando(l1, 6);
    l1 = insereOrdenando(l1, 2);
    l1 = insereOrdenando(l1, 4);
    l1 = insereOrdenando(l1, 3);
    l1 = insereOrdenando(l1, 5);
    l1 = insereOrdenando(l1, 1);
    l2 = insereOrdenando(l2, 6);
    l2 = insereOrdenando(l2, 2);
    l2 = insereOrdenando(l2, 4);
    l2 = insereOrdenando(l2, 3);
    l2 = insereOrdenando(l2, 5);
    l2 = insereOrdenando(l2, 1);
    l3 = junta(l1, l2);
    imprime(l3);
    return 0;
}