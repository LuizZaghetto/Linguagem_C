#define tam 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** cima(int **matriz);
int** baixo(int **matriz);
int** esquerda(int **matriz);
int** direita(int **matriz);

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

int **criaAleatoria() {
    int **matrizrandom = criaMatriz();
    matrizrandom = prencheMatriz();
    int i;
    srand(time(NULL));
for (int i = 0; i < 100; i++) {
        int numeroAleatorio = rand() % 4 + 1;
        switch (numeroAleatorio) {
            case 1:
                matrizrandom = cima(matrizrandom);
                break;
            case 2:
                matrizrandom = baixo(matrizrandom);
                break;
            case 3:
                matrizrandom = esquerda(matrizrandom);
                break;
            case 4:
                matrizrandom = direita(matrizrandom);
                break;
            default:
                break;
        }
    }
    return matrizrandom;
}


void printaMatriz(int **matriz) {
    // Percorre todos os elementos da matriz e printa eles.
    int i, j;
    for(i = 0; i < tam; i++) {
        for(j = 0; j < tam; j++) {
            printf("\t[%d] ", matriz[i][j]);
        }
        printf("\n\n");
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
                // O continue é colocado em ambos os casos para que não haja uma dupla verificação.
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


int verificaCertoDiscreta(int **matriz) {
	int i, j, cont = 0;
	for (i = 0; i <= 2; i++) {
	    for(j = 0; j <=2; j++) {
	        if(matriz[i][j] != 3*i + (j+1)) {
		        cont++;
            }
        }
}
    if(matriz[2][2] == 0) {
                    cont--;
    }
    return cont;
}
int** cima(int **matriz)
	{
		int vazio = 0;
		int aux, i, j;
		for(i = 0; i < 3; i++) {
			for(j = 0; j < 3; j++) {
		        if(matriz[i][j] == vazio) {
			        if( i >= 1) {
				        aux = matriz[i-1][j];
				        matriz[i-1][j] = matriz[i][j];
				        matriz[i][j] = aux;
			        }
		        }
		    }
		}
    return matriz;
}


int** baixo(int **matriz) {
    int vazio = 0;
    int aux, i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matriz[i][j] == vazio) {
                // Verifica se não está na última linha antes de mover para baixo.
                if (i < 2) {
                    aux = matriz[i + 1][j];
                    matriz[i + 1][j] = matriz[i][j];
                    matriz[i][j] = aux;
                    return matriz;
                }
            }
        }
    }
    return matriz;
}


int** esquerda(int **matriz) {
	int vazio = 0;
	int aux, i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
            if(matriz[i][j] == vazio) {
                if( j >= 1) {
                    aux = matriz[i][j-1];
                    matriz[i][j-1] = matriz[i][j];
                    matriz[i][j] = aux;
			    }
		    }
	    }
	}
    return matriz;
}


int** direita(int **matriz){
		int vazio = 0;
		int aux, i, j;
		for(i = 0; i < 3; i++){

            for(j = 0; j < 3; j++){

                if(matriz[i][j] == vazio){

                    if( j <= 1){
				        aux = matriz[i][j+1];
				        matriz[i][j+1] = matriz[i][j];
				        matriz[i][j] = aux;
                        break;
			        }
		        }
	        }
	    }
    return matriz;
}


int **opcoes(int **matriz,char movimento) {
    switch (movimento){
    case ('c') :
        matriz = cima(matriz);
        break;
    case ('b') :
        matriz = baixo(matriz);
        break;
    case ('e') :
        matriz = esquerda(matriz);
        break;
    case ('d') :
        matriz = direita(matriz);
        break;
    default :
        printf("O valor digitado é inválido");

    }
    return matriz;

}
void jogar() {
    int **matrizDoJogo = criaAleatoria();
    int **matrizPerfeita = prencheMatriz();
    printf("==> Sua meta é: \n");
    printaMatriz(matrizPerfeita);
    printf("\n\n");
		printf("==> Sua matriz inicial é: \n");
    printaMatriz(matrizDoJogo);
    while(1) {
        char direcao, continuar;
        printf("==> Digite seu próximo movimento(cima = c, baixo = b, esquerda = e, direita = d):\n");
        scanf(" %c", &direcao);
        matrizDoJogo = opcoes(matrizDoJogo, direcao);
        printaMatriz(matrizDoJogo);
        if(verificaCertoDiscreta(matrizDoJogo) == 0) {
            printf("\n\nParabéns, você ganhou!\n\n");
            break;
        }
        else{
            printf("\n\nVocê ainda não ganhou, existem %d números fora do lugar.\n\n", verificaCertoDiscreta(matrizDoJogo));
        }

    }
    printf("***Sua matriz final é: \n");
    printaMatriz(matrizDoJogo);

    free(matrizDoJogo);
    free(matrizPerfeita);
}
