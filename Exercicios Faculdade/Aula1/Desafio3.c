// Elabore um programa que leia uma valor em segundos e transforme em horas, minutos e segundos.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {

    int valorsegundos, valorminutos, valorhoras;

    printf("Digite o valor em segundos ");
    scanf("%d", &valorsegundos);

    valorhoras = valorsegundos / 3600;
    valorsegundos = valorsegundos - valorhoras * 3600;
    valorminutos = valorsegundos / 60;
    valorsegundos = valorsegundos - valorminutos * 60;

 printf("%d horas, %d minutos e %d segundos.\n", valorhoras, valorminutos, valorsegundos);








}