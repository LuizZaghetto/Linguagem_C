/*
a. Tenha como parâmetro uma fila. Retire os valores da fila e coloque-os em uma pilha
b. Transforme uma pilha em fila onde o topo da pilha é o início da fila
c. Transforme uma pilha em fila onde o topo da pilha é o fim da fila
d. Tenha como parâmetro duas filas F1 e F2. Cada uma das filas não possui elementos repe;dos.
Construa uma terceira fila (F3) que possua todos os elementos de F1 e F2, mas sem repe;r
números
e. Determine a quantidade de nós que existem na árvore
f. Retorne a quantidade de folhas de uma árvore
g. Determine o nível de um certo nó, se ele existir na árvore
h. Determine a quantidade de descendentes de um certo nó, se ele existir na árvore 
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int info;
    struct no *prox;
} No;
typedef struct fila {
    No *inicio;
    No *fim;
} Fila;
typedef struct pilha{
    No *topo;
}Pilha;
Pilha* inicializaP() {
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
int desempilha(Pilha *p) {
    int v;
    No *aux = p->topo;
    v = p->topo->info;
    p->topo = aux->prox;
    free(aux);
    return v;
}
void imprimePilha(Pilha *p) {
    No *aux;
    for(aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->info);
    }
}
Fila* inicializaF() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}
Fila* insereFila(Fila *f, int v) {
    No *novo = (No *) malloc(sizeof(No));
    novo->info = v;
    novo->prox = NULL;
    if(f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    return f;
}
int removeFila(Fila *f) {
    int v;
    No *aux = f->inicio;
    v = f->inicio->info;
    f->inicio = aux->prox;
    free(aux);
    return v;
}
void imprimeFila(Fila *f) {
    No *aux;
    for(aux = f->inicio; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->info);
    }
}
Pilha* filaParaPilha(Pilha* p, Fila *f) {
    No* aux;
    aux = f->inicio;
    while(aux != NULL) {
        p = empilha(p, removeFila(f));
        aux = aux->prox;
    }
    return p;
}
Fila* pilhaParaFila(Fila* f, Pilha* p) {
    No *aux;
    aux = p->topo;
    while(aux != NULL) {
        aux = aux->prox;
        f = insereFila(f, desempilha(p));
    }
}
Fila* pilhaParaFilaI(Fila* f, Pilha* p) {
    No *aux;
    Pilha* pAuxiliar = inicializaP();
    while(p->topo != NULL) {
        pAuxiliar = empilha(pAuxiliar, desempilha(p));
    }
    while(pAuxiliar->topo != NULL) {
        f = insereFila(f, desempilha(pAuxiliar));
    }
    return f;
}
Fila* juntaFila(Fila* f1, Fila* f2) {
    No *aux;
    Fila *f3 = inicializaF();
    while(f1->inicio != NULL) {
        f3 = insereFila(f3, removeFila(f1));
    }
    while(f2->inicio != NULL) {
        for(aux = f3->inicio; aux != NULL; aux = aux->prox){
            if(aux->info == f2->inicio->info) {
                break;
            }
        }
        if(aux == NULL) {
            f3 = insereFila(f3, removeFila(f2));
        }
        else{
            removeFila(f2);
        }
    }
    return f3;
}
int main() {
    Pilha *p = inicializaP();
    Fila *f1 = inicializaF();
    Fila *f2 = inicializaF();
    Fila *f3 = inicializaF();
    f1 = insereFila(f1, 1);
    f1 = insereFila(f1, 2);
    f1 = insereFila(f1, 3);
    f1 = insereFila(f1, 4);
    f1 = insereFila(f1, 5);
    f1 = insereFila(f1, 6);
    f2 = insereFila(f2, 1);
    f2 = insereFila(f2, 2);
    f2 = insereFila(f2, 3);
    f2 = insereFila(f2, 4);
    f2 = insereFila(f2, 5);
    f2 = insereFila(f2, 12);
    f3 = juntaFila(f1, f2);
    imprimeFila(f3);   
}