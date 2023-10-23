// Determine o perímetro de um retângulo.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {


    float altura;
    printf("Digite a altura do retângulo em cm ");
    scanf("%f", &altura);

    float base;
    printf("Digite a base do retângulo em cm ");
    scanf("%f", &base);

    float perimetro = (base + altura) * 2;
    
    printf("O perímetro total é de %f cm", perimetro);

}