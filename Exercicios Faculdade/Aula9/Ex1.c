/*
Elabore um programa em C com as seguintes funções para criação e manipulação de uma lista:
• Inicialização;
• Inserção;
• Busca de um elemento, onde o cabeçalho será int Busca(Lista *Aux, int valor);
A função retorna 1 se existe o elemento na Lista e 0 caso contrário:
• VaziaLista – verifica se a Lista está vazia, retorna 1 se estiver e 0 caso contrário.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct no {
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
    Lista* novo = cria();
    novo->info = valor;
    novo->prox = listinha;
    return novo;
}
int buscar(Lista *listinha, int valor) {
    Lista *aux;
    aux = listinha;
    while(aux != NULL) {
        if(aux->info) {
            return 1;
        }
    }
    return 0;
}
int vaziaLista(Lista *listinha) {
    if(listinha == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    Lista *minhaLista = inicializa();

    printf("Lista vazia? %s\n", vaziaLista(minhaLista) ? "Sim" : "Não");

    minhaLista = insere(minhaLista, 10);
    minhaLista = insere(minhaLista, 20);
    minhaLista = insere(minhaLista, 30);

    printf("Lista vazia? %s\n", vaziaLista(minhaLista) ? "Sim" : "Não");

    int elementoBuscado = 20;
    if (buscar(minhaLista, elementoBuscado)) {
        printf("%d encontrado na lista.\n", elementoBuscado);
    } else {
        printf("%d não encontrado na lista.\n", elementoBuscado);
    }

    int elementoNaoExistente = 40;
    if (buscar(minhaLista, elementoNaoExistente)) {
        printf("%d encontrado na lista.\n", elementoNaoExistente);
    } else {
        printf("%d não encontrado na lista.\n", elementoNaoExistente);
    }

    return 0;
}
