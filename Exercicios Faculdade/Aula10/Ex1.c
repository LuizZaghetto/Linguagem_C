/*
Use a biblioteca de pilha.h e crie:
a) O programa principal inserindo alguns números e imprimindo a pilha.
b) Uma função que conte o número de elementos da pilha.
c) Uma função que inverta a pilha original.
d) Remova um elemento da pilha, se ele existir.
e) Todos os resultados devem ser impressos.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
}No;

typedef struct pilha {
    No *topo;
}Pilha;

Pilha* inicializa() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p; 
}
Pilha* empilha(Pilha* pilhinha, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->info = valor;
    novo->prox=pilhinha->topo;
    pilhinha->topo = novo;
    return pilhinha;
}
int conta(Pilha* pilhinha) {
    int i = 0;
    No *aux;
    aux= pilhinha->topo;
    while(aux != NULL) {
        aux = aux->prox;
        i++;
    }
    return i;
}
void imprime(Pilha* pilhinha) {
    No *aux;
    aux = pilhinha->topo;
    while(aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}
int apagaTopo(Pilha* pilhinha) {
    int dado;
    No *apagado;
    apagado = pilhinha->topo;
    dado = pilhinha->topo->info;
    pilhinha->topo = apagado->prox;
    free(apagado);
    return dado;
}
Pilha* inverte(Pilha* pilhinha) {
    Pilha* pilhaInvertida = inicializa();
    No *aux = pilhinha->topo;
    while(aux != NULL) {
        empilha(pilhaInvertida, aux->info);
        aux = aux->prox;
    }
    return pilhaInvertida;
}

int main() {
    Pilha *duracell;
    duracell = inicializa();
    duracell = empilha(duracell, 4);
    duracell = empilha(duracell, 3);
    duracell = empilha(duracell, 25);
    duracell = empilha(duracell, 10);
    duracell = empilha(duracell, 9);
    printf("Sua pilha tem %d elemento(s)\n", conta(duracell));
    printf("O número que estava no topo da sua pilha e foi apagado era %d\n", apagaTopo(duracell));
    imprime(duracell);
    printf("Pilha invertida\n");
    Pilha *panasonic;
    panasonic = inicializa();
    panasonic = inverte(duracell);
    imprime(panasonic);
}