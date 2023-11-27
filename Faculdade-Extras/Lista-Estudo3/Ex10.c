// Construa uma função que dado uma lista e um valor inteiro e posi;vo k, deverá dividia a lista em duas: 
// a lista original fica com os valores até a posição k e a segunda lista fica com os valores de k até o final.

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
void divide(Lista** l1, Lista** l2, int v) {
    Lista *aux, *auxremove;
    aux = *l1;
    while(aux != NULL && aux->info != v) {
        aux = aux->prox;
    }
    if(aux == NULL) {
        printf("O valor %d não existe\n", v);
        return;
    }
    aux = aux->prox;
    if(aux == NULL) {
        printf("A lista não tem nenhum valor depois do %d\n", v);
        return;
    }
    auxremove = aux;
    
    while(aux != NULL) {
        *l2 = insereOrdenando(*l2, aux->info);
        aux = aux->prox;
    }
    while(auxremove != NULL) {
        *l1 = retira(*l1, auxremove->info);
        auxremove = auxremove->prox;
    }
 }
int main() {
    Lista *l1, *l2;
    l1 = inicializa();
    l2 = inicializa();
    l1 = insereOrdenando(l1, 1);
    l1 = insereOrdenando(l1, 2);
    l1 = insereOrdenando(l1, 3);
    l1 = insereOrdenando(l1, 4);
    l1 = insereOrdenando(l1, 5);
    l1 = insereOrdenando(l1, 6);
    l1 = insereOrdenando(l1, 7);
    l1 = insereOrdenando(l1, 8);
    l1 = insereOrdenando(l1, 9);
    l1 = insereOrdenando(l1, 10);
    divide(&l1, &l2, 5);
    imprime(l1);
    printf("\n");
    imprime(l2);
}