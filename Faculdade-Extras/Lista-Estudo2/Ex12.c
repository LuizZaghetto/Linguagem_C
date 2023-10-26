/*
Elabore uma função que insira um elemento no final de uma lista dinâmica. Considere que a lista pode
estar vazia e o elemento a ser inserido será o primeiro.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no *prox;
}Lista;

Lista* inicializa() {
    return NULL;
}
Lista* cria() {
    Lista *novo;
    novo = (Lista*)malloc(sizeof(Lista));
    return novo;
}
Lista* insere(Lista* listinha, int valor) {
    Lista *novo = cria();
    novo->info = valor;
    novo->prox = listinha;
    return novo;
}
Lista* imprime(Lista* listinha) {
    Lista *aux;
    aux = listinha;
    while(aux != NULL) {
        printf("\n%d", aux->info);
        aux = aux->prox;
    }
}
Lista* insereFim(Lista* listinha, int valor) {
    Lista *aux;
    aux = listinha;
    if(listinha == NULL) {
        listinha = insere(listinha, valor);
    }
    else{
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        Lista *novo = cria();
        novo->info = valor;
        novo->prox = NULL;
        aux->prox = novo;
    }    
    return listinha;  
}

int main() {

    Lista *p;
    p = inicializa();
    if(p == NULL) {
        p = insere(p, 12);
        p = insere(p, 10);
        p = insereFim(p, 18);
        imprime(p);
    }
    else {
        printf("Erro na alocação da memória");
    }
}