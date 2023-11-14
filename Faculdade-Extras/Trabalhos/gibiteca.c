#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Definição da estrutura para livros que estão disponíveis para locação.
typedef struct disp {
    int codigo;
    char nome[50];
    char assunto[100];
    char autor[50];
    struct disp *prox;
} LivroDisp;
// Definição da estrutura para livros que já estão alugados.
typedef struct empres {
    LivroDisp Livro;
    int codCliente;
    struct empres *prox;
}LivroEmpres;
// Definição da estrutura para clientes.
typedef struct cliente {
    int codigo;
    char nome[50];

}Cliente;
// Inicializa a estrutura do livroDisp.
LivroDisp* inicializa() {
    return NULL;
}
// Aloca um espaço para uma estrutura do tipo livroDisp, isso é útil na hora de inserir em uma lista.
LivroDisp* cria() {
    LivroDisp *novo; // Cria uma variável do tipo LivroDisp de nome novo.
    novo = (LivroDisp*)malloc(sizeof(LivroDisp)); // Aloca o espaço necessário com base na estrutura pré-estabelecida.
    return novo; 
}
// Está função insere livros novos na lista com base no código do produto, no fim a lista fica em ordem crescente.
// Já que vamos inserir um livro novo, precisamos de informações como autor, assunto e nome do livro.
LivroDisp* insereOrdenando(LivroDisp* listinha, int valor, char nome[], char assunto[], char autor[]) { 
    // Cria e define as variáveis ant e aux, que servem para percorrer a lista.
    LivroDisp *aux, *ant = NULL;
    aux = listinha;

    // Cria a variável LivroDisp e insere as informações necessárias nela.
    LivroDisp *novo = cria();
    novo->codigo = valor;
    strcpy(novo->nome, nome);
    strcpy(novo->assunto, assunto);
    strcpy(novo->autor, autor);

    // No caso de precisarmos colocar o novo no ínicio da lista, já que ele é menor que o primeiro elemento dela, definimos que ele irá apontar para o primeiro elemento anterior, e retornamos o novo, já que ele aponta para o resto da lista; É equivalente a retorna a lista.
    if (aux == NULL || aux->codigo > valor) {
        novo->prox = aux;
        return novo;
    }
    // No caso do elemento já existir na lista e ser o primeiro dela, fazemos esse caso especial para evitar problemas.
    if(aux->codigo == valor) {
    printf("O valor %d já existe na LivroDisp.\n", valor);
    free(novo); // Liberamos o elemento novo para evitar vazamento de memória.
    return listinha; // Retornamos a lista do mesmo jeito que ela foi passada.
    }
    // Aqui iremos percorrer a lista até acharmos um valor menor do que o que será inserido, já que ela está em ordem crescente. O if dentro do while serve para evitar repetições de produto com o mesmo valor.
    while (aux != NULL && aux->codigo < valor) {
        if((aux->prox !=NULL && aux->prox->codigo == valor) || aux->codigo == valor) {
            printf("O valor %d já existe na LivroDisp.\n", valor);
            return listinha;
        }
        ant = aux;
        aux = aux->prox;
    }
    // Aqui é definido o novo livro sem quebrar o encadeamento da lista.
    novo->prox = aux;
    ant->prox = novo;
    return listinha;
}
void imprimeLivroDisp(LivroDisp* listinha) {
    // Aqui a lista será percorrida e os valores da estrutura LivroDisp serão todos printados.
    LivroDisp *aux;
    aux = listinha;
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

int main() {
    LivroDisp *p;
    p = inicializa();
    p = insereOrdenando(p, 1, "Mágico de Oz", "Fantasia", "L. Frank Baum");
    p = insereOrdenando(p, 2, "Senhor dos anéis", "Fantasia", "Tolkien");
    p = insereOrdenando(p, 3, "1984", "Ficção Científica", "George Orwell");
    p = insereOrdenando(p, 4, "A Revolução dos Bichos", "Fábula Política", "George Orwell");
    p = insereOrdenando(p, 5, "O Pequeno Príncipe", "Fábula", "Antoine de Saint-Exupéry");
    p = insereOrdenando(p, 6, "Dom Quixote", "Romance", "Miguel de Cervantes");
    imprimeLivroDisp(p);
}