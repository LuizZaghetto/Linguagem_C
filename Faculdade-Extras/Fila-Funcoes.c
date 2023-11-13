#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no *prox;
}No;

typedef struct fila{
    No *ini;
    No *fim;
}Fila;

No* cria() {
    No *novo = (No *)malloc(sizeof(No));
    novo->prox = NULL;
    return novo;
}

Fila* inicializa() {
    Fila *filhinha = (Fila *)malloc(sizeof(Fila));
    filhinha->ini = NULL;
    filhinha->fim = NULL;
    return filhinha;
}
Fila* insere(Fila* filhinha, int valor) {
    No *colocado = cria();
    colocado->info = valor;
    colocado->prox = NULL;
    if(filhinha->ini == NULL) {
        filhinha->ini = colocado;
        filhinha->fim = colocado;
        return filhinha;
    }
    filhinha->fim->prox = colocado;
    filhinha->fim = colocado;
    return filhinha;
}
int apaga(Fila* filhinha) {
    int valor = filhinha->ini->info;
    No *apagado = filhinha->ini;
    filhinha->ini = filhinha->ini->prox;
    free(apagado);

    if(filhinha->ini == NULL) {
        filhinha->fim = NULL;
    }
    return valor;
}
int contaPar(Fila* filhinha) {
    int quantidade = 0;
    No *aux = filhinha->ini;
    while(aux != NULL) {
        if(aux->info % 2 == 0) {
            quantidade++;
        }
        aux = aux->prox;
    }
    return quantidade;
}
void apagaEspecifico(Fila* filhinha, int valor) {
    No *aux = filhinha->ini;
    No *ant = NULL;
    while(aux != NULL && aux->info != valor) {
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL) {
        printf("O elemento não foi encontrado na lista\n");
    }
    if(ant == NULL) {
        filhinha->ini = filhinha->ini->prox;
        free(aux);
        if(filhinha-> ini == NULL) {
            filhinha->fim == NULL;
        }
    }
    else {
        if(aux->prox == NULL) {
            filhinha->fim = ant;
        }
        ant->prox = aux->prox;
        free(aux);
    }
}
void dividePareImpar(Fila* filhinha, Fila* par, Fila* impar) {
    No* aux = filhinha->ini;
    while (aux != NULL) {
        if (aux->info % 2 == 0) {
            par = insere(par, aux->info);
        } else {
            impar = insere(impar, aux->info);
        }
        aux = aux->prox;
    }
}
void inverterFilaRecursiva(Fila *fila) {
    if (fila->ini == NULL) {
        return; 
    }

    int valor = apaga(fila);
    inverterFilaRecursiva(fila);
    insere(fila, valor);
}
void imprimeFila(Fila* filhinha) {
    No *aux = filhinha->ini;
    while(aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

int main() {

    Fila *f, *pordois, *porum;
    int trem;
    pordois = inicializa();
    porum = inicializa();
    f = inicializa();
    f = insere(f, 10);
    f = insere(f, 11);
    f = insere(f, 40);
    f = insere(f, 58);
    f = insere(f, 1);
    f = insere(f, 7);
    f = insere(f, 8);
    f = insere(f, 12);
    f = insere(f, 99);
    trem = apaga(f);
    apagaEspecifico(f, 1);
    imprimeFila(f);
    printf("O valor apagado foi %d\n", trem);
    printf("A fila tem %d elementos pares", contaPar(f));
    printf("*****Fila pares e ímpares*****\n");
    dividePareImpar(f, pordois, porum);
    printf("Impressão da fila par:\n");
    imprimeFila(pordois);
    printf("Impressão da lista ímpar:\n");
    imprimeFila(porum);
    printf("\n");
    inverterFilaRecursiva(f);
    imprimeFila(f);
}
