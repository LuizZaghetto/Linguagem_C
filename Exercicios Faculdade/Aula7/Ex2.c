// Elabore um programa que crie uma estrutura com as seguintes informações de um produto:
// • Código do produto – inteiro de 3 dígitos.
// • Quantidade em estoque - inteiro.
// • Valor de compra - real.
// • Valor de Venda - real.
// O programa deverá ler a informação de 10 produtos e determinar:
// • O código do produto com maior quantidade de estoque.
// • O quantidade de estoque do produto que proporciona o maior lucro.

#include <stdlib.h>
#include <stdio.h>
#define tam 10

struct Produto {
    int codigo;
    int quantidade;
    float valorcompra;
    float valorvenda;
    float lucro;
};
struct Produto produtos[tam];

void escreveProduto(struct Produto produtos[tam]) {
    for(int i = 0; i < tam; i++) {
        printf("Digite o código do produto: ");
        scanf("%d", &produtos[i].codigo);
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);
        printf("Digite o valor de compra: ");
        scanf("%f", &produtos[i].valorcompra);
        printf("Digite o valor de venda: ");
        scanf("%f", &produtos[i].valorvenda);
        produtos[i].lucro = produtos[i].valorvenda - produtos[i].valorcompra;
    }
}
int maiorEstoque(struct Produto produtos[tam], int* maior, int* codigo) {
    *maior = produtos[0].quantidade;
    for(int i = 0; i < tam; i++) {
        if(produtos[i].quantidade > *maior) {
            *maior = produtos[i].quantidade;
            *codigo = produtos[i].codigo;
        }
    }
    return *codigo;
}
int maiorLucro(struct Produto produtos[tam]) {
    int quantidade, maior = produtos[0].lucro;
    for(int i = 0; i < tam; i++) {
        if(produtos[i].lucro > maior) {
            maior = produtos[i].lucro;
            quantidade = produtos[i].quantidade;
        }
    }
    return quantidade;
}
int main() {
    struct Produto produtos[tam];
    int maior, codigo;
    escreveProduto(produtos);
    maiorEstoque(produtos, &maior, &codigo);
    printf("O código do produto com maior estoque é %d\n", codigo);
    float quantidade = maiorLucro(produtos);
    printf("A quantidade de produtos com maior lucro é %.2f\n", quantidade);

    return 0;
}
