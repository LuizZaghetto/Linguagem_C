// Elabore um programa que leia um valor em hora e transforme em minutos.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    int hora;
    printf("Digite a hora. (Os minutos vêm depois| Não utiliza Am/Pm) ");
    scanf("%d", &hora);

    int minuto;
    printf("Digite o minuto ");
    scanf("%d", &minuto);

    int horamin = hora * 60;
    int horario = horamin + minuto;
    printf("Os minutos totais são %d", horario);
    


}