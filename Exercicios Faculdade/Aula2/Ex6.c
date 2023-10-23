// Crie um algoritmo que leia dois valores (x e y) representando um intervalo. Em seguida, leia um novo
// valor (z) e verifique se z pertence ao intervalo [x, y]. 

#include <stdlib.h>
#include <stdio.h>

int main() {

    int x, y, z, num, true = 1, maior, menor;

    do {
        printf("Diga o valor x ");
        scanf("%d", &x);

        printf("Diga o valor y ");
        scanf("%d", &y);

        printf("Digite o valor de z: ");                                                                                                                                                                                                                                              
        scanf("%d", &z);

        if(x == y) {
            printf("Os números não podem ser iguais\n");
        }
        else {
            true = 0;
        }

    }while(true == 1);
    if(x > y) {
        maior = x;
        menor = y;
    }
    else {
        maior = y;
        menor = x;
    }

    num = menor + 1;
    
    printf("O intervalo é o seguinte:\n");
    
    do {

        printf("%d\n", num);
        num++;
    
    }while(num < maior);

    if (z >= menor && z <= maior) {
        printf("%d pertence ao intervalo [%d, %d]\n", z, menor, maior);
    } 
    else {
        printf("%d não pertence ao intervalo [%d, %d]\n", z, menor, maior);
    }
    
    return 0;

}