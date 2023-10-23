// Leia um vetor de 20 posições e em seguida um valor X qualquer. Seu
// programa deverá fazer uma busca do valor de X no vetor lido e
// informar a posição em que foi encontrado ou se não foi encontrado.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define tam 20

int main() {

    setlocale(LC_ALL,"portuguese");
    int i, N, v[tam] = {10, 20, 45, 30, 18, 19, 40, 28, 120, 20, 78, 29, 29, 25, 20, -10, 17, 21, 19, 4000};

    
    do{
    int tem = 0, posi = 0;
    int pos[tem];
    char sair;
    
    printf("Digite o valor que deseja buscar no vetor ");
    scanf("%d", &N);

    for(i = 0; i < tam; i++) {
        if(N == v[i]) {
            pos[tem] = i;
            tem++;
            posi = i;
        }

    }

    if(tem == 1) {
        printf("Seu valor foi encontrado uma vez e na posição %d\n", posi);
    }
    else if(tem > 1) {
        printf("Seu valor foi encontrado %d vezes e nas seguintes posições:\n", tem);
        for(i = 0; i < tem; i++) {
            printf("%d ", pos[i]);
        }
    }
    else {
        printf("Seu valor não foi encontrado no vetor\n");
    }

    printf("\nDeseja buscar mais algum valor? S ou N\n");
    scanf(" %c", &sair);

    if(sair == 'S' || sair == 's') {
        continue;
    }
    if(sair == 'N' || sair == 'n') {
        break;
    }

    }while(1);
    
    
    return 0;
}