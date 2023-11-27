// Construa um programa utilizando uma pilha que resolva o seguinte problema: Armazene as placas dos
// carros (apenas os números) que estão estacionados numa rua sem saída estreita. Dado uma placa
// verifique se o carro está estacionado na rua. Caso esteja, informe a sequência de carros que deverá ser
//retirada para que o carro em questão consiga sair. 

#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no *prox;
}No;

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
Pilha* desempilha(Pilha *p) {
    No *aux = p->topo;
    p->topo = aux->prox;
    free(aux);
    return p;
}
void imprime(Pilha *p) {
    No *aux;
    for(aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->info);
    }
}
void pegarCarro(Pilha *p, int v) {
    No *aux;
    aux = p->topo;
    while(aux != NULL && aux->info != v) {
        aux = aux->prox;
    }
    if(aux == NULL) {
        printf("O carro não foi encontrado\n");
        return;
    }
    printf("Carros que necessitam de retirada: \n");
    aux = p->topo;
    while(aux != NULL && aux->info != v) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}
int main() {
    Pilha *p;
    p = inicializa();
    p = empilha(p, 1189);
    p = empilha(p, 2111);
    p = empilha(p, 3109);
    p = empilha(p, 4387);
    p = empilha(p, 5222);
    p = empilha(p, 1801);
    pegarCarro(p, 2111);
    return 0;
}