// Escreva uma função que copie uma lista encadeada para um vetor.

#include <stdlib.h>
#include <stdio.h>
#define tam 6

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
        if (aux->info == v) {
            printf("O valor %d já foi utilizado\n", v);
            free(novo);
            return l;
        }
        ant = aux;
        aux = aux->prox;
    }

    if (aux != NULL && aux->info == v) {
        printf("O valor %d já foi utilizado\n", v);
        free(novo);
        return l;
    }

    ant->prox = novo;
    novo->prox = aux;

    return l;
}
void copiaListaVetor(Lista* l1, int a[]) {
    Lista *aux;
    int i = 0;
    for(aux = l1; aux != NULL; aux = aux->prox) {
        a[i] = aux->info;
        i++;
    }
}
void imprimeVetor(int a[]) {
    int i;
    for(i = 0; i < tam; i++) {
        printf("%d\n", a[i]);
    }
}
int main() {
    int a[tam];
    Lista* l1 = inicializa();
    l1 = insereOrdenando(l1, 8);
    l1 = insereOrdenando(l1, 128);
    l1 = insereOrdenando(l1, 833);
    l1 = insereOrdenando(l1, 85);
    l1 = insereOrdenando(l1, 558);
    l1 = insereOrdenando(l1, 899);
    copiaListaVetor(l1, a);
    imprimeVetor(a);
}