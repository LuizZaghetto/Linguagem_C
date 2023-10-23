// Leia o salário mensal atual de um funcionário e o percentual de reajuste e determine o valor do novo salário.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    float salario;
    printf("Digite o sálario atual ");
    scanf("%f", &salario);

    float percentual;
    printf("Digite o percentual(Somente o número) ");
    scanf("%f", &percentual);

    float salarioreajuste = salario * (1 + (percentual / 100));

    printf("O novo salário é de %f", salarioreajuste);







}