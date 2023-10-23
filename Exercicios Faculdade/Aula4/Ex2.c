// Calcular a quantidade dinheiro gasta por um fumante. Dados: o
// número de anos que ele fuma, o nº de cigarros fumados por dia e o
// preço de uma carteira.

#include <stdlib.h>
#include <stdio.h>

int main() {

    int precomaco = 10, nummacos, tempo, gasto;

    printf("A quantos anos tempo você fuma? ");
    scanf("%d", &tempo);

    printf("Quantos maços em média você fuma por dia? ");
    scanf("%d", &nummacos);

    gasto = ((precomaco * nummacos) * tempo) * 365;

    printf("O total gasto é de %d reais", gasto);

}