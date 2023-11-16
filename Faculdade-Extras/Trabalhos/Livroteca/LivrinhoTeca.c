#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct disp {
    int codigo;
    char nome[50];
    char assunto[100];
    char autor[50];
    struct disp *prox;
} LivroDisp;

typedef struct empres {
    int codigoLivro;
    int codCliente;
    char nome[50];
    char assunto[100];
    char autor[50];
    struct empres *prox;
}LivroEmpres;

typedef struct cliente {
    int codigo;
    char nome[50];
    LivroDisp *listaLivros;
    struct cliente *prox;
}Cliente;

// Funções de LivroDisp

LivroDisp* inicializaLivroDisp() {
    return NULL;
}
LivroDisp* criaLivroDisp() {
    LivroDisp *novo;
    novo = (LivroDisp*)malloc(sizeof(LivroDisp));
    return novo;
}
LivroDisp* insereLivroDispOrdenando(LivroDisp* livrinhoDisp, int valor, char nomeLivro[], char assuntoLivro[], char autorLivro[]) {
    LivroDisp *aux, *ant = NULL;
    aux = livrinhoDisp;

    LivroDisp *novo = criaLivroDisp();
    novo->codigo = valor;
    strcpy(novo->nome, nomeLivro);
    strcpy(novo->assunto, assuntoLivro);
    strcpy(novo->autor, autorLivro);

    if (aux == NULL || aux->codigo > valor) {
        novo->prox = aux;
        return novo;
    }
    if(aux->codigo == valor) {
    printf("O valor %d já existe na LivroDisp.\n", valor);
    free(novo);
    return livrinhoDisp;
    }

    while (aux != NULL && aux->codigo < valor) {
        if((aux->prox !=NULL && aux->prox->codigo == valor) || aux->codigo == valor) {
            printf("O valor %d já existe na LivroDisp.\n", valor);
            return livrinhoDisp;
        }
        ant = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    ant->prox = novo;
    return livrinhoDisp;
}
void imprimeLivroDisp(LivroDisp* livrinhoDisp) {
    LivroDisp *aux;
    aux = livrinhoDisp;
    while(aux != NULL) {
        printf("****************************\n");
        printf("Código do livro: %d\n", aux->codigo);
        printf("Nome do livro: %s\n", aux->nome);
        printf("Assunto do livro: %s\n", aux->assunto);
        printf("Nome do autor: %s\n", aux->autor);
        printf("****************************\n");
        aux = aux->prox;
    }
}

// Funções de LivroEmpres:

LivroEmpres* inicializaLivroEmpres() {
    return NULL;
}
LivroEmpres* criaLivroEmpres() {
    LivroEmpres *novo = (LivroEmpres *)malloc(sizeof(LivroEmpres));
    return novo;
}
LivroEmpres* insereLivroEmpresOrdenando(LivroEmpres* livrinhoEmpres, int valorCodigo, int valorCliente, char nomeLivro[], char assuntoLivro[], char autorLivro[]) {
        LivroEmpres *aux, *ant = NULL;
        aux = livrinhoEmpres;

        LivroEmpres *novo = criaLivroEmpres();
        novo->codigoLivro = valorCodigo;
        novo->codCliente = valorCliente;
        strcpy(novo->nome, nomeLivro);
        strcpy(novo->assunto, assuntoLivro);
        strcpy(novo->autor, autorLivro);

        if (aux == NULL || aux->codigoLivro > valorCodigo) {
            novo->prox = aux;
            return novo;
        }
        if(aux->codigoLivro == valorCodigo) {
        printf("O valor %d já existe na LivroEmpres.\n", valorCodigo);
        free(novo);
        return livrinhoEmpres;
        }

        while (aux != NULL && aux->codigoLivro < valorCodigo) {
            if((aux->prox !=NULL && aux->prox->codigoLivro == valorCodigo) || aux->codigoLivro == valorCodigo) {
                printf("O valor %d já existe na LivroEmpres.\n", valorCodigo);
                return livrinhoEmpres;
            }
            ant = aux;
            aux = aux->prox;
        }

        novo->prox = aux;
        ant->prox = novo;
        return livrinhoEmpres;
    }
void imprimeLivroEmpres(LivroEmpres* livrinhoEmpres) {
    LivroEmpres *aux = livrinhoEmpres;
    while(aux != NULL) {
        printf("****************************\n");
        printf("Código do cliente que pegou emprestado: %d\n", aux->codCliente);
        printf("Código do livro: %d\n", aux->codigoLivro);
        printf("Nome do livro: %s\n", aux->nome);
        printf("Assunto do livro: %s\n", aux->assunto);
        printf("Nome do autor: %s\n", aux->autor);
        printf("****************************\n");
        aux = aux->prox;
    }
}


// Funções de Cliente:

Cliente* inicializaCliente() {
    return NULL;
}
Cliente* criaCliente() {
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    return novo;
}
Cliente* insereClienteOrdenando(Cliente* clientinho, int valorCodigo, char nomeCliente[]) {
    Cliente *aux, *ant = NULL;
    aux = clientinho;

    Cliente *novo = criaCliente();
    novo->codigo = valorCodigo;
    strcpy(novo->nome, nomeCliente);

    if (aux == NULL || aux->codigo > valorCodigo) {
        novo->prox = aux;
        return novo;
    }
    if(aux->codigo == valorCodigo) {
    printf("O valor %d já existe na lista.\n", valorCodigo);
    return clientinho;
    }
    while (aux != NULL && aux->codigo < valorCodigo) {
        if((aux->prox !=NULL && aux->prox->codigo == valorCodigo) || aux->codigo == valorCodigo) {
            printf("O valor %d já existe na lista.\n", valorCodigo);
            return clientinho;
        }
        ant = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    ant->prox = novo;
    return clientinho;
}
Cliente* insereLivroClienteOrdenando(Cliente* clientinho,int valorCodigo, int codigoCliente, char nomeCliente[], char nomeLivro[], char assuntoLivro[], char autorLivro[]) {
        LivroDisp *aux, *ant = NULL;
        aux = clientinho->listaLivros;

        LivroDisp *novo = criaLivroDisp();
        novo->codigo = valorCodigo;
        strcpy(novo->nome, nomeLivro);
        strcpy(novo->assunto, assuntoLivro);
        strcpy(novo->autor, autorLivro);

        if (aux == NULL || aux->codigo > valorCodigo) {
            novo->prox = aux;
            clientinho->listaLivros = novo;
            return clientinho;
        }
        if(aux->codigo == valorCodigo) {
        printf("O valor %d já existe na LivroEmpres.\n", valorCodigo);
        free(novo);
        return clientinho;
        }

        while (aux != NULL && aux->codigo < valorCodigo) {
            if((aux->prox !=NULL && aux->prox->codigo == valorCodigo) || aux->codigo == valorCodigo) {
                printf("O valor %d já existe na LivroEmpres.\n", valorCodigo);
                free(novo);
                return clientinho;
            }
            ant = aux;
            aux = aux->prox;
        }

        novo->prox = aux;
        ant->prox = novo;
        return clientinho;
}
void imprimeCliente(Cliente* clientinho) {
    Cliente *aux;
    aux = clientinho;
    while(aux != NULL) {
        printf("****************************\n");
        printf("Código do Cliente: %d\n", aux->codigo);
        printf("Nome do Cliente: %s\n", aux->nome);
        printf("****************************\n");
        aux = aux->prox;
    }
}
void imprimeClienteLivro(Cliente* clientinho, char nomeCliente[]) {
    Cliente *aux = clientinho;
    while(aux != NULL && strcmp(nomeCliente, aux->nome) != 0) {
        aux = aux->prox;
    }
    if(aux == NULL) {
        printf("O cliente não existe");
        return;
    }
    LivroDisp *auxCliente = aux->listaLivros;
    if(auxCliente == NULL) {
        printf("O cliente não tem nenhum livro emprestado");
    }
    while(auxCliente != NULL) {
    printf("****************************\n");
    printf("Nome do livro: %s\n", auxCliente->nome);
    printf("Assunto do livro: %s\n", auxCliente->assunto);
    printf("Nome do autor: %s\n", auxCliente->autor);
    printf("****************************\n");
    auxCliente = auxCliente->prox;
    }
}


// Funções Gerais:

void imprimeGeral(Cliente* clientinho) {
    Cliente *aux;
    aux = clientinho;
    LivroDisp *auxCliente;
    while(aux != NULL) {
        printf("****************************\n");
        printf("Código do Cliente: %d\n", aux->codigo);
        printf("Nome do Cliente: %s\n", aux->nome);
        if(aux->listaLivros != NULL) {
            printf("O usuário tem a seguinte lista de livros emprestados: \n");
            imprimeClienteLivro(clientinho, aux->nome);
        }
        printf("****************************\n");
        aux = aux->prox;
    }
}
void emprestaLivro(char nomeLivro[], char nomeCliente[], LivroDisp* livrinhoDisp, LivroEmpres** livrinhoEmpres, Cliente** clientinho) {
    LivroDisp *aux, *ant;
    Cliente **auxCliente;
    aux = livrinhoDisp;
    auxCliente = clientinho;

    while (aux != NULL && strcmp(nomeLivro, aux->nome) != 0) {
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL) {
        printf("O livro não foi encontrado para empréstimo.\n");
        return;
    }
    while(*auxCliente != NULL && strcmp(nomeCliente, (*auxCliente)->nome) != 0) {
        (*auxCliente) = (*auxCliente)->prox;
    }
    if(*auxCliente == NULL) {
        printf("O cliente não foi encontrado");
        return;
    }
    *livrinhoEmpres = insereLivroEmpresOrdenando(*livrinhoEmpres, aux->codigo, (*auxCliente)->codigo, aux->nome, aux->assunto, aux->autor);
    *clientinho = insereLivroClienteOrdenando(*clientinho, aux->codigo, (*auxCliente)->codigo, nomeCliente, nomeLivro, aux->assunto, aux->autor);
    if(ant == NULL) {
        livrinhoDisp = aux->prox;
    }
    else{
        ant->prox = aux->prox;
    }
    free(aux);
}

int main() {
    LivroDisp *p;
    p = inicializaLivroDisp();
    p = insereLivroDispOrdenando(p, 1, "Mágico de Oz", "Fantasia", "L. Frank Baum");
    p = insereLivroDispOrdenando(p, 2, "Senhor dos anéis", "Fantasia", "Tolkien");
    p = insereLivroDispOrdenando(p, 3, "1984", "Ficção Científica", "George Orwell");
    p = insereLivroDispOrdenando(p, 4, "A Revolução dos Bichos", "Fábula Política", "George Orwell");
    p = insereLivroDispOrdenando(p, 5, "O Pequeno Príncipe", "Fábula", "Antoine de Saint-Exupéry");
    p = insereLivroDispOrdenando(p, 6, "Dom Quixote", "Romance", "Miguel de Cervantes");

    LivroEmpres *e;
    e = inicializaLivroEmpres();

    Cliente *c;
    c = inicializaCliente();
    c = insereClienteOrdenando(c, 5, "Cleiton");
    c = insereClienteOrdenando(c, 3, "Robinson");
    c = insereClienteOrdenando(c, 9, "Oláberto");
    c = insereClienteOrdenando(c, 10, "Umbrenildo");
    c = insereClienteOrdenando(c, 7, "Habernaldo");
    c = insereClienteOrdenando(c, 4, "John");

    emprestaLivro("1984", "John", p, &e, &c);
}
