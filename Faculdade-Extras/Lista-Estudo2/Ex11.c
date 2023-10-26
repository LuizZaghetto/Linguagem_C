/*
Elabore uma função que verifique a existência de um elemento, passado por parâmetro numa lista
dinâmica. A função retornará 1 se o elemento existir na lista e 0 caso contrário.
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
Lista* insere(Lista* listinha, int valor){

    Lista *novo;
    novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = listinha;
    return novo;
}
Lista* imprime(Lista* listinha) {

    Lista *aux;
    aux = listinha;
    while(aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}
int verifica(Lista* listinha, int valor) {
    Lista *aux;
    aux = listinha;
    int perceber = 0;
    while(aux != NULL) {
        if(aux->info == valor) {
            perceber = 1;
        }
        aux = aux->prox;
    }
    return perceber;
}

int main() {

    printf("Olá mundo\n");
    Lista *p;
    p = inicializa();
    if(p == NULL) {
        p = insere(p, 10);
        p = insere(p, 12);
        p = insere(p, 19);
        imprime(p);
        printf("%d", verifica(p, 12));
    }
    else{
        printf("A alocação deu errado");
    }


    return 0;

}
