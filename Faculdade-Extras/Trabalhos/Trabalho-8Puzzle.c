#include <stdlib.h>
#include <stdio.h>
#include <string.h>
# define tam 3

int **criaMatriz() {
    //Cria primeiro as 3 linhas da matriz, porém, elas estão vazias.
    int **matriz = (int **)malloc(tam * sizeof(int));
    //Preenche as 3 linhas com espaços para 3 elementos cada.
    for(int i = 0; i < tam; i++) {
        matriz[i] = (int *)malloc(tam * sizeof(int));
    }
    return matriz;
}
int **prencheMatriz() {
    //Preenche uma matriz vazia com dígitos de 1 a 8, e o 0 no final.
    int **matriz = criaMatriz();
    int i, j, k = 1;
    for(i = 0; i < tam; i++) {
        for(j = 0; j < tam; j++) {
            matriz[i][j] = k;
            k++;
        }
    }
    //Aqui temos o último elemento colocado como 0, ele será usado como o valor jogável em outros casos.
    matriz[2][2] = 0;
    return matriz;
}
void printaMatriz(int **matriz) {
    // Percorre todos os elementos da matriz e printa eles.
    int i, j;
    for(i = 0; i < tam; i++) {
        for(j = 0; j < tam; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
} 
void verificaCerto(int **matriz) {
    int i, j, k = 1;
    //A matriz inteira será percorrida com o objetivo de verificar se cada elemento está colocado corretamente.
    for(i = 0; i < tam; i++) {
        for(j = 0; j < tam; j++) {
            //Para evitarmos problemas no elemento final, será feito uma verificação específica para ele.
            if((i == 2) && (j == 2)) {
                if(matriz[i][j] != 0) {
                    printf("A matriz está incorreta, já que deviamos ter na posição %d/%d o valor 0 e não %d.\n",i + 1, j + 1, matriz[i][j]);
                    continue;
                }
                // O continue é colocado em ambos os casos para que haja uma dupla verificação.
                else{
                    continue;
                }
            }
            if(matriz[i][j] != k) {
                printf("A matriz está incorreta, já que deviamos ter na posição %d/%d o valor %d e não %d.\n",i + 1, j + 1, k, matriz[i][j]);
            }
            k++;
        }
    }
}

int main() {

    int **matrizona;
    matrizona = criaMatriz();
    matrizona = prencheMatriz();
    printaMatriz(matrizona);


    //Libera o espaço ocupado pela matriz na memória
    for (int i = 0; i < 3; i++) {
    free(matrizona[i]);
    }
    free(matrizona);
    
    
    return 0;
}
