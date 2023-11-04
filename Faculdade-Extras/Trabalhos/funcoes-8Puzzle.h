#define tam 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    int i, j, r, s, aux;
		srand(time(NULL));

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			r = rand() % 3; //aqui ele está gerando um número aleatório entre 1 e 3
			s = rand() % 3;
			aux = matrizrandom[i][j]; //aqui ele atribui à aux a matriz que pré definimos
			matrizrandom[i][j] = matrizrandom[r][s]; //aqui ele vai embaralhar os índice dos dois vetores da matriz, i & j (substitui os valores do indice pelos numeros aleatórios)
			matrizrandom[r][s] = aux; //e vai atribuir a matriz embaralhada ao aux e volta com o indice normal
		}
	}
    return matrizrandom;
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
    int i, j, k = 1, soma = 0;
    //A matriz inteira será percorrida com o objetivo de verificar se cada elemento está colocado corretamente.
    for(i = 0; i < tam; i++) {
        for(j = 0; j < tam; j++) {
            //Para evitarmos problemas no elemento final, será feito uma verificação específica para ele.
            if((i == 2) && (j == 2)) {
                if(matriz[i][j] != 0) {
                    soma++;
                    continue;
                }
                // O continue é colocado em ambos os casos para que não haja uma dupla verificação.
                else{
                    continue;
                }
            }
            if(matriz[i][j] != k) {
                soma++;
            }
            k++;
        }
    }
    return soma;
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
                    printaMatriz(matriz);
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
    if(movimento == 'c') {
        matriz = cima(matriz);
    }
    if(movimento == 'b') {
        matriz = baixo(matriz);
    }
    if(movimento == 'e') {
        matriz = esquerda(matriz);
    }
    if(movimento == 'd') {
        matriz = direita(matriz);
    }
    return matriz;
}

void jogar() {
    int **matrizDoJogo = criaAleatoria();
    int **matrizPerfeita = prencheMatriz();
    printf("Sua matriz inicial é : \n");
    printaMatriz(matrizDoJogo);    
    printf("Sua meta é : \n");
    printaMatriz(matrizPerfeita);
    while(1) {
        char direcao, continuar;
        printf("Digite seu próximo movimento(cima = c, baixo = b, esquerda = e, direita = d): ");
        scanf(" %c", &direcao);
        matrizDoJogo = opcoes(matrizDoJogo, direcao);
        printaMatriz(matrizDoJogo);
        if(verificaCertoDiscreta(matrizDoJogo) == 0) {
            printf("Parabéns, você ganhou!\n");
            break;
        }
        else{
            printf("Você ainda não ganhou, existem %d números fora do lugar.\n", verificaCertoDiscreta(matrizDoJogo));
        }
        printf("Deseja continuar jogando(S ou N)? ");
        scanf(" %c", &continuar);
        if(continuar == 'S' || continuar == 's') {
            continue;
        }
        if(continuar == 'N' || continuar == 'n') {
            break;
        }
    }
    printf("Sua matriz final é : \n");
    printaMatriz(matrizDoJogo);
}

