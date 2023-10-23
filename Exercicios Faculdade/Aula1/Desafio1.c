// A imobiliária Central vende apenas terrenos retangulares. Faça um algoritmo para ler as dimensões de um terreno e depois exibir a área do terreno.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {

float areatotal, frente, lateral;

printf("Qual o comprimento da frente do terreno em metros? ");
scanf("%f", &frente);

printf("Qual o comprimento da lateral do terreno em metros? ");
scanf("%f", &lateral);
    
areatotal = frente * lateral;

printf("A frente do terreno corresponde a %f metros, sua lateral a %f metros e sua área total é de %f", frente, lateral, areatotal);






}