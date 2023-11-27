// Escreva uma função que crie uma lista encadeada a par;r de um vetor.

#include <stdlib.h>
#include <stdio.h>
#define tam 50

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
Lista* insereVetor(Lista* l, int a[]) {
    int i;
    for (i = 0; i < tam; i++) {
        l = insereOrdenando(l, a[i]);
    }
    return l;
}
int main() {
    Lista *l1;
    l1 = inicializa();
    int a[tam] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
                  21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 
                  31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
                  41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    l1 = insereVetor(l1, a);
    imprime(l1);
}