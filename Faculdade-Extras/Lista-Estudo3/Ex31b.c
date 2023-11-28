#include <stdlib.h>
#include <stdio.h>

typedef struct noarvore{
    int info;
    struct noarvore *dir;
    struct noarvore *esq;
}noArvore;

 typedef struct arvore{
    noArvore *raiz;
}Arvore;

Arvore* inicializaA() {
    Arvore *novo = (Arvore *)malloc(sizeof(Arvore));
    if (novo != NULL) {
        novo->raiz = NULL;
    }
    return novo;
}
noArvore* criaNo() {
    noArvore *novo = (noArvore *)malloc(sizeof(noArvore));
    novo->dir=NULL;
    novo->esq=NULL;
    return novo;
}
Arvore* insere(Arvore* a, int v) {
    noArvore *novo, *aux;
    novo=criaNo();
    novo->info=v;
    if(a->raiz == NULL) {
        a->raiz=novo;
        return a;
    }
    aux = a->raiz;
    int flag=1;
    while(flag) {
        if(aux->info > v) {
            if(aux->esq!=NULL) {            
                aux = aux->esq;
            }
            else{
                aux->esq = novo;
                flag = 0;
            }
        }
        else {
             if(aux->info < v) {
               if(aux->dir!=NULL)
                {            
                    aux = aux->dir;
                }
                else{
                    aux->dir = novo;
                    flag = 0;
                } 
            }
            else{
                printf("O valor %d já existe\n", v);
                flag=0;
            }
        }    
    }
    return a;
}
void printarPreOrder(noArvore* no) {
    if (no == NULL) {
        return;
    }
    printf("%d\n", no->info);
    printarPreOrder(no->esq);
    printarPreOrder(no->dir);
}
int contaNo(noArvore* no) {
    if (no == NULL) {
        return 0;
    }
    int contagem = 1; 
    contagem += contaNo(no->esq);
    contagem += contaNo(no->dir);
    return contagem;
}
int contaFolha(noArvore* no) {
    if (no == NULL || (no->esq == NULL && no->dir == NULL)) {
        return 1;
    }
    int contagem = 0; 
    contagem += contaNo(no->esq);
    contagem += contaNo(no->dir);
    return contagem;
}
int procuraNo(Arvore* a, int v) {
    noArvore *aux;
    aux = a->raiz;
    if(aux->info == v) {
        return 0;
    }
    int contagem = 0;
    while(1) {
        if(aux->info == v) {
            return contagem;
        }
        if(aux->info > v) {
            if(aux->esq != NULL) {
                aux = aux->esq;
                contagem++;
            }
            else{
                printf("O valor não está contido na árvore.\n");
                return -1;
            }
        }
        else{
            if(aux->info < v) {
                if(aux->dir != NULL) {
                    aux = aux->dir;
                    contagem++;
                }
                else{
                    printf("O valor não está contido na árvore\n");
                    return -1;
                }
            }
        }
    }
}
int contaDescendente(Arvore* a, int v) {
    noArvore *aux;
    aux = a->raiz;
    if(aux->info == v) {
        if(aux->dir != NULL && aux->esq !=NULL) {
            return 2;
        }
        if(aux->dir != NULL || aux->esq != NULL) {
            return 1;
        }
        else{
            return 0;
        }
    }
    while(1) {
        if(aux->info == v) {
            break;
        }
        if(aux->info > v) {
            if(aux->esq != NULL) {
                aux = aux->esq;
            }
            else{
                printf("O valor não está contido na árvore.\n");
                return -1;
            }
        }
        else{
            if(aux->info < v) {
                if(aux->dir != NULL) {
                    aux = aux->dir;
                }
                else{
                    printf("O valor não está contido na árvore\n");
                    return -1;
                }
            }
        }
    }
    if(aux->dir != NULL && aux->esq !=NULL) {
    return 2;
    }
    if(aux->dir != NULL || aux->esq != NULL) {
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    int procura = 6;
    Arvore *a;
    a = inicializaA();
    a = insere(a, 10);
    a = insere(a, 40);
    a = insere(a, 5);
    a = insere(a, 7);
    a = insere(a, 6);
    printarPreOrder(a->raiz);
    printf("A árvore tem %d nós\n", contaNo(a->raiz));
    printf("A árvore tem %d folhas\n", contaFolha(a->raiz));
    printf("O valor %d existe na árvore e está na profundidade %d\n",procura, procuraNo(a, procura));
    printf("O valor %d existe na árvore e tem %d descendentes\n", procura, contaDescendente(a, procura));
}

