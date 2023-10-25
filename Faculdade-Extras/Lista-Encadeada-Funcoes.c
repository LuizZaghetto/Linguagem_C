#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int info;
    struct no *prox;
}Lista;

int verificaVazia(Lista *listinha);

Lista* inicializa() {
    return NULL;
}
Lista* cria() {
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    return novo;
}
Lista* insereInicio(Lista* listinha, int valor) {
    Lista *novo = cria();
    novo->info = valor;
    novo->prox = listinha;
    return novo; 
}
Lista* insereFim(Lista* listinha, int valor) {
    if(verificaVazia(listinha) == 0) {
        Lista *aux;
        aux = listinha;
            while(aux->prox != NULL) {
                aux = aux->prox;
            }
            Lista *novo = cria();
            novo->info = valor;
            novo->prox = NULL;
            aux->prox = novo;
        }
    else {
        return insereInicio(listinha, valor);
    }
    return listinha;
}
Lista* apaga(Lista* listinha, int valor) {
    if(verificaVazia(listinha) == 0) {
        Lista *aux;
        Lista *ant = NULL;
        aux = listinha;
        while((aux->info != valor) && (aux->prox != NULL)) {
            ant = aux;
            aux = aux->prox;
        }
        if(aux->info == valor) {
            if(ant != NULL) {
                ant->prox = aux->prox;
            }
            else{
                listinha = aux->prox;
            }
            free(aux);
        }
        else{
            printf("O valor não foi encontrado na lista\n");
        }
    }
    else {
        printf("A lista é vazia\n");
    }
    return listinha;
}
Lista* insereMeio(Lista* listinha, int valorA, int valorB) { //Valor "A" é o que vai ser usado de antecessor e valor "B" é o novo.
    if(verificaVazia(listinha) == 0) {
        Lista *aux;
        aux = listinha;
        while((aux != NULL) && (aux->info != valorA)) {
            aux = aux->prox;
        }
        if(aux == NULL) {
            printf("O valor usado para o antecessor não foi encontrado no programa\n");
            return listinha;
        }
        if(aux->info == valorA) {
            Lista *novo = cria();
            novo->info = valorB;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else{
        printf("A lista é vazia\n");
    }
    return listinha;
}
int verificaVazia(Lista* listinha) {
    if(listinha == NULL) {
        printf("A lista é vazia\n");
        return 1;
    }
    return 0;
}
void imprime(Lista* listinha) {
    if(verificaVazia(listinha) == 0) {
        Lista *aux;
        aux = listinha;
        while(aux != NULL) {
            printf("%d\n", aux->info);
            aux = aux->prox;
        }
    }
}
int main() {
    Lista* p;
    p = inicializa();
    p = insereInicio(p, 12);
    p = insereInicio(p, 15);
    p = insereInicio(p, 20);
    p = insereFim(p, 18);
    p = apaga(p, 18);
    p = insereMeio(p, 19, 27);
    imprime(p);
}