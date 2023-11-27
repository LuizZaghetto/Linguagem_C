// Elabore uma função em C que tenha dois parâmetros v1 e v2, duas posições de uma lista dinâmica. A
// função deverá trocar os elementos destas posições. Considere que estas posições podem não existir na lista.

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
Lista* troca(Lista* l1, int v1, int v2) {
    Lista *auxv1 = l1, *antv1 = NULL;
    Lista *auxv2 = l1, *antv2 = NULL;
    while(auxv1 != NULL && auxv1->info != v1) {
        antv1 = auxv1;
        auxv1 = auxv1->prox;
    }
    if(auxv1 == NULL) {
        printf("O valor %d não foi encontrado", v1);
        return l1;
    }
    while(auxv2 != NULL && auxv2->info != v2) {
        antv2 = auxv2;
        auxv2 = auxv2->prox;
    }
    if(auxv2 == NULL) {
        printf("O valor %d não foi encontrado", v2);
        return l1;
    }
    if(antv1 != NULL) {
        antv1->prox = auxv2;
    } else {
        l1 = auxv2;
    }

    if(antv2 != NULL) {
        antv2->prox = auxv1;
    } else {
        l1 = auxv1;
    }

    Lista *temp = auxv1->prox;
    auxv1->prox = auxv2->prox;
    auxv2->prox = temp;

    return l1;
}
int main() {
    Lista *l1;
    l1 = inicializa();
    l1 = insereOrdenando(l1, 1);
    l1 = insereOrdenando(l1, 2);
    l1 = insereOrdenando(l1, 3);
    l1 = insereOrdenando(l1, 4);
    l1 = insereOrdenando(l1, 5);
    l1 = insereOrdenando(l1, 6);
    l1 = troca(l1, 1, 6);
    imprime(l1);
}