// Fazer uma função para inverter uma lista L1 colocando a lista resultante em L2.

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
Lista* inverte(Lista *l1, Lista *l2) {
    Lista *aux;
    for(aux = l1; aux != NULL; aux = aux->prox) {
        l2 = insere(l2, aux->info);
    }
    return l2;
}
int main() {
    Lista *l, *l2;
    l = inicializa();
    l = insere(l, 1);  
    l = insere(l, 2);
    l = insere(l, 3);
    l = insere(l, 4);
    l = insere(l, 5);
    imprime(l);
    printf("\n");
    l2 = inicializa();
    l2 = inverte(l, l2);
    imprime(l2);
}