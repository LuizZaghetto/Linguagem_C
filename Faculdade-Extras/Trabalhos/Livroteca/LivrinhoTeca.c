#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Define as 3 estruturas necessárias, a primeira é referente ao livros disponíveis, a segunda aos emprestados e a terceira aos clientes
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
LivroDisp* DigitaLivroDispOrdenando(LivroDisp* livrinhoDisp) {
    LivroDisp *aux, *ant = NULL;
    aux = livrinhoDisp;

    LivroDisp *novo = criaLivroDisp();

    printf("Digite o código do livro: ");
    scanf("%d", &(novo->codigo));
    getchar();

    printf("Digite o nome do livro: ");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';

    printf("Digite o assunto do livro: ");
    fgets(novo->assunto, sizeof(novo->assunto), stdin);
    novo->assunto[strcspn(novo->assunto, "\n")] = '\0';

    printf("Digite o nome do autor do livro: ");
    fgets(novo->autor, sizeof(novo->autor), stdin);
    novo->autor[strcspn(novo->autor, "\n")] = '\0';

    while (aux != NULL) {
        if(aux->codigo == novo->codigo) {
            printf("O código %d já foi usado, ele pertence ao livro %s.\n", novo->codigo, aux->nome);
            free(novo);
            return livrinhoDisp;
        }
        if (strcasecmp(novo->nome, aux->nome) == 0) {
            printf("Um livro com o nome %s já existe, ele tem o código %d\n", novo->nome, aux->codigo);
            free(novo);
            return livrinhoDisp;
        }
        aux = aux->prox;
    }

    aux = livrinhoDisp;
    if(aux == NULL || novo->codigo < aux->codigo) {
        novo->prox = aux;
        return novo;
    }
    while (aux != NULL && novo->codigo > aux->codigo) {
        ant = aux;
        aux = aux->prox;
    }
    novo->prox = aux;
    if (ant != NULL) {
        ant->prox = novo;
    } else {
        livrinhoDisp = novo;
    }
    return livrinhoDisp;
}

void imprimeLivroDisp(LivroDisp* livrinhoDisp) {
    LivroDisp *aux;
    aux = livrinhoDisp;
    if(aux == NULL) {
        printf("Não há livros disponíveis para empréstimo\n");
    }
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
LivroEmpres* insereLivroEmpresOrdenando(LivroEmpres* livrinhoEmpres, LivroDisp* livrinhoDisp, int valorCliente, char nomeLivro[]) {
    LivroEmpres *auxEmpres, *antEmpres = NULL;
    LivroDisp *auxDisp = livrinhoDisp;

    LivroEmpres *novo = criaLivroEmpres();
    novo->codCliente = valorCliente;

    while (auxDisp != NULL && strcasecmp(auxDisp->nome, nomeLivro) != 0) {
        auxDisp = auxDisp->prox;
    }

    if (auxDisp == NULL) {
        printf("Livro com o nome %s não encontrado.\n", nomeLivro);
        free(novo);
        return livrinhoEmpres;
    }

    novo->codigoLivro = auxDisp->codigo;
    strcpy(novo->nome, auxDisp->nome);
    strcpy(novo->assunto, auxDisp->assunto);
    strcpy(novo->autor, auxDisp->autor);

    auxEmpres = livrinhoEmpres;

    if (auxEmpres == NULL || strcasecmp(auxEmpres->nome, nomeLivro) > 0) {
        novo->prox = auxEmpres;
        return novo;
    }

    if (strcasecmp(auxEmpres->nome, nomeLivro) == 0) {
        printf("O livro %s já está na lista de emprestados.\n", nomeLivro);
        free(novo);
        return livrinhoEmpres;
    }

    while (auxEmpres != NULL && strcasecmp(auxEmpres->nome, nomeLivro) < 0) {
        if ((auxEmpres->prox != NULL && strcasecmp(auxEmpres->prox->nome, nomeLivro) == 0) || strcasecmp(auxEmpres->nome, nomeLivro) == 0) {
            printf("O livro %s já está na lista de emprestados.\n", nomeLivro);
            free(novo);
            return livrinhoEmpres;
        }
        antEmpres = auxEmpres;
        auxEmpres = auxEmpres->prox;
    }

    novo->prox = auxEmpres;
    antEmpres->prox = novo;
    return livrinhoEmpres;
}
void imprimeLivroEmpres(LivroEmpres* livrinhoEmpres) {
    LivroEmpres *aux = livrinhoEmpres;
    if(aux == NULL) {
        printf("Não há livros emprestados\n");
    }
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
void removeLivroEmpres(LivroEmpres** livrinhoEmpres, char nomeLivro[]) {
    LivroEmpres *aux, *ant = NULL;
    aux = *livrinhoEmpres;

    if (aux == NULL) {
        printf("A lista está vazia");
        return;
    }

    if (strcmp(nomeLivro, aux->nome) == 0) {
        *livrinhoEmpres = aux->prox;
        free(aux);
        return;
    }

    while (aux != NULL && strcmp(nomeLivro, aux->nome) != 0) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("O livro não existe");
        return;
    }

    if (ant == NULL) {
        *livrinhoEmpres = aux->prox;
    } else {
        ant->prox = aux->prox;
    }

    free(aux);
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
Cliente* DigitaClienteOrdenando(Cliente* clientinho) {
    Cliente *aux, *ant = NULL;
    aux = clientinho;
    int valorCodigo;
    char nomeCliente[50];

    printf("Digite o código do cliente: ");
    scanf("%d", &valorCodigo);
    getchar();

    printf("Digite o nome do cliente: ");
    fgets(nomeCliente, sizeof(nomeCliente), stdin);
    nomeCliente[strcspn(nomeCliente, "\n")] = '\0';

    Cliente *novo = criaCliente();
    novo->codigo = valorCodigo;
    strcpy(novo->nome, nomeCliente);

    if (aux == NULL || aux->codigo > valorCodigo) {
        novo->prox = aux;
        return novo;
    }
    if (aux->codigo == valorCodigo) {
        printf("O valor %d já existe na lista.\n", valorCodigo);
        return clientinho;
    }
    while (aux != NULL && aux->codigo < valorCodigo) {
        if ((aux->prox != NULL && aux->prox->codigo == valorCodigo) || aux->codigo == valorCodigo) {
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
Cliente* insereLivroClienteOrdenando(Cliente* clientinho, LivroDisp* livrinhoDisp, char nomeLivro[], char nomeCliente[]) {
    LivroDisp *aux;
    aux = livrinhoDisp;
    Cliente* auxManos;
    auxManos = clientinho;

    while(aux != NULL) {
        if(strcmp(aux->nome, nomeLivro) == 0){
            break;
        }
        aux = aux->prox;
    }
    while(auxManos != NULL && strcmp(auxManos->nome, nomeCliente) != 0) {
        auxManos = auxManos->prox;
    }
    LivroDisp *auxCliente, *antCliente = NULL;
    auxCliente = auxManos->listaLivros;
    
    LivroDisp *novo = criaLivroDisp();
    novo->codigo = aux->codigo;
    strcpy(novo->nome, aux->nome);
    strcpy(novo->assunto, aux->assunto);
    strcpy(novo->autor, aux->autor);

    if (auxCliente == NULL || auxCliente->codigo > novo->codigo) {
        novo->prox = auxCliente;
        auxManos->listaLivros = novo;
        return clientinho;
    }
    while (auxCliente != NULL && novo->codigo < auxCliente->codigo) {
        antCliente = auxCliente;
        auxCliente = auxCliente->prox;
    }

    novo->prox = auxCliente;
    if (antCliente == NULL) {
        auxManos->listaLivros = novo;
    } else {
        antCliente->prox = novo;
    }
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
        printf("O cliente não existe\n");
        return;
    }
    LivroDisp *auxCliente = aux->listaLivros;
    if(auxCliente == NULL) {
        printf("O cliente não tem nenhum livro emprestado\n");
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
void DigitaClienteLivro(Cliente* clientinho) {
    int valorCodigo = -1;
    char nomeCliente[50];
    
    printf("Digite o código do cliente (ou -1 para buscar apenas pelo nome): ");
    scanf("%d", &valorCodigo);
    getchar();
    
    if (valorCodigo != -1) {
        Cliente *auxCodigo = clientinho;
        while (auxCodigo != NULL && auxCodigo->codigo != valorCodigo) {
            auxCodigo = auxCodigo->prox;
        }
        if (auxCodigo != NULL) {
            strcpy(nomeCliente, auxCodigo->nome);
        } else {
            printf("O cliente com o código fornecido não foi encontrado.\n");
            return;
        }
    } else {
        printf("Digite o nome do cliente: ");
        fflush(stdin);
        fgets(nomeCliente, sizeof(nomeCliente), stdin);
        nomeCliente[strcspn(nomeCliente, "\n")] = '\0';
    }

    Cliente *aux = clientinho;
    
    while(aux != NULL && strcmp(nomeCliente, aux->nome) != 0) {
        aux = aux->prox;
    }
    
    if(aux == NULL) {
        printf("O cliente não existe\n");
        return;
    }
    
    LivroDisp *auxCliente = aux->listaLivros;
    
    if(auxCliente == NULL) {
        printf("O cliente não tem nenhum livro emprestado\n");
        return;
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


void removeLivroCliente(Cliente* clientinho, char nomeLivro[], char nomeCliente[]) {
    Cliente *auxCliente;
    auxCliente = clientinho;
    while(auxCliente != NULL && strcmp(nomeCliente, auxCliente->nome) != 0) {
        auxCliente = auxCliente->prox;
    }
    if(auxCliente == NULL) {
        printf("O cliente %s não existe\n", nomeCliente);
        return;
    }   
    LivroDisp *auxLivro, *antLivro = NULL;
    auxLivro = auxCliente->listaLivros;
    while(auxLivro != NULL && strcmp(nomeLivro, auxLivro->nome) != 0) {
        antLivro = auxLivro;
        auxLivro = auxLivro->prox;
    }
    if(auxLivro == NULL) {
        printf("O livro %s não existe\n", nomeLivro);
        return;
    }
    if(antLivro == NULL) {
        auxCliente->listaLivros = auxLivro->prox;
    }
    else {
        antLivro->prox = auxLivro->prox;
    }
    free(auxLivro);
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

void emprestaLivro(LivroDisp** livrinhoDisp, LivroEmpres** livrinhoEmpres, Cliente** clientinho) {
    LivroDisp *aux, *ant = NULL;
    Cliente *auxCliente;
    aux = *livrinhoDisp;
    auxCliente = *clientinho;
    char nomeLivro[50];
    char nomeCliente[50];
    int codigoCliente = 0;
    int valorCodigo = -1;

    printf("Digite o código do livro (ou -1 para buscar pelo nome): ");
    scanf("%d", &valorCodigo);
    getchar();

    if (valorCodigo != -1) {
        while (aux != NULL && aux->codigo != valorCodigo) {
            ant = aux;
            aux = aux->prox;
        }
    } else {
        printf("Digite o nome do livro para empréstimo: ");
        fgets(nomeLivro, sizeof(nomeLivro), stdin);
        nomeLivro[strcspn(nomeLivro, "\n")] = '\0';

        while (aux != NULL && strcmp(nomeLivro, aux->nome) != 0) {
            ant = aux;
            aux = aux->prox;
        }
    }

    if(aux == NULL) {
        printf("O livro não foi encontrado para empréstimo.\n");
        return;
    }

    printf("Digite o código do cliente (ou -1 para buscar pelo nome): ");
    scanf("%d", &valorCodigo);
    getchar();

    if (valorCodigo != -1) {
        while(auxCliente != NULL && auxCliente->codigo != valorCodigo) {
            auxCliente = auxCliente->prox;
        }
    } else {
        printf("Digite o nome do cliente para o empréstimo: ");
        fgets(nomeCliente, sizeof(nomeCliente), stdin);
        nomeCliente[strcspn(nomeCliente, "\n")] = '\0';

        while(auxCliente != NULL && strcmp(nomeCliente, auxCliente->nome) != 0) {
            auxCliente = auxCliente->prox;
        }
    }

    if(auxCliente == NULL) {
        printf("O cliente não foi encontrado.\n");
        return;
    }
    codigoCliente = auxCliente->codigo;
    *livrinhoEmpres = insereLivroEmpresOrdenando(*livrinhoEmpres, *livrinhoDisp, codigoCliente, aux->nome);
    *clientinho = insereLivroClienteOrdenando(*clientinho, *livrinhoDisp, aux->nome, auxCliente->nome);
    
    if(ant == NULL) {
        *livrinhoDisp = aux->prox;
    } else {
        ant->prox = aux->prox;
    }
    free(aux);
}

void devolveLivro(LivroDisp** livrinhoDisp, LivroEmpres** livrinhoEmpres, Cliente** clientinho) {
    LivroEmpres *aux, *ant = NULL;
    Cliente *auxCliente;
    aux = *livrinhoEmpres;
    auxCliente = *clientinho;
    char nomeLivro[50];
    char nomeCliente[50];
    int valorCodigo = -1;

    printf("Digite o código do livro (ou -1 para buscar pelo nome): ");
    scanf("%d", &valorCodigo);
    getchar();

    if (valorCodigo != -1) {
        while (aux != NULL && aux->codigoLivro != valorCodigo) {
            ant = aux;
            aux = aux->prox;
        }
    } else {
        printf("Digite o nome do livro para devolução: ");
        fgets(nomeLivro, sizeof(nomeLivro), stdin);
        nomeLivro[strcspn(nomeLivro, "\n")] = '\0';

        while (aux != NULL && strcmp(nomeLivro, aux->nome) != 0) {
            ant = aux;
            aux = aux->prox;
        }
    }

    if(aux == NULL) {
        printf("O livro não foi encontrado para devolução.\n");
        return;
    }

    printf("Digite o código do cliente (ou -1 para buscar pelo nome): ");
    scanf("%d", &valorCodigo);
    getchar();

    if (valorCodigo != -1) {
        while(auxCliente != NULL && auxCliente->codigo != valorCodigo) {
            auxCliente = auxCliente->prox;
        }
    } else {
        printf("Digite o nome do cliente para a devolução: ");
        fgets(nomeCliente, sizeof(nomeCliente), stdin);
        nomeCliente[strcspn(nomeCliente, "\n")] = '\0';

        while(auxCliente != NULL && strcmp(nomeCliente, auxCliente->nome) != 0) {
            auxCliente = auxCliente->prox;
        }
    }

    if(auxCliente == NULL) {
        printf("O cliente não foi encontrado.\n");
        return;
    }

    *livrinhoDisp = insereLivroDispOrdenando(*livrinhoDisp, aux->codigoLivro, aux->nome, aux->assunto, aux->autor);
    removeLivroCliente(*clientinho, aux->nome, auxCliente->nome);
    removeLivroEmpres(livrinhoEmpres, aux->nome);
}

void menu(LivroDisp* livrinhoDisp, LivroEmpres* livrinhoEmpres, Cliente* clientinho) {
    while(1){
        int escolha = 0;
        printf("\nDigite o que deseja fazer: \n\n");
        printf("1 = Inserir um livro novo na biblioteca\n");
        printf("2 = Inserir um novo cliente\n");
        printf("3 = Emprestar um livro para um cliente\n");
        printf("4 = Devolver um livro de um determinado cliente\n");
        printf("5 = Imprimir os livros que estão emprestados por um dado cliente\n");
        printf("6 = Imprimir a Lista de todos os clientes com os respectivos livros emprestados\n");
        printf("7 = Imprimir a Lista de Todos os Livros Emprestado\n");
        printf("8 = Imprimir a lista de Livros Disponíveis da Biblioteca\n");
        printf("9 = Sair do Sistema\n");
        scanf("%d", &escolha);
        
        if(escolha == 1) {
            DigitaLivroDispOrdenando(livrinhoDisp);
        }
        if(escolha == 2) {
            DigitaClienteOrdenando(clientinho);
        }
        if(escolha == 3) {
            emprestaLivro(&livrinhoDisp, &livrinhoEmpres, &clientinho);
        }
        if(escolha == 4) {
            devolveLivro(&livrinhoDisp, &livrinhoEmpres, &clientinho);
        }
        if(escolha == 5) {
            DigitaClienteLivro(clientinho);
        }
        if(escolha == 6) {
            imprimeGeral(clientinho);
        }
        if(escolha == 7) {
            imprimeLivroEmpres(livrinhoEmpres);
        }
        if(escolha == 8) {
            imprimeLivroDisp(livrinhoDisp);
        }
        if(escolha == 9) {
            break;
        }
    }
}

int main() {
    LivroDisp *l;
    l = inicializaLivroDisp();
    l = insereLivroDispOrdenando(l, 1, "Mágico de Oz", "Fantasia", "L. Frank Baum");
    l = insereLivroDispOrdenando(l, 2, "Senhor dos Anéis", "Fantasia", "Tolkien");
    l = insereLivroDispOrdenando(l, 3, "1984", "Ficção Científica", "George Orwell");
    l = insereLivroDispOrdenando(l, 4, "A Revolução dos Bichos", "Fábula Política", "George Orwell");
    l = insereLivroDispOrdenando(l, 5, "O Pequeno Príncipe", "Fábula", "Antoine de Saint-Exupéry");
    l = insereLivroDispOrdenando(l, 6, "Dom Quixote", "Romance", "Miguel de Cervantes");
    
    LivroEmpres *e;
    e = inicializaLivroEmpres();
    Cliente *c;
    c = inicializaCliente();
    c = insereClienteOrdenando(c, 5, "Cleiton");
    c = insereClienteOrdenando(c, 3, "Ryan");
    c = insereClienteOrdenando(c, 9, "Oláberto");
    c = insereClienteOrdenando(c, 10, "Umbrenildo");
    c = insereClienteOrdenando(c, 7, "Habernaldo");
    c = insereClienteOrdenando(c, 4, "Patrício Patêhomem");
    menu(l, e, c);
}
